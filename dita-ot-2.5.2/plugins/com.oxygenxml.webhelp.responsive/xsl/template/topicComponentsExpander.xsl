<?xml version="1.0" encoding="UTF-8"?>
<!--
    
Oxygen Webhelp plugin
Copyright (c) 1998-2017 Syncro Soft SRL, Romania.  All rights reserved.

-->
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
    xmlns:xs="http://www.w3.org/2001/XMLSchema" exclude-result-prefixes="#all"
    xmlns:oxy="http://www.oxygenxml.com/functions"
    xmlns:relpath="http://dita2indesign/functions/relpath"
    xmlns:whc="http://www.oxygenxml.com/webhelp/components"
    xmlns:html="http://www.w3.org/1999/xhtml"
    xmlns:oxygen="http://www.oxygenxml.com/functions"
    xpath-default-namespace="http://www.w3.org/1999/xhtml" xmlns="http://www.w3.org/1999/xhtml"
    version="2.0">
    
    <xsl:include href="commonComponentsExpander.xsl"/>
    
    <xsl:variable name="VOID_HREF" select="'javascript:void(0)'"/>
    
    <xsl:template match="/" mode="copy_template">
        <xsl:param name="ditaot_topicContent" tunnel="yes"/>

        <!--<xsl:message>Process template, ditaot_topicContent: <xsl:copy-of select="$ditaot_topicContent"/></xsl:message>-->
        <xsl:apply-templates mode="#current" select="node()"/>
    </xsl:template>

    <!-- 
        Merge the content of the template body element with the body element generated by DITA-OT 
    -->
    <xsl:template match="body" mode="copy_template">
        <xsl:param name="ditaot_topicContent" tunnel="yes"/>
        <xsl:copy>
            <xsl:choose>
                <xsl:when test="exists($ditaot_topicContent)">
                    <!-- body element from dita-ot document -->
                    <xsl:variable name="ditaot_body" select="($ditaot_topicContent//body)[1]"/>
                    
                    <!-- Merge the attributes from the template body element with attributes from the body element produced by DITA-OT-->
                    <xsl:variable name="mergedAttributes"
                        select="oxy:mergeHTMLAttributes('body', @*, $ditaot_body/@*)"/>
                    <xsl:copy-of select="$mergedAttributes"/>
                                        
                    <xsl:apply-templates select="node()" mode="#current"/>
                </xsl:when>
                <xsl:otherwise>
                    <!-- Copy template body content -->
                    <xsl:apply-templates select="@* | node()" mode="#current"/>
                </xsl:otherwise>
            </xsl:choose>
        </xsl:copy>
    </xsl:template>

    <xsl:template match="whc:webhelp_topic_content" mode="copy_template">
        <xsl:param name="ditaot_topicContent" tunnel="yes"/>
        <xsl:choose>
            <xsl:when test="exists($ditaot_topicContent)">
                <div>
                    <xsl:call-template name="generateComponentClassAttribute">
                        <xsl:with-param name="compClass">wh_topic_content</xsl:with-param>
                    </xsl:call-template>
                    <!-- Copy attributes -->
                    <xsl:copy-of select="@* except @class"/>
        
                    <!-- Copy topic content without the related links section. -->
                    <!-- Try to copy the 'main' element. Generally, it is generated by DITA-OT 2.x  -->
                    <xsl:variable name="topicContent2_0" select="$ditaot_topicContent//body//main"/>
                    <xsl:choose>
                        <xsl:when test="exists($topicContent2_0)">
                            <xsl:apply-templates select="$topicContent2_0" mode="copy-topic-content"/>
                        </xsl:when>
                        <xsl:otherwise>
                            <!-- For DITA-OT 1.8 copy the content of div[@id = 'topicContent'] -->
                            <xsl:apply-templates select="$ditaot_topicContent//body//div[@id = 'topicContent']/node()" mode="copy-topic-content"/>                            
                        </xsl:otherwise>
                    </xsl:choose>
                </div>
            </xsl:when>
            <xsl:otherwise>
                <xsl:message>Cannot expand the 'webhelp_topic_content' component.</xsl:message>                
            </xsl:otherwise>
        </xsl:choose>
    </xsl:template>
    
    <xsl:template match="@*|node()" mode="copy-topic-content copy-related-links copy-child-links">
        <xsl:copy>
            <xsl:apply-templates select="@*|node()" mode="#current"/>
        </xsl:copy>
    </xsl:template>
        
   
    <!-- Matches the related links from a top level topic  -->
    <xsl:template match="*[contains(@class, 'related-links')]"
        mode="copy-topic-content">
        <!-- Filter the related links from the first level topic (with or without chunked content) -->
    </xsl:template>
    
    <!-- Matches the related links from a nested topic  -->
    <xsl:template match="*[contains(@class, 'related-links')][parent::*[contains(@class, 'nested') and not(contains(@class, 'nested0'))]]" priority="10"
        mode="copy-topic-content">
        <xsl:if test="oxy:getParameter('webhelp.merge.nested.topics.related.links') = 'no'">
            <!-- This is the related-links from a subtopic: copy the node. -->
            <xsl:copy-of select="."/>            
        </xsl:if>        
    </xsl:template>    
    
    <xsl:template match="*[contains(@class, 'olchildlinks')]" mode="copy-related-links">
        <!-- Filter ol child links. -->
    </xsl:template>
    
    <xsl:template match="*[contains(@class, 'ullinks')]" mode="copy-related-links">
        <!-- Filter ul child links. -->
    </xsl:template>
    
    <xsl:template match="*[contains(@class, 'linklist')]" mode="copy-child-links" priority="10">
        <!-- Filter link lists. -->
    </xsl:template>
    
    <xsl:template match="*[contains(@class, 'relinfo')]" mode="copy-child-links">
        <!-- Filter related information. -->
    </xsl:template>
    
    <xsl:template match="whc:webhelp_related_links" mode="copy_template">
        <xsl:param name="ditaot_topicContent" tunnel="yes"/>
        <xsl:if test="oxy:getParameter('webhelp.show.related.links') = 'yes'">
            <xsl:choose>
                <xsl:when test="exists($ditaot_topicContent)">
                    <xsl:variable name="relatedLinksContent">
                        <!-- Copy the related links excluding the ones generated from the children topics list. -->
                        <xsl:choose>
                            <xsl:when test="oxy:getParameter('webhelp.merge.nested.topics.related.links') = 'yes'">
                                <xsl:variable name="ungroupedLinks">
                                    <xsl:apply-templates select="$ditaot_topicContent//body//*[contains(@class, 'related-links')]" mode="copy-related-links"/>
                                </xsl:variable>
                                <xsl:call-template name="groupRelatedLinks">
                                    <xsl:with-param name="relLinks" select="$ungroupedLinks/*"/>
                                </xsl:call-template>
                            </xsl:when>
                            <xsl:otherwise>
                                <!-- Copy only the top level topic's related links -->
                                <xsl:apply-templates 
                                    select="$ditaot_topicContent//body//*[contains(@class, 'related-links')][parent::*[contains(@class, 'nested0') or not(contains(@class, 'nested'))]]" mode="copy-related-links"/>
                            </xsl:otherwise>
                        </xsl:choose>
                    </xsl:variable>
                    <!-- Generate the component only if there is at least one related link.  -->
                    <xsl:if test="count($relatedLinksContent/*/*) > 0">
                        <div>
                            <xsl:call-template name="generateComponentClassAttribute">
                                <xsl:with-param name="compClass">wh_related_links</xsl:with-param>
                            </xsl:call-template>
                            <!-- Copy attributes -->
                            <xsl:copy-of select="@* except @class"/>
                            <!-- There might be multiple .related-links nodes, but only some of the will have children -->
                            <xsl:copy-of select="$relatedLinksContent/*[count(child::*) > 0]"/>
                        </div>
                    </xsl:if>
                </xsl:when>
                <xsl:otherwise>
                    <xsl:message>Cannot expand the 'webhelp_related_links' component.</xsl:message>                
                </xsl:otherwise>
            </xsl:choose>
        </xsl:if>
    </xsl:template>
    
    <!-- EXM-36705: Merge & group related links from nested topics (chunk='to-content')-->
    <xsl:template name="groupRelatedLinks">
        <xsl:param name="relLinks" as="node()*"/>
        <xsl:if test="exists($relLinks)">
            <xsl:element name="{node-name($relLinks[1])}" 
                namespace="{namespace-uri($relLinks[1])}">
                <xsl:copy-of select="$relLinks[1]/@*"/>
                <xsl:for-each-group
                    select="$relLinks/div[contains(@class, 'linklist') or contains(@class, 'relinfo')]"
                    group-by="
                        (: Group by the link list's title heading (e.g. Related information, Related tasks, etc) :)
                        if (strong) then
                            (strong/text())
                        (: If the links list does not have a title, then consider an empty key for grouping the links. :)
                        else
                            ('')">
                    <!-- Sort the links by the links list's title heading -->
                    <xsl:sort select="current-grouping-key()"/>
                    <xsl:variable name="firstItem" select="current-group()[1]"/>
                    <!-- Merge links lists having the same title in a single list. -->
                    <xsl:element name="{node-name($firstItem)}"
                        namespace="{namespace-uri($firstItem)}">
                        <xsl:copy-of select="$firstItem/@*"/>
                        <xsl:if test="current-grouping-key() != ''">
                            <!-- The links list title heading -->
                            <strong>
                                <xsl:value-of select="current-grouping-key()"/>
                            </strong>
                            <br/>
                        </xsl:if>
                        <!-- Copy the related links for the current group -->
                        <xsl:copy-of
                            select="current-group()//*[contains(@class, 'related_link')]"/>
                    </xsl:element>
                </xsl:for-each-group>
            </xsl:element>
        </xsl:if>
    </xsl:template>
    
    <xsl:template match="whc:webhelp_child_links" mode="copy_template">
        <xsl:param name="ditaot_topicContent" tunnel="yes"/>
        <xsl:if test="oxy:getParameter('webhelp.show.child.links') = 'yes'">
            <xsl:choose>
                <xsl:when test="exists($ditaot_topicContent)">
                    <xsl:variable name="childLinksContent">
                        <!-- Copy only the related links generated from the children topics list. -->
                        <xsl:apply-templates select="$ditaot_topicContent//body//*[contains(@class, 'related-links')]" mode="copy-child-links"/>
                    </xsl:variable>
                    <!-- Generate the component only if there is at least one child link.  -->
                    <xsl:if test="count($childLinksContent/*/*) > 0">
                        <div>
                            <xsl:call-template name="generateComponentClassAttribute">
                                <xsl:with-param name="compClass">wh_child_links</xsl:with-param>
                            </xsl:call-template>
                            <!-- Copy attributes -->
                            <xsl:copy-of select="@* except @class"/>
                            <!-- There might be multiple .related-links nodes, but only some of the will have children -->
                            <xsl:copy-of select="$childLinksContent/*[count(child::*) > 0]"/>
                        </div>
                    </xsl:if>
                </xsl:when>
                <xsl:otherwise>
                    <xsl:message>Cannot expand the 'webhelp_related_links' component.</xsl:message>                
                </xsl:otherwise>
            </xsl:choose>
        </xsl:if>
    </xsl:template>
    
    <!-- Expand 'webhelp_side_toc' place holder. -->
    <xsl:template match="whc:webhelp_side_toc" mode="copy_template">
        <xsl:if test="oxy:getParameter('webhelp.show.side.toc') = 'yes'">
            <xsl:variable name="sideToc">
                <xsl:call-template name="generateSideToc"/>
            </xsl:variable>
            <!-- If the side toc has only one item, do not generate it -->
            <xsl:if test="count($sideToc/ul/descendant::li) > 1">
                <xsl:variable name="side_toc_content">
                    <div>
                        <xsl:call-template name="generateComponentClassAttribute">
                            <xsl:with-param name="compClass">wh_side_toc</xsl:with-param>
                        </xsl:call-template>
                        <!-- Copy attributes -->
                        <xsl:copy-of select="@* except @class"/>
                        <xsl:if test="@data-tooltip-position">
                            <xsl:attribute name="data-tooltip-position" select="oxygen:getParameter('webhelp.side.toc.tooltip.position')"/>
                        </xsl:if>
                        
                        <xsl:copy-of select="$sideToc"/>
                    </div>
                </xsl:variable>
                
                <xsl:call-template name="outputComponentContent">
                    <xsl:with-param name="compContent" select="$side_toc_content"/>
                    <xsl:with-param name="compName" select="local-name()"/>
                </xsl:call-template>
            </xsl:if>
            
        </xsl:if>
    </xsl:template>
    
    <!-- 
        Load the Side TOC content for the current topic from a temporary file.
    -->
    <xsl:template name="generateSideToc">
        <xsl:variable name="sidetocFileUri">
            <xsl:call-template name="getTempFileURI">
                <xsl:with-param name="extension">.sidetoc</xsl:with-param>
            </xsl:call-template>
        </xsl:variable>
        
        <xsl:if test="doc-available($sidetocFileUri)">
            <xsl:variable name="sidetoc" select="doc($sidetocFileUri)"/>
            <xsl:apply-templates select="$sidetoc" mode="copy-sidetoc"/>
        </xsl:if>
    </xsl:template>
    
    <!-- 
        Load the breadcrumb content for the current topic from a temporary file.
    -->
    <xsl:template name="generateBreadcrumb">
        <xsl:param name="i18n_context" as="element()*"/>
        
        <xsl:variable name="breadcrumbFileUri">
            <xsl:call-template name="getTempFileURI">
                <xsl:with-param name="extension">.brdcrmb</xsl:with-param>
            </xsl:call-template>
        </xsl:variable>
        
        <xsl:if test="doc-available($breadcrumbFileUri)">
            <xsl:variable name="breadcrumb" select="doc($breadcrumbFileUri)"/>
            <xsl:apply-templates select="$breadcrumb" mode="copy-breadcrumb">
                <xsl:with-param name="i18n_context" select="$i18n_context"/>
            </xsl:apply-templates>
        </xsl:if>
    </xsl:template>
    
    <!-- 
        Returns the URI of a file from the temporary directory having 
        the same path as the current processed topic and the given extension.
        
        For example, for the "temp-dir/topics/my-topic.dita" topic file and the "EXT" file extension,
        it returns the URI of the "temp-dir/topics/my-topic.EXT" file. 
    -->
    <xsl:template name="getTempFileURI">
        <xsl:param name="extension"/>
        <xsl:variable name="breadcrumbFileName">
            <xsl:call-template name="replace-extension">
                <xsl:with-param name="filename" select="$FILENAME"/>
                <xsl:with-param name="extension" select="$extension"/>
                <!-- Remove anchors -->
                <xsl:with-param name="ignore-fragment" select="true()"/>
                <xsl:with-param name="forceReplace" select="true()"/>
            </xsl:call-template>
        </xsl:variable>
        <xsl:variable name="tempFilePath" select="concat($TEMPDIR, '/', $FILEDIR, '/', $breadcrumbFileName)"/>
        <xsl:variable name="tempFileUri" select="string(oxygen:makeURL($tempFilePath))"/>
        <xsl:value-of select="$tempFileUri"/>
    </xsl:template>
    
    <xsl:template match="html:ol" mode="copy-breadcrumb">
        <xsl:param name="i18n_context" tunnel="yes" as="element()*"/>
        <xsl:copy>
            <xsl:apply-templates select="@*" mode="#current"/>
            
            <!-- EXM-36063 - Link to home page -->
            <li>
                <xsl:variable name="homeText">
                    <xsl:choose>
                        <xsl:when test="exists($i18n_context)">                            
                            <xsl:for-each select="$i18n_context[1]">
                                <xsl:call-template name="getWebhelpString">
                                    <xsl:with-param name="stringName" select="'label.home'"/>
                                </xsl:call-template>
                            </xsl:for-each>
                        </xsl:when>
                        <xsl:otherwise>Home</xsl:otherwise>
                    </xsl:choose>
                </xsl:variable>
                
                <span class="home">
                    <!-- Use a span inside the 'a' element, such that users can hide the text and add a background image. -->
                    <a href="{concat($PATH2PROJ, 'index', $OUTEXT)}"><span><xsl:value-of select="$homeText"/></span></a>
                </span>
            </li>
            
            <xsl:apply-templates select="node()" mode="#current"/>
        </xsl:copy>
    </xsl:template>
    
    <!-- Copy template. -->
    <xsl:template match="node() | @*" mode="copy-sidetoc copy-breadcrumb">
        <xsl:copy>
            <xsl:apply-templates select="node() | @* except @data-scope" mode="#current"/>
        </xsl:copy>
    </xsl:template>
    
    <!-- 
        Update the Side TOC and breadcrumb links to be relative to the current topic.
        Currently they are stored relative to the output directory.
        
        Avoid external references and void (fake) links.
    -->
    <xsl:template match="a[@href][@href != $VOID_HREF][not(@data-scope='external')]" mode="copy-sidetoc copy-breadcrumb">
        <xsl:copy>
            <xsl:attribute name="href" select="concat($PATH2PROJ, @href)"/>
            <xsl:apply-templates select="node() | @* except @href" mode="#current"/>
        </xsl:copy>
    </xsl:template>
    
    <xsl:template match="whc:webhelp_navigation_links" mode="copy_template">
        <xsl:param name="ditaot_topicContent" tunnel="yes"/>
        
        <xsl:if test="oxy:getParameter('webhelp.show.navigation.links') = 'yes'">
            <xsl:choose>
                <xsl:when test="exists($ditaot_topicContent)">
                    <div>
                        <xsl:call-template name="generateComponentClassAttribute">
                            <xsl:with-param name="compClass">wh_navigation_links</xsl:with-param>
                        </xsl:call-template>
                        <!-- Copy attributes -->
                        <xsl:copy-of select="@* except @class"/>
                        
                        <xsl:variable name="navLinks"
                            select="$ditaot_topicContent//*[@id = 'topic_navigation_links']"/>
                        <xsl:choose>
                            <xsl:when test="exists($navLinks)">
                                <xsl:apply-templates select="$navLinks" mode="copyNavigationLinks"/>
                            </xsl:when>
                            <xsl:otherwise>
                                <xsl:message>Warn: Cannot find the sideToc component in the DITA-OT
                                    output.</xsl:message>
                            </xsl:otherwise>
                        </xsl:choose>
                    </div>
                </xsl:when>
                <xsl:otherwise>
                    <xsl:message>Error: Cannot expand the 'webhelp_navigation_links' component</xsl:message>
                </xsl:otherwise>
            </xsl:choose>
        </xsl:if>
    </xsl:template>

    <xsl:template match="whc:webhelp_print_link" mode="copy_template">
	    <!-- EXM-36737 - Context node used for messages localization -->
        <xsl:param name="i18n_context" tunnel="yes" as="element()*"/>
        <xsl:if test="oxy:getParameter('webhelp.show.print.link') = 'yes'">
            <xsl:variable name="printThisPage">
                <xsl:choose>
                    <xsl:when test="exists($i18n_context)">
                        <xsl:for-each select="$i18n_context[1]">
                            <xsl:call-template name="getWebhelpString">
                                <xsl:with-param name="stringName" select="'printThisPage'"/>
                            </xsl:call-template>
                        </xsl:for-each>
                    </xsl:when>
                    <xsl:otherwise>Print this page</xsl:otherwise>
                </xsl:choose>
            </xsl:variable>
            <div>
                <xsl:call-template name="generateComponentClassAttribute">
                    <xsl:with-param name="compClass">wh_print_link</xsl:with-param>
                </xsl:call-template>
                <!-- Copy attributes -->
                <xsl:copy-of select="@* except @class"/>
                
                <a href="javascript:window.print();" title="{$printThisPage}"/>
            </div>
        </xsl:if>
    </xsl:template>

    <!-- WH-1405 - Toggle Highlight on a search result -->
    <xsl:template match="whc:webhelp_toggle_highlight" mode="copy_template">
        <xsl:param name="i18n_context" tunnel="yes" as="element()*"/>
        <xsl:if test="oxy:getParameter('webhelp.show.toggle.highlights') = 'yes'">
            <xsl:variable name="toggleHighlights">
                <xsl:choose>
                    <xsl:when test="exists($i18n_context)">
                        <xsl:for-each select="$i18n_context[1]">
                            <xsl:call-template name="getWebhelpString">
                                <xsl:with-param name="stringName" select="'toggleHighlights'"/>
                            </xsl:call-template>
                        </xsl:for-each>
                    </xsl:when>
                    <xsl:otherwise>Show/Hide the highlight</xsl:otherwise>
                </xsl:choose>
            </xsl:variable>
            
            <button class="wh_hide_highlight" title="{$toggleHighlights}"></button>
        </xsl:if>        
    </xsl:template>

    <!-- Expand 'webhelp_breadcrumb' place holder. -->
    <xsl:template match="whc:webhelp_breadcrumb" mode="copy_template">
        <xsl:param name="ditaot_topicContent" tunnel="yes"/>
        <xsl:param name="i18n_context" tunnel="yes" as="element()*"/>
        
        <xsl:if test="oxy:getParameter('webhelp.show.breadcrumb') = 'yes'">
            <xsl:variable name="breadcrumb">
                <div data-tooltip-position="bottom">
                    <xsl:call-template name="generateComponentClassAttribute">
                        <xsl:with-param name="compClass">wh_breadcrumb</xsl:with-param>
                    </xsl:call-template>
                    <!-- Copy attributes -->
                    <xsl:copy-of select="@* except @class"/>
                    
                    <!-- Generate the breadcrumb -->
                    <xsl:call-template name="generateBreadcrumb">
                        <xsl:with-param name="i18n_context" select="$i18n_context"/>
                    </xsl:call-template>
                </div>
            </xsl:variable>
            
            <xsl:call-template name="outputComponentContent">
                <xsl:with-param name="compContent" select="$breadcrumb"/>
                <xsl:with-param name="compName" select="local-name()"/>
            </xsl:call-template>
        </xsl:if>
    </xsl:template>
    
    <xsl:template match="html:html" mode="copy_template">
        <xsl:param name="ditaot_topicContent" tunnel="yes"/>
        
        <xsl:copy>
            <xsl:choose>
                <xsl:when test="exists($ditaot_topicContent/html:html)">
                    <!-- EXM-36308 - Merge attributes -->
                    <xsl:copy-of select="oxygen:mergeHTMLAttributes(
                        'html', 
                        ./@*, 
                        $ditaot_topicContent/html:html/@*)"/>          
                </xsl:when>
                <xsl:otherwise>
                    <xsl:apply-templates select="@*" mode="#current"/>
                </xsl:otherwise>
            </xsl:choose>
            
            <!-- Copy elements -->
            <xsl:apply-templates select="node()" mode="#current"/>
        </xsl:copy>
    </xsl:template>

    <!-- Expand 'webhelp_feedback' place holder. -->
    <xsl:template match="whc:webhelp_feedback" mode="copy_template">
        <xsl:if test="string-length($WEBHELP_PRODUCT_ID)>0 and string-length($WEBHELP_PRODUCT_VERSION)>0">
            <xsl:variable name="feedbackFile" select="doc('../../oxygen-webhelp/feedback.xml')"/>
            <xsl:apply-templates select="$feedbackFile" mode="#current" />
        </xsl:if>
    </xsl:template>

    <!-- Filter the link to parent -->
    <xsl:template match="span[@id = 'topic_navigation_links']/span[contains(@class, 'navparent')]"
        mode="copyNavigationLinks"/>

    <!-- Filter any child nodes of next/prev links -->
    <xsl:template
        match="span[@id = 'topic_navigation_links']/span[contains(@class, 'navprev')]/a/node()"
        mode="copyNavigationLinks"/>
    <xsl:template
        match="span[@id = 'topic_navigation_links']/span[contains(@class, 'navnext')]/a/node()"
        mode="copyNavigationLinks"/>

    <xsl:template match="node() | @*" mode="copyNavigationLinks">
        <xsl:copy>
            <xsl:apply-templates select="node() | @*" mode="#current"/>
        </xsl:copy>
    </xsl:template>

</xsl:stylesheet>
