<?xml version="1.0" encoding="UTF-8"?>
<xsl:stylesheet xmlns:xsl="http://www.w3.org/1999/XSL/Transform"
    xmlns:xs="http://www.w3.org/2001/XMLSchema"
    exclude-result-prefixes="xs"
    version="2.0">
    
    <xsl:param name="SHOWCOMMENTS" select="'NO'"/>    
    
    <!--
    
    <xsl:template name="chapter-setup">
        <html>
            <xsl:call-template name="setTopicLanguage"/>
            <xsl:value-of select="$newline"/>
            <xsl:call-template name="chapterHead"/>
            <xsl:call-template name="chapterBody"/> 
        </html>
    </xsl:template>  
    
    <xsl:template name="ul-child-links">
        <xsl:variable name="children"
            select="descendant::*[contains(@class, ' topic/link ')]
            [@role = ('child', 'descendant')]
            [not(parent::*/@collection-type = 'sequence')]
            [not(ancestor::*[contains(@class, ' topic/linklist ')])]"/>
        <xsl:if test="$children">
            <xsl:value-of select="$newline"/>
            <ul class="ullinks">
                <xsl:value-of select="$newline"/>
                once you've tested that at least one child/descendant exists, apply templates to only the unique ones
                <xsl:apply-templates select="$children[generate-id(.) = generate-id(key('link', related-links:link(.))[1])]"/>
            </ul>
            <xsl:value-of select="$newline"/>
        </xsl:if>
    </xsl:template>
    
    <xsl:template name="next-prev-parent-links">
        <xsl:for-each select="descendant::*[contains(@class, ' topic/link ')]
            [@role = ('parent', 'next', 'previous') and
            generate-id(.) = generate-id(key('link', related-links:link(.))[1])]/parent::*">
            <xsl:value-of select="$newline"/>
            <div class="familylinks">
                <xsl:value-of select="$newline"/>
                
                <xsl:if test="$NOPARENTLINK = 'no' and $include.roles = 'parent'">
                    <xsl:choose>
                        <xsl:when test="*[@href][@role = 'parent']">
                            <xsl:for-each select="*[@href][@role = 'parent']">
                                <div class="parentlink">
                                    <xsl:apply-templates select="."/>
                                </div>
                                <xsl:value-of select="$newline"/>
                            </xsl:for-each>
                        </xsl:when>
                        <xsl:otherwise>
                            <xsl:for-each select="*[@href][@role = 'ancestor'][last()]">
                                <div class="parentlink">
                                    <xsl:call-template name="parentlink"/>
                                </div>
                                <xsl:value-of select="$newline"/>
                            </xsl:for-each>
                        </xsl:otherwise>
                    </xsl:choose>
                </xsl:if>
                
                <xsl:if test="$include.roles = 'previous'">
                    <xsl:for-each select="*[@href][@role = 'previous']">
                        <div class="previouslink">
                            <xsl:apply-templates select="."/>
                        </div>
                        <xsl:value-of select="$newline"/>
                    </xsl:for-each>
                </xsl:if>
                <xsl:if test="$include.roles = 'next'">
                    <xsl:for-each select="*[@href][@role = 'next']">
                        <div class="nextlink">
                            <xsl:apply-templates select="."/>
                        </div>
                        <xsl:value-of select="$newline"/>
                    </xsl:for-each>
                </xsl:if>
            </div>
            <xsl:value-of select="$newline"/>
        </xsl:for-each>
    </xsl:template>
 -->   
 
  <xsl:template name="findBackgroundColor">
    <xsl:choose>
      <xsl:when test="@bg_color">
        <xsl:attribute name="background-color">
          <xsl:value-of select="@bg_color"/>
        </xsl:attribute>
      </xsl:when>
      <xsl:when test="parent::*[contains(@class, ' topic/row ')][@bg_color]">
        <xsl:attribute name="style">background-color:<xsl:value-of select="parent::*[contains(@class, ' topic/row ')]/@bg_color"/></xsl:attribute>
      </xsl:when>
      <xsl:otherwise>
        <xsl:choose>
          <xsl:when test="@namest">
            <xsl:variable name="namest" select="@namest"/>
            <xsl:if test="ancestor::*[contains(@class, ' topic/tgroup ')]/*[contains(@class, ' topic/colspec ')][@colname = $namest]/@bg_color"/>
            <xsl:attribute name="style">background-color:<xsl:value-of select="ancestor::*[contains(@class, ' topic/tgroup ')]/*[contains(@class, ' topic/colspec ')][@colname = $namest]/@bg_color"/></xsl:attribute>
          </xsl:when>
          <xsl:otherwise>
            <xsl:variable name="current_cell">
              <xsl:call-template name="determine-current-cell">
                <xsl:with-param name="dataset" select="preceding-sibling::*[contains(@class, ' topic/entry ')]"/>
              </xsl:call-template>
            </xsl:variable>
            <xsl:if test="ancestor::*[contains(@class, ' topic/tgroup ')]/*[contains(@class, ' topic/colspec ')][number($current_cell)]/@bg_color">
              <xsl:attribute name="style">background-color:<xsl:value-of select="ancestor::*[contains(@class, ' topic/tgroup ')]/*[contains(@class, ' topic/colspec ')][number($current_cell)]/@bg_color"/></xsl:attribute>
            </xsl:if>
          </xsl:otherwise>
        </xsl:choose>
      </xsl:otherwise>
    </xsl:choose>
  </xsl:template>

  <xsl:template name="determine-current-cell">
    <!-- A template to determine the correct colspec element that an individual cell refers too -->
    <xsl:param name="dataset"/>
    <xsl:param name="running_count" select="0"/>
    <xsl:param name="position" select="1"/>
    <xsl:choose>
      <xsl:when test="$position &lt;= count($dataset)">
        <xsl:choose>
          <xsl:when test="$dataset[$position][@namest]">
            <xsl:variable name="namest" select="$dataset[$position]/@namest"/>
            <xsl:variable name="nameend" select="$dataset[$position]/@nameend"/>
            <xsl:variable name="starting_colpec" select="ancestor::*[contains(@class, ' topic/tgroup ')]/*[contains(@class, ' topic/colspec ')][1][@colname = $namest]/position()"/>
            <xsl:variable name="ending_colspec" select="ancestor::*[contains(@class, ' topic/tgroup ')]/*[contains(@class, ' topic/colspec ')][1][@colname = $nameend]/position()"/>
            <xsl:call-template name="determine-current-cell">
              <xsl:with-param name="dataset" select="$dataset"/>
              <xsl:with-param name="running_count" select="$running_count + ($ending_colspec - $starting_colpec) + 1"/>
              <xsl:with-param name="position" select="$position + 1"/>
            </xsl:call-template>
          </xsl:when>
          <xsl:otherwise>
            <xsl:call-template name="determine-current-cell">
              <xsl:with-param name="dataset" select="$dataset"/>
              <xsl:with-param name="running_count" select="$running_count + 1"/>
              <xsl:with-param name="position" select="$position + 1"/>
            </xsl:call-template>
          </xsl:otherwise>

        </xsl:choose>
      </xsl:when>
      <xsl:otherwise>
        <!-- This whole exercise has been to determine how many cells preceed the current one, so add one more to bring us up to the present. -->
        <xsl:value-of select="$running_count + 1"/>
      </xsl:otherwise>
    </xsl:choose>

  </xsl:template>

  <!-- Revision History table -->

  <!-- This section filters the contents of the pmc_revhistory element to determine what parts of them to display in the revision history of external documents -->

  <xsl:template match="*[contains(@class, ' topic/table ')][descendant::pmc-revhistory]" priority="100">
    <!-- This template overrides the stock dita table template so that we can massage the external revision history -->
    <table cellpadding="4" cellspacing="0" summary="" class="table" frame="border" border="1" rules="all">
      <thead class="thead" align="left">
        <tr style="background-color:#cccccc;align:middle">
          <th class="entry" valign="top" width="10%" id="d1510e1574"> Issue </th>
          <th class="entry" valign="top" width="15%" id="d1510e1574"> Date </th>
          <th class="entry" valign="top" width="75%" id="d1510e1574"> Description </th>
        </tr>
      </thead>
      <tbody class="tbody">
        <xsl:for-each select="descendant::pmc-revhistory/pmc-revision">
          <xsl:choose>
            <xsl:when test="@role='internal' or @otherprops='internal'"/>
            <xsl:when test="@role='external' or @otherprops='external'">
              <tr class="row">
                <td class="entry" valign="top" width="10%" headers="d1510e1574 ">
                  <p>
                    <xsl:value-of select="pmc-rev-number"/>
                  </p>
                </td>
                <td class="entry" valign="top" width="15%" headers="d1510e1574 ">
                  <p>
                    <xsl:value-of select="pmc-date"/>
                  </p>
                </td>
                <td class="entry" valign="top" width="75%" headers="d1510e1574 ">
                  <xsl:apply-templates select="pmc-revisionhistory" mode="revhistory-passthrough"/>
                </td>
              </tr>
            </xsl:when>
            <xsl:when test="descendant::*/@role='external' or descendant::*/@otherprops='external'">
              <tr class="row">
                <td class="entry" valign="top" width="10%" headers="d1510e1574 ">
                  <p>
                    <xsl:value-of select="pmc-rev-number"/>
                  </p>
                </td>
                <td class="entry" valign="top" width="15%" headers="d1510e1574 ">
                  <p>
                    <xsl:value-of select="pmc-date"/>
                  </p>
                </td>
                <td class="entry" valign="top" width="75%" headers="d1510e1574 ">
                  <xsl:apply-templates select="pmc-description" mode="revisionhistory"/>
                </td>
              </tr>
            </xsl:when>
            <xsl:otherwise>
              <tr class="row">
                <td class="entry" valign="top" width="10%" headers="d1510e1574 ">
                  <p>
                    <xsl:value-of select="pmc-rev-number"/>
                  </p>
                </td>
                <td class="entry" valign="top" width="15%" headers="d1510e1574 ">
                  <p>
                    <xsl:value-of select="pmc-date"/>
                  </p>
                </td>
                <td class="entry" valign="top" width="75%" headers="d1510e1574 ">
                  <xsl:apply-templates select="pmc-description" mode="revisionhistory-strip-internal"/>
                </td>
              </tr>
            </xsl:otherwise>
          </xsl:choose>
        </xsl:for-each>
      </tbody>
    </table>

  </xsl:template>

  <xsl:template match="pmc_revdescription | pmc-description">
    <xsl:apply-templates/>
  </xsl:template>

  <xsl:template match="pmc_revdescription | pmc-description" mode="revhistory-passthrough">
    <xsl:apply-templates mode="revhistory-passthrough"/>
  </xsl:template>

  <xsl:template match="pmc_revdescription | pmc-description" mode="revisionhistory">
    <xsl:choose>
      <xsl:when test="@role='external'or @otherprops='external'">
        <xsl:apply-templates mode="revhistory-passthrough"/>
      </xsl:when>
      <xsl:when test="descendant::node()/@role='external' or descendant::node()/@otherprops='external'">
        <xsl:apply-templates mode="revisionhistory"/>
      </xsl:when>
      <xsl:otherwise>
        <xsl:apply-templates mode="revhistory-passthrough"/>
      </xsl:otherwise>
    </xsl:choose>
  </xsl:template>

  <xsl:template match="ol" mode="revisionhistory">
    <xsl:choose>
      <xsl:when test="@role='external' or @otherprops='external'">
        <ol>
          <xsl:apply-templates mode="revhistory-passthrough"/>
        </ol>
      </xsl:when>
      <xsl:when test="descendant::node()/@role='external' or descendant::node()/@otherprops='external'">
        <ol>
          <xsl:apply-templates mode="revisionhistory"/>
        </ol>
      </xsl:when>
      <xsl:otherwise>
        <ol>
          <xsl:apply-templates mode="revisionhistory"/>
        </ol>
      </xsl:otherwise>
    </xsl:choose>
  </xsl:template>

  <xsl:template match="ul" mode="revisionhistory">
    <xsl:choose>
      <xsl:when test="@role='external' or @otherprops='external'">
        <ul>
          <xsl:apply-templates mode="revhistory-passthrough"/>
        </ul>
      </xsl:when>
      <xsl:when test="descendant::node()/@role='external' or descendant::node()/@otherprops='external'">
        <ul>
          <xsl:apply-templates mode="revisionhistory"/>
        </ul>
      </xsl:when>
      <xsl:otherwise>
        <ul>
          <xsl:apply-templates mode="revisionhistory"/>
        </ul>
      </xsl:otherwise>
    </xsl:choose>
  </xsl:template>

  <xsl:template match="ul" mode="revhistory-passthrough">
    <ul>
      <xsl:apply-templates mode="revhistory-passthrough"/>
    </ul>
  </xsl:template>

  <xsl:template match="ol" mode="revhistory-passthrough">
    <ol>
      <xsl:apply-templates mode="revhistory-passthrough"/>
    </ol>
  </xsl:template>

  <xsl:template match="listitem | li" mode="revisionhistory">
    <xsl:choose>
      <xsl:when test="@role='external' or @otherprops='external'">
        <li>
          <xsl:apply-templates/>
        </li>
      </xsl:when>
      <xsl:when test="descendant::node()/@role='external' or descendant::node()/@otherprops='external'">
        <li>
          <xsl:apply-templates mode="revisionhistory"/>
        </li>
      </xsl:when>
      <xsl:otherwise/>
    </xsl:choose>
  </xsl:template>

  <xsl:template match="li" mode="revhistory-passthrough">
    <li>
      <xsl:apply-templates/>
    </li>
  </xsl:template>

  <xsl:template match="p" mode="revisionhistory">
    <xsl:if test="@otherprops='external'">
      <p>
        <xsl:apply-templates/>
      </p>
    </xsl:if>
  </xsl:template>

  <xsl:template match="p" mode="revhistory-passthrough">
    <p>
      <xsl:apply-templates/>
    </p>
  </xsl:template>

  <xsl:template match="p[ancestor::pmc_iso]">
    <p>
      <xsl:apply-templates/>
    </p>
  </xsl:template>

  <!-- The following sections should strip any parts of the revision history that are designated "internal" -->

  <xsl:template match="pmc-revisionhistory" mode="revisionhistory-strip-internal">
    <xsl:choose>
      <xsl:when test="@role='internal' or @otherprops='internal'"/>
      <xsl:when test="descendant::node()/@role='internal' or descendant::node()/@otherprops='internal'">
        <xsl:apply-templates mode="revisionhistory-strip-internal"/>
      </xsl:when>
      <xsl:otherwise>
        <xsl:apply-templates/>
      </xsl:otherwise>
    </xsl:choose>
  </xsl:template>

  <xsl:template match="p" mode="revisionhistory-strip-internal">
    <xsl:choose>
      <xsl:when test="@otherprops='internal' or @role='internal'"/>
      <xsl:otherwise>
        <p>
          <xsl:apply-templates/>
        </p>
      </xsl:otherwise>
    </xsl:choose>
  </xsl:template>

  <xsl:template match="ul" mode="revisionhistory-strip-internal">
    <xsl:choose>
      <xsl:when test="@role='internal' or @otherprops='internal'"/>
      <xsl:when test="descendant::node()/@role='internal' or descendant::node()/@otherprops='internal'">
        <ul>
          <xsl:apply-templates mode="revisionhistory-strip-internal"/>
        </ul>
      </xsl:when>
      <xsl:otherwise>
        <ul>
          <xsl:apply-templates/>
        </ul>
      </xsl:otherwise>
    </xsl:choose>
  </xsl:template>

  <xsl:template match="ol" mode="revisionhistory-strip-internal">
    <xsl:choose>
      <xsl:when test="@role='internal' or @otherprops='internal'"/>
      <xsl:when test="descendant::node()/@role='internal' or descendant::node()/@otherprops='internal'">
        <ol>
          <xsl:apply-templates mode="revisionhistory-strip-internal"/>
        </ol>
      </xsl:when>
      <xsl:otherwise>
        <ol>
          <xsl:apply-templates/>
        </ol>
      </xsl:otherwise>
    </xsl:choose>
  </xsl:template>

  <xsl:template match="li" mode="revisionhistory-strip-internal">
    <xsl:choose>
      <xsl:when test="@role='internal' or @otherprops='internal'"/>
      <xsl:when test="descendant::node()/@role='internal' or descendant::node()/@otherprops='internal'">
        <li>
          <xsl:apply-templates mode="revisionhistory-strip-internal"/>
        </li>
      </xsl:when>
      <xsl:otherwise>
        <li>
          <xsl:apply-templates mode="revisionhistory-strip-internal"/>
        </li>
      </xsl:otherwise>
    </xsl:choose>
  </xsl:template>

  <xsl:template match="p" mode="revisionhistory-strip-internal">
    <xsl:choose>
      <xsl:when test="@otherprops='internal' or @role='internal'"/>
      <xsl:otherwise>
        <p>
          <xsl:apply-templates/>
        </p>
      </xsl:otherwise>
    </xsl:choose>
  </xsl:template>

  <xsl:template name="tokenize">
    <xsl:param name="string"/>
    <xsl:param name="separator" select="' '"/>
    <xsl:choose>
      <xsl:when test="contains($string,$separator)">
        <token>
          <xsl:value-of select="substring-before($string,$separator)"/>
        </token>
        <xsl:call-template name="tokenize">
          <xsl:with-param name="string" select="substring-after($string,$separator)"/>
        </xsl:call-template>
      </xsl:when>
      <xsl:otherwise>
        <token>
          <xsl:value-of select="$string"/>
        </token>
      </xsl:otherwise>
    </xsl:choose>
  </xsl:template>
    
</xsl:stylesheet>