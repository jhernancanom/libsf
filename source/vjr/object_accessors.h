//////////
//
// /libsf/source/vjr/object_accessors.h
//
//////
// Version 0.52
// Copyright (c) 2014 by Rick C. Hodgin
//////
// Last update:
//	   Jul.13.2014
//////
// Change log:
//	   Jul.13.2014 - Initial creation
//////
//
// This software is released as Liberty Software under a Repeat License, as governed
// by the Public Benefit License v1.0 or later (PBL).
//
// You are free to use, copy, modify and share this software.  However, it can only
// be released under the PBL version indicated, and every project must include a copy
// of the pbl.txt document for its version as is at http://www.libsf.org/licenses/.
//
// For additional information about this project, or to view the license, see:
//
//	   http://www.libsf.org/
//	   http://www.libsf.org/licenses/
//	   http://www.visual-freepro.org/vjr/indexmain.html
//	   http://www.visual-freepro.org/wiki/index.php/PBL
//	   http://www.visual-freepro.org/wiki/index.php/Repeat_License
//
// Thank you.  And may The Lord bless you richly as you lift up your life, your
// talents, your gifts, your praise, unto Him.	In Jesus' name I pray.	Amen.
//
// To jump immediately to a section, search for one of these here or in object_accessors.cpp:
//		OBJECT Properties
//		FORM Properties
//		SUBFORM Properties
//
//////









//////////
// Define the setters and getters
//////
	const s8		cgc_activeColumn[]										= "activeColumn";
	const s8		cgc_activeControl[]										= "activeControl";
	const s8		cgc_activeForm[]										= "activeForm";
	const s8		cgc_activePage[]										= "activePage";
	const s8		cgc_activeRow[]											= "activeRow";
	const s8		cgc_addLineFeeds[]										= "addLineFeeds";
	const s8		cgc_align[]												= "align";
	const s8		cgc_alignment[]											= "alignment";
	const s8		cgc_allowAddNew[]										= "allowAddNew";
	const s8		cgc_allowAutoColumnFit[]								= "allowAutoColumnFit";
	const s8		cgc_allowCellSelection[]								= "allowCellSelection";
	const s8		cgc_allowHeaderSizing[]									= "allowHeaderSizing";
	const s8		cgc_allowOutput[]										= "allowOutput";
	const s8		cgc_allowRowSizing[]									= "allowRowSizing";
	const s8		cgc_allowTabs[]											= "allowTabs";
	const s8		cgc_alwaysOnBottom[]									= "alwaysOnBottom";
	const s8		cgc_alwaysOnTop[]										= "alwaysOnTop";
	const s8		cgc_anchor[]											= "anchor";
	const s8		cgc_application[]										= "application";
	const s8		cgc_autoActivate[]										= "autoActivate";
	const s8		cgc_autoCenter[]										= "autoCenter";
	const s8		cgc_autoCompSource[]									= "autoCompSource";
	const s8		cgc_autoCompTable[]										= "autoCompTable";
	const s8		cgc_autoComplete[]										= "autoComplete";
	const s8		cgc_autoHideScrollBar[]									= "autoHideScrollBar";
	const s8		cgc_autoRelease[]										= "autoRelease";
	const s8		cgc_autoSize[]											= "autoSize";
	const s8		cgc_autoVerbMenu[]										= "autoVerbMenu";
	const s8		cgc_backColor[]											= "backColor";
	const s8		cgc_backStyle[]											= "backStyle";
	const s8		cgc_baseClass[]											= "baseClass";
	const s8		cgc_bindControls[]										= "bindControls";
	const s8		cgc_borderColor[]										= "borderColor";
	const s8		cgc_borderStyle[]										= "borderStyle";
	const s8		cgc_borderWidth[]										= "borderWidth";
	const s8		cgc_bound[]												= "bound";
	const s8		cgc_boundColumn[]										= "boundColumn";
	const s8		cgc_boundTo[]											= "boundTo";
	const s8		cgc_bufferMode[]										= "bufferMode";
	const s8		cgc_buttonCount[]										= "buttonCount";
	const s8		cgc_cancel[]											= "cancel";
	const s8		cgc_caption[]											= "caption";
	const s8		cgc_centered[]											= "centered";
	const s8		cgc_century[]											= "century";
	const s8		cgc_childOrder[]										= "childOrder";
	const s8		cgc_class[]												= "class";
	const s8		cgc_classLibrary[]										= "classLibrary";
	const s8		cgc_clipControls[]										= "clipControls";
	const s8		cgc_closable[]											= "closable";
	const s8		cgc_colorScheme[]										= "colorScheme";
	const s8		cgc_colorSource[]										= "colorSource";
	const s8		cgc_columnCount[]										= "columnCount";
	const s8		cgc_columnLines[]										= "columnLines";
	const s8		cgc_columnOrder[]										= "columnOrder";
	const s8		cgc_columnWidths[]										= "columnWidths";
	const s8		cgc_columns[]											= "columns";
	const s8		cgc_comment[]											= "comment";
	const s8		cgc_continuousScroll[]									= "continuousScroll";
	const s8		cgc_controlBox[]										= "controlBox";
	const s8		cgc_controlCount[]										= "controlCount";
	const s8		cgc_controlSource[]										= "controlSource";
	const s8		cgc_controls[]											= "controls";
	const s8		cgc_count[]												= "count";
	const s8		cgc_currentControl[]									= "currentControl";
	const s8		cgc_currentX[]											= "currentX";
	const s8		cgc_currentY[]											= "currentY";
	const s8		cgc_curvature[]											= "curvature";
	const s8		cgc_dEClass[]											= "dEClass";
	const s8		cgc_dEClassLibrary[]									= "dEClassLibrary";
	const s8		cgc_dataEnvironment[]									= "dataEnvironment";
	const s8		cgc_dataSession[]										= "dataSession";
	const s8		cgc_dataSessionID[]										= "dataSessionID";
	const s8		cgc_dateFormat[]										= "dateFormat";
	const s8		cgc_dateMark[]											= "dateMark";
	const s8		cgc_defOLELCID[]										= "defOLELCID";
	const s8		cgc_default[]											= "default";
	const s8		cgc_deleteMark[]										= "deleteMark";
	const s8		cgc_desktop[]											= "desktop";
	const s8		cgc_details[]											= "details";
	const s8		cgc_disabledBackColor[]									= "disabledBackColor";
	const s8		cgc_disabledForeColor[]									= "disabledForeColor";
	const s8		cgc_disabledItemBackColor[]								= "disabledItemBackColor";
	const s8		cgc_disabledItemForeColor[]								= "disabledItemForeColor";
	const s8		cgc_disabledPicture[]									= "disabledPicture";
	const s8		cgc_displayCount[]										= "displayCount";
	const s8		cgc_displayValue[]										= "displayValue";
	const s8		cgc_doCreate[]											= "doCreate";
	const s8		cgc_dockPosition[]										= "dockPosition";
	const s8		cgc_dockable[]											= "dockable";
	const s8		cgc_docked[]											= "docked";
	const s8		cgc_documentFile[]										= "documentFile";
	const s8		cgc_downPicture[]										= "downPicture";
	const s8		cgc_dragIcon[]											= "dragIcon";
	const s8		cgc_dragMode[]											= "dragMode";
	const s8		cgc_drawMode[]											= "drawMode";
	const s8		cgc_drawStyle[]											= "drawStyle";
	const s8		cgc_drawWidth[]											= "drawWidth";
	const s8		cgc_dynamicAlignment[]									= "dynamicAlignment";
	const s8		cgc_dynamicBackColor[]									= "dynamicBackColor";
	const s8		cgc_dynamicCurrentControl[]								= "dynamicCurrentControl";
	const s8		cgc_dynamicFontBold[]									= "dynamicFontBold";
	const s8		cgc_dynamicFontItalic[]									= "dynamicFontItalic";
	const s8		cgc_dynamicFontName[]									= "dynamicFontName";
	const s8		cgc_dynamicFontOutline[]								= "dynamicFontOutline";
	const s8		cgc_dynamicFontShadow[]									= "dynamicFontShadow";
	const s8		cgc_dynamicFontSize[]									= "dynamicFontSize";
	const s8		cgc_dynamicFontStrikeThru[]								= "dynamicFontStrikeThru";
	const s8		cgc_dynamicFontUnderline[]								= "dynamicFontUnderline";
	const s8		cgc_dynamicForeColor[]									= "dynamicForeColor";
	const s8		cgc_dynamicInputMask[]									= "dynamicInputMask";
	const s8		cgc_enableHyperlinks[]									= "enableHyperlinks";
	const s8		cgc_enabled[]											= "enabled";
	const s8		cgc_errorNo[]											= "errorNo";
	const s8		cgc_fillColor[]											= "fillColor";
	const s8		cgc_fillStyle[]											= "fillStyle";
	const s8		cgc_firstElement[]										= "firstElement";
	const s8		cgc_fontBold[]											= "fontBold";
	const s8		cgc_fontCharSet[]										= "fontCharSet";
	const s8		cgc_fontCondense[]										= "fontCondense";
	const s8		cgc_fontExtend[]										= "fontExtend";
	const s8		cgc_fontItalic[]										= "fontItalic";
	const s8		cgc_fontName[]											= "fontName";
	const s8		cgc_fontOutline[]										= "fontOutline";
	const s8		cgc_fontShadow[]										= "fontShadow";
	const s8		cgc_fontSize[]											= "fontSize";
	const s8		cgc_fontStrikeThru[]									= "fontStrikeThru";
	const s8		cgc_fontUnderLine[]										= "fontUnderLine";
	const s8		cgc_fontUnderline[]										= "fontUnderline";
	const s8		cgc_foreColor[]											= "foreColor";
	const s8		cgc_formCount[]											= "formCount";
	const s8		cgc_format[]											= "format";
	const s8		cgc_forms[]												= "forms";
	const s8		cgc_gridLineColor[]										= "gridLineColor";
	const s8		cgc_gridLineWidth[]										= "gridLineWidth";
	const s8		cgc_gridLines[]											= "gridLines";
	const s8		cgc_hScrollSmallChange[]								= "hScrollSmallChange";
	const s8		cgc_hWnd[]												= "hWnd";
	const s8		cgc_halfHeightCaption[]									= "halfHeightCaption";
	const s8		cgc_headerClass[]										= "headerClass";
	const s8		cgc_headerClassLibrary[]								= "headerClassLibrary";
	const s8		cgc_headerHeight[]										= "headerHeight";
	const s8		cgc_height[]											= "height";
	const s8		cgc_helpContextID[]										= "helpContextID";
	const s8		cgc_hideSelection[]										= "hideSelection";
	const s8		cgc_highLight[]											= "highLight";
	const s8		cgc_highLightRow[]										= "highLightRow";
	const s8		cgc_highlightBackColor[]								= "highlightBackColor";
	const s8		cgc_highlightForeColor[]								= "highlightForeColor";
	const s8		cgc_highlightRowLineWidth[]								= "highlightRowLineWidth";
	const s8		cgc_highlightStyle[]									= "highlightStyle";
	const s8		cgc_hostName[]											= "hostName";
	const s8		cgc_hours[]												= "hours";
	const s8		cgc_iMEMode[]											= "iMEMode";
	const s8		cgc_icon[]												= "icon";
	const s8		cgc_increment[]											= "increment";
	const s8		cgc_incrementalSearch[]									= "incrementalSearch";
	const s8		cgc_inputMask[]											= "inputMask";
	const s8		cgc_integralHeight[]									= "integralHeight";
	const s8		cgc_interval[]											= "interval";
	const s8		cgc_itemBackColor[]										= "itemBackColor";
	const s8		cgc_itemData[]											= "itemData";
	const s8		cgc_itemForeColor[]										= "itemForeColor";
	const s8		cgc_itemIDData[]										= "itemIDData";
	const s8		cgc_itemTips[]											= "itemTips";
	const s8		cgc_keyPreview[]										= "keyPreview";
	const s8		cgc_keySort[]											= "keySort";
	const s8		cgc_keyboardHighValue[]									= "keyboardHighValue";
	const s8		cgc_keyboardLowValue[]									= "keyboardLowValue";
	const s8		cgc_left[]												= "left";
	const s8		cgc_leftColumn[]										= "leftColumn";
	const s8		cgc_lineContents[]										= "lineContents";
	const s8		cgc_lineNo[]											= "lineNo";
	const s8		cgc_lineSlant[]											= "lineSlant";
	const s8		cgc_linkMaster[]										= "linkMaster";
	const s8		cgc_list[]												= "list";
	const s8		cgc_listCount[]											= "listCount";
	const s8		cgc_listIndex[]											= "listIndex";
	const s8		cgc_listItem[]											= "listItem";
	const s8		cgc_listItemID[]										= "listItemID";
	const s8		cgc_lockColumns[]										= "lockColumns";
	const s8		cgc_lockColumnsLeft[]									= "lockColumnsLeft";
	const s8		cgc_lockScreen[]										= "lockScreen";
	const s8		cgc_mDIForm[]											= "mDIForm";
	const s8		cgc_macDesktop[]										= "macDesktop";
	const s8		cgc_margin[]											= "margin";
	const s8		cgc_maxButton[]											= "maxButton";
	const s8		cgc_maxHeight[]											= "maxHeight";
	const s8		cgc_maxLeft[]											= "maxLeft";
	const s8		cgc_maxLength[]											= "maxLength";
	const s8		cgc_maxTop[]											= "maxTop";
	const s8		cgc_maxWidth[]											= "maxWidth";
	const s8		cgc_memberClass[]										= "memberClass";
	const s8		cgc_memberClassLibrary[]								= "memberClassLibrary";
	const s8		cgc_memoWindow[]										= "memoWindow";
	const s8		cgc_message[]											= "message";
	const s8		cgc_minButton[]											= "minButton";
	const s8		cgc_minHeight[]											= "minHeight";
	const s8		cgc_minWidth[]											= "minWidth";
	const s8		cgc_mouseIcon[]											= "mouseIcon";
	const s8		cgc_mousePointer[]										= "mousePointer";
	const s8		cgc_movable[]											= "movable";
	const s8		cgc_moverBars[]											= "moverBars";
	const s8		cgc_multiSelect[]										= "multiSelect";
	const s8		cgc_name[]												= "name";
	const s8		cgc_newIndex[]											= "newIndex";
	const s8		cgc_newItemID[]											= "newItemID";
	const s8		cgc_nullDisplay[]										= "nullDisplay";
	const s8		cgc_numberOfElements[]									= "numberOfElements";
	const s8		cgc_oLEClass[]											= "oLEClass";
	const s8		cgc_oLEDragMode[]										= "oLEDragMode";
	const s8		cgc_oLEDragPicture[]									= "oLEDragPicture";
	const s8		cgc_oLEDropEffects[]									= "oLEDropEffects";
	const s8		cgc_oLEDropHasData[]									= "oLEDropHasData";
	const s8		cgc_oLEDropMode[]										= "oLEDropMode";
	const s8		cgc_oLEDropTextInsertion[]								= "oLEDropTextInsertion";
	const s8		cgc_oLELCID[]											= "oLELCID";
	const s8		cgc_oLETypeAllowed[]									= "oLETypeAllowed";
	const s8		cgc_object[]											= "object";
	const s8		cgc_objects[]											= "objects";
	const s8		cgc_openWindow[]										= "openWindow";
	const s8		cgc_optimize[]											= "optimize";
	const s8		cgc_pageCount[]											= "pageCount";
	const s8		cgc_pageHeight[]										= "pageHeight";
	const s8		cgc_pageOrder[]											= "pageOrder";
	const s8		cgc_pageWidth[]											= "pageWidth";
	const s8		cgc_pages[]												= "pages";
	const s8		cgc_panel[]												= "panel";
	const s8		cgc_panelLink[]											= "panelLink";
	const s8		cgc_parent[]											= "parent";
	const s8		cgc_parentClass[]										= "parentClass";
	const s8		cgc_partition[]											= "partition";
	const s8		cgc_passwordChar[]										= "passwordChar";
	const s8		cgc_picture[]											= "picture";
	const s8		cgc_pictureMargin[]										= "pictureMargin";
	const s8		cgc_picturePosition[]									= "picturePosition";
	const s8		cgc_pictureSelectionDisplay[]							= "pictureSelectionDisplay";
	const s8		cgc_pictureSpacing[]									= "pictureSpacing";
	const s8		cgc_pictureVal[]										= "pictureVal";
	const s8		cgc_polyPoints[]										= "polyPoints";
	const s8		cgc_procedure[]											= "procedure";
	const s8		cgc_readBackColor[]										= "readBackColor";
	const s8		cgc_readCycle[]											= "readCycle";
	const s8		cgc_readForeColor[]										= "readForeColor";
	const s8		cgc_readLock[]											= "readLock";
	const s8		cgc_readMouse[]											= "readMouse";
	const s8		cgc_readOnly[]											= "readOnly";
	const s8		cgc_readSave[]											= "readSave";
	const s8		cgc_readTimeOut[]										= "readTimeOut";
	const s8		cgc_recordMark[]										= "recordMark";
	const s8		cgc_recordSource[]										= "recordSource";
	const s8		cgc_recordSourceType[]									= "recordSourceType";
	const s8		cgc_relationalExpr[]									= "relationalExpr";
	const s8		cgc_relativeColumn[]									= "relativeColumn";
	const s8		cgc_relativeRow[]										= "relativeRow";
	const s8		cgc_releaseType[]										= "releaseType";
	const s8		cgc_resizable[]											= "resizable";
	const s8		cgc_rightToLeft[]										= "rightToLeft";
	const s8		cgc_rotateFlip[]										= "rotateFlip";
	const s8		cgc_rotation[]											= "rotation";
	const s8		cgc_rowColChange[]										= "rowColChange";
	const s8		cgc_rowHeight[]											= "rowHeight";
	const s8		cgc_rowSource[]											= "rowSource";
	const s8		cgc_rowSourceType[]										= "rowSourceType";
	const s8		cgc_scaleMode[]											= "scaleMode";
	const s8		cgc_scrollBars[]										= "scrollBars";
	const s8		cgc_seconds[]											= "seconds";
	const s8		cgc_selLength[]											= "selLength";
	const s8		cgc_selStart[]											= "selStart";
	const s8		cgc_selText[]											= "selText";
	const s8		cgc_selectOnEntry[]										= "selectOnEntry";
	const s8		cgc_selected[]											= "selected";
	const s8		cgc_selectedBackColor[]									= "selectedBackColor";
	const s8		cgc_selectedForeColor[]									= "selectedForeColor";
	const s8		cgc_selectedID[]										= "selectedID";
	const s8		cgc_selectedItemBackColor[]								= "selectedItemBackColor";
	const s8		cgc_selectedItemForeColor[]								= "selectedItemForeColor";
	const s8		cgc_showInTaskbar[]										= "showInTaskbar";
	const s8		cgc_showTips[]											= "showTips";
	const s8		cgc_showWindow[]										= "showWindow";
	const s8		cgc_sizable[]											= "sizable";
	const s8		cgc_sizeBox[]											= "sizeBox";
	const s8		cgc_sorted[]											= "sorted";
	const s8		cgc_sparse[]											= "sparse";
	const s8		cgc_specialEffect[]										= "specialEffect";
	const s8		cgc_spinnerHighValue[]									= "spinnerHighValue";
	const s8		cgc_spinnerLowValue[]									= "spinnerLowValue";
	const s8		cgc_splitBar[]											= "splitBar";
	const s8		cgc_stackLevel[]										= "stackLevel";
	const s8		cgc_statusBarText[]										= "statusBarText";
	const s8		cgc_stretch[]											= "stretch";
	const s8		cgc_strictDateEntry[]									= "strictDateEntry";
	const s8		cgc_style[]												= "style";
	const s8		cgc_tabIndex[]											= "tabIndex";
	const s8		cgc_tabOrientation[]									= "tabOrientation";
	const s8		cgc_tabStop[]											= "tabStop";
	const s8		cgc_tabStyle[]											= "tabStyle";
	const s8		cgc_tabs[]												= "tabs";
	const s8		cgc_tag[]												= "tag";
	const s8		cgc_terminateRead[]										= "terminateRead";
	const s8		cgc_text[]												= "text";
	const s8		cgc_themes[]											= "themes";
	const s8		cgc_titleBar[]											= "titleBar";
	const s8		cgc_toolTipText[]										= "toolTipText";
	const s8		cgc_top[]												= "top";
	const s8		cgc_topIndex[]											= "topIndex";
	const s8		cgc_topItemID[]											= "topItemID";
	const s8		cgc_userValue[]											= "userValue";
	const s8		cgc_vScrollSmallChange[]								= "vScrollSmallChange";
	const s8		cgc_value[]												= "value";
	const s8		cgc_view[]												= "view";
	const s8		cgc_viewPortHeight[]									= "viewPortHeight";
	const s8		cgc_viewPortLeft[]										= "viewPortLeft";
	const s8		cgc_viewPortTop[]										= "viewPortTop";
	const s8		cgc_viewPortWidth[]										= "viewPortWidth";
	const s8		cgc_visible[]											= "visible";
	const s8		cgc_visualEffect[]										= "visualEffect";
	const s8		cgc_whatsThisButton[]									= "whatsThisButton";
	const s8		cgc_whatsThisHelp[]										= "whatsThisHelp";
	const s8		cgc_whatsThisHelpID[]									= "whatsThisHelpID";
	const s8		cgc_width[]												= "width";
	const s8		cgc_windowList[]										= "windowList";
	const s8		cgc_windowState[]										= "windowState";
	const s8		cgc_windowType[]										= "windowType";
	const s8		cgc_wordWrap[]											= "wordWrap";
	const s8		cgc_zoomBox[]											= "zoomBox";

	const u32		_INDEX_ACTIVECOLUMN										= 0;
	const u32		_INDEX_ACTIVECONTROL									= 1;
	const u32		_INDEX_ACTIVEFORM										= 2;
	const u32		_INDEX_ACTIVEPAGE										= 3;
	const u32		_INDEX_ACTIVEROW										= 4;
	const u32		_INDEX_ADDLINEFEEDS										= 5;
	const u32		_INDEX_ALIGN											= 6;
	const u32		_INDEX_ALIGNMENT										= 7;
	const u32		_INDEX_ALLOWADDNEW										= 8;
	const u32		_INDEX_ALLOWAUTOCOLUMNFIT								= 9;
	const u32		_INDEX_ALLOWCELLSELECTION								= 10;
	const u32		_INDEX_ALLOWHEADERSIZING								= 11;
	const u32		_INDEX_ALLOWOUTPUT										= 12;
	const u32		_INDEX_ALLOWROWSIZING									= 13;
	const u32		_INDEX_ALLOWTABS										= 14;
	const u32		_INDEX_ALWAYSONBOTTOM									= 15;
	const u32		_INDEX_ALWAYSONTOP										= 16;
	const u32		_INDEX_ANCHOR											= 17;
	const u32		_INDEX_APPLICATION										= 18;
	const u32		_INDEX_AUTOACTIVATE										= 19;
	const u32		_INDEX_AUTOCENTER										= 20;
	const u32		_INDEX_AUTOCOMPSOURCE									= 21;
	const u32		_INDEX_AUTOCOMPTABLE									= 22;
	const u32		_INDEX_AUTOCOMPLETE										= 23;
	const u32		_INDEX_AUTOHIDESCROLLBAR								= 24;
	const u32		_INDEX_AUTORELEASE										= 25;
	const u32		_INDEX_AUTOSIZE											= 26;
	const u32		_INDEX_AUTOVERBMENU										= 27;
	const u32		_INDEX_BACKCOLOR										= 28;
	const u32		_INDEX_BACKSTYLE										= 29;
	const u32		_INDEX_BASECLASS										= 30;
	const u32		_INDEX_BINDCONTROLS										= 31;
	const u32		_INDEX_BORDERCOLOR										= 32;
	const u32		_INDEX_BORDERSTYLE										= 33;
	const u32		_INDEX_BORDERWIDTH										= 34;
	const u32		_INDEX_BOUND											= 35;
	const u32		_INDEX_BOUNDCOLUMN										= 36;
	const u32		_INDEX_BOUNDTO											= 37;
	const u32		_INDEX_BUFFERMODE										= 38;
	const u32		_INDEX_BUTTONCOUNT										= 39;
	const u32		_INDEX_CANCEL											= 40;
	const u32		_INDEX_CAPTION											= 41;
	const u32		_INDEX_CENTERED											= 42;
	const u32		_INDEX_CENTURY											= 43;
	const u32		_INDEX_CHILDORDER										= 44;
	const u32		_INDEX_CLASS											= 45;
	const u32		_INDEX_CLASSLIBRARY										= 46;
	const u32		_INDEX_CLIPCONTROLS										= 47;
	const u32		_INDEX_CLOSABLE											= 48;
	const u32		_INDEX_COLORSCHEME										= 49;
	const u32		_INDEX_COLORSOURCE										= 50;
	const u32		_INDEX_COLUMNCOUNT										= 51;
	const u32		_INDEX_COLUMNLINES										= 52;
	const u32		_INDEX_COLUMNORDER										= 53;
	const u32		_INDEX_COLUMNWIDTHS										= 54;
	const u32		_INDEX_COLUMNS											= 55;
	const u32		_INDEX_COMMENT											= 56;
	const u32		_INDEX_CONTINUOUSSCROLL									= 57;
	const u32		_INDEX_CONTROLBOX										= 58;
	const u32		_INDEX_CONTROLCOUNT										= 59;
	const u32		_INDEX_CONTROLSOURCE									= 60;
	const u32		_INDEX_CONTROLS											= 61;
	const u32		_INDEX_COUNT											= 62;
	const u32		_INDEX_CURRENTCONTROL									= 63;
	const u32		_INDEX_CURRENTX											= 64;
	const u32		_INDEX_CURRENTY											= 65;
	const u32		_INDEX_CURVATURE										= 66;
	const u32		_INDEX_DECLASS											= 67;
	const u32		_INDEX_DECLASSLIBRARY									= 68;
	const u32		_INDEX_DATAENVIRONMENT									= 69;
	const u32		_INDEX_DATASESSION										= 70;
	const u32		_INDEX_DATASESSIONID									= 71;
	const u32		_INDEX_DATEFORMAT										= 72;
	const u32		_INDEX_DATEMARK											= 73;
	const u32		_INDEX_DEFOLELCID										= 74;
	const u32		_INDEX_DEFAULT											= 75;
	const u32		_INDEX_DELETEMARK										= 76;
	const u32		_INDEX_DESKTOP											= 77;
	const u32		_INDEX_DETAILS											= 78;
	const u32		_INDEX_DISABLEDBACKCOLOR								= 79;
	const u32		_INDEX_DISABLEDFORECOLOR								= 80;
	const u32		_INDEX_DISABLEDITEMBACKCOLOR							= 81;
	const u32		_INDEX_DISABLEDITEMFORECOLOR							= 82;
	const u32		_INDEX_DISABLEDPICTURE									= 83;
	const u32		_INDEX_DISPLAYCOUNT										= 84;
	const u32		_INDEX_DISPLAYVALUE										= 85;
	const u32		_INDEX_DOCREATE											= 86;
	const u32		_INDEX_DOCKPOSITION										= 87;
	const u32		_INDEX_DOCKABLE											= 88;
	const u32		_INDEX_DOCKED											= 89;
	const u32		_INDEX_DOCUMENTFILE										= 90;
	const u32		_INDEX_DOWNPICTURE										= 91;
	const u32		_INDEX_DRAGICON											= 92;
	const u32		_INDEX_DRAGMODE											= 93;
	const u32		_INDEX_DRAWMODE											= 94;
	const u32		_INDEX_DRAWSTYLE										= 95;
	const u32		_INDEX_DRAWWIDTH										= 96;
	const u32		_INDEX_DYNAMICALIGNMENT									= 97;
	const u32		_INDEX_DYNAMICBACKCOLOR									= 98;
	const u32		_INDEX_DYNAMICCURRENTCONTROL							= 99;
	const u32		_INDEX_DYNAMICFONTBOLD									= 100;
	const u32		_INDEX_DYNAMICFONTITALIC								= 101;
	const u32		_INDEX_DYNAMICFONTNAME									= 102;
	const u32		_INDEX_DYNAMICFONTOUTLINE								= 103;
	const u32		_INDEX_DYNAMICFONTSHADOW								= 104;
	const u32		_INDEX_DYNAMICFONTSIZE									= 105;
	const u32		_INDEX_DYNAMICFONTSTRIKETHRU							= 106;
	const u32		_INDEX_DYNAMICFONTUNDERLINE								= 107;
	const u32		_INDEX_DYNAMICFORECOLOR									= 108;
	const u32		_INDEX_DYNAMICINPUTMASK									= 109;
	const u32		_INDEX_ENABLEHYPERLINKS									= 110;
	const u32		_INDEX_ENABLED											= 111;
	const u32		_INDEX_ERRORNO											= 112;
	const u32		_INDEX_FILLCOLOR										= 113;
	const u32		_INDEX_FILLSTYLE										= 114;
	const u32		_INDEX_FIRSTELEMENT										= 115;
	const u32		_INDEX_FONTBOLD											= 116;
	const u32		_INDEX_FONTCHARSET										= 117;
	const u32		_INDEX_FONTCONDENSE										= 118;
	const u32		_INDEX_FONTEXTEND										= 119;
	const u32		_INDEX_FONTITALIC										= 120;
	const u32		_INDEX_FONTNAME											= 121;
	const u32		_INDEX_FONTOUTLINE										= 122;
	const u32		_INDEX_FONTSHADOW										= 123;
	const u32		_INDEX_FONTSIZE											= 124;
	const u32		_INDEX_FONTSTRIKETHRU									= 125;
	const u32		_INDEX_FONTUNDERLINE									= 126;
	const u32		_INDEX_FORECOLOR										= 127;
	const u32		_INDEX_FORMCOUNT										= 128;
	const u32		_INDEX_FORMAT											= 129;
	const u32		_INDEX_FORMS											= 130;
	const u32		_INDEX_GRIDLINECOLOR									= 131;
	const u32		_INDEX_GRIDLINEWIDTH									= 132;
	const u32		_INDEX_GRIDLINES										= 133;
	const u32		_INDEX_HSCROLLSMALLCHANGE								= 134;
	const u32		_INDEX_HWND												= 135;
	const u32		_INDEX_HALFHEIGHTCAPTION								= 136;
	const u32		_INDEX_HEADERCLASS										= 137;
	const u32		_INDEX_HEADERCLASSLIBRARY								= 138;
	const u32		_INDEX_HEADERHEIGHT										= 139;
	const u32		_INDEX_HEIGHT											= 140;
	const u32		_INDEX_HELPCONTEXTID									= 141;
	const u32		_INDEX_HIDESELECTION									= 142;
	const u32		_INDEX_HIGHLIGHT										= 143;
	const u32		_INDEX_HIGHLIGHTROW										= 144;
	const u32		_INDEX_HIGHLIGHTBACKCOLOR								= 145;
	const u32		_INDEX_HIGHLIGHTFORECOLOR								= 146;
	const u32		_INDEX_HIGHLIGHTROWLINEWIDTH							= 147;
	const u32		_INDEX_HIGHLIGHTSTYLE									= 148;
	const u32		_INDEX_HOSTNAME											= 149;
	const u32		_INDEX_HOURS											= 150;
	const u32		_INDEX_ICON												= 151;
	const u32		_INDEX_IMEMODE											= 152;
	const u32		_INDEX_INCREMENT										= 153;
	const u32		_INDEX_INCREMENTALSEARCH								= 154;
	const u32		_INDEX_INPUTMASK										= 155;
	const u32		_INDEX_INTEGRALHEIGHT									= 156;
	const u32		_INDEX_INTERVAL											= 157;
	const u32		_INDEX_ITEMBACKCOLOR									= 158;
	const u32		_INDEX_ITEMDATA											= 159;
	const u32		_INDEX_ITEMFORECOLOR									= 160;
	const u32		_INDEX_ITEMIDDATA										= 161;
	const u32		_INDEX_ITEMTIPS											= 162;
	const u32		_INDEX_KEYPREVIEW										= 163;
	const u32		_INDEX_KEYSORT											= 164;
	const u32		_INDEX_KEYBOARDHIGHVALUE								= 165;
	const u32		_INDEX_KEYBOARDLOWVALUE									= 166;
	const u32		_INDEX_LEFT												= 167;
	const u32		_INDEX_LEFTCOLUMN										= 168;
	const u32		_INDEX_LINECONTENTS										= 169;
	const u32		_INDEX_LINENO											= 170;
	const u32		_INDEX_LINESLANT										= 171;
	const u32		_INDEX_LINKMASTER										= 172;
	const u32		_INDEX_LIST												= 173;
	const u32		_INDEX_LISTCOUNT										= 174;
	const u32		_INDEX_LISTINDEX										= 175;
	const u32		_INDEX_LISTITEM											= 176;
	const u32		_INDEX_LISTITEMID										= 177;
	const u32		_INDEX_LOCKCOLUMNS										= 178;
	const u32		_INDEX_LOCKCOLUMNSLEFT									= 179;
	const u32		_INDEX_LOCKSCREEN										= 180;
	const u32		_INDEX_MDIFORM											= 181;
	const u32		_INDEX_MACDESKTOP										= 182;
	const u32		_INDEX_MARGIN											= 183;
	const u32		_INDEX_MAXBUTTON										= 184;
	const u32		_INDEX_MAXHEIGHT										= 185;
	const u32		_INDEX_MAXLEFT											= 186;
	const u32		_INDEX_MAXLENGTH										= 187;
	const u32		_INDEX_MAXTOP											= 188;
	const u32		_INDEX_MAXWIDTH											= 189;
	const u32		_INDEX_MEMBERCLASS										= 190;
	const u32		_INDEX_MEMBERCLASSLIBRARY								= 191;
	const u32		_INDEX_MEMOWINDOW										= 192;
	const u32		_INDEX_MESSAGE											= 193;
	const u32		_INDEX_MINBUTTON										= 194;
	const u32		_INDEX_MINHEIGHT										= 195;
	const u32		_INDEX_MINWIDTH											= 196;
	const u32		_INDEX_MOUSEICON										= 197;
	const u32		_INDEX_MOUSEPOINTER										= 198;
	const u32		_INDEX_MOVABLE											= 199;
	const u32		_INDEX_MOVERBARS										= 200;
	const u32		_INDEX_MULTISELECT										= 201;
	const u32		_INDEX_NAME												= 202;
	const u32		_INDEX_NEWINDEX											= 203;
	const u32		_INDEX_NEWITEMID										= 204;
	const u32		_INDEX_NULLDISPLAY										= 205;
	const u32		_INDEX_NUMBEROFELEMENTS									= 206;
	const u32		_INDEX_OLECLASS											= 207;
	const u32		_INDEX_OLEDRAGMODE										= 208;
	const u32		_INDEX_OLEDRAGPICTURE									= 209;
	const u32		_INDEX_OLEDROPEFFECTS									= 210;
	const u32		_INDEX_OLEDROPHASDATA									= 211;
	const u32		_INDEX_OLEDROPMODE										= 212;
	const u32		_INDEX_OLEDROPTEXTINSERTION								= 213;
	const u32		_INDEX_OLELCID											= 214;
	const u32		_INDEX_OLETYPEALLOWED									= 215;
	const u32		_INDEX_OBJECT											= 216;
	const u32		_INDEX_OBJECTS											= 217;
	const u32		_INDEX_OPENWINDOW										= 218;
	const u32		_INDEX_OPTIMIZE											= 219;
	const u32		_INDEX_PAGECOUNT										= 220;
	const u32		_INDEX_PAGEHEIGHT										= 221;
	const u32		_INDEX_PAGEORDER										= 222;
	const u32		_INDEX_PAGEWIDTH										= 223;
	const u32		_INDEX_PAGES											= 224;
	const u32		_INDEX_PANEL											= 225;
	const u32		_INDEX_PANELLINK										= 226;
	const u32		_INDEX_PARENT											= 227;
	const u32		_INDEX_PARENTCLASS										= 228;
	const u32		_INDEX_PARTITION										= 229;
	const u32		_INDEX_PASSWORDCHAR										= 230;
	const u32		_INDEX_PICTURE											= 231;
	const u32		_INDEX_PICTUREMARGIN									= 232;
	const u32		_INDEX_PICTUREPOSITION									= 233;
	const u32		_INDEX_PICTURESELECTIONDISPLAY							= 234;
	const u32		_INDEX_PICTURESPACING									= 235;
	const u32		_INDEX_PICTUREVAL										= 236;
	const u32		_INDEX_POLYPOINTS										= 237;
	const u32		_INDEX_PROCEDURE										= 238;
	const u32		_INDEX_READBACKCOLOR									= 239;
	const u32		_INDEX_READCYCLE										= 240;
	const u32		_INDEX_READFORECOLOR									= 241;
	const u32		_INDEX_READLOCK											= 242;
	const u32		_INDEX_READMOUSE										= 243;
	const u32		_INDEX_READONLY											= 244;
	const u32		_INDEX_READSAVE											= 245;
	const u32		_INDEX_READTIMEOUT										= 246;
	const u32		_INDEX_RECORDMARK										= 247;
	const u32		_INDEX_RECORDSOURCE										= 248;
	const u32		_INDEX_RECORDSOURCETYPE									= 249;
	const u32		_INDEX_RELATIONALEXPR									= 250;
	const u32		_INDEX_RELATIVECOLUMN									= 251;
	const u32		_INDEX_RELATIVEROW										= 252;
	const u32		_INDEX_RELEASETYPE										= 253;
	const u32		_INDEX_RESIZABLE										= 254;
	const u32		_INDEX_RIGHTTOLEFT										= 255;
	const u32		_INDEX_ROTATEFLIP										= 256;
	const u32		_INDEX_ROTATION											= 257;
	const u32		_INDEX_ROWCOLCHANGE										= 258;
	const u32		_INDEX_ROWHEIGHT										= 259;
	const u32		_INDEX_ROWSOURCE										= 260;
	const u32		_INDEX_ROWSOURCETYPE									= 261;
	const u32		_INDEX_SCALEMODE										= 262;
	const u32		_INDEX_SCROLLBARS										= 263;
	const u32		_INDEX_SECONDS											= 264;
	const u32		_INDEX_SELLENGTH										= 265;
	const u32		_INDEX_SELSTART											= 266;
	const u32		_INDEX_SELTEXT											= 267;
	const u32		_INDEX_SELECTONENTRY									= 268;
	const u32		_INDEX_SELECTED											= 269;
	const u32		_INDEX_SELECTEDBACKCOLOR								= 270;
	const u32		_INDEX_SELECTEDFORECOLOR								= 271;
	const u32		_INDEX_SELECTEDID										= 272;
	const u32		_INDEX_SELECTEDITEMBACKCOLOR							= 273;
	const u32		_INDEX_SELECTEDITEMFORECOLOR							= 274;
	const u32		_INDEX_SHOWINTASKBAR									= 275;
	const u32		_INDEX_SHOWTIPS											= 276;
	const u32		_INDEX_SHOWWINDOW										= 277;
	const u32		_INDEX_SIZABLE											= 278;
	const u32		_INDEX_SIZEBOX											= 279;
	const u32		_INDEX_SORTED											= 280;
	const u32		_INDEX_SPARSE											= 281;
	const u32		_INDEX_SPECIALEFFECT									= 282;
	const u32		_INDEX_SPINNERHIGHVALUE									= 283;
	const u32		_INDEX_SPINNERLOWVALUE									= 284;
	const u32		_INDEX_SPLITBAR											= 285;
	const u32		_INDEX_STACKLEVEL										= 286;
	const u32		_INDEX_STATUSBARTEXT									= 287;
	const u32		_INDEX_STRETCH											= 288;
	const u32		_INDEX_STRICTDATEENTRY									= 289;
	const u32		_INDEX_STYLE											= 290;
	const u32		_INDEX_TABINDEX											= 291;
	const u32		_INDEX_TABORIENTATION									= 292;
	const u32		_INDEX_TABSTOP											= 293;
	const u32		_INDEX_TABSTYLE											= 294;
	const u32		_INDEX_TABS												= 295;
	const u32		_INDEX_TAG												= 296;
	const u32		_INDEX_TERMINATEREAD									= 297;
	const u32		_INDEX_TEXT												= 298;
	const u32		_INDEX_THEMES											= 299;
	const u32		_INDEX_TITLEBAR											= 300;
	const u32		_INDEX_TOOLTIPTEXT										= 301;
	const u32		_INDEX_TOP												= 302;
	const u32		_INDEX_TOPINDEX											= 303;
	const u32		_INDEX_TOPITEMID										= 304;
	const u32		_INDEX_USERVALUE										= 305;
	const u32		_INDEX_VSCROLLSMALLCHANGE								= 306;
	const u32		_INDEX_VALUE											= 307;
	const u32		_INDEX_VIEW												= 308;
	const u32		_INDEX_VIEWPORTHEIGHT									= 309;
	const u32		_INDEX_VIEWPORTLEFT										= 310;
	const u32		_INDEX_VIEWPORTTOP										= 311;
	const u32		_INDEX_VIEWPORTWIDTH									= 312;
	const u32		_INDEX_VISIBLE											= 313;
	const u32		_INDEX_VISUALEFFECT										= 314;
	const u32		_INDEX_WHATSTHISBUTTON									= 315;
	const u32		_INDEX_WHATSTHISHELP									= 316;
	const u32		_INDEX_WHATSTHISHELPID									= 317;
	const u32		_INDEX_WIDTH											= 318;
	const u32		_INDEX_WINDOWLIST										= 319;
	const u32		_INDEX_WINDOWSTATE										= 320;
	const u32		_INDEX_WINDOWTYPE										= 321;
	const u32		_INDEX_WORDWRAP											= 322;
	const u32		_INDEX_ZOOMBOX											= 323;

	bool			iObj_set_activeColumn									(SObject* obj, SVariable* var);
	bool			iObj_set_activeControl									(SObject* obj, SVariable* var);
	bool			iObj_set_activeForm										(SObject* obj, SVariable* var);
	bool			iObj_set_activePage										(SObject* obj, SVariable* var);
	bool			iObj_set_activeRow										(SObject* obj, SVariable* var);
	bool			iObj_set_addLineFeeds									(SObject* obj, SVariable* var);
	bool			iObj_set_align											(SObject* obj, SVariable* var);
	bool			iObj_set_alignment										(SObject* obj, SVariable* var);
	bool			iObj_set_allowAddNew									(SObject* obj, SVariable* var);
	bool			iObj_set_allowAutoColumnFit								(SObject* obj, SVariable* var);
	bool			iObj_set_allowCellSelection								(SObject* obj, SVariable* var);
	bool			iObj_set_allowHeaderSizing								(SObject* obj, SVariable* var);
	bool			iObj_set_allowOutput									(SObject* obj, SVariable* var);
	bool			iObj_set_allowRowSizing									(SObject* obj, SVariable* var);
	bool			iObj_set_allowTabs										(SObject* obj, SVariable* var);
	bool			iObj_set_alwaysOnBottom									(SObject* obj, SVariable* var);
	bool			iObj_set_alwaysOnTop									(SObject* obj, SVariable* var);
	bool			iObj_set_anchor											(SObject* obj, SVariable* var);
	bool			iObj_set_application									(SObject* obj, SVariable* var);
	bool			iObj_set_autoActivate									(SObject* obj, SVariable* var);
	bool			iObj_set_autoCenter										(SObject* obj, SVariable* var);
	bool			iObj_set_autoCompSource									(SObject* obj, SVariable* var);
	bool			iObj_set_autoCompTable									(SObject* obj, SVariable* var);
	bool			iObj_set_autoComplete									(SObject* obj, SVariable* var);
	bool			iObj_set_autoHideScrollBar								(SObject* obj, SVariable* var);
	bool			iObj_set_autoRelease									(SObject* obj, SVariable* var);
	bool			iObj_set_autoSize										(SObject* obj, SVariable* var);
	bool			iObj_set_autoVerbMenu									(SObject* obj, SVariable* var);
	bool			iObj_set_backColor										(SObject* obj, SVariable* var);
	bool			iObj_set_backStyle										(SObject* obj, SVariable* var);
	bool			iObj_set_baseClass										(SObject* obj, SVariable* var);
	bool			iObj_set_bindControls									(SObject* obj, SVariable* var);
	bool			iObj_set_borderColor									(SObject* obj, SVariable* var);
	bool			iObj_set_borderStyle									(SObject* obj, SVariable* var);
	bool			iObj_set_borderWidth									(SObject* obj, SVariable* var);
	bool			iObj_set_bound											(SObject* obj, SVariable* var);
	bool			iObj_set_boundColumn									(SObject* obj, SVariable* var);
	bool			iObj_set_boundTo										(SObject* obj, SVariable* var);
	bool			iObj_set_bufferMode										(SObject* obj, SVariable* var);
	bool			iObj_set_buttonCount									(SObject* obj, SVariable* var);
	bool			iObj_set_cancel											(SObject* obj, SVariable* var);
	bool			iObj_set_caption										(SObject* obj, SVariable* var);
	bool			iObj_set_centered										(SObject* obj, SVariable* var);
	bool			iObj_set_century										(SObject* obj, SVariable* var);
	bool			iObj_set_childOrder										(SObject* obj, SVariable* var);
	bool			iObj_set_class											(SObject* obj, SVariable* var);
	bool			iObj_set_classLibrary									(SObject* obj, SVariable* var);
	bool			iObj_set_clipControls									(SObject* obj, SVariable* var);
	bool			iObj_set_closable										(SObject* obj, SVariable* var);
	bool			iObj_set_colorScheme									(SObject* obj, SVariable* var);
	bool			iObj_set_colorSource									(SObject* obj, SVariable* var);
	bool			iObj_set_columnCount									(SObject* obj, SVariable* var);
	bool			iObj_set_columnLines									(SObject* obj, SVariable* var);
	bool			iObj_set_columnOrder									(SObject* obj, SVariable* var);
	bool			iObj_set_columnWidths									(SObject* obj, SVariable* var);
	bool			iObj_set_columns										(SObject* obj, SVariable* var);
	bool			iObj_set_comment										(SObject* obj, SVariable* var);
	bool			iObj_set_continuousScroll								(SObject* obj, SVariable* var);
	bool			iObj_set_controlBox										(SObject* obj, SVariable* var);
	bool			iObj_set_controlCount									(SObject* obj, SVariable* var);
	bool			iObj_set_controlSource									(SObject* obj, SVariable* var);
	bool			iObj_set_controls										(SObject* obj, SVariable* var);
	bool			iObj_set_count											(SObject* obj, SVariable* var);
	bool			iObj_set_currentControl									(SObject* obj, SVariable* var);
	bool			iObj_set_currentX										(SObject* obj, SVariable* var);
	bool			iObj_set_currentY										(SObject* obj, SVariable* var);
	bool			iObj_set_curvature										(SObject* obj, SVariable* var);
	bool			iObj_set_dEClass										(SObject* obj, SVariable* var);
	bool			iObj_set_dEClassLibrary									(SObject* obj, SVariable* var);
	bool			iObj_set_dataEnvironment								(SObject* obj, SVariable* var);
	bool			iObj_set_dataSession									(SObject* obj, SVariable* var);
	bool			iObj_set_dataSessionID									(SObject* obj, SVariable* var);
	bool			iObj_set_dateFormat										(SObject* obj, SVariable* var);
	bool			iObj_set_dateMark										(SObject* obj, SVariable* var);
	bool			iObj_set_defOLELCID										(SObject* obj, SVariable* var);
	bool			iObj_set_default										(SObject* obj, SVariable* var);
	bool			iObj_set_deleteMark										(SObject* obj, SVariable* var);
	bool			iObj_set_desktop										(SObject* obj, SVariable* var);
	bool			iObj_set_details										(SObject* obj, SVariable* var);
	bool			iObj_set_disabledBackColor								(SObject* obj, SVariable* var);
	bool			iObj_set_disabledForeColor								(SObject* obj, SVariable* var);
	bool			iObj_set_disabledItemBackColor							(SObject* obj, SVariable* var);
	bool			iObj_set_disabledItemForeColor							(SObject* obj, SVariable* var);
	bool			iObj_set_disabledPicture								(SObject* obj, SVariable* var);
	bool			iObj_set_displayCount									(SObject* obj, SVariable* var);
	bool			iObj_set_displayValue									(SObject* obj, SVariable* var);
	bool			iObj_set_doCreate										(SObject* obj, SVariable* var);
	bool			iObj_set_dockPosition									(SObject* obj, SVariable* var);
	bool			iObj_set_dockable										(SObject* obj, SVariable* var);
	bool			iObj_set_docked											(SObject* obj, SVariable* var);
	bool			iObj_set_documentFile									(SObject* obj, SVariable* var);
	bool			iObj_set_downPicture									(SObject* obj, SVariable* var);
	bool			iObj_set_dragIcon										(SObject* obj, SVariable* var);
	bool			iObj_set_dragMode										(SObject* obj, SVariable* var);
	bool			iObj_set_drawMode										(SObject* obj, SVariable* var);
	bool			iObj_set_drawStyle										(SObject* obj, SVariable* var);
	bool			iObj_set_drawWidth										(SObject* obj, SVariable* var);
	bool			iObj_set_dynamicAlignment								(SObject* obj, SVariable* var);
	bool			iObj_set_dynamicBackColor								(SObject* obj, SVariable* var);
	bool			iObj_set_dynamicCurrentControl							(SObject* obj, SVariable* var);
	bool			iObj_set_dynamicFontBold								(SObject* obj, SVariable* var);
	bool			iObj_set_dynamicFontItalic								(SObject* obj, SVariable* var);
	bool			iObj_set_dynamicFontName								(SObject* obj, SVariable* var);
	bool			iObj_set_dynamicFontOutline								(SObject* obj, SVariable* var);
	bool			iObj_set_dynamicFontShadow								(SObject* obj, SVariable* var);
	bool			iObj_set_dynamicFontSize								(SObject* obj, SVariable* var);
	bool			iObj_set_dynamicFontStrikeThru							(SObject* obj, SVariable* var);
	bool			iObj_set_dynamicFontUnderline							(SObject* obj, SVariable* var);
	bool			iObj_set_dynamicForeColor								(SObject* obj, SVariable* var);
	bool			iObj_set_dynamicInputMask								(SObject* obj, SVariable* var);
	bool			iObj_set_enableHyperlinks								(SObject* obj, SVariable* var);
	bool			iObj_set_enabled										(SObject* obj, SVariable* var);
	bool			iObj_set_errorNo										(SObject* obj, SVariable* var);
	bool			iObj_set_fillColor										(SObject* obj, SVariable* var);
	bool			iObj_set_fillStyle										(SObject* obj, SVariable* var);
	bool			iObj_set_firstElement									(SObject* obj, SVariable* var);
	bool			iObj_set_fontBold										(SObject* obj, SVariable* var);
	bool			iObj_set_fontCharSet									(SObject* obj, SVariable* var);
	bool			iObj_set_fontCondense									(SObject* obj, SVariable* var);
	bool			iObj_set_fontExtend										(SObject* obj, SVariable* var);
	bool			iObj_set_fontItalic										(SObject* obj, SVariable* var);
	bool			iObj_set_fontName										(SObject* obj, SVariable* var);
	bool			iObj_set_fontOutline									(SObject* obj, SVariable* var);
	bool			iObj_set_fontShadow										(SObject* obj, SVariable* var);
	bool			iObj_set_fontSize										(SObject* obj, SVariable* var);
	bool			iObj_set_fontStrikeThru									(SObject* obj, SVariable* var);
	bool			iObj_set_fontUnderLine									(SObject* obj, SVariable* var);
	bool			iObj_set_fontUnderline									(SObject* obj, SVariable* var);
	bool			iObj_set_foreColor										(SObject* obj, SVariable* var);
	bool			iObj_set_formCount										(SObject* obj, SVariable* var);
	bool			iObj_set_format											(SObject* obj, SVariable* var);
	bool			iObj_set_forms											(SObject* obj, SVariable* var);
	bool			iObj_set_gridLineColor									(SObject* obj, SVariable* var);
	bool			iObj_set_gridLineWidth									(SObject* obj, SVariable* var);
	bool			iObj_set_gridLines										(SObject* obj, SVariable* var);
	bool			iObj_set_hScrollSmallChange								(SObject* obj, SVariable* var);
	bool			iObj_set_hWnd											(SObject* obj, SVariable* var);
	bool			iObj_set_halfHeightCaption								(SObject* obj, SVariable* var);
	bool			iObj_set_headerClass									(SObject* obj, SVariable* var);
	bool			iObj_set_headerClassLibrary								(SObject* obj, SVariable* var);
	bool			iObj_set_headerHeight									(SObject* obj, SVariable* var);
	bool			iObj_set_height											(SObject* obj, SVariable* var);
	bool			iObj_set_helpContextID									(SObject* obj, SVariable* var);
	bool			iObj_set_hideSelection									(SObject* obj, SVariable* var);
	bool			iObj_set_highLight										(SObject* obj, SVariable* var);
	bool			iObj_set_highLightRow									(SObject* obj, SVariable* var);
	bool			iObj_set_highlightBackColor								(SObject* obj, SVariable* var);
	bool			iObj_set_highlightForeColor								(SObject* obj, SVariable* var);
	bool			iObj_set_highlightRowLineWidth							(SObject* obj, SVariable* var);
	bool			iObj_set_highlightStyle									(SObject* obj, SVariable* var);
	bool			iObj_set_hostName										(SObject* obj, SVariable* var);
	bool			iObj_set_hours											(SObject* obj, SVariable* var);
	bool			iObj_set_iMEMode										(SObject* obj, SVariable* var);
	bool			iObj_set_icon											(SObject* obj, SBitmap* bmp);
	bool			iObj_set_increment										(SObject* obj, SVariable* var);
	bool			iObj_set_incrementalSearch								(SObject* obj, SVariable* var);
	bool			iObj_set_inputMask										(SObject* obj, SVariable* var);
	bool			iObj_set_integralHeight									(SObject* obj, SVariable* var);
	bool			iObj_set_interval										(SObject* obj, SVariable* var);
	bool			iObj_set_itemBackColor									(SObject* obj, SVariable* var);
	bool			iObj_set_itemData										(SObject* obj, SVariable* var);
	bool			iObj_set_itemForeColor									(SObject* obj, SVariable* var);
	bool			iObj_set_itemIDData										(SObject* obj, SVariable* var);
	bool			iObj_set_itemTips										(SObject* obj, SVariable* var);
	bool			iObj_set_keyPreview										(SObject* obj, SVariable* var);
	bool			iObj_set_keySort										(SObject* obj, SVariable* var);
	bool			iObj_set_keyboardHighValue								(SObject* obj, SVariable* var);
	bool			iObj_set_keyboardLowValue								(SObject* obj, SVariable* var);
	bool			iObj_set_left											(SObject* obj, SVariable* var);
	bool			iObj_set_leftColumn										(SObject* obj, SVariable* var);
	bool			iObj_set_lineContents									(SObject* obj, SVariable* var);
	bool			iObj_set_lineNo											(SObject* obj, SVariable* var);
	bool			iObj_set_lineSlant										(SObject* obj, SVariable* var);
	bool			iObj_set_linkMaster										(SObject* obj, SVariable* var);
	bool			iObj_set_list											(SObject* obj, SVariable* var);
	bool			iObj_set_listCount										(SObject* obj, SVariable* var);
	bool			iObj_set_listIndex										(SObject* obj, SVariable* var);
	bool			iObj_set_listItem										(SObject* obj, SVariable* var);
	bool			iObj_set_listItemID										(SObject* obj, SVariable* var);
	bool			iObj_set_lockColumns									(SObject* obj, SVariable* var);
	bool			iObj_set_lockColumnsLeft								(SObject* obj, SVariable* var);
	bool			iObj_set_lockScreen										(SObject* obj, SVariable* var);
	bool			iObj_set_mDIForm										(SObject* obj, SVariable* var);
	bool			iObj_set_macDesktop										(SObject* obj, SVariable* var);
	bool			iObj_set_margin											(SObject* obj, SVariable* var);
	bool			iObj_set_maxButton										(SObject* obj, SVariable* var);
	bool			iObj_set_maxHeight										(SObject* obj, SVariable* var);
	bool			iObj_set_maxLeft										(SObject* obj, SVariable* var);
	bool			iObj_set_maxLength										(SObject* obj, SVariable* var);
	bool			iObj_set_maxTop											(SObject* obj, SVariable* var);
	bool			iObj_set_maxWidth										(SObject* obj, SVariable* var);
	bool			iObj_set_memberClass									(SObject* obj, SVariable* var);
	bool			iObj_set_memberClassLibrary								(SObject* obj, SVariable* var);
	bool			iObj_set_memoWindow										(SObject* obj, SVariable* var);
	bool			iObj_set_message										(SObject* obj, SVariable* var);
	bool			iObj_set_minButton										(SObject* obj, SVariable* var);
	bool			iObj_set_minHeight										(SObject* obj, SVariable* var);
	bool			iObj_set_minWidth										(SObject* obj, SVariable* var);
	bool			iObj_set_mouseIcon										(SObject* obj, SBitmap* bmp);
	bool			iObj_set_mousePointer									(SObject* obj, SVariable* var);
	bool			iObj_set_movable										(SObject* obj, SVariable* var);
	bool			iObj_set_moverBars										(SObject* obj, SVariable* var);
	bool			iObj_set_multiSelect									(SObject* obj, SVariable* var);
	bool			iObj_set_name											(SObject* obj, SVariable* var);
	bool			iObj_set_newIndex										(SObject* obj, SVariable* var);
	bool			iObj_set_newItemID										(SObject* obj, SVariable* var);
	bool			iObj_set_nullDisplay									(SObject* obj, SVariable* var);
	bool			iObj_set_numberOfElements								(SObject* obj, SVariable* var);
	bool			iObj_set_oLEClass										(SObject* obj, SVariable* var);
	bool			iObj_set_oLEDragMode									(SObject* obj, SVariable* var);
	bool			iObj_set_oLEDragPicture									(SObject* obj, SBitmap* bmp);
	bool			iObj_set_oLEDropEffects									(SObject* obj, SVariable* var);
	bool			iObj_set_oLEDropHasData									(SObject* obj, SVariable* var);
	bool			iObj_set_oLEDropMode									(SObject* obj, SVariable* var);
	bool			iObj_set_oLEDropTextInsertion							(SObject* obj, SVariable* var);
	bool			iObj_set_oLELCID										(SObject* obj, SVariable* var);
	bool			iObj_set_oLETypeAllowed									(SObject* obj, SVariable* var);
	bool			iObj_set_object											(SObject* obj, SVariable* var);
	bool			iObj_set_objects										(SObject* obj, SVariable* var);
	bool			iObj_set_openWindow										(SObject* obj, SVariable* var);
	bool			iObj_set_optimize										(SObject* obj, SVariable* var);
	bool			iObj_set_pageCount										(SObject* obj, SVariable* var);
	bool			iObj_set_pageHeight										(SObject* obj, SVariable* var);
	bool			iObj_set_pageOrder										(SObject* obj, SVariable* var);
	bool			iObj_set_pageWidth										(SObject* obj, SVariable* var);
	bool			iObj_set_pages											(SObject* obj, SVariable* var);
	bool			iObj_set_panel											(SObject* obj, SVariable* var);
	bool			iObj_set_panelLink										(SObject* obj, SVariable* var);
	bool			iObj_set_parent											(SObject* obj, SVariable* var);
	bool			iObj_set_parentClass									(SObject* obj, SVariable* var);
	bool			iObj_set_partition										(SObject* obj, SVariable* var);
	bool			iObj_set_passwordChar									(SObject* obj, SVariable* var);
	bool			iObj_set_picture										(SObject* obj, SVariable* var);
	bool			iObj_set_pictureMargin									(SObject* obj, SVariable* var);
	bool			iObj_set_picturePosition								(SObject* obj, SVariable* var);
	bool			iObj_set_pictureSelectionDisplay						(SObject* obj, SVariable* var);
	bool			iObj_set_pictureSpacing									(SObject* obj, SVariable* var);
	bool			iObj_set_pictureVal										(SObject* obj, SVariable* var);
	bool			iObj_set_polyPoints										(SObject* obj, SVariable* var);
	bool			iObj_set_procedure										(SObject* obj, SVariable* var);
	bool			iObj_set_readBackColor									(SObject* obj, SVariable* var);
	bool			iObj_set_readCycle										(SObject* obj, SVariable* var);
	bool			iObj_set_readForeColor									(SObject* obj, SVariable* var);
	bool			iObj_set_readLock										(SObject* obj, SVariable* var);
	bool			iObj_set_readMouse										(SObject* obj, SVariable* var);
	bool			iObj_set_readOnly										(SObject* obj, SVariable* var);
	bool			iObj_set_readSave										(SObject* obj, SVariable* var);
	bool			iObj_set_readTimeOut									(SObject* obj, SVariable* var);
	bool			iObj_set_recordMark										(SObject* obj, SVariable* var);
	bool			iObj_set_recordSource									(SObject* obj, SVariable* var);
	bool			iObj_set_recordSourceType								(SObject* obj, SVariable* var);
	bool			iObj_set_relationalExpr									(SObject* obj, SVariable* var);
	bool			iObj_set_relativeColumn									(SObject* obj, SVariable* var);
	bool			iObj_set_relativeRow									(SObject* obj, SVariable* var);
	bool			iObj_set_releaseType									(SObject* obj, SVariable* var);
	bool			iObj_set_resizable										(SObject* obj, SVariable* var);
	bool			iObj_set_rightToLeft									(SObject* obj, SVariable* var);
	bool			iObj_set_rotateFlip										(SObject* obj, SVariable* var);
	bool			iObj_set_rotation										(SObject* obj, SVariable* var);
	bool			iObj_set_rowColChange									(SObject* obj, SVariable* var);
	bool			iObj_set_rowHeight										(SObject* obj, SVariable* var);
	bool			iObj_set_rowSource										(SObject* obj, SVariable* var);
	bool			iObj_set_rowSourceType									(SObject* obj, SVariable* var);
	bool			iObj_set_scaleMode										(SObject* obj, SVariable* var);
	bool			iObj_set_scrollBars										(SObject* obj, SVariable* var);
	bool			iObj_set_seconds										(SObject* obj, SVariable* var);
	bool			iObj_set_selLength										(SObject* obj, SVariable* var);
	bool			iObj_set_selStart										(SObject* obj, SVariable* var);
	bool			iObj_set_selText										(SObject* obj, SVariable* var);
	bool			iObj_set_selectOnEntry									(SObject* obj, SVariable* var);
	bool			iObj_set_selected										(SObject* obj, SVariable* var);
	bool			iObj_set_selectedBackColor								(SObject* obj, SVariable* var);
	bool			iObj_set_selectedForeColor								(SObject* obj, SVariable* var);
	bool			iObj_set_selectedID										(SObject* obj, SVariable* var);
	bool			iObj_set_selectedItemBackColor							(SObject* obj, SVariable* var);
	bool			iObj_set_selectedItemForeColor							(SObject* obj, SVariable* var);
	bool			iObj_set_showInTaskbar									(SObject* obj, SVariable* var);
	bool			iObj_set_showTips										(SObject* obj, SVariable* var);
	bool			iObj_set_showWindow										(SObject* obj, SVariable* var);
	bool			iObj_set_sizable										(SObject* obj, SVariable* var);
	bool			iObj_set_sizeBox										(SObject* obj, SVariable* var);
	bool			iObj_set_sorted											(SObject* obj, SVariable* var);
	bool			iObj_set_sparse											(SObject* obj, SVariable* var);
	bool			iObj_set_specialEffect									(SObject* obj, SVariable* var);
	bool			iObj_set_spinnerHighValue								(SObject* obj, SVariable* var);
	bool			iObj_set_spinnerLowValue								(SObject* obj, SVariable* var);
	bool			iObj_set_splitBar										(SObject* obj, SVariable* var);
	bool			iObj_set_stackLevel										(SObject* obj, SVariable* var);
	bool			iObj_set_statusBarText									(SObject* obj, SVariable* var);
	bool			iObj_set_stretch										(SObject* obj, SVariable* var);
	bool			iObj_set_strictDateEntry								(SObject* obj, SVariable* var);
	bool			iObj_set_style											(SObject* obj, SVariable* var);
	bool			iObj_set_tabIndex										(SObject* obj, SVariable* var);
	bool			iObj_set_tabOrientation									(SObject* obj, SVariable* var);
	bool			iObj_set_tabStop										(SObject* obj, SVariable* var);
	bool			iObj_set_tabStyle										(SObject* obj, SVariable* var);
	bool			iObj_set_tabs											(SObject* obj, SVariable* var);
	bool			iObj_set_tag											(SObject* obj, SVariable* var);
	bool			iObj_set_terminateRead									(SObject* obj, SVariable* var);
	bool			iObj_set_text											(SObject* obj, SVariable* var);
	bool			iObj_set_themes											(SObject* obj, SVariable* var);
	bool			iObj_set_titleBar										(SObject* obj, SVariable* var);
	bool			iObj_set_toolTipText									(SObject* obj, SVariable* var);
	bool			iObj_set_top											(SObject* obj, SVariable* var);
	bool			iObj_set_topIndex										(SObject* obj, SVariable* var);
	bool			iObj_set_topItemID										(SObject* obj, SVariable* var);
	bool			iObj_set_userValue										(SObject* obj, SVariable* var);
	bool			iObj_set_vScrollSmallChange								(SObject* obj, SVariable* var);
	bool			iObj_set_value											(SObject* obj, SVariable* var);
	bool			iObj_set_view											(SObject* obj, SVariable* var);
	bool			iObj_set_viewPortHeight									(SObject* obj, SVariable* var);
	bool			iObj_set_viewPortLeft									(SObject* obj, SVariable* var);
	bool			iObj_set_viewPortTop									(SObject* obj, SVariable* var);
	bool			iObj_set_viewPortWidth									(SObject* obj, SVariable* var);
	bool			iObj_set_visible										(SObject* obj, SVariable* var);
	bool			iObj_set_visualEffect									(SObject* obj, SVariable* var);
	bool			iObj_set_whatsThisButton								(SObject* obj, SVariable* var);
	bool			iObj_set_whatsThisHelp									(SObject* obj, SVariable* var);
	bool			iObj_set_whatsThisHelpID								(SObject* obj, SVariable* var);
	bool			iObj_set_width											(SObject* obj, SVariable* var);
	bool			iObj_set_windowList										(SObject* obj, SVariable* var);
	bool			iObj_set_windowState									(SObject* obj, SVariable* var);
	bool			iObj_set_windowType										(SObject* obj, SVariable* var);
	bool			iObj_set_wordWrap										(SObject* obj, SVariable* var);
	bool			iObj_set_zoomBox										(SObject* obj, SVariable* var);

	SVariable*		iObj_get_activeColumn									(SObject* obj);
	SVariable*		iObj_get_activeControl									(SObject* obj);
	SVariable*		iObj_get_activeForm										(SObject* obj);
	SVariable*		iObj_get_activePage										(SObject* obj);
	SVariable*		iObj_get_activeRow										(SObject* obj);
	SVariable*		iObj_get_addLineFeeds									(SObject* obj);
	SVariable*		iObj_get_align											(SObject* obj);
	SVariable*		iObj_get_alignment										(SObject* obj);
	SVariable*		iObj_get_allowAddNew									(SObject* obj);
	SVariable*		iObj_get_allowAutoColumnFit								(SObject* obj);
	SVariable*		iObj_get_allowCellSelection								(SObject* obj);
	SVariable*		iObj_get_allowHeaderSizing								(SObject* obj);
	SVariable*		iObj_get_allowOutput									(SObject* obj);
	SVariable*		iObj_get_allowRowSizing									(SObject* obj);
	SVariable*		iObj_get_allowTabs										(SObject* obj);
	SVariable*		iObj_get_alwaysOnBottom									(SObject* obj);
	SVariable*		iObj_get_alwaysOnTop									(SObject* obj);
	SVariable*		iObj_get_anchor											(SObject* obj);
	SVariable*		iObj_get_application									(SObject* obj);
	SVariable*		iObj_get_autoActivate									(SObject* obj);
	SVariable*		iObj_get_autoCenter										(SObject* obj);
	SVariable*		iObj_get_autoCompSource									(SObject* obj);
	SVariable*		iObj_get_autoCompTable									(SObject* obj);
	SVariable*		iObj_get_autoComplete									(SObject* obj);
	SVariable*		iObj_get_autoHideScrollBar								(SObject* obj);
	SVariable*		iObj_get_autoRelease									(SObject* obj);
	SVariable*		iObj_get_autoSize										(SObject* obj);
	SVariable*		iObj_get_autoVerbMenu									(SObject* obj);
	SVariable*		iObj_get_backColor										(SObject* obj);
	SVariable*		iObj_get_backStyle										(SObject* obj);
	SVariable*		iObj_get_baseClass										(SObject* obj);
	SVariable*		iObj_get_bindControls									(SObject* obj);
	SVariable*		iObj_get_borderColor									(SObject* obj);
	SVariable*		iObj_get_borderStyle									(SObject* obj);
	SVariable*		iObj_get_borderWidth									(SObject* obj);
	SVariable*		iObj_get_bound											(SObject* obj);
	SVariable*		iObj_get_boundColumn									(SObject* obj);
	SVariable*		iObj_get_boundTo										(SObject* obj);
	SVariable*		iObj_get_bufferMode										(SObject* obj);
	SVariable*		iObj_get_buttonCount									(SObject* obj);
	SVariable*		iObj_get_cancel											(SObject* obj);
	SVariable*		iObj_get_caption										(SObject* obj);
	SVariable*		iObj_get_centered										(SObject* obj);
	SVariable*		iObj_get_century										(SObject* obj);
	SVariable*		iObj_get_childOrder										(SObject* obj);
	SVariable*		iObj_get_class											(SObject* obj);
	SVariable*		iObj_get_classLibrary									(SObject* obj);
	SVariable*		iObj_get_clipControls									(SObject* obj);
	SVariable*		iObj_get_closable										(SObject* obj);
	SVariable*		iObj_get_colorScheme									(SObject* obj);
	SVariable*		iObj_get_colorSource									(SObject* obj);
	SVariable*		iObj_get_columnCount									(SObject* obj);
	SVariable*		iObj_get_columnLines									(SObject* obj);
	SVariable*		iObj_get_columnOrder									(SObject* obj);
	SVariable*		iObj_get_columnWidths									(SObject* obj);
	SVariable*		iObj_get_columns										(SObject* obj);
	SVariable*		iObj_get_comment										(SObject* obj);
	SVariable*		iObj_get_continuousScroll								(SObject* obj);
	SVariable*		iObj_get_controlBox										(SObject* obj);
	SVariable*		iObj_get_controlCount									(SObject* obj);
	SVariable*		iObj_get_controlSource									(SObject* obj);
	SVariable*		iObj_get_controls										(SObject* obj);
	SVariable*		iObj_get_count											(SObject* obj);
	SVariable*		iObj_get_currentControl									(SObject* obj);
	SVariable*		iObj_get_currentX										(SObject* obj);
	SVariable*		iObj_get_currentY										(SObject* obj);
	SVariable*		iObj_get_curvature										(SObject* obj);
	SVariable*		iObj_get_dEClass										(SObject* obj);
	SVariable*		iObj_get_dEClassLibrary									(SObject* obj);
	SVariable*		iObj_get_dataEnvironment								(SObject* obj);
	SVariable*		iObj_get_dataSession									(SObject* obj);
	SVariable*		iObj_get_dataSessionID									(SObject* obj);
	SVariable*		iObj_get_dateFormat										(SObject* obj);
	SVariable*		iObj_get_dateMark										(SObject* obj);
	SVariable*		iObj_get_defOLELCID										(SObject* obj);
	SVariable*		iObj_get_default										(SObject* obj);
	SVariable*		iObj_get_deleteMark										(SObject* obj);
	SVariable*		iObj_get_desktop										(SObject* obj);
	SVariable*		iObj_get_details										(SObject* obj);
	SVariable*		iObj_get_disabledBackColor								(SObject* obj);
	SVariable*		iObj_get_disabledForeColor								(SObject* obj);
	SVariable*		iObj_get_disabledItemBackColor							(SObject* obj);
	SVariable*		iObj_get_disabledItemForeColor							(SObject* obj);
	SVariable*		iObj_get_disabledPicture								(SObject* obj);
	SVariable*		iObj_get_displayCount									(SObject* obj);
	SVariable*		iObj_get_displayValue									(SObject* obj);
	SVariable*		iObj_get_doCreate										(SObject* obj);
	SVariable*		iObj_get_dockPosition									(SObject* obj);
	SVariable*		iObj_get_dockable										(SObject* obj);
	SVariable*		iObj_get_docked											(SObject* obj);
	SVariable*		iObj_get_documentFile									(SObject* obj);
	SVariable*		iObj_get_downPicture									(SObject* obj);
	SVariable*		iObj_get_dragIcon										(SObject* obj);
	SVariable*		iObj_get_dragMode										(SObject* obj);
	SVariable*		iObj_get_drawMode										(SObject* obj);
	SVariable*		iObj_get_drawStyle										(SObject* obj);
	SVariable*		iObj_get_drawWidth										(SObject* obj);
	SVariable*		iObj_get_dynamicAlignment								(SObject* obj);
	SVariable*		iObj_get_dynamicBackColor								(SObject* obj);
	SVariable*		iObj_get_dynamicCurrentControl							(SObject* obj);
	SVariable*		iObj_get_dynamicFontBold								(SObject* obj);
	SVariable*		iObj_get_dynamicFontItalic								(SObject* obj);
	SVariable*		iObj_get_dynamicFontName								(SObject* obj);
	SVariable*		iObj_get_dynamicFontOutline								(SObject* obj);
	SVariable*		iObj_get_dynamicFontShadow								(SObject* obj);
	SVariable*		iObj_get_dynamicFontSize								(SObject* obj);
	SVariable*		iObj_get_dynamicFontStrikeThru							(SObject* obj);
	SVariable*		iObj_get_dynamicFontUnderline							(SObject* obj);
	SVariable*		iObj_get_dynamicForeColor								(SObject* obj);
	SVariable*		iObj_get_dynamicInputMask								(SObject* obj);
	SVariable*		iObj_get_enableHyperlinks								(SObject* obj);
	SVariable*		iObj_get_enabled										(SObject* obj);
	SVariable*		iObj_get_errorNo										(SObject* obj);
	SVariable*		iObj_get_fillColor										(SObject* obj);
	SVariable*		iObj_get_fillStyle										(SObject* obj);
	SVariable*		iObj_get_firstElement									(SObject* obj);
	SVariable*		iObj_get_fontBold										(SObject* obj);
	SVariable*		iObj_get_fontCharSet									(SObject* obj);
	SVariable*		iObj_get_fontCondense									(SObject* obj);
	SVariable*		iObj_get_fontExtend										(SObject* obj);
	SVariable*		iObj_get_fontItalic										(SObject* obj);
	SVariable*		iObj_get_fontName										(SObject* obj);
	SVariable*		iObj_get_fontOutline									(SObject* obj);
	SVariable*		iObj_get_fontShadow										(SObject* obj);
	SVariable*		iObj_get_fontSize										(SObject* obj);
	SVariable*		iObj_get_fontStrikeThru									(SObject* obj);
	SVariable*		iObj_get_fontUnderLine									(SObject* obj);
	SVariable*		iObj_get_fontUnderline									(SObject* obj);
	SVariable*		iObj_get_foreColor										(SObject* obj);
	SVariable*		iObj_get_formCount										(SObject* obj);
	SVariable*		iObj_get_format											(SObject* obj);
	SVariable*		iObj_get_forms											(SObject* obj);
	SVariable*		iObj_get_gridLineColor									(SObject* obj);
	SVariable*		iObj_get_gridLineWidth									(SObject* obj);
	SVariable*		iObj_get_gridLines										(SObject* obj);
	SVariable*		iObj_get_hScrollSmallChange								(SObject* obj);
	SVariable*		iObj_get_hWnd											(SObject* obj);
	SVariable*		iObj_get_halfHeightCaption								(SObject* obj);
	SVariable*		iObj_get_headerClass									(SObject* obj);
	SVariable*		iObj_get_headerClassLibrary								(SObject* obj);
	SVariable*		iObj_get_headerHeight									(SObject* obj);
	SVariable*		iObj_get_height											(SObject* obj);
	SVariable*		iObj_get_helpContextID									(SObject* obj);
	SVariable*		iObj_get_hideSelection									(SObject* obj);
	SVariable*		iObj_get_highLight										(SObject* obj);
	SVariable*		iObj_get_highLightRow									(SObject* obj);
	SVariable*		iObj_get_highlightBackColor								(SObject* obj);
	SVariable*		iObj_get_highlightForeColor								(SObject* obj);
	SVariable*		iObj_get_highlightRowLineWidth							(SObject* obj);
	SVariable*		iObj_get_highlightStyle									(SObject* obj);
	SVariable*		iObj_get_hostName										(SObject* obj);
	SVariable*		iObj_get_hours											(SObject* obj);
	SVariable*		iObj_get_iMEMode										(SObject* obj);
	SBitmap*		iObj_get_icon											(SObject* obj);
	SVariable*		iObj_get_increment										(SObject* obj);
	SVariable*		iObj_get_incrementalSearch								(SObject* obj);
	SVariable*		iObj_get_inputMask										(SObject* obj);
	SVariable*		iObj_get_integralHeight									(SObject* obj);
	SVariable*		iObj_get_interval										(SObject* obj);
	SVariable*		iObj_get_itemBackColor									(SObject* obj);
	SVariable*		iObj_get_itemData										(SObject* obj);
	SVariable*		iObj_get_itemForeColor									(SObject* obj);
	SVariable*		iObj_get_itemIDData										(SObject* obj);
	SVariable*		iObj_get_itemTips										(SObject* obj);
	SVariable*		iObj_get_keyPreview										(SObject* obj);
	SVariable*		iObj_get_keySort										(SObject* obj);
	SVariable*		iObj_get_keyboardHighValue								(SObject* obj);
	SVariable*		iObj_get_keyboardLowValue								(SObject* obj);
	SVariable*		iObj_get_left											(SObject* obj);
	SVariable*		iObj_get_leftColumn										(SObject* obj);
	SVariable*		iObj_get_lineContents									(SObject* obj);
	SVariable*		iObj_get_lineNo											(SObject* obj);
	SVariable*		iObj_get_lineSlant										(SObject* obj);
	SVariable*		iObj_get_linkMaster										(SObject* obj);
	SVariable*		iObj_get_list											(SObject* obj);
	SVariable*		iObj_get_listCount										(SObject* obj);
	SVariable*		iObj_get_listIndex										(SObject* obj);
	SVariable*		iObj_get_listItem										(SObject* obj);
	SVariable*		iObj_get_listItemID										(SObject* obj);
	SVariable*		iObj_get_lockColumns									(SObject* obj);
	SVariable*		iObj_get_lockColumnsLeft								(SObject* obj);
	SVariable*		iObj_get_lockScreen										(SObject* obj);
	SVariable*		iObj_get_mDIForm										(SObject* obj);
	SVariable*		iObj_get_macDesktop										(SObject* obj);
	SVariable*		iObj_get_margin											(SObject* obj);
	SVariable*		iObj_get_maxButton										(SObject* obj);
	SVariable*		iObj_get_maxHeight										(SObject* obj);
	SVariable*		iObj_get_maxLeft										(SObject* obj);
	SVariable*		iObj_get_maxLength										(SObject* obj);
	SVariable*		iObj_get_maxTop											(SObject* obj);
	SVariable*		iObj_get_maxWidth										(SObject* obj);
	SVariable*		iObj_get_memberClass									(SObject* obj);
	SVariable*		iObj_get_memberClassLibrary								(SObject* obj);
	SVariable*		iObj_get_memoWindow										(SObject* obj);
	SVariable*		iObj_get_message										(SObject* obj);
	SVariable*		iObj_get_minButton										(SObject* obj);
	SVariable*		iObj_get_minHeight										(SObject* obj);
	SVariable*		iObj_get_minWidth										(SObject* obj);
	SBitmap*		iObj_get_mouseIcon										(SObject* obj);
	SVariable*		iObj_get_mousePointer									(SObject* obj);
	SVariable*		iObj_get_movable										(SObject* obj);
	SVariable*		iObj_get_moverBars										(SObject* obj);
	SVariable*		iObj_get_multiSelect									(SObject* obj);
	SVariable*		iObj_get_name											(SObject* obj);
	SVariable*		iObj_get_newIndex										(SObject* obj);
	SVariable*		iObj_get_newItemID										(SObject* obj);
	SVariable*		iObj_get_nullDisplay									(SObject* obj);
	SVariable*		iObj_get_numberOfElements								(SObject* obj);
	SVariable*		iObj_get_oLEClass										(SObject* obj);
	SVariable*		iObj_get_oLEDragMode									(SObject* obj);
	SBitmap*		iObj_get_oLEDragPicture									(SObject* obj);
	SVariable*		iObj_get_oLEDropEffects									(SObject* obj);
	SVariable*		iObj_get_oLEDropHasData									(SObject* obj);
	SVariable*		iObj_get_oLEDropMode									(SObject* obj);
	SVariable*		iObj_get_oLEDropTextInsertion							(SObject* obj);
	SVariable*		iObj_get_oLELCID										(SObject* obj);
	SVariable*		iObj_get_oLETypeAllowed									(SObject* obj);
	SVariable*		iObj_get_object											(SObject* obj);
	SVariable*		iObj_get_objects										(SObject* obj);
	SVariable*		iObj_get_openWindow										(SObject* obj);
	SVariable*		iObj_get_optimize										(SObject* obj);
	SVariable*		iObj_get_pageCount										(SObject* obj);
	SVariable*		iObj_get_pageHeight										(SObject* obj);
	SVariable*		iObj_get_pageOrder										(SObject* obj);
	SVariable*		iObj_get_pageWidth										(SObject* obj);
	SVariable*		iObj_get_pages											(SObject* obj);
	SVariable*		iObj_get_panel											(SObject* obj);
	SVariable*		iObj_get_panelLink										(SObject* obj);
	SVariable*		iObj_get_parent											(SObject* obj);
	SVariable*		iObj_get_parentClass									(SObject* obj);
	SVariable*		iObj_get_partition										(SObject* obj);
	SVariable*		iObj_get_passwordChar									(SObject* obj);
	SVariable*		iObj_get_picture										(SObject* obj);
	SVariable*		iObj_get_pictureMargin									(SObject* obj);
	SVariable*		iObj_get_picturePosition								(SObject* obj);
	SVariable*		iObj_get_pictureSelectionDisplay						(SObject* obj);
	SVariable*		iObj_get_pictureSpacing									(SObject* obj);
	SVariable*		iObj_get_pictureVal										(SObject* obj);
	SVariable*		iObj_get_polyPoints										(SObject* obj);
	SVariable*		iObj_get_procedure										(SObject* obj);
	SVariable*		iObj_get_readBackColor									(SObject* obj);
	SVariable*		iObj_get_readCycle										(SObject* obj);
	SVariable*		iObj_get_readForeColor									(SObject* obj);
	SVariable*		iObj_get_readLock										(SObject* obj);
	SVariable*		iObj_get_readMouse										(SObject* obj);
	SVariable*		iObj_get_readOnly										(SObject* obj);
	SVariable*		iObj_get_readSave										(SObject* obj);
	SVariable*		iObj_get_readTimeOut									(SObject* obj);
	SVariable*		iObj_get_recordMark										(SObject* obj);
	SVariable*		iObj_get_recordSource									(SObject* obj);
	SVariable*		iObj_get_recordSourceType								(SObject* obj);
	SVariable*		iObj_get_relationalExpr									(SObject* obj);
	SVariable*		iObj_get_relativeColumn									(SObject* obj);
	SVariable*		iObj_get_relativeRow									(SObject* obj);
	SVariable*		iObj_get_releaseType									(SObject* obj);
	SVariable*		iObj_get_resizable										(SObject* obj);
	SVariable*		iObj_get_rightToLeft									(SObject* obj);
	SVariable*		iObj_get_rotateFlip										(SObject* obj);
	SVariable*		iObj_get_rotation										(SObject* obj);
	SVariable*		iObj_get_rowColChange									(SObject* obj);
	SVariable*		iObj_get_rowHeight										(SObject* obj);
	SVariable*		iObj_get_rowSource										(SObject* obj);
	SVariable*		iObj_get_rowSourceType									(SObject* obj);
	SVariable*		iObj_get_scaleMode										(SObject* obj);
	SVariable*		iObj_get_scrollBars										(SObject* obj);
	SVariable*		iObj_get_seconds										(SObject* obj);
	SVariable*		iObj_get_selLength										(SObject* obj);
	SVariable*		iObj_get_selStart										(SObject* obj);
	SVariable*		iObj_get_selText										(SObject* obj);
	SVariable*		iObj_get_selectOnEntry									(SObject* obj);
	SVariable*		iObj_get_selected										(SObject* obj);
	SVariable*		iObj_get_selectedBackColor								(SObject* obj);
	SVariable*		iObj_get_selectedForeColor								(SObject* obj);
	SVariable*		iObj_get_selectedID										(SObject* obj);
	SVariable*		iObj_get_selectedItemBackColor							(SObject* obj);
	SVariable*		iObj_get_selectedItemForeColor							(SObject* obj);
	SVariable*		iObj_get_showInTaskbar									(SObject* obj);
	SVariable*		iObj_get_showTips										(SObject* obj);
	SVariable*		iObj_get_showWindow										(SObject* obj);
	SVariable*		iObj_get_sizable										(SObject* obj);
	SVariable*		iObj_get_sizeBox										(SObject* obj);
	SVariable*		iObj_get_sorted											(SObject* obj);
	SVariable*		iObj_get_sparse											(SObject* obj);
	SVariable*		iObj_get_specialEffect									(SObject* obj);
	SVariable*		iObj_get_spinnerHighValue								(SObject* obj);
	SVariable*		iObj_get_spinnerLowValue								(SObject* obj);
	SVariable*		iObj_get_splitBar										(SObject* obj);
	SVariable*		iObj_get_stackLevel										(SObject* obj);
	SVariable*		iObj_get_statusBarText									(SObject* obj);
	SVariable*		iObj_get_stretch										(SObject* obj);
	SVariable*		iObj_get_strictDateEntry								(SObject* obj);
	SVariable*		iObj_get_style											(SObject* obj);
	SVariable*		iObj_get_tabIndex										(SObject* obj);
	SVariable*		iObj_get_tabOrientation									(SObject* obj);
	SVariable*		iObj_get_tabStop										(SObject* obj);
	SVariable*		iObj_get_tabStyle										(SObject* obj);
	SVariable*		iObj_get_tabs											(SObject* obj);
	SVariable*		iObj_get_tag											(SObject* obj);
	SVariable*		iObj_get_terminateRead									(SObject* obj);
	SVariable*		iObj_get_text											(SObject* obj);
	SVariable*		iObj_get_themes											(SObject* obj);
	SVariable*		iObj_get_titleBar										(SObject* obj);
	SVariable*		iObj_get_toolTipText									(SObject* obj);
	SVariable*		iObj_get_top											(SObject* obj);
	SVariable*		iObj_get_topIndex										(SObject* obj);
	SVariable*		iObj_get_topItemID										(SObject* obj);
	SVariable*		iObj_get_userValue										(SObject* obj);
	SVariable*		iObj_get_vScrollSmallChange								(SObject* obj);
	SVariable*		iObj_get_value											(SObject* obj);
	SVariable*		iObj_get_view											(SObject* obj);
	SVariable*		iObj_get_viewPortHeight									(SObject* obj);
	SVariable*		iObj_get_viewPortLeft									(SObject* obj);
	SVariable*		iObj_get_viewPortTop									(SObject* obj);
	SVariable*		iObj_get_viewPortWidth									(SObject* obj);
	SVariable*		iObj_get_visible										(SObject* obj);
	SVariable*		iObj_get_visualEffect									(SObject* obj);
	SVariable*		iObj_get_whatsThisButton								(SObject* obj);
	SVariable*		iObj_get_whatsThisHelp									(SObject* obj);
	SVariable*		iObj_get_whatsThisHelpID								(SObject* obj);
	SVariable*		iObj_get_width											(SObject* obj);
	SVariable*		iObj_get_windowList										(SObject* obj);
	SVariable*		iObj_get_windowState									(SObject* obj);
	SVariable*		iObj_get_windowType										(SObject* obj);
	SVariable*		iObj_get_wordWrap										(SObject* obj);
	SVariable*		iObj_get_zoomBox										(SObject* obj);



	struct SPropertyInits
	{
		u32			index;								// Array index
		cs8*		prop;								// Property
		u32			length;								// Length of the property name
		s32			objType;							// What is the object type if not a bitmap?

		// Default values
		union {
			u32		_u32;
			f64		_f64;
			f32		_f32;
			s64		_s64;
			s32		_s32;
			s16		_s16;
			s8		_s8;
			u64		_u64;
			u16		_u16;
			u8		_u8;
			s8*		_s8p;
			u8*		_u8p;
		};
	};

	// Initialization parameters
	SPropertyInits gsInitialization[] =
	{
		{	_INDEX_ACTIVECOLUMN,			cgc_activeColumn,				sizeof(cgc_activeColumn) - 1,				_VAR_TYPE_S32,			0		},
		{	_INDEX_ACTIVECONTROL,			cgc_activeControl,				sizeof(cgc_activeControl) - 1,				_VAR_TYPE_OBJECT,		0		},
		{	_INDEX_ACTIVEFORM,				cgc_activeForm,					sizeof(cgc_activeForm) - 1,					_VAR_TYPE_OBJECT,		0		},
		{	_INDEX_ACTIVEPAGE,				cgc_activePage,					sizeof(cgc_activePage) - 1,					_VAR_TYPE_S32,			0		},
		{	_INDEX_ACTIVEROW,				cgc_activeRow,					sizeof(cgc_activeRow) - 1,					_VAR_TYPE_S32,			0		},
		{	_INDEX_ADDLINEFEEDS,			cgc_addLineFeeds,				sizeof(cgc_addLineFeeds) - 1,				_VAR_TYPE_LOGICAL,		1		},					// .t.=yes (default), .f.=no
		{	_INDEX_ALIGN,					cgc_align,						sizeof(cgc_align) - 1,						_VAR_TYPE_S32,			0		},					// 0=Standard alignment, 1=top, 2=bottom, 3=left, 4=right
		{	_INDEX_ALIGNMENT,				cgc_alignment,					sizeof(cgc_alignment) - 1,					_VAR_TYPE_S32,			0		},					// 0=vertical left, 1=vertical right, 2=centered, 4=top left, 5=top right, 6=top center, 7=bottom left, 8=bottom right, 9=bottom center
		{	_INDEX_ALLOWADDNEW,				cgc_allowAddNew,				sizeof(cgc_allowAddNew) - 1,				_VAR_TYPE_LOGICAL,		0		},					// .t.=yes, .f.=no (default)
		{	_INDEX_ALLOWAUTOCOLUMNFIT,		cgc_allowAutoColumnFit,			sizeof(cgc_allowAutoColumnFit) - 1,			_VAR_TYPE_S32,			0		},					// 0=all automatically, 1=individual columns, 2=disabled
		{	_INDEX_ALLOWCELLSELECTION,		cgc_allowCellSelection,			sizeof(cgc_allowCellSelection) - 1,			_VAR_TYPE_LOGICAL,		1		},					// .t.=yes (default), .f.=no
		{	_INDEX_ALLOWHEADERSIZING,		cgc_allowHeaderSizing,			sizeof(cgc_allowHeaderSizing) - 1,			_VAR_TYPE_LOGICAL,		1		},					// .t.=yes (default), .f.=no
		{	_INDEX_ALLOWOUTPUT,				cgc_allowOutput,				sizeof(cgc_allowOutput) - 1,				_VAR_TYPE_LOGICAL,		1		},					// .t.=yes (default), .f.=no
		{	_INDEX_ALLOWROWSIZING,			cgc_allowRowSizing,				sizeof(cgc_allowRowSizing) - 1,				_VAR_TYPE_LOGICAL,		1		},					// .t.=yes (default), .f.=no
		{	_INDEX_ALLOWTABS,				cgc_allowTabs,					sizeof(cgc_allowTabs) - 1,					_VAR_TYPE_LOGICAL,		1		},					// .t.=yes, .f.=no (default) (in editboxes)
		{	_INDEX_ALWAYSONBOTTOM,			cgc_alwaysOnBottom,				sizeof(cgc_alwaysOnBottom) - 1,				_VAR_TYPE_LOGICAL,		1		},					// .t.=yes, .f.=no (default)
		{	_INDEX_ALWAYSONTOP,				cgc_alwaysOnTop,				sizeof(cgc_alwaysOnTop) - 1,				_VAR_TYPE_LOGICAL,		1		},					// .t.=yes, .f.=no (default)
		{	_INDEX_ANCHOR,					cgc_anchor,						sizeof(cgc_anchor) - 1,						_VAR_TYPE_S32,			0		},					// 0=top left (default), 1=top absolute, 2=left absolute, 4=bottom absolute, 8=right absolute, 16=top relative, 32=left relative, 64=bottom relative, 128=right relative, 256=horizontal fixed, 512=vertical fixed
		{	_INDEX_APPLICATION,				cgc_application,				sizeof(cgc_application) - 1,				_VAR_TYPE_OBJECT,		0		},					// A pseudo-interface to application objects and methods
		{	_INDEX_AUTOACTIVATE,			cgc_autoActivate,				sizeof(cgc_autoActivate) - 1,				_VAR_TYPE_S32,			0		},					// 0=manual, 1=got focus, 2=double click (default), 3=automatic
		{	_INDEX_AUTOCENTER,				cgc_autoCenter,					sizeof(cgc_autoCenter) - 1,					_VAR_TYPE_LOGICAL,		0		},					// .t.=yes, .f.=no (default)
		{	_INDEX_AUTOCOMPSOURCE,			cgc_autoCompSource,				sizeof(cgc_autoCompSource) - 1,				_VAR_TYPE_CHARACTER,	(u32)&cgcEmptyString[0] },	// Field to track for auto complete
		{	_INDEX_AUTOCOMPTABLE,			cgc_autoCompTable,				sizeof(cgc_autoCompTable) - 1,				_VAR_TYPE_CHARACTER,	(u32)&cgcEmptyString[0] },	// Table to for auto complete
		{	_INDEX_AUTOCOMPLETE,			cgc_autoComplete,				sizeof(cgc_autoComplete) - 1,				_VAR_TYPE_S32,			0		},					// 0=no display, 1=alphabetical, 2=most frequent, 3=most recent, 4=custom weighting
		{	_INDEX_AUTOHIDESCROLLBAR,		cgc_autoHideScrollBar,			sizeof(cgc_autoHideScrollBar) - 1,			_VAR_TYPE_S32,			0		},					// 0=no (default), 1=yes
		{	_INDEX_AUTORELEASE,				cgc_autoRelease,				sizeof(cgc_autoRelease) - 1,				_VAR_TYPE_CHARACTER,	1		},					// .t.=released when last form is released, .f.=persists even after last form is released (in formsets)
		{	_INDEX_AUTOSIZE,				cgc_autoSize,					sizeof(cgc_autoSize) - 1,					_VAR_TYPE_LOGICAL,		0  	    },					// .t.=auto resize, .f.=no auto resize (default)
		{	_INDEX_AUTOVERBMENU,			cgc_autoVerbMenu,				sizeof(cgc_autoVerbMenu) - 1,				_VAR_TYPE_LOGICAL,		1  	    },					// .t.=shows ole menu on right-click (default), .f.=ignore
		{	_INDEX_BACKCOLOR,				cgc_backColor,					sizeof(cgc_backColor) - 1,					_VAR_TYPE_S32,			rgba(255,255,255,255)	},	// White
		{	_INDEX_BACKSTYLE,				cgc_backStyle,					sizeof(cgc_backStyle) - 1,					_VAR_TYPE_S32,			1  	    },					// 0=transparent, 1=opaque
		{	_INDEX_BASECLASS,				cgc_baseClass,					sizeof(cgc_baseClass) - 1,					_VAR_TYPE_CHARACTER,	(u32)&cgcEmptyString[0] },	// Varies by class
		{	_INDEX_BINDCONTROLS,			cgc_bindControls,				sizeof(cgc_bindControls) - 1,				_VAR_TYPE_LOGICAL,		1  	    },					// .t.=immediately bind, .f.=delayed binding (not used in Visual FreePro, Jr. as all controls delay binding and complete load operations)
		{	_INDEX_BORDERCOLOR,				cgc_borderColor,				sizeof(cgc_borderColor) - 1,				_VAR_TYPE_S32,			0  	    },					// Black
		{	_INDEX_BORDERSTYLE,				cgc_borderStyle,				sizeof(cgc_borderStyle) - 1,				_VAR_TYPE_S32,			0  	    },					// 0=none, 1=fixed; for lines or shapes 0=none, 1=solid, 2=dash, 3=dot, 4=dash-dot, 5=dash-dash-dot, 6=inside solid; for forms 0=none, 1=fixed single, 2=fixed double, 3=sizable (not used in Visual FreePro, Jr., all windows are sizable with resize event overrides to limit the size)
		{	_INDEX_BORDERWIDTH,				cgc_borderWidth,				sizeof(cgc_borderWidth) - 1,				_VAR_TYPE_S32,			1  	    },					// 1 pixel
		{	_INDEX_BOUND,					cgc_bound,						sizeof(cgc_bound) - 1,						_VAR_TYPE_LOGICAL,		0  	    },					// .t.=bound, .f.=not bound, not used in Visual FreePro, Jr. as all controls are not bound
		{	_INDEX_BOUNDCOLUMN,				cgc_boundColumn,				sizeof(cgc_boundColumn) - 1,				_VAR_TYPE_S32,			1  	    },					// Column 1 default
		{	_INDEX_BOUNDTO,					cgc_boundTo,					sizeof(cgc_boundTo) - 1,					_VAR_TYPE_LOGICAL,		0  	    },					// .t.=per list property (default), .f.=based on controlsource, if character then list property, if numeric then listindex property
		{	_INDEX_BUFFERMODE,				cgc_bufferMode,					sizeof(cgc_bufferMode) - 1,					_VAR_TYPE_S32,			0  	    },					// 0=none (default), 1=pessimistic, 2=optimistic
		{	_INDEX_BUTTONCOUNT,				cgc_buttonCount,				sizeof(cgc_buttonCount) - 1,				_VAR_TYPE_S32,			2  	    },					// 2 buttons
		{	_INDEX_CANCEL,					cgc_cancel,						sizeof(cgc_cancel) - 1,						_VAR_TYPE_S32,			0  	    },					// .t.=the control is a cancel, .f.=normal control (default)
		{	_INDEX_CAPTION,					cgc_caption,					sizeof(cgc_caption) - 1,					_VAR_TYPE_CHARACTER,	(u32)&cgcEmptyString[0] },	// Varies by class
		{	_INDEX_CENTERED,				cgc_centered,					sizeof(cgc_centered) - 1,					_VAR_TYPE_LOGICAL,		0  	    },					// .t.=centered between boundaries, .f.=not centered (default)
		{	_INDEX_CENTURY,					cgc_century,					sizeof(cgc_century) - 1,					_VAR_TYPE_S32,			1  	    },					// 0=off, 1=on, 2=uses SET CENTURY setting
		{	_INDEX_CHILDORDER,				cgc_childOrder,					sizeof(cgc_childOrder) - 1,					_VAR_TYPE_CHARACTER,	(u32)&cgcEmptyString[0] },	// Tag name
		{	_INDEX_CLASS,					cgc_class,						sizeof(cgc_class) - 1,						_VAR_TYPE_CHARACTER,	(u32)&cgcEmptyString[0] },	// Varies by class
		{	_INDEX_CLASSLIBRARY,			cgc_classLibrary,				sizeof(cgc_classLibrary) - 1,				_VAR_TYPE_CHARACTER,	(u32)&cgcEmptyString[0] },	// Varies by class
		{	_INDEX_CLIPCONTROLS,			cgc_clipControls,				sizeof(cgc_clipControls) - 1,				_VAR_TYPE_LOGICAL,		1  	    },					// .t.=repaints entire object (default), .f.=only paints newly exposed areas
		{	_INDEX_CLOSABLE,				cgc_closable,					sizeof(cgc_closable) - 1,					_VAR_TYPE_LOGICAL,		1  	    },					// .t.=close icon (default), .f.=no close icon
		{	_INDEX_COLORSCHEME,				cgc_colorScheme,				sizeof(cgc_colorScheme) - 1,				_VAR_TYPE_S32,			0  	    },					// Not used in Visual FreePro, Jr.
		{	_INDEX_COLORSOURCE,				cgc_colorSource,				sizeof(cgc_colorSource) - 1,				_VAR_TYPE_S32,			0  	    },					// 0=object (default), 1=form, 2=colorscheme property, 3=default scheme, 4=windows 3d surface, 5=windows
		{	_INDEX_COLUMNCOUNT,				cgc_columnCount,				sizeof(cgc_columnCount) - 1,				_VAR_TYPE_S32,			1  	    },					// The number of columns on the control, varies by control
		{	_INDEX_COLUMNLINES,				cgc_columnLines,				sizeof(cgc_columnLines) - 1,				_VAR_TYPE_LOGICAL,		1  	    },					// .t.=visible (default), .f.=not visible
		{	_INDEX_COLUMNORDER,				cgc_columnOrder,				sizeof(cgc_columnOrder) - 1,				_VAR_TYPE_S32,			0  	    },					// This column's order
		{	_INDEX_COLUMNWIDTHS,			cgc_columnWidths,				sizeof(cgc_columnWidths) - 1,				_VAR_TYPE_CHARACTER,	0		},					// A comma-delimited string
		{	_INDEX_COLUMNS,					cgc_columns,					sizeof(cgc_columns) - 1,					_VAR_TYPE_OBJECT,		0	    },					// A pseudo-object to access columns within
		{	_INDEX_COMMENT,					cgc_comment,					sizeof(cgc_comment) - 1,					_VAR_TYPE_CHARACTER,	(u32)&cgcEmptyString[0] },	// Unspecified
		{	_INDEX_CONTINUOUSSCROLL,		cgc_continuousScroll,			sizeof(cgc_continuousScroll) - 1,			_VAR_TYPE_LOGICAL,		1  	    },					// .t.=scrolls with mouse down (default), .f.=scrolls only when released
		{	_INDEX_CONTROLBOX,				cgc_controlBox,					sizeof(cgc_controlBox) - 1,					_VAR_TYPE_LOGICAL,		1  	    },					// .t.=form and subform icon (default), .f.=no icon
		{	_INDEX_CONTROLCOUNT,			cgc_controlCount,				sizeof(cgc_controlCount) - 1,				_VAR_TYPE_S32,			0  	    },					// Varies, based on number of direct child objects
		{	_INDEX_CONTROLSOURCE,			cgc_controlSource,				sizeof(cgc_controlSource) - 1,				_VAR_TYPE_CHARACTER,	(u32)&cgcEmptyString[0] },	// The source for the object
		{	_INDEX_CONTROLS,				cgc_controls,					sizeof(cgc_controls) - 1,					_VAR_TYPE_OBJECT,		0	    },					// A psuedo-object to access controls within
		{	_INDEX_COUNT,					cgc_count,						sizeof(cgc_count) - 1,						_VAR_TYPE_S32,			0  	    },					// Number of items in the object
		{	_INDEX_CURRENTCONTROL,			cgc_currentControl,				sizeof(cgc_currentControl) - 1,				_VAR_TYPE_OBJECT,		0	    },					// Which control in a column is used for display
		{	_INDEX_CURRENTX,				cgc_currentX,					sizeof(cgc_currentX) - 1,					_VAR_TYPE_S32,			0  	    },					// The X coordinate for drawing (not used in Visual FreePro, Jr.)
		{	_INDEX_CURRENTY,				cgc_currentY,					sizeof(cgc_currentY) - 1,					_VAR_TYPE_S32,			0  	    },					// The Y coordinate for drawing (not used in Visual FreePro, Jr.)
		{	_INDEX_CURVATURE,				cgc_curvature,					sizeof(cgc_curvature) - 1,					_VAR_TYPE_S32,			0  	    },					// 0=none, 1..98=rounded, 99=full circle
		{	_INDEX_DECLASS,					cgc_dEClass,					sizeof(cgc_dEClass) - 1,					_VAR_TYPE_CHARACTER,	(u32)&cgcEmptyString[0] },	// Varies
		{	_INDEX_DECLASSLIBRARY,			cgc_dEClassLibrary,				sizeof(cgc_dEClassLibrary) - 1,				_VAR_TYPE_CHARACTER,	(u32)&cgcEmptyString[0] },	// Varies
		{	_INDEX_DATAENVIRONMENT,			cgc_dataEnvironment,			sizeof(cgc_dataEnvironment) - 1,			_VAR_TYPE_OBJECT,		0		},					// Varies
		{	_INDEX_DATASESSION,				cgc_dataSession,				sizeof(cgc_dataSession) - 1,				_VAR_TYPE_S32,			0  	    },					// 0=default, 1=private
		{	_INDEX_DATASESSIONID,			cgc_dataSessionID,				sizeof(cgc_dataSessionID) - 1,				_VAR_TYPE_S32,			0  	    },					// Varies
		{	_INDEX_DATEFORMAT,				cgc_dateFormat,					sizeof(cgc_dateFormat) - 1,					_VAR_TYPE_S32,			0  	    },					// 0=use SET DATE (default), 1=American mm/dd/yy, 2=ANSI yy.mm.dd, 3=British dd/mm/yy, 4=Italian dd-mm-yy, 5= French dd/mm/yy, 6=German dd.mm.yy, 7=Japan yy/mm/dd, 8= Taiwan yy/mm/dd, 9=USA mm-dd-yy, 10=MDY mm/dd/yy, 11=DMY dd/mm/yy, 12=YMD yy/mm/dd, 12=short per Windows' settings, 13=long per Windows' settings
		{	_INDEX_DATEMARK,				cgc_dateMark,					sizeof(cgc_dateMark) - 1,					_VAR_TYPE_CHARACTER,	0 	    },					// If unspecified, uses SET MARK
		{	_INDEX_DEFOLELCID,				cgc_defOLELCID,					sizeof(cgc_defOLELCID) - 1,					_VAR_TYPE_S32,			0  	    },					// Default locale ID
		{	_INDEX_DEFAULT,					cgc_default,					sizeof(cgc_default) - 1,					_VAR_TYPE_LOGICAL,		0  	    },					// .t.=Control to trigger with enter key, .f.=do not trigger (default)
		{	_INDEX_DELETEMARK,				cgc_deleteMark,					sizeof(cgc_deleteMark) - 1,					_VAR_TYPE_LOGICAL,		1  	    },					// .t.=show deleted() mark (default), .f.=do not show
		{	_INDEX_DESKTOP,					cgc_desktop,					sizeof(cgc_desktop) - 1,					_VAR_TYPE_LOGICAL,		0 	    },					// .t.=show anywhere, .f.=show only in Visual FreePro, Jr. screen (default)
		{	_INDEX_DETAILS,					cgc_details,					sizeof(cgc_details) - 1,					_VAR_TYPE_CHARACTER,	(u32)&cgcEmptyString[0] },	// Additional information about an exception
		{	_INDEX_DISABLEDBACKCOLOR,		cgc_disabledBackColor,			sizeof(cgc_disabledBackColor) - 1,			_VAR_TYPE_S32,			_disabledBackColor },
		{	_INDEX_DISABLEDFORECOLOR,		cgc_disabledForeColor,			sizeof(cgc_disabledForeColor) - 1,			_VAR_TYPE_S32,			_disabledForeColor },
		{	_INDEX_DISABLEDITEMBACKCOLOR,	cgc_disabledItemBackColor,		sizeof(cgc_disabledItemBackColor) - 1,		_VAR_TYPE_S32,			_disabledBackColor },
		{	_INDEX_DISABLEDITEMFORECOLOR,	cgc_disabledItemForeColor,		sizeof(cgc_disabledItemForeColor) - 1,		_VAR_TYPE_S32,			_disabledForeColor },
		{	_INDEX_DISABLEDPICTURE,			cgc_disabledPicture,			sizeof(cgc_disabledPicture) - 1,			_VAR_TYPE_BITMAP,		0		},					// No picture by default
		{	_INDEX_DISPLAYCOUNT,			cgc_displayCount,				sizeof(cgc_displayCount) - 1,				_VAR_TYPE_S32,			0  		},					// Default number of items to display in a combobox
		{	_INDEX_DISPLAYVALUE,			cgc_displayValue,				sizeof(cgc_displayValue) - 1,				_VAR_TYPE_CHARACTER,	(u32)&cgcEmptyString[0] },	// The displayed value in a listbox or combobox
		{	_INDEX_DOCREATE,				cgc_doCreate,					sizeof(cgc_doCreate) - 1,					_VAR_TYPE_LOGICAL,		1  		},					// A pseudo-property indicating if the form should actually be created
		{	_INDEX_DOCKPOSITION,			cgc_dockPosition,				sizeof(cgc_dockPosition) - 1,				_VAR_TYPE_S32,			0  		},					// -1=not docked, 0=top, 1=left, 2=right, 3=bottom, 4=tabbed, 5=link-docked
		{	_INDEX_DOCKABLE,				cgc_dockable,					sizeof(cgc_dockable) - 1,					_VAR_TYPE_LOGICAL,		0  		},					// .t.=yes, .f.=no (default)
		{	_INDEX_DOCKED,					cgc_docked,						sizeof(cgc_docked) - 1,						_VAR_TYPE_LOGICAL,		0  		},					// .t.=yes, .f.=no (default)
		{	_INDEX_DOCUMENTFILE,			cgc_documentFile,				sizeof(cgc_documentFile) - 1,				_VAR_TYPE_CHARACTER,	(u32)&cgcEmptyString[0] },	// Name of the OLE-bound document file (if any)
		{	_INDEX_DOWNPICTURE,				cgc_downPicture,				sizeof(cgc_downPicture) - 1,				_VAR_TYPE_CHARACTER,	(u32)&cgcEmptyString[0] },	// Name of the graphic to display when the mouse is down
		{	_INDEX_DRAGICON,				cgc_dragIcon,					sizeof(cgc_dragIcon) - 1,					_VAR_TYPE_CHARACTER,	(u32)&cgcEmptyString[0] },	// Name of the icon to display when the object is being dragged
		{	_INDEX_DRAGMODE,				cgc_dragMode,					sizeof(cgc_dragMode) - 1,					_VAR_TYPE_S32,			0  		},					// 0=manual (default), 1=automatic
		{	_INDEX_DRAWMODE,				cgc_drawMode,					sizeof(cgc_drawMode) - 1,					_VAR_TYPE_S32,			13  	},					// 1=black pen, 2=NOT Merge pen, 3=mask NOT pen, 4=NOT copy pen, 5=mask NOT pen, 6=invert, 7=xor, 8=NOT mask pen, 9=mask pen, 10=NOT xor, 11=NOP, 12=merge NOT pen, 13=copy, 14=merge pen NOT, 15=merge pen, 16=white pen
		{	_INDEX_DRAWSTYLE,				cgc_drawStyle,					sizeof(cgc_drawStyle) - 1,					_VAR_TYPE_S32,			0  		},					// 0=solid, 1=dash, 2=dot, 3=dash-dot, 4=dash-dot-dot, 5=transparent, 6=inside solid
		{	_INDEX_DRAWWIDTH,				cgc_drawWidth,					sizeof(cgc_drawWidth) - 1,					_VAR_TYPE_S32,			1  		},					// Pixel width for drawing
		{	_INDEX_DYNAMICALIGNMENT,		cgc_dynamicAlignment,			sizeof(cgc_dynamicAlignment) - 1,			_VAR_TYPE_S32,			3  		},					// 0=middle left, 1=middle right, 2=middle center, 3=automatic (default), 4=top left, 5=top right, 6=top center, 7=bottom left, 8=bottom right, 9=bottom center
		{	_INDEX_DYNAMICBACKCOLOR,		cgc_dynamicBackColor,			sizeof(cgc_dynamicBackColor) - 1,			_VAR_TYPE_CHARACTER,	(u32)&cgcEmptyString[0] },	// Character expression evaluated for the value
		{	_INDEX_DYNAMICCURRENTCONTROL,	cgc_dynamicCurrentControl,		sizeof(cgc_dynamicCurrentControl) - 1,		_VAR_TYPE_CHARACTER,	(u32)&cgcEmptyString[0] },	// Character expression evaluated for the active control for that cell
		{	_INDEX_DYNAMICFONTBOLD,			cgc_dynamicFontBold,			sizeof(cgc_dynamicFontBold) - 1,			_VAR_TYPE_CHARACTER,	(u32)&cgcEmptyString[0] },	// Character expression evaluated for the value
		{	_INDEX_DYNAMICFONTITALIC,		cgc_dynamicFontItalic,			sizeof(cgc_dynamicFontItalic) - 1,			_VAR_TYPE_CHARACTER,	(u32)&cgcEmptyString[0] },	// Character expression evaluated for the value
		{	_INDEX_DYNAMICFONTNAME,			cgc_dynamicFontName,			sizeof(cgc_dynamicFontName) - 1,			_VAR_TYPE_CHARACTER,	(u32)&cgcEmptyString[0] },	// Character expression evaluated for the value
		{	_INDEX_DYNAMICFONTOUTLINE,		cgc_dynamicFontOutline,			sizeof(cgc_dynamicFontOutline) - 1,			_VAR_TYPE_CHARACTER,	(u32)&cgcEmptyString[0] },	// Character expression evaluated for the value
		{	_INDEX_DYNAMICFONTSHADOW,		cgc_dynamicFontShadow,			sizeof(cgc_dynamicFontShadow) - 1,			_VAR_TYPE_CHARACTER,	(u32)&cgcEmptyString[0] },	// Character expression evaluated for the value
		{	_INDEX_DYNAMICFONTSIZE,			cgc_dynamicFontSize,			sizeof(cgc_dynamicFontSize) - 1,			_VAR_TYPE_CHARACTER,	(u32)&cgcEmptyString[0] },	// Character expression evaluated for the value
		{	_INDEX_DYNAMICFONTSTRIKETHRU,	cgc_dynamicFontStrikeThru,		sizeof(cgc_dynamicFontStrikeThru) - 1,		_VAR_TYPE_CHARACTER,	(u32)&cgcEmptyString[0] },	// Character expression evaluated for the value
		{	_INDEX_DYNAMICFONTUNDERLINE,	cgc_dynamicFontUnderline,		sizeof(cgc_dynamicFontUnderline) - 1,		_VAR_TYPE_CHARACTER,	(u32)&cgcEmptyString[0] },	// Character expression evaluated for the value
		{	_INDEX_DYNAMICFORECOLOR,		cgc_dynamicForeColor,			sizeof(cgc_dynamicForeColor) - 1,			_VAR_TYPE_CHARACTER,	(u32)&cgcEmptyString[0] },	// Character expression evaluated for the value
		{	_INDEX_DYNAMICINPUTMASK,		cgc_dynamicInputMask,			sizeof(cgc_dynamicInputMask) - 1,			_VAR_TYPE_CHARACTER,	(u32)&cgcEmptyString[0] },	// Character expression evaluated for the value
		{	_INDEX_ENABLEHYPERLINKS,		cgc_enableHyperlinks,			sizeof(cgc_enableHyperlinks) - 1,			_VAR_TYPE_LOGICAL,		1  		},					// .t.=yes, .f.=no (default) are hyperlinks enabled in an editbox or textbox
		{	_INDEX_ENABLED,					cgc_enabled,					sizeof(cgc_enabled) - 1,					_VAR_TYPE_LOGICAL,		1  		},					// .t.=yes (default), .f.=no
		{	_INDEX_ERRORNO,					cgc_errorNo,					sizeof(cgc_errorNo) - 1,					_VAR_TYPE_S32,			0  		},					// The error number on an exception
		{	_INDEX_FILLCOLOR,				cgc_fillColor,					sizeof(cgc_fillColor) - 1,					_VAR_TYPE_S32,			_whiteColor },				// The default fill color
		{	_INDEX_FILLSTYLE,				cgc_fillStyle,					sizeof(cgc_fillStyle) - 1,					_VAR_TYPE_S32,			_FILL_STYLE_TRANSPARENT },	// 0=solid, 1=transparent (default), 2=horizontal lines, 3=vertical line, 4=ul to lr diagonal, 5=ll to ur diagonal, 6=horizontal and vertical, 7=both diagonals
		{	_INDEX_FIRSTELEMENT,			cgc_firstElement,				sizeof(cgc_firstElement) - 1,				_VAR_TYPE_S32,			1  		},					// The array element to display in listbox or combobox when rowSourcetype = 5 (array)
		{	_INDEX_FONTBOLD,				cgc_fontBold,					sizeof(cgc_fontBold) - 1,					_VAR_TYPE_LOGICAL,		0  		},					// .t.=bold, .f.=not bold (default)
		{	_INDEX_FONTCHARSET,				cgc_fontCharSet,				sizeof(cgc_fontCharSet) - 1,				_VAR_TYPE_S32,			1  		},					// The default font set
		{	_INDEX_FONTCONDENSE,			cgc_fontCondense,				sizeof(cgc_fontCondense) - 1,				_VAR_TYPE_LOGICAL,		0  		},					// .t.=condense, .f.=not condense (default)
		{	_INDEX_FONTEXTEND,				cgc_fontExtend,					sizeof(cgc_fontExtend) - 1,					_VAR_TYPE_LOGICAL,		0  		},					// .t.=extend, .f.=not extend (default)
		{	_INDEX_FONTITALIC,				cgc_fontItalic,					sizeof(cgc_fontItalic) - 1,					_VAR_TYPE_LOGICAL,		0  		},					// .t.=italic, .f.=not italic (default)
		{	_INDEX_FONTNAME,				cgc_fontName,					sizeof(cgc_fontName) - 1,					_VAR_TYPE_CHARACTER,	(u32)&cgcFontName_default[0] },	// Ubuntu fonts are used by Visual FreePro, Jr. by default
		{	_INDEX_FONTOUTLINE,				cgc_fontOutline,				sizeof(cgc_fontOutline) - 1,				_VAR_TYPE_LOGICAL,		0  		},					// .t.=outline, .f.=not outline (default)
		{	_INDEX_FONTSHADOW,				cgc_fontShadow,					sizeof(cgc_fontShadow) - 1,					_VAR_TYPE_LOGICAL,		0  		},					// .t.=shadow, .f.=not shadow (default)
		{	_INDEX_FONTSIZE,				cgc_fontSize,					sizeof(cgc_fontSize) - 1,					_VAR_TYPE_S32,			10 		},					// Default font size is 10pt
		{	_INDEX_FONTSTRIKETHRU,			cgc_fontStrikeThru,				sizeof(cgc_fontStrikeThru) - 1,				_VAR_TYPE_LOGICAL,		0  		},					// .t.=strikethru, .f.=not strikethru (default)
		{	_INDEX_FONTUNDERLINE,			cgc_fontUnderLine,				sizeof(cgc_fontUnderLine) - 1,				_VAR_TYPE_LOGICAL,		0  		},					// .t.=underline, .f.=not underline (default)
		{	_INDEX_FORECOLOR,				cgc_foreColor,					sizeof(cgc_foreColor) - 1,					_VAR_TYPE_S32,			0  		},					// Black
		{	_INDEX_FORMCOUNT,				cgc_formCount,					sizeof(cgc_formCount) - 1,					_VAR_TYPE_S32,			0  		},					// Number of forms in a form set
		{	_INDEX_FORMAT,					cgc_format,						sizeof(cgc_format) - 1,						_VAR_TYPE_CHARACTER,	(u32)&cgcEmptyString[0] },	// The input format string
		{	_INDEX_FORMS,					cgc_forms,						sizeof(cgc_forms) - 1,						_VAR_TYPE_OBJECT,		0		},					// A pseudo index object to access the forms of a form set
		{	_INDEX_GRIDLINECOLOR,			cgc_gridLineColor,				sizeof(cgc_gridLineColor) - 1,				_VAR_TYPE_S32,			_blackColor },				// The default grid line color
		{	_INDEX_GRIDLINEWIDTH,			cgc_gridLineWidth,				sizeof(cgc_gridLineWidth) - 1,				_VAR_TYPE_S32,			1  		},					// The default grid line width
		{	_INDEX_GRIDLINES,				cgc_gridLines,					sizeof(cgc_gridLines) - 1,					_VAR_TYPE_S32,			_GRID_LINES_BOTH },			// 0=none, 1=horizontal only, 2=vertical online, 3=both (default)
		{	_INDEX_HSCROLLSMALLCHANGE,		cgc_hScrollSmallChange,			sizeof(cgc_hScrollSmallChange) - 1,			_VAR_TYPE_S32,			10 		},					// When scalemode = 3, default is 10 pixels
		{	_INDEX_HWND,					cgc_hWnd,						sizeof(cgc_hWnd) - 1,						_VAR_TYPE_S32,			0  		},					// A direct handle to the OS window
		{	_INDEX_HALFHEIGHTCAPTION,		cgc_halfHeightCaption,			sizeof(cgc_halfHeightCaption) - 1,			_VAR_TYPE_LOGICAL,		0  		},					// .t.=half height, .f.=full height (default) visual FreePro, Jr. does not use this setting, but it remains for compatibility
		{	_INDEX_HEADERCLASS,				cgc_headerClass,				sizeof(cgc_headerClass) - 1,				_VAR_TYPE_CHARACTER,	(u32)&cgcEmptyString[0] },	// The default header class for a grid
		{	_INDEX_HEADERCLASSLIBRARY,		cgc_headerClassLibrary,			sizeof(cgc_headerClassLibrary) - 1,			_VAR_TYPE_CHARACTER,	(u32)&cgcEmptyString[0] },	// The default header class library for a grid
		{	_INDEX_HEADERHEIGHT,			cgc_headerHeight,				sizeof(cgc_headerHeight) - 1,				_VAR_TYPE_S32,			0  		},					// The header height for a grid
		{	_INDEX_HEIGHT,					cgc_height,						sizeof(cgc_height) - 1,						_VAR_TYPE_S32,			0  		},					// The height of the object
		{	_INDEX_HELPCONTEXTID,			cgc_helpContextID,				sizeof(cgc_helpContextID) - 1,				_VAR_TYPE_S32,			0  		},					// The help context id
		{	_INDEX_HIDESELECTION,			cgc_hideSelection,				sizeof(cgc_hideSelection) - 1,				_VAR_TYPE_LOGICAL,		0  		},					// .t.=yes (default), .f.=no (should the selected text be hidden (shown as regular text) when the control loses focus)
		{	_INDEX_HIGHLIGHT,				cgc_highLight,					sizeof(cgc_highLight) - 1,					_VAR_TYPE_LOGICAL,		1  		},					// .t.=yes (default), .f.=no (should the grid cell be highlighted in navigation)
		{	_INDEX_HIGHLIGHTROW,			cgc_highLightRow,				sizeof(cgc_highLightRow) - 1,				_VAR_TYPE_LOGICAL,		1  		},					// .t.=yes (default), .f.=no (should the entire  grid cell row be highlighted in navigation)
		{	_INDEX_HIGHLIGHTBACKCOLOR,		cgc_highlightBackColor,			sizeof(cgc_highlightBackColor) - 1,			_VAR_TYPE_S32,			_selectedBackColor },		// The default highlight back color
		{	_INDEX_HIGHLIGHTFORECOLOR,		cgc_highlightForeColor,			sizeof(cgc_highlightForeColor) - 1,			_VAR_TYPE_S32,			_selectedForeColor },		// The default highlight fore color
		{	_INDEX_HIGHLIGHTROWLINEWIDTH,	cgc_highlightRowLineWidth,		sizeof(cgc_highlightRowLineWidth) - 1,		_VAR_TYPE_S32,			1  		},					// In pixels, the thickness of the border around the entire grid cell row
		{	_INDEX_HIGHLIGHTSTYLE,			cgc_highlightStyle,				sizeof(cgc_highlightStyle) - 1,				_VAR_TYPE_S32,			0  		},					// 0=no color (default), 1=highlight current row only, 2=highlight all rows
		{	_INDEX_HOSTNAME,				cgc_hostName,					sizeof(cgc_hostName) - 1,					_VAR_TYPE_CHARACTER,	(u32)&cgcEmptyString[0] },	// The name to display for OLE controls
		{	_INDEX_HOURS,					cgc_hours,						sizeof(cgc_hours) - 1,						_VAR_TYPE_S32,			0  		},					// 0=use SET HOURS (default), 1=12 hour, 2=24-hour
		{	_INDEX_IMEMODE,					cgc_iMEMode,					sizeof(cgc_iMEMode) - 1,					_VAR_TYPE_S32,			0  		},					// 0=use OS settings (default), 1=open on focus, 2=close on focus
		{	_INDEX_INCREMENT,				cgc_increment,					sizeof(cgc_increment) - 1,					_VAR_TYPE_F64,			1		},					// The default increment for spinners
		{	_INDEX_INCREMENTALSEARCH,		cgc_incrementalSearch,			sizeof(cgc_incrementalSearch) - 1,			_VAR_TYPE_LOGICAL,		1  		},					// .t.=yes (default), .f.=no (should keyboard input perform a search on each character)
		{	_INDEX_INPUTMASK,				cgc_inputMask,					sizeof(cgc_inputMask) - 1,					_VAR_TYPE_CHARACTER,	(u32)&cgcEmptyString[0] },	// The input mask
		{	_INDEX_INTEGRALHEIGHT,			cgc_integralHeight,				sizeof(cgc_integralHeight) - 1,				_VAR_TYPE_LOGICAL,		0  		},					// .t.=yes, .f.=no (default) (should the height of a control be auto-adjusted so the last line is fully displayed)
		{	_INDEX_INTERVAL,				cgc_interval,					sizeof(cgc_interval) - 1,					_VAR_TYPE_S32,			0		},					// The default interval between timer fires
		{	_INDEX_ITEMBACKCOLOR,			cgc_itemBackColor,				sizeof(cgc_itemBackColor) - 1,				_VAR_TYPE_S32,			_whiteColor },				// White
		{	_INDEX_ITEMDATA,				cgc_itemData,					sizeof(cgc_itemData) - 1,					_VAR_TYPE_S32,			0  		},					// A pseudo-property used for indexed access to listbox or combobox data 
		{	_INDEX_ITEMFORECOLOR,			cgc_itemForeColor,				sizeof(cgc_itemForeColor) - 1,				_VAR_TYPE_S32,			_blackColor },				// Black
		{	_INDEX_ITEMIDDATA,				cgc_itemIDData,					sizeof(cgc_itemIDData) - 1,					_VAR_TYPE_S32,			0  		},
		{	_INDEX_ITEMTIPS,				cgc_itemTips,					sizeof(cgc_itemTips) - 1,					_VAR_TYPE_S32,			0  		},
		{	_INDEX_KEYPREVIEW,				cgc_keyPreview,					sizeof(cgc_keyPreview) - 1,					_VAR_TYPE_S32,			0  		},
		{	_INDEX_KEYSORT,					cgc_keySort,					sizeof(cgc_keySort) - 1,					_VAR_TYPE_S32,			0  		},
		{	_INDEX_KEYBOARDHIGHVALUE,		cgc_keyboardHighValue,			sizeof(cgc_keyboardHighValue) - 1,			_VAR_TYPE_S32,			0  		},
		{	_INDEX_KEYBOARDLOWVALUE,		cgc_keyboardLowValue,			sizeof(cgc_keyboardLowValue) - 1,			_VAR_TYPE_S32,			0  		},
		{	_INDEX_LEFT,					cgc_left,						sizeof(cgc_left) - 1,						_VAR_TYPE_S32,			0  		},
		{	_INDEX_LEFTCOLUMN,				cgc_leftColumn,					sizeof(cgc_leftColumn) - 1,					_VAR_TYPE_S32,			0  		},
		{	_INDEX_LINECONTENTS,			cgc_lineContents,				sizeof(cgc_lineContents) - 1,				_VAR_TYPE_S32,			0  		},
		{	_INDEX_LINENO,					cgc_lineNo,						sizeof(cgc_lineNo) - 1,						_VAR_TYPE_S32,			0  		},
		{	_INDEX_LINESLANT,				cgc_lineSlant,					sizeof(cgc_lineSlant) - 1,					_VAR_TYPE_S32,			0  		},
		{	_INDEX_LINKMASTER,				cgc_linkMaster,					sizeof(cgc_linkMaster) - 1,					_VAR_TYPE_S32,			0  		},
		{	_INDEX_LIST,					cgc_list,						sizeof(cgc_list) - 1,						_VAR_TYPE_S32,			0  		},
		{	_INDEX_LISTCOUNT,				cgc_listCount,					sizeof(cgc_listCount) - 1,					_VAR_TYPE_S32,			0  		},
		{	_INDEX_LISTINDEX,				cgc_listIndex,					sizeof(cgc_listIndex) - 1,					_VAR_TYPE_S32,			0  		},
		{	_INDEX_LISTITEM,				cgc_listItem,					sizeof(cgc_listItem) - 1,					_VAR_TYPE_S32,			0  		},
		{	_INDEX_LISTITEMID,				cgc_listItemID,					sizeof(cgc_listItemID) - 1,					_VAR_TYPE_S32,			0  		},
		{	_INDEX_LOCKCOLUMNS,				cgc_lockColumns,				sizeof(cgc_lockColumns) - 1,				_VAR_TYPE_S32,			0  		},
		{	_INDEX_LOCKCOLUMNSLEFT,			cgc_lockColumnsLeft,			sizeof(cgc_lockColumnsLeft) - 1,			_VAR_TYPE_S32,			0  		},
		{	_INDEX_LOCKSCREEN,				cgc_lockScreen,					sizeof(cgc_lockScreen) - 1,					_VAR_TYPE_S32,			0  		},
		{	_INDEX_MDIFORM,					cgc_mDIForm,					sizeof(cgc_mDIForm) - 1,					_VAR_TYPE_S32,			0  		},
		{	_INDEX_MACDESKTOP,				cgc_macDesktop,					sizeof(cgc_macDesktop) - 1,					_VAR_TYPE_S32,			0  		},
		{	_INDEX_MARGIN,					cgc_margin,						sizeof(cgc_margin) - 1,						_VAR_TYPE_S32,			0  		},
		{	_INDEX_MAXBUTTON,				cgc_maxButton,					sizeof(cgc_maxButton) - 1,					_VAR_TYPE_S32,			0  		},
		{	_INDEX_MAXHEIGHT,				cgc_maxHeight,					sizeof(cgc_maxHeight) - 1,					_VAR_TYPE_S32,			0  		},
		{	_INDEX_MAXLEFT,					cgc_maxLeft,					sizeof(cgc_maxLeft) - 1,					_VAR_TYPE_S32,			0  		},
		{	_INDEX_MAXLENGTH,				cgc_maxLength,					sizeof(cgc_maxLength) - 1,					_VAR_TYPE_S32,			0  		},
		{	_INDEX_MAXTOP,					cgc_maxTop,						sizeof(cgc_maxTop) - 1,						_VAR_TYPE_S32,			0  		},
		{	_INDEX_MAXWIDTH,				cgc_maxWidth,					sizeof(cgc_maxWidth) - 1,					_VAR_TYPE_S32,			0  		},
		{	_INDEX_MEMBERCLASS,				cgc_memberClass,				sizeof(cgc_memberClass) - 1,				_VAR_TYPE_S32,			0  		},
		{	_INDEX_MEMBERCLASSLIBRARY,		cgc_memberClassLibrary,			sizeof(cgc_memberClassLibrary) - 1,			_VAR_TYPE_S32,			0  		},
		{	_INDEX_MEMOWINDOW,				cgc_memoWindow,					sizeof(cgc_memoWindow) - 1,					_VAR_TYPE_S32,			0  		},
		{	_INDEX_MESSAGE,					cgc_message,					sizeof(cgc_message) - 1,					_VAR_TYPE_S32,			0  		},
		{	_INDEX_MINBUTTON,				cgc_minButton,					sizeof(cgc_minButton) - 1,					_VAR_TYPE_S32,			0  		},
		{	_INDEX_MINHEIGHT,				cgc_minHeight,					sizeof(cgc_minHeight) - 1,					_VAR_TYPE_S32,			0  		},
		{	_INDEX_MINWIDTH,				cgc_minWidth,					sizeof(cgc_minWidth) - 1,					_VAR_TYPE_S32,			0  		},
		{	_INDEX_MOUSEPOINTER,			cgc_mousePointer,				sizeof(cgc_mousePointer) - 1,				_VAR_TYPE_S32,			0  		},
		{	_INDEX_MOVABLE,					cgc_movable,					sizeof(cgc_movable) - 1,					_VAR_TYPE_S32,			0  		},
		{	_INDEX_MOVERBARS,				cgc_moverBars,					sizeof(cgc_moverBars) - 1,					_VAR_TYPE_S32,			0  		},
		{	_INDEX_MULTISELECT,				cgc_multiSelect,				sizeof(cgc_multiSelect) - 1,				_VAR_TYPE_S32,			0  		},
		{	_INDEX_NAME,					cgc_name,						sizeof(cgc_name) - 1,						_VAR_TYPE_S32,			0  		},
		{	_INDEX_NEWINDEX,				cgc_newIndex,					sizeof(cgc_newIndex) - 1,					_VAR_TYPE_S32,			0  		},
		{	_INDEX_NEWITEMID,				cgc_newItemID,					sizeof(cgc_newItemID) - 1,					_VAR_TYPE_S32,			0  		},
		{	_INDEX_NULLDISPLAY,				cgc_nullDisplay,				sizeof(cgc_nullDisplay) - 1,				_VAR_TYPE_S32,			0  		},
		{	_INDEX_NUMBEROFELEMENTS,		cgc_numberOfElements,			sizeof(cgc_numberOfElements) - 1,			_VAR_TYPE_S32,			0  		},
		{	_INDEX_OLECLASS,				cgc_oLEClass,					sizeof(cgc_oLEClass) - 1,					_VAR_TYPE_S32,			0  		},
		{	_INDEX_OLEDRAGMODE,				cgc_oLEDragMode,				sizeof(cgc_oLEDragMode) - 1,				_VAR_TYPE_S32,			0  		},
		{	_INDEX_OLEDROPEFFECTS,			cgc_oLEDropEffects,				sizeof(cgc_oLEDropEffects) - 1,				_VAR_TYPE_S32,			0  		},
		{	_INDEX_OLEDROPHASDATA,			cgc_oLEDropHasData,				sizeof(cgc_oLEDropHasData) - 1,				_VAR_TYPE_S32,			0  		},
		{	_INDEX_OLEDROPMODE,				cgc_oLEDropMode,				sizeof(cgc_oLEDropMode) - 1,				_VAR_TYPE_S32,			0  		},
		{	_INDEX_OLEDROPTEXTINSERTION,	cgc_oLEDropTextInsertion,		sizeof(cgc_oLEDropTextInsertion) - 1,		_VAR_TYPE_S32,			0  		},
		{	_INDEX_OLELCID,					cgc_oLELCID,					sizeof(cgc_oLELCID) - 1,					_VAR_TYPE_S32,			0  		},
		{	_INDEX_OLETYPEALLOWED,			cgc_oLETypeAllowed,				sizeof(cgc_oLETypeAllowed) - 1,				_VAR_TYPE_S32,			0  		},
		{	_INDEX_OBJECT,					cgc_object,						sizeof(cgc_object) - 1,						_VAR_TYPE_S32,			0  		},
		{	_INDEX_OBJECTS,					cgc_objects,					sizeof(cgc_objects) - 1,					_VAR_TYPE_S32,			0  		},
		{	_INDEX_OPENWINDOW,				cgc_openWindow,					sizeof(cgc_openWindow) - 1,					_VAR_TYPE_S32,			0  		},
		{	_INDEX_OPTIMIZE,				cgc_optimize,					sizeof(cgc_optimize) - 1,					_VAR_TYPE_S32,			0  		},
		{	_INDEX_PAGECOUNT,				cgc_pageCount,					sizeof(cgc_pageCount) - 1,					_VAR_TYPE_S32,			0  		},
		{	_INDEX_PAGEHEIGHT,				cgc_pageHeight,					sizeof(cgc_pageHeight) - 1,					_VAR_TYPE_S32,			0  		},
		{	_INDEX_PAGEORDER,				cgc_pageOrder,					sizeof(cgc_pageOrder) - 1,					_VAR_TYPE_S32,			0  		},
		{	_INDEX_PAGEWIDTH,				cgc_pageWidth,					sizeof(cgc_pageWidth) - 1,					_VAR_TYPE_S32,			0  		},
		{	_INDEX_PAGES,					cgc_pages,						sizeof(cgc_pages) - 1,						_VAR_TYPE_S32,			0  		},
		{	_INDEX_PANEL,					cgc_panel,						sizeof(cgc_panel) - 1,						_VAR_TYPE_S32,			0  		},
		{	_INDEX_PANELLINK,				cgc_panelLink,					sizeof(cgc_panelLink) - 1,					_VAR_TYPE_S32,			0  		},
		{	_INDEX_PARENT,					cgc_parent,						sizeof(cgc_parent) - 1,						_VAR_TYPE_S32,			0  		},
		{	_INDEX_PARENTCLASS,				cgc_parentClass,				sizeof(cgc_parentClass) - 1,				_VAR_TYPE_S32,			0  		},
		{	_INDEX_PARTITION,				cgc_partition,					sizeof(cgc_partition) - 1,					_VAR_TYPE_S32,			0  		},
		{	_INDEX_PASSWORDCHAR,			cgc_passwordChar,				sizeof(cgc_passwordChar) - 1,				_VAR_TYPE_S32,			0  		},
		{	_INDEX_PICTURE,					cgc_picture,					sizeof(cgc_picture) - 1,					_VAR_TYPE_S32,			0  		},
		{	_INDEX_PICTUREMARGIN,			cgc_pictureMargin,				sizeof(cgc_pictureMargin) - 1,				_VAR_TYPE_S32,			0  		},
		{	_INDEX_PICTUREPOSITION,			cgc_picturePosition,			sizeof(cgc_picturePosition) - 1,			_VAR_TYPE_S32,			0  		},
		{	_INDEX_PICTURESELECTIONDISPLAY, cgc_pictureSelectionDisplay,	sizeof(cgc_pictureSelectionDisplay) - 1,	_VAR_TYPE_S32,			0  		},
		{	_INDEX_PICTURESPACING,			cgc_pictureSpacing,				sizeof(cgc_pictureSpacing) - 1,				_VAR_TYPE_S32,			0  		},
		{	_INDEX_PICTUREVAL,				cgc_pictureVal,					sizeof(cgc_pictureVal) - 1,					_VAR_TYPE_S32,			0  		},
		{	_INDEX_POLYPOINTS,				cgc_polyPoints,					sizeof(cgc_polyPoints) - 1,					_VAR_TYPE_S32,			0  		},
		{	_INDEX_PROCEDURE,				cgc_procedure,					sizeof(cgc_procedure) - 1,					_VAR_TYPE_S32,			0  		},
		{	_INDEX_READBACKCOLOR,			cgc_readBackColor,				sizeof(cgc_readBackColor) - 1,				_VAR_TYPE_S32,			0  		},
		{	_INDEX_READCYCLE,				cgc_readCycle,					sizeof(cgc_readCycle) - 1,					_VAR_TYPE_S32,			0  		},
		{	_INDEX_READFORECOLOR,			cgc_readForeColor,				sizeof(cgc_readForeColor) - 1,				_VAR_TYPE_S32,			0  		},
		{	_INDEX_READLOCK,				cgc_readLock,					sizeof(cgc_readLock) - 1,					_VAR_TYPE_S32,			0  		},
		{	_INDEX_READMOUSE,				cgc_readMouse,					sizeof(cgc_readMouse) - 1,					_VAR_TYPE_S32,			0  		},
		{	_INDEX_READONLY,				cgc_readOnly,					sizeof(cgc_readOnly) - 1,					_VAR_TYPE_S32,			0  		},
		{	_INDEX_READSAVE,				cgc_readSave,					sizeof(cgc_readSave) - 1,					_VAR_TYPE_S32,			0  		},
		{	_INDEX_READTIMEOUT,				cgc_readTimeOut,				sizeof(cgc_readTimeOut) - 1,				_VAR_TYPE_S32,			0  		},
		{	_INDEX_RECORDMARK,				cgc_recordMark,					sizeof(cgc_recordMark) - 1,					_VAR_TYPE_S32,			0  		},
		{	_INDEX_RECORDSOURCE,			cgc_recordSource,				sizeof(cgc_recordSource) - 1,				_VAR_TYPE_S32,			0  		},
		{	_INDEX_RECORDSOURCETYPE,		cgc_recordSourceType,			sizeof(cgc_recordSourceType) - 1,			_VAR_TYPE_S32,			0  		},
		{	_INDEX_RELATIONALEXPR,			cgc_relationalExpr,				sizeof(cgc_relationalExpr) - 1,				_VAR_TYPE_S32,			0  		},
		{	_INDEX_RELATIVECOLUMN,			cgc_relativeColumn,				sizeof(cgc_relativeColumn) - 1,				_VAR_TYPE_S32,			0  		},
		{	_INDEX_RELATIVEROW,				cgc_relativeRow,				sizeof(cgc_relativeRow) - 1,				_VAR_TYPE_S32,			0  		},
		{	_INDEX_RELEASETYPE,				cgc_releaseType,				sizeof(cgc_releaseType) - 1,				_VAR_TYPE_S32,			0  		},
		{	_INDEX_RESIZABLE,				cgc_resizable,					sizeof(cgc_resizable) - 1,					_VAR_TYPE_S32,			0  		},
		{	_INDEX_RIGHTTOLEFT,				cgc_rightToLeft,				sizeof(cgc_rightToLeft) - 1,				_VAR_TYPE_S32,			0  		},
		{	_INDEX_ROTATEFLIP,				cgc_rotateFlip,					sizeof(cgc_rotateFlip) - 1,					_VAR_TYPE_S32,			0  		},
		{	_INDEX_ROTATION,				cgc_rotation,					sizeof(cgc_rotation) - 1,					_VAR_TYPE_S32,			0  		},
		{	_INDEX_ROWCOLCHANGE,			cgc_rowColChange,				sizeof(cgc_rowColChange) - 1,				_VAR_TYPE_S32,			0  		},
		{	_INDEX_ROWHEIGHT,				cgc_rowHeight,					sizeof(cgc_rowHeight) - 1,					_VAR_TYPE_S32,			0  		},
		{	_INDEX_ROWSOURCE,				cgc_rowSource,					sizeof(cgc_rowSource) - 1,					_VAR_TYPE_S32,			0  		},
		{	_INDEX_ROWSOURCETYPE,			cgc_rowSourceType,				sizeof(cgc_rowSourceType) - 1,				_VAR_TYPE_S32,			0  		},
		{	_INDEX_SCALEMODE,				cgc_scaleMode,					sizeof(cgc_scaleMode) - 1,					_VAR_TYPE_S32,			3  		},					// 0=foxels, 1=pixels (default)
		{	_INDEX_SCROLLBARS,				cgc_scrollBars,					sizeof(cgc_scrollBars) - 1,					_VAR_TYPE_S32,			0  		},
		{	_INDEX_SECONDS,					cgc_seconds,					sizeof(cgc_seconds) - 1,					_VAR_TYPE_S32,			0  		},
		{	_INDEX_SELLENGTH,				cgc_selLength,					sizeof(cgc_selLength) - 1,					_VAR_TYPE_S32,			0  		},
		{	_INDEX_SELSTART,				cgc_selStart,					sizeof(cgc_selStart) - 1,					_VAR_TYPE_S32,			0  		},
		{	_INDEX_SELTEXT,					cgc_selText,					sizeof(cgc_selText) - 1,					_VAR_TYPE_S32,			0  		},
		{	_INDEX_SELECTONENTRY,			cgc_selectOnEntry,				sizeof(cgc_selectOnEntry) - 1,				_VAR_TYPE_S32,			0  		},
		{	_INDEX_SELECTED,				cgc_selected,					sizeof(cgc_selected) - 1,					_VAR_TYPE_S32,			0  		},
		{	_INDEX_SELECTEDBACKCOLOR,		cgc_selectedBackColor,			sizeof(cgc_selectedBackColor) - 1,			_VAR_TYPE_S32,			0  		},
		{	_INDEX_SELECTEDFORECOLOR,		cgc_selectedForeColor,			sizeof(cgc_selectedForeColor) - 1,			_VAR_TYPE_S32,			0  		},
		{	_INDEX_SELECTEDID,				cgc_selectedID,					sizeof(cgc_selectedID) - 1,					_VAR_TYPE_S32,			0  		},
		{	_INDEX_SELECTEDITEMBACKCOLOR,	cgc_selectedItemBackColor,		sizeof(cgc_selectedItemBackColor) - 1,		_VAR_TYPE_S32,			0  		},
		{	_INDEX_SELECTEDITEMFORECOLOR,	cgc_selectedItemForeColor,		sizeof(cgc_selectedItemForeColor) - 1,		_VAR_TYPE_S32,			0  		},
		{	_INDEX_SHOWINTASKBAR,			cgc_showInTaskbar,				sizeof(cgc_showInTaskbar) - 1,				_VAR_TYPE_S32,			0  		},
		{	_INDEX_SHOWTIPS,				cgc_showTips,					sizeof(cgc_showTips) - 1,					_VAR_TYPE_S32,			0  		},
		{	_INDEX_SHOWWINDOW,				cgc_showWindow,					sizeof(cgc_showWindow) - 1,					_VAR_TYPE_S32,			0  		},
		{	_INDEX_SIZABLE,					cgc_sizable,					sizeof(cgc_sizable) - 1,					_VAR_TYPE_S32,			0  		},
		{	_INDEX_SIZEBOX,					cgc_sizeBox,					sizeof(cgc_sizeBox) - 1,					_VAR_TYPE_S32,			0  		},
		{	_INDEX_SORTED,					cgc_sorted,						sizeof(cgc_sorted) - 1,						_VAR_TYPE_S32,			0  		},
		{	_INDEX_SPARSE,					cgc_sparse,						sizeof(cgc_sparse) - 1,						_VAR_TYPE_S32,			0  		},
		{	_INDEX_SPECIALEFFECT,			cgc_specialEffect,				sizeof(cgc_specialEffect) - 1,				_VAR_TYPE_S32,			0  		},
		{	_INDEX_SPINNERHIGHVALUE,		cgc_spinnerHighValue,			sizeof(cgc_spinnerHighValue) - 1,			_VAR_TYPE_S32,			0  		},
		{	_INDEX_SPINNERLOWVALUE,			cgc_spinnerLowValue,			sizeof(cgc_spinnerLowValue) - 1,			_VAR_TYPE_S32,			0  		},
		{	_INDEX_SPLITBAR,				cgc_splitBar,					sizeof(cgc_splitBar) - 1,					_VAR_TYPE_S32,			0  		},
		{	_INDEX_STACKLEVEL,				cgc_stackLevel,					sizeof(cgc_stackLevel) - 1,					_VAR_TYPE_S32,			0  		},
		{	_INDEX_STATUSBARTEXT,			cgc_statusBarText,				sizeof(cgc_statusBarText) - 1,				_VAR_TYPE_S32,			0  		},
		{	_INDEX_STRETCH,					cgc_stretch,					sizeof(cgc_stretch) - 1,					_VAR_TYPE_S32,			0  		},
		{	_INDEX_STRICTDATEENTRY,			cgc_strictDateEntry,			sizeof(cgc_strictDateEntry) - 1,			_VAR_TYPE_S32,			0  		},
		{	_INDEX_STYLE,					cgc_style,						sizeof(cgc_style) - 1,						_VAR_TYPE_S32,			0  		},
		{	_INDEX_TABINDEX,				cgc_tabIndex,					sizeof(cgc_tabIndex) - 1,					_VAR_TYPE_S32,			0  		},
		{	_INDEX_TABORIENTATION,			cgc_tabOrientation,				sizeof(cgc_tabOrientation) - 1,				_VAR_TYPE_S32,			0  		},
		{	_INDEX_TABSTOP,					cgc_tabStop,					sizeof(cgc_tabStop) - 1,					_VAR_TYPE_S32,			0  		},
		{	_INDEX_TABSTYLE,				cgc_tabStyle,					sizeof(cgc_tabStyle) - 1,					_VAR_TYPE_S32,			0  		},
		{	_INDEX_TABS,					cgc_tabs,						sizeof(cgc_tabs) - 1,						_VAR_TYPE_S32,			0  		},
		{	_INDEX_TAG,						cgc_tag,						sizeof(cgc_tag) - 1,						_VAR_TYPE_S32,			0  		},
		{	_INDEX_TERMINATEREAD,			cgc_terminateRead,				sizeof(cgc_terminateRead) - 1,				_VAR_TYPE_S32,			0  		},
		{	_INDEX_TEXT,					cgc_text,						sizeof(cgc_text) - 1,						_VAR_TYPE_S32,			0  		},
		{	_INDEX_THEMES,					cgc_themes,						sizeof(cgc_themes) - 1,						_VAR_TYPE_S32,			0  		},
		{	_INDEX_TITLEBAR,				cgc_titleBar,					sizeof(cgc_titleBar) - 1,					_VAR_TYPE_S32,			0  		},
		{	_INDEX_TOOLTIPTEXT,				cgc_toolTipText,				sizeof(cgc_toolTipText) - 1,				_VAR_TYPE_S32,			0  		},
		{	_INDEX_TOP,						cgc_top,						sizeof(cgc_top) - 1,						_VAR_TYPE_S32,			0  		},
		{	_INDEX_TOPINDEX,				cgc_topIndex,					sizeof(cgc_topIndex) - 1,					_VAR_TYPE_S32,			0  		},
		{	_INDEX_TOPITEMID,				cgc_topItemID,					sizeof(cgc_topItemID) - 1,					_VAR_TYPE_S32,			0  		},
		{	_INDEX_USERVALUE,				cgc_userValue,					sizeof(cgc_userValue) - 1,					_VAR_TYPE_S32,			0  		},
		{	_INDEX_VSCROLLSMALLCHANGE,		cgc_vScrollSmallChange,			sizeof(cgc_vScrollSmallChange) - 1,			_VAR_TYPE_S32,			0  		},
		{	_INDEX_VALUE,					cgc_value,						sizeof(cgc_value) - 1,						_VAR_TYPE_S32,			0  		},
		{	_INDEX_VIEW,					cgc_view,						sizeof(cgc_view) - 1,						_VAR_TYPE_S32,			0  		},
		{	_INDEX_VIEWPORTHEIGHT,			cgc_viewPortHeight,				sizeof(cgc_viewPortHeight) - 1,				_VAR_TYPE_S32,			0  		},
		{	_INDEX_VIEWPORTLEFT,			cgc_viewPortLeft,				sizeof(cgc_viewPortLeft) - 1,				_VAR_TYPE_S32,			0  		},
		{	_INDEX_VIEWPORTTOP,				cgc_viewPortTop,				sizeof(cgc_viewPortTop) - 1,				_VAR_TYPE_S32,			0  		},
		{	_INDEX_VIEWPORTWIDTH,			cgc_viewPortWidth,				sizeof(cgc_viewPortWidth) - 1,				_VAR_TYPE_S32,			0  		},
		{	_INDEX_VISIBLE,					cgc_visible,					sizeof(cgc_visible) - 1,					_VAR_TYPE_S32,			0  		},
		{	_INDEX_VISUALEFFECT,			cgc_visualEffect,				sizeof(cgc_visualEffect) - 1,				_VAR_TYPE_S32,			0  		},
		{	_INDEX_WHATSTHISBUTTON,			cgc_whatsThisButton,			sizeof(cgc_whatsThisButton) - 1,			_VAR_TYPE_S32,			0  		},
		{	_INDEX_WHATSTHISHELP,			cgc_whatsThisHelp,				sizeof(cgc_whatsThisHelp) - 1,				_VAR_TYPE_S32,			0  		},
		{	_INDEX_WHATSTHISHELPID,			cgc_whatsThisHelpID,			sizeof(cgc_whatsThisHelpID) - 1,			_VAR_TYPE_S32,			0  		},
		{	_INDEX_WIDTH,					cgc_width,						sizeof(cgc_width) - 1,						_VAR_TYPE_S32,			0  		},
		{	_INDEX_WINDOWLIST,				cgc_windowList,					sizeof(cgc_windowList) - 1,					_VAR_TYPE_S32,			0  		},
		{	_INDEX_WINDOWSTATE,				cgc_windowState,				sizeof(cgc_windowState) - 1,				_VAR_TYPE_S32,			0  		},
		{	_INDEX_WINDOWTYPE,				cgc_windowType,					sizeof(cgc_windowType) - 1,					_VAR_TYPE_S32,			0  		},
		{	_INDEX_WORDWRAP,				cgc_wordWrap,					sizeof(cgc_wordWrap) - 1,					_VAR_TYPE_S32,			0  		},
		{	_INDEX_ZOOMBOX,					cgc_zoomBox,					sizeof(cgc_zoomBox) - 1,					_VAR_TYPE_S32,			0  		},

// 	{	SBitmap*	icon,			false,	0	}
// 	{	SBitmap*	mouseIcon,			false,	0	}
// 	{	SBitmap*	oLEDragPicture,			false,	0	}

// 	SVariable*	pictureName;
// 	SBitmap*	bmpPicture;
// 	SVariable*	pictureOverName;
// 	SBitmap*	bmpPictureOver;
// 	SVariable*	pictureDownName;
// 	SBitmap*	bmpPictureDown;
//
// 	SVariable*	minValue;
// 	SVariable*	maxValue;
// 	SVariable*	mask;
	};


	struct SPropertyMap
	{
		u32			index;

		union {
			u32			_setter;
			bool		(*setterVar)	(SObject* obj, SVariable* var);
			bool		(*setterBmp)	(SObject* obj, SBitmap* bmp);
		};

		union {
			u32			_getter;
			SVariable*	(*getterVar)	(SObject* obj);
			SBitmap*	(*getterBmp)	(SObject* obj);
		};
	};

	SPropertyMap gcProps_empty[] =
	{
		{	0,								0,									0										}
	};

	SPropertyMap gcProps_subform[] =
	{
		{	_INDEX_ACTIVECONTROL,			(u32)&iObj_set_activeControl,		(u32)&iObj_get_activeControl			},
		{	_INDEX_ALLOWOUTPUT,				(u32)&iObj_set_allowOutput,			(u32)&iObj_get_allowOutput				},
		{	_INDEX_FILLCOLOR,				(u32)&iObj_set_fillColor,			(u32)&iObj_get_fillColor				},
		{	_INDEX_FILLSTYLE,				(u32)&iObj_set_fillStyle,			(u32)&iObj_get_fillStyle				},
		{	_INDEX_MAXHEIGHT,				(u32)&iObj_set_maxHeight,			(u32)&iObj_get_maxHeight				},
		{	_INDEX_MAXWIDTH,				(u32)&iObj_set_maxWidth,			(u32)&iObj_get_maxWidth					},
		{	_INDEX_MAXTOP,					(u32)&iObj_set_maxTop,				(u32)&iObj_get_maxTop					},
		{	_INDEX_MAXLEFT,					(u32)&iObj_set_maxLeft,				(u32)&iObj_get_maxLeft					},
		{	_INDEX_MINHEIGHT,				(u32)&iObj_set_minHeight,			(u32)&iObj_get_minHeight				},
		{	_INDEX_MINWIDTH,				(u32)&iObj_set_minWidth,			(u32)&iObj_get_minWidth					},
		{	_INDEX_BASECLASS,				(u32)&iObj_set_baseClass,			(u32)&iObj_get_baseClass				},
		{	_INDEX_CLASS,					(u32)&iObj_set_class,				(u32)&iObj_get_class					},
		{	_INDEX_CLASSLIBRARY,			(u32)&iObj_set_classLibrary,		(u32)&iObj_get_classLibrary				},
		{	_INDEX_CONTROLS,				(u32)&iObj_set_controls,			(u32)&iObj_get_controls					},
		{	_INDEX_CONTROLCOUNT,			(u32)&iObj_set_controlCount,		(u32)&iObj_get_controlCount				},
		{	_INDEX_OBJECTS,					(u32)&iObj_set_objects,				(u32)&iObj_get_objects					},
		{	_INDEX_BORDERSTYLE,				(u32)&iObj_set_borderStyle,			(u32)&iObj_get_borderStyle				},
		{	_INDEX_CAPTION,					(u32)&iObj_set_caption,				(u32)&iObj_get_caption					},
		{	_INDEX_FORECOLOR,				(u32)&iObj_set_foreColor,			(u32)&iObj_get_foreColor				},
		{	_INDEX_BACKCOLOR,				(u32)&iObj_set_backColor,			(u32)&iObj_get_backColor				},
		{	_INDEX_COMMENT,					(u32)&iObj_set_comment,				(u32)&iObj_get_comment					},
		{	_INDEX_ENABLED,					(u32)&iObj_set_enabled,				(u32)&iObj_get_enabled					},
		{	_INDEX_FONTBOLD,				(u32)&iObj_set_fontBold,			(u32)&iObj_get_fontBold					},
		{	_INDEX_FONTCHARSET,				(u32)&iObj_set_fontCharSet,			(u32)&iObj_get_fontCharSet				},
		{	_INDEX_FONTCONDENSE,			(u32)&iObj_set_fontCondense,		(u32)&iObj_get_fontCondense				},
		{	_INDEX_FONTEXTEND,				(u32)&iObj_set_fontExtend,			(u32)&iObj_get_fontExtend				},
		{	_INDEX_FONTITALIC,				(u32)&iObj_set_fontItalic,			(u32)&iObj_get_fontItalic				},
		{	_INDEX_FONTNAME,				(u32)&iObj_set_fontName,			(u32)&iObj_get_fontName					},
		{	_INDEX_FONTOUTLINE,				(u32)&iObj_set_fontOutline,			(u32)&iObj_get_fontOutline				},
		{	_INDEX_FONTSHADOW,				(u32)&iObj_set_fontShadow,			(u32)&iObj_get_fontShadow				},
		{	_INDEX_FONTSIZE,				(u32)&iObj_set_fontSize,			(u32)&iObj_get_fontSize					},
		{	_INDEX_FONTSTRIKETHRU,			(u32)&iObj_set_fontStrikeThru,		(u32)&iObj_get_fontStrikeThru			},
		{	_INDEX_FONTUNDERLINE,			(u32)&iObj_set_fontUnderline,		(u32)&iObj_get_fontUnderline			},
		{	_INDEX_HEIGHT,					(u32)&iObj_set_height,				(u32)&iObj_get_height					},
		{	_INDEX_HELPCONTEXTID,			(u32)&iObj_set_helpContextID,		(u32)&iObj_get_helpContextID			},
		{	_INDEX_HWND,					(u32)&iObj_set_hWnd,				(u32)&iObj_get_hWnd						},
		{	_INDEX_KEYPREVIEW,				(u32)&iObj_set_keyPreview,			(u32)&iObj_get_keyPreview				},
		{	_INDEX_LEFT,					(u32)&iObj_set_left,				(u32)&iObj_get_left						},
		{	_INDEX_MOUSEICON,				(u32)&iObj_set_mouseIcon,			(u32)&iObj_get_mouseIcon				},
		{	_INDEX_MOUSEPOINTER,			(u32)&iObj_set_mousePointer,		(u32)&iObj_get_mousePointer				},
		{	_INDEX_NAME,					(u32)&iObj_set_name,				(u32)&iObj_get_name						},
		{	_INDEX_PARENT,					(u32)&iObj_set_parent,				(u32)&iObj_get_parent					},
		{	_INDEX_PARENTCLASS,				(u32)&iObj_set_parentClass,			(u32)&iObj_get_parentClass				},
		{	_INDEX_ICON,					(u32)&iObj_set_icon,				(u32)&iObj_get_icon						},
		{	_INDEX_PICTURE,					(u32)&iObj_set_picture,				(u32)&iObj_get_picture					},
		{	_INDEX_TAG,						(u32)&iObj_set_tag,					(u32)&iObj_get_tag						},
		{	_INDEX_TOP,						(u32)&iObj_set_top,					(u32)&iObj_get_top						},
		{	_INDEX_VISIBLE,					(u32)&iObj_set_visible,				(u32)&iObj_get_visible					},
		{	_INDEX_WIDTH,					(u32)&iObj_set_width,				(u32)&iObj_get_width					},
		{	_INDEX_ZOOMBOX,					(u32)&iObj_set_zoomBox,				(u32)&iObj_get_zoomBox					},
		{	0,								0,									0										}
	};

	SPropertyMap gcProps_radio[] =
	{
		{	0,								0,									0										}
	};

	SPropertyMap gcProps_checkbox[] =
	{
		{	_INDEX_ALIGNMENT,				(u32)&iObj_set_alignment,			(u32)&iObj_get_alignment				},
		{	_INDEX_ANCHOR,					(u32)&iObj_set_anchor,				(u32)&iObj_get_anchor					},
		{	_INDEX_APPLICATION,				(u32)&iObj_set_application,			(u32)&iObj_get_application				},
		{	_INDEX_AUTOSIZE,				(u32)&iObj_set_autoSize,			(u32)&iObj_get_autoSize					},
		{	_INDEX_BACKSTYLE,				(u32)&iObj_set_backStyle,			(u32)&iObj_get_backStyle				},
		{	_INDEX_BASECLASS,				(u32)&iObj_set_baseClass,			(u32)&iObj_get_baseClass				},
		{	_INDEX_CLASS,					(u32)&iObj_set_class,				(u32)&iObj_get_class					},
		{	_INDEX_CLASSLIBRARY,			(u32)&iObj_set_classLibrary,		(u32)&iObj_get_classLibrary				},
		{	_INDEX_CAPTION,					(u32)&iObj_set_caption,				(u32)&iObj_get_caption					},
		{	_INDEX_CENTERED,				(u32)&iObj_set_centered,			(u32)&iObj_get_centered					},
		{	_INDEX_COLORSCHEME,				(u32)&iObj_set_colorScheme,			(u32)&iObj_get_colorScheme				},
		{	_INDEX_COLORSOURCE,				(u32)&iObj_set_colorSource,			(u32)&iObj_get_colorSource				},
		{	_INDEX_FORECOLOR,				(u32)&iObj_set_foreColor,			(u32)&iObj_get_foreColor				},
		{	_INDEX_BACKCOLOR,				(u32)&iObj_set_backColor,			(u32)&iObj_get_backColor				},
		{	_INDEX_DISABLEDBACKCOLOR,		(u32)&iObj_set_disabledBackColor,	(u32)&iObj_get_disabledBackColor		},
		{	_INDEX_DISABLEDFORECOLOR,		(u32)&iObj_set_disabledForeColor,	(u32)&iObj_get_disabledForeColor		},
		{	_INDEX_COMMENT,					(u32)&iObj_set_comment,				(u32)&iObj_get_comment					},
		{	_INDEX_CONTROLSOURCE,			(u32)&iObj_set_controlSource,		(u32)&iObj_get_controlSource			},
		{	_INDEX_DRAGICON,				(u32)&iObj_set_dragIcon,			(u32)&iObj_get_dragIcon					},
		{	_INDEX_DRAGMODE,				(u32)&iObj_set_dragMode,			(u32)&iObj_get_dragMode					},
		{	_INDEX_ENABLED,					(u32)&iObj_set_enabled,				(u32)&iObj_get_enabled					},
		{	_INDEX_FONTBOLD,				(u32)&iObj_set_fontBold,			(u32)&iObj_get_fontBold					},
		{	_INDEX_FONTCHARSET,				(u32)&iObj_set_fontCharSet,			(u32)&iObj_get_fontCharSet				},
		{	_INDEX_FONTCONDENSE,			(u32)&iObj_set_fontCondense,		(u32)&iObj_get_fontCondense				},
		{	_INDEX_FONTEXTEND,				(u32)&iObj_set_fontExtend,			(u32)&iObj_get_fontExtend				},
		{	_INDEX_FONTITALIC,				(u32)&iObj_set_fontItalic,			(u32)&iObj_get_fontItalic				},
		{	_INDEX_FONTNAME,				(u32)&iObj_set_fontName,			(u32)&iObj_get_fontName					},
		{	_INDEX_FONTOUTLINE,				(u32)&iObj_set_fontOutline,			(u32)&iObj_get_fontOutline				},
		{	_INDEX_FONTSHADOW,				(u32)&iObj_set_fontShadow,			(u32)&iObj_get_fontShadow				},
		{	_INDEX_FONTSTRIKETHRU,			(u32)&iObj_set_fontStrikeThru,		(u32)&iObj_get_fontStrikeThru			},
		{	_INDEX_FONTUNDERLINE,			(u32)&iObj_set_fontUnderline,		(u32)&iObj_get_fontUnderline			},
		{	_INDEX_HEIGHT,					(u32)&iObj_set_height,				(u32)&iObj_get_height					},
		{	_INDEX_HELPCONTEXTID,			(u32)&iObj_set_helpContextID,		(u32)&iObj_get_helpContextID			},
		{	_INDEX_LEFT,					(u32)&iObj_set_left,				(u32)&iObj_get_left						},
		{	_INDEX_MOUSEICON,				(u32)&iObj_set_mouseIcon,			(u32)&iObj_get_mouseIcon				},
		{	_INDEX_MOUSEPOINTER,			(u32)&iObj_set_mousePointer,		(u32)&iObj_get_mousePointer				},
		{	_INDEX_NAME,					(u32)&iObj_set_name,				(u32)&iObj_get_name						},
		{	_INDEX_OLEDRAGMODE,				(u32)&iObj_set_oLEDragMode,			(u32)&iObj_get_oLEDragMode				},
		{	_INDEX_OLEDRAGPICTURE,			(u32)&iObj_set_oLEDragPicture,		(u32)&iObj_get_oLEDragPicture			},
		{	_INDEX_OLEDROPEFFECTS,			(u32)&iObj_set_oLEDropEffects,		(u32)&iObj_get_oLEDropEffects			},
		{	_INDEX_OLEDROPHASDATA,			(u32)&iObj_set_oLEDropHasData,		(u32)&iObj_get_oLEDropHasData			},
		{	_INDEX_PARENT,					(u32)&iObj_set_parent,				(u32)&iObj_get_parent					},
		{	_INDEX_PARENTCLASS,				(u32)&iObj_set_parentClass,			(u32)&iObj_get_parentClass				},
		{	_INDEX_PICTURE,					(u32)&iObj_set_picture,				(u32)&iObj_get_picture					},
		{	_INDEX_PICTUREMARGIN,			(u32)&iObj_set_pictureMargin,		(u32)&iObj_get_pictureMargin			},
		{	_INDEX_PICTUREPOSITION,			(u32)&iObj_set_picturePosition,		(u32)&iObj_get_picturePosition			},
		{	_INDEX_PICTURESPACING,			(u32)&iObj_set_pictureSpacing,		(u32)&iObj_get_pictureSpacing			},
		{	_INDEX_DISABLEDPICTURE,			(u32)&iObj_set_disabledPicture,		(u32)&iObj_get_disabledPicture			},
		{	_INDEX_DOWNPICTURE,				(u32)&iObj_set_downPicture,			(u32)&iObj_get_downPicture				},
		{	_INDEX_READONLY,				(u32)&iObj_set_readOnly,			(u32)&iObj_get_readOnly					},
		{	_INDEX_RIGHTTOLEFT,				(u32)&iObj_set_rightToLeft,			(u32)&iObj_get_rightToLeft				},
		{	_INDEX_SPECIALEFFECT,			(u32)&iObj_set_specialEffect,		(u32)&iObj_get_specialEffect			},
		{	_INDEX_STATUSBARTEXT,			(u32)&iObj_set_statusBarText,		(u32)&iObj_get_statusBarText			},
		{	_INDEX_STYLE,					(u32)&iObj_set_style,				(u32)&iObj_get_style					},
		{	_INDEX_TABINDEX,				(u32)&iObj_set_tabIndex,			(u32)&iObj_get_tabIndex					},
		{	_INDEX_TABSTOP,					(u32)&iObj_set_tabStop,				(u32)&iObj_get_tabStop					},
		{	_INDEX_TAG,						(u32)&iObj_set_tag,					(u32)&iObj_get_tag						},
		{	_INDEX_TERMINATEREAD,			(u32)&iObj_set_terminateRead,		(u32)&iObj_get_terminateRead			},
		{	_INDEX_THEMES,					(u32)&iObj_set_themes,				(u32)&iObj_get_themes					},
		{	_INDEX_TOOLTIPTEXT,				(u32)&iObj_set_toolTipText,			(u32)&iObj_get_toolTipText				},
		{	_INDEX_TOP,						(u32)&iObj_set_top,					(u32)&iObj_get_top						},
		{	_INDEX_VALUE,					(u32)&iObj_set_value,				(u32)&iObj_get_value					},
		{	_INDEX_VISIBLE,					(u32)&iObj_set_visible,				(u32)&iObj_get_visible					},
		{	_INDEX_WHATSTHISHELPID,			(u32)&iObj_set_whatsThisHelpID,		(u32)&iObj_get_whatsThisHelpID			},
		{	_INDEX_WIDTH,					(u32)&iObj_set_width,				(u32)&iObj_get_width					},
		{	_INDEX_WORDWRAP,				(u32)&iObj_set_wordWrap,			(u32)&iObj_get_wordWrap					},
		{	0,								0,									0										}
	};

	SPropertyMap gcProps_button[] =
	{
		{	_INDEX_ALIGNMENT,				(u32)&iObj_set_alignment,			(u32)&iObj_get_alignment				},
		{	_INDEX_ANCHOR,					(u32)&iObj_set_anchor,				(u32)&iObj_get_anchor					},
		{	_INDEX_APPLICATION,				(u32)&iObj_set_application,			(u32)&iObj_get_application				},
		{	_INDEX_AUTOSIZE,				(u32)&iObj_set_autoSize,			(u32)&iObj_get_autoSize					},
		{	_INDEX_BASECLASS,				(u32)&iObj_set_baseClass,			(u32)&iObj_get_baseClass				},
		{	_INDEX_CLASS,					(u32)&iObj_set_class,				(u32)&iObj_get_class					},
		{	_INDEX_CLASSLIBRARY,			(u32)&iObj_set_classLibrary,		(u32)&iObj_get_classLibrary				},
		{	_INDEX_CANCEL,					(u32)&iObj_set_cancel,				(u32)&iObj_get_cancel					},
		{	_INDEX_DEFAULT,					(u32)&iObj_set_default,				(u32)&iObj_get_default					},
		{	_INDEX_CAPTION,					(u32)&iObj_set_caption,				(u32)&iObj_get_caption					},
		{	_INDEX_COLORSCHEME,				(u32)&iObj_set_colorScheme,			(u32)&iObj_get_colorScheme				},
		{	_INDEX_COLORSOURCE,				(u32)&iObj_set_colorSource,			(u32)&iObj_get_colorSource				},
		{	_INDEX_FORECOLOR,				(u32)&iObj_set_foreColor,			(u32)&iObj_get_foreColor				},
		{	_INDEX_BACKCOLOR,				(u32)&iObj_set_backColor,			(u32)&iObj_get_backColor				},
		{	_INDEX_DISABLEDBACKCOLOR,		(u32)&iObj_set_disabledBackColor,	(u32)&iObj_get_disabledBackColor		},
		{	_INDEX_DISABLEDFORECOLOR,		(u32)&iObj_set_disabledForeColor,	(u32)&iObj_get_disabledForeColor		},
		{	_INDEX_COMMENT,					(u32)&iObj_set_comment,				(u32)&iObj_get_comment					},
		{	_INDEX_DRAGICON,				(u32)&iObj_set_dragIcon,			(u32)&iObj_get_dragIcon					},
		{	_INDEX_DRAGMODE,				(u32)&iObj_set_dragMode,			(u32)&iObj_get_dragMode					},
		{	_INDEX_ENABLED,					(u32)&iObj_set_enabled,				(u32)&iObj_get_enabled					},
		{	_INDEX_FONTBOLD,				(u32)&iObj_set_fontBold,			(u32)&iObj_get_fontBold					},
		{	_INDEX_FONTCHARSET,				(u32)&iObj_set_fontCharSet,			(u32)&iObj_get_fontCharSet				},
		{	_INDEX_FONTCONDENSE,			(u32)&iObj_set_fontCondense,		(u32)&iObj_get_fontCondense				},
		{	_INDEX_FONTEXTEND,				(u32)&iObj_set_fontExtend,			(u32)&iObj_get_fontExtend				},
		{	_INDEX_FONTITALIC,				(u32)&iObj_set_fontItalic,			(u32)&iObj_get_fontItalic				},
		{	_INDEX_FONTNAME,				(u32)&iObj_set_fontName,			(u32)&iObj_get_fontName					},
		{	_INDEX_FONTOUTLINE,				(u32)&iObj_set_fontOutline,			(u32)&iObj_get_fontOutline				},
		{	_INDEX_FONTSHADOW,				(u32)&iObj_set_fontShadow,			(u32)&iObj_get_fontShadow				},
		{	_INDEX_FONTSIZE,				(u32)&iObj_set_fontSize,			(u32)&iObj_get_fontSize					},
		{	_INDEX_FONTSTRIKETHRU,			(u32)&iObj_set_fontStrikeThru,		(u32)&iObj_get_fontStrikeThru			},
		{	_INDEX_FONTUNDERLINE,			(u32)&iObj_set_fontUnderline,		(u32)&iObj_get_fontUnderline			},
		{	_INDEX_HEIGHT,					(u32)&iObj_set_height,				(u32)&iObj_get_height					},
		{	_INDEX_HELPCONTEXTID,			(u32)&iObj_set_helpContextID,		(u32)&iObj_get_helpContextID			},
		{	_INDEX_LEFT,					(u32)&iObj_set_left,				(u32)&iObj_get_left						},
		{	_INDEX_MOUSEICON,				(u32)&iObj_set_mouseIcon,			(u32)&iObj_get_mouseIcon				},
		{	_INDEX_MOUSEPOINTER,			(u32)&iObj_set_mousePointer,		(u32)&iObj_get_mousePointer				},
		{	_INDEX_NAME,					(u32)&iObj_set_name,				(u32)&iObj_get_name						},
		{	_INDEX_OLEDRAGMODE,				(u32)&iObj_set_oLEDragMode,			(u32)&iObj_get_oLEDragMode				},
		{	_INDEX_OLEDRAGPICTURE,			(u32)&iObj_set_oLEDragPicture,		(u32)&iObj_get_oLEDragPicture			},
		{	_INDEX_OLEDROPEFFECTS,			(u32)&iObj_set_oLEDropEffects,		(u32)&iObj_get_oLEDropEffects			},
		{	_INDEX_OLEDROPHASDATA,			(u32)&iObj_set_oLEDropHasData,		(u32)&iObj_get_oLEDropHasData			},
		{	_INDEX_OLEDROPMODE,				(u32)&iObj_set_oLEDropMode,			(u32)&iObj_get_oLEDropMode				},
		{	_INDEX_PARENT,					(u32)&iObj_set_parent,				(u32)&iObj_get_parent					},
		{	_INDEX_PARENTCLASS,				(u32)&iObj_set_parentClass,			(u32)&iObj_get_parentClass				},
		{	_INDEX_PICTURE,					(u32)&iObj_set_picture,				(u32)&iObj_get_picture					},
		{	_INDEX_PICTUREMARGIN,			(u32)&iObj_set_pictureMargin,		(u32)&iObj_get_pictureMargin			},
		{	_INDEX_PICTUREPOSITION,			(u32)&iObj_set_picturePosition,		(u32)&iObj_get_picturePosition			},
		{	_INDEX_PICTURESPACING,			(u32)&iObj_set_pictureSpacing,		(u32)&iObj_get_pictureSpacing			},
		{	_INDEX_DISABLEDPICTURE,			(u32)&iObj_set_disabledPicture,		(u32)&iObj_get_disabledPicture			},
		{	_INDEX_DOWNPICTURE,				(u32)&iObj_set_downPicture,			(u32)&iObj_get_downPicture				},
		{	_INDEX_RIGHTTOLEFT,				(u32)&iObj_set_rightToLeft,			(u32)&iObj_get_rightToLeft				},
		{	_INDEX_SPECIALEFFECT,			(u32)&iObj_set_specialEffect,		(u32)&iObj_get_specialEffect			},
		{	_INDEX_STATUSBARTEXT,			(u32)&iObj_set_statusBarText,		(u32)&iObj_get_statusBarText			},
		{	_INDEX_STYLE,					(u32)&iObj_set_style,				(u32)&iObj_get_style					},
		{	_INDEX_TABINDEX,				(u32)&iObj_set_tabIndex,			(u32)&iObj_get_tabIndex					},
		{	_INDEX_TABSTOP,					(u32)&iObj_set_tabStop,				(u32)&iObj_get_tabStop					},
		{	_INDEX_TAG,						(u32)&iObj_set_tag,					(u32)&iObj_get_tag						},
		{	_INDEX_TERMINATEREAD,			(u32)&iObj_set_terminateRead,		(u32)&iObj_get_terminateRead			},
		{	_INDEX_THEMES,					(u32)&iObj_set_themes,				(u32)&iObj_get_themes					},
		{	_INDEX_TOOLTIPTEXT,				(u32)&iObj_set_toolTipText,			(u32)&iObj_get_toolTipText				},
		{	_INDEX_TOP,						(u32)&iObj_set_top,					(u32)&iObj_get_top						},
		{	_INDEX_VISIBLE,					(u32)&iObj_set_visible,				(u32)&iObj_get_visible					},
		{	_INDEX_VISUALEFFECT,			(u32)&iObj_set_visualEffect,		(u32)&iObj_get_visualEffect				},
		{	_INDEX_WHATSTHISHELPID,			(u32)&iObj_set_whatsThisHelpID,		(u32)&iObj_get_whatsThisHelpID			},
		{	_INDEX_WIDTH,					(u32)&iObj_set_width,				(u32)&iObj_get_width					},
		{	_INDEX_WORDWRAP,				(u32)&iObj_set_wordWrap,			(u32)&iObj_get_wordWrap					},
		{	0,								0,									0										}
	};

	SPropertyMap gcProps_cmdgroup[] =
	{
		{	_INDEX_ANCHOR,					(u32)&iObj_set_anchor,				(u32)&iObj_get_anchor					},
		{	_INDEX_AUTOSIZE,				(u32)&iObj_set_autoSize,			(u32)&iObj_get_autoSize					},
		{	_INDEX_BACKSTYLE,				(u32)&iObj_set_backStyle,			(u32)&iObj_get_backStyle				},
		{	_INDEX_BUTTONCOUNT,				(u32)&iObj_set_buttonCount,			(u32)&iObj_get_buttonCount				},
		{	_INDEX_BORDERCOLOR,				(u32)&iObj_set_borderColor,			(u32)&iObj_get_borderColor				},
		{	_INDEX_BORDERSTYLE,				(u32)&iObj_set_borderStyle,			(u32)&iObj_get_borderStyle				},
		{	_INDEX_COLORSOURCE,				(u32)&iObj_set_colorSource,			(u32)&iObj_get_colorSource				},
		{	_INDEX_BACKCOLOR,				(u32)&iObj_set_backColor,			(u32)&iObj_get_backColor				},
		{	_INDEX_COMMENT,					(u32)&iObj_set_comment,				(u32)&iObj_get_comment					},
		{	_INDEX_CONTROLSOURCE,			(u32)&iObj_set_controlSource,		(u32)&iObj_get_controlSource			},
		{	_INDEX_DRAGICON,				(u32)&iObj_set_dragIcon,			(u32)&iObj_get_dragIcon					},
		{	_INDEX_DRAGMODE,				(u32)&iObj_set_dragMode,			(u32)&iObj_get_dragMode					},
		{	_INDEX_ENABLED,					(u32)&iObj_set_enabled,				(u32)&iObj_get_enabled					},
		{	_INDEX_HEIGHT,					(u32)&iObj_set_height,				(u32)&iObj_get_height					},
		{	_INDEX_HELPCONTEXTID,			(u32)&iObj_set_helpContextID,		(u32)&iObj_get_helpContextID			},
		{	_INDEX_LEFT,					(u32)&iObj_set_left,				(u32)&iObj_get_left						},
		{	_INDEX_MEMBERCLASS,				(u32)&iObj_set_memberClass,			(u32)&iObj_get_memberClass				},
		{	_INDEX_MEMBERCLASSLIBRARY,		(u32)&iObj_set_memberClassLibrary,	(u32)&iObj_get_memberClassLibrary		},
		{	_INDEX_MOUSEICON,				(u32)&iObj_set_mouseIcon,			(u32)&iObj_get_mouseIcon				},
		{	_INDEX_MOUSEPOINTER,			(u32)&iObj_set_mousePointer,		(u32)&iObj_get_mousePointer				},
		{	_INDEX_NAME,					(u32)&iObj_set_name,				(u32)&iObj_get_name						},
		{	_INDEX_OLEDRAGMODE,				(u32)&iObj_set_oLEDragMode,			(u32)&iObj_get_oLEDragMode				},
		{	_INDEX_OLEDRAGPICTURE,			(u32)&iObj_set_oLEDragPicture,		(u32)&iObj_get_oLEDragPicture			},
		{	_INDEX_OLEDROPEFFECTS,			(u32)&iObj_set_oLEDropEffects,		(u32)&iObj_get_oLEDropEffects			},
		{	_INDEX_OLEDROPMODE,				(u32)&iObj_set_oLEDropMode,			(u32)&iObj_get_oLEDropMode				},
		{	_INDEX_SPECIALEFFECT,			(u32)&iObj_set_specialEffect,		(u32)&iObj_get_specialEffect			},
		{	_INDEX_STATUSBARTEXT,			(u32)&iObj_set_statusBarText,		(u32)&iObj_get_statusBarText			},
		{	_INDEX_TAG,						(u32)&iObj_set_tag,					(u32)&iObj_get_tag						},
		{	_INDEX_TERMINATEREAD,			(u32)&iObj_set_terminateRead,		(u32)&iObj_get_terminateRead			},
		{	_INDEX_THEMES,					(u32)&iObj_set_themes,				(u32)&iObj_get_themes					},
		{	_INDEX_TOOLTIPTEXT,				(u32)&iObj_set_toolTipText,			(u32)&iObj_get_toolTipText				},
		{	_INDEX_TOP,						(u32)&iObj_set_top,					(u32)&iObj_get_top						},
		{	_INDEX_VALUE,					(u32)&iObj_set_value,				(u32)&iObj_get_value					},
		{	_INDEX_VISIBLE,					(u32)&iObj_set_visible,				(u32)&iObj_get_visible					},
		{	_INDEX_WHATSTHISHELPID,			(u32)&iObj_set_whatsThisHelpID,		(u32)&iObj_get_whatsThisHelpID			},
		{	_INDEX_WIDTH,					(u32)&iObj_set_width,				(u32)&iObj_get_width					},
		{	0,								0,									0										}
	};

	SPropertyMap gcProps_label[] =
	{
		{	_INDEX_ALIGNMENT,				(u32)&iObj_set_alignment,			(u32)&iObj_get_alignment				},
		{	_INDEX_ANCHOR,					(u32)&iObj_set_anchor,				(u32)&iObj_get_anchor					},
		{	_INDEX_APPLICATION,				(u32)&iObj_set_application,			(u32)&iObj_get_application				},
		{	_INDEX_AUTOSIZE,				(u32)&iObj_set_autoSize,			(u32)&iObj_get_autoSize					},
		{	_INDEX_BACKSTYLE,				(u32)&iObj_set_backStyle,			(u32)&iObj_get_backStyle				},
		{	_INDEX_BASECLASS,				(u32)&iObj_set_baseClass,			(u32)&iObj_get_baseClass				},
		{	_INDEX_CLASS,					(u32)&iObj_set_class,				(u32)&iObj_get_class					},
		{	_INDEX_CLASSLIBRARY,			(u32)&iObj_set_classLibrary,		(u32)&iObj_get_classLibrary				},
		{	_INDEX_BORDERSTYLE,				(u32)&iObj_set_borderStyle,			(u32)&iObj_get_borderStyle				},
		{	_INDEX_CAPTION,					(u32)&iObj_set_caption,				(u32)&iObj_get_caption					},
		{	_INDEX_COLORSCHEME,				(u32)&iObj_set_colorScheme,			(u32)&iObj_get_colorScheme				},
		{	_INDEX_COLORSOURCE,				(u32)&iObj_set_colorSource,			(u32)&iObj_get_colorSource				},
		{	_INDEX_FORECOLOR,				(u32)&iObj_set_foreColor,			(u32)&iObj_get_foreColor				},
		{	_INDEX_BACKCOLOR,				(u32)&iObj_set_backColor,			(u32)&iObj_get_backColor				},
		{	_INDEX_DISABLEDBACKCOLOR,		(u32)&iObj_set_disabledBackColor,	(u32)&iObj_get_disabledBackColor		},
		{	_INDEX_DISABLEDFORECOLOR,		(u32)&iObj_set_disabledForeColor,	(u32)&iObj_get_disabledForeColor		},
		{	_INDEX_COMMENT,					(u32)&iObj_set_comment,				(u32)&iObj_get_comment					},
		{	_INDEX_DRAGICON,				(u32)&iObj_set_dragIcon,			(u32)&iObj_get_dragIcon					},
		{	_INDEX_DRAGMODE,				(u32)&iObj_set_dragMode,			(u32)&iObj_get_dragMode					},
		{	_INDEX_ENABLED,					(u32)&iObj_set_enabled,				(u32)&iObj_get_enabled					},
		{	_INDEX_FONTBOLD,				(u32)&iObj_set_fontBold,			(u32)&iObj_get_fontBold					},
		{	_INDEX_FONTCHARSET,				(u32)&iObj_set_fontCharSet,			(u32)&iObj_get_fontCharSet				},
		{	_INDEX_FONTCONDENSE,			(u32)&iObj_set_fontCondense,		(u32)&iObj_get_fontCondense				},
		{	_INDEX_FONTEXTEND,				(u32)&iObj_set_fontExtend,			(u32)&iObj_get_fontExtend				},
		{	_INDEX_FONTITALIC,				(u32)&iObj_set_fontItalic,			(u32)&iObj_get_fontItalic				},
		{	_INDEX_FONTNAME,				(u32)&iObj_set_fontName,			(u32)&iObj_get_fontName					},
		{	_INDEX_FONTOUTLINE,				(u32)&iObj_set_fontOutline,			(u32)&iObj_get_fontOutline				},
		{	_INDEX_FONTSHADOW,				(u32)&iObj_set_fontShadow,			(u32)&iObj_get_fontShadow				},
		{	_INDEX_FONTSIZE,				(u32)&iObj_set_fontSize,			(u32)&iObj_get_fontSize					},
		{	_INDEX_FONTSTRIKETHRU,			(u32)&iObj_set_fontStrikeThru,		(u32)&iObj_get_fontStrikeThru			},
		{	_INDEX_FONTUNDERLINE,			(u32)&iObj_set_fontUnderline,		(u32)&iObj_get_fontUnderline			},
		{	_INDEX_HEIGHT,					(u32)&iObj_set_height,				(u32)&iObj_get_height					},
		{	_INDEX_HELPCONTEXTID,			(u32)&iObj_set_helpContextID,		(u32)&iObj_get_helpContextID			},
		{	_INDEX_LEFT,					(u32)&iObj_set_left,				(u32)&iObj_get_left						},
		{	_INDEX_MOUSEICON,				(u32)&iObj_set_mouseIcon,			(u32)&iObj_get_mouseIcon				},
		{	_INDEX_MOUSEPOINTER,			(u32)&iObj_set_mousePointer,		(u32)&iObj_get_mousePointer				},
		{	_INDEX_NAME,					(u32)&iObj_set_name,				(u32)&iObj_get_name						},
		{	_INDEX_OLEDRAGMODE,				(u32)&iObj_set_oLEDragMode,			(u32)&iObj_get_oLEDragMode				},
		{	_INDEX_OLEDRAGPICTURE,			(u32)&iObj_set_oLEDragPicture,		(u32)&iObj_get_oLEDragPicture			},
		{	_INDEX_OLEDROPEFFECTS,			(u32)&iObj_set_oLEDropEffects,		(u32)&iObj_get_oLEDropEffects			},
		{	_INDEX_OLEDROPHASDATA,			(u32)&iObj_set_oLEDropHasData,		(u32)&iObj_get_oLEDropHasData			},
		{	_INDEX_OLEDROPMODE,				(u32)&iObj_set_oLEDropMode,			(u32)&iObj_get_oLEDropMode				},
		{	_INDEX_PARENT,					(u32)&iObj_set_parent,				(u32)&iObj_get_parent					},
		{	_INDEX_PARENTCLASS,				(u32)&iObj_set_parentClass,			(u32)&iObj_get_parentClass				},
		{	_INDEX_RIGHTTOLEFT,				(u32)&iObj_set_rightToLeft,			(u32)&iObj_get_rightToLeft				},
		{	_INDEX_ROTATION,				(u32)&iObj_set_rotation,			(u32)&iObj_get_rotation					},
		{	_INDEX_STATUSBARTEXT,			(u32)&iObj_set_statusBarText,		(u32)&iObj_get_statusBarText			},
		{	_INDEX_STYLE,					(u32)&iObj_set_style,				(u32)&iObj_get_style					},
		{	_INDEX_TABINDEX,				(u32)&iObj_set_tabIndex,			(u32)&iObj_get_tabIndex					},
		{	_INDEX_TAG,						(u32)&iObj_set_tag,					(u32)&iObj_get_tag						},
		{	_INDEX_TOOLTIPTEXT,				(u32)&iObj_set_toolTipText,			(u32)&iObj_get_toolTipText				},
		{	_INDEX_TOP,						(u32)&iObj_set_top,					(u32)&iObj_get_top						},
		{	_INDEX_VISIBLE,					(u32)&iObj_set_visible,				(u32)&iObj_get_visible					},
		{	_INDEX_WHATSTHISHELPID,			(u32)&iObj_set_whatsThisHelpID,		(u32)&iObj_get_whatsThisHelpID			},
		{	_INDEX_WIDTH,					(u32)&iObj_set_width,				(u32)&iObj_get_width					},
		{	_INDEX_WORDWRAP,				(u32)&iObj_set_wordWrap,			(u32)&iObj_get_wordWrap					},
		{	0,								0,									0										}
	};

	SPropertyMap gcProps_option[] =
	{
		{	_INDEX_ALIGNMENT,				(u32)&iObj_set_alignment,			(u32)&iObj_get_alignment				},
		{	_INDEX_ANCHOR,					(u32)&iObj_set_anchor,				(u32)&iObj_get_anchor					},
		{	_INDEX_AUTOSIZE,				(u32)&iObj_set_autoSize,			(u32)&iObj_get_autoSize					},
		{	_INDEX_BACKSTYLE,				(u32)&iObj_set_backStyle,			(u32)&iObj_get_backStyle				},
		{	_INDEX_CAPTION,					(u32)&iObj_set_caption,				(u32)&iObj_get_caption					},
		{	_INDEX_COLORSCHEME,				(u32)&iObj_set_colorScheme,			(u32)&iObj_get_colorScheme				},
		{	_INDEX_COLORSOURCE,				(u32)&iObj_set_colorSource,			(u32)&iObj_get_colorSource				},
		{	_INDEX_FORECOLOR,				(u32)&iObj_set_foreColor,			(u32)&iObj_get_foreColor				},
		{	_INDEX_BACKCOLOR,				(u32)&iObj_set_backColor,			(u32)&iObj_get_backColor				},
		{	_INDEX_DISABLEDBACKCOLOR,		(u32)&iObj_set_disabledBackColor,	(u32)&iObj_get_disabledBackColor		},
		{	_INDEX_DISABLEDFORECOLOR,		(u32)&iObj_set_disabledForeColor,	(u32)&iObj_get_disabledForeColor		},
		{	_INDEX_COMMENT,					(u32)&iObj_set_comment,				(u32)&iObj_get_comment					},
		{	_INDEX_CONTROLSOURCE,			(u32)&iObj_set_controlSource,		(u32)&iObj_get_controlSource			},
		{	_INDEX_DRAGICON,				(u32)&iObj_set_dragIcon,			(u32)&iObj_get_dragIcon					},
		{	_INDEX_DRAGMODE,				(u32)&iObj_set_dragMode,			(u32)&iObj_get_dragMode					},
		{	_INDEX_ENABLED,					(u32)&iObj_set_enabled,				(u32)&iObj_get_enabled					},
		{	_INDEX_FONTBOLD,				(u32)&iObj_set_fontBold,			(u32)&iObj_get_fontBold					},
		{	_INDEX_FONTCHARSET,				(u32)&iObj_set_fontCharSet,			(u32)&iObj_get_fontCharSet				},
		{	_INDEX_FONTCONDENSE,			(u32)&iObj_set_fontCondense,		(u32)&iObj_get_fontCondense				},
		{	_INDEX_FONTEXTEND,				(u32)&iObj_set_fontExtend,			(u32)&iObj_get_fontExtend				},
		{	_INDEX_FONTITALIC,				(u32)&iObj_set_fontItalic,			(u32)&iObj_get_fontItalic				},
		{	_INDEX_FONTNAME,				(u32)&iObj_set_fontName,			(u32)&iObj_get_fontName					},
		{	_INDEX_FONTOUTLINE,				(u32)&iObj_set_fontOutline,			(u32)&iObj_get_fontOutline				},
		{	_INDEX_FONTSHADOW,				(u32)&iObj_set_fontShadow,			(u32)&iObj_get_fontShadow				},
		{	_INDEX_FONTSIZE,				(u32)&iObj_set_fontSize,			(u32)&iObj_get_fontSize					},
		{	_INDEX_FONTSTRIKETHRU,			(u32)&iObj_set_fontStrikeThru,		(u32)&iObj_get_fontStrikeThru			},
		{	_INDEX_FONTUNDERLINE,			(u32)&iObj_set_fontUnderline,		(u32)&iObj_get_fontUnderline			},
		{	_INDEX_HEIGHT,					(u32)&iObj_set_height,				(u32)&iObj_get_height					},
		{	_INDEX_HELPCONTEXTID,			(u32)&iObj_set_helpContextID,		(u32)&iObj_get_helpContextID			},
		{	_INDEX_LEFT,					(u32)&iObj_set_left,				(u32)&iObj_get_left						},
		{	_INDEX_MOUSEICON,				(u32)&iObj_set_mouseIcon,			(u32)&iObj_get_mouseIcon				},
		{	_INDEX_MOUSEPOINTER,			(u32)&iObj_set_mousePointer,		(u32)&iObj_get_mousePointer				},
		{	_INDEX_NAME,					(u32)&iObj_set_name,				(u32)&iObj_get_name						},
		{	_INDEX_OLEDRAGMODE,				(u32)&iObj_set_oLEDragMode,			(u32)&iObj_get_oLEDragMode				},
		{	_INDEX_OLEDRAGPICTURE,			(u32)&iObj_set_oLEDragPicture,		(u32)&iObj_get_oLEDragPicture			},
		{	_INDEX_OLEDROPEFFECTS,			(u32)&iObj_set_oLEDropEffects,		(u32)&iObj_get_oLEDropEffects			},
		{	_INDEX_OLEDROPMODE,				(u32)&iObj_set_oLEDropMode,			(u32)&iObj_get_oLEDropMode				},
		{	_INDEX_PICTURE,					(u32)&iObj_set_picture,				(u32)&iObj_get_picture					},
		{	_INDEX_PICTUREMARGIN,			(u32)&iObj_set_pictureMargin,		(u32)&iObj_get_pictureMargin			},
		{	_INDEX_PICTUREPOSITION,			(u32)&iObj_set_picturePosition,		(u32)&iObj_get_picturePosition			},
		{	_INDEX_PICTURESPACING,			(u32)&iObj_set_pictureSpacing,		(u32)&iObj_get_pictureSpacing			},
		{	_INDEX_DISABLEDPICTURE,			(u32)&iObj_set_disabledPicture,		(u32)&iObj_get_disabledPicture			},
		{	_INDEX_DOWNPICTURE,				(u32)&iObj_set_downPicture,			(u32)&iObj_get_downPicture				},
		{	_INDEX_RIGHTTOLEFT,				(u32)&iObj_set_rightToLeft,			(u32)&iObj_get_rightToLeft				},
		{	_INDEX_SPECIALEFFECT,			(u32)&iObj_set_specialEffect,		(u32)&iObj_get_specialEffect			},
		{	_INDEX_STATUSBARTEXT,			(u32)&iObj_set_statusBarText,		(u32)&iObj_get_statusBarText			},
		{	_INDEX_STYLE,					(u32)&iObj_set_style,				(u32)&iObj_get_style					},
		{	_INDEX_TABINDEX,				(u32)&iObj_set_tabIndex,			(u32)&iObj_get_tabIndex					},
		{	_INDEX_TABSTOP,					(u32)&iObj_set_tabStop,				(u32)&iObj_get_tabStop					},
		{	_INDEX_TAG,						(u32)&iObj_set_tag,					(u32)&iObj_get_tag						},
		{	_INDEX_TERMINATEREAD,			(u32)&iObj_set_terminateRead,		(u32)&iObj_get_terminateRead			},
		{	_INDEX_THEMES,					(u32)&iObj_set_themes,				(u32)&iObj_get_themes					},
		{	_INDEX_TOOLTIPTEXT,				(u32)&iObj_set_toolTipText,			(u32)&iObj_get_toolTipText				},
		{	_INDEX_TOP,						(u32)&iObj_set_top,					(u32)&iObj_get_top						},
		{	_INDEX_VALUE,					(u32)&iObj_set_value,				(u32)&iObj_get_value					},
		{	_INDEX_VISIBLE,					(u32)&iObj_set_visible,				(u32)&iObj_get_visible					},
		{	_INDEX_WHATSTHISHELPID,			(u32)&iObj_set_whatsThisHelpID,		(u32)&iObj_get_whatsThisHelpID			},
		{	_INDEX_WIDTH,					(u32)&iObj_set_width,				(u32)&iObj_get_width					},
		{	_INDEX_WORDWRAP,				(u32)&iObj_set_wordWrap,			(u32)&iObj_get_wordWrap					},
		{	0,								0,									0										}
	};

	SPropertyMap gcProps_optgroup[] =
	{
		{	_INDEX_ANCHOR,					(u32)&iObj_set_anchor,				(u32)&iObj_get_anchor					},
		{	_INDEX_AUTOSIZE,				(u32)&iObj_set_autoSize,			(u32)&iObj_get_autoSize					},
		{	_INDEX_BACKSTYLE,				(u32)&iObj_set_backStyle,			(u32)&iObj_get_backStyle				},
		{	_INDEX_BUTTONCOUNT,				(u32)&iObj_set_buttonCount,			(u32)&iObj_get_buttonCount				},
		{	_INDEX_BORDERCOLOR,				(u32)&iObj_set_borderColor,			(u32)&iObj_get_borderColor				},
		{	_INDEX_BORDERSTYLE,				(u32)&iObj_set_borderStyle,			(u32)&iObj_get_borderStyle				},
		{	_INDEX_COLORSOURCE,				(u32)&iObj_set_colorSource,			(u32)&iObj_get_colorSource				},
		{	_INDEX_BACKCOLOR,				(u32)&iObj_set_backColor,			(u32)&iObj_get_backColor				},
		{	_INDEX_COMMENT,					(u32)&iObj_set_comment,				(u32)&iObj_get_comment					},
		{	_INDEX_CONTROLSOURCE,			(u32)&iObj_set_controlSource,		(u32)&iObj_get_controlSource			},
		{	_INDEX_DRAGICON,				(u32)&iObj_set_dragIcon,			(u32)&iObj_get_dragIcon					},
		{	_INDEX_DRAGMODE,				(u32)&iObj_set_dragMode,			(u32)&iObj_get_dragMode					},
		{	_INDEX_ENABLED,					(u32)&iObj_set_enabled,				(u32)&iObj_get_enabled					},
		{	_INDEX_HEIGHT,					(u32)&iObj_set_height,				(u32)&iObj_get_height					},
		{	_INDEX_HELPCONTEXTID,			(u32)&iObj_set_helpContextID,		(u32)&iObj_get_helpContextID			},
		{	_INDEX_LEFT,					(u32)&iObj_set_left,				(u32)&iObj_get_left						},
		{	_INDEX_MEMBERCLASS,				(u32)&iObj_set_memberClass,			(u32)&iObj_get_memberClass				},
		{	_INDEX_MEMBERCLASSLIBRARY,		(u32)&iObj_set_memberClassLibrary,	(u32)&iObj_get_memberClassLibrary		},
		{	_INDEX_MOUSEICON,				(u32)&iObj_set_mouseIcon,			(u32)&iObj_get_mouseIcon				},
		{	_INDEX_MOUSEPOINTER,			(u32)&iObj_set_mousePointer,		(u32)&iObj_get_mousePointer				},
		{	_INDEX_NAME,					(u32)&iObj_set_name,				(u32)&iObj_get_name						},
		{	_INDEX_OLEDRAGMODE,				(u32)&iObj_set_oLEDragMode,			(u32)&iObj_get_oLEDragMode				},
		{	_INDEX_OLEDRAGPICTURE,			(u32)&iObj_set_oLEDragPicture,		(u32)&iObj_get_oLEDragPicture			},
		{	_INDEX_OLEDROPEFFECTS,			(u32)&iObj_set_oLEDropEffects,		(u32)&iObj_get_oLEDropEffects			},
		{	_INDEX_OLEDROPMODE,				(u32)&iObj_set_oLEDropMode,			(u32)&iObj_get_oLEDropMode				},
		{	_INDEX_SPECIALEFFECT,			(u32)&iObj_set_specialEffect,		(u32)&iObj_get_specialEffect			},
		{	_INDEX_STATUSBARTEXT,			(u32)&iObj_set_statusBarText,		(u32)&iObj_get_statusBarText			},
		{	_INDEX_TABINDEX,				(u32)&iObj_set_tabIndex,			(u32)&iObj_get_tabIndex					},
		{	_INDEX_TAG,						(u32)&iObj_set_tag,					(u32)&iObj_get_tag						},
		{	_INDEX_TERMINATEREAD,			(u32)&iObj_set_terminateRead,		(u32)&iObj_get_terminateRead			},
		{	_INDEX_THEMES,					(u32)&iObj_set_themes,				(u32)&iObj_get_themes					},
		{	_INDEX_TOOLTIPTEXT,				(u32)&iObj_set_toolTipText,			(u32)&iObj_get_toolTipText				},
		{	_INDEX_TOP,						(u32)&iObj_set_top,					(u32)&iObj_get_top						},
		{	_INDEX_VALUE,					(u32)&iObj_set_value,				(u32)&iObj_get_value					},
		{	_INDEX_VISIBLE,					(u32)&iObj_set_visible,				(u32)&iObj_get_visible					},
		{	_INDEX_WHATSTHISHELPID,			(u32)&iObj_set_whatsThisHelpID,		(u32)&iObj_get_whatsThisHelpID			},
		{	_INDEX_WIDTH,					(u32)&iObj_set_width,				(u32)&iObj_get_width					},
		{	0,								0,									0										}
	};

	SPropertyMap gcProps_textbox[] =
	{
		{	_INDEX_ALIGNMENT,				(u32)&iObj_set_alignment,			(u32)&iObj_get_alignment				},
		{	_INDEX_ANCHOR,					(u32)&iObj_set_anchor,				(u32)&iObj_get_anchor					},
		{	_INDEX_APPLICATION,				(u32)&iObj_set_application,			(u32)&iObj_get_application				},
		{	_INDEX_AUTOCOMPLETE,			(u32)&iObj_set_autoComplete,		(u32)&iObj_get_autoComplete				},
		{	_INDEX_AUTOCOMPTABLE,			(u32)&iObj_set_autoCompTable,		(u32)&iObj_get_autoCompTable			},
		{	_INDEX_AUTOCOMPSOURCE,			(u32)&iObj_set_autoCompSource,		(u32)&iObj_get_autoCompSource			},
		{	_INDEX_BACKSTYLE,				(u32)&iObj_set_backStyle,			(u32)&iObj_get_backStyle				},
		{	_INDEX_BASECLASS,				(u32)&iObj_set_baseClass,			(u32)&iObj_get_baseClass				},
		{	_INDEX_CLASS,					(u32)&iObj_set_class,				(u32)&iObj_get_class					},
		{	_INDEX_CLASSLIBRARY,			(u32)&iObj_set_classLibrary,		(u32)&iObj_get_classLibrary				},
		{	_INDEX_BORDERCOLOR,				(u32)&iObj_set_borderColor,			(u32)&iObj_get_borderColor				},
		{	_INDEX_BORDERSTYLE,				(u32)&iObj_set_borderStyle,			(u32)&iObj_get_borderStyle				},
		{	_INDEX_CENTURY,					(u32)&iObj_set_century,				(u32)&iObj_get_century					},
		{	_INDEX_COLORSCHEME,				(u32)&iObj_set_colorScheme,			(u32)&iObj_get_colorScheme				},
		{	_INDEX_COLORSOURCE,				(u32)&iObj_set_colorSource,			(u32)&iObj_get_colorSource				},
		{	_INDEX_FORECOLOR,				(u32)&iObj_set_foreColor,			(u32)&iObj_get_foreColor				},
		{	_INDEX_BACKCOLOR,				(u32)&iObj_set_backColor,			(u32)&iObj_get_backColor				},
		{	_INDEX_DISABLEDBACKCOLOR,		(u32)&iObj_set_disabledBackColor,	(u32)&iObj_get_disabledBackColor		},
		{	_INDEX_DISABLEDFORECOLOR,		(u32)&iObj_set_disabledForeColor,	(u32)&iObj_get_disabledForeColor		},
		{	_INDEX_COMMENT,					(u32)&iObj_set_comment,				(u32)&iObj_get_comment					},
		{	_INDEX_CONTROLSOURCE,			(u32)&iObj_set_controlSource,		(u32)&iObj_get_controlSource			},
		{	_INDEX_DATEFORMAT,				(u32)&iObj_set_dateFormat,			(u32)&iObj_get_dateFormat				},
		{	_INDEX_DATEMARK,				(u32)&iObj_set_dateMark,			(u32)&iObj_get_dateMark					},
		{	_INDEX_DRAGICON,				(u32)&iObj_set_dragIcon,			(u32)&iObj_get_dragIcon					},
		{	_INDEX_DRAGMODE,				(u32)&iObj_set_dragMode,			(u32)&iObj_get_dragMode					},
		{	_INDEX_ENABLED,					(u32)&iObj_set_enabled,				(u32)&iObj_get_enabled					},
		{	_INDEX_ENABLEHYPERLINKS,		(u32)&iObj_set_enableHyperlinks,	(u32)&iObj_get_enableHyperlinks			},
		{	_INDEX_FONTBOLD,				(u32)&iObj_set_fontBold,			(u32)&iObj_get_fontBold					},
		{	_INDEX_FONTCHARSET,				(u32)&iObj_set_fontCharSet,			(u32)&iObj_get_fontCharSet				},
		{	_INDEX_FONTCONDENSE,			(u32)&iObj_set_fontCondense,		(u32)&iObj_get_fontCondense				},
		{	_INDEX_FONTEXTEND,				(u32)&iObj_set_fontExtend,			(u32)&iObj_get_fontExtend				},
		{	_INDEX_FONTITALIC,				(u32)&iObj_set_fontItalic,			(u32)&iObj_get_fontItalic				},
		{	_INDEX_FONTNAME,				(u32)&iObj_set_fontName,			(u32)&iObj_get_fontName					},
		{	_INDEX_FONTOUTLINE,				(u32)&iObj_set_fontOutline,			(u32)&iObj_get_fontOutline				},
		{	_INDEX_FONTSHADOW,				(u32)&iObj_set_fontShadow,			(u32)&iObj_get_fontShadow				},
		{	_INDEX_FONTSIZE,				(u32)&iObj_set_fontSize,			(u32)&iObj_get_fontSize					},
		{	_INDEX_FONTSTRIKETHRU,			(u32)&iObj_set_fontStrikeThru,		(u32)&iObj_get_fontStrikeThru			},
		{	_INDEX_FONTUNDERLINE,			(u32)&iObj_set_fontUnderline,		(u32)&iObj_get_fontUnderline			},
		{	_INDEX_FORMAT,					(u32)&iObj_set_format,				(u32)&iObj_get_format					},
		{	_INDEX_HEIGHT,					(u32)&iObj_set_height,				(u32)&iObj_get_height					},
		{	_INDEX_HELPCONTEXTID,			(u32)&iObj_set_helpContextID,		(u32)&iObj_get_helpContextID			},
		{	_INDEX_HIDESELECTION,			(u32)&iObj_set_hideSelection,		(u32)&iObj_get_hideSelection			},
		{	_INDEX_HOURS,					(u32)&iObj_set_hours,				(u32)&iObj_get_hours					},
		{	_INDEX_IMEMODE,					(u32)&iObj_set_iMEMode,				(u32)&iObj_get_iMEMode					},
		{	_INDEX_INPUTMASK,				(u32)&iObj_set_inputMask,			(u32)&iObj_get_inputMask				},
		{	_INDEX_INTEGRALHEIGHT,			(u32)&iObj_set_integralHeight,		(u32)&iObj_get_integralHeight			},
		{	_INDEX_LEFT,					(u32)&iObj_set_left,				(u32)&iObj_get_left						},
		{	_INDEX_MARGIN,					(u32)&iObj_set_margin,				(u32)&iObj_get_margin					},
		{	_INDEX_MAXLENGTH,				(u32)&iObj_set_maxLength,			(u32)&iObj_get_maxLength				},
		{	_INDEX_MOUSEICON,				(u32)&iObj_set_mouseIcon,			(u32)&iObj_get_mouseIcon				},
		{	_INDEX_MOUSEPOINTER,			(u32)&iObj_set_mousePointer,		(u32)&iObj_get_mousePointer				},
		{	_INDEX_MEMOWINDOW,				(u32)&iObj_set_memoWindow,			(u32)&iObj_get_memoWindow				},
		{	_INDEX_NAME,					(u32)&iObj_set_name,				(u32)&iObj_get_name						},
		{	_INDEX_NULLDISPLAY,				(u32)&iObj_set_nullDisplay,			(u32)&iObj_get_nullDisplay				},
		{	_INDEX_OLEDRAGMODE,				(u32)&iObj_set_oLEDragMode,			(u32)&iObj_get_oLEDragMode				},
		{	_INDEX_OLEDRAGPICTURE,			(u32)&iObj_set_oLEDragPicture,		(u32)&iObj_get_oLEDragPicture			},
		{	_INDEX_OLEDROPEFFECTS,			(u32)&iObj_set_oLEDropEffects,		(u32)&iObj_get_oLEDropEffects			},
		{	_INDEX_OLEDROPHASDATA,			(u32)&iObj_set_oLEDropHasData,		(u32)&iObj_get_oLEDropHasData			},
		{	_INDEX_OLEDROPMODE,				(u32)&iObj_set_oLEDropMode,			(u32)&iObj_get_oLEDropMode				},
		{	_INDEX_OLEDROPTEXTINSERTION,	(u32)&iObj_set_oLEDropTextInsertion,(u32)&iObj_get_oLEDropTextInsertion		},
		{	_INDEX_OPENWINDOW,				(u32)&iObj_set_openWindow,			(u32)&iObj_get_openWindow				},
		{	_INDEX_PARENT,					(u32)&iObj_set_parent,				(u32)&iObj_get_parent					},
		{	_INDEX_PARENTCLASS,				(u32)&iObj_set_parentClass,			(u32)&iObj_get_parentClass				},
		{	_INDEX_PASSWORDCHAR,			(u32)&iObj_set_passwordChar,		(u32)&iObj_get_passwordChar				},
		{	_INDEX_READONLY,				(u32)&iObj_set_readOnly,			(u32)&iObj_get_readOnly					},
		{	_INDEX_RIGHTTOLEFT,				(u32)&iObj_set_rightToLeft,			(u32)&iObj_get_rightToLeft				},
		{	_INDEX_SECONDS,					(u32)&iObj_set_seconds,				(u32)&iObj_get_seconds					},
		{	_INDEX_SELECTEDBACKCOLOR,		(u32)&iObj_set_selectedBackColor,	(u32)&iObj_get_selectedBackColor		},
		{	_INDEX_SELECTEDFORECOLOR,		(u32)&iObj_set_selectedForeColor,	(u32)&iObj_get_selectedForeColor		},
		{	_INDEX_SELECTONENTRY,			(u32)&iObj_set_selectOnEntry,		(u32)&iObj_get_selectOnEntry			},
		{	_INDEX_SELLENGTH,				(u32)&iObj_set_selLength,			(u32)&iObj_get_selLength				},
		{	_INDEX_SELSTART,				(u32)&iObj_set_selStart,			(u32)&iObj_get_selStart					},
		{	_INDEX_SELTEXT,					(u32)&iObj_set_selText,				(u32)&iObj_get_selText					},
		{	_INDEX_SPECIALEFFECT,			(u32)&iObj_set_specialEffect,		(u32)&iObj_get_specialEffect			},
		{	_INDEX_STATUSBARTEXT,			(u32)&iObj_set_statusBarText,		(u32)&iObj_get_statusBarText			},
		{	_INDEX_STRICTDATEENTRY,			(u32)&iObj_set_strictDateEntry,		(u32)&iObj_get_strictDateEntry			},
		{	_INDEX_STYLE,					(u32)&iObj_set_style,				(u32)&iObj_get_style					},
		{	_INDEX_TABINDEX,				(u32)&iObj_set_tabIndex,			(u32)&iObj_get_tabIndex					},
		{	_INDEX_TABSTOP,					(u32)&iObj_set_tabStop,				(u32)&iObj_get_tabStop					},
		{	_INDEX_TAG,						(u32)&iObj_set_tag,					(u32)&iObj_get_tag						},
		{	_INDEX_TERMINATEREAD,			(u32)&iObj_set_terminateRead,		(u32)&iObj_get_terminateRead			},
		{	_INDEX_TEXT,					(u32)&iObj_set_text,				(u32)&iObj_get_text						},
		{	_INDEX_THEMES,					(u32)&iObj_set_themes,				(u32)&iObj_get_themes					},
		{	_INDEX_TOOLTIPTEXT,				(u32)&iObj_set_toolTipText,			(u32)&iObj_get_toolTipText				},
		{	_INDEX_TOP,						(u32)&iObj_set_top,					(u32)&iObj_get_top						},
		{	_INDEX_VALUE,					(u32)&iObj_set_value,				(u32)&iObj_get_value					},
		{	_INDEX_VISIBLE,					(u32)&iObj_set_visible,				(u32)&iObj_get_visible					},
		{	_INDEX_WHATSTHISHELPID,			(u32)&iObj_set_whatsThisHelpID,		(u32)&iObj_get_whatsThisHelpID			},
		{	_INDEX_WIDTH,					(u32)&iObj_set_width,				(u32)&iObj_get_width					},
		{	0,								0,									0										}
	};

	SPropertyMap gcProps_editbox[] =
	{
		{	_INDEX_ADDLINEFEEDS,			(u32)&iObj_set_addLineFeeds,		(u32)&iObj_get_addLineFeeds				},
		{	_INDEX_ALIGNMENT,				(u32)&iObj_set_alignment,			(u32)&iObj_get_alignment				},
		{	_INDEX_ALLOWTABS,				(u32)&iObj_set_allowTabs,			(u32)&iObj_get_allowTabs				},
		{	_INDEX_ANCHOR,					(u32)&iObj_set_anchor,				(u32)&iObj_get_anchor					},
		{	_INDEX_APPLICATION,				(u32)&iObj_set_application,			(u32)&iObj_get_application				},
		{	_INDEX_BACKSTYLE,				(u32)&iObj_set_backStyle,			(u32)&iObj_get_backStyle				},
		{	_INDEX_BASECLASS,				(u32)&iObj_set_baseClass,			(u32)&iObj_get_baseClass				},
		{	_INDEX_CLASS,					(u32)&iObj_set_class,				(u32)&iObj_get_class					},
		{	_INDEX_CLASSLIBRARY,			(u32)&iObj_set_classLibrary,		(u32)&iObj_get_classLibrary				},
		{	_INDEX_BORDERCOLOR,				(u32)&iObj_set_borderColor,			(u32)&iObj_get_borderColor				},
		{	_INDEX_BORDERSTYLE,				(u32)&iObj_set_borderStyle,			(u32)&iObj_get_borderStyle				},
		{	_INDEX_COLORSCHEME,				(u32)&iObj_set_colorScheme,			(u32)&iObj_get_colorScheme				},
		{	_INDEX_COLORSOURCE,				(u32)&iObj_set_colorSource,			(u32)&iObj_get_colorSource				},
		{	_INDEX_FORECOLOR,				(u32)&iObj_set_foreColor,			(u32)&iObj_get_foreColor				},
		{	_INDEX_BACKCOLOR,				(u32)&iObj_set_backColor,			(u32)&iObj_get_backColor				},
		{	_INDEX_DISABLEDBACKCOLOR,		(u32)&iObj_set_disabledBackColor,	(u32)&iObj_get_disabledBackColor		},
		{	_INDEX_DISABLEDFORECOLOR,		(u32)&iObj_set_disabledForeColor,	(u32)&iObj_get_disabledForeColor		},
		{	_INDEX_COMMENT,					(u32)&iObj_set_comment,				(u32)&iObj_get_comment					},
		{	_INDEX_CONTROLSOURCE,			(u32)&iObj_set_controlSource,		(u32)&iObj_get_controlSource			},
		{	_INDEX_DRAGICON,				(u32)&iObj_set_dragIcon,			(u32)&iObj_get_dragIcon					},
		{	_INDEX_DRAGMODE,				(u32)&iObj_set_dragMode,			(u32)&iObj_get_dragMode					},
		{	_INDEX_ENABLED,					(u32)&iObj_set_enabled,				(u32)&iObj_get_enabled					},
		{	_INDEX_ENABLEHYPERLINKS,		(u32)&iObj_set_enableHyperlinks,	(u32)&iObj_get_enableHyperlinks			},
		{	_INDEX_FONTBOLD,				(u32)&iObj_set_fontBold,			(u32)&iObj_get_fontBold					},
		{	_INDEX_FONTCHARSET,				(u32)&iObj_set_fontCharSet,			(u32)&iObj_get_fontCharSet				},
		{	_INDEX_FONTCONDENSE,			(u32)&iObj_set_fontCondense,		(u32)&iObj_get_fontCondense				},
		{	_INDEX_FONTEXTEND,				(u32)&iObj_set_fontExtend,			(u32)&iObj_get_fontExtend				},
		{	_INDEX_FONTITALIC,				(u32)&iObj_set_fontItalic,			(u32)&iObj_get_fontItalic				},
		{	_INDEX_FONTNAME,				(u32)&iObj_set_fontName,			(u32)&iObj_get_fontName					},
		{	_INDEX_FONTOUTLINE,				(u32)&iObj_set_fontOutline,			(u32)&iObj_get_fontOutline				},
		{	_INDEX_FONTSHADOW,				(u32)&iObj_set_fontShadow,			(u32)&iObj_get_fontShadow				},
		{	_INDEX_FONTSIZE,				(u32)&iObj_set_fontSize,			(u32)&iObj_get_fontSize					},
		{	_INDEX_FONTSTRIKETHRU,			(u32)&iObj_set_fontStrikeThru,		(u32)&iObj_get_fontStrikeThru			},
		{	_INDEX_FONTUNDERLINE,			(u32)&iObj_set_fontUnderline,		(u32)&iObj_get_fontUnderline			},
		{	_INDEX_FORMAT,					(u32)&iObj_set_format,				(u32)&iObj_get_format					},
		{	_INDEX_HEIGHT,					(u32)&iObj_set_height,				(u32)&iObj_get_height					},
		{	_INDEX_HELPCONTEXTID,			(u32)&iObj_set_helpContextID,		(u32)&iObj_get_helpContextID			},
		{	_INDEX_HIDESELECTION,			(u32)&iObj_set_hideSelection,		(u32)&iObj_get_hideSelection			},
		{	_INDEX_IMEMODE,					(u32)&iObj_set_iMEMode,				(u32)&iObj_get_iMEMode					},
		{	_INDEX_INTEGRALHEIGHT,			(u32)&iObj_set_integralHeight,		(u32)&iObj_get_integralHeight			},
		{	_INDEX_LEFT,					(u32)&iObj_set_left,				(u32)&iObj_get_left						},
		{	_INDEX_MARGIN,					(u32)&iObj_set_margin,				(u32)&iObj_get_margin					},
		{	_INDEX_MAXLENGTH,				(u32)&iObj_set_maxLength,			(u32)&iObj_get_maxLength				},
		{	_INDEX_MOUSEICON,				(u32)&iObj_set_mouseIcon,			(u32)&iObj_get_mouseIcon				},
		{	_INDEX_MOUSEPOINTER,			(u32)&iObj_set_mousePointer,		(u32)&iObj_get_mousePointer				},
		{	_INDEX_NAME,					(u32)&iObj_set_name,				(u32)&iObj_get_name						},
		{	_INDEX_NULLDISPLAY,				(u32)&iObj_set_nullDisplay,			(u32)&iObj_get_nullDisplay				},
		{	_INDEX_OLEDRAGMODE,				(u32)&iObj_set_oLEDragMode,			(u32)&iObj_get_oLEDragMode				},
		{	_INDEX_OLEDRAGPICTURE,			(u32)&iObj_set_oLEDragPicture,		(u32)&iObj_get_oLEDragPicture			},
		{	_INDEX_OLEDROPEFFECTS,			(u32)&iObj_set_oLEDropEffects,		(u32)&iObj_get_oLEDropEffects			},
		{	_INDEX_OLEDROPHASDATA,			(u32)&iObj_set_oLEDropHasData,		(u32)&iObj_get_oLEDropHasData			},
		{	_INDEX_OLEDROPMODE,				(u32)&iObj_set_oLEDropMode,			(u32)&iObj_get_oLEDropMode				},
		{	_INDEX_OLEDROPTEXTINSERTION,	(u32)&iObj_set_oLEDropTextInsertion,(u32)&iObj_get_oLEDropTextInsertion		},
		{	_INDEX_PARENT,					(u32)&iObj_set_parent,				(u32)&iObj_get_parent					},
		{	_INDEX_PARENTCLASS,				(u32)&iObj_set_parentClass,			(u32)&iObj_get_parentClass				},
		{	_INDEX_PASSWORDCHAR,			(u32)&iObj_set_passwordChar,		(u32)&iObj_get_passwordChar				},
		{	_INDEX_READONLY,				(u32)&iObj_set_readOnly,			(u32)&iObj_get_readOnly					},
		{	_INDEX_RIGHTTOLEFT,				(u32)&iObj_set_rightToLeft,			(u32)&iObj_get_rightToLeft				},
		{	_INDEX_SCROLLBARS,				(u32)&iObj_set_scrollBars,			(u32)&iObj_get_scrollBars				},
		{	_INDEX_SELECTEDBACKCOLOR,		(u32)&iObj_set_selectedBackColor,	(u32)&iObj_get_selectedBackColor		},
		{	_INDEX_SELECTEDFORECOLOR,		(u32)&iObj_set_selectedForeColor,	(u32)&iObj_get_selectedForeColor		},
		{	_INDEX_SELECTONENTRY,			(u32)&iObj_set_selectOnEntry,		(u32)&iObj_get_selectOnEntry			},
		{	_INDEX_SELLENGTH,				(u32)&iObj_set_selLength,			(u32)&iObj_get_selLength				},
		{	_INDEX_SELSTART,				(u32)&iObj_set_selStart,			(u32)&iObj_get_selStart					},
		{	_INDEX_SELTEXT,					(u32)&iObj_set_selText,				(u32)&iObj_get_selText					},
		{	_INDEX_SPECIALEFFECT,			(u32)&iObj_set_specialEffect,		(u32)&iObj_get_specialEffect			},
		{	_INDEX_STATUSBARTEXT,			(u32)&iObj_set_statusBarText,		(u32)&iObj_get_statusBarText			},
		{	_INDEX_TABINDEX,				(u32)&iObj_set_tabIndex,			(u32)&iObj_get_tabIndex					},
		{	_INDEX_TABSTOP,					(u32)&iObj_set_tabStop,				(u32)&iObj_get_tabStop					},
		{	_INDEX_TAG,						(u32)&iObj_set_tag,					(u32)&iObj_get_tag						},
		{	_INDEX_TERMINATEREAD,			(u32)&iObj_set_terminateRead,		(u32)&iObj_get_terminateRead			},
		{	_INDEX_TEXT,					(u32)&iObj_set_text,				(u32)&iObj_get_text						},
		{	_INDEX_TOOLTIPTEXT,				(u32)&iObj_set_toolTipText,			(u32)&iObj_get_toolTipText				},
		{	_INDEX_TOP,						(u32)&iObj_set_top,					(u32)&iObj_get_top						},
		{	_INDEX_VALUE,					(u32)&iObj_set_value,				(u32)&iObj_get_value					},
		{	_INDEX_VISIBLE,					(u32)&iObj_set_visible,				(u32)&iObj_get_visible					},
		{	_INDEX_WHATSTHISHELPID,			(u32)&iObj_set_whatsThisHelpID,		(u32)&iObj_get_whatsThisHelpID			},
		{	_INDEX_WIDTH,					(u32)&iObj_set_width,				(u32)&iObj_get_width					},
		{	0,								0,									0										}
	};

	SPropertyMap gcProps_listbox[] =
	{
		{	_INDEX_ANCHOR,					(u32)&iObj_set_anchor,				(u32)&iObj_get_anchor					},
		{	_INDEX_APPLICATION,				(u32)&iObj_set_application,			(u32)&iObj_get_application				},
		{	_INDEX_AUTOHIDESCROLLBAR,		(u32)&iObj_set_autoHideScrollBar,	(u32)&iObj_get_autoHideScrollBar		},
		{	_INDEX_BASECLASS,				(u32)&iObj_set_baseClass,			(u32)&iObj_get_baseClass				},
		{	_INDEX_CLASS,					(u32)&iObj_set_class,				(u32)&iObj_get_class					},
		{	_INDEX_CLASSLIBRARY,			(u32)&iObj_set_classLibrary,		(u32)&iObj_get_classLibrary				},
		{	_INDEX_LISTCOUNT,				(u32)&iObj_set_listCount,			(u32)&iObj_get_listCount				},
		{	_INDEX_COLUMNCOUNT,				(u32)&iObj_set_columnCount,			(u32)&iObj_get_columnCount				},
		{	_INDEX_BORDERCOLOR,				(u32)&iObj_set_borderColor,			(u32)&iObj_get_borderColor				},
		{	_INDEX_BOUNDCOLUMN,				(u32)&iObj_set_boundColumn,			(u32)&iObj_get_boundColumn				},
		{	_INDEX_BOUNDTO,					(u32)&iObj_set_boundTo,				(u32)&iObj_get_boundTo					},
		{	_INDEX_COLORSCHEME,				(u32)&iObj_set_colorScheme,			(u32)&iObj_get_colorScheme				},
		{	_INDEX_COLORSOURCE,				(u32)&iObj_set_colorSource,			(u32)&iObj_get_colorSource				},
		{	_INDEX_DISABLEDBACKCOLOR,		(u32)&iObj_set_disabledBackColor,	(u32)&iObj_get_disabledBackColor		},
		{	_INDEX_DISABLEDFORECOLOR,		(u32)&iObj_set_disabledForeColor,	(u32)&iObj_get_disabledForeColor		},
		{	_INDEX_DISABLEDITEMBACKCOLOR,	(u32)&iObj_set_disabledItemBackColor,	(u32)&iObj_get_disabledItemBackColor	},
		{	_INDEX_DISABLEDITEMFORECOLOR,	(u32)&iObj_set_disabledItemForeColor,	 (u32)&iObj_get_disabledItemForeColor	},
		{	_INDEX_COLUMNLINES,				(u32)&iObj_set_columnLines,			(u32)&iObj_get_columnLines				},
		{	_INDEX_COLUMNWIDTHS,			(u32)&iObj_set_columnWidths,		(u32)&iObj_get_columnWidths				},
		{	_INDEX_COMMENT,					(u32)&iObj_set_comment,				(u32)&iObj_get_comment					},
		{	_INDEX_CONTROLSOURCE,			(u32)&iObj_set_controlSource,		(u32)&iObj_get_controlSource			},
		{	_INDEX_ROWSOURCE,				(u32)&iObj_set_rowSource,			(u32)&iObj_get_rowSource				},
		{	_INDEX_ROWSOURCETYPE,			(u32)&iObj_set_rowSourceType,		(u32)&iObj_get_rowSourceType			},
		{	_INDEX_DISPLAYVALUE,			(u32)&iObj_set_displayValue,		(u32)&iObj_get_displayValue				},
		{	_INDEX_DRAGICON,				(u32)&iObj_set_dragIcon,			(u32)&iObj_get_dragIcon					},
		{	_INDEX_DRAGMODE,				(u32)&iObj_set_dragMode,			(u32)&iObj_get_dragMode					},
		{	_INDEX_ENABLED,					(u32)&iObj_set_enabled,				(u32)&iObj_get_enabled					},
		{	_INDEX_FIRSTELEMENT,			(u32)&iObj_set_firstElement,		(u32)&iObj_get_firstElement				},
		{	_INDEX_FONTBOLD,				(u32)&iObj_set_fontBold,			(u32)&iObj_get_fontBold					},
		{	_INDEX_FONTCHARSET,				(u32)&iObj_set_fontCharSet,			(u32)&iObj_get_fontCharSet				},
		{	_INDEX_FONTCONDENSE,			(u32)&iObj_set_fontCondense,		(u32)&iObj_get_fontCondense				},
		{	_INDEX_FONTEXTEND,				(u32)&iObj_set_fontExtend,			(u32)&iObj_get_fontExtend				},
		{	_INDEX_FONTITALIC,				(u32)&iObj_set_fontItalic,			(u32)&iObj_get_fontItalic				},
		{	_INDEX_FONTNAME,				(u32)&iObj_set_fontName,			(u32)&iObj_get_fontName					},
		{	_INDEX_FONTOUTLINE,				(u32)&iObj_set_fontOutline,			(u32)&iObj_get_fontOutline				},
		{	_INDEX_FONTSHADOW,				(u32)&iObj_set_fontShadow,			(u32)&iObj_get_fontShadow				},
		{	_INDEX_FONTSIZE,				(u32)&iObj_set_fontSize,			(u32)&iObj_get_fontSize					},
		{	_INDEX_FONTSTRIKETHRU,			(u32)&iObj_set_fontStrikeThru,		(u32)&iObj_get_fontStrikeThru			},
		{	_INDEX_FONTUNDERLINE,			(u32)&iObj_set_fontUnderLine,		(u32)&iObj_get_fontUnderLine			},
		{	_INDEX_HEIGHT,					(u32)&iObj_set_height,				(u32)&iObj_get_height					},
		{	_INDEX_HELPCONTEXTID,			(u32)&iObj_set_helpContextID,		(u32)&iObj_get_helpContextID			},
		{	_INDEX_INCREMENTALSEARCH,		(u32)&iObj_set_incrementalSearch,	(u32)&iObj_get_incrementalSearch		},
		{	_INDEX_INTEGRALHEIGHT,			(u32)&iObj_set_integralHeight,		(u32)&iObj_get_integralHeight			},
		{	_INDEX_ITEMBACKCOLOR,			(u32)&iObj_set_itemBackColor,		(u32)&iObj_get_itemBackColor			},
		{	_INDEX_ITEMFORECOLOR,			(u32)&iObj_set_itemForeColor,		(u32)&iObj_get_itemForeColor			},
		{	_INDEX_ITEMDATA,				(u32)&iObj_set_itemData,			(u32)&iObj_get_itemData					},
		{	_INDEX_ITEMIDDATA,				(u32)&iObj_set_itemIDData,			(u32)&iObj_get_itemIDData				},
		{	_INDEX_ITEMTIPS,				(u32)&iObj_set_itemTips,			(u32)&iObj_get_itemTips					},
		{	_INDEX_LEFT,					(u32)&iObj_set_left,				(u32)&iObj_get_left						},
		{	_INDEX_LIST,					(u32)&iObj_set_list,				(u32)&iObj_get_list						},
		{	_INDEX_LISTINDEX,				(u32)&iObj_set_listIndex,			(u32)&iObj_get_listIndex				},
		{	_INDEX_LISTITEM,				(u32)&iObj_set_listItem,			(u32)&iObj_get_listItem					},
		{	_INDEX_LISTITEMID,				(u32)&iObj_set_listItemID,			(u32)&iObj_get_listItemID				},
		{	_INDEX_MOUSEICON,				(u32)&iObj_set_mouseIcon,			(u32)&iObj_get_mouseIcon				},
		{	_INDEX_MOUSEPOINTER,			(u32)&iObj_set_mousePointer,		(u32)&iObj_get_mousePointer				},
		{	_INDEX_MOVERBARS,				(u32)&iObj_set_moverBars,			(u32)&iObj_get_moverBars				},
		{	_INDEX_MULTISELECT,				(u32)&iObj_set_multiSelect,			(u32)&iObj_get_multiSelect				},
		{	_INDEX_NAME,					(u32)&iObj_set_name,				(u32)&iObj_get_name						},
		{	_INDEX_NEWINDEX,				(u32)&iObj_set_newIndex,			(u32)&iObj_get_newIndex					},
		{	_INDEX_NEWITEMID,				(u32)&iObj_set_newItemID,			(u32)&iObj_get_newItemID				},
		{	_INDEX_NULLDISPLAY,				(u32)&iObj_set_nullDisplay,			(u32)&iObj_get_nullDisplay				},
		{	_INDEX_NUMBEROFELEMENTS,		(u32)&iObj_set_numberOfElements,	(u32)&iObj_get_numberOfElements			},
		{	_INDEX_OLEDRAGMODE,				(u32)&iObj_set_oLEDragMode,			(u32)&iObj_get_oLEDragMode				},
		{	_INDEX_OLEDRAGPICTURE,			(u32)&iObj_set_oLEDragPicture,		(u32)&iObj_get_oLEDragPicture			},
		{	_INDEX_OLEDROPEFFECTS,			(u32)&iObj_set_oLEDropEffects,		(u32)&iObj_get_oLEDropEffects			},
		{	_INDEX_OLEDROPHASDATA,			(u32)&iObj_set_oLEDropHasData,		(u32)&iObj_get_oLEDropHasData			},
		{	_INDEX_OLEDROPMODE,				(u32)&iObj_set_oLEDropMode,			(u32)&iObj_get_oLEDropMode				},
		{	_INDEX_PARENT,					(u32)&iObj_set_parent,				(u32)&iObj_get_parent					},
		{	_INDEX_PARENTCLASS,				(u32)&iObj_set_parentClass,			(u32)&iObj_get_parentClass				},
		{	_INDEX_PICTURE,					(u32)&iObj_set_picture,				(u32)&iObj_get_picture					},
		{	_INDEX_RIGHTTOLEFT,				(u32)&iObj_set_rightToLeft,			(u32)&iObj_get_rightToLeft				},
		{	_INDEX_SELECTED,				(u32)&iObj_set_selected,			(u32)&iObj_get_selected					},
		{	_INDEX_SELECTEDID,				(u32)&iObj_set_selectedID,			(u32)&iObj_get_selectedID				},
		{	_INDEX_SELECTEDITEMBACKCOLOR,	(u32)&iObj_set_selectedItemBackColor,	 (u32)&iObj_get_selectedItemBackColor	},
		{	_INDEX_SELECTEDITEMFORECOLOR,	(u32)&iObj_set_selectedItemForeColor,	 (u32)&iObj_get_selectedItemForeColor	},
		{	_INDEX_SORTED,					(u32)&iObj_set_sorted,				(u32)&iObj_get_sorted					},
		{	_INDEX_SPECIALEFFECT,			(u32)&iObj_set_specialEffect,		(u32)&iObj_get_specialEffect			},
		{	_INDEX_STATUSBARTEXT,			(u32)&iObj_set_statusBarText,		(u32)&iObj_get_statusBarText			},
		{	_INDEX_TABINDEX,				(u32)&iObj_set_tabIndex,			(u32)&iObj_get_tabIndex					},
		{	_INDEX_TABSTOP,					(u32)&iObj_set_tabStop,				(u32)&iObj_get_tabStop					},
		{	_INDEX_TAG,						(u32)&iObj_set_tag,					(u32)&iObj_get_tag						},
		{	_INDEX_TERMINATEREAD,			(u32)&iObj_set_terminateRead,		(u32)&iObj_get_terminateRead			},
		{	_INDEX_THEMES,					(u32)&iObj_set_themes,				(u32)&iObj_get_themes					},
		{	_INDEX_TOOLTIPTEXT,				(u32)&iObj_set_toolTipText,			(u32)&iObj_get_toolTipText				},
		{	_INDEX_TOP,						(u32)&iObj_set_top,					(u32)&iObj_get_top						},
		{	_INDEX_TOPINDEX,				(u32)&iObj_set_topIndex,			(u32)&iObj_get_topIndex					},
		{	_INDEX_TOPITEMID,				(u32)&iObj_set_topItemID,			(u32)&iObj_get_topItemID				},
		{	_INDEX_VALUE,					(u32)&iObj_set_value,				(u32)&iObj_get_value					},
		{	_INDEX_VISIBLE,					(u32)&iObj_set_visible,				(u32)&iObj_get_visible					},
		{	_INDEX_WHATSTHISHELPID,			(u32)&iObj_set_whatsThisHelpID,		(u32)&iObj_get_whatsThisHelpID			},
		{	_INDEX_WIDTH,					(u32)&iObj_set_width,				(u32)&iObj_get_width					},
		{	0,								0,									0										}
	};

	SPropertyMap gcProps_combobox[] =
	{
		{	_INDEX_ALIGNMENT,				(u32)&iObj_set_alignment,			(u32)&iObj_get_alignment				},
		{	_INDEX_ANCHOR,					(u32)&iObj_set_anchor,				(u32)&iObj_get_anchor					},
		{	_INDEX_APPLICATION,				(u32)&iObj_set_application,			(u32)&iObj_get_application				},
		{	_INDEX_BASECLASS,				(u32)&iObj_set_baseClass,			(u32)&iObj_get_baseClass				},
		{	_INDEX_CLASS,					(u32)&iObj_set_class,				(u32)&iObj_get_class					},
		{	_INDEX_CLASSLIBRARY,			(u32)&iObj_set_classLibrary,		(u32)&iObj_get_classLibrary				},
		{	_INDEX_LISTCOUNT,				(u32)&iObj_set_listCount,			(u32)&iObj_get_listCount				},
		{	_INDEX_COLUMNCOUNT,				(u32)&iObj_set_columnCount,			(u32)&iObj_get_columnCount				},
		{	_INDEX_BORDERCOLOR,				(u32)&iObj_set_borderColor,			(u32)&iObj_get_borderColor				},
		{	_INDEX_BORDERSTYLE,				(u32)&iObj_set_borderStyle,			(u32)&iObj_get_borderStyle				},
		{	_INDEX_BOUNDCOLUMN,				(u32)&iObj_set_boundColumn,			(u32)&iObj_get_boundColumn				},
		{	_INDEX_BOUNDTO,					(u32)&iObj_set_boundTo,				(u32)&iObj_get_boundTo					},
		{	_INDEX_COLORSCHEME,				(u32)&iObj_set_colorScheme,			(u32)&iObj_get_colorScheme				},
		{	_INDEX_COLORSOURCE,				(u32)&iObj_set_colorSource,			(u32)&iObj_get_colorSource				},
		{	_INDEX_FORECOLOR,				(u32)&iObj_set_foreColor,			(u32)&iObj_get_foreColor				},
		{	_INDEX_BACKCOLOR,				(u32)&iObj_set_backColor,			(u32)&iObj_get_backColor				},
		{	_INDEX_DISABLEDBACKCOLOR,		(u32)&iObj_set_disabledBackColor,	(u32)&iObj_get_disabledBackColor		},
		{	_INDEX_DISABLEDFORECOLOR,		(u32)&iObj_set_disabledForeColor,	(u32)&iObj_get_disabledForeColor		},
		{	_INDEX_DISABLEDITEMBACKCOLOR,	(u32)&iObj_set_disabledItemBackColor,	 (u32)&iObj_get_disabledItemBackColor	},
		{	_INDEX_DISABLEDITEMFORECOLOR,	(u32)&iObj_set_disabledItemForeColor,	 (u32)&iObj_get_disabledItemForeColor	},
		{	_INDEX_COLUMNLINES,				(u32)&iObj_set_columnLines,			(u32)&iObj_get_columnLines				},
		{	_INDEX_COLUMNWIDTHS,			(u32)&iObj_set_columnWidths,		(u32)&iObj_get_columnWidths				},
		{	_INDEX_COMMENT,					(u32)&iObj_set_comment,				(u32)&iObj_get_comment					},
		{	_INDEX_CONTROLSOURCE,			(u32)&iObj_set_controlSource,		(u32)&iObj_get_controlSource			},
		{	_INDEX_ROWSOURCE,				(u32)&iObj_set_rowSource,			(u32)&iObj_get_rowSource				},
		{	_INDEX_ROWSOURCETYPE,			(u32)&iObj_set_rowSourceType,		(u32)&iObj_get_rowSourceType			},
		{	_INDEX_DISPLAYCOUNT,			(u32)&iObj_set_displayCount,		(u32)&iObj_get_displayCount				},
		{	_INDEX_DISPLAYVALUE,			(u32)&iObj_set_displayValue,		(u32)&iObj_get_displayValue				},
		{	_INDEX_DRAGICON,				(u32)&iObj_set_dragIcon,			(u32)&iObj_get_dragIcon					},
		{	_INDEX_DRAGMODE,				(u32)&iObj_set_dragMode,			(u32)&iObj_get_dragMode					},
		{	_INDEX_ENABLED,					(u32)&iObj_set_enabled,				(u32)&iObj_get_enabled					},
		{	_INDEX_FIRSTELEMENT,			(u32)&iObj_set_firstElement,		(u32)&iObj_get_firstElement				},
		{	_INDEX_FONTBOLD,				(u32)&iObj_set_fontBold,			(u32)&iObj_get_fontBold					},
		{	_INDEX_FONTCHARSET,				(u32)&iObj_set_fontCharSet,			(u32)&iObj_get_fontCharSet				},
		{	_INDEX_FONTCONDENSE,			(u32)&iObj_set_fontCondense,		(u32)&iObj_get_fontCondense				},
		{	_INDEX_FONTEXTEND,				(u32)&iObj_set_fontExtend,			(u32)&iObj_get_fontExtend				},
		{	_INDEX_FONTITALIC,				(u32)&iObj_set_fontItalic,			(u32)&iObj_get_fontItalic				},
		{	_INDEX_FONTNAME,				(u32)&iObj_set_fontName,			(u32)&iObj_get_fontName					},
		{	_INDEX_FONTOUTLINE,				(u32)&iObj_set_fontOutline,			(u32)&iObj_get_fontOutline				},
		{	_INDEX_FONTSHADOW,				(u32)&iObj_set_fontShadow,			(u32)&iObj_get_fontShadow				},
		{	_INDEX_FONTSIZE,				(u32)&iObj_set_fontSize,			(u32)&iObj_get_fontSize					},
		{	_INDEX_FONTSTRIKETHRU,			(u32)&iObj_set_fontStrikeThru,		(u32)&iObj_get_fontStrikeThru			},
		{	_INDEX_FONTUNDERLINE,			(u32)&iObj_set_fontUnderline,		(u32)&iObj_get_fontUnderline			},
		{	_INDEX_FORMAT,					(u32)&iObj_set_format,				(u32)&iObj_get_format					},
		{	_INDEX_HEIGHT,					(u32)&iObj_set_height,				(u32)&iObj_get_height					},
		{	_INDEX_HELPCONTEXTID,			(u32)&iObj_set_helpContextID,		(u32)&iObj_get_helpContextID			},
		{	_INDEX_HIDESELECTION,			(u32)&iObj_set_hideSelection,		(u32)&iObj_get_hideSelection			},
		{	_INDEX_IMEMODE,					(u32)&iObj_set_iMEMode,				(u32)&iObj_get_iMEMode					},
		{	_INDEX_INCREMENTALSEARCH,		(u32)&iObj_set_incrementalSearch,	(u32)&iObj_get_incrementalSearch		},
		{	_INDEX_INPUTMASK,				(u32)&iObj_set_inputMask,			(u32)&iObj_get_inputMask				},
		{	_INDEX_ITEMBACKCOLOR,			(u32)&iObj_set_itemBackColor,		(u32)&iObj_get_itemBackColor			},
		{	_INDEX_ITEMFORECOLOR,			(u32)&iObj_set_itemForeColor,		(u32)&iObj_get_itemForeColor			},
		{	_INDEX_ITEMDATA,				(u32)&iObj_set_itemData,			(u32)&iObj_get_itemData					},
		{	_INDEX_ITEMIDDATA,				(u32)&iObj_set_itemIDData,			(u32)&iObj_get_itemIDData				},
		{	_INDEX_ITEMTIPS,				(u32)&iObj_set_itemTips,			(u32)&iObj_get_itemTips					},
		{	_INDEX_LEFT,					(u32)&iObj_set_left,				(u32)&iObj_get_left						},
		{	_INDEX_LIST,					(u32)&iObj_set_list,				(u32)&iObj_get_list						},
		{	_INDEX_LISTINDEX,				(u32)&iObj_set_listIndex,			(u32)&iObj_get_listIndex				},
		{	_INDEX_LISTITEM,				(u32)&iObj_set_listItem,			(u32)&iObj_get_listItem					},
		{	_INDEX_LISTITEMID,				(u32)&iObj_set_listItemID,			(u32)&iObj_get_listItemID				},
		{	_INDEX_MARGIN,					(u32)&iObj_set_margin,				(u32)&iObj_get_margin					},
		{	_INDEX_MAXLENGTH,				(u32)&iObj_set_maxLength,			(u32)&iObj_get_maxLength				},
		{	_INDEX_MOUSEICON,				(u32)&iObj_set_mouseIcon,			(u32)&iObj_get_mouseIcon				},
		{	_INDEX_MOUSEPOINTER,			(u32)&iObj_set_mousePointer,		(u32)&iObj_get_mousePointer				},
		{	_INDEX_NAME,					(u32)&iObj_set_name,				(u32)&iObj_get_name						},
		{	_INDEX_NEWINDEX,				(u32)&iObj_set_newIndex,			(u32)&iObj_get_newIndex					},
		{	_INDEX_NEWITEMID,				(u32)&iObj_set_newItemID,			(u32)&iObj_get_newItemID				},
		{	_INDEX_NULLDISPLAY,				(u32)&iObj_set_nullDisplay,			(u32)&iObj_get_nullDisplay				},
		{	_INDEX_NUMBEROFELEMENTS,		(u32)&iObj_set_numberOfElements,	(u32)&iObj_get_numberOfElements			},
		{	_INDEX_OLEDRAGMODE,				(u32)&iObj_set_oLEDragMode,			(u32)&iObj_get_oLEDragMode				},
		{	_INDEX_OLEDRAGPICTURE,			(u32)&iObj_set_oLEDragPicture,		(u32)&iObj_get_oLEDragPicture			},
		{	_INDEX_OLEDROPEFFECTS,			(u32)&iObj_set_oLEDropEffects,		(u32)&iObj_get_oLEDropEffects			},
		{	_INDEX_OLEDROPHASDATA,			(u32)&iObj_set_oLEDropHasData,		(u32)&iObj_get_oLEDropHasData			},
		{	_INDEX_OLEDROPMODE,				(u32)&iObj_set_oLEDropMode,			(u32)&iObj_get_oLEDropMode				},
		{	_INDEX_OLEDROPTEXTINSERTION,	(u32)&iObj_set_oLEDropTextInsertion,(u32)&iObj_get_oLEDropTextInsertion		},
		{	_INDEX_PARENT,					(u32)&iObj_set_parent,				(u32)&iObj_get_parent					},
		{	_INDEX_PARENTCLASS,				(u32)&iObj_set_parentClass,			(u32)&iObj_get_parentClass				},
		{	_INDEX_PICTURE,					(u32)&iObj_set_picture,				(u32)&iObj_get_picture					},
		{	_INDEX_PICTURESELECTIONDISPLAY,	(u32)&iObj_set_pictureSelectionDisplay, (u32)&iObj_get_pictureSelectionDisplay	},
		{	_INDEX_READONLY,				(u32)&iObj_set_readOnly,			(u32)&iObj_get_readOnly					},
		{	_INDEX_RIGHTTOLEFT,				(u32)&iObj_set_rightToLeft,			(u32)&iObj_get_rightToLeft				},
		{	_INDEX_SELECTED,				(u32)&iObj_set_selected,			(u32)&iObj_get_selected					},
		{	_INDEX_SELECTEDID,				(u32)&iObj_set_selectedID,			(u32)&iObj_get_selectedID				},
		{	_INDEX_SELECTEDBACKCOLOR,		(u32)&iObj_set_selectedBackColor,	(u32)&iObj_get_selectedBackColor		},
		{	_INDEX_SELECTEDFORECOLOR,		(u32)&iObj_set_selectedForeColor,	(u32)&iObj_get_selectedForeColor		},
		{	_INDEX_SELECTEDITEMBACKCOLOR,	(u32)&iObj_set_selectedItemBackColor,	 (u32)&iObj_get_selectedItemBackColor	},
		{	_INDEX_SELECTEDITEMFORECOLOR,	(u32)&iObj_set_selectedItemForeColor,	 (u32)&iObj_get_selectedItemForeColor	},
		{	_INDEX_SELECTONENTRY,			(u32)&iObj_set_selectOnEntry,		(u32)&iObj_get_selectOnEntry			},
		{	_INDEX_SELLENGTH,				(u32)&iObj_set_selLength,			(u32)&iObj_get_selLength				},
		{	_INDEX_SELSTART,				(u32)&iObj_set_selStart,			(u32)&iObj_get_selStart					},
		{	_INDEX_SELTEXT,					(u32)&iObj_set_selText,				(u32)&iObj_get_selText					},
		{	_INDEX_SORTED,					(u32)&iObj_set_sorted,				(u32)&iObj_get_sorted					},
		{	_INDEX_SPECIALEFFECT,			(u32)&iObj_set_specialEffect,		(u32)&iObj_get_specialEffect			},
		{	_INDEX_STATUSBARTEXT,			(u32)&iObj_set_statusBarText,		(u32)&iObj_get_statusBarText			},
		{	_INDEX_STYLE,					(u32)&iObj_set_style,				(u32)&iObj_get_style					},
		{	_INDEX_TABINDEX,				(u32)&iObj_set_tabIndex,			(u32)&iObj_get_tabIndex					},
		{	_INDEX_TABSTOP,					(u32)&iObj_set_tabStop,				(u32)&iObj_get_tabStop					},
		{	_INDEX_TAG,						(u32)&iObj_set_tag,					(u32)&iObj_get_tag						},
		{	_INDEX_TERMINATEREAD,			(u32)&iObj_set_terminateRead,		(u32)&iObj_get_terminateRead			},
		{	_INDEX_TEXT,					(u32)&iObj_set_text,				(u32)&iObj_get_text						},
		{	_INDEX_THEMES,					(u32)&iObj_set_themes,				(u32)&iObj_get_themes					},
		{	_INDEX_TOOLTIPTEXT,				(u32)&iObj_set_toolTipText,			(u32)&iObj_get_toolTipText				},
		{	_INDEX_TOP,						(u32)&iObj_set_top,					(u32)&iObj_get_top						},
		{	_INDEX_TOPINDEX,				(u32)&iObj_set_topIndex,			(u32)&iObj_get_topIndex					},
		{	_INDEX_TOPITEMID,				(u32)&iObj_set_topItemID,			(u32)&iObj_get_topItemID				},
		{	_INDEX_VALUE,					(u32)&iObj_set_value,				(u32)&iObj_get_value					},
		{	_INDEX_VISIBLE,					(u32)&iObj_set_visible,				(u32)&iObj_get_visible					},
		{	_INDEX_WHATSTHISHELPID,			(u32)&iObj_set_whatsThisHelpID,		(u32)&iObj_get_whatsThisHelpID			},
		{	_INDEX_WIDTH,					(u32)&iObj_set_width,				(u32)&iObj_get_width					},
		{	0,								0,									0										}
	};

	SPropertyMap gcProps_form[] =
	{
		{	_INDEX_ACTIVECONTROL,			(u32)&iObj_set_activeControl,		(u32)&iObj_get_activeControl			},
		{	_INDEX_ACTIVEFORM,				(u32)&iObj_set_activeForm,			(u32)&iObj_get_activeForm				},
		{	_INDEX_ALLOWOUTPUT,				(u32)&iObj_set_allowOutput,			(u32)&iObj_get_allowOutput				},
		{	_INDEX_ALWAYSONTOP,				(u32)&iObj_set_alwaysOnTop,			(u32)&iObj_get_alwaysOnTop				},
		{	_INDEX_ALWAYSONBOTTOM,			(u32)&iObj_set_alwaysOnBottom,		(u32)&iObj_get_alwaysOnBottom			},
		{	_INDEX_BINDCONTROLS,			(u32)&iObj_set_bindControls,		(u32)&iObj_get_bindControls				},
		{	_INDEX_BUFFERMODE,				(u32)&iObj_set_bufferMode,			(u32)&iObj_get_bufferMode				},
		{	_INDEX_CONTROLBOX,				(u32)&iObj_set_controlBox,			(u32)&iObj_get_controlBox				},
		{	_INDEX_CLOSABLE,				(u32)&iObj_set_closable,			(u32)&iObj_get_closable					},
		{	_INDEX_CONTINUOUSSCROLL,		(u32)&iObj_set_continuousScroll,	(u32)&iObj_get_continuousScroll			},
		{	_INDEX_DATASESSION,				(u32)&iObj_set_dataSession,			(u32)&iObj_get_dataSession				},
		{	_INDEX_DATASESSIONID,			(u32)&iObj_set_dataSessionID,		(u32)&iObj_get_dataSessionID			},
		{	_INDEX_DATAENVIRONMENT,			(u32)&iObj_set_dataEnvironment,		(u32)&iObj_get_dataEnvironment			},
		{	_INDEX_DECLASS,					(u32)&iObj_set_dEClass,				(u32)&iObj_get_dEClass					},
		{	_INDEX_DECLASSLIBRARY,			(u32)&iObj_set_dEClassLibrary,		(u32)&iObj_get_dEClassLibrary			},
		{	_INDEX_DEFOLELCID,				(u32)&iObj_set_defOLELCID,			(u32)&iObj_get_defOLELCID				},
		{	_INDEX_DESKTOP,					(u32)&iObj_set_desktop,				(u32)&iObj_get_desktop					},
		{	_INDEX_MACDESKTOP,				(u32)&iObj_set_macDesktop,			(u32)&iObj_get_macDesktop				},
		{	_INDEX_DOCKPOSITION,			(u32)&iObj_set_dockPosition,		(u32)&iObj_get_dockPosition				},
		{	_INDEX_DOCKABLE,				(u32)&iObj_set_dockable,			(u32)&iObj_get_dockable					},
		{	_INDEX_DOCKED,					(u32)&iObj_set_docked,				(u32)&iObj_get_docked					},
		{	_INDEX_MDIFORM,					(u32)&iObj_set_mDIForm,				(u32)&iObj_get_mDIForm					},
		{	_INDEX_DOCREATE,				(u32)&iObj_set_doCreate,			(u32)&iObj_get_doCreate					},
		{	_INDEX_FILLCOLOR,				(u32)&iObj_set_fillColor,			(u32)&iObj_get_fillColor				},
		{	_INDEX_FILLSTYLE,				(u32)&iObj_set_fillStyle,			(u32)&iObj_get_fillStyle				},
		{	_INDEX_HSCROLLSMALLCHANGE,		(u32)&iObj_set_hScrollSmallChange,	(u32)&iObj_get_hScrollSmallChange		},
		{	_INDEX_VSCROLLSMALLCHANGE,		(u32)&iObj_set_vScrollSmallChange,	(u32)&iObj_get_vScrollSmallChange		},
		{	_INDEX_LOCKSCREEN,				(u32)&iObj_set_lockScreen,			(u32)&iObj_get_lockScreen				},
		{	_INDEX_MAXBUTTON,				(u32)&iObj_set_maxButton,			(u32)&iObj_get_maxButton				},
		{	_INDEX_MINBUTTON,				(u32)&iObj_set_minButton,			(u32)&iObj_get_minButton				},
		{	_INDEX_MOVABLE,					(u32)&iObj_set_movable,				(u32)&iObj_get_movable					},
		{	_INDEX_MAXHEIGHT,				(u32)&iObj_set_maxHeight,			(u32)&iObj_get_maxHeight				},
		{	_INDEX_MAXWIDTH,				(u32)&iObj_set_maxWidth,			(u32)&iObj_get_maxWidth					},
		{	_INDEX_MAXTOP,					(u32)&iObj_set_maxTop,				(u32)&iObj_get_maxTop					},
		{	_INDEX_MAXLEFT,					(u32)&iObj_set_maxLeft,				(u32)&iObj_get_maxLeft					},
		{	_INDEX_MINHEIGHT,				(u32)&iObj_set_minHeight,			(u32)&iObj_get_minHeight				},
		{	_INDEX_MINWIDTH,				(u32)&iObj_set_minWidth,			(u32)&iObj_get_minWidth					},
		{	_INDEX_SCALEMODE,				(u32)&iObj_set_scaleMode,			(u32)&iObj_get_scaleMode				},
		{	_INDEX_SHOWTIPS,				(u32)&iObj_set_showTips,			(u32)&iObj_get_showTips					},
		{	_INDEX_SHOWWINDOW,				(u32)&iObj_set_showWindow,			(u32)&iObj_get_showWindow				},
		{	_INDEX_SHOWINTASKBAR,			(u32)&iObj_set_showInTaskbar,		(u32)&iObj_get_showInTaskbar			},
		{	_INDEX_SIZEBOX,					(u32)&iObj_set_sizeBox,				(u32)&iObj_get_sizeBox					},
		{	_INDEX_WINDOWTYPE,				(u32)&iObj_set_windowType,			(u32)&iObj_get_windowType				},
		{	_INDEX_WINDOWSTATE,				(u32)&iObj_set_windowState,			(u32)&iObj_get_windowState				},
		{	_INDEX_AUTOCENTER,				(u32)&iObj_set_autoCenter,			(u32)&iObj_get_autoCenter				},
		{	_INDEX_BASECLASS,				(u32)&iObj_set_baseClass,			(u32)&iObj_get_baseClass				},
		{	_INDEX_CLASS,					(u32)&iObj_set_class,				(u32)&iObj_get_class					},
		{	_INDEX_CLASSLIBRARY,			(u32)&iObj_set_classLibrary,		(u32)&iObj_get_classLibrary				},
		{	_INDEX_CONTROLS,				(u32)&iObj_set_controls,			(u32)&iObj_get_controls					},
		{	_INDEX_CONTROLCOUNT,			(u32)&iObj_set_controlCount,		(u32)&iObj_get_controlCount				},
		{	_INDEX_OBJECTS,					(u32)&iObj_set_objects,				(u32)&iObj_get_objects					},
		{	_INDEX_BORDERSTYLE,				(u32)&iObj_set_borderStyle,			(u32)&iObj_get_borderStyle				},
		{	_INDEX_CLIPCONTROLS,			(u32)&iObj_set_clipControls,		(u32)&iObj_get_clipControls				},
		{	_INDEX_CAPTION,					(u32)&iObj_set_caption,				(u32)&iObj_get_caption					},
		{	_INDEX_HALFHEIGHTCAPTION,		(u32)&iObj_set_halfHeightCaption,	(u32)&iObj_get_halfHeightCaption		},
		{	_INDEX_COLORSOURCE,				(u32)&iObj_set_colorSource,			(u32)&iObj_get_colorSource				},
		{	_INDEX_FORECOLOR,				(u32)&iObj_set_foreColor,			(u32)&iObj_get_foreColor				},
		{	_INDEX_BACKCOLOR,				(u32)&iObj_set_backColor,			(u32)&iObj_get_backColor				},
		{	_INDEX_CURRENTX,				(u32)&iObj_set_currentX,			(u32)&iObj_get_currentX					},
		{	_INDEX_CURRENTY,				(u32)&iObj_set_currentY,			(u32)&iObj_get_currentY					},
		{	_INDEX_COMMENT,					(u32)&iObj_set_comment,				(u32)&iObj_get_comment					},
		{	_INDEX_DRAWMODE,				(u32)&iObj_set_drawMode,			(u32)&iObj_get_drawMode					},
		{	_INDEX_DRAWSTYLE,				(u32)&iObj_set_drawStyle,			(u32)&iObj_get_drawStyle				},
		{	_INDEX_DRAWWIDTH,				(u32)&iObj_set_drawWidth,			(u32)&iObj_get_drawWidth				},
		{	_INDEX_ENABLED,					(u32)&iObj_set_enabled,				(u32)&iObj_get_enabled					},
		{	_INDEX_FONTBOLD,				(u32)&iObj_set_fontBold,			(u32)&iObj_get_fontBold					},
		{	_INDEX_FONTCHARSET,				(u32)&iObj_set_fontCharSet,			(u32)&iObj_get_fontCharSet				},
		{	_INDEX_FONTCONDENSE,			(u32)&iObj_set_fontCondense,		(u32)&iObj_get_fontCondense				},
		{	_INDEX_FONTEXTEND,				(u32)&iObj_set_fontExtend,			(u32)&iObj_get_fontExtend				},
		{	_INDEX_FONTITALIC,				(u32)&iObj_set_fontItalic,			(u32)&iObj_get_fontItalic				},
		{	_INDEX_FONTNAME,				(u32)&iObj_set_fontName,			(u32)&iObj_get_fontName					},
		{	_INDEX_FONTOUTLINE,				(u32)&iObj_set_fontOutline,			(u32)&iObj_get_fontOutline				},
		{	_INDEX_FONTSHADOW,				(u32)&iObj_set_fontShadow,			(u32)&iObj_get_fontShadow				},
		{	_INDEX_FONTSIZE,				(u32)&iObj_set_fontSize,			(u32)&iObj_get_fontSize					},
		{	_INDEX_FONTSTRIKETHRU,			(u32)&iObj_set_fontStrikeThru,		(u32)&iObj_get_fontStrikeThru			},
		{	_INDEX_FONTUNDERLINE,			(u32)&iObj_set_fontUnderline,		(u32)&iObj_get_fontUnderline			},
		{	_INDEX_HEIGHT,					(u32)&iObj_set_height,				(u32)&iObj_get_height					},
		{	_INDEX_HELPCONTEXTID,			(u32)&iObj_set_helpContextID,		(u32)&iObj_get_helpContextID			},
		{	_INDEX_HWND,					(u32)&iObj_set_hWnd,				(u32)&iObj_get_hWnd						},
		{	_INDEX_KEYPREVIEW,				(u32)&iObj_set_keyPreview,			(u32)&iObj_get_keyPreview				},
		{	_INDEX_LEFT,					(u32)&iObj_set_left,				(u32)&iObj_get_left						},
		{	_INDEX_LOCKSCREEN,				(u32)&iObj_set_lockScreen,			(u32)&iObj_get_lockScreen				},
		{	_INDEX_MOUSEICON,				(u32)&iObj_set_mouseIcon,			(u32)&iObj_get_mouseIcon				},
		{	_INDEX_MOUSEPOINTER,			(u32)&iObj_set_mousePointer,		(u32)&iObj_get_mousePointer				},
		{	_INDEX_NAME,					(u32)&iObj_set_name,				(u32)&iObj_get_name						},
		{	_INDEX_OLEDRAGMODE,				(u32)&iObj_set_oLEDragMode,			(u32)&iObj_get_oLEDragMode				},
		{	_INDEX_OLEDRAGPICTURE,			(u32)&iObj_set_oLEDragPicture,		(u32)&iObj_get_oLEDragPicture			},
		{	_INDEX_OLEDROPEFFECTS,			(u32)&iObj_set_oLEDropEffects,		(u32)&iObj_get_oLEDropEffects			},
		{	_INDEX_OLEDROPHASDATA,			(u32)&iObj_set_oLEDropHasData,		(u32)&iObj_get_oLEDropHasData			},
		{	_INDEX_OLEDROPMODE,				(u32)&iObj_set_oLEDropMode,			(u32)&iObj_get_oLEDropMode				},
		{	_INDEX_PARENT,					(u32)&iObj_set_parent,				(u32)&iObj_get_parent					},
		{	_INDEX_PARENTCLASS,				(u32)&iObj_set_parentClass,			(u32)&iObj_get_parentClass				},
		{	_INDEX_ICON,					(u32)&iObj_set_icon,				(u32)&iObj_get_icon						},
		{	_INDEX_PICTURE,					(u32)&iObj_set_picture,				(u32)&iObj_get_picture					},
		{	_INDEX_RELEASETYPE,				(u32)&iObj_set_releaseType,			(u32)&iObj_get_releaseType				},
		{	_INDEX_RIGHTTOLEFT,				(u32)&iObj_set_rightToLeft,			(u32)&iObj_get_rightToLeft				},
		{	_INDEX_SCROLLBARS,				(u32)&iObj_set_scrollBars,			(u32)&iObj_get_scrollBars				},
		{	_INDEX_TABINDEX,				(u32)&iObj_set_tabIndex,			(u32)&iObj_get_tabIndex					},
		{	_INDEX_TABSTOP,					(u32)&iObj_set_tabStop,				(u32)&iObj_get_tabStop					},
		{	_INDEX_TAG,						(u32)&iObj_set_tag,					(u32)&iObj_get_tag						},
		{	_INDEX_THEMES,					(u32)&iObj_set_themes,				(u32)&iObj_get_themes					},
		{	_INDEX_TITLEBAR,				(u32)&iObj_set_titleBar,			(u32)&iObj_get_titleBar					},
		{	_INDEX_TOP,						(u32)&iObj_set_top,					(u32)&iObj_get_top						},
		{	_INDEX_VISIBLE,					(u32)&iObj_set_visible,				(u32)&iObj_get_visible					},
		{	_INDEX_VIEWPORTHEIGHT,			(u32)&iObj_set_viewPortHeight,		(u32)&iObj_get_viewPortHeight			},
		{	_INDEX_VIEWPORTLEFT,			(u32)&iObj_set_viewPortLeft,		(u32)&iObj_get_viewPortLeft				},
		{	_INDEX_VIEWPORTTOP,				(u32)&iObj_set_viewPortTop,			(u32)&iObj_get_viewPortTop				},
		{	_INDEX_VIEWPORTWIDTH,			(u32)&iObj_set_viewPortWidth,		(u32)&iObj_get_viewPortWidth			},
		{	_INDEX_WHATSTHISHELPID,			(u32)&iObj_set_whatsThisHelpID,		(u32)&iObj_get_whatsThisHelpID			},
		{	_INDEX_WHATSTHISHELP,			(u32)&iObj_set_whatsThisHelp,		(u32)&iObj_get_whatsThisHelp			},
		{	_INDEX_WHATSTHISBUTTON,			(u32)&iObj_set_whatsThisButton,		(u32)&iObj_get_whatsThisButton			},
		{	_INDEX_WIDTH,					(u32)&iObj_set_width,				(u32)&iObj_get_width					},
		{	_INDEX_ZOOMBOX,					(u32)&iObj_set_zoomBox,				(u32)&iObj_get_zoomBox					},
		{	0,								0,									0										}
	};

	SPropertyMap gcProps_formset[] =
	{
		{	_INDEX_ACTIVEFORM,				(u32)&iObj_set_activeForm,			(u32)&iObj_get_activeForm				},
		{	_INDEX_AUTORELEASE,				(u32)&iObj_set_autoRelease,			(u32)&iObj_get_autoRelease				},
		{	_INDEX_BUFFERMODE,				(u32)&iObj_set_bufferMode,			(u32)&iObj_get_bufferMode				},
		{	_INDEX_DATASESSION,				(u32)&iObj_set_dataSession,			(u32)&iObj_get_dataSession				},
		{	_INDEX_DATASESSIONID,			(u32)&iObj_set_dataSessionID,		(u32)&iObj_get_dataSessionID			},
		{	_INDEX_DATAENVIRONMENT,			(u32)&iObj_set_dataEnvironment,		(u32)&iObj_get_dataEnvironment			},
		{	_INDEX_APPLICATION,				(u32)&iObj_set_application,			(u32)&iObj_get_application				},
		{	_INDEX_BASECLASS,				(u32)&iObj_set_baseClass,			(u32)&iObj_get_baseClass				},
		{	_INDEX_CLASS,					(u32)&iObj_set_class,				(u32)&iObj_get_class					},
		{	_INDEX_CLASSLIBRARY,			(u32)&iObj_set_classLibrary,		(u32)&iObj_get_classLibrary				},
		{	_INDEX_FORMS,					(u32)&iObj_set_forms,				(u32)&iObj_get_forms					},
		{	_INDEX_FORMCOUNT,				(u32)&iObj_set_formCount,			(u32)&iObj_get_formCount				},
		{	_INDEX_OBJECTS,					(u32)&iObj_set_objects,				(u32)&iObj_get_objects					},
		{	_INDEX_COMMENT,					(u32)&iObj_set_comment,				(u32)&iObj_get_comment					},
		{	_INDEX_NAME,					(u32)&iObj_set_name,				(u32)&iObj_get_name						},
		{	_INDEX_PARENT,					(u32)&iObj_set_parent,				(u32)&iObj_get_parent					},
		{	_INDEX_PARENTCLASS,				(u32)&iObj_set_parentClass,			(u32)&iObj_get_parentClass				},
		{	_INDEX_READBACKCOLOR,			(u32)&iObj_set_readBackColor,		(u32)&iObj_get_readBackColor			},
		{	_INDEX_READCYCLE,				(u32)&iObj_set_readCycle,			(u32)&iObj_get_readCycle				},
		{	_INDEX_READFORECOLOR,			(u32)&iObj_set_readForeColor,		(u32)&iObj_get_readForeColor			},
		{	_INDEX_READLOCK,				(u32)&iObj_set_readLock,			(u32)&iObj_get_readLock					},
		{	_INDEX_READMOUSE,				(u32)&iObj_set_readMouse,			(u32)&iObj_get_readMouse				},
		{	_INDEX_READSAVE,				(u32)&iObj_set_readSave,			(u32)&iObj_get_readSave					},
		{	_INDEX_READTIMEOUT,				(u32)&iObj_set_readTimeOut,			(u32)&iObj_get_readTimeOut				},
		{	_INDEX_TAG,						(u32)&iObj_set_tag,					(u32)&iObj_get_tag						},
		{	_INDEX_VISIBLE,					(u32)&iObj_set_visible,				(u32)&iObj_get_visible					},
		{	_INDEX_WINDOWLIST,				(u32)&iObj_set_windowList,			(u32)&iObj_get_windowList				},
		{	_INDEX_WINDOWTYPE,				(u32)&iObj_set_windowType,			(u32)&iObj_get_windowType				},
		{	0,								0,									0										}
	};

	SPropertyMap gcProps_toolbar[] =
	{
		{	_INDEX_ACTIVECONTROL,			(u32)&iObj_set_activeControl,		(u32)&iObj_get_activeControl			},
		{	_INDEX_CONTROLBOX,				(u32)&iObj_set_controlBox,			(u32)&iObj_get_controlBox				},
		{	_INDEX_DATASESSION,				(u32)&iObj_set_dataSession,			(u32)&iObj_get_dataSession				},
		{	_INDEX_DATASESSIONID,			(u32)&iObj_set_dataSessionID,		(u32)&iObj_get_dataSessionID			},
		{	_INDEX_DOCKPOSITION,			(u32)&iObj_set_dockPosition,		(u32)&iObj_get_dockPosition				},
		{	_INDEX_DOCKED,					(u32)&iObj_set_docked,				(u32)&iObj_get_docked					},
		{	_INDEX_MOVABLE,					(u32)&iObj_set_movable,				(u32)&iObj_get_movable					},
		{	_INDEX_SCALEMODE,				(u32)&iObj_set_scaleMode,			(u32)&iObj_get_scaleMode				},
		{	_INDEX_SHOWTIPS,				(u32)&iObj_set_showTips,			(u32)&iObj_get_showTips					},
		{	_INDEX_SHOWWINDOW,				(u32)&iObj_set_showWindow,			(u32)&iObj_get_showWindow				},
		{	_INDEX_APPLICATION,				(u32)&iObj_set_application,			(u32)&iObj_get_application				},
		{	_INDEX_BASECLASS,				(u32)&iObj_set_baseClass,			(u32)&iObj_get_baseClass				},
		{	_INDEX_CLASS,					(u32)&iObj_set_class,				(u32)&iObj_get_class					},
		{	_INDEX_CLASSLIBRARY,			(u32)&iObj_set_classLibrary,		(u32)&iObj_get_classLibrary				},
		{	_INDEX_CONTROLS,				(u32)&iObj_set_controls,			(u32)&iObj_get_controls					},
		{	_INDEX_CONTROLCOUNT,			(u32)&iObj_set_controlCount,		(u32)&iObj_get_controlCount				},
		{	_INDEX_OBJECTS,					(u32)&iObj_set_objects,				(u32)&iObj_get_objects					},
		{	_INDEX_CAPTION,					(u32)&iObj_set_caption,				(u32)&iObj_get_caption					},
		{	_INDEX_COLORSOURCE,				(u32)&iObj_set_colorSource,			(u32)&iObj_get_colorSource				},
		{	_INDEX_FORECOLOR,				(u32)&iObj_set_foreColor,			(u32)&iObj_get_foreColor				},
		{	_INDEX_BACKCOLOR,				(u32)&iObj_set_backColor,			(u32)&iObj_get_backColor				},
		{	_INDEX_COMMENT,					(u32)&iObj_set_comment,				(u32)&iObj_get_comment					},
		{	_INDEX_ENABLED,					(u32)&iObj_set_enabled,				(u32)&iObj_get_enabled					},
		{	_INDEX_HEIGHT,					(u32)&iObj_set_height,				(u32)&iObj_get_height					},
		{	_INDEX_HELPCONTEXTID,			(u32)&iObj_set_helpContextID,		(u32)&iObj_get_helpContextID			},
		{	_INDEX_HWND,					(u32)&iObj_set_hWnd,				(u32)&iObj_get_hWnd						},
		{	_INDEX_KEYPREVIEW,				(u32)&iObj_set_keyPreview,			(u32)&iObj_get_keyPreview				},
		{	_INDEX_LEFT,					(u32)&iObj_set_left,				(u32)&iObj_get_left						},
		{	_INDEX_LOCKSCREEN,				(u32)&iObj_set_lockScreen,			(u32)&iObj_get_lockScreen				},
		{	_INDEX_MOUSEICON,				(u32)&iObj_set_mouseIcon,			(u32)&iObj_get_mouseIcon				},
		{	_INDEX_MOUSEPOINTER,			(u32)&iObj_set_mousePointer,		(u32)&iObj_get_mousePointer				},
		{	_INDEX_NAME,					(u32)&iObj_set_name,				(u32)&iObj_get_name						},
		{	_INDEX_OLEDRAGMODE,				(u32)&iObj_set_oLEDragMode,			(u32)&iObj_get_oLEDragMode				},
		{	_INDEX_OLEDRAGPICTURE,			(u32)&iObj_set_oLEDragPicture,		(u32)&iObj_get_oLEDragPicture			},
		{	_INDEX_OLEDROPEFFECTS,			(u32)&iObj_set_oLEDropEffects,		(u32)&iObj_get_oLEDropEffects			},
		{	_INDEX_OLEDROPHASDATA,			(u32)&iObj_set_oLEDropHasData,		(u32)&iObj_get_oLEDropHasData			},
		{	_INDEX_OLEDROPMODE,				(u32)&iObj_set_oLEDropMode,			(u32)&iObj_get_oLEDropMode				},
		{	_INDEX_PARENT,					(u32)&iObj_set_parent,				(u32)&iObj_get_parent					},
		{	_INDEX_PARENTCLASS,				(u32)&iObj_set_parentClass,			(u32)&iObj_get_parentClass				},
		{	_INDEX_SIZABLE,					(u32)&iObj_set_sizable,				(u32)&iObj_get_sizable					},
		{	_INDEX_TAG,						(u32)&iObj_set_tag,					(u32)&iObj_get_tag						},
		{	_INDEX_THEMES,					(u32)&iObj_set_themes,				(u32)&iObj_get_themes					},
		{	_INDEX_TOP,						(u32)&iObj_set_top,					(u32)&iObj_get_top						},
		{	_INDEX_VISIBLE,					(u32)&iObj_set_visible,				(u32)&iObj_get_visible					},
		{	_INDEX_WHATSTHISHELPID,			(u32)&iObj_set_whatsThisHelpID,		(u32)&iObj_get_whatsThisHelpID			},
		{	_INDEX_WIDTH,					(u32)&iObj_set_width,				(u32)&iObj_get_width					},
		{	0,								0,									0										}
	};

	SPropertyMap gcProps_separator[] =
	{
		{	_INDEX_APPLICATION,				(u32)&iObj_set_application,			(u32)&iObj_get_application				},
		{	_INDEX_BASECLASS,				(u32)&iObj_set_baseClass,			(u32)&iObj_get_baseClass				},
		{	_INDEX_CLASS,					(u32)&iObj_set_class,				(u32)&iObj_get_class					},
		{	_INDEX_CLASSLIBRARY,			(u32)&iObj_set_classLibrary,		(u32)&iObj_get_classLibrary				},
		{	_INDEX_COMMENT,					(u32)&iObj_set_comment,				(u32)&iObj_get_comment					},
		{	_INDEX_ENABLED,					(u32)&iObj_set_enabled,				(u32)&iObj_get_enabled					},
		{	_INDEX_NAME,					(u32)&iObj_set_name,				(u32)&iObj_get_name						},
		{	_INDEX_PARENT,					(u32)&iObj_set_parent,				(u32)&iObj_get_parent					},
		{	_INDEX_PARENTCLASS,				(u32)&iObj_set_parentClass,			(u32)&iObj_get_parentClass				},
		{	_INDEX_STYLE,					(u32)&iObj_set_style,				(u32)&iObj_get_style					},
		{	_INDEX_TAG,						(u32)&iObj_set_tag,					(u32)&iObj_get_tag						},
		{	_INDEX_VISIBLE,					(u32)&iObj_set_visible,				(u32)&iObj_get_visible					},
		{	0,								0,									0										}
	};

	SPropertyMap gcProps_line[] =
	{
		{	_INDEX_ANCHOR,					(u32)&iObj_set_anchor,				(u32)&iObj_get_anchor					},
		{	_INDEX_APPLICATION,				(u32)&iObj_set_application,			(u32)&iObj_get_application				},
		{	_INDEX_BASECLASS,				(u32)&iObj_set_baseClass,			(u32)&iObj_get_baseClass				},
		{	_INDEX_CLASS,					(u32)&iObj_set_class,				(u32)&iObj_get_class					},
		{	_INDEX_CLASSLIBRARY,			(u32)&iObj_set_classLibrary,		(u32)&iObj_get_classLibrary				},
		{	_INDEX_BORDERCOLOR,				(u32)&iObj_set_borderColor,			(u32)&iObj_get_borderColor				},
		{	_INDEX_BORDERWIDTH,				(u32)&iObj_set_borderWidth,			(u32)&iObj_get_borderWidth				},
		{	_INDEX_BORDERSTYLE,				(u32)&iObj_set_borderStyle,			(u32)&iObj_get_borderStyle				},
		{	_INDEX_COLORSOURCE,				(u32)&iObj_set_colorSource,			(u32)&iObj_get_colorSource				},
		{	_INDEX_COMMENT,					(u32)&iObj_set_comment,				(u32)&iObj_get_comment					},
		{	_INDEX_DRAGICON,				(u32)&iObj_set_dragIcon,			(u32)&iObj_get_dragIcon					},
		{	_INDEX_DRAGMODE,				(u32)&iObj_set_dragMode,			(u32)&iObj_get_dragMode					},
		{	_INDEX_DRAWMODE,				(u32)&iObj_set_drawMode,			(u32)&iObj_get_drawMode					},
		{	_INDEX_ENABLED,					(u32)&iObj_set_enabled,				(u32)&iObj_get_enabled					},
		{	_INDEX_HEIGHT,					(u32)&iObj_set_height,				(u32)&iObj_get_height					},
		{	_INDEX_HELPCONTEXTID,			(u32)&iObj_set_helpContextID,		(u32)&iObj_get_helpContextID			},
		{	_INDEX_LEFT,					(u32)&iObj_set_left,				(u32)&iObj_get_left						},
		{	_INDEX_LINESLANT,				(u32)&iObj_set_lineSlant,			(u32)&iObj_get_lineSlant				},
		{	_INDEX_MOUSEPOINTER,			(u32)&iObj_set_mousePointer,		(u32)&iObj_get_mousePointer				},
		{	_INDEX_NAME,					(u32)&iObj_set_name,				(u32)&iObj_get_name						},
		{	_INDEX_OLEDRAGMODE,				(u32)&iObj_set_oLEDragMode,			(u32)&iObj_get_oLEDragMode				},
		{	_INDEX_OLEDRAGPICTURE,			(u32)&iObj_set_oLEDragPicture,		(u32)&iObj_get_oLEDragPicture			},
		{	_INDEX_OLEDROPEFFECTS,			(u32)&iObj_set_oLEDropEffects,		(u32)&iObj_get_oLEDropEffects			},
		{	_INDEX_OLEDROPHASDATA,			(u32)&iObj_set_oLEDropHasData,		(u32)&iObj_get_oLEDropHasData			},
		{	_INDEX_OLEDROPMODE,				(u32)&iObj_set_oLEDropMode,			(u32)&iObj_get_oLEDropMode				},
		{	_INDEX_PARENT,					(u32)&iObj_set_parent,				(u32)&iObj_get_parent					},
		{	_INDEX_PARENTCLASS,				(u32)&iObj_set_parentClass,			(u32)&iObj_get_parentClass				},
		{	_INDEX_POLYPOINTS,				(u32)&iObj_set_polyPoints,			(u32)&iObj_get_polyPoints				},
		{	_INDEX_ROTATION,				(u32)&iObj_set_rotation,			(u32)&iObj_get_rotation					},
		{	_INDEX_STATUSBARTEXT,			(u32)&iObj_set_statusBarText,		(u32)&iObj_get_statusBarText			},
		{	_INDEX_TAG,						(u32)&iObj_set_tag,					(u32)&iObj_get_tag						},
		{	_INDEX_TOOLTIPTEXT,				(u32)&iObj_set_toolTipText,			(u32)&iObj_get_toolTipText				},
		{	_INDEX_TOP,						(u32)&iObj_set_top,					(u32)&iObj_get_top						},
		{	_INDEX_VISIBLE,					(u32)&iObj_set_visible,				(u32)&iObj_get_visible					},
		{	_INDEX_WHATSTHISHELPID,			(u32)&iObj_set_whatsThisHelpID,		(u32)&iObj_get_whatsThisHelpID			},
		{	_INDEX_WIDTH,					(u32)&iObj_set_width,				(u32)&iObj_get_width					},
		{	0,								0,									0										}
	};

	SPropertyMap gcProps_shape[] =
	{
		{	_INDEX_FILLCOLOR,				(u32)&iObj_set_fillColor,			(u32)&iObj_get_fillColor				},
		{	_INDEX_FILLSTYLE,				(u32)&iObj_set_fillStyle,			(u32)&iObj_get_fillStyle				},
		{	_INDEX_ANCHOR,					(u32)&iObj_set_anchor,				(u32)&iObj_get_anchor					},
		{	_INDEX_APPLICATION,				(u32)&iObj_set_application,			(u32)&iObj_get_application				},
		{	_INDEX_BACKSTYLE,				(u32)&iObj_set_backStyle,			(u32)&iObj_get_backStyle				},
		{	_INDEX_BASECLASS,				(u32)&iObj_set_baseClass,			(u32)&iObj_get_baseClass				},
		{	_INDEX_CLASS,					(u32)&iObj_set_class,				(u32)&iObj_get_class					},
		{	_INDEX_CLASSLIBRARY,			(u32)&iObj_set_classLibrary,		(u32)&iObj_get_classLibrary				},
		{	_INDEX_BORDERCOLOR,				(u32)&iObj_set_borderColor,			(u32)&iObj_get_borderColor				},
		{	_INDEX_BORDERWIDTH,				(u32)&iObj_set_borderWidth,			(u32)&iObj_get_borderWidth				},
		{	_INDEX_BORDERSTYLE,				(u32)&iObj_set_borderStyle,			(u32)&iObj_get_borderStyle				},
		{	_INDEX_CURVATURE,				(u32)&iObj_set_curvature,			(u32)&iObj_get_curvature				},
		{	_INDEX_COLORSCHEME,				(u32)&iObj_set_colorScheme,			(u32)&iObj_get_colorScheme				},
		{	_INDEX_COLORSOURCE,				(u32)&iObj_set_colorSource,			(u32)&iObj_get_colorSource				},
		{	_INDEX_BACKCOLOR,				(u32)&iObj_set_backColor,			(u32)&iObj_get_backColor				},
		{	_INDEX_COMMENT,					(u32)&iObj_set_comment,				(u32)&iObj_get_comment					},
		{	_INDEX_DRAGICON,				(u32)&iObj_set_dragIcon,			(u32)&iObj_get_dragIcon					},
		{	_INDEX_DRAGMODE,				(u32)&iObj_set_dragMode,			(u32)&iObj_get_dragMode					},
		{	_INDEX_DRAWMODE,				(u32)&iObj_set_drawMode,			(u32)&iObj_get_drawMode					},
		{	_INDEX_ENABLED,					(u32)&iObj_set_enabled,				(u32)&iObj_get_enabled					},
		{	_INDEX_HEIGHT,					(u32)&iObj_set_height,				(u32)&iObj_get_height					},
		{	_INDEX_HELPCONTEXTID,			(u32)&iObj_set_helpContextID,		(u32)&iObj_get_helpContextID			},
		{	_INDEX_LEFT,					(u32)&iObj_set_left,				(u32)&iObj_get_left						},
		{	_INDEX_MOUSEICON,				(u32)&iObj_set_mouseIcon,			(u32)&iObj_get_mouseIcon				},
		{	_INDEX_MOUSEPOINTER,			(u32)&iObj_set_mousePointer,		(u32)&iObj_get_mousePointer				},
		{	_INDEX_NAME,					(u32)&iObj_set_name,				(u32)&iObj_get_name						},
		{	_INDEX_OLEDRAGMODE,				(u32)&iObj_set_oLEDragMode,			(u32)&iObj_get_oLEDragMode				},
		{	_INDEX_OLEDRAGPICTURE,			(u32)&iObj_set_oLEDragPicture,		(u32)&iObj_get_oLEDragPicture			},
		{	_INDEX_OLEDROPEFFECTS,			(u32)&iObj_set_oLEDropEffects,		(u32)&iObj_get_oLEDropEffects			},
		{	_INDEX_OLEDROPHASDATA,			(u32)&iObj_set_oLEDropHasData,		(u32)&iObj_get_oLEDropHasData			},
		{	_INDEX_OLEDROPMODE,				(u32)&iObj_set_oLEDropMode,			(u32)&iObj_get_oLEDropMode				},
		{	_INDEX_PARENT,					(u32)&iObj_set_parent,				(u32)&iObj_get_parent					},
		{	_INDEX_PARENTCLASS,				(u32)&iObj_set_parentClass,			(u32)&iObj_get_parentClass				},
		{	_INDEX_POLYPOINTS,				(u32)&iObj_set_polyPoints,			(u32)&iObj_get_polyPoints				},
		{	_INDEX_ROTATION,				(u32)&iObj_set_rotation,			(u32)&iObj_get_rotation					},
		{	_INDEX_SPECIALEFFECT,			(u32)&iObj_set_specialEffect,		(u32)&iObj_get_specialEffect			},
		{	_INDEX_TAG,						(u32)&iObj_set_tag,					(u32)&iObj_get_tag						},
		{	_INDEX_TOOLTIPTEXT,				(u32)&iObj_set_toolTipText,			(u32)&iObj_get_toolTipText				},
		{	_INDEX_TOP,						(u32)&iObj_set_top,					(u32)&iObj_get_top						},
		{	_INDEX_VISIBLE,					(u32)&iObj_set_visible,				(u32)&iObj_get_visible					},
		{	_INDEX_WHATSTHISHELPID,			(u32)&iObj_set_whatsThisHelpID,		(u32)&iObj_get_whatsThisHelpID			},
		{	_INDEX_WIDTH,					(u32)&iObj_set_width,				(u32)&iObj_get_width					},
		{	0,								0,									0										}
	};

	SPropertyMap gcProps_image[] =
	{
		{	_INDEX_ANCHOR,					(u32)&iObj_set_anchor,				(u32)&iObj_get_anchor					},
		{	_INDEX_APPLICATION,				(u32)&iObj_set_application,			(u32)&iObj_get_application				},
		{	_INDEX_BACKSTYLE,				(u32)&iObj_set_backStyle,			(u32)&iObj_get_backStyle				},
		{	_INDEX_BASECLASS,				(u32)&iObj_set_baseClass,			(u32)&iObj_get_baseClass				},
		{	_INDEX_CLASS,					(u32)&iObj_set_class,				(u32)&iObj_get_class					},
		{	_INDEX_CLASSLIBRARY,			(u32)&iObj_set_classLibrary,		(u32)&iObj_get_classLibrary				},
		{	_INDEX_BORDERCOLOR,				(u32)&iObj_set_borderColor,			(u32)&iObj_get_borderColor				},
		{	_INDEX_BORDERSTYLE,				(u32)&iObj_set_borderStyle,			(u32)&iObj_get_borderStyle				},
		{	_INDEX_COLORSOURCE,				(u32)&iObj_set_colorSource,			(u32)&iObj_get_colorSource				},
		{	_INDEX_COMMENT,					(u32)&iObj_set_comment,				(u32)&iObj_get_comment					},
		{	_INDEX_DRAGICON,				(u32)&iObj_set_dragIcon,			(u32)&iObj_get_dragIcon					},
		{	_INDEX_DRAGMODE,				(u32)&iObj_set_dragMode,			(u32)&iObj_get_dragMode					},
		{	_INDEX_ENABLED,					(u32)&iObj_set_enabled,				(u32)&iObj_get_enabled					},
		{	_INDEX_HEIGHT,					(u32)&iObj_set_height,				(u32)&iObj_get_height					},
		{	_INDEX_HELPCONTEXTID,			(u32)&iObj_set_helpContextID,		(u32)&iObj_get_helpContextID			},
		{	_INDEX_LEFT,					(u32)&iObj_set_left,				(u32)&iObj_get_left						},
		{	_INDEX_MOUSEPOINTER,			(u32)&iObj_set_mousePointer,		(u32)&iObj_get_mousePointer				},
		{	_INDEX_NAME,					(u32)&iObj_set_name,				(u32)&iObj_get_name						},
		{	_INDEX_OLEDRAGMODE,				(u32)&iObj_set_oLEDragMode,			(u32)&iObj_get_oLEDragMode				},
		{	_INDEX_OLEDRAGPICTURE,			(u32)&iObj_set_oLEDragPicture,		(u32)&iObj_get_oLEDragPicture			},
		{	_INDEX_OLEDROPEFFECTS,			(u32)&iObj_set_oLEDropEffects,		(u32)&iObj_get_oLEDropEffects			},
		{	_INDEX_OLEDROPHASDATA,			(u32)&iObj_set_oLEDropHasData,		(u32)&iObj_get_oLEDropHasData			},
		{	_INDEX_OLEDROPMODE,				(u32)&iObj_set_oLEDropMode,			(u32)&iObj_get_oLEDropMode				},
		{	_INDEX_PARENT,					(u32)&iObj_set_parent,				(u32)&iObj_get_parent					},
		{	_INDEX_PARENTCLASS,				(u32)&iObj_set_parentClass,			(u32)&iObj_get_parentClass				},
		{	_INDEX_PICTURE,					(u32)&iObj_set_picture,				(u32)&iObj_get_picture					},
		{	_INDEX_PICTUREVAL,				(u32)&iObj_set_pictureVal,			(u32)&iObj_get_pictureVal				},
		{	_INDEX_ROTATEFLIP,				(u32)&iObj_set_rotateFlip,			(u32)&iObj_get_rotateFlip				},
		{	_INDEX_STRETCH,					(u32)&iObj_set_stretch,				(u32)&iObj_get_stretch					},
		{	_INDEX_STATUSBARTEXT,			(u32)&iObj_set_statusBarText,		(u32)&iObj_get_statusBarText			},
		{	_INDEX_TAG,						(u32)&iObj_set_tag,					(u32)&iObj_get_tag						},
		{	_INDEX_THEMES,					(u32)&iObj_set_themes,				(u32)&iObj_get_themes					},
		{	_INDEX_TOOLTIPTEXT,				(u32)&iObj_set_toolTipText,			(u32)&iObj_get_toolTipText				},
		{	_INDEX_TOP,						(u32)&iObj_set_top,					(u32)&iObj_get_top						},
		{	_INDEX_VISIBLE,					(u32)&iObj_set_visible,				(u32)&iObj_get_visible					},
		{	_INDEX_WHATSTHISHELPID,			(u32)&iObj_set_whatsThisHelpID,		(u32)&iObj_get_whatsThisHelpID			},
		{	_INDEX_WIDTH,					(u32)&iObj_set_width,				(u32)&iObj_get_width					},
		{	0,								0,									0										}
	};

	SPropertyMap gcProps_container[] =
	{
		{	_INDEX_ACTIVECONTROL,			(u32)&iObj_set_activeControl,		(u32)&iObj_get_activeControl			},
		{	_INDEX_ANCHOR,					(u32)&iObj_set_anchor,				(u32)&iObj_get_anchor					},
		{	_INDEX_APPLICATION,				(u32)&iObj_set_application,			(u32)&iObj_get_application				},
		{	_INDEX_BACKSTYLE,				(u32)&iObj_set_backStyle,			(u32)&iObj_get_backStyle				},
		{	_INDEX_BASECLASS,				(u32)&iObj_set_baseClass,			(u32)&iObj_get_baseClass				},
		{	_INDEX_CLASS,					(u32)&iObj_set_class,				(u32)&iObj_get_class					},
		{	_INDEX_CLASSLIBRARY,			(u32)&iObj_set_classLibrary,		(u32)&iObj_get_classLibrary				},
		{	_INDEX_CONTROLS,				(u32)&iObj_set_controls,			(u32)&iObj_get_controls					},
		{	_INDEX_CONTROLCOUNT,			(u32)&iObj_set_controlCount,		(u32)&iObj_get_controlCount				},
		{	_INDEX_OBJECTS,					(u32)&iObj_set_objects,				(u32)&iObj_get_objects					},
		{	_INDEX_BORDERCOLOR,				(u32)&iObj_set_borderColor,			(u32)&iObj_get_borderColor				},
		{	_INDEX_BORDERWIDTH,				(u32)&iObj_set_borderWidth,			(u32)&iObj_get_borderWidth				},
		{	_INDEX_COLORSOURCE,				(u32)&iObj_set_colorSource,			(u32)&iObj_get_colorSource				},
		{	_INDEX_FORECOLOR,				(u32)&iObj_set_foreColor,			(u32)&iObj_get_foreColor				},
		{	_INDEX_BACKCOLOR,				(u32)&iObj_set_backColor,			(u32)&iObj_get_backColor				},
		{	_INDEX_COMMENT,					(u32)&iObj_set_comment,				(u32)&iObj_get_comment					},
		{	_INDEX_DRAGICON,				(u32)&iObj_set_dragIcon,			(u32)&iObj_get_dragIcon					},
		{	_INDEX_DRAGMODE,				(u32)&iObj_set_dragMode,			(u32)&iObj_get_dragMode					},
		{	_INDEX_ENABLED,					(u32)&iObj_set_enabled,				(u32)&iObj_get_enabled					},
		{	_INDEX_HEIGHT,					(u32)&iObj_set_height,				(u32)&iObj_get_height					},
		{	_INDEX_HELPCONTEXTID,			(u32)&iObj_set_helpContextID,		(u32)&iObj_get_helpContextID			},
		{	_INDEX_LEFT,					(u32)&iObj_set_left,				(u32)&iObj_get_left						},
		{	_INDEX_MOUSEICON,				(u32)&iObj_set_mouseIcon,			(u32)&iObj_get_mouseIcon				},
		{	_INDEX_MOUSEPOINTER,			(u32)&iObj_set_mousePointer,		(u32)&iObj_get_mousePointer				},
		{	_INDEX_NAME,					(u32)&iObj_set_name,				(u32)&iObj_get_name						},
		{	_INDEX_OLEDRAGMODE,				(u32)&iObj_set_oLEDragMode,			(u32)&iObj_get_oLEDragMode				},
		{	_INDEX_OLEDRAGPICTURE,			(u32)&iObj_set_oLEDragPicture,		(u32)&iObj_get_oLEDragPicture			},
		{	_INDEX_OLEDROPEFFECTS,			(u32)&iObj_set_oLEDropEffects,		(u32)&iObj_get_oLEDropEffects			},
		{	_INDEX_OLEDROPHASDATA,			(u32)&iObj_set_oLEDropHasData,		(u32)&iObj_get_oLEDropHasData			},
		{	_INDEX_OLEDROPMODE,				(u32)&iObj_set_oLEDropMode,			(u32)&iObj_get_oLEDropMode				},
		{	_INDEX_PARENT,					(u32)&iObj_set_parent,				(u32)&iObj_get_parent					},
		{	_INDEX_PARENTCLASS,				(u32)&iObj_set_parentClass,			(u32)&iObj_get_parentClass				},
		{	_INDEX_PICTURE,					(u32)&iObj_set_picture,				(u32)&iObj_get_picture					},
		{	_INDEX_SPECIALEFFECT,			(u32)&iObj_set_specialEffect,		(u32)&iObj_get_specialEffect			},
		{	_INDEX_STATUSBARTEXT,			(u32)&iObj_set_statusBarText,		(u32)&iObj_get_statusBarText			},
		{	_INDEX_TABINDEX,				(u32)&iObj_set_tabIndex,			(u32)&iObj_get_tabIndex					},
		{	_INDEX_TABSTOP,					(u32)&iObj_set_tabStop,				(u32)&iObj_get_tabStop					},
		{	_INDEX_TAG,						(u32)&iObj_set_tag,					(u32)&iObj_get_tag						},
		{	_INDEX_TOOLTIPTEXT,				(u32)&iObj_set_toolTipText,			(u32)&iObj_get_toolTipText				},
		{	_INDEX_TOP,						(u32)&iObj_set_top,					(u32)&iObj_get_top						},
		{	_INDEX_VISIBLE,					(u32)&iObj_set_visible,				(u32)&iObj_get_visible					},
		{	_INDEX_WHATSTHISHELPID,			(u32)&iObj_set_whatsThisHelpID,		(u32)&iObj_get_whatsThisHelpID			},
		{	_INDEX_WIDTH,					(u32)&iObj_set_width,				(u32)&iObj_get_width					},
		{	0,								0,									0										}
	};

	SPropertyMap gcProps_control[] =
	{
		{	_INDEX_ACTIVECONTROL,			(u32)&iObj_set_activeControl,		(u32)&iObj_get_activeControl			},
		{	_INDEX_ANCHOR,					(u32)&iObj_set_anchor,				(u32)&iObj_get_anchor					},
		{	_INDEX_APPLICATION,				(u32)&iObj_set_application,			(u32)&iObj_get_application				},
		{	_INDEX_BACKSTYLE,				(u32)&iObj_set_backStyle,			(u32)&iObj_get_backStyle				},
		{	_INDEX_BASECLASS,				(u32)&iObj_set_baseClass,			(u32)&iObj_get_baseClass				},
		{	_INDEX_CLASS,					(u32)&iObj_set_class,				(u32)&iObj_get_class					},
		{	_INDEX_CLASSLIBRARY,			(u32)&iObj_set_classLibrary,		(u32)&iObj_get_classLibrary				},
		{	_INDEX_CONTROLS,				(u32)&iObj_set_controls,			(u32)&iObj_get_controls					},
		{	_INDEX_CONTROLCOUNT,			(u32)&iObj_set_controlCount,		(u32)&iObj_get_controlCount				},
		{	_INDEX_OBJECTS,					(u32)&iObj_set_objects,				(u32)&iObj_get_objects					},
		{	_INDEX_BORDERCOLOR,				(u32)&iObj_set_borderColor,			(u32)&iObj_get_borderColor				},
		{	_INDEX_BORDERWIDTH,				(u32)&iObj_set_borderWidth,			(u32)&iObj_get_borderWidth				},
		{	_INDEX_COLORSOURCE,				(u32)&iObj_set_colorSource,			(u32)&iObj_get_colorSource				},
		{	_INDEX_FORECOLOR,				(u32)&iObj_set_foreColor,			(u32)&iObj_get_foreColor				},
		{	_INDEX_BACKCOLOR,				(u32)&iObj_set_backColor,			(u32)&iObj_get_backColor				},
		{	_INDEX_COMMENT,					(u32)&iObj_set_comment,				(u32)&iObj_get_comment					},
		{	_INDEX_DRAGICON,				(u32)&iObj_set_dragIcon,			(u32)&iObj_get_dragIcon					},
		{	_INDEX_DRAGMODE,				(u32)&iObj_set_dragMode,			(u32)&iObj_get_dragMode					},
		{	_INDEX_ENABLED,					(u32)&iObj_set_enabled,				(u32)&iObj_get_enabled					},
		{	_INDEX_HEIGHT,					(u32)&iObj_set_height,				(u32)&iObj_get_height					},
		{	_INDEX_HELPCONTEXTID,			(u32)&iObj_set_helpContextID,		(u32)&iObj_get_helpContextID			},
		{	_INDEX_LEFT,					(u32)&iObj_set_left,				(u32)&iObj_get_left						},
		{	_INDEX_MOUSEICON,				(u32)&iObj_set_mouseIcon,			(u32)&iObj_get_mouseIcon				},
		{	_INDEX_MOUSEPOINTER,			(u32)&iObj_set_mousePointer,		(u32)&iObj_get_mousePointer				},
		{	_INDEX_NAME,					(u32)&iObj_set_name,				(u32)&iObj_get_name						},
		{	_INDEX_OLEDRAGMODE,				(u32)&iObj_set_oLEDragMode,			(u32)&iObj_get_oLEDragMode				},
		{	_INDEX_OLEDRAGPICTURE,			(u32)&iObj_set_oLEDragPicture,		(u32)&iObj_get_oLEDragPicture			},
		{	_INDEX_OLEDROPEFFECTS,			(u32)&iObj_set_oLEDropEffects,		(u32)&iObj_get_oLEDropEffects			},
		{	_INDEX_OLEDROPHASDATA,			(u32)&iObj_set_oLEDropHasData,		(u32)&iObj_get_oLEDropHasData			},
		{	_INDEX_OLEDROPMODE,				(u32)&iObj_set_oLEDropMode,			(u32)&iObj_get_oLEDropMode				},
		{	_INDEX_PARENT,					(u32)&iObj_set_parent,				(u32)&iObj_get_parent					},
		{	_INDEX_PARENTCLASS,				(u32)&iObj_set_parentClass,			(u32)&iObj_get_parentClass				},
		{	_INDEX_PICTURE,					(u32)&iObj_set_picture,				(u32)&iObj_get_picture					},
		{	_INDEX_SPECIALEFFECT,			(u32)&iObj_set_specialEffect,		(u32)&iObj_get_specialEffect			},
		{	_INDEX_STATUSBARTEXT,			(u32)&iObj_set_statusBarText,		(u32)&iObj_get_statusBarText			},
		{	_INDEX_TABINDEX,				(u32)&iObj_set_tabIndex,			(u32)&iObj_get_tabIndex					},
		{	_INDEX_TABSTOP,					(u32)&iObj_set_tabStop,				(u32)&iObj_get_tabStop					},
		{	_INDEX_TAG,						(u32)&iObj_set_tag,					(u32)&iObj_get_tag						},
		{	_INDEX_TOOLTIPTEXT,				(u32)&iObj_set_toolTipText,			(u32)&iObj_get_toolTipText				},
		{	_INDEX_TOP,						(u32)&iObj_set_top,					(u32)&iObj_get_top						},
		{	_INDEX_VISIBLE,					(u32)&iObj_set_visible,				(u32)&iObj_get_visible					},
		{	_INDEX_WHATSTHISHELPID,			(u32)&iObj_set_whatsThisHelpID,		(u32)&iObj_get_whatsThisHelpID			},
		{	_INDEX_WIDTH,					(u32)&iObj_set_width,				(u32)&iObj_get_width					},
		{	0,								0,									0										}
	};

	SPropertyMap gcProps_grid[] =
	{
		{	_INDEX_ACTIVECOLUMN,			(u32)&iObj_set_activeColumn,		(u32)&iObj_get_activeColumn				},
		{	_INDEX_ACTIVEROW,				(u32)&iObj_set_activeRow,			(u32)&iObj_get_activeRow				},
		{	_INDEX_ALLOWADDNEW,				(u32)&iObj_set_allowAddNew,			(u32)&iObj_get_allowAddNew				},
		{	_INDEX_ALLOWAUTOCOLUMNFIT,		(u32)&iObj_set_allowAutoColumnFit,	(u32)&iObj_get_allowAutoColumnFit		},
		{	_INDEX_ALLOWCELLSELECTION,		(u32)&iObj_set_allowCellSelection,	(u32)&iObj_get_allowCellSelection		},
		{	_INDEX_ALLOWHEADERSIZING,		(u32)&iObj_set_allowHeaderSizing,	(u32)&iObj_get_allowHeaderSizing		},
		{	_INDEX_ALLOWROWSIZING,			(u32)&iObj_set_allowRowSizing,		(u32)&iObj_get_allowRowSizing			},
		{	_INDEX_GRIDLINECOLOR,			(u32)&iObj_set_gridLineColor,		(u32)&iObj_get_gridLineColor			},
		{	_INDEX_GRIDLINES,				(u32)&iObj_set_gridLines,			(u32)&iObj_get_gridLines				},
		{	_INDEX_GRIDLINEWIDTH,			(u32)&iObj_set_gridLineWidth,		(u32)&iObj_get_gridLineWidth			},
		{	_INDEX_HEADERHEIGHT,			(u32)&iObj_set_headerHeight,		(u32)&iObj_get_headerHeight				},
		{	_INDEX_HIGHLIGHT,				(u32)&iObj_set_highLight,			(u32)&iObj_get_highLight				},
		{	_INDEX_HIGHLIGHTBACKCOLOR,		(u32)&iObj_set_highlightBackColor,	(u32)&iObj_get_highlightBackColor		},
		{	_INDEX_HIGHLIGHTFORECOLOR,		(u32)&iObj_set_highlightForeColor,	(u32)&iObj_get_highlightForeColor		},
		{	_INDEX_HIGHLIGHTSTYLE,			(u32)&iObj_set_highlightStyle,		(u32)&iObj_get_highlightStyle			},
		{	_INDEX_HIGHLIGHTROW,			(u32)&iObj_set_highLightRow,		(u32)&iObj_get_highLightRow				},
		{	_INDEX_HIGHLIGHTROWLINEWIDTH,	(u32)&iObj_set_highlightRowLineWidth,	 (u32)&iObj_get_highlightRowLineWidth	},
		{	_INDEX_LEFTCOLUMN,				(u32)&iObj_set_leftColumn,			(u32)&iObj_get_leftColumn				},
		{	_INDEX_LINKMASTER,				(u32)&iObj_set_linkMaster,			(u32)&iObj_get_linkMaster				},
		{	_INDEX_CHILDORDER,				(u32)&iObj_set_childOrder,			(u32)&iObj_get_childOrder				},
		{	_INDEX_LOCKCOLUMNS,				(u32)&iObj_set_lockColumns,			(u32)&iObj_get_lockColumns				},
		{	_INDEX_LOCKCOLUMNSLEFT,			(u32)&iObj_set_lockColumnsLeft,		(u32)&iObj_get_lockColumnsLeft			},
		{	_INDEX_MEMBERCLASS,				(u32)&iObj_set_memberClass,			(u32)&iObj_get_memberClass				},
		{	_INDEX_MEMBERCLASSLIBRARY,		(u32)&iObj_set_memberClassLibrary,	(u32)&iObj_get_memberClassLibrary		},
		{	_INDEX_OPTIMIZE,				(u32)&iObj_set_optimize,			(u32)&iObj_get_optimize					},
		{	_INDEX_PARTITION,				(u32)&iObj_set_partition,			(u32)&iObj_get_partition				},
		{	_INDEX_PANELLINK,				(u32)&iObj_set_panelLink,			(u32)&iObj_get_panelLink				},
		{	_INDEX_PANEL,					(u32)&iObj_set_panel,				(u32)&iObj_get_panel					},
		{	_INDEX_SPLITBAR,				(u32)&iObj_set_splitBar,			(u32)&iObj_get_splitBar					},
		{	_INDEX_DELETEMARK,				(u32)&iObj_set_deleteMark,			(u32)&iObj_get_deleteMark				},
		{	_INDEX_RECORDMARK,				(u32)&iObj_set_recordMark,			(u32)&iObj_get_recordMark				},
		{	_INDEX_RELATIVECOLUMN,			(u32)&iObj_set_relativeColumn,		(u32)&iObj_get_relativeColumn			},
		{	_INDEX_RELATIVEROW,				(u32)&iObj_set_relativeRow,			(u32)&iObj_get_relativeRow				},
		{	_INDEX_VIEW,					(u32)&iObj_set_view,				(u32)&iObj_get_view						},
		{	_INDEX_ANCHOR,					(u32)&iObj_set_anchor,				(u32)&iObj_get_anchor					},
		{	_INDEX_APPLICATION,				(u32)&iObj_set_application,			(u32)&iObj_get_application				},
		{	_INDEX_BASECLASS,				(u32)&iObj_set_baseClass,			(u32)&iObj_get_baseClass				},
		{	_INDEX_CLASS,					(u32)&iObj_set_class,				(u32)&iObj_get_class					},
		{	_INDEX_CLASSLIBRARY,			(u32)&iObj_set_classLibrary,		(u32)&iObj_get_classLibrary				},
		{	_INDEX_COLUMNS,					(u32)&iObj_set_columns,				(u32)&iObj_get_columns					},
		{	_INDEX_COLUMNCOUNT,				(u32)&iObj_set_columnCount,			(u32)&iObj_get_columnCount				},
		{	_INDEX_OBJECTS,					(u32)&iObj_set_objects,				(u32)&iObj_get_objects					},
		{	_INDEX_FORECOLOR,				(u32)&iObj_set_foreColor,			(u32)&iObj_get_foreColor				},
		{	_INDEX_BACKCOLOR,				(u32)&iObj_set_backColor,			(u32)&iObj_get_backColor				},
		{	_INDEX_COMMENT,					(u32)&iObj_set_comment,				(u32)&iObj_get_comment					},
		{	_INDEX_RECORDSOURCE,			(u32)&iObj_set_recordSource,		(u32)&iObj_get_recordSource				},
		{	_INDEX_RECORDSOURCETYPE,		(u32)&iObj_set_recordSourceType,	(u32)&iObj_get_recordSourceType			},
		{	_INDEX_DRAGICON,				(u32)&iObj_set_dragIcon,			(u32)&iObj_get_dragIcon					},
		{	_INDEX_DRAGMODE,				(u32)&iObj_set_dragMode,			(u32)&iObj_get_dragMode					},
		{	_INDEX_ENABLED,					(u32)&iObj_set_enabled,				(u32)&iObj_get_enabled					},
		{	_INDEX_FONTBOLD,				(u32)&iObj_set_fontBold,			(u32)&iObj_get_fontBold					},
		{	_INDEX_FONTCHARSET,				(u32)&iObj_set_fontCharSet,			(u32)&iObj_get_fontCharSet				},
		{	_INDEX_FONTCONDENSE,			(u32)&iObj_set_fontCondense,		(u32)&iObj_get_fontCondense				},
		{	_INDEX_FONTEXTEND,				(u32)&iObj_set_fontExtend,			(u32)&iObj_get_fontExtend				},
		{	_INDEX_FONTITALIC,				(u32)&iObj_set_fontItalic,			(u32)&iObj_get_fontItalic				},
		{	_INDEX_FONTNAME,				(u32)&iObj_set_fontName,			(u32)&iObj_get_fontName					},
		{	_INDEX_FONTOUTLINE,				(u32)&iObj_set_fontOutline,			(u32)&iObj_get_fontOutline				},
		{	_INDEX_FONTSHADOW,				(u32)&iObj_set_fontShadow,			(u32)&iObj_get_fontShadow				},
		{	_INDEX_FONTSIZE,				(u32)&iObj_set_fontSize,			(u32)&iObj_get_fontSize					},
		{	_INDEX_FONTSTRIKETHRU,			(u32)&iObj_set_fontStrikeThru,		(u32)&iObj_get_fontStrikeThru			},
		{	_INDEX_FONTUNDERLINE,			(u32)&iObj_set_fontUnderline,		(u32)&iObj_get_fontUnderline			},
		{	_INDEX_HEADERHEIGHT,			(u32)&iObj_set_headerHeight,		(u32)&iObj_get_headerHeight				},
		{	_INDEX_HEIGHT,					(u32)&iObj_set_height,				(u32)&iObj_get_height					},
		{	_INDEX_HELPCONTEXTID,			(u32)&iObj_set_helpContextID,		(u32)&iObj_get_helpContextID			},
		{	_INDEX_LEFT,					(u32)&iObj_set_left,				(u32)&iObj_get_left						},
		{	_INDEX_MOUSEICON,				(u32)&iObj_set_mouseIcon,			(u32)&iObj_get_mouseIcon				},
		{	_INDEX_MOUSEPOINTER,			(u32)&iObj_set_mousePointer,		(u32)&iObj_get_mousePointer				},
		{	_INDEX_NAME,					(u32)&iObj_set_name,				(u32)&iObj_get_name						},
		{	_INDEX_OLEDRAGMODE,				(u32)&iObj_set_oLEDragMode,			(u32)&iObj_get_oLEDragMode				},
		{	_INDEX_OLEDRAGPICTURE,			(u32)&iObj_set_oLEDragPicture,		(u32)&iObj_get_oLEDragPicture			},
		{	_INDEX_OLEDROPEFFECTS,			(u32)&iObj_set_oLEDropEffects,		(u32)&iObj_get_oLEDropEffects			},
		{	_INDEX_OLEDROPHASDATA,			(u32)&iObj_set_oLEDropHasData,		(u32)&iObj_get_oLEDropHasData			},
		{	_INDEX_OLEDROPMODE,				(u32)&iObj_set_oLEDropMode,			(u32)&iObj_get_oLEDropMode				},
		{	_INDEX_PARENT,					(u32)&iObj_set_parent,				(u32)&iObj_get_parent					},
		{	_INDEX_PARENTCLASS,				(u32)&iObj_set_parentClass,			(u32)&iObj_get_parentClass				},
		{	_INDEX_READONLY,				(u32)&iObj_set_readOnly,			(u32)&iObj_get_readOnly					},
		{	_INDEX_RELATIONALEXPR,			(u32)&iObj_set_relationalExpr,		(u32)&iObj_get_relationalExpr			},
		{	_INDEX_RIGHTTOLEFT,				(u32)&iObj_set_rightToLeft,			(u32)&iObj_get_rightToLeft				},
		{	_INDEX_ROWCOLCHANGE,			(u32)&iObj_set_rowColChange,		(u32)&iObj_get_rowColChange				},
		{	_INDEX_ROWHEIGHT,				(u32)&iObj_set_rowHeight,			(u32)&iObj_get_rowHeight				},
		{	_INDEX_SCROLLBARS,				(u32)&iObj_set_scrollBars,			(u32)&iObj_get_scrollBars				},
		{	_INDEX_SELECTEDITEMBACKCOLOR,	(u32)&iObj_set_selectedItemBackColor,	 (u32)&iObj_get_selectedItemBackColor	},
		{	_INDEX_SELECTEDITEMFORECOLOR,	(u32)&iObj_set_selectedItemForeColor,	 (u32)&iObj_get_selectedItemForeColor	},
		{	_INDEX_STATUSBARTEXT,			(u32)&iObj_set_statusBarText,		(u32)&iObj_get_statusBarText			},
		{	_INDEX_TABINDEX,				(u32)&iObj_set_tabIndex,			(u32)&iObj_get_tabIndex					},
		{	_INDEX_TABSTOP,					(u32)&iObj_set_tabStop,				(u32)&iObj_get_tabStop					},
		{	_INDEX_TAG,						(u32)&iObj_set_tag,					(u32)&iObj_get_tag						},
		{	_INDEX_THEMES,					(u32)&iObj_set_themes,				(u32)&iObj_get_themes					},
		{	_INDEX_TOOLTIPTEXT,				(u32)&iObj_set_toolTipText,			(u32)&iObj_get_toolTipText				},
		{	_INDEX_TOP,						(u32)&iObj_set_top,					(u32)&iObj_get_top						},
		{	_INDEX_VALUE,					(u32)&iObj_set_value,				(u32)&iObj_get_value					},
		{	_INDEX_VISIBLE,					(u32)&iObj_set_visible,				(u32)&iObj_get_visible					},
		{	_INDEX_WHATSTHISHELPID,			(u32)&iObj_set_whatsThisHelpID,		(u32)&iObj_get_whatsThisHelpID			},
		{	_INDEX_WIDTH,					(u32)&iObj_set_width,				(u32)&iObj_get_width					},
		{	0,								0,									0										}
	};

	SPropertyMap gcProps_column[] =
	{
		{	_INDEX_CURRENTCONTROL,			(u32)&iObj_set_currentControl,		(u32)&iObj_get_currentControl			},
		{	_INDEX_DYNAMICALIGNMENT,		(u32)&iObj_set_dynamicAlignment,	(u32)&iObj_get_dynamicAlignment			},
		{	_INDEX_DYNAMICBACKCOLOR,		(u32)&iObj_set_dynamicBackColor,	(u32)&iObj_get_dynamicBackColor			},
		{	_INDEX_DYNAMICCURRENTCONTROL,	(u32)&iObj_set_dynamicCurrentControl,	 (u32)&iObj_get_dynamicCurrentControl	},
		{	_INDEX_DYNAMICFONTBOLD,			(u32)&iObj_set_dynamicFontBold,		(u32)&iObj_get_dynamicFontBold			},
		{	_INDEX_DYNAMICFONTITALIC,		(u32)&iObj_set_dynamicFontItalic,	(u32)&iObj_get_dynamicFontItalic		},
		{	_INDEX_DYNAMICFONTNAME,			(u32)&iObj_set_dynamicFontName,		(u32)&iObj_get_dynamicFontName			},
		{	_INDEX_DYNAMICFONTOUTLINE,		(u32)&iObj_set_dynamicFontOutline,	(u32)&iObj_get_dynamicFontOutline		},
		{	_INDEX_DYNAMICFONTSHADOW,		(u32)&iObj_set_dynamicFontShadow,	(u32)&iObj_get_dynamicFontShadow		},
		{	_INDEX_DYNAMICFONTSIZE,			(u32)&iObj_set_dynamicFontSize,		(u32)&iObj_get_dynamicFontSize			},
		{	_INDEX_DYNAMICFONTSTRIKETHRU,	(u32)&iObj_set_dynamicFontStrikeThru,	 (u32)&iObj_get_dynamicFontStrikeThru	},
		{	_INDEX_DYNAMICFONTUNDERLINE,	(u32)&iObj_set_dynamicFontUnderline,	 (u32)&iObj_get_dynamicFontUnderline	},
		{	_INDEX_DYNAMICFORECOLOR,		(u32)&iObj_set_dynamicForeColor,	(u32)&iObj_get_dynamicForeColor			},
		{	_INDEX_DYNAMICINPUTMASK,		(u32)&iObj_set_dynamicInputMask,	(u32)&iObj_get_dynamicInputMask			},
		{	_INDEX_SPARSE,					(u32)&iObj_set_sparse,				(u32)&iObj_get_sparse					},
		{	_INDEX_COLUMNORDER,				(u32)&iObj_set_columnOrder,			(u32)&iObj_get_columnOrder				},
		{	_INDEX_HEADERCLASS,				(u32)&iObj_set_headerClass,			(u32)&iObj_get_headerClass				},
		{	_INDEX_HEADERCLASSLIBRARY,		(u32)&iObj_set_headerClassLibrary,	(u32)&iObj_get_headerClassLibrary		},
		{	_INDEX_MOVABLE,					(u32)&iObj_set_movable,				(u32)&iObj_get_movable					},
		{	_INDEX_ALIGNMENT,				(u32)&iObj_set_alignment,			(u32)&iObj_get_alignment				},
		{	_INDEX_APPLICATION,				(u32)&iObj_set_application,			(u32)&iObj_get_application				},
		{	_INDEX_BASECLASS,				(u32)&iObj_set_baseClass,			(u32)&iObj_get_baseClass				},
		{	_INDEX_CLASS,					(u32)&iObj_set_class,				(u32)&iObj_get_class					},
		{	_INDEX_CLASSLIBRARY,			(u32)&iObj_set_classLibrary,		(u32)&iObj_get_classLibrary				},
		{	_INDEX_CONTROLS,				(u32)&iObj_set_controls,			(u32)&iObj_get_controls					},
		{	_INDEX_CONTROLCOUNT,			(u32)&iObj_set_controlCount,		(u32)&iObj_get_controlCount				},
		{	_INDEX_OBJECTS,					(u32)&iObj_set_objects,				(u32)&iObj_get_objects					},
		{	_INDEX_BOUND,					(u32)&iObj_set_bound,				(u32)&iObj_get_bound					},
		{	_INDEX_FORECOLOR,				(u32)&iObj_set_foreColor,			(u32)&iObj_get_foreColor				},
		{	_INDEX_BACKCOLOR,				(u32)&iObj_set_backColor,			(u32)&iObj_get_backColor				},
		{	_INDEX_COMMENT,					(u32)&iObj_set_comment,				(u32)&iObj_get_comment					},
		{	_INDEX_CONTROLSOURCE,			(u32)&iObj_set_controlSource,		(u32)&iObj_get_controlSource			},
		{	_INDEX_ENABLED,					(u32)&iObj_set_enabled,				(u32)&iObj_get_enabled					},
		{	_INDEX_FONTBOLD,				(u32)&iObj_set_fontBold,			(u32)&iObj_get_fontBold					},
		{	_INDEX_FONTCHARSET,				(u32)&iObj_set_fontCharSet,			(u32)&iObj_get_fontCharSet				},
		{	_INDEX_FONTCONDENSE,			(u32)&iObj_set_fontCondense,		(u32)&iObj_get_fontCondense				},
		{	_INDEX_FONTEXTEND,				(u32)&iObj_set_fontExtend,			(u32)&iObj_get_fontExtend				},
		{	_INDEX_FONTITALIC,				(u32)&iObj_set_fontItalic,			(u32)&iObj_get_fontItalic				},
		{	_INDEX_FONTNAME,				(u32)&iObj_set_fontName,			(u32)&iObj_get_fontName					},
		{	_INDEX_FONTOUTLINE,				(u32)&iObj_set_fontOutline,			(u32)&iObj_get_fontOutline				},
		{	_INDEX_FONTSHADOW,				(u32)&iObj_set_fontShadow,			(u32)&iObj_get_fontShadow				},
		{	_INDEX_FONTSIZE,				(u32)&iObj_set_fontSize,			(u32)&iObj_get_fontSize					},
		{	_INDEX_FONTSTRIKETHRU,			(u32)&iObj_set_fontStrikeThru,		(u32)&iObj_get_fontStrikeThru			},
		{	_INDEX_FONTUNDERLINE,			(u32)&iObj_set_fontUnderline,		(u32)&iObj_get_fontUnderline			},
		{	_INDEX_FORMAT,					(u32)&iObj_set_format,				(u32)&iObj_get_format					},
		{	_INDEX_INPUTMASK,				(u32)&iObj_set_inputMask,			(u32)&iObj_get_inputMask				},
		{	_INDEX_MOUSEICON,				(u32)&iObj_set_mouseIcon,			(u32)&iObj_get_mouseIcon				},
		{	_INDEX_MOUSEPOINTER,			(u32)&iObj_set_mousePointer,		(u32)&iObj_get_mousePointer				},
		{	_INDEX_NAME,					(u32)&iObj_set_name,				(u32)&iObj_get_name						},
		{	_INDEX_PARENT,					(u32)&iObj_set_parent,				(u32)&iObj_get_parent					},
		{	_INDEX_PARENTCLASS,				(u32)&iObj_set_parentClass,			(u32)&iObj_get_parentClass				},
		{	_INDEX_READONLY,				(u32)&iObj_set_readOnly,			(u32)&iObj_get_readOnly					},
		{	_INDEX_SELECTONENTRY,			(u32)&iObj_set_selectOnEntry,		(u32)&iObj_get_selectOnEntry			},
		{	_INDEX_RESIZABLE,				(u32)&iObj_set_resizable,			(u32)&iObj_get_resizable				},
		{	_INDEX_STATUSBARTEXT,			(u32)&iObj_set_statusBarText,		(u32)&iObj_get_statusBarText			},
		{	_INDEX_TAG,						(u32)&iObj_set_tag,					(u32)&iObj_get_tag						},
		{	_INDEX_TOOLTIPTEXT,				(u32)&iObj_set_toolTipText,			(u32)&iObj_get_toolTipText				},
		{	_INDEX_VISIBLE,					(u32)&iObj_set_visible,				(u32)&iObj_get_visible					},
		{	_INDEX_WIDTH,					(u32)&iObj_set_width,				(u32)&iObj_get_width					},
		{	0,								0,									0										}
	};

	SPropertyMap gcProps_header[] =
	{
		{	_INDEX_ALIGNMENT,				(u32)&iObj_set_alignment,			(u32)&iObj_get_alignment				},
		{	_INDEX_ANCHOR,					(u32)&iObj_set_anchor,				(u32)&iObj_get_anchor					},
		{	_INDEX_APPLICATION,				(u32)&iObj_set_application,			(u32)&iObj_get_application				},
		{	_INDEX_BASECLASS,				(u32)&iObj_set_baseClass,			(u32)&iObj_get_baseClass				},
		{	_INDEX_CLASS,					(u32)&iObj_set_class,				(u32)&iObj_get_class					},
		{	_INDEX_CLASSLIBRARY,			(u32)&iObj_set_classLibrary,		(u32)&iObj_get_classLibrary				},
		{	_INDEX_CAPTION,					(u32)&iObj_set_caption,				(u32)&iObj_get_caption					},
		{	_INDEX_FORECOLOR,				(u32)&iObj_set_foreColor,			(u32)&iObj_get_foreColor				},
		{	_INDEX_BACKCOLOR,				(u32)&iObj_set_backColor,			(u32)&iObj_get_backColor				},
		{	_INDEX_COMMENT,					(u32)&iObj_set_comment,				(u32)&iObj_get_comment					},
		{	_INDEX_FONTBOLD,				(u32)&iObj_set_fontBold,			(u32)&iObj_get_fontBold					},
		{	_INDEX_FONTCHARSET,				(u32)&iObj_set_fontCharSet,			(u32)&iObj_get_fontCharSet				},
		{	_INDEX_FONTCONDENSE,			(u32)&iObj_set_fontCondense,		(u32)&iObj_get_fontCondense				},
		{	_INDEX_FONTEXTEND,				(u32)&iObj_set_fontExtend,			(u32)&iObj_get_fontExtend				},
		{	_INDEX_FONTITALIC,				(u32)&iObj_set_fontItalic,			(u32)&iObj_get_fontItalic				},
		{	_INDEX_FONTNAME,				(u32)&iObj_set_fontName,			(u32)&iObj_get_fontName					},
		{	_INDEX_FONTOUTLINE,				(u32)&iObj_set_fontOutline,			(u32)&iObj_get_fontOutline				},
		{	_INDEX_FONTSHADOW,				(u32)&iObj_set_fontShadow,			(u32)&iObj_get_fontShadow				},
		{	_INDEX_FONTSIZE,				(u32)&iObj_set_fontSize,			(u32)&iObj_get_fontSize					},
		{	_INDEX_FONTSTRIKETHRU,			(u32)&iObj_set_fontStrikeThru,		(u32)&iObj_get_fontStrikeThru			},
		{	_INDEX_FONTUNDERLINE,			(u32)&iObj_set_fontUnderline,		(u32)&iObj_get_fontUnderline			},
		{	_INDEX_MOUSEICON,				(u32)&iObj_set_mouseIcon,			(u32)&iObj_get_mouseIcon				},
		{	_INDEX_MOUSEPOINTER,			(u32)&iObj_set_mousePointer,		(u32)&iObj_get_mousePointer				},
		{	_INDEX_NAME,					(u32)&iObj_set_name,				(u32)&iObj_get_name						},
		{	_INDEX_PARENT,					(u32)&iObj_set_parent,				(u32)&iObj_get_parent					},
		{	_INDEX_PARENTCLASS,				(u32)&iObj_set_parentClass,			(u32)&iObj_get_parentClass				},
		{	_INDEX_PICTURE,					(u32)&iObj_set_picture,				(u32)&iObj_get_picture					},
		{	_INDEX_STATUSBARTEXT,			(u32)&iObj_set_statusBarText,		(u32)&iObj_get_statusBarText			},
		{	_INDEX_TAG,						(u32)&iObj_set_tag,					(u32)&iObj_get_tag						},
		{	_INDEX_TOOLTIPTEXT,				(u32)&iObj_set_toolTipText,			(u32)&iObj_get_toolTipText				},
		{	_INDEX_WORDWRAP,				(u32)&iObj_set_wordWrap,			(u32)&iObj_get_wordWrap					},
		{	0,								0,									0										}
	};

	SPropertyMap gcProps_olebound[] =
	{
		{	_INDEX_AUTOACTIVATE,			(u32)&iObj_set_autoActivate,		(u32)&iObj_get_autoActivate				},
		{	_INDEX_AUTOSIZE,				(u32)&iObj_set_autoSize,			(u32)&iObj_get_autoSize					},
		{	_INDEX_AUTOVERBMENU,			(u32)&iObj_set_autoVerbMenu,		(u32)&iObj_get_autoVerbMenu				},
		{	_INDEX_DOCUMENTFILE,			(u32)&iObj_set_documentFile,		(u32)&iObj_get_documentFile				},
		{	_INDEX_HOSTNAME,				(u32)&iObj_set_hostName,			(u32)&iObj_get_hostName					},
		{	_INDEX_OBJECT,					(u32)&iObj_set_object,				(u32)&iObj_get_object					},
		{	_INDEX_ANCHOR,					(u32)&iObj_set_anchor,				(u32)&iObj_get_anchor					},
		{	_INDEX_APPLICATION,				(u32)&iObj_set_application,			(u32)&iObj_get_application				},
		{	_INDEX_BASECLASS,				(u32)&iObj_set_baseClass,			(u32)&iObj_get_baseClass				},
		{	_INDEX_CLASS,					(u32)&iObj_set_class,				(u32)&iObj_get_class					},
		{	_INDEX_CLASSLIBRARY,			(u32)&iObj_set_classLibrary,		(u32)&iObj_get_classLibrary				},
		{	_INDEX_COMMENT,					(u32)&iObj_set_comment,				(u32)&iObj_get_comment					},
		{	_INDEX_CONTROLSOURCE,			(u32)&iObj_set_controlSource,		(u32)&iObj_get_controlSource			},
		{	_INDEX_DRAGICON,				(u32)&iObj_set_dragIcon,			(u32)&iObj_get_dragIcon					},
		{	_INDEX_DRAGMODE,				(u32)&iObj_set_dragMode,			(u32)&iObj_get_dragMode					},
		{	_INDEX_ENABLED,					(u32)&iObj_set_enabled,				(u32)&iObj_get_enabled					},
		{	_INDEX_HEIGHT,					(u32)&iObj_set_height,				(u32)&iObj_get_height					},
		{	_INDEX_HELPCONTEXTID,			(u32)&iObj_set_helpContextID,		(u32)&iObj_get_helpContextID			},
		{	_INDEX_LEFT,					(u32)&iObj_set_left,				(u32)&iObj_get_left						},
		{	_INDEX_MOUSEPOINTER,			(u32)&iObj_set_mousePointer,		(u32)&iObj_get_mousePointer				},
		{	_INDEX_NAME,					(u32)&iObj_set_name,				(u32)&iObj_get_name						},
		{	_INDEX_OLECLASS,				(u32)&iObj_set_oLEClass,			(u32)&iObj_get_oLEClass					},
		{	_INDEX_OLELCID,					(u32)&iObj_set_oLELCID,				(u32)&iObj_get_oLELCID					},
		{	_INDEX_OLETYPEALLOWED,			(u32)&iObj_set_oLETypeAllowed,		(u32)&iObj_get_oLETypeAllowed			},
		{	_INDEX_PARENTCLASS,				(u32)&iObj_set_parentClass,			(u32)&iObj_get_parentClass				},
		{	_INDEX_SIZABLE,					(u32)&iObj_set_sizable,				(u32)&iObj_get_sizable					},
		{	_INDEX_STRETCH,					(u32)&iObj_set_stretch,				(u32)&iObj_get_stretch					},
		{	_INDEX_STATUSBARTEXT,			(u32)&iObj_set_statusBarText,		(u32)&iObj_get_statusBarText			},
		{	_INDEX_TABINDEX,				(u32)&iObj_set_tabIndex,			(u32)&iObj_get_tabIndex					},
		{	_INDEX_TABSTOP,					(u32)&iObj_set_tabStop,				(u32)&iObj_get_tabStop					},
		{	_INDEX_TAG,						(u32)&iObj_set_tag,					(u32)&iObj_get_tag						},
		{	_INDEX_TOOLTIPTEXT,				(u32)&iObj_set_toolTipText,			(u32)&iObj_get_toolTipText				},
		{	_INDEX_TOP,						(u32)&iObj_set_top,					(u32)&iObj_get_top						},
		{	_INDEX_VISIBLE,					(u32)&iObj_set_visible,				(u32)&iObj_get_visible					},
		{	_INDEX_WHATSTHISHELPID,			(u32)&iObj_set_whatsThisHelpID,		(u32)&iObj_get_whatsThisHelpID			},
		{	_INDEX_WIDTH,					(u32)&iObj_set_width,				(u32)&iObj_get_width					},
		{	_INDEX_WORDWRAP,				(u32)&iObj_set_wordWrap,			(u32)&iObj_get_wordWrap					},
		{	0,								0,									0										}
	};

	SPropertyMap gcProps_olecontain[] =
	{
		{	_INDEX_AUTOACTIVATE,			(u32)&iObj_set_autoActivate,		(u32)&iObj_get_autoActivate				},
		{	_INDEX_AUTOSIZE,				(u32)&iObj_set_autoSize,			(u32)&iObj_get_autoSize					},
		{	_INDEX_AUTOVERBMENU,			(u32)&iObj_set_autoVerbMenu,		(u32)&iObj_get_autoVerbMenu				},
		{	_INDEX_DOCUMENTFILE,			(u32)&iObj_set_documentFile,		(u32)&iObj_get_documentFile				},
		{	_INDEX_HOSTNAME,				(u32)&iObj_set_hostName,			(u32)&iObj_get_hostName					},
		{	_INDEX_OBJECT,					(u32)&iObj_set_object,				(u32)&iObj_get_object					},
		{	_INDEX_ALIGN,					(u32)&iObj_set_align,				(u32)&iObj_get_align					},
		{	_INDEX_ANCHOR,					(u32)&iObj_set_anchor,				(u32)&iObj_get_anchor					},
		{	_INDEX_APPLICATION,				(u32)&iObj_set_application,			(u32)&iObj_get_application				},
		{	_INDEX_BASECLASS,				(u32)&iObj_set_baseClass,			(u32)&iObj_get_baseClass				},
		{	_INDEX_CLASS,					(u32)&iObj_set_class,				(u32)&iObj_get_class					},
		{	_INDEX_CLASSLIBRARY,			(u32)&iObj_set_classLibrary,		(u32)&iObj_get_classLibrary				},
		{	_INDEX_CANCEL,					(u32)&iObj_set_cancel,				(u32)&iObj_get_cancel					},
		{	_INDEX_DEFAULT,					(u32)&iObj_set_default,				(u32)&iObj_get_default					},
		{	_INDEX_COMMENT,					(u32)&iObj_set_comment,				(u32)&iObj_get_comment					},
		{	_INDEX_CONTROLSOURCE,			(u32)&iObj_set_controlSource,		(u32)&iObj_get_controlSource			},
		{	_INDEX_DRAGICON,				(u32)&iObj_set_dragIcon,			(u32)&iObj_get_dragIcon					},
		{	_INDEX_DRAGMODE,				(u32)&iObj_set_dragMode,			(u32)&iObj_get_dragMode					},
		{	_INDEX_ENABLED,					(u32)&iObj_set_enabled,				(u32)&iObj_get_enabled					},
		{	_INDEX_HEIGHT,					(u32)&iObj_set_height,				(u32)&iObj_get_height					},
		{	_INDEX_HELPCONTEXTID,			(u32)&iObj_set_helpContextID,		(u32)&iObj_get_helpContextID			},
		{	_INDEX_LEFT,					(u32)&iObj_set_left,				(u32)&iObj_get_left						},
		{	_INDEX_MOUSEICON,				(u32)&iObj_set_mouseIcon,			(u32)&iObj_get_mouseIcon				},
		{	_INDEX_MOUSEPOINTER,			(u32)&iObj_set_mousePointer,		(u32)&iObj_get_mousePointer				},
		{	_INDEX_NAME,					(u32)&iObj_set_name,				(u32)&iObj_get_name						},
		{	_INDEX_OLECLASS,				(u32)&iObj_set_oLEClass,			(u32)&iObj_get_oLEClass					},
		{	_INDEX_OLELCID,					(u32)&iObj_set_oLELCID,				(u32)&iObj_get_oLELCID					},
		{	_INDEX_OLETYPEALLOWED,			(u32)&iObj_set_oLETypeAllowed,		(u32)&iObj_get_oLETypeAllowed			},
		{	_INDEX_PARENT,					(u32)&iObj_set_parent,				(u32)&iObj_get_parent					},
		{	_INDEX_PARENTCLASS,				(u32)&iObj_set_parentClass,			(u32)&iObj_get_parentClass				},
		{	_INDEX_SIZABLE,					(u32)&iObj_set_sizable,				(u32)&iObj_get_sizable					},
		{	_INDEX_STRETCH,					(u32)&iObj_set_stretch,				(u32)&iObj_get_stretch					},
		{	_INDEX_TABINDEX,				(u32)&iObj_set_tabIndex,			(u32)&iObj_get_tabIndex					},
		{	_INDEX_TABSTOP,					(u32)&iObj_set_tabStop,				(u32)&iObj_get_tabStop					},
		{	_INDEX_TAG,						(u32)&iObj_set_tag,					(u32)&iObj_get_tag						},
		{	_INDEX_TOP,						(u32)&iObj_set_top,					(u32)&iObj_get_top						},
		{	_INDEX_VISIBLE,					(u32)&iObj_set_visible,				(u32)&iObj_get_visible					},
		{	_INDEX_WHATSTHISHELPID,			(u32)&iObj_set_whatsThisHelpID,		(u32)&iObj_get_whatsThisHelpID			},
		{	_INDEX_WIDTH,					(u32)&iObj_set_width,				(u32)&iObj_get_width					},
		{	0,								0,									0										}
	};

	SPropertyMap gcProps_spinner[] =
	{
		{	_INDEX_SPINNERHIGHVALUE,		(u32)&iObj_set_spinnerHighValue,	(u32)&iObj_get_spinnerHighValue			},
		{	_INDEX_SPINNERLOWVALUE,			(u32)&iObj_set_spinnerLowValue,		(u32)&iObj_get_spinnerLowValue			},
		{	_INDEX_KEYBOARDHIGHVALUE,		(u32)&iObj_set_keyboardHighValue,	(u32)&iObj_get_keyboardHighValue		},
		{	_INDEX_KEYBOARDLOWVALUE,		(u32)&iObj_set_keyboardLowValue,	(u32)&iObj_get_keyboardLowValue			},
		{	_INDEX_INCREMENT,				(u32)&iObj_set_increment,			(u32)&iObj_get_increment				},
		{	_INDEX_ALIGNMENT,				(u32)&iObj_set_alignment,			(u32)&iObj_get_alignment				},
		{	_INDEX_ANCHOR,					(u32)&iObj_set_anchor,				(u32)&iObj_get_anchor					},
		{	_INDEX_APPLICATION,				(u32)&iObj_set_application,			(u32)&iObj_get_application				},
		{	_INDEX_BASECLASS,				(u32)&iObj_set_baseClass,			(u32)&iObj_get_baseClass				},
		{	_INDEX_CLASS,					(u32)&iObj_set_class,				(u32)&iObj_get_class					},
		{	_INDEX_CLASSLIBRARY,			(u32)&iObj_set_classLibrary,		(u32)&iObj_get_classLibrary				},
		{	_INDEX_BORDERCOLOR,				(u32)&iObj_set_borderColor,			(u32)&iObj_get_borderColor				},
		{	_INDEX_BORDERSTYLE,				(u32)&iObj_set_borderStyle,			(u32)&iObj_get_borderStyle				},
		{	_INDEX_COLORSCHEME,				(u32)&iObj_set_colorScheme,			(u32)&iObj_get_colorScheme				},
		{	_INDEX_COLORSOURCE,				(u32)&iObj_set_colorSource,			(u32)&iObj_get_colorSource				},
		{	_INDEX_FORECOLOR,				(u32)&iObj_set_foreColor,			(u32)&iObj_get_foreColor				},
		{	_INDEX_BACKCOLOR,				(u32)&iObj_set_backColor,			(u32)&iObj_get_backColor				},
		{	_INDEX_DISABLEDBACKCOLOR,		(u32)&iObj_set_disabledBackColor,	(u32)&iObj_get_disabledBackColor		},
		{	_INDEX_DISABLEDFORECOLOR,		(u32)&iObj_set_disabledForeColor,	(u32)&iObj_get_disabledForeColor		},
		{	_INDEX_COMMENT,					(u32)&iObj_set_comment,				(u32)&iObj_get_comment					},
		{	_INDEX_CONTROLSOURCE,			(u32)&iObj_set_controlSource,		(u32)&iObj_get_controlSource			},
		{	_INDEX_DRAGICON,				(u32)&iObj_set_dragIcon,			(u32)&iObj_get_dragIcon					},
		{	_INDEX_DRAGMODE,				(u32)&iObj_set_dragMode,			(u32)&iObj_get_dragMode					},
		{	_INDEX_ENABLED,					(u32)&iObj_set_enabled,				(u32)&iObj_get_enabled					},
		{	_INDEX_FONTBOLD,				(u32)&iObj_set_fontBold,			(u32)&iObj_get_fontBold					},
		{	_INDEX_FONTCHARSET,				(u32)&iObj_set_fontCharSet,			(u32)&iObj_get_fontCharSet				},
		{	_INDEX_FONTCONDENSE,			(u32)&iObj_set_fontCondense,		(u32)&iObj_get_fontCondense				},
		{	_INDEX_FONTEXTEND,				(u32)&iObj_set_fontExtend,			(u32)&iObj_get_fontExtend				},
		{	_INDEX_FONTITALIC,				(u32)&iObj_set_fontItalic,			(u32)&iObj_get_fontItalic				},
		{	_INDEX_FONTNAME,				(u32)&iObj_set_fontName,			(u32)&iObj_get_fontName					},
		{	_INDEX_FONTOUTLINE,				(u32)&iObj_set_fontOutline,			(u32)&iObj_get_fontOutline				},
		{	_INDEX_FONTSHADOW,				(u32)&iObj_set_fontShadow,			(u32)&iObj_get_fontShadow				},
		{	_INDEX_FONTSIZE,				(u32)&iObj_set_fontSize,			(u32)&iObj_get_fontSize					},
		{	_INDEX_FONTSTRIKETHRU,			(u32)&iObj_set_fontStrikeThru,		(u32)&iObj_get_fontStrikeThru			},
		{	_INDEX_FONTUNDERLINE,			(u32)&iObj_set_fontUnderline,		(u32)&iObj_get_fontUnderline			},
		{	_INDEX_FORMAT,					(u32)&iObj_set_format,				(u32)&iObj_get_format					},
		{	_INDEX_HEIGHT,					(u32)&iObj_set_height,				(u32)&iObj_get_height					},
		{	_INDEX_HELPCONTEXTID,			(u32)&iObj_set_helpContextID,		(u32)&iObj_get_helpContextID			},
		{	_INDEX_HIDESELECTION,			(u32)&iObj_set_hideSelection,		(u32)&iObj_get_hideSelection			},
		{	_INDEX_INPUTMASK,				(u32)&iObj_set_inputMask,			(u32)&iObj_get_inputMask				},
		{	_INDEX_LEFT,					(u32)&iObj_set_left,				(u32)&iObj_get_left						},
		{	_INDEX_MARGIN,					(u32)&iObj_set_margin,				(u32)&iObj_get_margin					},
		{	_INDEX_MOUSEICON,				(u32)&iObj_set_mouseIcon,			(u32)&iObj_get_mouseIcon				},
		{	_INDEX_MOUSEPOINTER,			(u32)&iObj_set_mousePointer,		(u32)&iObj_get_mousePointer				},
		{	_INDEX_NAME,					(u32)&iObj_set_name,				(u32)&iObj_get_name						},
		{	_INDEX_NULLDISPLAY,				(u32)&iObj_set_nullDisplay,			(u32)&iObj_get_nullDisplay				},
		{	_INDEX_OLEDRAGMODE,				(u32)&iObj_set_oLEDragMode,			(u32)&iObj_get_oLEDragMode				},
		{	_INDEX_OLEDRAGPICTURE,			(u32)&iObj_set_oLEDragPicture,		(u32)&iObj_get_oLEDragPicture			},
		{	_INDEX_OLEDROPEFFECTS,			(u32)&iObj_set_oLEDropEffects,		(u32)&iObj_get_oLEDropEffects			},
		{	_INDEX_OLEDROPHASDATA,			(u32)&iObj_set_oLEDropHasData,		(u32)&iObj_get_oLEDropHasData			},
		{	_INDEX_OLEDROPMODE,				(u32)&iObj_set_oLEDropMode,			(u32)&iObj_get_oLEDropMode				},
		{	_INDEX_OLEDROPTEXTINSERTION,	(u32)&iObj_set_oLEDropTextInsertion,(u32)&iObj_get_oLEDropTextInsertion		},
		{	_INDEX_PARENT,					(u32)&iObj_set_parent,				(u32)&iObj_get_parent					},
		{	_INDEX_PARENTCLASS,				(u32)&iObj_set_parentClass,			(u32)&iObj_get_parentClass				},
		{	_INDEX_READONLY,				(u32)&iObj_set_readOnly,			(u32)&iObj_get_readOnly					},
		{	_INDEX_RIGHTTOLEFT,				(u32)&iObj_set_rightToLeft,			(u32)&iObj_get_rightToLeft				},
		{	_INDEX_SELECTEDBACKCOLOR,		(u32)&iObj_set_selectedBackColor,	(u32)&iObj_get_selectedBackColor		},
		{	_INDEX_SELECTEDFORECOLOR,		(u32)&iObj_set_selectedForeColor,	(u32)&iObj_get_selectedForeColor		},
		{	_INDEX_SELECTONENTRY,			(u32)&iObj_set_selectOnEntry,		(u32)&iObj_get_selectOnEntry			},
		{	_INDEX_SELLENGTH,				(u32)&iObj_set_selLength,			(u32)&iObj_get_selLength				},
		{	_INDEX_SELSTART,				(u32)&iObj_set_selStart,			(u32)&iObj_get_selStart					},
		{	_INDEX_SELTEXT,					(u32)&iObj_set_selText,				(u32)&iObj_get_selText					},
		{	_INDEX_SPECIALEFFECT,			(u32)&iObj_set_specialEffect,		(u32)&iObj_get_specialEffect			},
		{	_INDEX_STATUSBARTEXT,			(u32)&iObj_set_statusBarText,		(u32)&iObj_get_statusBarText			},
		{	_INDEX_TABINDEX,				(u32)&iObj_set_tabIndex,			(u32)&iObj_get_tabIndex					},
		{	_INDEX_TABSTOP,					(u32)&iObj_set_tabStop,				(u32)&iObj_get_tabStop					},
		{	_INDEX_TAG,						(u32)&iObj_set_tag,					(u32)&iObj_get_tag						},
		{	_INDEX_TERMINATEREAD,			(u32)&iObj_set_terminateRead,		(u32)&iObj_get_terminateRead			},
		{	_INDEX_TEXT,					(u32)&iObj_set_text,				(u32)&iObj_get_text						},
		{	_INDEX_THEMES,					(u32)&iObj_set_themes,				(u32)&iObj_get_themes					},
		{	_INDEX_TOOLTIPTEXT,				(u32)&iObj_set_toolTipText,			(u32)&iObj_get_toolTipText				},
		{	_INDEX_TOP,						(u32)&iObj_set_top,					(u32)&iObj_get_top						},
		{	_INDEX_VALUE,					(u32)&iObj_set_value,				(u32)&iObj_get_value					},
		{	_INDEX_VISIBLE,					(u32)&iObj_set_visible,				(u32)&iObj_get_visible					},
		{	_INDEX_WHATSTHISHELPID,			(u32)&iObj_set_whatsThisHelpID,		(u32)&iObj_get_whatsThisHelpID			},
		{	_INDEX_WIDTH,					(u32)&iObj_set_width,				(u32)&iObj_get_width					},
		{	0,								0,									0										}
	};

	SPropertyMap gcProps_timer[] =
	{
		{	_INDEX_INTERVAL,				(u32)&iObj_set_interval,			(u32)&iObj_get_interval					},
		{	_INDEX_APPLICATION,				(u32)&iObj_set_application,			(u32)&iObj_get_application				},
		{	_INDEX_BASECLASS,				(u32)&iObj_set_baseClass,			(u32)&iObj_get_baseClass				},
		{	_INDEX_CLASS,					(u32)&iObj_set_class,				(u32)&iObj_get_class					},
		{	_INDEX_CLASSLIBRARY,			(u32)&iObj_set_classLibrary,		(u32)&iObj_get_classLibrary				},
		{	_INDEX_COMMENT,					(u32)&iObj_set_comment,				(u32)&iObj_get_comment					},
		{	_INDEX_ENABLED,					(u32)&iObj_set_enabled,				(u32)&iObj_get_enabled					},
		{	_INDEX_HEIGHT,					(u32)&iObj_set_height,				(u32)&iObj_get_height					},
		{	_INDEX_LEFT,					(u32)&iObj_set_left,				(u32)&iObj_get_left						},
		{	_INDEX_NAME,					(u32)&iObj_set_name,				(u32)&iObj_get_name						},
		{	_INDEX_PARENT,					(u32)&iObj_set_parent,				(u32)&iObj_get_parent					},
		{	_INDEX_PARENTCLASS,				(u32)&iObj_set_parentClass,			(u32)&iObj_get_parentClass				},
		{	_INDEX_TAG,						(u32)&iObj_set_tag,					(u32)&iObj_get_tag						},
		{	_INDEX_TOP,						(u32)&iObj_set_top,					(u32)&iObj_get_top						},
		{	_INDEX_WIDTH,					(u32)&iObj_set_width,				(u32)&iObj_get_width					},
		{	0,								0,									0										}
	};

	SPropertyMap gcProps_hyperlink[] =
	{
		{	_INDEX_APPLICATION,				(u32)&iObj_set_application,			(u32)&iObj_get_application				},
		{	_INDEX_BASECLASS,				(u32)&iObj_set_baseClass,			(u32)&iObj_get_baseClass				},
		{	_INDEX_CLASS,					(u32)&iObj_set_class,				(u32)&iObj_get_class					},
		{	_INDEX_CLASSLIBRARY,			(u32)&iObj_set_classLibrary,		(u32)&iObj_get_classLibrary				},
		{	_INDEX_COMMENT,					(u32)&iObj_set_comment,				(u32)&iObj_get_comment					},
		{	_INDEX_NAME,					(u32)&iObj_set_name,				(u32)&iObj_get_name						},
		{	_INDEX_PARENT,					(u32)&iObj_set_parent,				(u32)&iObj_get_parent					},
		{	_INDEX_PARENTCLASS,				(u32)&iObj_set_parentClass,			(u32)&iObj_get_parentClass				},
		{	_INDEX_TAG,						(u32)&iObj_set_tag,					(u32)&iObj_get_tag						},
		{	0,								0,									0										}
	};

	SPropertyMap gcProps_collection[] =
	{
		{	_INDEX_KEYSORT,					(u32)&iObj_set_keySort,				(u32)&iObj_get_keySort					},
		{	_INDEX_BASECLASS,				(u32)&iObj_set_baseClass,			(u32)&iObj_get_baseClass				},
		{	_INDEX_CLASS,					(u32)&iObj_set_class,				(u32)&iObj_get_class					},
		{	_INDEX_CLASSLIBRARY,			(u32)&iObj_set_classLibrary,		(u32)&iObj_get_classLibrary				},
		{	_INDEX_COUNT,					(u32)&iObj_set_count,				(u32)&iObj_get_count					},
		{	_INDEX_COMMENT,					(u32)&iObj_set_comment,				(u32)&iObj_get_comment					},
		{	_INDEX_NAME,					(u32)&iObj_set_name,				(u32)&iObj_get_name						},
		{	_INDEX_PARENT,					(u32)&iObj_set_parent,				(u32)&iObj_get_parent					},
		{	_INDEX_PARENTCLASS,				(u32)&iObj_set_parentClass,			(u32)&iObj_get_parentClass				},
		{	_INDEX_TAG,						(u32)&iObj_set_tag,					(u32)&iObj_get_tag						},
		{	0,								0,									0										}
	};

	SPropertyMap gcProps_page[] =
	{
		{	_INDEX_ACTIVECONTROL,			(u32)&iObj_set_activeControl,		(u32)&iObj_get_activeControl			},
		{	_INDEX_PAGEORDER,				(u32)&iObj_set_pageOrder,			(u32)&iObj_get_pageOrder				},
		{	_INDEX_APPLICATION,				(u32)&iObj_set_application,			(u32)&iObj_get_application				},
		{	_INDEX_BACKSTYLE,				(u32)&iObj_set_backStyle,			(u32)&iObj_get_backStyle				},
		{	_INDEX_BASECLASS,				(u32)&iObj_set_baseClass,			(u32)&iObj_get_baseClass				},
		{	_INDEX_CLASS,					(u32)&iObj_set_class,				(u32)&iObj_get_class					},
		{	_INDEX_CLASSLIBRARY,			(u32)&iObj_set_classLibrary,		(u32)&iObj_get_classLibrary				},
		{	_INDEX_CONTROLS,				(u32)&iObj_set_controls,			(u32)&iObj_get_controls					},
		{	_INDEX_CONTROLCOUNT,			(u32)&iObj_set_controlCount,		(u32)&iObj_get_controlCount				},
		{	_INDEX_OBJECTS,					(u32)&iObj_set_objects,				(u32)&iObj_get_objects					},
		{	_INDEX_CAPTION,					(u32)&iObj_set_caption,				(u32)&iObj_get_caption					},
		{	_INDEX_COLORSOURCE,				(u32)&iObj_set_colorSource,			(u32)&iObj_get_colorSource				},
		{	_INDEX_FORECOLOR,				(u32)&iObj_set_foreColor,			(u32)&iObj_get_foreColor				},
		{	_INDEX_BACKCOLOR,				(u32)&iObj_set_backColor,			(u32)&iObj_get_backColor				},
		{	_INDEX_COMMENT,					(u32)&iObj_set_comment,				(u32)&iObj_get_comment					},
		{	_INDEX_DRAGICON,				(u32)&iObj_set_dragIcon,			(u32)&iObj_get_dragIcon					},
		{	_INDEX_DRAGMODE,				(u32)&iObj_set_dragMode,			(u32)&iObj_get_dragMode					},
		{	_INDEX_ENABLED,					(u32)&iObj_set_enabled,				(u32)&iObj_get_enabled					},
		{	_INDEX_FONTBOLD,				(u32)&iObj_set_fontBold,			(u32)&iObj_get_fontBold					},
		{	_INDEX_FONTCHARSET,				(u32)&iObj_set_fontCharSet,			(u32)&iObj_get_fontCharSet				},
		{	_INDEX_FONTCONDENSE,			(u32)&iObj_set_fontCondense,		(u32)&iObj_get_fontCondense				},
		{	_INDEX_FONTEXTEND,				(u32)&iObj_set_fontExtend,			(u32)&iObj_get_fontExtend				},
		{	_INDEX_FONTITALIC,				(u32)&iObj_set_fontItalic,			(u32)&iObj_get_fontItalic				},
		{	_INDEX_FONTNAME,				(u32)&iObj_set_fontName,			(u32)&iObj_get_fontName					},
		{	_INDEX_FONTOUTLINE,				(u32)&iObj_set_fontOutline,			(u32)&iObj_get_fontOutline				},
		{	_INDEX_FONTSHADOW,				(u32)&iObj_set_fontShadow,			(u32)&iObj_get_fontShadow				},
		{	_INDEX_FONTSIZE,				(u32)&iObj_set_fontSize,			(u32)&iObj_get_fontSize					},
		{	_INDEX_FONTSTRIKETHRU,			(u32)&iObj_set_fontStrikeThru,		(u32)&iObj_get_fontStrikeThru			},
		{	_INDEX_FONTUNDERLINE,			(u32)&iObj_set_fontUnderline,		(u32)&iObj_get_fontUnderline			},
		{	_INDEX_HELPCONTEXTID,			(u32)&iObj_set_helpContextID,		(u32)&iObj_get_helpContextID			},
		{	_INDEX_MOUSEICON,				(u32)&iObj_set_mouseIcon,			(u32)&iObj_get_mouseIcon				},
		{	_INDEX_MOUSEPOINTER,			(u32)&iObj_set_mousePointer,		(u32)&iObj_get_mousePointer				},
		{	_INDEX_NAME,					(u32)&iObj_set_name,				(u32)&iObj_get_name						},
		{	_INDEX_OLEDRAGMODE,				(u32)&iObj_set_oLEDragMode,			(u32)&iObj_get_oLEDragMode				},
		{	_INDEX_OLEDRAGPICTURE,			(u32)&iObj_set_oLEDragPicture,		(u32)&iObj_get_oLEDragPicture			},
		{	_INDEX_OLEDROPEFFECTS,			(u32)&iObj_set_oLEDropEffects,		(u32)&iObj_get_oLEDropEffects			},
		{	_INDEX_OLEDROPHASDATA,			(u32)&iObj_set_oLEDropHasData,		(u32)&iObj_get_oLEDropHasData			},
		{	_INDEX_OLEDROPMODE,				(u32)&iObj_set_oLEDropMode,			(u32)&iObj_get_oLEDropMode				},
		{	_INDEX_PARENT,					(u32)&iObj_set_parent,				(u32)&iObj_get_parent					},
		{	_INDEX_PARENTCLASS,				(u32)&iObj_set_parentClass,			(u32)&iObj_get_parentClass				},
		{	_INDEX_PICTURE,					(u32)&iObj_set_picture,				(u32)&iObj_get_picture					},
		{	_INDEX_TAG,						(u32)&iObj_set_tag,					(u32)&iObj_get_tag						},
		{	_INDEX_TOOLTIPTEXT,				(u32)&iObj_set_toolTipText,			(u32)&iObj_get_toolTipText				},
		{	_INDEX_WHATSTHISHELPID,			(u32)&iObj_set_whatsThisHelpID,		(u32)&iObj_get_whatsThisHelpID			},
		{	0,								0,									0										}
	};

	SPropertyMap gcProps_pageframe[] =
	{
		{	_INDEX_ACTIVEPAGE,				(u32)&iObj_set_activePage,			(u32)&iObj_get_activePage				},
		{	_INDEX_TABORIENTATION,			(u32)&iObj_set_tabOrientation,		(u32)&iObj_get_tabOrientation			},
		{	_INDEX_TABS,					(u32)&iObj_set_tabs,				(u32)&iObj_get_tabs						},
		{	_INDEX_PAGEHEIGHT,				(u32)&iObj_set_pageHeight,			(u32)&iObj_get_pageHeight				},
		{	_INDEX_PAGEWIDTH,				(u32)&iObj_set_pageWidth,			(u32)&iObj_get_pageWidth				},
		{	_INDEX_ANCHOR,					(u32)&iObj_set_anchor,				(u32)&iObj_get_anchor					},
		{	_INDEX_APPLICATION,				(u32)&iObj_set_application,			(u32)&iObj_get_application				},
		{	_INDEX_BASECLASS,				(u32)&iObj_set_baseClass,			(u32)&iObj_get_baseClass				},
		{	_INDEX_CLASS,					(u32)&iObj_set_class,				(u32)&iObj_get_class					},
		{	_INDEX_CLASSLIBRARY,			(u32)&iObj_set_classLibrary,		(u32)&iObj_get_classLibrary				},
		{	_INDEX_PAGES,					(u32)&iObj_set_pages,				(u32)&iObj_get_pages					},
		{	_INDEX_PAGECOUNT,				(u32)&iObj_set_pageCount,			(u32)&iObj_get_pageCount				},
		{	_INDEX_OBJECTS,					(u32)&iObj_set_objects,				(u32)&iObj_get_objects					},
		{	_INDEX_BORDERCOLOR,				(u32)&iObj_set_borderColor,			(u32)&iObj_get_borderColor				},
		{	_INDEX_BORDERWIDTH,				(u32)&iObj_set_borderWidth,			(u32)&iObj_get_borderWidth				},
		{	_INDEX_COLORSOURCE,				(u32)&iObj_set_colorSource,			(u32)&iObj_get_colorSource				},
		{	_INDEX_COMMENT,					(u32)&iObj_set_comment,				(u32)&iObj_get_comment					},
		{	_INDEX_DRAGICON,				(u32)&iObj_set_dragIcon,			(u32)&iObj_get_dragIcon					},
		{	_INDEX_DRAGMODE,				(u32)&iObj_set_dragMode,			(u32)&iObj_get_dragMode					},
		{	_INDEX_ENABLED,					(u32)&iObj_set_enabled,				(u32)&iObj_get_enabled					},
		{	_INDEX_HEIGHT,					(u32)&iObj_set_height,				(u32)&iObj_get_height					},
		{	_INDEX_HELPCONTEXTID,			(u32)&iObj_set_helpContextID,		(u32)&iObj_get_helpContextID			},
		{	_INDEX_LEFT,					(u32)&iObj_set_left,				(u32)&iObj_get_left						},
		{	_INDEX_MEMBERCLASS,				(u32)&iObj_set_memberClass,			(u32)&iObj_get_memberClass				},
		{	_INDEX_MEMBERCLASSLIBRARY,		(u32)&iObj_set_memberClassLibrary,	(u32)&iObj_get_memberClassLibrary		},
		{	_INDEX_MOUSEICON,				(u32)&iObj_set_mouseIcon,			(u32)&iObj_get_mouseIcon				},
		{	_INDEX_MOUSEPOINTER,			(u32)&iObj_set_mousePointer,		(u32)&iObj_get_mousePointer				},
		{	_INDEX_NAME,					(u32)&iObj_set_name,				(u32)&iObj_get_name						},
		{	_INDEX_OLEDRAGMODE,				(u32)&iObj_set_oLEDragMode,			(u32)&iObj_get_oLEDragMode				},
		{	_INDEX_OLEDRAGPICTURE,			(u32)&iObj_set_oLEDragPicture,		(u32)&iObj_get_oLEDragPicture			},
		{	_INDEX_OLEDROPEFFECTS,			(u32)&iObj_set_oLEDropEffects,		(u32)&iObj_get_oLEDropEffects			},
		{	_INDEX_OLEDROPHASDATA,			(u32)&iObj_set_oLEDropHasData,		(u32)&iObj_get_oLEDropHasData			},
		{	_INDEX_OLEDROPMODE,				(u32)&iObj_set_oLEDropMode,			(u32)&iObj_get_oLEDropMode				},
		{	_INDEX_PARENT,					(u32)&iObj_set_parent,				(u32)&iObj_get_parent					},
		{	_INDEX_PARENTCLASS,				(u32)&iObj_set_parentClass,			(u32)&iObj_get_parentClass				},
		{	_INDEX_RIGHTTOLEFT,				(u32)&iObj_set_rightToLeft,			(u32)&iObj_get_rightToLeft				},
		{	_INDEX_SPECIALEFFECT,			(u32)&iObj_set_specialEffect,		(u32)&iObj_get_specialEffect			},
		{	_INDEX_STATUSBARTEXT,			(u32)&iObj_set_statusBarText,		(u32)&iObj_get_statusBarText			},
		{	_INDEX_TABSTYLE,				(u32)&iObj_set_tabStyle,			(u32)&iObj_get_tabStyle					},
		{	_INDEX_TABINDEX,				(u32)&iObj_set_tabIndex,			(u32)&iObj_get_tabIndex					},
		{	_INDEX_TABSTOP,					(u32)&iObj_set_tabStop,				(u32)&iObj_get_tabStop					},
		{	_INDEX_TAG,						(u32)&iObj_set_tag,					(u32)&iObj_get_tag						},
		{	_INDEX_THEMES,					(u32)&iObj_set_themes,				(u32)&iObj_get_themes					},
		{	_INDEX_TOOLTIPTEXT,				(u32)&iObj_set_toolTipText,			(u32)&iObj_get_toolTipText				},
		{	_INDEX_TOP,						(u32)&iObj_set_top,					(u32)&iObj_get_top						},
		{	_INDEX_VISIBLE,					(u32)&iObj_set_visible,				(u32)&iObj_get_visible					},
		{	_INDEX_WHATSTHISHELPID,			(u32)&iObj_set_whatsThisHelpID,		(u32)&iObj_get_whatsThisHelpID			},
		{	_INDEX_WIDTH,					(u32)&iObj_set_width,				(u32)&iObj_get_width					},
		{	0,								0,									0										}
	};

	SPropertyMap gcProps_session[] =
	{
		{	_INDEX_DATASESSION,				(u32)&iObj_set_dataSession,			(u32)&iObj_get_dataSession				},
		{	_INDEX_DATASESSIONID,			(u32)&iObj_set_dataSessionID,		(u32)&iObj_get_dataSessionID			},
		{	_INDEX_APPLICATION,				(u32)&iObj_set_application,			(u32)&iObj_get_application				},
		{	_INDEX_BASECLASS,				(u32)&iObj_set_baseClass,			(u32)&iObj_get_baseClass				},
		{	_INDEX_CLASS,					(u32)&iObj_set_class,				(u32)&iObj_get_class					},
		{	_INDEX_CLASSLIBRARY,			(u32)&iObj_set_classLibrary,		(u32)&iObj_get_classLibrary				},
		{	_INDEX_COMMENT,					(u32)&iObj_set_comment,				(u32)&iObj_get_comment					},
		{	_INDEX_NAME,					(u32)&iObj_set_name,				(u32)&iObj_get_name						},
		{	_INDEX_PARENT,					(u32)&iObj_set_parent,				(u32)&iObj_get_parent					},
		{	_INDEX_PARENTCLASS,				(u32)&iObj_set_parentClass,			(u32)&iObj_get_parentClass				},
		{	_INDEX_TAG,						(u32)&iObj_set_tag,					(u32)&iObj_get_tag						},
		{	0,								0,									0										}
	};

	SPropertyMap gcProps_custom[] =
	{
		{	_INDEX_APPLICATION,				(u32)&iObj_set_application,			(u32)&iObj_get_application				},
		{	_INDEX_BASECLASS,				(u32)&iObj_set_baseClass,			(u32)&iObj_get_baseClass				},
		{	_INDEX_CLASS,					(u32)&iObj_set_class,				(u32)&iObj_get_class					},
		{	_INDEX_CLASSLIBRARY,			(u32)&iObj_set_classLibrary,		(u32)&iObj_get_classLibrary				},
		{	_INDEX_CONTROLS,				(u32)&iObj_set_controls,			(u32)&iObj_get_controls					},
		{	_INDEX_CONTROLCOUNT,			(u32)&iObj_set_controlCount,		(u32)&iObj_get_controlCount				},
		{	_INDEX_OBJECTS,					(u32)&iObj_set_objects,				(u32)&iObj_get_objects					},
		{	_INDEX_COMMENT,					(u32)&iObj_set_comment,				(u32)&iObj_get_comment					},
		{	_INDEX_HEIGHT,					(u32)&iObj_set_height,				(u32)&iObj_get_height					},
		{	_INDEX_HELPCONTEXTID,			(u32)&iObj_set_helpContextID,		(u32)&iObj_get_helpContextID			},
		{	_INDEX_LEFT,					(u32)&iObj_set_left,				(u32)&iObj_get_left						},
		{	_INDEX_NAME,					(u32)&iObj_set_name,				(u32)&iObj_get_name						},
		{	_INDEX_PARENT,					(u32)&iObj_set_parent,				(u32)&iObj_get_parent					},
		{	_INDEX_PARENTCLASS,				(u32)&iObj_set_parentClass,			(u32)&iObj_get_parentClass				},
		{	_INDEX_PICTURE,					(u32)&iObj_set_picture,				(u32)&iObj_get_picture					},
		{	_INDEX_TAG,						(u32)&iObj_set_tag,					(u32)&iObj_get_tag						},
		{	_INDEX_TOP,						(u32)&iObj_set_top,					(u32)&iObj_get_top						},
		{	_INDEX_WHATSTHISHELPID,			(u32)&iObj_set_whatsThisHelpID,		(u32)&iObj_get_whatsThisHelpID			},
		{	_INDEX_WIDTH,					(u32)&iObj_set_width,				(u32)&iObj_get_width					},
		{	0,								0,									0										}
	};

	SPropertyMap gcProps_exception[] =
	{
		{	_INDEX_DETAILS,					(u32)&iObj_set_details,				(u32)&iObj_get_details					},
		{	_INDEX_ERRORNO,					(u32)&iObj_set_errorNo,				(u32)&iObj_get_errorNo					},
		{	_INDEX_LINECONTENTS,			(u32)&iObj_set_lineContents,		(u32)&iObj_get_lineContents				},
		{	_INDEX_LINENO,					(u32)&iObj_set_lineNo,				(u32)&iObj_get_lineNo					},
		{	_INDEX_MESSAGE,					(u32)&iObj_set_message,				(u32)&iObj_get_message					},
		{	_INDEX_PROCEDURE,				(u32)&iObj_set_procedure,			(u32)&iObj_get_procedure				},
		{	_INDEX_STACKLEVEL,				(u32)&iObj_set_stackLevel,			(u32)&iObj_get_stackLevel				},
		{	_INDEX_USERVALUE,				(u32)&iObj_set_userValue,			(u32)&iObj_get_userValue				},
		{	_INDEX_BASECLASS,				(u32)&iObj_set_baseClass,			(u32)&iObj_get_baseClass				},
		{	_INDEX_CLASS,					(u32)&iObj_set_class,				(u32)&iObj_get_class					},
		{	_INDEX_CLASSLIBRARY,			(u32)&iObj_set_classLibrary,		(u32)&iObj_get_classLibrary				},
		{	_INDEX_COMMENT,					(u32)&iObj_set_comment,				(u32)&iObj_get_comment					},
		{	_INDEX_NAME,					(u32)&iObj_set_name,				(u32)&iObj_get_name						},
		{	_INDEX_PARENT,					(u32)&iObj_set_parent,				(u32)&iObj_get_parent					},
		{	_INDEX_PARENTCLASS,				(u32)&iObj_set_parentClass,			(u32)&iObj_get_parentClass				},
		{	_INDEX_TAG,						(u32)&iObj_set_tag,					(u32)&iObj_get_tag						},
		{	0,								0,									0										}
	};




//////////
// Baseclass translation text name to objType, and objType to full record
//////
	SBaseclassList gsKnownBaseclasses[] = {
		//	objType					Text name				Length of name						Base object property list
		//	------------------		-----------------		-------------------------------		-------------------------------
		{	_OBJ_TYPE_EMPTY,		cgcName_empty,			sizeof(cgcName_empty)		- 1,	(u32)&gcProps_empty[0]			},
		{	_OBJ_TYPE_SUBFORM,		cgcName_subform,		sizeof(cgcName_subform)		- 1,	(u32)&gcProps_subform[0]		},
		{	_OBJ_TYPE_BUTTON,		cgcName_button,			sizeof(cgcName_button)		- 1,	(u32)&gcProps_button[0]			},
		{	_OBJ_TYPE_RADIO,		cgcName_radio,			sizeof(cgcName_radio)		- 1,	(u32)&gcProps_radio[0]			},
		{	_OBJ_TYPE_CHECKBOX,		cgcName_checkbox,		sizeof(cgcName_checkbox)	- 1,	(u32)&gcProps_checkbox[0]		},
		{	_OBJ_TYPE_CMDGROUP,		cgcName_cmdgroup,		sizeof(cgcName_cmdgroup)	- 1,	(u32)&gcProps_cmdgroup[0]		},
		{	_OBJ_TYPE_LABEL,		cgcName_label,			sizeof(cgcName_label)		- 1,	(u32)&gcProps_label[0]			},
		{	_OBJ_TYPE_OPTION,		cgcName_option,			sizeof(cgcName_option)		- 1,	(u32)&gcProps_option[0]			},
		{	_OBJ_TYPE_OPTGROUP,		cgcName_optgroup,		sizeof(cgcName_optgroup)	- 1,	(u32)&gcProps_optgroup[0]		},
		{	_OBJ_TYPE_TEXTBOX,		cgcName_textbox,		sizeof(cgcName_textbox)		- 1,	(u32)&gcProps_textbox[0]		},
		{	_OBJ_TYPE_LISTBOX,		cgcName_listbox,		sizeof(cgcName_listbox)		- 1,	(u32)&gcProps_listbox[0]		},
		{	_OBJ_TYPE_COMBOBOX,		cgcName_combobox,		sizeof(cgcName_combobox)	- 1,	(u32)&gcProps_combobox[0]		},
		{	_OBJ_TYPE_FORM,			cgcName_form,			sizeof(cgcName_form)		- 1,	(u32)&gcProps_form[0]			},
		{	_OBJ_TYPE_FORMSET,		cgcName_formset,		sizeof(cgcName_formset)		- 1,	(u32)&gcProps_formset[0]		},
		{	_OBJ_TYPE_TOOLBAR,		cgcName_toolbar,		sizeof(cgcName_toolbar)		- 1,	(u32)&gcProps_toolbar[0]		},
		{	_OBJ_TYPE_SEPARATOR,	cgcName_separator,		sizeof(cgcName_separator)	- 1,	(u32)&gcProps_separator[0]		},
		{	_OBJ_TYPE_LINE,			cgcName_line,			sizeof(cgcName_line)		- 1,	(u32)&gcProps_line[0]			},
		{	_OBJ_TYPE_SHAPE,		cgcName_shape,			sizeof(cgcName_shape)		- 1,	(u32)&gcProps_shape[0]			},
		{	_OBJ_TYPE_IMAGE,		cgcName_image,			sizeof(cgcName_image)		- 1,	(u32)&gcProps_image[0]			},
		{	_OBJ_TYPE_CONTAINER,	cgcName_container,		sizeof(cgcName_container)	- 1,	(u32)&gcProps_container[0]		},
		{	_OBJ_TYPE_CONTROL,		cgcName_control,		sizeof(cgcName_control)		- 1,	(u32)&gcProps_control[0]		},
		{	_OBJ_TYPE_GRID,			cgcName_grid,			sizeof(cgcName_grid)		- 1,	(u32)&gcProps_grid[0]			},
		{	_OBJ_TYPE_COLUMN,		cgcName_column,			sizeof(cgcName_column)		- 1,	(u32)&gcProps_column[0]			},
		{	_OBJ_TYPE_HEADER,		cgcName_header,			sizeof(cgcName_header)		- 1,	(u32)&gcProps_header[0]			},
		{	_OBJ_TYPE_OLEBOUND,		cgcName_olebound,		sizeof(cgcName_olebound)	- 1,	(u32)&gcProps_olebound[0]		},
		{	_OBJ_TYPE_OLECONTAIN,	cgcName_olecontain,		sizeof(cgcName_olecontain)	- 1,	(u32)&gcProps_olecontain[0]		},
		{	_OBJ_TYPE_SPINNER,		cgcName_spinner,		sizeof(cgcName_spinner)		- 1,	(u32)&gcProps_spinner[0]		},
		{	_OBJ_TYPE_TIMER,		cgcName_timer,			sizeof(cgcName_timer)		- 1,	(u32)&gcProps_timer[0]			},
		{	_OBJ_TYPE_HYPERLINK,	cgcName_hyperlink,		sizeof(cgcName_hyperlink)	- 1,	(u32)&gcProps_hyperlink[0]		},
		{	_OBJ_TYPE_COLLECTION,	cgcName_collection,		sizeof(cgcName_collection)	- 1,	(u32)&gcProps_collection[0]		},
		{	_OBJ_TYPE_PAGE,			cgcName_page,			sizeof(cgcName_page)		- 1,	(u32)&gcProps_page[0]			},
		{	_OBJ_TYPE_PAGEFRAME,	cgcName_pageframe,		sizeof(cgcName_pageframe)	- 1,	(u32)&gcProps_pageframe[0]		},
		{	_OBJ_TYPE_SESSION,		cgcName_session,		sizeof(cgcName_session)		- 1,	(u32)&gcProps_session[0]		},
		{	_OBJ_TYPE_CUSTOM,		cgcName_custom,			sizeof(cgcName_custom)		- 1,	(u32)&gcProps_custom[0]			},
		{	_OBJ_TYPE_EXCEPTION,	cgcName_exception,		sizeof(cgcName_exception)	- 1,	(u32)&gcProps_exception[0]		},
		// Note:  Do not delete this line, it is used to terminate the search list
		{	0,						NULL,					0,									0	}
	};

