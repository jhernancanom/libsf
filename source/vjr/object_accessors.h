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


	// Basic setters and getters
	// Note:  The _direct()* function variations are used to bypass the normal setters
	//         and getters, and should be used for internal use only.
	bool					iObj_set_bitmap							(SObject* obj, u32 tnIndex, SBitmap* bmp);
	bool					iObj_set_character						(SObject* obj, u32 tnIndex, SVariable* var);
	bool					iObj_set_character_direct				(SObject* obj, u32 tnIndex, cs8* tcText, u32 tnTextLength);
	bool					iObj_set_character_direct				(SObject* obj, u32 tnIndex,  s8* tcText, u32 tnTextLength);
	bool					iObj_set_f64							(SObject* obj, u32 tnIndex, SVariable* var);
	bool					iObj_set_logical						(SObject* obj, u32 tnIndex, SVariable* var);
	bool					iObj_set_logical_direct					(SObject* obj, u32 tnIndex, s32 tnValue);
	bool					iObj_set_object							(SObject* obj, u32 tnIndex, SVariable* var);
	bool					iObj_set_s32							(SObject* obj, u32 tnIndex, SVariable* var);
	bool					iObj_set_s32_direct						(SObject* obj, u32 tnIndex, s32 tnValue);

	SVariable*				iObj_get_variable_byIndex				(SObject* obj, u32 tnIndex);
	SVariable*				iObj_get_variable_byName				(SObject* obj, u32 tnIndex, s8* tcName, u32 tnNameLength, bool tlSearchBaseProps, bool tlSearchUserProps);
	SBitmap*				iObj_get_bitmap							(SObject* obj, u32 tnIndex);
	SVariable*				iObj_get_character						(SObject* obj, u32 tnIndex);
	SVariable*				iObj_get_f64							(SObject* obj, u32 tnIndex);
	SVariable*				iObj_get_logical						(SObject* obj, u32 tnIndex);
	// Note:  The s32 value returned will be a _LOGICAL_* or _LOGICALX_* value.  To test for .T., use (x != _LOGICAL_FALSE).
	s32						iObj_get_logical_direct					(SObject* obj, u32 tnIndex);
	SVariable*				iObj_get_object							(SObject* obj, u32 tnIndex);
	SVariable*				iObj_get_s32							(SObject* obj, u32 tnIndex);
	s32						iObj_get_s32_direct						(SObject* obj, u32 tnIndex);
	SBgra					iObj_get_sbgra_direct					(SObject* obj, u32 tnIndex);


	// For different types of properties
	struct SPropertyInits
	{
		// Constant index
		u32			index;

		// Property name
		cs8*		prop;								// Property
		u32			length;								// Length of the property name

		// Default variable type
		s32			varType;

		// Setter
		union {
			u32			_setter;
			bool		(*setterOVar)	(SObject* obj, u32 tnIndex, SVariable* var);
			bool		(*setterBmp)	(SObject* obj, u32 tnIndex, SBitmap* bmp);
		};

		// Getter
		union {
			u32			_getter;
			SVariable*	(*getterVar)	(SObject* obj, u32 tnIndex);
			SBitmap*	(*getterBmp)	(SObject* obj, u32 tnIndex);
		};

		// An amalgam of default values
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
	SPropertyInits gsProps_masterDefaultInitValues[] =
	{
		{	_INDEX_ACTIVECOLUMN,			cgc_activeColumn,				sizeof(cgc_activeColumn) - 1,				_VAR_TYPE_S32,			     (u32)&iObj_set_s32,			(u32)&iObj_get_s32,				0		},
		{	_INDEX_ACTIVECONTROL,			cgc_activeControl,				sizeof(cgc_activeControl) - 1,				_VAR_TYPE_OBJECT,		     (u32)&iObj_set_object, 		(u32)&iObj_get_object,			0		},
		{	_INDEX_ACTIVEFORM,				cgc_activeForm,					sizeof(cgc_activeForm) - 1,					_VAR_TYPE_OBJECT,		     (u32)&iObj_set_object, 		(u32)&iObj_get_object,			0		},
		{	_INDEX_ACTIVEPAGE,				cgc_activePage,					sizeof(cgc_activePage) - 1,					_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,				0		},
		{	_INDEX_ACTIVEROW,				cgc_activeRow,					sizeof(cgc_activeRow) - 1,					_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,				0		},
		{	_INDEX_ADDLINEFEEDS,			cgc_addLineFeeds,				sizeof(cgc_addLineFeeds) - 1,				_VAR_TYPE_LOGICAL,		     (u32)&iObj_set_logical, 		(u32)&iObj_get_logical,			_LOGICAL_TRUE },			// .t.=yes (default), .f.=no
		{	_INDEX_ALIGN,					cgc_align,						sizeof(cgc_align) - 1,						_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,				0		},					// 0=Standard alignment, 1=top, 2=bottom, 3=left, 4=right
		{	_INDEX_ALIGNMENT,				cgc_alignment,					sizeof(cgc_alignment) - 1,					_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,				0		},					// 0=vertical left, 1=vertical right, 2=centered, 4=top left, 5=top right, 6=top center, 7=bottom left, 8=bottom right, 9=bottom center
		{	_INDEX_ALLOWADDNEW,				cgc_allowAddNew,				sizeof(cgc_allowAddNew) - 1,				_VAR_TYPE_LOGICAL,		     (u32)&iObj_set_logical, 		(u32)&iObj_get_logical,			_LOGICAL_FALSE },			// .t.=yes, .f.=no (default)
		{	_INDEX_ALLOWAUTOCOLUMNFIT,		cgc_allowAutoColumnFit,			sizeof(cgc_allowAutoColumnFit) - 1,			_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,				0		},					// 0=all automatically, 1=individual columns, 2=disabled
		{	_INDEX_ALLOWCELLSELECTION,		cgc_allowCellSelection,			sizeof(cgc_allowCellSelection) - 1,			_VAR_TYPE_LOGICAL,		     (u32)&iObj_set_logical, 		(u32)&iObj_get_logical,			_LOGICAL_TRUE },			// .t.=yes (default), .f.=no
		{	_INDEX_ALLOWHEADERSIZING,		cgc_allowHeaderSizing,			sizeof(cgc_allowHeaderSizing) - 1,			_VAR_TYPE_LOGICAL,		     (u32)&iObj_set_logical, 		(u32)&iObj_get_logical,			_LOGICAL_TRUE },			// .t.=yes (default), .f.=no
		{	_INDEX_ALLOWOUTPUT,				cgc_allowOutput,				sizeof(cgc_allowOutput) - 1,				_VAR_TYPE_LOGICAL,		     (u32)&iObj_set_logical, 		(u32)&iObj_get_logical,			_LOGICAL_TRUE },			// .t.=yes (default), .f.=no
		{	_INDEX_ALLOWROWSIZING,			cgc_allowRowSizing,				sizeof(cgc_allowRowSizing) - 1,				_VAR_TYPE_LOGICAL,		     (u32)&iObj_set_logical, 		(u32)&iObj_get_logical,			_LOGICAL_TRUE },			// .t.=yes (default), .f.=no
		{	_INDEX_ALLOWTABS,				cgc_allowTabs,					sizeof(cgc_allowTabs) - 1,					_VAR_TYPE_LOGICAL,		     (u32)&iObj_set_logical, 		(u32)&iObj_get_logical,			_LOGICAL_TRUE },			// .t.=yes, .f.=no (default) (in editboxes)
		{	_INDEX_ALWAYSONBOTTOM,			cgc_alwaysOnBottom,				sizeof(cgc_alwaysOnBottom) - 1,				_VAR_TYPE_LOGICAL,		     (u32)&iObj_set_logical, 		(u32)&iObj_get_logical,			_LOGICAL_TRUE },			// .t.=yes, .f.=no (default)
		{	_INDEX_ALWAYSONTOP,				cgc_alwaysOnTop,				sizeof(cgc_alwaysOnTop) - 1,				_VAR_TYPE_LOGICAL,		     (u32)&iObj_set_logical, 		(u32)&iObj_get_logical,			_LOGICAL_TRUE },			// .t.=yes, .f.=no (default)
		{	_INDEX_ANCHOR,					cgc_anchor,						sizeof(cgc_anchor) - 1,						_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,				0		},					// 0=top left (default), 1=top absolute, 2=left absolute, 4=bottom absolute, 8=right absolute, 16=top relative, 32=left relative, 64=bottom relative, 128=right relative, 256=horizontal fixed, 512=vertical fixed
		{	_INDEX_APPLICATION,				cgc_application,				sizeof(cgc_application) - 1,				_VAR_TYPE_OBJECT,		     (u32)&iObj_set_object, 		(u32)&iObj_get_object,			0		},					// A pseudo-interface to application objects and methods
		{	_INDEX_AUTOACTIVATE,			cgc_autoActivate,				sizeof(cgc_autoActivate) - 1,				_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,				0		},					// 0=manual, 1=got focus, 2=double click (default), 3=automatic
		{	_INDEX_AUTOCENTER,				cgc_autoCenter,					sizeof(cgc_autoCenter) - 1,					_VAR_TYPE_LOGICAL,		     (u32)&iObj_set_logical, 		(u32)&iObj_get_logical,			_LOGICAL_FALSE },			// .t.=yes, .f.=no (default)
		{	_INDEX_AUTOCOMPSOURCE,			cgc_autoCompSource,				sizeof(cgc_autoCompSource) - 1,				_VAR_TYPE_CHARACTER,	     (u32)&iObj_set_character, 		(u32)&iObj_get_character,		(u32)&cgcNullString[0] },	// Field to track for auto complete
		{	_INDEX_AUTOCOMPTABLE,			cgc_autoCompTable,				sizeof(cgc_autoCompTable) - 1,				_VAR_TYPE_CHARACTER,	     (u32)&iObj_set_character, 		(u32)&iObj_get_character,		(u32)&cgcNullString[0] },	// Table to for auto complete
		{	_INDEX_AUTOCOMPLETE,			cgc_autoComplete,				sizeof(cgc_autoComplete) - 1,				_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,				0		},					// 0=no display, 1=alphabetical, 2=most frequent, 3=most recent, 4=custom weighting
		{	_INDEX_AUTOHIDESCROLLBAR,		cgc_autoHideScrollBar,			sizeof(cgc_autoHideScrollBar) - 1,			_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,				0		},					// 0=no (default), 1=yes
		{	_INDEX_AUTORELEASE,				cgc_autoRelease,				sizeof(cgc_autoRelease) - 1,				_VAR_TYPE_CHARACTER,	     (u32)&iObj_set_character, 		(u32)&iObj_get_character,		1		},					// .t.=released when last form is released, .f.=persists even after last form is released (in formsets)
		{	_INDEX_AUTOSIZE,				cgc_autoSize,					sizeof(cgc_autoSize) - 1,					_VAR_TYPE_LOGICAL,		     (u32)&iObj_set_logical, 		(u32)&iObj_get_logical,			_LOGICAL_FALSE },			// .t.=auto resize, .f.=no auto resize (default)
		{	_INDEX_AUTOVERBMENU,			cgc_autoVerbMenu,				sizeof(cgc_autoVerbMenu) - 1,				_VAR_TYPE_LOGICAL,		     (u32)&iObj_set_logical, 		(u32)&iObj_get_logical,			_LOGICAL_TRUE },			// .t.=shows ole menu on right-click (default), .f.=ignore
		{	_INDEX_BACKCOLOR,				cgc_backColor,					sizeof(cgc_backColor) - 1,					_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,				rgba(255,255,255,255)	},	// White
		{	_INDEX_BACKSTYLE,				cgc_backStyle,					sizeof(cgc_backStyle) - 1,					_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,				1  	    },					// 0=transparent, 1=opaque
		{	_INDEX_BASECLASS,				cgc_baseClass,					sizeof(cgc_baseClass) - 1,					_VAR_TYPE_CHARACTER,	     (u32)&iObj_set_character, 		(u32)&iObj_get_character,		(u32)&cgcNullString[0] },	// Varies by class
		{	_INDEX_BINDCONTROLS,			cgc_bindControls,				sizeof(cgc_bindControls) - 1,				_VAR_TYPE_LOGICAL,		     (u32)&iObj_set_logical, 		(u32)&iObj_get_logical,			_LOGICAL_TRUE },			// .t.=immediately bind, .f.=delayed binding (not used in Visual FreePro, Jr. as all controls delay binding and complete load operations)
		{	_INDEX_BORDERCOLOR,				cgc_borderColor,				sizeof(cgc_borderColor) - 1,				_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,				0  	    },					// Black
		{	_INDEX_BORDERSTYLE,				cgc_borderStyle,				sizeof(cgc_borderStyle) - 1,				_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,				0  	    },					// 0=none, 1=fixed; for lines or shapes 0=none, 1=solid, 2=dash, 3=dot, 4=dash-dot, 5=dash-dash-dot, 6=inside solid; for forms 0=none, 1=fixed single, 2=fixed double, 3=sizable (not used in Visual FreePro, Jr., all windows are sizable with resize event overrides to limit the size)
		{	_INDEX_BORDERWIDTH,				cgc_borderWidth,				sizeof(cgc_borderWidth) - 1,				_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,				1  	    },					// 1 pixel
		{	_INDEX_BOUND,					cgc_bound,						sizeof(cgc_bound) - 1,						_VAR_TYPE_LOGICAL,		     (u32)&iObj_set_logical, 		(u32)&iObj_get_logical,			_LOGICAL_FALSE },			// .t.=bound, .f.=not bound, not used in Visual FreePro, Jr. as all controls are not bound
		{	_INDEX_BOUNDCOLUMN,				cgc_boundColumn,				sizeof(cgc_boundColumn) - 1,				_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,				1  	    },					// Column 1 default
		{	_INDEX_BOUNDTO,					cgc_boundTo,					sizeof(cgc_boundTo) - 1,					_VAR_TYPE_LOGICAL,		     (u32)&iObj_set_logical, 		(u32)&iObj_get_logical,			_LOGICAL_FALSE },			// .t.=per list property (default), .f.=based on controlsource, if character then list property, if numeric then listindex property
		{	_INDEX_BUFFERMODE,				cgc_bufferMode,					sizeof(cgc_bufferMode) - 1,					_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,				0  	    },					// 0=none (default), 1=pessimistic, 2=optimistic
		{	_INDEX_BUTTONCOUNT,				cgc_buttonCount,				sizeof(cgc_buttonCount) - 1,				_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,				2  	    },					// 2 buttons
		{	_INDEX_CANCEL,					cgc_cancel,						sizeof(cgc_cancel) - 1,						_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,				0  	    },					// .t.=the control is a cancel, .f.=normal control (default)
		{	_INDEX_CAPTION,					cgc_caption,					sizeof(cgc_caption) - 1,					_VAR_TYPE_CHARACTER,	     (u32)&iObj_set_character, 		(u32)&iObj_get_character,		(u32)&cgcNullString[0] },	// Varies by class
		{	_INDEX_CENTERED,				cgc_centered,					sizeof(cgc_centered) - 1,					_VAR_TYPE_LOGICAL,		     (u32)&iObj_set_logical, 		(u32)&iObj_get_logical,			_LOGICAL_FALSE },			// .t.=centered between boundaries, .f.=not centered (default)
		{	_INDEX_CENTURY,					cgc_century,					sizeof(cgc_century) - 1,					_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,				1  	    },					// 0=off, 1=on, 2=uses SET CENTURY setting
		{	_INDEX_CHILDORDER,				cgc_childOrder,					sizeof(cgc_childOrder) - 1,					_VAR_TYPE_CHARACTER,	     (u32)&iObj_set_character, 		(u32)&iObj_get_character,		(u32)&cgcNullString[0] },	// Tag name
		{	_INDEX_CLASS,					cgc_class,						sizeof(cgc_class) - 1,						_VAR_TYPE_CHARACTER,	     (u32)&iObj_set_character, 		(u32)&iObj_get_character,		(u32)&cgcNullString[0] },	// Varies by class
		{	_INDEX_CLASSLIBRARY,			cgc_classLibrary,				sizeof(cgc_classLibrary) - 1,				_VAR_TYPE_CHARACTER,	     (u32)&iObj_set_character, 		(u32)&iObj_get_character,		(u32)&cgcNullString[0] },	// Varies by class
		{	_INDEX_CLIPCONTROLS,			cgc_clipControls,				sizeof(cgc_clipControls) - 1,				_VAR_TYPE_LOGICAL,		     (u32)&iObj_set_logical, 		(u32)&iObj_get_logical,			_LOGICAL_TRUE },			// .t.=repaints entire object (default), .f.=only paints newly exposed areas
		{	_INDEX_CLOSABLE,				cgc_closable,					sizeof(cgc_closable) - 1,					_VAR_TYPE_LOGICAL,		     (u32)&iObj_set_logical, 		(u32)&iObj_get_logical,			_LOGICAL_TRUE },			// .t.=close icon (default), .f.=no close icon
		{	_INDEX_COLORSCHEME,				cgc_colorScheme,				sizeof(cgc_colorScheme) - 1,				_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,				0  	    },					// Not used in Visual FreePro, Jr.
		{	_INDEX_COLORSOURCE,				cgc_colorSource,				sizeof(cgc_colorSource) - 1,				_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,				0  	    },					// 0=object (default), 1=form, 2=colorscheme property, 3=default scheme, 4=windows 3d surface, 5=windows
		{	_INDEX_COLUMNCOUNT,				cgc_columnCount,				sizeof(cgc_columnCount) - 1,				_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,				1  	    },					// The number of columns on the control, varies by control
		{	_INDEX_COLUMNLINES,				cgc_columnLines,				sizeof(cgc_columnLines) - 1,				_VAR_TYPE_LOGICAL,		     (u32)&iObj_set_logical, 		(u32)&iObj_get_logical,			_LOGICAL_TRUE },			// .t.=visible (default), .f.=not visible
		{	_INDEX_COLUMNORDER,				cgc_columnOrder,				sizeof(cgc_columnOrder) - 1,				_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,				0  	    },					// This column's order
		{	_INDEX_COLUMNWIDTHS,			cgc_columnWidths,				sizeof(cgc_columnWidths) - 1,				_VAR_TYPE_CHARACTER,	     (u32)&iObj_set_character, 		(u32)&iObj_get_character,		0		},					// A comma-delimited string
		{	_INDEX_COLUMNS,					cgc_columns,					sizeof(cgc_columns) - 1,					_VAR_TYPE_OBJECT,		     (u32)&iObj_set_object, 		(u32)&iObj_get_object,			0	    },					// A pseudo-object to access columns within
		{	_INDEX_COMMENT,					cgc_comment,					sizeof(cgc_comment) - 1,					_VAR_TYPE_CHARACTER,	     (u32)&iObj_set_character, 		(u32)&iObj_get_character,		(u32)&cgcNullString[0] },	// Unspecified
		{	_INDEX_CONTINUOUSSCROLL,		cgc_continuousScroll,			sizeof(cgc_continuousScroll) - 1,			_VAR_TYPE_LOGICAL,		     (u32)&iObj_set_logical, 		(u32)&iObj_get_logical,			_LOGICAL_TRUE },			// .t.=scrolls with mouse down (default), .f.=scrolls only when released
		{	_INDEX_CONTROLBOX,				cgc_controlBox,					sizeof(cgc_controlBox) - 1,					_VAR_TYPE_LOGICAL,		     (u32)&iObj_set_logical, 		(u32)&iObj_get_logical,			_LOGICAL_TRUE },			// .t.=form and subform icon (default), .f.=no icon
		{	_INDEX_CONTROLCOUNT,			cgc_controlCount,				sizeof(cgc_controlCount) - 1,				_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,				0  	    },					// Varies, based on number of direct child objects
		{	_INDEX_CONTROLSOURCE,			cgc_controlSource,				sizeof(cgc_controlSource) - 1,				_VAR_TYPE_CHARACTER,	     (u32)&iObj_set_character, 		(u32)&iObj_get_character,		(u32)&cgcNullString[0] },	// The source for the object
		{	_INDEX_CONTROLS,				cgc_controls,					sizeof(cgc_controls) - 1,					_VAR_TYPE_OBJECT,		     (u32)&iObj_set_object, 		(u32)&iObj_get_object,			0	    },					// A psuedo-object to access controls within
		{	_INDEX_COUNT,					cgc_count,						sizeof(cgc_count) - 1,						_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,				0  	    },					// Number of items in the object
		{	_INDEX_CURRENTCONTROL,			cgc_currentControl,				sizeof(cgc_currentControl) - 1,				_VAR_TYPE_OBJECT,		     (u32)&iObj_set_object, 		(u32)&iObj_get_object,			0	    },					// Which control in a column is used for display
		{	_INDEX_CURRENTX,				cgc_currentX,					sizeof(cgc_currentX) - 1,					_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,				0  	    },					// The X coordinate for drawing (not used in Visual FreePro, Jr.)
		{	_INDEX_CURRENTY,				cgc_currentY,					sizeof(cgc_currentY) - 1,					_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,				0  	    },					// The Y coordinate for drawing (not used in Visual FreePro, Jr.)
		{	_INDEX_CURVATURE,				cgc_curvature,					sizeof(cgc_curvature) - 1,					_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,				0  	    },					// 0=none, 1..98=rounded, 99=full circle
		{	_INDEX_DECLASS,					cgc_dEClass,					sizeof(cgc_dEClass) - 1,					_VAR_TYPE_CHARACTER,	     (u32)&iObj_set_character, 		(u32)&iObj_get_character,		(u32)&cgcNullString[0] },	// Varies
		{	_INDEX_DECLASSLIBRARY,			cgc_dEClassLibrary,				sizeof(cgc_dEClassLibrary) - 1,				_VAR_TYPE_CHARACTER,	     (u32)&iObj_set_character, 		(u32)&iObj_get_character,		(u32)&cgcNullString[0] },	// Varies
		{	_INDEX_DATAENVIRONMENT,			cgc_dataEnvironment,			sizeof(cgc_dataEnvironment) - 1,			_VAR_TYPE_OBJECT,		     (u32)&iObj_set_object, 		(u32)&iObj_get_object,			0		},					// Varies
		{	_INDEX_DATASESSION,				cgc_dataSession,				sizeof(cgc_dataSession) - 1,				_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,				0  	    },					// 0=default, 1=private
		{	_INDEX_DATASESSIONID,			cgc_dataSessionID,				sizeof(cgc_dataSessionID) - 1,				_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,				0  	    },					// Varies
		{	_INDEX_DATEFORMAT,				cgc_dateFormat,					sizeof(cgc_dateFormat) - 1,					_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,				0  	    },					// 0=use SET DATE (default), 1=American mm/dd/yy, 2=ANSI yy.mm.dd, 3=British dd/mm/yy, 4=Italian dd-mm-yy, 5= French dd/mm/yy, 6=German dd.mm.yy, 7=Japan yy/mm/dd, 8= Taiwan yy/mm/dd, 9=USA mm-dd-yy, 10=MDY mm/dd/yy, 11=DMY dd/mm/yy, 12=YMD yy/mm/dd, 12=short per Windows' settings, 13=long per Windows' settings
		{	_INDEX_DATEMARK,				cgc_dateMark,					sizeof(cgc_dateMark) - 1,					_VAR_TYPE_CHARACTER,	     (u32)&iObj_set_character, 		(u32)&iObj_get_character,		0 	    },					// If unspecified, uses SET MARK
		{	_INDEX_DEFOLELCID,				cgc_defOLELCID,					sizeof(cgc_defOLELCID) - 1,					_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,				0  	    },					// Default locale ID
		{	_INDEX_DEFAULT,					cgc_default,					sizeof(cgc_default) - 1,					_VAR_TYPE_LOGICAL,		     (u32)&iObj_set_logical, 		(u32)&iObj_get_logical,			_LOGICAL_FALSE },			// .t.=Control to trigger with enter key, .f.=do not trigger (default)
		{	_INDEX_DELETEMARK,				cgc_deleteMark,					sizeof(cgc_deleteMark) - 1,					_VAR_TYPE_LOGICAL,		     (u32)&iObj_set_logical, 		(u32)&iObj_get_logical,			_LOGICAL_TRUE },			// .t.=show deleted() mark (default), .f.=do not show
		{	_INDEX_DESKTOP,					cgc_desktop,					sizeof(cgc_desktop) - 1,					_VAR_TYPE_LOGICAL,		     (u32)&iObj_set_logical, 		(u32)&iObj_get_logical,			_LOGICAL_FALSE },			// .t.=show anywhere, .f.=show only in Visual FreePro, Jr. screen (default)
		{	_INDEX_DETAILS,					cgc_details,					sizeof(cgc_details) - 1,					_VAR_TYPE_CHARACTER,	     (u32)&iObj_set_character, 		(u32)&iObj_get_character,		(u32)&cgcNullString[0] },	// Additional information about an exception
		{	_INDEX_DISABLEDBACKCOLOR,		cgc_disabledBackColor,			sizeof(cgc_disabledBackColor) - 1,			_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,				_disabledBackColor },
		{	_INDEX_DISABLEDFORECOLOR,		cgc_disabledForeColor,			sizeof(cgc_disabledForeColor) - 1,			_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,				_disabledForeColor },
		{	_INDEX_DISABLEDITEMBACKCOLOR,	cgc_disabledItemBackColor,		sizeof(cgc_disabledItemBackColor) - 1,		_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,				_disabledBackColor },
		{	_INDEX_DISABLEDITEMFORECOLOR,	cgc_disabledItemForeColor,		sizeof(cgc_disabledItemForeColor) - 1,		_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,				_disabledForeColor },
		{	_INDEX_DISABLEDPICTURE,			cgc_disabledPicture,			sizeof(cgc_disabledPicture) - 1,			_VAR_TYPE_BITMAP,		     (u32)&iObj_set_bitmap, 		(u32)&iObj_get_bitmap,			0		},					// No picture by default
		{	_INDEX_DISPLAYCOUNT,			cgc_displayCount,				sizeof(cgc_displayCount) - 1,				_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,				0  		},					// Default number of items to display in a combobox
		{	_INDEX_DISPLAYVALUE,			cgc_displayValue,				sizeof(cgc_displayValue) - 1,				_VAR_TYPE_CHARACTER,	     (u32)&iObj_set_character, 		(u32)&iObj_get_character,		(u32)&cgcNullString[0] },	// The displayed value in a listbox or combobox
		{	_INDEX_DOCREATE,				cgc_doCreate,					sizeof(cgc_doCreate) - 1,					_VAR_TYPE_LOGICAL,		     (u32)&iObj_set_logical, 		(u32)&iObj_get_logical,			_LOGICAL_TRUE },			// A pseudo-property indicating if the form should actually be created
		{	_INDEX_DOCKPOSITION,			cgc_dockPosition,				sizeof(cgc_dockPosition) - 1,				_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,				0  		},					// -1=not docked, 0=top, 1=left, 2=right, 3=bottom, 4=tabbed, 5=link-docked
		{	_INDEX_DOCKABLE,				cgc_dockable,					sizeof(cgc_dockable) - 1,					_VAR_TYPE_LOGICAL,		     (u32)&iObj_set_logical, 		(u32)&iObj_get_logical,			_LOGICAL_FALSE },			// .t.=yes, .f.=no (default)
		{	_INDEX_DOCKED,					cgc_docked,						sizeof(cgc_docked) - 1,						_VAR_TYPE_LOGICAL,		     (u32)&iObj_set_logical, 		(u32)&iObj_get_logical,			_LOGICAL_FALSE },			// .t.=yes, .f.=no (default)
		{	_INDEX_DOCUMENTFILE,			cgc_documentFile,				sizeof(cgc_documentFile) - 1,				_VAR_TYPE_CHARACTER,	     (u32)&iObj_set_character, 		(u32)&iObj_get_character,		(u32)&cgcNullString[0] },	// Name of the OLE-bound document file (if any)
		{	_INDEX_DOWNPICTURE,				cgc_downPicture,				sizeof(cgc_downPicture) - 1,				_VAR_TYPE_CHARACTER,	     (u32)&iObj_set_character, 		(u32)&iObj_get_character,		(u32)&cgcNullString[0] },	// Name of the graphic to display when the mouse is down
		{	_INDEX_DRAGICON,				cgc_dragIcon,					sizeof(cgc_dragIcon) - 1,					_VAR_TYPE_CHARACTER,	     (u32)&iObj_set_character, 		(u32)&iObj_get_character,		(u32)&cgcNullString[0] },	// Name of the icon to display when the object is being dragged
		{	_INDEX_DRAGMODE,				cgc_dragMode,					sizeof(cgc_dragMode) - 1,					_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,				0  		},					// 0=manual (default), 1=automatic
		{	_INDEX_DRAWMODE,				cgc_drawMode,					sizeof(cgc_drawMode) - 1,					_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,				13  	},					// 1=black pen, 2=NOT Merge pen, 3=mask NOT pen, 4=NOT copy pen, 5=mask NOT pen, 6=invert, 7=xor, 8=NOT mask pen, 9=mask pen, 10=NOT xor, 11=NOP, 12=merge NOT pen, 13=copy, 14=merge pen NOT, 15=merge pen, 16=white pen
		{	_INDEX_DRAWSTYLE,				cgc_drawStyle,					sizeof(cgc_drawStyle) - 1,					_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,				0  		},					// 0=solid, 1=dash, 2=dot, 3=dash-dot, 4=dash-dot-dot, 5=transparent, 6=inside solid
		{	_INDEX_DRAWWIDTH,				cgc_drawWidth,					sizeof(cgc_drawWidth) - 1,					_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,				1  		},					// Pixel width for drawing
		{	_INDEX_DYNAMICALIGNMENT,		cgc_dynamicAlignment,			sizeof(cgc_dynamicAlignment) - 1,			_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,				3  		},					// 0=middle left, 1=middle right, 2=middle center, 3=automatic (default), 4=top left, 5=top right, 6=top center, 7=bottom left, 8=bottom right, 9=bottom center
		{   _INDEX_DYNAMICBACKCOLOR,        cgc_dynamicBackColor,           sizeof(cgc_dynamicBackColor) - 1,           _VAR_TYPE_CHARACTER,         (u32)&iObj_set_character,      (u32)&iObj_get_character,       (u32)&cgcNullString[0] },   // Character expression evaluated for the value
		{   _INDEX_DYNAMICCURRENTCONTROL,   cgc_dynamicCurrentControl,      sizeof(cgc_dynamicCurrentControl) - 1,      _VAR_TYPE_CHARACTER,         (u32)&iObj_set_character,      (u32)&iObj_get_character,       (u32)&cgcNullString[0] },   // Character expression evaluated for the active control for that cell
		{   _INDEX_DYNAMICFONTBOLD,         cgc_dynamicFontBold,            sizeof(cgc_dynamicFontBold) - 1,            _VAR_TYPE_CHARACTER,         (u32)&iObj_set_character,      (u32)&iObj_get_character,       (u32)&cgcNullString[0] },   // Character expression evaluated for the value
		{   _INDEX_DYNAMICFONTITALIC,       cgc_dynamicFontItalic,          sizeof(cgc_dynamicFontItalic) - 1,          _VAR_TYPE_CHARACTER,         (u32)&iObj_set_character,      (u32)&iObj_get_character,       (u32)&cgcNullString[0] },   // Character expression evaluated for the value
		{   _INDEX_DYNAMICFONTNAME,         cgc_dynamicFontName,            sizeof(cgc_dynamicFontName) - 1,            _VAR_TYPE_CHARACTER,         (u32)&iObj_set_character,      (u32)&iObj_get_character,       (u32)&cgcNullString[0] },   // Character expression evaluated for the value
		{   _INDEX_DYNAMICFONTOUTLINE,      cgc_dynamicFontOutline,         sizeof(cgc_dynamicFontOutline) - 1,         _VAR_TYPE_CHARACTER,         (u32)&iObj_set_character,      (u32)&iObj_get_character,       (u32)&cgcNullString[0] },   // Character expression evaluated for the value
		{   _INDEX_DYNAMICFONTSHADOW,       cgc_dynamicFontShadow,          sizeof(cgc_dynamicFontShadow) - 1,          _VAR_TYPE_CHARACTER,         (u32)&iObj_set_character,      (u32)&iObj_get_character,       (u32)&cgcNullString[0] },   // Character expression evaluated for the value
		{   _INDEX_DYNAMICFONTSIZE,         cgc_dynamicFontSize,            sizeof(cgc_dynamicFontSize) - 1,            _VAR_TYPE_CHARACTER,         (u32)&iObj_set_character,      (u32)&iObj_get_character,       (u32)&cgcNullString[0] },   // Character expression evaluated for the value
		{   _INDEX_DYNAMICFONTSTRIKETHRU,   cgc_dynamicFontStrikeThru,      sizeof(cgc_dynamicFontStrikeThru) - 1,      _VAR_TYPE_CHARACTER,         (u32)&iObj_set_character,      (u32)&iObj_get_character,       (u32)&cgcNullString[0] },   // Character expression evaluated for the value
		{   _INDEX_DYNAMICFONTUNDERLINE,    cgc_dynamicFontUnderline,       sizeof(cgc_dynamicFontUnderline) - 1,       _VAR_TYPE_CHARACTER,         (u32)&iObj_set_character,      (u32)&iObj_get_character,       (u32)&cgcNullString[0] },   // Character expression evaluated for the value
		{   _INDEX_DYNAMICFORECOLOR,        cgc_dynamicForeColor,           sizeof(cgc_dynamicForeColor) - 1,           _VAR_TYPE_CHARACTER,         (u32)&iObj_set_character,      (u32)&iObj_get_character,       (u32)&cgcNullString[0] },   // Character expression evaluated for the value
		{   _INDEX_DYNAMICINPUTMASK,        cgc_dynamicInputMask,           sizeof(cgc_dynamicInputMask) - 1,           _VAR_TYPE_CHARACTER,         (u32)&iObj_set_character,      (u32)&iObj_get_character,       (u32)&cgcNullString[0] },   // Character expression evaluated for the value
		{	_INDEX_ENABLEHYPERLINKS,		cgc_enableHyperlinks,			sizeof(cgc_enableHyperlinks) - 1,			_VAR_TYPE_LOGICAL,		     (u32)&iObj_set_logical, 		(u32)&iObj_get_logical,			_LOGICAL_TRUE },			// .t.=yes, .f.=no (default) are hyperlinks enabled in an editbox or textbox
		{	_INDEX_ENABLED,					cgc_enabled,					sizeof(cgc_enabled) - 1,					_VAR_TYPE_LOGICAL,		     (u32)&iObj_set_logical, 		(u32)&iObj_get_logical,			_LOGICAL_TRUE },			// .t.=yes (default), .f.=no
		{	_INDEX_ERRORNO,					cgc_errorNo,					sizeof(cgc_errorNo) - 1,					_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,				0  		},					// The error number on an exception
		{	_INDEX_FILLCOLOR,				cgc_fillColor,					sizeof(cgc_fillColor) - 1,					_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,				_whiteColor },				// The default fill color
		{	_INDEX_FILLSTYLE,				cgc_fillStyle,					sizeof(cgc_fillStyle) - 1,					_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,				_FILL_STYLE_TRANSPARENT },	// 0=solid, 1=transparent (default), 2=horizontal lines, 3=vertical line, 4=ul to lr diagonal, 5=ll to ur diagonal, 6=horizontal and vertical, 7=both diagonals
		{	_INDEX_FIRSTELEMENT,			cgc_firstElement,				sizeof(cgc_firstElement) - 1,				_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,				1  		},					// The array element to display in listbox or combobox when rowSourcetype = 5 (array)
		{	_INDEX_FONTBOLD,				cgc_fontBold,					sizeof(cgc_fontBold) - 1,					_VAR_TYPE_LOGICAL,		     (u32)&iObj_set_logical, 		(u32)&iObj_get_logical,			_LOGICAL_FALSE },					// .t.=bold, .f.=not bold (default)
		{	_INDEX_FONTCHARSET,				cgc_fontCharSet,				sizeof(cgc_fontCharSet) - 1,				_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,				1  		},					// The default font set
		{	_INDEX_FONTCONDENSE,			cgc_fontCondense,				sizeof(cgc_fontCondense) - 1,				_VAR_TYPE_LOGICAL,		     (u32)&iObj_set_logical, 		(u32)&iObj_get_logical,			_LOGICAL_FALSE },			// .t.=condense, .f.=not condense (default)
		{	_INDEX_FONTEXTEND,				cgc_fontExtend,					sizeof(cgc_fontExtend) - 1,					_VAR_TYPE_LOGICAL,		     (u32)&iObj_set_logical, 		(u32)&iObj_get_logical,			_LOGICAL_FALSE },			// .t.=extend, .f.=not extend (default)
		{	_INDEX_FONTITALIC,				cgc_fontItalic,					sizeof(cgc_fontItalic) - 1,					_VAR_TYPE_LOGICAL,		     (u32)&iObj_set_logical, 		(u32)&iObj_get_logical,			_LOGICAL_FALSE },			// .t.=italic, .f.=not italic (default)
		{	_INDEX_FONTNAME,				cgc_fontName,					sizeof(cgc_fontName) - 1,					_VAR_TYPE_CHARACTER,	     (u32)&iObj_set_character, 		(u32)&iObj_get_character,		(u32)&cgcFontName_default[0] },	// Ubuntu fonts are used by Visual FreePro, Jr. by default
		{	_INDEX_FONTOUTLINE,				cgc_fontOutline,				sizeof(cgc_fontOutline) - 1,				_VAR_TYPE_LOGICAL,		     (u32)&iObj_set_logical, 		(u32)&iObj_get_logical,			_LOGICAL_FALSE },			// .t.=outline, .f.=not outline (default)
		{	_INDEX_FONTSHADOW,				cgc_fontShadow,					sizeof(cgc_fontShadow) - 1,					_VAR_TYPE_LOGICAL,		     (u32)&iObj_set_logical, 		(u32)&iObj_get_logical,			_LOGICAL_FALSE },			// .t.=shadow, .f.=not shadow (default)
		{	_INDEX_FONTSIZE,				cgc_fontSize,					sizeof(cgc_fontSize) - 1,					_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,				10 		},					// Default font size is 10pt
		{	_INDEX_FONTSTRIKETHRU,			cgc_fontStrikeThru,				sizeof(cgc_fontStrikeThru) - 1,				_VAR_TYPE_LOGICAL,		     (u32)&iObj_set_logical, 		(u32)&iObj_get_logical,			_LOGICAL_FALSE },			// .t.=strikethru, .f.=not strikethru (default)
		{	_INDEX_FONTUNDERLINE,			cgc_fontUnderLine,				sizeof(cgc_fontUnderLine) - 1,				_VAR_TYPE_LOGICAL,		     (u32)&iObj_set_logical, 		(u32)&iObj_get_logical,			_LOGICAL_FALSE },			// .t.=underline, .f.=not underline (default)
		{	_INDEX_FORECOLOR,				cgc_foreColor,					sizeof(cgc_foreColor) - 1,					_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,				0  		},					// Black
		{	_INDEX_FORMCOUNT,				cgc_formCount,					sizeof(cgc_formCount) - 1,					_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,				0  		},					// Number of forms in a form set
		{	_INDEX_FORMAT,					cgc_format,						sizeof(cgc_format) - 1,						_VAR_TYPE_CHARACTER,	     (u32)&iObj_set_character, 		(u32)&iObj_get_character,		(u32)&cgcNullString[0] },	// The input format string
		{	_INDEX_FORMS,					cgc_forms,						sizeof(cgc_forms) - 1,						_VAR_TYPE_OBJECT,		     (u32)&iObj_set_object, 		(u32)&iObj_get_object,			0		},					// A pseudo index object to access the forms of a form set
		{	_INDEX_GRIDLINECOLOR,			cgc_gridLineColor,				sizeof(cgc_gridLineColor) - 1,				_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,				_blackColor },				// The default grid line color
		{	_INDEX_GRIDLINEWIDTH,			cgc_gridLineWidth,				sizeof(cgc_gridLineWidth) - 1,				_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,				1  		},					// The default grid line width
		{	_INDEX_GRIDLINES,				cgc_gridLines,					sizeof(cgc_gridLines) - 1,					_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,				_GRID_LINES_BOTH },			// 0=none, 1=horizontal only, 2=vertical online, 3=both (default)
		{	_INDEX_HSCROLLSMALLCHANGE,		cgc_hScrollSmallChange,			sizeof(cgc_hScrollSmallChange) - 1,			_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,				10 		},					// When scalemode = 3, default is 10 pixels
		{	_INDEX_HWND,					cgc_hWnd,						sizeof(cgc_hWnd) - 1,						_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,				0  		},					// A direct handle to the OS window
		{	_INDEX_HALFHEIGHTCAPTION,		cgc_halfHeightCaption,			sizeof(cgc_halfHeightCaption) - 1,			_VAR_TYPE_LOGICAL,		     (u32)&iObj_set_logical, 		(u32)&iObj_get_logical,			_LOGICAL_FALSE },			// .t.=half height, .f.=full height (default) visual FreePro, Jr. does not use this setting, but it remains for compatibility
		{	_INDEX_HEADERCLASS,				cgc_headerClass,				sizeof(cgc_headerClass) - 1,				_VAR_TYPE_CHARACTER,	     (u32)&iObj_set_character, 		(u32)&iObj_get_character,		(u32)&cgcNullString[0] },	// The default header class for a grid
		{	_INDEX_HEADERCLASSLIBRARY,		cgc_headerClassLibrary,			sizeof(cgc_headerClassLibrary) - 1,			_VAR_TYPE_CHARACTER,	     (u32)&iObj_set_character, 		(u32)&iObj_get_character,		(u32)&cgcNullString[0] },	// The default header class library for a grid
		{	_INDEX_HEADERHEIGHT,			cgc_headerHeight,				sizeof(cgc_headerHeight) - 1,				_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,				0  		},					// The header height for a grid
		{	_INDEX_HEIGHT,					cgc_height,						sizeof(cgc_height) - 1,						_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,				0  		},					// The height of the object
		{	_INDEX_HELPCONTEXTID,			cgc_helpContextID,				sizeof(cgc_helpContextID) - 1,				_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,				0  		},					// The help context id
		{	_INDEX_HIDESELECTION,			cgc_hideSelection,				sizeof(cgc_hideSelection) - 1,				_VAR_TYPE_LOGICAL,		     (u32)&iObj_set_logical, 		(u32)&iObj_get_logical,			_LOGICAL_TRUE },			// .t.=yes (default), .f.=no (should the selected text be hidden (shown as regular text) when the control loses focus)
		{	_INDEX_HIGHLIGHT,				cgc_highLight,					sizeof(cgc_highLight) - 1,					_VAR_TYPE_LOGICAL,		     (u32)&iObj_set_logical, 		(u32)&iObj_get_logical,			_LOGICAL_TRUE },			// .t.=yes (default), .f.=no (should the grid cell be highlighted in navigation)
		{	_INDEX_HIGHLIGHTROW,			cgc_highLightRow,				sizeof(cgc_highLightRow) - 1,				_VAR_TYPE_LOGICAL,		     (u32)&iObj_set_logical, 		(u32)&iObj_get_logical,			_LOGICAL_TRUE },			// .t.=yes (default), .f.=no (should the entire  grid cell row be highlighted in navigation)
		{	_INDEX_HIGHLIGHTBACKCOLOR,		cgc_highlightBackColor,			sizeof(cgc_highlightBackColor) - 1,			_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,				_selectedBackColor },		// The default highlight back color
		{	_INDEX_HIGHLIGHTFORECOLOR,		cgc_highlightForeColor,			sizeof(cgc_highlightForeColor) - 1,			_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,				_selectedForeColor },		// The default highlight fore color
		{	_INDEX_HIGHLIGHTROWLINEWIDTH,	cgc_highlightRowLineWidth,		sizeof(cgc_highlightRowLineWidth) - 1,		_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,				1  		},					// In pixels, the thickness of the border around the entire grid cell row
		{	_INDEX_HIGHLIGHTSTYLE,			cgc_highlightStyle,				sizeof(cgc_highlightStyle) - 1,				_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,				0  		},					// 0=no color (default), 1=highlight current row only, 2=highlight all rows
		{	_INDEX_HOSTNAME,				cgc_hostName,					sizeof(cgc_hostName) - 1,					_VAR_TYPE_CHARACTER,	     (u32)&iObj_set_character, 		(u32)&iObj_get_character,		(u32)&cgcNullString[0] },	// The name to display for OLE controls
		{	_INDEX_HOURS,					cgc_hours,						sizeof(cgc_hours) - 1,						_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,				0  		},					// 0=use SET HOURS (default), 1=12 hour, 2=24-hour
		{	_INDEX_IMEMODE,					cgc_iMEMode,					sizeof(cgc_iMEMode) - 1,					_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,				0  		},					// 0=use OS settings (default), 1=open on focus, 2=close on focus
		// Note:  The increment is updated in the iVjr_init() code because MSVC does not allow anonymous union member declarations.
		{	_INDEX_INCREMENT,				cgc_increment,					sizeof(cgc_increment) - 1,					_VAR_TYPE_F64,			     (u32)&iObj_set_f64, 			(u32)&iObj_get_f64,				0		},					// The default increment for spinners
		{	_INDEX_INCREMENTALSEARCH,		cgc_incrementalSearch,			sizeof(cgc_incrementalSearch) - 1,			_VAR_TYPE_LOGICAL,		     (u32)&iObj_set_logical, 		(u32)&iObj_get_logical,			_LOGICAL_TRUE },			// .t.=yes (default), .f.=no (should keyboard input perform a search on each character)
		{	_INDEX_INPUTMASK,				cgc_inputMask,					sizeof(cgc_inputMask) - 1,					_VAR_TYPE_CHARACTER,	     (u32)&iObj_set_character, 		(u32)&iObj_get_character,		(u32)&cgcNullString[0] },	// The input mask
		{	_INDEX_INTEGRALHEIGHT,			cgc_integralHeight,				sizeof(cgc_integralHeight) - 1,				_VAR_TYPE_LOGICAL,		     (u32)&iObj_set_logical, 		(u32)&iObj_get_logical,			0  		},					// .t.=yes, .f.=no (default) (should the height of a control be auto-adjusted so the last line is fully displayed)
		{	_INDEX_INTERVAL,				cgc_interval,					sizeof(cgc_interval) - 1,					_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,				0		},					// The default interval between timer fires
		{	_INDEX_ITEMBACKCOLOR,			cgc_itemBackColor,				sizeof(cgc_itemBackColor) - 1,				_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,				_whiteColor },				// White
		{	_INDEX_ITEMDATA,				cgc_itemData,					sizeof(cgc_itemData) - 1,					_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,				0  		},					// A pseudo-property used for indexed access to listbox or combobox data
		{	_INDEX_ITEMFORECOLOR,			cgc_itemForeColor,				sizeof(cgc_itemForeColor) - 1,				_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,				_blackColor },				// Black
		{	_INDEX_ITEMIDDATA,				cgc_itemIDData,					sizeof(cgc_itemIDData) - 1,					_VAR_TYPE_OBJECT,		     (u32)&iObj_set_object, 		(u32)&iObj_get_object,			NULL },						// A pseudo index object to access the forms of a form set
		{	_INDEX_ITEMTIPS,				cgc_itemTips,					sizeof(cgc_itemTips) - 1,					_VAR_TYPE_LOGICAL,		     (u32)&iObj_set_logical, 		(u32)&iObj_get_logical,			_LOGICAL_FALSE },			// .t.=shows tips, .f.=do not show (default)
		{	_INDEX_KEYPREVIEW,				cgc_keyPreview,					sizeof(cgc_keyPreview) - 1,					_VAR_TYPE_LOGICAL,		     (u32)&iObj_set_logical, 		(u32)&iObj_get_logical,			_LOGICAL_FALSE },			// .t.=form's keypress fires on object keystrokes, .f.=does not fire (default)
		{	_INDEX_KEYSORT,					cgc_keySort,					sizeof(cgc_keySort) - 1,					_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,				0  		},					// 0=index ascending, 1=index descending, 2=key ascending, 3=key descending
		{	_INDEX_KEYBOARDHIGHVALUE,		cgc_keyboardHighValue,			sizeof(cgc_keyboardHighValue) - 1,			_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,				2147483647 },				// Highest value for a spinner control by keyboard input
		{	_INDEX_KEYBOARDLOWVALUE,		cgc_keyboardLowValue,			sizeof(cgc_keyboardLowValue) - 1,			_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,		-		2147483647 },				// Lowest value for a spinner control by keyboard input
		{	_INDEX_LEFT,					cgc_left,						sizeof(cgc_left) - 1,						_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,				0  		},					// Left coordinate
		{	_INDEX_LEFTCOLUMN,				cgc_leftColumn,					sizeof(cgc_leftColumn) - 1,					_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,				1  		},					// Left-most column in a grid
		{	_INDEX_LINECONTENTS,			cgc_lineContents,				sizeof(cgc_lineContents) - 1,				_VAR_TYPE_CHARACTER,	     (u32)&iObj_set_character, 		(u32)&iObj_get_character,		(u32)&cgcNullString[0] },	// The line that triggered the exception
		{	_INDEX_LINENO,					cgc_lineNo,						sizeof(cgc_lineNo) - 1,						_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,				0  		},					// The line number that triggered the exception
		{	_INDEX_LINESLANT,				cgc_lineSlant,					sizeof(cgc_lineSlant) - 1,					_VAR_TYPE_CHARACTER,	     (u32)&iObj_set_character, 		(u32)&iObj_get_character,		(u32)&cgcBackslash[0] },	// Either \ (default) or / indicating if the line slants up or down, or S indicating it uses polyPoints for a bezier
		{	_INDEX_LINKMASTER,				cgc_linkMaster,					sizeof(cgc_linkMaster) - 1,					_VAR_TYPE_CHARACTER,	     (u32)&iObj_set_character, 		(u32)&iObj_get_character,		(u32)&cgcNullString[0] },	// The linked parent table in a grid
		{	_INDEX_LIST,					cgc_list,						sizeof(cgc_list) - 1,						_VAR_TYPE_OBJECT,		     (u32)&iObj_set_object, 		(u32)&iObj_get_object,			NULL },						// A pseudo-object to access items in a listbox or combobox
		{	_INDEX_LISTCOUNT,				cgc_listCount,					sizeof(cgc_listCount) - 1,					_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,				0  		},					// The number of items in a listbox or combobox
		{	_INDEX_LISTINDEX,				cgc_listIndex,					sizeof(cgc_listIndex) - 1,					_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,				0  		},					// The currently selected item in a listbox or combobox
		{	_INDEX_LISTITEM,				cgc_listItem,					sizeof(cgc_listItem) - 1,					_VAR_TYPE_OBJECT,		     (u32)&iObj_set_object, 		(u32)&iObj_get_object,			NULL },						// A pseudo-object to access or set items in a listbox or combobox
		{	_INDEX_LISTITEMID,				cgc_listItemID,					sizeof(cgc_listItemID) - 1,					_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,				0  		},					// The uid of the selected item in a listbox or combobox
		{	_INDEX_LOCKCOLUMNS,				cgc_lockColumns,				sizeof(cgc_lockColumns) - 1,				_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,				0  		},					// Number of columns to lock on right in a grid or browse window
		{	_INDEX_LOCKCOLUMNSLEFT,			cgc_lockColumnsLeft,			sizeof(cgc_lockColumnsLeft) - 1,			_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,				0  		},					// Number of columns to lock on left in a grid or browse window
		{	_INDEX_LOCKSCREEN,				cgc_lockScreen,					sizeof(cgc_lockScreen) - 1,					_VAR_TYPE_LOGICAL,		     (u32)&iObj_set_logical, 		(u32)&iObj_get_logical,			_LOGICAL_FALSE },			// .t.=ignores refresh, .f.=honors refresh (default) (whether or not the form's objects are repainted when their value changes)
		{	_INDEX_MDIFORM,					cgc_mDIForm,					sizeof(cgc_mDIForm) - 1,					_VAR_TYPE_LOGICAL,		     (u32)&iObj_set_logical, 		(u32)&iObj_get_logical,			_LOGICAL_FALSE },			// .t.=form is MDI, .f.=form is not MDI (default)
		{	_INDEX_MACDESKTOP,				cgc_macDesktop,					sizeof(cgc_macDesktop) - 1,					_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,				0  		},					// 0=automatic (default, uses showWindow), 1=on OS desktop, 2=in _screen
		{	_INDEX_MARGIN,					cgc_margin,						sizeof(cgc_margin) - 1,						_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,				0  		},					// Margin in pixels for combobox, editbox, textbox, and spinner
		{	_INDEX_MAXBUTTON,				cgc_maxButton,					sizeof(cgc_maxButton) - 1,					_VAR_TYPE_LOGICAL,		     (u32)&iObj_set_logical, 		(u32)&iObj_get_logical,			_LOGICAL_TRUE },			// .t.=yes (default), .f.=no, does the form have a max button?
		{	_INDEX_MAXHEIGHT,				cgc_maxHeight,					sizeof(cgc_maxHeight) - 1,					_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,		-		1 		},					// Maximum height for the form
		{	_INDEX_MAXLEFT,					cgc_maxLeft,					sizeof(cgc_maxLeft) - 1,					_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,		-		1 		},					// Maximum left coordinate for the form
		{	_INDEX_MAXLENGTH,				cgc_maxLength,					sizeof(cgc_maxLength) - 1,					_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,				0  		},					// The maximum number of characters to input for a control
		{	_INDEX_MAXTOP,					cgc_maxTop,						sizeof(cgc_maxTop) - 1,						_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,		-		1 		},					// Maximum top coordinate for the form
		{	_INDEX_MAXWIDTH,				cgc_maxWidth,					sizeof(cgc_maxWidth) - 1,					_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,		-		1  	},					// The maximum width for a form
		{	_INDEX_MEMBERCLASS,				cgc_memberClass,				sizeof(cgc_memberClass) - 1,				_VAR_TYPE_CHARACTER,	     (u32)&iObj_set_character, 		(u32)&iObj_get_character,		(u32)&cgcNullString[0] },	// When new members are added to a container, what class should be used for the creation?
		{	_INDEX_MEMBERCLASSLIBRARY,		cgc_memberClassLibrary,			sizeof(cgc_memberClassLibrary) - 1,			_VAR_TYPE_CHARACTER,	     (u32)&iObj_set_character, 		(u32)&iObj_get_character,		(u32)&cgcNullString[0] },	// Library for the memberClass
		{	_INDEX_MEMOWINDOW,				cgc_memoWindow,					sizeof(cgc_memoWindow) - 1,					_VAR_TYPE_LOGICAL,		     (u32)&iObj_set_logical, 		(u32)&iObj_get_logical,			_LOGICAL_FALSE },			// .t.=yes, .f.=no (default), should the contents of this control be edited in a memo window?
		{	_INDEX_MESSAGE,					cgc_message,					sizeof(cgc_message) - 1,					_VAR_TYPE_CHARACTER,	     (u32)&iObj_set_character, 		(u32)&iObj_get_character,		(u32)&cgcNullString[0] },	// The exception error message
		{	_INDEX_MINBUTTON,				cgc_minButton,					sizeof(cgc_minButton) - 1,					_VAR_TYPE_LOGICAL,		     (u32)&iObj_set_logical, 		(u32)&iObj_get_logical,			_LOGICAL_TRUE },			// .t.=yes (default), .f.=no, does the form have a min button?
		{	_INDEX_MINHEIGHT,				cgc_minHeight,					sizeof(cgc_minHeight) - 1,					_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,				0 		},					// Minimum height for the form
		{	_INDEX_MINWIDTH,				cgc_minWidth,					sizeof(cgc_minWidth) - 1,					_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,				0  		},					// Minimum width for the form
		{	_INDEX_MOUSEPOINTER,			cgc_mousePointer,				sizeof(cgc_mousePointer) - 1,				_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,				_MOUSE_POINTER_DEFAULT },	// 0=default, 1=arrow, 2=crosshair, 3=i-beam, 4=icon, 5=sizer, 6=ne2sw sizer, 7=ns sizer, 8=nw2se sizer, 9=ew sizer, 10=up arrow, 11=hourglass, 12=do not drop, 13=invisible, 14=arrow, 15=hand, 16=down arrow, 99=uses mouseIcon
		{	_INDEX_MOVABLE,					cgc_movable,					sizeof(cgc_movable) - 1,					_VAR_TYPE_LOGICAL,		     (u32)&iObj_set_logical, 		(u32)&iObj_get_logical,			_LOGICAL_TRUE },			// .t.=yes (default), .f.=no, is the form movable?
		{	_INDEX_MOVERBARS,				cgc_moverBars,					sizeof(cgc_moverBars) - 1,					_VAR_TYPE_LOGICAL,		     (u32)&iObj_set_logical, 		(u32)&iObj_get_logical,			_LOGICAL_FALSE },			// .t.=show, .f.=hide (default), are mover bars shown on listboxes?
		{	_INDEX_MULTISELECT,				cgc_multiSelect,				sizeof(cgc_multiSelect) - 1,				_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,				0  		},					// 0=no multi-select (default), 1=multi-select
		{	_INDEX_NAME,					cgc_name,						sizeof(cgc_name) - 1,						_VAR_TYPE_CHARACTER,	     (u32)&iObj_set_character, 		(u32)&iObj_get_character,		(u32)&cgcNullString[0] },	// Object name
		{	_INDEX_NEWINDEX,				cgc_newIndex,					sizeof(cgc_newIndex) - 1,					_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,				0  		},					// When an item is added to a sorted listbox or combobox, newIndex indicates its position
		{	_INDEX_NEWITEMID,				cgc_newItemID,					sizeof(cgc_newItemID) - 1,					_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,				0  		},					// When an item is added to a listbox or combobox, the uid of the added item
		{	_INDEX_NULLDISPLAY,				cgc_nullDisplay,				sizeof(cgc_nullDisplay) - 1,				_VAR_TYPE_CHARACTER,	     (u32)&iObj_set_character, 		(u32)&iObj_get_character,		(u32)&cgcNullText[0] },		// The text to display for .NULL. items
		{	_INDEX_NUMBEROFELEMENTS,		cgc_numberOfElements,			sizeof(cgc_numberOfElements) - 1,			_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,				0  		},					// How many items in an array are used to populate items in a listbox or combobox
		{	_INDEX_OLECLASS,				cgc_oLEClass,					sizeof(cgc_oLEClass) - 1,					_VAR_TYPE_CHARACTER,	     (u32)&iObj_set_character, 		(u32)&iObj_get_character,		(u32)&cgcNullString[0] },	// Name of the class ID for an OLE object
		{	_INDEX_OLEDRAGMODE,				cgc_oLEDragMode,				sizeof(cgc_oLEDragMode) - 1,				_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,				_DRAG_MODE_MANUAL },		// 0=manual (default), 1=automatic
		{	_INDEX_OLEDROPEFFECTS,			cgc_oLEDropEffects,				sizeof(cgc_oLEDropEffects) - 1,				_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,				_DROP_EFFECT_NONE },		// 0=none (default), 1=copy, 2=move, 4=link, values can be combined
		{	_INDEX_OLEDROPHASDATA,			cgc_oLEDropHasData,				sizeof(cgc_oLEDropHasData) - 1,				_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,				_DROP_HAS_DATA_AUTOMATIC },	// 0=automatic (default), 1=no, 2=yes
		{	_INDEX_OLEDROPMODE,				cgc_oLEDropMode,				sizeof(cgc_oLEDropMode) - 1,				_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,				_DROP_DISABLED },			// 0=disabled (default), 1=enabled, 2=container
		{	_INDEX_OLEDROPTEXTINSERTION,	cgc_oLEDropTextInsertion,		sizeof(cgc_oLEDropTextInsertion) - 1,		_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,				0  		},					// 0=allow (default), 1=disallow, indicates if drops can be in the middle of a word, rather than at the end only
		{	_INDEX_OLELCID,					cgc_oLELCID,					sizeof(cgc_oLELCID) - 1,					_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,				0  		},					// The OLE control object's locale id
		{	_INDEX_OLETYPEALLOWED,			cgc_oLETypeAllowed,				sizeof(cgc_oLETypeAllowed) - 1,				_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,				_OLE_IS_LINKED },			// -2=Active X, -1=bound, 0=linked, 1=embedded
		{	_INDEX_OBJECT,					cgc_object,						sizeof(cgc_object) - 1,						_VAR_TYPE_OBJECT,		     (u32)&iObj_set_object, 		(u32)&iObj_get_object,			NULL },						// A pseudo-object to access data within the OLE object
		{	_INDEX_OBJECTS,					cgc_objects,					sizeof(cgc_objects) - 1,					_VAR_TYPE_OBJECT,		     (u32)&iObj_set_object, 		(u32)&iObj_get_object,			NULL },						// A pseudo-object to access child objects
		{	_INDEX_OPENWINDOW,				cgc_openWindow,					sizeof(cgc_openWindow) - 1,					_VAR_TYPE_LOGICAL,		     (u32)&iObj_set_logical, 		(u32)&iObj_get_logical,			_LOGICAL_FALSE },			// Should a memo-style window be opened when the control receives focus
		{	_INDEX_OPTIMIZE,				cgc_optimize,					sizeof(cgc_optimize) - 1,					_VAR_TYPE_LOGICAL,		     (u32)&iObj_set_logical, 		(u32)&iObj_get_logical,			_LOGICAL_FALSE },			// .t.=uses optimization, .f.=does not use optimization (default)
		{	_INDEX_PAGECOUNT,				cgc_pageCount,					sizeof(cgc_pageCount) - 1,					_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,				0  		},					// Number of pages in a pageframe
		{	_INDEX_PAGEHEIGHT,				cgc_pageHeight,					sizeof(cgc_pageHeight) - 1,					_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,				0  		},					// Height of a page
		{	_INDEX_PAGEORDER,				cgc_pageOrder,					sizeof(cgc_pageOrder) - 1,					_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,				0  		},					// Page order in the display
		{	_INDEX_PAGEWIDTH,				cgc_pageWidth,					sizeof(cgc_pageWidth) - 1,					_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,				0  		},					// Width of a page
		{	_INDEX_PAGES,					cgc_pages,						sizeof(cgc_pages) - 1,						_VAR_TYPE_OBJECT,		     (u32)&iObj_set_object, 		(u32)&iObj_get_object,			NULL },						// A pseudo-object to access pages
		{	_INDEX_PANEL,					cgc_panel,						sizeof(cgc_panel) - 1,						_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,				_GRID_PANEL_RIGHT },				// 0=left, 1=right (default)
		{	_INDEX_PANELLINK,				cgc_panelLink,					sizeof(cgc_panelLink) - 1,					_VAR_TYPE_LOGICAL,		     (u32)&iObj_set_logical, 		(u32)&iObj_get_logical,			_LOGICAL_TRUE },			// .t.=linked (default), .f.=not linked
		{	_INDEX_PARENT,					cgc_parent,						sizeof(cgc_parent) - 1,						_VAR_TYPE_OBJECT,		     (u32)&iObj_set_object, 		(u32)&iObj_get_object,			NULL },						// A pseudo-object which accesses the parent object (if any)
		{	_INDEX_PARENTCLASS,				cgc_parentClass,				sizeof(cgc_parentClass) - 1,				_VAR_TYPE_CHARACTER,	     (u32)&iObj_set_character, 		(u32)&iObj_get_character,		(u32)&cgcNullString[0] },	// A pseudo-property which accesses the parent object's class (if any)
		{	_INDEX_PARTITION,				cgc_partition,					sizeof(cgc_partition) - 1,					_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,				_GRID_NO_PARTITION },		// 0=not split (default), others=split
		{	_INDEX_PASSWORDCHAR,			cgc_passwordChar,				sizeof(cgc_passwordChar) - 1,				_VAR_TYPE_CHARACTER,	     (u32)&iObj_set_character, 		(u32)&iObj_get_character,		(u32)&cgcPasswordCharText[0] },	// A character placeholder for input characters on password fields
		{	_INDEX_PICTURE,					cgc_picture,					sizeof(cgc_picture) - 1,					_VAR_TYPE_CHARACTER,	     (u32)&iObj_set_character, 		(u32)&iObj_get_character,		(u32)&cgcNullString[0] },	// A filename to use for the picture
		{	_INDEX_PICTUREMARGIN,			cgc_pictureMargin,				sizeof(cgc_pictureMargin) - 1,				_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,				0  		},					// Pixels to place around the picture
		{	_INDEX_PICTUREPOSITION,			cgc_picturePosition,			sizeof(cgc_picturePosition) - 1,			_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,				_PICTURE_CENTERED_RELATIVE },	// See _PICTURE_* constants
		{	_INDEX_PICTURESELECTIONDISPLAY, cgc_pictureSelectionDisplay,	sizeof(cgc_pictureSelectionDisplay) - 1,	_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,				_PICTURE_NO_DISPLAY },		// 0=no display (default), 1=clip, 2=scale, 3=stretch
		{	_INDEX_PICTURESPACING,			cgc_pictureSpacing,				sizeof(cgc_pictureSpacing) - 1,				_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,				0  		},					// Pixels between image and text
		{	_INDEX_PICTUREVAL,				cgc_pictureVal,					sizeof(cgc_pictureVal) - 1,					_VAR_TYPE_CHARACTER,	     (u32)&iObj_set_character, 		(u32)&iObj_get_character,		(u32)&cgcNullString[0] },	// Raw image data for the picture
		{	_INDEX_POLYPOINTS,				cgc_polyPoints,					sizeof(cgc_polyPoints) - 1,					_VAR_TYPE_CHARACTER,	     (u32)&iObj_set_character, 		(u32)&iObj_get_character,		(u32)&cgcNullString[0] },	// Name of the array to use for the bezier
		{	_INDEX_PROCEDURE,				cgc_procedure,					sizeof(cgc_procedure) - 1,					_VAR_TYPE_CHARACTER,	     (u32)&iObj_set_character, 		(u32)&iObj_get_character,		(u32)&cgcNullString[0] },	// Name of the error procedure
		{	_INDEX_READBACKCOLOR,			cgc_readBackColor,				sizeof(cgc_readBackColor) - 1,				_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,				_selectedBackColor },		// Back color of the control with READ focus
		{	_INDEX_READCYCLE,				cgc_readCycle,					sizeof(cgc_readCycle) - 1,					_VAR_TYPE_LOGICAL,		     (u32)&iObj_set_logical, 		(u32)&iObj_get_logical,			_LOGICAL_TRUE },			// .t.=cycle (default), .f.=terminate read, should the READ continue on to the top when the end is reached?
		{	_INDEX_READFORECOLOR,			cgc_readForeColor,				sizeof(cgc_readForeColor) - 1,				_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,				_selectedForeColor },		// Fore color of the control with READ focus
		{	_INDEX_READLOCK,				cgc_readLock,					sizeof(cgc_readLock) - 1,					_VAR_TYPE_LOGICAL,		     (u32)&iObj_set_logical, 		(u32)&iObj_get_logical,			_LOGICAL_FALSE },			// .t.=pessimistic, .f.=optimistic (default), should the records associated with a READ be auto-locked during READ
		{	_INDEX_READMOUSE,				cgc_readMouse,					sizeof(cgc_readMouse) - 1,					_VAR_TYPE_LOGICAL,		     (u32)&iObj_set_logical, 		(u32)&iObj_get_logical,			_LOGICAL_FALSE },			// .t.=mouse prohibited, .t.=mouse allowed (default), should the mouse be prohibited from selecting a field during READ?
		{	_INDEX_READONLY,				cgc_readOnly,					sizeof(cgc_readOnly) - 1,					_VAR_TYPE_LOGICAL,		     (u32)&iObj_set_logical, 		(u32)&iObj_get_logical,			_LOGICAL_FALSE },			// .t.=read only, .f.=read-write (default), is the control read-only?
		{	_INDEX_READSAVE,				cgc_readSave,					sizeof(cgc_readSave) - 1,					_VAR_TYPE_LOGICAL,		     (u32)&iObj_set_logical, 		(u32)&iObj_get_logical,			_LOGICAL_FALSE },			// .t.=maintain, .f.=recycle (default), should the objects associated with the READ be kept active (maintain) or discarded (recycle)?
		{	_INDEX_READTIMEOUT,				cgc_readTimeOut,				sizeof(cgc_readTimeOut) - 1,				_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,				0  		},					// Default = 0. Seconds before READ automatically times out.
		{	_INDEX_RECORDMARK,				cgc_recordMark,					sizeof(cgc_recordMark) - 1,					_VAR_TYPE_LOGICAL,		     (u32)&iObj_set_logical, 		(u32)&iObj_get_logical,			_LOGICAL_TRUE },			// .t.=show (default), .f.=hide, should the record selection mark be shown on a grid?
		{	_INDEX_RECORDSOURCE,			cgc_recordSource,				sizeof(cgc_recordSource) - 1,				_VAR_TYPE_CHARACTER,	     (u32)&iObj_set_character, 		(u32)&iObj_get_character,		(u32)&cgcNullString[0] },	// Record source relating to recordSourceType
		{	_INDEX_RECORDSOURCETYPE,		cgc_recordSourceType,			sizeof(cgc_recordSourceType) - 1,			_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,				_GRID_RECORD_SOURCE_ALIAS },// 0=table, 1=alias (default), 3=prompt, 4=query, 5=sql statement
		{	_INDEX_RELATIONALEXPR,			cgc_relationalExpr,				sizeof(cgc_relationalExpr) - 1,				_VAR_TYPE_CHARACTER,	     (u32)&iObj_set_character, 		(u32)&iObj_get_character,		(u32)&cgcNullString[0] },	// The expression for the parent/child relationship
		{	_INDEX_RELATIVECOLUMN,			cgc_relativeColumn,				sizeof(cgc_relativeColumn) - 1,				_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,				0  		},					// Active column in a grid
		{	_INDEX_RELATIVEROW,				cgc_relativeRow,				sizeof(cgc_relativeRow) - 1,				_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,				0  		},					// Active row in a grid
		{	_INDEX_RELEASETYPE,				cgc_releaseType,				sizeof(cgc_releaseType) - 1,				_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,				_RELEASE_TYPE_VARIABLE },	// How an object is released
		{	_INDEX_RESIZABLE,				cgc_resizable,					sizeof(cgc_resizable) - 1,					_VAR_TYPE_LOGICAL,		     (u32)&iObj_set_logical, 		(u32)&iObj_get_logical,			_LOGICAL_FALSE },			// .t.=resizable, .f.=static (default), can a grid column be resized through UI action at runtime?
		{	_INDEX_RIGHTTOLEFT,				cgc_rightToLeft,				sizeof(cgc_rightToLeft) - 1,				_VAR_TYPE_LOGICAL,		     (u32)&iObj_set_logical, 		(u32)&iObj_get_logical,			_LOGICAL_FALSE },			// .t.=right to left, .f.=left to right (default), is text displayed in right-to-left reading order?
		{	_INDEX_ROTATEFLIP,				cgc_rotateFlip,					sizeof(cgc_rotateFlip) - 1,					_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,				_ROTATE_NONE },				// 0=none, 1=90, 2=180, 3=270, 4=flip, 5=90 flip, 6=180 flip, 7=270 flip
		{	_INDEX_ROTATION,				cgc_rotation,					sizeof(cgc_rotation) - 1,					_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,				0  		},					// Rotation in degrees for a control
		{	_INDEX_ROWCOLCHANGE,			cgc_rowColChange,				sizeof(cgc_rowColChange) - 1,				_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,				_GRID_ROW_COL_CHANGE_NONE },// 0=none, 1=row, 2=col, can be combined for 3=both
		{	_INDEX_ROWHEIGHT,				cgc_rowHeight,					sizeof(cgc_rowHeight) - 1,					_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,				0  		},					// Height of a row in a grid
		{	_INDEX_ROWSOURCE,				cgc_rowSource,					sizeof(cgc_rowSource) - 1,					_VAR_TYPE_CHARACTER,	     (u32)&iObj_set_character, 		(u32)&iObj_get_character,		(u32)&cgcNullString[0] },	// Related to rowSourceType
		{	_INDEX_ROWSOURCETYPE,			cgc_rowSourceType,				sizeof(cgc_rowSourceType) - 1,				_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,				_ROW_SOURCE_TYPE_NONE },	// 0=none (default), see _ROW_SOURCE_TYPE_* constants
		{	_INDEX_SCALEMODE,				cgc_scaleMode,					sizeof(cgc_scaleMode) - 1,					_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,				3  		},					// 0=foxels, 1=pixels (default)
		{	_INDEX_SCROLLBARS,				cgc_scrollBars,					sizeof(cgc_scrollBars) - 1,					_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,				_SCROLL_BARS_BOTH },		// 0=none, 1=horizontal, 2=vertical, can be combined for 3=both (default)
		{	_INDEX_SECONDS,					cgc_seconds,					sizeof(cgc_seconds) - 1,					_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,				_SECONDS_SET },				// 0=off, 1=on, 2=use SET SECONDS (default)
		{	_INDEX_SELLENGTH,				cgc_selLength,					sizeof(cgc_selLength) - 1,					_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,				0  		},					// Number of selected characters
		{	_INDEX_SELSTART,				cgc_selStart,					sizeof(cgc_selStart) - 1,					_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,				0  		},					// Offset where the selection starts
		{	_INDEX_SELTEXT,					cgc_selText,					sizeof(cgc_selText) - 1,					_VAR_TYPE_CHARACTER,	     (u32)&iObj_set_character, 		(u32)&iObj_get_character,		(u32)&cgcNullString[0] },	// A pseudo-interface to access the selected characters
		{	_INDEX_SELECTONENTRY,			cgc_selectOnEntry,				sizeof(cgc_selectOnEntry) - 1,				_VAR_TYPE_LOGICAL,		     (u32)&iObj_set_logical, 		(u32)&iObj_get_logical,			_LOGICAL_FALSE },			// .t.=yes, .f.=no (default), should the contents be selected when the control receives focus?
		{	_INDEX_SELECTED,				cgc_selected,					sizeof(cgc_selected) - 1,					_VAR_TYPE_LOGICAL,		     (u32)&iObj_set_logical, 		(u32)&iObj_get_logical,			_LOGICAL_FALSE },			// .t.=yes, .f.=no (default), if the item is selected in a listbox or combobox
		{	_INDEX_SELECTEDBACKCOLOR,		cgc_selectedBackColor,			sizeof(cgc_selectedBackColor) - 1,			_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,				_selectedBackColor },		// Selected back color
		{	_INDEX_SELECTEDFORECOLOR,		cgc_selectedForeColor,			sizeof(cgc_selectedForeColor) - 1,			_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,				_selectedForeColor },		// Selected fore color
		{	_INDEX_SELECTEDID,				cgc_selectedID,					sizeof(cgc_selectedID) - 1,					_VAR_TYPE_OBJECT,		     (u32)&iObj_set_object, 		(u32)&iObj_get_object,			NULL },						// A pseudo-object for accessing the items within, and getting/setting their selected status
		{	_INDEX_SELECTEDITEMBACKCOLOR,	cgc_selectedItemBackColor,		sizeof(cgc_selectedItemBackColor) - 1,		_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,				_selectedBackColor },		// Back color of selected items
		{	_INDEX_SELECTEDITEMFORECOLOR,	cgc_selectedItemForeColor,		sizeof(cgc_selectedItemForeColor) - 1,		_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,				_selectedForeColor },		// Fore color of selected items
		{	_INDEX_SHOWINTASKBAR,			cgc_showInTaskbar,				sizeof(cgc_showInTaskbar) - 1,				_VAR_TYPE_LOGICAL,		     (u32)&iObj_set_logical, 		(u32)&iObj_get_logical,			_LOGICAL_TRUE },			// .t.=show (default), .f.=don't show, should the window appear in the task bar?
		{	_INDEX_SHOWTIPS,				cgc_showTips,					sizeof(cgc_showTips) - 1,					_VAR_TYPE_LOGICAL,		     (u32)&iObj_set_logical, 		(u32)&iObj_get_logical,			_LOGICAL_FALSE },			// .t.=show, .f.=don't show (default), should tooltips be shown?
		{	_INDEX_SHOWWINDOW,				cgc_showWindow,					sizeof(cgc_showWindow) - 1,					_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,				_SHOW_WINDOW_IN_SCREEN },	// 0=in _screen, 1=inside parent form, 2=on the OS desktop
		{	_INDEX_SIZABLE,					cgc_sizable,					sizeof(cgc_sizable) - 1,					_VAR_TYPE_LOGICAL,		     (u32)&iObj_set_logical, 		(u32)&iObj_get_logical,			_LOGICAL_TRUE },			// .t.=sizing allowed (default), .f.=not allowed, can the control be sized?
		{	_INDEX_SIZEBOX,					cgc_sizeBox,					sizeof(cgc_sizeBox) - 1,					_VAR_TYPE_LOGICAL,		     (u32)&iObj_set_logical, 		(u32)&iObj_get_logical,			_LOGICAL_FALSE },			// .t.=has a sizebox, .f.=does not have a sizebox (default), not used
		{	_INDEX_SORTED,					cgc_sorted,						sizeof(cgc_sorted) - 1,						_VAR_TYPE_LOGICAL,		     (u32)&iObj_set_logical, 		(u32)&iObj_get_logical,			_LOGICAL_FALSE },			// .t.=sorted, .f.=not sorted (default), are items in a listbox or combobox sorted?
		{	_INDEX_SPARSE,					cgc_sparse,						sizeof(cgc_sparse) - 1,						_VAR_TYPE_LOGICAL,		     (u32)&iObj_set_logical, 		(u32)&iObj_get_logical,			_LOGICAL_TRUE },			// .t.=all use currentControl (default), .f.=only active cell uses currentControl, how is the column displayed in grids?
		{	_INDEX_SPECIALEFFECT,			cgc_specialEffect,				sizeof(cgc_specialEffect) - 1,				_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,				0  		},					// Varies by control
		{	_INDEX_SPINNERHIGHVALUE,		cgc_spinnerHighValue,			sizeof(cgc_spinnerHighValue) - 1,			_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,				0  		},					// Maximum value for spinner
		{	_INDEX_SPINNERLOWVALUE,			cgc_spinnerLowValue,			sizeof(cgc_spinnerLowValue) - 1,			_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,				0  		},					// Minimum value for spinner
		{	_INDEX_SPLITBAR,				cgc_splitBar,					sizeof(cgc_splitBar) - 1,					_VAR_TYPE_LOGICAL,		     (u32)&iObj_set_logical, 		(u32)&iObj_get_logical,			_LOGICAL_TRUE },			// .t.=show split bar (default), .f.=do not show, in grids when slip should the dividing bar be shown?
		{	_INDEX_STACKLEVEL,				cgc_stackLevel,					sizeof(cgc_stackLevel) - 1,					_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,				0  		},					// On exception, how many levels deep it is
		{	_INDEX_STATUSBARTEXT,			cgc_statusBarText,				sizeof(cgc_statusBarText) - 1,				_VAR_TYPE_CHARACTER,	     (u32)&iObj_set_character, 		(u32)&iObj_get_character,		(u32)&cgcNullString[0] },	// The text to display in the status bar when the control gains focus
		{	_INDEX_STRETCH,					cgc_stretch,					sizeof(cgc_stretch) - 1,					_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,				_STRETCH_CLIP },			// 0=clip, 1=scale, 2=stretch
		{	_INDEX_STRICTDATEENTRY,			cgc_strictDateEntry,			sizeof(cgc_strictDateEntry) - 1,			_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,				_STRICT_DATE_LOOSE },		// 0=loose (default), 1=strict, date input allowance
		{	_INDEX_STYLE,					cgc_style,						sizeof(cgc_style) - 1,						_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,				0  		},					// Varies by control
		{	_INDEX_TABINDEX,				cgc_tabIndex,					sizeof(cgc_tabIndex) - 1,					_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,				0  		},					// Set by control
		{	_INDEX_TABORIENTATION,			cgc_tabOrientation,				sizeof(cgc_tabOrientation) - 1,				_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,				_TAB_ORIENTATION_TOP },		// 0=top (default), 1=bottom, 2=left, 3=right, where the tabs appear on a pageframe
		{	_INDEX_TABSTOP,					cgc_tabStop,					sizeof(cgc_tabStop) - 1,					_VAR_TYPE_LOGICAL,		     (u32)&iObj_set_logical, 		(u32)&iObj_get_logical,			_LOGICAL_TRUE },			// Does this control receive a stop when tabbing?
		{	_INDEX_TABSTYLE,				cgc_tabStyle,					sizeof(cgc_tabStyle) - 1,					_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,				_TAB_STYLE_JUSTIFIED },		// How does the text appear in a pageframe tab?
		{	_INDEX_TABS,					cgc_tabs,						sizeof(cgc_tabs) - 1,						_VAR_TYPE_LOGICAL,		     (u32)&iObj_set_logical, 		(u32)&iObj_get_logical,			_LOGICAL_TRUE },			// .t.=show (default), .f.=hide, are tabs shown on a pageframe?
		{	_INDEX_TAG,						cgc_tag,						sizeof(cgc_tag) - 1,						_VAR_TYPE_CHARACTER,	     (u32)&iObj_set_character, 		(u32)&iObj_get_character,		(u32)&cgcNullString[0] },	// Custom text per user needs
		{	_INDEX_TERMINATEREAD,			cgc_terminateRead,				sizeof(cgc_terminateRead) - 1,				_VAR_TYPE_LOGICAL,		     (u32)&iObj_set_logical, 		(u32)&iObj_get_logical,			_LOGICAL_FALSE },			// When this control is activated, should the form's READ terminate?
		{	_INDEX_TEXT,					cgc_text,						sizeof(cgc_text) - 1,						_VAR_TYPE_CHARACTER,	     (u32)&iObj_set_character, 		(u32)&iObj_get_character,		(u32)&cgcNullString[0] },	// The raw text form of the control's contents without pictures and auto-expansion (as with date fields)
		{	_INDEX_THEMES,					cgc_themes,						sizeof(cgc_themes) - 1,						_VAR_TYPE_LOGICAL,		     (u32)&iObj_set_logical, 		(u32)&iObj_get_logical,			_LOGICAL_TRUE },			// .t.=use themes (default), .f.=standard, are themes shown?
		{	_INDEX_TITLEBAR,				cgc_titleBar,					sizeof(cgc_titleBar) - 1,					_VAR_TYPE_LOGICAL,		     (u32)&iObj_set_logical, 		(u32)&iObj_get_logical,			_LOGICAL_TRUE },			// .t.=has title bar (default), .f.=no title bar
		{	_INDEX_TOOLTIPTEXT,				cgc_toolTipText,				sizeof(cgc_toolTipText) - 1,				_VAR_TYPE_CHARACTER,	     (u32)&iObj_set_character, 		(u32)&iObj_get_character,		(u32)&cgcNullString[0] },	// Tooltip text to display when hovering over the control
		{	_INDEX_TOP,						cgc_top,						sizeof(cgc_top) - 1,						_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,				0  		},					// The top coordinate for the object
		{	_INDEX_TOPINDEX,				cgc_topIndex,					sizeof(cgc_topIndex) - 1,					_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,				0  		},					// The index of the item in the topmost visible position of a listbox or combobox
		{	_INDEX_TOPITEMID,				cgc_topItemID,					sizeof(cgc_topItemID) - 1,					_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,				0  		},					// The uid of the item in the topmost visible position of a listbox or combobox
		{	_INDEX_USERVALUE,				cgc_userValue,					sizeof(cgc_userValue) - 1,					_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,				0  		},					// The value in a THROW statement for a manual exception
		{	_INDEX_VSCROLLSMALLCHANGE,		cgc_vScrollSmallChange,			sizeof(cgc_vScrollSmallChange) - 1,			_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,				10 		},					// When scalemode = 3, default is 10 pixels
		{	_INDEX_VALUE,					cgc_value,						sizeof(cgc_value) - 1,						_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,				0  		},					// Varies by control, but the value of the control's contents
		{	_INDEX_VIEW,					cgc_view,						sizeof(cgc_view) - 1,						_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,				_GRID_VIEW_CHANGE_BOTH },	// 0=browse, 1=change / change right, 2=change left, 3=change both (default)
		{	_INDEX_VIEWPORTHEIGHT,			cgc_viewPortHeight,				sizeof(cgc_viewPortHeight) - 1,				_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,				0  		},					// A pseudo-property to read the viewport height
		{	_INDEX_VIEWPORTLEFT,			cgc_viewPortLeft,				sizeof(cgc_viewPortLeft) - 1,				_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,				0  		},					// A pseudo-property to read the viewport left
		{	_INDEX_VIEWPORTTOP,				cgc_viewPortTop,				sizeof(cgc_viewPortTop) - 1,				_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,				0  		},					// A pseudo-property to read the viewport top
		{	_INDEX_VIEWPORTWIDTH,			cgc_viewPortWidth,				sizeof(cgc_viewPortWidth) - 1,				_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,				0  		},					// A pseudo-property to read the viewport width
		{	_INDEX_VISIBLE,					cgc_visible,					sizeof(cgc_visible) - 1,					_VAR_TYPE_LOGICAL,		     (u32)&iObj_set_logical, 		(u32)&iObj_get_logical,			_LOGICAL_TRUE },			// .t.=visible, .f.=invisible, is the control visible?
		{	_INDEX_VISUALEFFECT,			cgc_visualEffect,				sizeof(cgc_visualEffect) - 1,				_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,				_VISUAL_EFFECT_NONE },		// 0=none (default), 1=raised, 2=sunken, how a command button appears
		{	_INDEX_WHATSTHISBUTTON,			cgc_whatsThisButton,			sizeof(cgc_whatsThisButton) - 1,			_VAR_TYPE_LOGICAL,		     (u32)&iObj_set_logical, 		(u32)&iObj_get_logical,			_LOGICAL_FALSE },			// .t.=has what's this, .f.=does not have what's this (default)
		{	_INDEX_WHATSTHISHELP,			cgc_whatsThisHelp,				sizeof(cgc_whatsThisHelp) - 1,				_VAR_TYPE_LOGICAL,		     (u32)&iObj_set_logical, 		(u32)&iObj_get_logical,			_LOGICAL_TRUE },			// .t.=based on SET HELP, .f.=triggered by f1 (default), how is help triggered?
		{	_INDEX_WHATSTHISHELPID,			cgc_whatsThisHelpID,			sizeof(cgc_whatsThisHelpID) - 1,			_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,				0  		},					// The help id to lookup in the help file
		{	_INDEX_WIDTH,					cgc_width,						sizeof(cgc_width) - 1,						_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,				0  		},					// Width of the control
		{	_INDEX_WINDOWLIST,				cgc_windowList,					sizeof(cgc_windowList) - 1,					_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,				0  		},					// Not used
		{	_INDEX_WINDOWSTATE,				cgc_windowState,				sizeof(cgc_windowState) - 1,				_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,				_WINDOW_STATE_NORMAL },		// 0=normal (default), 1=minimized, 2=maximized, how a form is displayed?
		{	_INDEX_WINDOWTYPE,				cgc_windowType,					sizeof(cgc_windowType) - 1,					_VAR_TYPE_S32,			     (u32)&iObj_set_s32, 			(u32)&iObj_get_s32,				_WINDOW_TYPE_MODELESS },	// 0=modeless (default), 1=modal, 2=read, 3=read modeless, how a window is presented
		{	_INDEX_WORDWRAP,				cgc_wordWrap,					sizeof(cgc_wordWrap) - 1,					_VAR_TYPE_LOGICAL,		     (u32)&iObj_set_logical, 		(u32)&iObj_get_logical,			_LOGICAL_FALSE },			// .t.=wraps, .f.=single line (default), how text is presented
		{	_INDEX_ZOOMBOX,					cgc_zoomBox,					sizeof(cgc_zoomBox) - 1,					_VAR_TYPE_LOGICAL,		     (u32)&iObj_set_logical, 		(u32)&iObj_get_logical,			_LOGICAL_FALSE },			// .t.=shows zoom box, .f.=does not show (default), for backward compatibility, not used
	};


	struct SPropertyMap
	{
		u32			index;

		union {
			u32			_setter;
			bool		(*setterOverrideVar)	(SObject* obj, u32 tnIndex, SVariable* var);
			bool		(*setterOverrideBmp)	(SObject* obj, u32 tnIndex, SBitmap* bmp);
		};

		union {
			u32			_getter;
			SVariable*	(*getterOverrideVar)	(SObject* obj, u32 tnIndex);
			SBitmap*	(*getterOverrideBmp)	(SObject* obj, u32 tnIndex);
		};
	};

	SPropertyMap gsProps_empty[] =
	{
		{	_INDEX_NAME,					0,				0   },
		{	0,								0,				0	}
	};
	const u32 gnProps_emptySize = sizeof(gsProps_empty) / sizeof(SPropertyMap) - 1;

	SPropertyMap gsProps_subform[] =
	{
		{	_INDEX_ACTIVECONTROL,			0,				0	},
		{	_INDEX_ALLOWOUTPUT,				0,				0	},
		{	_INDEX_FILLCOLOR,				0,				0	},
		{	_INDEX_FILLSTYLE,				0,				0	},
		{	_INDEX_MAXHEIGHT,				0,				0	},
		{	_INDEX_MAXWIDTH,				0,				0	},
		{	_INDEX_MAXTOP,					0,				0	},
		{	_INDEX_MAXLEFT,					0,				0	},
		{	_INDEX_MINHEIGHT,				0,				0	},
		{	_INDEX_MINWIDTH,				0,				0	},
		{	_INDEX_BASECLASS,				0,				0	},
		{	_INDEX_CLASS,					0,				0	},
		{	_INDEX_CLASSLIBRARY,			0,				0	},
		{	_INDEX_CONTROLS,				0,				0	},
		{	_INDEX_CONTROLCOUNT,			0,				0	},
		{	_INDEX_OBJECTS,					0,				0	},
		{	_INDEX_BORDERSTYLE,				0,				0	},
		{	_INDEX_CAPTION,					0,				0	},
		{	_INDEX_FORECOLOR,				0,				0	},
		{	_INDEX_BACKCOLOR,				0,				0	},
		{	_INDEX_COMMENT,					0,				0	},
		{	_INDEX_ENABLED,					0,				0	},
		{	_INDEX_FONTBOLD,				0,				0	},
		{	_INDEX_FONTCHARSET,				0,				0	},
		{	_INDEX_FONTCONDENSE,			0,				0	},
		{	_INDEX_FONTEXTEND,				0,				0	},
		{	_INDEX_FONTITALIC,				0,				0	},
		{	_INDEX_FONTNAME,				0,				0	},
		{	_INDEX_FONTOUTLINE,				0,				0	},
		{	_INDEX_FONTSHADOW,				0,				0	},
		{	_INDEX_FONTSIZE,				0,				0	},
		{	_INDEX_FONTSTRIKETHRU,			0,				0	},
		{	_INDEX_FONTUNDERLINE,			0,				0	},
		{	_INDEX_HEIGHT,					0,				0	},
		{	_INDEX_HELPCONTEXTID,			0,				0	},
		{	_INDEX_HWND,					0,				0	},
		{	_INDEX_KEYPREVIEW,				0,				0	},
		{	_INDEX_LEFT,					0,				0	},
		{	_INDEX_MOUSEICON,				0,				0	},
		{	_INDEX_MOUSEPOINTER,			0,				0	},
		{	_INDEX_NAME,					0,				0	},
		{	_INDEX_PARENT,					0,				0	},
		{	_INDEX_PARENTCLASS,				0,				0	},
		{	_INDEX_ICON,					0,				0	},
		{	_INDEX_PICTURE,					0,				0	},
		{	_INDEX_TAG,						0,				0	},
		{	_INDEX_TOP,						0,				0	},
		{	_INDEX_VISIBLE,					0,				0	},
		{	_INDEX_WIDTH,					0,				0	},
		{	_INDEX_ZOOMBOX,					0,				0	},
		{	0,								0,				0	},
	};
	const u32 gnProps_subformSize = sizeof(gsProps_subform) / sizeof(SPropertyMap) - 1;

	SPropertyMap gsProps_radio[] =
	{
		{	_INDEX_NAME,					0,				0	},
		{	0,								0,				0	},
	};
	const u32 gnProps_radioSize = sizeof(gsProps_radio) / sizeof(SPropertyMap) - 1;

	SPropertyMap gsProps_checkbox[] =
	{
		{	_INDEX_ALIGNMENT,				0,				0	},
		{	_INDEX_ANCHOR,					0,				0	},
		{	_INDEX_APPLICATION,				0,				0	},
		{	_INDEX_AUTOSIZE,				0,				0	},
		{	_INDEX_BACKSTYLE,				0,				0	},
		{	_INDEX_BASECLASS,				0,				0	},
		{	_INDEX_CLASS,					0,				0	},
		{	_INDEX_CLASSLIBRARY,			0,				0	},
		{	_INDEX_CAPTION,					0,				0	},
		{	_INDEX_CENTERED,				0,				0	},
		{	_INDEX_COLORSCHEME,				0,				0	},
		{	_INDEX_COLORSOURCE,				0,				0	},
		{	_INDEX_FORECOLOR,				0,				0	},
		{	_INDEX_BACKCOLOR,				0,				0	},
		{	_INDEX_DISABLEDBACKCOLOR,		0,				0	},
		{	_INDEX_DISABLEDFORECOLOR,		0,				0	},
		{	_INDEX_COMMENT,					0,				0	},
		{	_INDEX_CONTROLSOURCE,			0,				0	},
		{	_INDEX_DRAGICON,				0,				0	},
		{	_INDEX_DRAGMODE,				0,				0	},
		{	_INDEX_ENABLED,					0,				0	},
		{	_INDEX_FONTBOLD,				0,				0	},
		{	_INDEX_FONTCHARSET,				0,				0	},
		{	_INDEX_FONTCONDENSE,			0,				0	},
		{	_INDEX_FONTEXTEND,				0,				0	},
		{	_INDEX_FONTITALIC,				0,				0	},
		{	_INDEX_FONTNAME,				0,				0	},
		{	_INDEX_FONTOUTLINE,				0,				0	},
		{	_INDEX_FONTSHADOW,				0,				0	},
		{	_INDEX_FONTSTRIKETHRU,			0,				0	},
		{	_INDEX_FONTUNDERLINE,			0,				0	},
		{	_INDEX_HEIGHT,					0,				0	},
		{	_INDEX_HELPCONTEXTID,			0,				0	},
		{	_INDEX_LEFT,					0,				0	},
		{	_INDEX_MOUSEICON,				0,				0	},
		{	_INDEX_MOUSEPOINTER,			0,				0	},
		{	_INDEX_NAME,					0,				0	},
		{	_INDEX_OLEDRAGMODE,				0,				0	},
		{	_INDEX_OLEDRAGPICTURE,			0,				0	},
		{	_INDEX_OLEDROPEFFECTS,			0,				0	},
		{	_INDEX_OLEDROPHASDATA,			0,				0	},
		{	_INDEX_PARENT,					0,				0	},
		{	_INDEX_PARENTCLASS,				0,				0	},
		{	_INDEX_PICTURE,					0,				0	},
		{	_INDEX_PICTUREMARGIN,			0,				0	},
		{	_INDEX_PICTUREPOSITION,			0,				0	},
		{	_INDEX_PICTURESPACING,			0,				0	},
		{	_INDEX_DISABLEDPICTURE,			0,				0	},
		{	_INDEX_DOWNPICTURE,				0,				0	},
		{	_INDEX_READONLY,				0,				0	},
		{	_INDEX_RIGHTTOLEFT,				0,				0	},
		{	_INDEX_SPECIALEFFECT,			0,				0	},
		{	_INDEX_STATUSBARTEXT,			0,				0	},
		{	_INDEX_STYLE,					0,				0	},
		{	_INDEX_TABINDEX,				0,				0	},
		{	_INDEX_TABSTOP,					0,				0	},
		{	_INDEX_TAG,						0,				0	},
		{	_INDEX_TERMINATEREAD,			0,				0	},
		{	_INDEX_THEMES,					0,				0	},
		{	_INDEX_TOOLTIPTEXT,				0,				0	},
		{	_INDEX_TOP,						0,				0	},
		{	_INDEX_VALUE,					0,				0	},
		{	_INDEX_VISIBLE,					0,				0	},
		{	_INDEX_WHATSTHISHELPID,			0,				0	},
		{	_INDEX_WIDTH,					0,				0	},
		{	_INDEX_WORDWRAP,				0,				0	},
		{	0,								0,				0	},
	};
	const u32 gnProps_checkboxSize = sizeof(gsProps_checkbox) / sizeof(SPropertyMap) - 1;

	SPropertyMap gsProps_button[] =
	{
		{	_INDEX_ALIGNMENT,				0,				0	},
		{	_INDEX_ANCHOR,					0,				0	},
		{	_INDEX_APPLICATION,				0,				0	},
		{	_INDEX_AUTOSIZE,				0,				0	},
		{	_INDEX_BASECLASS,				0,				0	},
		{	_INDEX_CLASS,					0,				0	},
		{	_INDEX_CLASSLIBRARY,			0,				0	},
		{	_INDEX_CANCEL,					0,				0	},
		{	_INDEX_DEFAULT,					0,				0	},
		{	_INDEX_CAPTION,					0,				0	},
		{	_INDEX_COLORSCHEME,				0,				0	},
		{	_INDEX_COLORSOURCE,				0,				0	},
		{	_INDEX_FORECOLOR,				0,				0	},
		{	_INDEX_BACKCOLOR,				0,				0	},
		{	_INDEX_DISABLEDBACKCOLOR,		0,				0	},
		{	_INDEX_DISABLEDFORECOLOR,		0,				0	},
		{	_INDEX_COMMENT,					0,				0	},
		{	_INDEX_DRAGICON,				0,				0	},
		{	_INDEX_DRAGMODE,				0,				0	},
		{	_INDEX_ENABLED,					0,				0	},
		{	_INDEX_FONTBOLD,				0,				0	},
		{	_INDEX_FONTCHARSET,				0,				0	},
		{	_INDEX_FONTCONDENSE,			0,				0	},
		{	_INDEX_FONTEXTEND,				0,				0	},
		{	_INDEX_FONTITALIC,				0,				0	},
		{	_INDEX_FONTNAME,				0,				0	},
		{	_INDEX_FONTOUTLINE,				0,				0	},
		{	_INDEX_FONTSHADOW,				0,				0	},
		{	_INDEX_FONTSIZE,				0,				0	},
		{	_INDEX_FONTSTRIKETHRU,			0,				0	},
		{	_INDEX_FONTUNDERLINE,			0,				0	},
		{	_INDEX_HEIGHT,					0,				0	},
		{	_INDEX_HELPCONTEXTID,			0,				0	},
		{	_INDEX_LEFT,					0,				0	},
		{	_INDEX_MOUSEICON,				0,				0	},
		{	_INDEX_MOUSEPOINTER,			0,				0	},
		{	_INDEX_NAME,					0,				0	},
		{	_INDEX_OLEDRAGMODE,				0,				0	},
		{	_INDEX_OLEDRAGPICTURE,			0,				0	},
		{	_INDEX_OLEDROPEFFECTS,			0,				0	},
		{	_INDEX_OLEDROPHASDATA,			0,				0	},
		{	_INDEX_OLEDROPMODE,				0,				0	},
		{	_INDEX_PARENT,					0,				0	},
		{	_INDEX_PARENTCLASS,				0,				0	},
		{	_INDEX_PICTURE,					0,				0	},
		{	_INDEX_PICTUREMARGIN,			0,				0	},
		{	_INDEX_PICTUREPOSITION,			0,				0	},
		{	_INDEX_PICTURESPACING,			0,				0	},
		{	_INDEX_DISABLEDPICTURE,			0,				0	},
		{	_INDEX_DOWNPICTURE,				0,				0	},
		{	_INDEX_RIGHTTOLEFT,				0,				0	},
		{	_INDEX_SPECIALEFFECT,			0,				0	},
		{	_INDEX_STATUSBARTEXT,			0,				0	},
		{	_INDEX_STYLE,					0,				0	},
		{	_INDEX_TABINDEX,				0,				0	},
		{	_INDEX_TABSTOP,					0,				0	},
		{	_INDEX_TAG,						0,				0	},
		{	_INDEX_TERMINATEREAD,			0,				0	},
		{	_INDEX_THEMES,					0,				0	},
		{	_INDEX_TOOLTIPTEXT,				0,				0	},
		{	_INDEX_TOP,						0,				0	},
		{	_INDEX_VISIBLE,					0,				0	},
		{	_INDEX_VISUALEFFECT,			0,				0	},
		{	_INDEX_WHATSTHISHELPID,			0,				0	},
		{	_INDEX_WIDTH,					0,				0	},
		{	_INDEX_WORDWRAP,				0,				0	},
		{	0,								0,				0	},
	};
	const u32 gnProps_buttonSize = sizeof(gsProps_button) / sizeof(SPropertyMap) - 1;

	SPropertyMap gsProps_cmdgroup[] =
	{
		{	_INDEX_ANCHOR,					0,				0	},
		{	_INDEX_AUTOSIZE,				0,				0	},
		{	_INDEX_BACKSTYLE,				0,				0	},
		{	_INDEX_BUTTONCOUNT,				0,				0	},
		{	_INDEX_BORDERCOLOR,				0,				0	},
		{	_INDEX_BORDERSTYLE,				0,				0	},
		{	_INDEX_COLORSOURCE,				0,				0	},
		{	_INDEX_BACKCOLOR,				0,				0	},
		{	_INDEX_COMMENT,					0,				0	},
		{	_INDEX_CONTROLSOURCE,			0,				0	},
		{	_INDEX_DRAGICON,				0,				0	},
		{	_INDEX_DRAGMODE,				0,				0	},
		{	_INDEX_ENABLED,					0,				0	},
		{	_INDEX_HEIGHT,					0,				0	},
		{	_INDEX_HELPCONTEXTID,			0,				0	},
		{	_INDEX_LEFT,					0,				0	},
		{	_INDEX_MEMBERCLASS,				0,				0	},
		{	_INDEX_MEMBERCLASSLIBRARY,		0,				0	},
		{	_INDEX_MOUSEICON,				0,				0	},
		{	_INDEX_MOUSEPOINTER,			0,				0	},
		{	_INDEX_NAME,					0,				0	},
		{	_INDEX_OLEDRAGMODE,				0,				0	},
		{	_INDEX_OLEDRAGPICTURE,			0,				0	},
		{	_INDEX_OLEDROPEFFECTS,			0,				0	},
		{	_INDEX_OLEDROPMODE,				0,				0	},
		{	_INDEX_SPECIALEFFECT,			0,				0	},
		{	_INDEX_STATUSBARTEXT,			0,				0	},
		{	_INDEX_TAG,						0,				0	},
		{	_INDEX_TERMINATEREAD,			0,				0	},
		{	_INDEX_THEMES,					0,				0	},
		{	_INDEX_TOOLTIPTEXT,				0,				0	},
		{	_INDEX_TOP,						0,				0	},
		{	_INDEX_VALUE,					0,				0	},
		{	_INDEX_VISIBLE,					0,				0	},
		{	_INDEX_WHATSTHISHELPID,			0,				0	},
		{	_INDEX_WIDTH,					0,				0	},
		{	0,								0,				0	},
	};
	const u32 gnProps_cmdgroupSize = sizeof(gsProps_cmdgroup) / sizeof(SPropertyMap) - 1;

	SPropertyMap gsProps_label[] =
	{
		{	_INDEX_ALIGNMENT,				0,				0	},
		{	_INDEX_ANCHOR,					0,				0	},
		{	_INDEX_APPLICATION,				0,				0	},
		{	_INDEX_AUTOSIZE,				0,				0	},
		{	_INDEX_BACKSTYLE,				0,				0	},
		{	_INDEX_BASECLASS,				0,				0	},
		{	_INDEX_CLASS,					0,				0	},
		{	_INDEX_CLASSLIBRARY,			0,				0	},
		{	_INDEX_BORDERSTYLE,				0,				0	},
		{	_INDEX_CAPTION,					0,				0	},
		{	_INDEX_COLORSCHEME,				0,				0	},
		{	_INDEX_COLORSOURCE,				0,				0	},
		{	_INDEX_FORECOLOR,				0,				0	},
		{	_INDEX_BACKCOLOR,				0,				0	},
		{	_INDEX_DISABLEDBACKCOLOR,		0,				0	},
		{	_INDEX_DISABLEDFORECOLOR,		0,				0	},
		{	_INDEX_COMMENT,					0,				0	},
		{	_INDEX_DRAGICON,				0,				0	},
		{	_INDEX_DRAGMODE,				0,				0	},
		{	_INDEX_ENABLED,					0,				0	},
		{	_INDEX_FONTBOLD,				0,				0	},
		{	_INDEX_FONTCHARSET,				0,				0	},
		{	_INDEX_FONTCONDENSE,			0,				0	},
		{	_INDEX_FONTEXTEND,				0,				0	},
		{	_INDEX_FONTITALIC,				0,				0	},
		{	_INDEX_FONTNAME,				0,				0	},
		{	_INDEX_FONTOUTLINE,				0,				0	},
		{	_INDEX_FONTSHADOW,				0,				0	},
		{	_INDEX_FONTSIZE,				0,				0	},
		{	_INDEX_FONTSTRIKETHRU,			0,				0	},
		{	_INDEX_FONTUNDERLINE,			0,				0	},
		{	_INDEX_HEIGHT,					0,				0	},
		{	_INDEX_HELPCONTEXTID,			0,				0	},
		{	_INDEX_LEFT,					0,				0	},
		{	_INDEX_MOUSEICON,				0,				0	},
		{	_INDEX_MOUSEPOINTER,			0,				0	},
		{	_INDEX_NAME,					0,				0	},
		{	_INDEX_OLEDRAGMODE,				0,				0	},
		{	_INDEX_OLEDRAGPICTURE,			0,				0	},
		{	_INDEX_OLEDROPEFFECTS,			0,				0	},
		{	_INDEX_OLEDROPHASDATA,			0,				0	},
		{	_INDEX_OLEDROPMODE,				0,				0	},
		{	_INDEX_PARENT,					0,				0	},
		{	_INDEX_PARENTCLASS,				0,				0	},
		{	_INDEX_RIGHTTOLEFT,				0,				0	},
		{	_INDEX_ROTATION,				0,				0	},
		{	_INDEX_STATUSBARTEXT,			0,				0	},
		{	_INDEX_STYLE,					0,				0	},
		{	_INDEX_TABINDEX,				0,				0	},
		{	_INDEX_TAG,						0,				0	},
		{	_INDEX_TOOLTIPTEXT,				0,				0	},
		{	_INDEX_TOP,						0,				0	},
		{	_INDEX_VISIBLE,					0,				0	},
		{	_INDEX_WHATSTHISHELPID,			0,				0	},
		{	_INDEX_WIDTH,					0,				0	},
		{	_INDEX_WORDWRAP,				0,				0	},
		{	0,								0,				0	},
	};
	const u32 gnProps_labelSize = sizeof(gsProps_label) / sizeof(SPropertyMap) - 1;

	SPropertyMap gsProps_option[] =
	{
		{	_INDEX_ALIGNMENT,				0,				0	},
		{	_INDEX_ANCHOR,					0,				0	},
		{	_INDEX_AUTOSIZE,				0,				0	},
		{	_INDEX_BACKSTYLE,				0,				0	},
		{	_INDEX_CAPTION,					0,				0	},
		{	_INDEX_COLORSCHEME,				0,				0	},
		{	_INDEX_COLORSOURCE,				0,				0	},
		{	_INDEX_FORECOLOR,				0,				0	},
		{	_INDEX_BACKCOLOR,				0,				0	},
		{	_INDEX_DISABLEDBACKCOLOR,		0,				0	},
		{	_INDEX_DISABLEDFORECOLOR,		0,				0	},
		{	_INDEX_COMMENT,					0,				0	},
		{	_INDEX_CONTROLSOURCE,			0,				0	},
		{	_INDEX_DRAGICON,				0,				0	},
		{	_INDEX_DRAGMODE,				0,				0	},
		{	_INDEX_ENABLED,					0,				0	},
		{	_INDEX_FONTBOLD,				0,				0	},
		{	_INDEX_FONTCHARSET,				0,				0	},
		{	_INDEX_FONTCONDENSE,			0,				0	},
		{	_INDEX_FONTEXTEND,				0,				0	},
		{	_INDEX_FONTITALIC,				0,				0	},
		{	_INDEX_FONTNAME,				0,				0	},
		{	_INDEX_FONTOUTLINE,				0,				0	},
		{	_INDEX_FONTSHADOW,				0,				0	},
		{	_INDEX_FONTSIZE,				0,				0	},
		{	_INDEX_FONTSTRIKETHRU,			0,				0	},
		{	_INDEX_FONTUNDERLINE,			0,				0	},
		{	_INDEX_HEIGHT,					0,				0	},
		{	_INDEX_HELPCONTEXTID,			0,				0	},
		{	_INDEX_LEFT,					0,				0	},
		{	_INDEX_MOUSEICON,				0,				0	},
		{	_INDEX_MOUSEPOINTER,			0,				0	},
		{	_INDEX_NAME,					0,				0	},
		{	_INDEX_OLEDRAGMODE,				0,				0	},
		{	_INDEX_OLEDRAGPICTURE,			0,				0	},
		{	_INDEX_OLEDROPEFFECTS,			0,				0	},
		{	_INDEX_OLEDROPMODE,				0,				0	},
		{	_INDEX_PICTURE,					0,				0	},
		{	_INDEX_PICTUREMARGIN,			0,				0	},
		{	_INDEX_PICTUREPOSITION,			0,				0	},
		{	_INDEX_PICTURESPACING,			0,				0	},
		{	_INDEX_DISABLEDPICTURE,			0,				0	},
		{	_INDEX_DOWNPICTURE,				0,				0	},
		{	_INDEX_RIGHTTOLEFT,				0,				0	},
		{	_INDEX_SPECIALEFFECT,			0,				0	},
		{	_INDEX_STATUSBARTEXT,			0,				0	},
		{	_INDEX_STYLE,					0,				0	},
		{	_INDEX_TABINDEX,				0,				0	},
		{	_INDEX_TABSTOP,					0,				0	},
		{	_INDEX_TAG,						0,				0	},
		{	_INDEX_TERMINATEREAD,			0,				0	},
		{	_INDEX_THEMES,					0,				0	},
		{	_INDEX_TOOLTIPTEXT,				0,				0	},
		{	_INDEX_TOP,						0,				0	},
		{	_INDEX_VALUE,					0,				0	},
		{	_INDEX_VISIBLE,					0,				0	},
		{	_INDEX_WHATSTHISHELPID,			0,				0	},
		{	_INDEX_WIDTH,					0,				0	},
		{	_INDEX_WORDWRAP,				0,				0	},
		{	0,								0,				0	},
	};
	const u32 gnProps_optionSize = sizeof(gsProps_option) / sizeof(SPropertyMap) - 1;

	SPropertyMap gsProps_optgroup[] =
	{
		{	_INDEX_ANCHOR,					0,				0	},
		{	_INDEX_AUTOSIZE,				0,				0	},
		{	_INDEX_BACKSTYLE,				0,				0	},
		{	_INDEX_BUTTONCOUNT,				0,				0	},
		{	_INDEX_BORDERCOLOR,				0,				0	},
		{	_INDEX_BORDERSTYLE,				0,				0	},
		{	_INDEX_COLORSOURCE,				0,				0	},
		{	_INDEX_BACKCOLOR,				0,				0	},
		{	_INDEX_COMMENT,					0,				0	},
		{	_INDEX_CONTROLSOURCE,			0,				0	},
		{	_INDEX_DRAGICON,				0,				0	},
		{	_INDEX_DRAGMODE,				0,				0	},
		{	_INDEX_ENABLED,					0,				0	},
		{	_INDEX_HEIGHT,					0,				0	},
		{	_INDEX_HELPCONTEXTID,			0,				0	},
		{	_INDEX_LEFT,					0,				0	},
		{	_INDEX_MEMBERCLASS,				0,				0	},
		{	_INDEX_MEMBERCLASSLIBRARY,		0,				0	},
		{	_INDEX_MOUSEICON,				0,				0	},
		{	_INDEX_MOUSEPOINTER,			0,				0	},
		{	_INDEX_NAME,					0,				0	},
		{	_INDEX_OLEDRAGMODE,				0,				0	},
		{	_INDEX_OLEDRAGPICTURE,			0,				0	},
		{	_INDEX_OLEDROPEFFECTS,			0,				0	},
		{	_INDEX_OLEDROPMODE,				0,				0	},
		{	_INDEX_SPECIALEFFECT,			0,				0	},
		{	_INDEX_STATUSBARTEXT,			0,				0	},
		{	_INDEX_TABINDEX,				0,				0	},
		{	_INDEX_TAG,						0,				0	},
		{	_INDEX_TERMINATEREAD,			0,				0	},
		{	_INDEX_THEMES,					0,				0	},
		{	_INDEX_TOOLTIPTEXT,				0,				0	},
		{	_INDEX_TOP,						0,				0	},
		{	_INDEX_VALUE,					0,				0	},
		{	_INDEX_VISIBLE,					0,				0	},
		{	_INDEX_WHATSTHISHELPID,			0,				0	},
		{	_INDEX_WIDTH,					0,				0	},
		{	0,								0,				0	},
	};
	const u32 gnProps_optgroupSize = sizeof(gsProps_optgroup) / sizeof(SPropertyMap) - 1;

	SPropertyMap gsProps_textbox[] =
	{
		{	_INDEX_ALIGNMENT,				0,				0	},
		{	_INDEX_ANCHOR,					0,				0	},
		{	_INDEX_APPLICATION,				0,				0	},
		{	_INDEX_AUTOCOMPLETE,			0,				0	},
		{	_INDEX_AUTOCOMPTABLE,			0,				0	},
		{	_INDEX_AUTOCOMPSOURCE,			0,				0	},
		{	_INDEX_BACKSTYLE,				0,				0	},
		{	_INDEX_BASECLASS,				0,				0	},
		{	_INDEX_CLASS,					0,				0	},
		{	_INDEX_CLASSLIBRARY,			0,				0	},
		{	_INDEX_BORDERCOLOR,				0,				0	},
		{	_INDEX_BORDERSTYLE,				0,				0	},
		{	_INDEX_CENTURY,					0,				0	},
		{	_INDEX_COLORSCHEME,				0,				0	},
		{	_INDEX_COLORSOURCE,				0,				0	},
		{	_INDEX_FORECOLOR,				0,				0	},
		{	_INDEX_BACKCOLOR,				0,				0	},
		{	_INDEX_DISABLEDBACKCOLOR,		0,				0	},
		{	_INDEX_DISABLEDFORECOLOR,		0,				0	},
		{	_INDEX_COMMENT,					0,				0	},
		{	_INDEX_CONTROLSOURCE,			0,				0	},
		{	_INDEX_DATEFORMAT,				0,				0	},
		{	_INDEX_DATEMARK,				0,				0	},
		{	_INDEX_DRAGICON,				0,				0	},
		{	_INDEX_DRAGMODE,				0,				0	},
		{	_INDEX_ENABLED,					0,				0	},
		{	_INDEX_ENABLEHYPERLINKS,		0,				0	},
		{	_INDEX_FONTBOLD,				0,				0	},
		{	_INDEX_FONTCHARSET,				0,				0	},
		{	_INDEX_FONTCONDENSE,			0,				0	},
		{	_INDEX_FONTEXTEND,				0,				0	},
		{	_INDEX_FONTITALIC,				0,				0	},
		{	_INDEX_FONTNAME,				0,				0	},
		{	_INDEX_FONTOUTLINE,				0,				0	},
		{	_INDEX_FONTSHADOW,				0,				0	},
		{	_INDEX_FONTSIZE,				0,				0	},
		{	_INDEX_FONTSTRIKETHRU,			0,				0	},
		{	_INDEX_FONTUNDERLINE,			0,				0	},
		{	_INDEX_FORMAT,					0,				0	},
		{	_INDEX_HEIGHT,					0,				0	},
		{	_INDEX_HELPCONTEXTID,			0,				0	},
		{	_INDEX_HIDESELECTION,			0,				0	},
		{	_INDEX_HOURS,					0,				0	},
		{	_INDEX_IMEMODE,					0,				0	},
		{	_INDEX_INPUTMASK,				0,				0	},
		{	_INDEX_INTEGRALHEIGHT,			0,				0	},
		{	_INDEX_LEFT,					0,				0	},
		{	_INDEX_MARGIN,					0,				0	},
		{	_INDEX_MAXLENGTH,				0,				0	},
		{	_INDEX_MOUSEICON,				0,				0	},
		{	_INDEX_MOUSEPOINTER,			0,				0	},
		{	_INDEX_MEMOWINDOW,				0,				0	},
		{	_INDEX_NAME,					0,				0	},
		{	_INDEX_NULLDISPLAY,				0,				0	},
		{	_INDEX_OLEDRAGMODE,				0,				0	},
		{	_INDEX_OLEDRAGPICTURE,			0,				0	},
		{	_INDEX_OLEDROPEFFECTS,			0,				0	},
		{	_INDEX_OLEDROPHASDATA,			0,				0	},
		{	_INDEX_OLEDROPMODE,				0,				0	},
		{	_INDEX_OLEDROPTEXTINSERTION,	0,				0	},
		{	_INDEX_OPENWINDOW,				0,				0	},
		{	_INDEX_PARENT,					0,				0	},
		{	_INDEX_PARENTCLASS,				0,				0	},
		{	_INDEX_PASSWORDCHAR,			0,				0	},
		{	_INDEX_READONLY,				0,				0	},
		{	_INDEX_RIGHTTOLEFT,				0,				0	},
		{	_INDEX_SECONDS,					0,				0	},
		{	_INDEX_SELECTEDBACKCOLOR,		0,				0	},
		{	_INDEX_SELECTEDFORECOLOR,		0,				0	},
		{	_INDEX_SELECTONENTRY,			0,				0	},
		{	_INDEX_SELLENGTH,				0,				0	},
		{	_INDEX_SELSTART,				0,				0	},
		{	_INDEX_SELTEXT,					0,				0	},
		{	_INDEX_SPECIALEFFECT,			0,				0	},
		{	_INDEX_STATUSBARTEXT,			0,				0	},
		{	_INDEX_STRICTDATEENTRY,			0,				0	},
		{	_INDEX_STYLE,					0,				0	},
		{	_INDEX_TABINDEX,				0,				0	},
		{	_INDEX_TABSTOP,					0,				0	},
		{	_INDEX_TAG,						0,				0	},
		{	_INDEX_TERMINATEREAD,			0,				0	},
		{	_INDEX_TEXT,					0,				0	},
		{	_INDEX_THEMES,					0,				0	},
		{	_INDEX_TOOLTIPTEXT,				0,				0	},
		{	_INDEX_TOP,						0,				0	},
		{	_INDEX_VALUE,					0,				0	},
		{	_INDEX_VISIBLE,					0,				0	},
		{	_INDEX_WHATSTHISHELPID,			0,				0	},
		{	_INDEX_WIDTH,					0,				0	},
		{	0,								0,				0	},
	};
	const u32 gnProps_textboxSize = sizeof(gsProps_textbox) / sizeof(SPropertyMap) - 1;

	SPropertyMap gsProps_editbox[] =
	{
		{	_INDEX_ADDLINEFEEDS,			0,				0	},
		{	_INDEX_ALIGNMENT,				0,				0	},
		{	_INDEX_ALLOWTABS,				0,				0	},
		{	_INDEX_ANCHOR,					0,				0	},
		{	_INDEX_APPLICATION,				0,				0	},
		{	_INDEX_BACKSTYLE,				0,				0	},
		{	_INDEX_BASECLASS,				0,				0	},
		{	_INDEX_CLASS,					0,				0	},
		{	_INDEX_CLASSLIBRARY,			0,				0	},
		{	_INDEX_BORDERCOLOR,				0,				0	},
		{	_INDEX_BORDERSTYLE,				0,				0	},
		{	_INDEX_COLORSCHEME,				0,				0	},
		{	_INDEX_COLORSOURCE,				0,				0	},
		{	_INDEX_FORECOLOR,				0,				0	},
		{	_INDEX_BACKCOLOR,				0,				0	},
		{	_INDEX_DISABLEDBACKCOLOR,		0,				0	},
		{	_INDEX_DISABLEDFORECOLOR,		0,				0	},
		{	_INDEX_COMMENT,					0,				0	},
		{	_INDEX_CONTROLSOURCE,			0,				0	},
		{	_INDEX_DRAGICON,				0,				0	},
		{	_INDEX_DRAGMODE,				0,				0	},
		{	_INDEX_ENABLED,					0,				0	},
		{	_INDEX_ENABLEHYPERLINKS,		0,				0	},
		{	_INDEX_FONTBOLD,				0,				0	},
		{	_INDEX_FONTCHARSET,				0,				0	},
		{	_INDEX_FONTCONDENSE,			0,				0	},
		{	_INDEX_FONTEXTEND,				0,				0	},
		{	_INDEX_FONTITALIC,				0,				0	},
		{	_INDEX_FONTNAME,				0,				0	},
		{	_INDEX_FONTOUTLINE,				0,				0	},
		{	_INDEX_FONTSHADOW,				0,				0	},
		{	_INDEX_FONTSIZE,				0,				0	},
		{	_INDEX_FONTSTRIKETHRU,			0,				0	},
		{	_INDEX_FONTUNDERLINE,			0,				0	},
		{	_INDEX_FORMAT,					0,				0	},
		{	_INDEX_HEIGHT,					0,				0	},
		{	_INDEX_HELPCONTEXTID,			0,				0	},
		{	_INDEX_HIDESELECTION,			0,				0	},
		{	_INDEX_IMEMODE,					0,				0	},
		{	_INDEX_INTEGRALHEIGHT,			0,				0	},
		{	_INDEX_LEFT,					0,				0	},
		{	_INDEX_MARGIN,					0,				0	},
		{	_INDEX_MAXLENGTH,				0,				0	},
		{	_INDEX_MOUSEICON,				0,				0	},
		{	_INDEX_MOUSEPOINTER,			0,				0	},
		{	_INDEX_NAME,					0,				0	},
		{	_INDEX_NULLDISPLAY,				0,				0	},
		{	_INDEX_OLEDRAGMODE,				0,				0	},
		{	_INDEX_OLEDRAGPICTURE,			0,				0	},
		{	_INDEX_OLEDROPEFFECTS,			0,				0	},
		{	_INDEX_OLEDROPHASDATA,			0,				0	},
		{	_INDEX_OLEDROPMODE,				0,				0	},
		{	_INDEX_OLEDROPTEXTINSERTION,	0,				0	},
		{	_INDEX_PARENT,					0,				0	},
		{	_INDEX_PARENTCLASS,				0,				0	},
		{	_INDEX_PASSWORDCHAR,			0,				0	},
		{	_INDEX_READONLY,				0,				0	},
		{	_INDEX_RIGHTTOLEFT,				0,				0	},
		{	_INDEX_SCROLLBARS,				0,				0	},
		{	_INDEX_SELECTEDBACKCOLOR,		0,				0	},
		{	_INDEX_SELECTEDFORECOLOR,		0,				0	},
		{	_INDEX_SELECTONENTRY,			0,				0	},
		{	_INDEX_SELLENGTH,				0,				0	},
		{	_INDEX_SELSTART,				0,				0	},
		{	_INDEX_SELTEXT,					0,				0	},
		{	_INDEX_SPECIALEFFECT,			0,				0	},
		{	_INDEX_STATUSBARTEXT,			0,				0	},
		{	_INDEX_TABINDEX,				0,				0	},
		{	_INDEX_TABSTOP,					0,				0	},
		{	_INDEX_TAG,						0,				0	},
		{	_INDEX_TERMINATEREAD,			0,				0	},
		{	_INDEX_TEXT,					0,				0	},
		{	_INDEX_TOOLTIPTEXT,				0,				0	},
		{	_INDEX_TOP,						0,				0	},
		{	_INDEX_VALUE,					0,				0	},
		{	_INDEX_VISIBLE,					0,				0	},
		{	_INDEX_WHATSTHISHELPID,			0,				0	},
		{	_INDEX_WIDTH,					0,				0	},
		{	0,								0,				0	},
	};
	const u32 gnProps_editboxSize = sizeof(gsProps_editbox) / sizeof(SPropertyMap) - 1;

	SPropertyMap gsProps_listbox[] =
	{
		{	_INDEX_ANCHOR,					0,				0	},
		{	_INDEX_APPLICATION,				0,				0	},
		{	_INDEX_AUTOHIDESCROLLBAR,		0,				0	},
		{	_INDEX_BASECLASS,				0,				0	},
		{	_INDEX_CLASS,					0,				0	},
		{	_INDEX_CLASSLIBRARY,			0,				0	},
		{	_INDEX_LISTCOUNT,				0,				0	},
		{	_INDEX_COLUMNCOUNT,				0,				0	},
		{	_INDEX_BORDERCOLOR,				0,				0	},
		{	_INDEX_BOUNDCOLUMN,				0,				0	},
		{	_INDEX_BOUNDTO,					0,				0	},
		{	_INDEX_COLORSCHEME,				0,				0	},
		{	_INDEX_COLORSOURCE,				0,				0	},
		{	_INDEX_DISABLEDBACKCOLOR,		0,				0	},
		{	_INDEX_DISABLEDFORECOLOR,		0,				0	},
		{	_INDEX_DISABLEDITEMBACKCOLOR,	0,				0	},
		{	_INDEX_DISABLEDITEMFORECOLOR,	0,				0	},
		{	_INDEX_COLUMNLINES,				0,				0	},
		{	_INDEX_COLUMNWIDTHS,			0,				0	},
		{	_INDEX_COMMENT,					0,				0	},
		{	_INDEX_CONTROLSOURCE,			0,				0	},
		{	_INDEX_ROWSOURCE,				0,				0	},
		{	_INDEX_ROWSOURCETYPE,			0,				0	},
		{	_INDEX_DISPLAYVALUE,			0,				0	},
		{	_INDEX_DRAGICON,				0,				0	},
		{	_INDEX_DRAGMODE,				0,				0	},
		{	_INDEX_ENABLED,					0,				0	},
		{	_INDEX_FIRSTELEMENT,			0,				0	},
		{	_INDEX_FONTBOLD,				0,				0	},
		{	_INDEX_FONTCHARSET,				0,				0	},
		{	_INDEX_FONTCONDENSE,			0,				0	},
		{	_INDEX_FONTEXTEND,				0,				0	},
		{	_INDEX_FONTITALIC,				0,				0	},
		{	_INDEX_FONTNAME,				0,				0	},
		{	_INDEX_FONTOUTLINE,				0,				0	},
		{	_INDEX_FONTSHADOW,				0,				0	},
		{	_INDEX_FONTSIZE,				0,				0	},
		{	_INDEX_FONTSTRIKETHRU,			0,				0	},
		{	_INDEX_FONTUNDERLINE,			0,				0	},
		{	_INDEX_HEIGHT,					0,				0	},
		{	_INDEX_HELPCONTEXTID,			0,				0	},
		{	_INDEX_INCREMENTALSEARCH,		0,				0	},
		{	_INDEX_INTEGRALHEIGHT,			0,				0	},
		{	_INDEX_ITEMBACKCOLOR,			0,				0	},
		{	_INDEX_ITEMFORECOLOR,			0,				0	},
		{	_INDEX_ITEMDATA,				0,				0	},
		{	_INDEX_ITEMIDDATA,				0,				0	},
		{	_INDEX_ITEMTIPS,				0,				0	},
		{	_INDEX_LEFT,					0,				0	},
		{	_INDEX_LIST,					0,				0	},
		{	_INDEX_LISTINDEX,				0,				0	},
		{	_INDEX_LISTITEM,				0,				0	},
		{	_INDEX_LISTITEMID,				0,				0	},
		{	_INDEX_MOUSEICON,				0,				0	},
		{	_INDEX_MOUSEPOINTER,			0,				0	},
		{	_INDEX_MOVERBARS,				0,				0	},
		{	_INDEX_MULTISELECT,				0,				0	},
		{	_INDEX_NAME,					0,				0	},
		{	_INDEX_NEWINDEX,				0,				0	},
		{	_INDEX_NEWITEMID,				0,				0	},
		{	_INDEX_NULLDISPLAY,				0,				0	},
		{	_INDEX_NUMBEROFELEMENTS,		0,				0	},
		{	_INDEX_OLEDRAGMODE,				0,				0	},
		{	_INDEX_OLEDRAGPICTURE,			0,				0	},
		{	_INDEX_OLEDROPEFFECTS,			0,				0	},
		{	_INDEX_OLEDROPHASDATA,			0,				0	},
		{	_INDEX_OLEDROPMODE,				0,				0	},
		{	_INDEX_PARENT,					0,				0	},
		{	_INDEX_PARENTCLASS,				0,				0	},
		{	_INDEX_PICTURE,					0,				0	},
		{	_INDEX_RIGHTTOLEFT,				0,				0	},
		{	_INDEX_SELECTED,				0,				0	},
		{	_INDEX_SELECTEDID,				0,				0	},
		{	_INDEX_SELECTEDITEMBACKCOLOR,	0,				0	},
		{	_INDEX_SELECTEDITEMFORECOLOR,	0,				0	},
		{	_INDEX_SORTED,					0,				0	},
		{	_INDEX_SPECIALEFFECT,			0,				0	},
		{	_INDEX_STATUSBARTEXT,			0,				0	},
		{	_INDEX_TABINDEX,				0,				0	},
		{	_INDEX_TABSTOP,					0,				0	},
		{	_INDEX_TAG,						0,				0	},
		{	_INDEX_TERMINATEREAD,			0,				0	},
		{	_INDEX_THEMES,					0,				0	},
		{	_INDEX_TOOLTIPTEXT,				0,				0	},
		{	_INDEX_TOP,						0,				0	},
		{	_INDEX_TOPINDEX,				0,				0	},
		{	_INDEX_TOPITEMID,				0,				0	},
		{	_INDEX_VALUE,					0,				0	},
		{	_INDEX_VISIBLE,					0,				0	},
		{	_INDEX_WHATSTHISHELPID,			0,				0	},
		{	_INDEX_WIDTH,					0,				0	},
		{	0,								0,				0	},
	};
	const u32 gnProps_listboxSize = sizeof(gsProps_listbox) / sizeof(SPropertyMap) - 1;

	SPropertyMap gsProps_combobox[] =
	{
		{	_INDEX_ALIGNMENT,				0,				0	},
		{	_INDEX_ANCHOR,					0,				0	},
		{	_INDEX_APPLICATION,				0,				0	},
		{	_INDEX_BASECLASS,				0,				0	},
		{	_INDEX_CLASS,					0,				0	},
		{	_INDEX_CLASSLIBRARY,			0,				0	},
		{	_INDEX_LISTCOUNT,				0,				0	},
		{	_INDEX_COLUMNCOUNT,				0,				0	},
		{	_INDEX_BORDERCOLOR,				0,				0	},
		{	_INDEX_BORDERSTYLE,				0,				0	},
		{	_INDEX_BOUNDCOLUMN,				0,				0	},
		{	_INDEX_BOUNDTO,					0,				0	},
		{	_INDEX_COLORSCHEME,				0,				0	},
		{	_INDEX_COLORSOURCE,				0,				0	},
		{	_INDEX_FORECOLOR,				0,				0	},
		{	_INDEX_BACKCOLOR,				0,				0	},
		{	_INDEX_DISABLEDBACKCOLOR,		0,				0	},
		{	_INDEX_DISABLEDFORECOLOR,		0,				0	},
		{	_INDEX_DISABLEDITEMBACKCOLOR,	0,				0	},
		{	_INDEX_DISABLEDITEMFORECOLOR,	0,				0	},
		{	_INDEX_COLUMNLINES,				0,				0	},
		{	_INDEX_COLUMNWIDTHS,			0,				0	},
		{	_INDEX_COMMENT,					0,				0	},
		{	_INDEX_CONTROLSOURCE,			0,				0	},
		{	_INDEX_ROWSOURCE,				0,				0	},
		{	_INDEX_ROWSOURCETYPE,			0,				0	},
		{	_INDEX_DISPLAYCOUNT,			0,				0	},
		{	_INDEX_DISPLAYVALUE,			0,				0	},
		{	_INDEX_DRAGICON,				0,				0	},
		{	_INDEX_DRAGMODE,				0,				0	},
		{	_INDEX_ENABLED,					0,				0	},
		{	_INDEX_FIRSTELEMENT,			0,				0	},
		{	_INDEX_FONTBOLD,				0,				0	},
		{	_INDEX_FONTCHARSET,				0,				0	},
		{	_INDEX_FONTCONDENSE,			0,				0	},
		{	_INDEX_FONTEXTEND,				0,				0	},
		{	_INDEX_FONTITALIC,				0,				0	},
		{	_INDEX_FONTNAME,				0,				0	},
		{	_INDEX_FONTOUTLINE,				0,				0	},
		{	_INDEX_FONTSHADOW,				0,				0	},
		{	_INDEX_FONTSIZE,				0,				0	},
		{	_INDEX_FONTSTRIKETHRU,			0,				0	},
		{	_INDEX_FONTUNDERLINE,			0,				0	},
		{	_INDEX_FORMAT,					0,				0	},
		{	_INDEX_HEIGHT,					0,				0	},
		{	_INDEX_HELPCONTEXTID,			0,				0	},
		{	_INDEX_HIDESELECTION,			0,				0	},
		{	_INDEX_IMEMODE,					0,				0	},
		{	_INDEX_INCREMENTALSEARCH,		0,				0	},
		{	_INDEX_INPUTMASK,				0,				0	},
		{	_INDEX_ITEMBACKCOLOR,			0,				0	},
		{	_INDEX_ITEMFORECOLOR,			0,				0	},
		{	_INDEX_ITEMDATA,				0,				0	},
		{	_INDEX_ITEMIDDATA,				0,				0	},
		{	_INDEX_ITEMTIPS,				0,				0	},
		{	_INDEX_LEFT,					0,				0	},
		{	_INDEX_LIST,					0,				0	},
		{	_INDEX_LISTINDEX,				0,				0	},
		{	_INDEX_LISTITEM,				0,				0	},
		{	_INDEX_LISTITEMID,				0,				0	},
		{	_INDEX_MARGIN,					0,				0	},
		{	_INDEX_MAXLENGTH,				0,				0	},
		{	_INDEX_MOUSEICON,				0,				0	},
		{	_INDEX_MOUSEPOINTER,			0,				0	},
		{	_INDEX_NAME,					0,				0	},
		{	_INDEX_NEWINDEX,				0,				0	},
		{	_INDEX_NEWITEMID,				0,				0	},
		{	_INDEX_NULLDISPLAY,				0,				0	},
		{	_INDEX_NUMBEROFELEMENTS,		0,				0	},
		{	_INDEX_OLEDRAGMODE,				0,				0	},
		{	_INDEX_OLEDRAGPICTURE,			0,				0	},
		{	_INDEX_OLEDROPEFFECTS,			0,				0	},
		{	_INDEX_OLEDROPHASDATA,			0,				0	},
		{	_INDEX_OLEDROPMODE,				0,				0	},
		{	_INDEX_OLEDROPTEXTINSERTION,	0,				0	},
		{	_INDEX_PARENT,					0,				0	},
		{	_INDEX_PARENTCLASS,				0,				0	},
		{	_INDEX_PICTURE,					0,				0	},
		{	_INDEX_PICTURESELECTIONDISPLAY,	0,				0	},
		{	_INDEX_READONLY,				0,				0	},
		{	_INDEX_RIGHTTOLEFT,				0,				0	},
		{	_INDEX_SELECTED,				0,				0	},
		{	_INDEX_SELECTEDID,				0,				0	},
		{	_INDEX_SELECTEDBACKCOLOR,		0,				0	},
		{	_INDEX_SELECTEDFORECOLOR,		0,				0	},
		{	_INDEX_SELECTEDITEMBACKCOLOR,	0,				0	},
		{	_INDEX_SELECTEDITEMFORECOLOR,	0,				0	},
		{	_INDEX_SELECTONENTRY,			0,				0	},
		{	_INDEX_SELLENGTH,				0,				0	},
		{	_INDEX_SELSTART,				0,				0	},
		{	_INDEX_SELTEXT,					0,				0	},
		{	_INDEX_SORTED,					0,				0	},
		{	_INDEX_SPECIALEFFECT,			0,				0	},
		{	_INDEX_STATUSBARTEXT,			0,				0	},
		{	_INDEX_STYLE,					0,				0	},
		{	_INDEX_TABINDEX,				0,				0	},
		{	_INDEX_TABSTOP,					0,				0	},
		{	_INDEX_TAG,						0,				0	},
		{	_INDEX_TERMINATEREAD,			0,				0	},
		{	_INDEX_TEXT,					0,				0	},
		{	_INDEX_THEMES,					0,				0	},
		{	_INDEX_TOOLTIPTEXT,				0,				0	},
		{	_INDEX_TOP,						0,				0	},
		{	_INDEX_TOPINDEX,				0,				0	},
		{	_INDEX_TOPITEMID,				0,				0	},
		{	_INDEX_VALUE,					0,				0	},
		{	_INDEX_VISIBLE,					0,				0	},
		{	_INDEX_WHATSTHISHELPID,			0,				0	},
		{	_INDEX_WIDTH,					0,				0	},
		{	0,								0,				0	},
	};
	const u32 gnProps_comboboxSize = sizeof(gsProps_combobox) / sizeof(SPropertyMap) - 1;

	SPropertyMap gsProps_form[] =
	{
		{	_INDEX_ACTIVECONTROL,			0,				0	},
		{	_INDEX_ACTIVEFORM,				0,				0	},
		{	_INDEX_ALLOWOUTPUT,				0,				0	},
		{	_INDEX_ALWAYSONTOP,				0,				0	},
		{	_INDEX_ALWAYSONBOTTOM,			0,				0	},
		{	_INDEX_BINDCONTROLS,			0,				0	},
		{	_INDEX_BUFFERMODE,				0,				0	},
		{	_INDEX_CONTROLBOX,				0,				0	},
		{	_INDEX_CLOSABLE,				0,				0	},
		{	_INDEX_CONTINUOUSSCROLL,		0,				0	},
		{	_INDEX_DATASESSION,				0,				0	},
		{	_INDEX_DATASESSIONID,			0,				0	},
		{	_INDEX_DATAENVIRONMENT,			0,				0	},
		{	_INDEX_DECLASS,					0,				0	},
		{	_INDEX_DECLASSLIBRARY,			0,				0	},
		{	_INDEX_DEFOLELCID,				0,				0	},
		{	_INDEX_DESKTOP,					0,				0	},
		{	_INDEX_MACDESKTOP,				0,				0	},
		{	_INDEX_DOCKPOSITION,			0,				0	},
		{	_INDEX_DOCKABLE,				0,				0	},
		{	_INDEX_DOCKED,					0,				0	},
		{	_INDEX_MDIFORM,					0,				0	},
		{	_INDEX_DOCREATE,				0,				0	},
		{	_INDEX_FILLCOLOR,				0,				0	},
		{	_INDEX_FILLSTYLE,				0,				0	},
		{	_INDEX_HSCROLLSMALLCHANGE,		0,				0	},
		{	_INDEX_VSCROLLSMALLCHANGE,		0,				0	},
		{	_INDEX_LOCKSCREEN,				0,				0	},
		{	_INDEX_MAXBUTTON,				0,				0	},
		{	_INDEX_MINBUTTON,				0,				0	},
		{	_INDEX_MOVABLE,					0,				0	},
		{	_INDEX_MAXHEIGHT,				0,				0	},
		{	_INDEX_MAXWIDTH,				0,				0	},
		{	_INDEX_MAXTOP,					0,				0	},
		{	_INDEX_MAXLEFT,					0,				0	},
		{	_INDEX_MINHEIGHT,				0,				0	},
		{	_INDEX_MINWIDTH,				0,				0	},
		{	_INDEX_SCALEMODE,				0,				0	},
		{	_INDEX_SHOWTIPS,				0,				0	},
		{	_INDEX_SHOWWINDOW,				0,				0	},
		{	_INDEX_SHOWINTASKBAR,			0,				0	},
		{	_INDEX_SIZEBOX,					0,				0	},
		{	_INDEX_WINDOWTYPE,				0,				0	},
		{	_INDEX_WINDOWSTATE,				0,				0	},
		{	_INDEX_AUTOCENTER,				0,				0	},
		{	_INDEX_BASECLASS,				0,				0	},
		{	_INDEX_CLASS,					0,				0	},
		{	_INDEX_CLASSLIBRARY,			0,				0	},
		{	_INDEX_CONTROLS,				0,				0	},
		{	_INDEX_CONTROLCOUNT,			0,				0	},
		{	_INDEX_OBJECTS,					0,				0	},
		{	_INDEX_BORDERSTYLE,				0,				0	},
		{	_INDEX_CLIPCONTROLS,			0,				0	},
		{	_INDEX_CAPTION,					0,				0	},
		{	_INDEX_HALFHEIGHTCAPTION,		0,				0	},
		{	_INDEX_COLORSOURCE,				0,				0	},
		{	_INDEX_FORECOLOR,				0,				0	},
		{	_INDEX_BACKCOLOR,				0,				0	},
		{	_INDEX_CURRENTX,				0,				0	},
		{	_INDEX_CURRENTY,				0,				0	},
		{	_INDEX_COMMENT,					0,				0	},
		{	_INDEX_DRAWMODE,				0,				0	},
		{	_INDEX_DRAWSTYLE,				0,				0	},
		{	_INDEX_DRAWWIDTH,				0,				0	},
		{	_INDEX_ENABLED,					0,				0	},
		{	_INDEX_FONTBOLD,				0,				0	},
		{	_INDEX_FONTCHARSET,				0,				0	},
		{	_INDEX_FONTCONDENSE,			0,				0	},
		{	_INDEX_FONTEXTEND,				0,				0	},
		{	_INDEX_FONTITALIC,				0,				0	},
		{	_INDEX_FONTNAME,				0,				0	},
		{	_INDEX_FONTOUTLINE,				0,				0	},
		{	_INDEX_FONTSHADOW,				0,				0	},
		{	_INDEX_FONTSIZE,				0,				0	},
		{	_INDEX_FONTSTRIKETHRU,			0,				0	},
		{	_INDEX_FONTUNDERLINE,			0,				0	},
		{	_INDEX_HEIGHT,					0,				0	},
		{	_INDEX_HELPCONTEXTID,			0,				0	},
		{	_INDEX_HWND,					0,				0	},
		{	_INDEX_KEYPREVIEW,				0,				0	},
		{	_INDEX_LEFT,					0,				0	},
		{	_INDEX_LOCKSCREEN,				0,				0	},
		{	_INDEX_MOUSEICON,				0,				0	},
		{	_INDEX_MOUSEPOINTER,			0,				0	},
		{	_INDEX_NAME,					0,				0	},
		{	_INDEX_OLEDRAGMODE,				0,				0	},
		{	_INDEX_OLEDRAGPICTURE,			0,				0	},
		{	_INDEX_OLEDROPEFFECTS,			0,				0	},
		{	_INDEX_OLEDROPHASDATA,			0,				0	},
		{	_INDEX_OLEDROPMODE,				0,				0	},
		{	_INDEX_PARENT,					0,				0	},
		{	_INDEX_PARENTCLASS,				0,				0	},
		{	_INDEX_ICON,					0,				0	},
		{	_INDEX_PICTURE,					0,				0	},
		{	_INDEX_RELEASETYPE,				0,				0	},
		{	_INDEX_RIGHTTOLEFT,				0,				0	},
		{	_INDEX_SCROLLBARS,				0,				0	},
		{	_INDEX_TABINDEX,				0,				0	},
		{	_INDEX_TABSTOP,					0,				0	},
		{	_INDEX_TAG,						0,				0	},
		{	_INDEX_THEMES,					0,				0	},
		{	_INDEX_TITLEBAR,				0,				0	},
		{	_INDEX_TOP,						0,				0	},
		{	_INDEX_VISIBLE,					0,				0	},
		{	_INDEX_VIEWPORTHEIGHT,			0,				0	},
		{	_INDEX_VIEWPORTLEFT,			0,				0	},
		{	_INDEX_VIEWPORTTOP,				0,				0	},
		{	_INDEX_VIEWPORTWIDTH,			0,				0	},
		{	_INDEX_WHATSTHISHELPID,			0,				0	},
		{	_INDEX_WHATSTHISHELP,			0,				0	},
		{	_INDEX_WHATSTHISBUTTON,			0,				0	},
		{	_INDEX_WIDTH,					0,				0	},
		{	_INDEX_ZOOMBOX,					0,				0	},
		{	0,								0,				0	},
	};
	const u32 gnProps_formSize = sizeof(gsProps_form) / sizeof(SPropertyMap) - 1;

	SPropertyMap gsProps_formset[] =
	{
		{	_INDEX_ACTIVEFORM,				0,				0	},
		{	_INDEX_AUTORELEASE,				0,				0	},
		{	_INDEX_BUFFERMODE,				0,				0	},
		{	_INDEX_DATASESSION,				0,				0	},
		{	_INDEX_DATASESSIONID,			0,				0	},
		{	_INDEX_DATAENVIRONMENT,			0,				0	},
		{	_INDEX_APPLICATION,				0,				0	},
		{	_INDEX_BASECLASS,				0,				0	},
		{	_INDEX_CLASS,					0,				0	},
		{	_INDEX_CLASSLIBRARY,			0,				0	},
		{	_INDEX_FORMS,					0,				0	},
		{	_INDEX_FORMCOUNT,				0,				0	},
		{	_INDEX_OBJECTS,					0,				0	},
		{	_INDEX_COMMENT,					0,				0	},
		{	_INDEX_NAME,					0,				0	},
		{	_INDEX_PARENT,					0,				0	},
		{	_INDEX_PARENTCLASS,				0,				0	},
		{	_INDEX_READBACKCOLOR,			0,				0	},
		{	_INDEX_READCYCLE,				0,				0	},
		{	_INDEX_READFORECOLOR,			0,				0	},
		{	_INDEX_READLOCK,				0,				0	},
		{	_INDEX_READMOUSE,				0,				0	},
		{	_INDEX_READSAVE,				0,				0	},
		{	_INDEX_READTIMEOUT,				0,				0	},
		{	_INDEX_TAG,						0,				0	},
		{	_INDEX_VISIBLE,					0,				0	},
		{	_INDEX_WINDOWLIST,				0,				0	},
		{	_INDEX_WINDOWTYPE,				0,				0	},
		{	0,								0,				0	},
	};
	const u32 gnProps_formsetSize = sizeof(gsProps_formset) / sizeof(SPropertyMap) - 1;

	SPropertyMap gsProps_toolbar[] =
	{
		{	_INDEX_ACTIVECONTROL,			0,				0	},
		{	_INDEX_CONTROLBOX,				0,				0	},
		{	_INDEX_DATASESSION,				0,				0	},
		{	_INDEX_DATASESSIONID,			0,				0	},
		{	_INDEX_DOCKPOSITION,			0,				0	},
		{	_INDEX_DOCKED,					0,				0	},
		{	_INDEX_MOVABLE,					0,				0	},
		{	_INDEX_SCALEMODE,				0,				0	},
		{	_INDEX_SHOWTIPS,				0,				0	},
		{	_INDEX_SHOWWINDOW,				0,				0	},
		{	_INDEX_APPLICATION,				0,				0	},
		{	_INDEX_BASECLASS,				0,				0	},
		{	_INDEX_CLASS,					0,				0	},
		{	_INDEX_CLASSLIBRARY,			0,				0	},
		{	_INDEX_CONTROLS,				0,				0	},
		{	_INDEX_CONTROLCOUNT,			0,				0	},
		{	_INDEX_OBJECTS,					0,				0	},
		{	_INDEX_CAPTION,					0,				0	},
		{	_INDEX_COLORSOURCE,				0,				0	},
		{	_INDEX_FORECOLOR,				0,				0	},
		{	_INDEX_BACKCOLOR,				0,				0	},
		{	_INDEX_COMMENT,					0,				0	},
		{	_INDEX_ENABLED,					0,				0	},
		{	_INDEX_HEIGHT,					0,				0	},
		{	_INDEX_HELPCONTEXTID,			0,				0	},
		{	_INDEX_HWND,					0,				0	},
		{	_INDEX_KEYPREVIEW,				0,				0	},
		{	_INDEX_LEFT,					0,				0	},
		{	_INDEX_LOCKSCREEN,				0,				0	},
		{	_INDEX_MOUSEICON,				0,				0	},
		{	_INDEX_MOUSEPOINTER,			0,				0	},
		{	_INDEX_NAME,					0,				0	},
		{	_INDEX_OLEDRAGMODE,				0,				0	},
		{	_INDEX_OLEDRAGPICTURE,			0,				0	},
		{	_INDEX_OLEDROPEFFECTS,			0,				0	},
		{	_INDEX_OLEDROPHASDATA,			0,				0	},
		{	_INDEX_OLEDROPMODE,				0,				0	},
		{	_INDEX_PARENT,					0,				0	},
		{	_INDEX_PARENTCLASS,				0,				0	},
		{	_INDEX_SIZABLE,					0,				0	},
		{	_INDEX_TAG,						0,				0	},
		{	_INDEX_THEMES,					0,				0	},
		{	_INDEX_TOP,						0,				0	},
		{	_INDEX_VISIBLE,					0,				0	},
		{	_INDEX_WHATSTHISHELPID,			0,				0	},
		{	_INDEX_WIDTH,					0,				0	},
		{	0,								0,				0	},
	};
	const u32 gnProps_toolbarSize = sizeof(gsProps_toolbar) / sizeof(SPropertyMap) - 1;

	SPropertyMap gsProps_separator[] =
	{
		{	_INDEX_APPLICATION,				0,				0	},
		{	_INDEX_BASECLASS,				0,				0	},
		{	_INDEX_CLASS,					0,				0	},
		{	_INDEX_CLASSLIBRARY,			0,				0	},
		{	_INDEX_COMMENT,					0,				0	},
		{	_INDEX_ENABLED,					0,				0	},
		{	_INDEX_NAME,					0,				0	},
		{	_INDEX_PARENT,					0,				0	},
		{	_INDEX_PARENTCLASS,				0,				0	},
		{	_INDEX_STYLE,					0,				0	},
		{	_INDEX_TAG,						0,				0	},
		{	_INDEX_VISIBLE,					0,				0	},
		{	0,								0,				0	},
	};
	const u32 gnProps_separatorSize = sizeof(gsProps_separator) / sizeof(SPropertyMap) - 1;

	SPropertyMap gsProps_line[] =
	{
		{	_INDEX_ANCHOR,					0,				0	},
		{	_INDEX_APPLICATION,				0,				0	},
		{	_INDEX_BASECLASS,				0,				0	},
		{	_INDEX_CLASS,					0,				0	},
		{	_INDEX_CLASSLIBRARY,			0,				0	},
		{	_INDEX_BORDERCOLOR,				0,				0	},
		{	_INDEX_BORDERWIDTH,				0,				0	},
		{	_INDEX_BORDERSTYLE,				0,				0	},
		{	_INDEX_COLORSOURCE,				0,				0	},
		{	_INDEX_COMMENT,					0,				0	},
		{	_INDEX_DRAGICON,				0,				0	},
		{	_INDEX_DRAGMODE,				0,				0	},
		{	_INDEX_DRAWMODE,				0,				0	},
		{	_INDEX_ENABLED,					0,				0	},
		{	_INDEX_HEIGHT,					0,				0	},
		{	_INDEX_HELPCONTEXTID,			0,				0	},
		{	_INDEX_LEFT,					0,				0	},
		{	_INDEX_LINESLANT,				0,				0	},
		{	_INDEX_MOUSEPOINTER,			0,				0	},
		{	_INDEX_NAME,					0,				0	},
		{	_INDEX_OLEDRAGMODE,				0,				0	},
		{	_INDEX_OLEDRAGPICTURE,			0,				0	},
		{	_INDEX_OLEDROPEFFECTS,			0,				0	},
		{	_INDEX_OLEDROPHASDATA,			0,				0	},
		{	_INDEX_OLEDROPMODE,				0,				0	},
		{	_INDEX_PARENT,					0,				0	},
		{	_INDEX_PARENTCLASS,				0,				0	},
		{	_INDEX_POLYPOINTS,				0,				0	},
		{	_INDEX_ROTATION,				0,				0	},
		{	_INDEX_STATUSBARTEXT,			0,				0	},
		{	_INDEX_TAG,						0,				0	},
		{	_INDEX_TOOLTIPTEXT,				0,				0	},
		{	_INDEX_TOP,						0,				0	},
		{	_INDEX_VISIBLE,					0,				0	},
		{	_INDEX_WHATSTHISHELPID,			0,				0	},
		{	_INDEX_WIDTH,					0,				0	},
		{	0,								0,				0	},
	};
	const u32 gnProps_lineSize = sizeof(gsProps_line) / sizeof(SPropertyMap) - 1;

	SPropertyMap gsProps_shape[] =
	{
		{	_INDEX_FILLCOLOR,				0,				0	},
		{	_INDEX_FILLSTYLE,				0,				0	},
		{	_INDEX_ANCHOR,					0,				0	},
		{	_INDEX_APPLICATION,				0,				0	},
		{	_INDEX_BACKSTYLE,				0,				0	},
		{	_INDEX_BASECLASS,				0,				0	},
		{	_INDEX_CLASS,					0,				0	},
		{	_INDEX_CLASSLIBRARY,			0,				0	},
		{	_INDEX_BORDERCOLOR,				0,				0	},
		{	_INDEX_BORDERWIDTH,				0,				0	},
		{	_INDEX_BORDERSTYLE,				0,				0	},
		{	_INDEX_CURVATURE,				0,				0	},
		{	_INDEX_COLORSCHEME,				0,				0	},
		{	_INDEX_COLORSOURCE,				0,				0	},
		{	_INDEX_BACKCOLOR,				0,				0	},
		{	_INDEX_COMMENT,					0,				0	},
		{	_INDEX_DRAGICON,				0,				0	},
		{	_INDEX_DRAGMODE,				0,				0	},
		{	_INDEX_DRAWMODE,				0,				0	},
		{	_INDEX_ENABLED,					0,				0	},
		{	_INDEX_HEIGHT,					0,				0	},
		{	_INDEX_HELPCONTEXTID,			0,				0	},
		{	_INDEX_LEFT,					0,				0	},
		{	_INDEX_MOUSEICON,				0,				0	},
		{	_INDEX_MOUSEPOINTER,			0,				0	},
		{	_INDEX_NAME,					0,				0	},
		{	_INDEX_OLEDRAGMODE,				0,				0	},
		{	_INDEX_OLEDRAGPICTURE,			0,				0	},
		{	_INDEX_OLEDROPEFFECTS,			0,				0	},
		{	_INDEX_OLEDROPHASDATA,			0,				0	},
		{	_INDEX_OLEDROPMODE,				0,				0	},
		{	_INDEX_PARENT,					0,				0	},
		{	_INDEX_PARENTCLASS,				0,				0	},
		{	_INDEX_POLYPOINTS,				0,				0	},
		{	_INDEX_ROTATION,				0,				0	},
		{	_INDEX_SPECIALEFFECT,			0,				0	},
		{	_INDEX_TAG,						0,				0	},
		{	_INDEX_TOOLTIPTEXT,				0,				0	},
		{	_INDEX_TOP,						0,				0	},
		{	_INDEX_VISIBLE,					0,				0	},
		{	_INDEX_WHATSTHISHELPID,			0,				0	},
		{	_INDEX_WIDTH,					0,				0	},
		{	0,								0,				0	},
	};
	const u32 gnProps_shapeSize = sizeof(gsProps_shape) / sizeof(SPropertyMap) - 1;

	SPropertyMap gsProps_image[] =
	{
		{	_INDEX_ANCHOR,					0,				0	},
		{	_INDEX_APPLICATION,				0,				0	},
		{	_INDEX_BACKSTYLE,				0,				0	},
		{	_INDEX_BASECLASS,				0,				0	},
		{	_INDEX_CLASS,					0,				0	},
		{	_INDEX_CLASSLIBRARY,			0,				0	},
		{	_INDEX_BORDERCOLOR,				0,				0	},
		{	_INDEX_BORDERSTYLE,				0,				0	},
		{	_INDEX_COLORSOURCE,				0,				0	},
		{	_INDEX_COMMENT,					0,				0	},
		{	_INDEX_DRAGICON,				0,				0	},
		{	_INDEX_DRAGMODE,				0,				0	},
		{	_INDEX_ENABLED,					0,				0	},
		{	_INDEX_HEIGHT,					0,				0	},
		{	_INDEX_HELPCONTEXTID,			0,				0	},
		{	_INDEX_LEFT,					0,				0	},
		{	_INDEX_MOUSEPOINTER,			0,				0	},
		{	_INDEX_NAME,					0,				0	},
		{	_INDEX_OLEDRAGMODE,				0,				0	},
		{	_INDEX_OLEDRAGPICTURE,			0,				0	},
		{	_INDEX_OLEDROPEFFECTS,			0,				0	},
		{	_INDEX_OLEDROPHASDATA,			0,				0	},
		{	_INDEX_OLEDROPMODE,				0,				0	},
		{	_INDEX_PARENT,					0,				0	},
		{	_INDEX_PARENTCLASS,				0,				0	},
		{	_INDEX_PICTURE,					0,				0	},
		{	_INDEX_PICTUREVAL,				0,				0	},
		{	_INDEX_ROTATEFLIP,				0,				0	},
		{	_INDEX_STRETCH,					0,				0	},
		{	_INDEX_STATUSBARTEXT,			0,				0	},
		{	_INDEX_TAG,						0,				0	},
		{	_INDEX_THEMES,					0,				0	},
		{	_INDEX_TOOLTIPTEXT,				0,				0	},
		{	_INDEX_TOP,						0,				0	},
		{	_INDEX_VISIBLE,					0,				0	},
		{	_INDEX_WHATSTHISHELPID,			0,				0	},
		{	_INDEX_WIDTH,					0,				0	},
		{	0,								0,				0	},
	};
	const u32 gnProps_imageSize = sizeof(gsProps_image) / sizeof(SPropertyMap) - 1;

	SPropertyMap gsProps_container[] =
	{
		{	_INDEX_ACTIVECONTROL,			0,				0	},
		{	_INDEX_ANCHOR,					0,				0	},
		{	_INDEX_APPLICATION,				0,				0	},
		{	_INDEX_BACKSTYLE,				0,				0	},
		{	_INDEX_BASECLASS,				0,				0	},
		{	_INDEX_CLASS,					0,				0	},
		{	_INDEX_CLASSLIBRARY,			0,				0	},
		{	_INDEX_CONTROLS,				0,				0	},
		{	_INDEX_CONTROLCOUNT,			0,				0	},
		{	_INDEX_OBJECTS,					0,				0	},
		{	_INDEX_BORDERCOLOR,				0,				0	},
		{	_INDEX_BORDERWIDTH,				0,				0	},
		{	_INDEX_COLORSOURCE,				0,				0	},
		{	_INDEX_FORECOLOR,				0,				0	},
		{	_INDEX_BACKCOLOR,				0,				0	},
		{	_INDEX_COMMENT,					0,				0	},
		{	_INDEX_DRAGICON,				0,				0	},
		{	_INDEX_DRAGMODE,				0,				0	},
		{	_INDEX_ENABLED,					0,				0	},
		{	_INDEX_HEIGHT,					0,				0	},
		{	_INDEX_HELPCONTEXTID,			0,				0	},
		{	_INDEX_LEFT,					0,				0	},
		{	_INDEX_MOUSEICON,				0,				0	},
		{	_INDEX_MOUSEPOINTER,			0,				0	},
		{	_INDEX_NAME,					0,				0	},
		{	_INDEX_OLEDRAGMODE,				0,				0	},
		{	_INDEX_OLEDRAGPICTURE,			0,				0	},
		{	_INDEX_OLEDROPEFFECTS,			0,				0	},
		{	_INDEX_OLEDROPHASDATA,			0,				0	},
		{	_INDEX_OLEDROPMODE,				0,				0	},
		{	_INDEX_PARENT,					0,				0	},
		{	_INDEX_PARENTCLASS,				0,				0	},
		{	_INDEX_PICTURE,					0,				0	},
		{	_INDEX_SPECIALEFFECT,			0,				0	},
		{	_INDEX_STATUSBARTEXT,			0,				0	},
		{	_INDEX_TABINDEX,				0,				0	},
		{	_INDEX_TABSTOP,					0,				0	},
		{	_INDEX_TAG,						0,				0	},
		{	_INDEX_TOOLTIPTEXT,				0,				0	},
		{	_INDEX_TOP,						0,				0	},
		{	_INDEX_VISIBLE,					0,				0	},
		{	_INDEX_WHATSTHISHELPID,			0,				0	},
		{	_INDEX_WIDTH,					0,				0	},
		{	0,								0,				0	},
	};
	const u32 gnProps_containerSize = sizeof(gsProps_container) / sizeof(SPropertyMap) - 1;

	SPropertyMap gsProps_control[] =
	{
		{	_INDEX_ACTIVECONTROL,			0,				0	},
		{	_INDEX_ANCHOR,					0,				0	},
		{	_INDEX_APPLICATION,				0,				0	},
		{	_INDEX_BACKSTYLE,				0,				0	},
		{	_INDEX_BASECLASS,				0,				0	},
		{	_INDEX_CLASS,					0,				0	},
		{	_INDEX_CLASSLIBRARY,			0,				0	},
		{	_INDEX_CONTROLS,				0,				0	},
		{	_INDEX_CONTROLCOUNT,			0,				0	},
		{	_INDEX_OBJECTS,					0,				0	},
		{	_INDEX_BORDERCOLOR,				0,				0	},
		{	_INDEX_BORDERWIDTH,				0,				0	},
		{	_INDEX_COLORSOURCE,				0,				0	},
		{	_INDEX_FORECOLOR,				0,				0	},
		{	_INDEX_BACKCOLOR,				0,				0	},
		{	_INDEX_COMMENT,					0,				0	},
		{	_INDEX_DRAGICON,				0,				0	},
		{	_INDEX_DRAGMODE,				0,				0	},
		{	_INDEX_ENABLED,					0,				0	},
		{	_INDEX_HEIGHT,					0,				0	},
		{	_INDEX_HELPCONTEXTID,			0,				0	},
		{	_INDEX_LEFT,					0,				0	},
		{	_INDEX_MOUSEICON,				0,				0	},
		{	_INDEX_MOUSEPOINTER,			0,				0	},
		{	_INDEX_NAME,					0,				0	},
		{	_INDEX_OLEDRAGMODE,				0,				0	},
		{	_INDEX_OLEDRAGPICTURE,			0,				0	},
		{	_INDEX_OLEDROPEFFECTS,			0,				0	},
		{	_INDEX_OLEDROPHASDATA,			0,				0	},
		{	_INDEX_OLEDROPMODE,				0,				0	},
		{	_INDEX_PARENT,					0,				0	},
		{	_INDEX_PARENTCLASS,				0,				0	},
		{	_INDEX_PICTURE,					0,				0	},
		{	_INDEX_SPECIALEFFECT,			0,				0	},
		{	_INDEX_STATUSBARTEXT,			0,				0	},
		{	_INDEX_TABINDEX,				0,				0	},
		{	_INDEX_TABSTOP,					0,				0	},
		{	_INDEX_TAG,						0,				0	},
		{	_INDEX_TOOLTIPTEXT,				0,				0	},
		{	_INDEX_TOP,						0,				0	},
		{	_INDEX_VISIBLE,					0,				0	},
		{	_INDEX_WHATSTHISHELPID,			0,				0	},
		{	_INDEX_WIDTH,					0,				0	},
		{	0,								0,				0	},
	};
	const u32 gnProps_controlSize = sizeof(gsProps_control) / sizeof(SPropertyMap) - 1;

	SPropertyMap gsProps_grid[] =
	{
		{	_INDEX_ACTIVECOLUMN,			0,				0	},
		{	_INDEX_ACTIVEROW,				0,				0	},
		{	_INDEX_ALLOWADDNEW,				0,				0	},
		{	_INDEX_ALLOWAUTOCOLUMNFIT,		0,				0	},
		{	_INDEX_ALLOWCELLSELECTION,		0,				0	},
		{	_INDEX_ALLOWHEADERSIZING,		0,				0	},
		{	_INDEX_ALLOWROWSIZING,			0,				0	},
		{	_INDEX_GRIDLINECOLOR,			0,				0	},
		{	_INDEX_GRIDLINES,				0,				0	},
		{	_INDEX_GRIDLINEWIDTH,			0,				0	},
		{	_INDEX_HEADERHEIGHT,			0,				0	},
		{	_INDEX_HIGHLIGHT,				0,				0	},
		{	_INDEX_HIGHLIGHTBACKCOLOR,		0,				0	},
		{	_INDEX_HIGHLIGHTFORECOLOR,		0,				0	},
		{	_INDEX_HIGHLIGHTSTYLE,			0,				0	},
		{	_INDEX_HIGHLIGHTROW,			0,				0	},
		{	_INDEX_HIGHLIGHTROWLINEWIDTH,	0,				0	},
		{	_INDEX_LEFTCOLUMN,				0,				0	},
		{	_INDEX_LINKMASTER,				0,				0	},
		{	_INDEX_CHILDORDER,				0,				0	},
		{	_INDEX_LOCKCOLUMNS,				0,				0	},
		{	_INDEX_LOCKCOLUMNSLEFT,			0,				0	},
		{	_INDEX_MEMBERCLASS,				0,				0	},
		{	_INDEX_MEMBERCLASSLIBRARY,		0,				0	},
		{	_INDEX_OPTIMIZE,				0,				0	},
		{	_INDEX_PARTITION,				0,				0	},
		{	_INDEX_PANELLINK,				0,				0	},
		{	_INDEX_PANEL,					0,				0	},
		{	_INDEX_SPLITBAR,				0,				0	},
		{	_INDEX_DELETEMARK,				0,				0	},
		{	_INDEX_RECORDMARK,				0,				0	},
		{	_INDEX_RELATIVECOLUMN,			0,				0	},
		{	_INDEX_RELATIVEROW,				0,				0	},
		{	_INDEX_VIEW,					0,				0	},
		{	_INDEX_ANCHOR,					0,				0	},
		{	_INDEX_APPLICATION,				0,				0	},
		{	_INDEX_BASECLASS,				0,				0	},
		{	_INDEX_CLASS,					0,				0	},
		{	_INDEX_CLASSLIBRARY,			0,				0	},
		{	_INDEX_COLUMNS,					0,				0	},
		{	_INDEX_COLUMNCOUNT,				0,				0	},
		{	_INDEX_OBJECTS,					0,				0	},
		{	_INDEX_FORECOLOR,				0,				0	},
		{	_INDEX_BACKCOLOR,				0,				0	},
		{	_INDEX_COMMENT,					0,				0	},
		{	_INDEX_RECORDSOURCE,			0,				0	},
		{	_INDEX_RECORDSOURCETYPE,		0,				0	},
		{	_INDEX_DRAGICON,				0,				0	},
		{	_INDEX_DRAGMODE,				0,				0	},
		{	_INDEX_ENABLED,					0,				0	},
		{	_INDEX_FONTBOLD,				0,				0	},
		{	_INDEX_FONTCHARSET,				0,				0	},
		{	_INDEX_FONTCONDENSE,			0,				0	},
		{	_INDEX_FONTEXTEND,				0,				0	},
		{	_INDEX_FONTITALIC,				0,				0	},
		{	_INDEX_FONTNAME,				0,				0	},
		{	_INDEX_FONTOUTLINE,				0,				0	},
		{	_INDEX_FONTSHADOW,				0,				0	},
		{	_INDEX_FONTSIZE,				0,				0	},
		{	_INDEX_FONTSTRIKETHRU,			0,				0	},
		{	_INDEX_FONTUNDERLINE,			0,				0	},
		{	_INDEX_HEADERHEIGHT,			0,				0	},
		{	_INDEX_HEIGHT,					0,				0	},
		{	_INDEX_HELPCONTEXTID,			0,				0	},
		{	_INDEX_LEFT,					0,				0	},
		{	_INDEX_MOUSEICON,				0,				0	},
		{	_INDEX_MOUSEPOINTER,			0,				0	},
		{	_INDEX_NAME,					0,				0	},
		{	_INDEX_OLEDRAGMODE,				0,				0	},
		{	_INDEX_OLEDRAGPICTURE,			0,				0	},
		{	_INDEX_OLEDROPEFFECTS,			0,				0	},
		{	_INDEX_OLEDROPHASDATA,			0,				0	},
		{	_INDEX_OLEDROPMODE,				0,				0	},
		{	_INDEX_PARENT,					0,				0	},
		{	_INDEX_PARENTCLASS,				0,				0	},
		{	_INDEX_READONLY,				0,				0	},
		{	_INDEX_RELATIONALEXPR,			0,				0	},
		{	_INDEX_RIGHTTOLEFT,				0,				0	},
		{	_INDEX_ROWCOLCHANGE,			0,				0	},
		{	_INDEX_ROWHEIGHT,				0,				0	},
		{	_INDEX_SCROLLBARS,				0,				0	},
		{	_INDEX_SELECTEDITEMBACKCOLOR,	0,				0	},
		{	_INDEX_SELECTEDITEMFORECOLOR,	0,				0	},
		{	_INDEX_STATUSBARTEXT,			0,				0	},
		{	_INDEX_TABINDEX,				0,				0	},
		{	_INDEX_TABSTOP,					0,				0	},
		{	_INDEX_TAG,						0,				0	},
		{	_INDEX_THEMES,					0,				0	},
		{	_INDEX_TOOLTIPTEXT,				0,				0	},
		{	_INDEX_TOP,						0,				0	},
		{	_INDEX_VALUE,					0,				0	},
		{	_INDEX_VISIBLE,					0,				0	},
		{	_INDEX_WHATSTHISHELPID,			0,				0	},
		{	_INDEX_WIDTH,					0,				0	},
		{	0,								0,				0	},
	};
	const u32 gnProps_gridSize = sizeof(gsProps_grid) / sizeof(SPropertyMap) - 1;

	SPropertyMap gsProps_column[] =
	{
		{	_INDEX_CURRENTCONTROL,			0,				0	},
		{	_INDEX_DYNAMICALIGNMENT,		0,				0	},
		{	_INDEX_DYNAMICBACKCOLOR,		0,				0	},
		{	_INDEX_DYNAMICCURRENTCONTROL,	0,				0	},
		{	_INDEX_DYNAMICFONTBOLD,			0,				0	},
		{	_INDEX_DYNAMICFONTITALIC,		0,				0	},
		{	_INDEX_DYNAMICFONTNAME,			0,				0	},
		{	_INDEX_DYNAMICFONTOUTLINE,		0,				0	},
		{	_INDEX_DYNAMICFONTSHADOW,		0,				0	},
		{	_INDEX_DYNAMICFONTSIZE,			0,				0	},
		{	_INDEX_DYNAMICFONTSTRIKETHRU,	0,				0	},
		{	_INDEX_DYNAMICFONTUNDERLINE,	0,				0	},
		{	_INDEX_DYNAMICFORECOLOR,		0,				0	},
		{	_INDEX_DYNAMICINPUTMASK,		0,				0	},
		{	_INDEX_SPARSE,					0,				0	},
		{	_INDEX_COLUMNORDER,				0,				0	},
		{	_INDEX_HEADERCLASS,				0,				0	},
		{	_INDEX_HEADERCLASSLIBRARY,		0,				0	},
		{	_INDEX_MOVABLE,					0,				0	},
		{	_INDEX_ALIGNMENT,				0,				0	},
		{	_INDEX_APPLICATION,				0,				0	},
		{	_INDEX_BASECLASS,				0,				0	},
		{	_INDEX_CLASS,					0,				0	},
		{	_INDEX_CLASSLIBRARY,			0,				0	},
		{	_INDEX_CONTROLS,				0,				0	},
		{	_INDEX_CONTROLCOUNT,			0,				0	},
		{	_INDEX_OBJECTS,					0,				0	},
		{	_INDEX_BOUND,					0,				0	},
		{	_INDEX_FORECOLOR,				0,				0	},
		{	_INDEX_BACKCOLOR,				0,				0	},
		{	_INDEX_COMMENT,					0,				0	},
		{	_INDEX_CONTROLSOURCE,			0,				0	},
		{	_INDEX_ENABLED,					0,				0	},
		{	_INDEX_FONTBOLD,				0,				0	},
		{	_INDEX_FONTCHARSET,				0,				0	},
		{	_INDEX_FONTCONDENSE,			0,				0	},
		{	_INDEX_FONTEXTEND,				0,				0	},
		{	_INDEX_FONTITALIC,				0,				0	},
		{	_INDEX_FONTNAME,				0,				0	},
		{	_INDEX_FONTOUTLINE,				0,				0	},
		{	_INDEX_FONTSHADOW,				0,				0	},
		{	_INDEX_FONTSIZE,				0,				0	},
		{	_INDEX_FONTSTRIKETHRU,			0,				0	},
		{	_INDEX_FONTUNDERLINE,			0,				0	},
		{	_INDEX_FORMAT,					0,				0	},
		{	_INDEX_INPUTMASK,				0,				0	},
		{	_INDEX_MOUSEICON,				0,				0	},
		{	_INDEX_MOUSEPOINTER,			0,				0	},
		{	_INDEX_NAME,					0,				0	},
		{	_INDEX_PARENT,					0,				0	},
		{	_INDEX_PARENTCLASS,				0,				0	},
		{	_INDEX_READONLY,				0,				0	},
		{	_INDEX_SELECTONENTRY,			0,				0	},
		{	_INDEX_RESIZABLE,				0,				0	},
		{	_INDEX_STATUSBARTEXT,			0,				0	},
		{	_INDEX_TAG,						0,				0	},
		{	_INDEX_TOOLTIPTEXT,				0,				0	},
		{	_INDEX_VISIBLE,					0,				0	},
		{	_INDEX_WIDTH,					0,				0	},
		{	0,								0,				0	},
	};
	const u32 gnProps_columnSize = sizeof(gsProps_column) / sizeof(SPropertyMap) - 1;

	SPropertyMap gsProps_header[] =
	{
		{	_INDEX_ALIGNMENT,				0,				0	},
		{	_INDEX_ANCHOR,					0,				0	},
		{	_INDEX_APPLICATION,				0,				0	},
		{	_INDEX_BASECLASS,				0,				0	},
		{	_INDEX_CLASS,					0,				0	},
		{	_INDEX_CLASSLIBRARY,			0,				0	},
		{	_INDEX_CAPTION,					0,				0	},
		{	_INDEX_FORECOLOR,				0,				0	},
		{	_INDEX_BACKCOLOR,				0,				0	},
		{	_INDEX_COMMENT,					0,				0	},
		{	_INDEX_FONTBOLD,				0,				0	},
		{	_INDEX_FONTCHARSET,				0,				0	},
		{	_INDEX_FONTCONDENSE,			0,				0	},
		{	_INDEX_FONTEXTEND,				0,				0	},
		{	_INDEX_FONTITALIC,				0,				0	},
		{	_INDEX_FONTNAME,				0,				0	},
		{	_INDEX_FONTOUTLINE,				0,				0	},
		{	_INDEX_FONTSHADOW,				0,				0	},
		{	_INDEX_FONTSIZE,				0,				0	},
		{	_INDEX_FONTSTRIKETHRU,			0,				0	},
		{	_INDEX_FONTUNDERLINE,			0,				0	},
		{	_INDEX_MOUSEICON,				0,				0	},
		{	_INDEX_MOUSEPOINTER,			0,				0	},
		{	_INDEX_NAME,					0,				0	},
		{	_INDEX_PARENT,					0,				0	},
		{	_INDEX_PARENTCLASS,				0,				0	},
		{	_INDEX_PICTURE,					0,				0	},
		{	_INDEX_STATUSBARTEXT,			0,				0	},
		{	_INDEX_TAG,						0,				0	},
		{	_INDEX_TOOLTIPTEXT,				0,				0	},
		{	_INDEX_WORDWRAP,				0,				0	},
		{	0,								0,				0	},
	};
	const u32 gnProps_headerSize = sizeof(gsProps_header) / sizeof(SPropertyMap) - 1;

	SPropertyMap gsProps_olebound[] =
	{
		{	_INDEX_AUTOACTIVATE,			0,				0	},
		{	_INDEX_AUTOSIZE,				0,				0	},
		{	_INDEX_AUTOVERBMENU,			0,				0	},
		{	_INDEX_DOCUMENTFILE,			0,				0	},
		{	_INDEX_HOSTNAME,				0,				0	},
		{	_INDEX_OBJECT,					0,				0	},
		{	_INDEX_ANCHOR,					0,				0	},
		{	_INDEX_APPLICATION,				0,				0	},
		{	_INDEX_BASECLASS,				0,				0	},
		{	_INDEX_CLASS,					0,				0	},
		{	_INDEX_CLASSLIBRARY,			0,				0	},
		{	_INDEX_COMMENT,					0,				0	},
		{	_INDEX_CONTROLSOURCE,			0,				0	},
		{	_INDEX_DRAGICON,				0,				0	},
		{	_INDEX_DRAGMODE,				0,				0	},
		{	_INDEX_ENABLED,					0,				0	},
		{	_INDEX_HEIGHT,					0,				0	},
		{	_INDEX_HELPCONTEXTID,			0,				0	},
		{	_INDEX_LEFT,					0,				0	},
		{	_INDEX_MOUSEPOINTER,			0,				0	},
		{	_INDEX_NAME,					0,				0	},
		{	_INDEX_OLECLASS,				0,				0	},
		{	_INDEX_OLELCID,					0,				0	},
		{	_INDEX_OLETYPEALLOWED,			0,				0	},
		{	_INDEX_PARENTCLASS,				0,				0	},
		{	_INDEX_SIZABLE,					0,				0	},
		{	_INDEX_STRETCH,					0,				0	},
		{	_INDEX_STATUSBARTEXT,			0,				0	},
		{	_INDEX_TABINDEX,				0,				0	},
		{	_INDEX_TABSTOP,					0,				0	},
		{	_INDEX_TAG,						0,				0	},
		{	_INDEX_TOOLTIPTEXT,				0,				0	},
		{	_INDEX_TOP,						0,				0	},
		{	_INDEX_VISIBLE,					0,				0	},
		{	_INDEX_WHATSTHISHELPID,			0,				0	},
		{	_INDEX_WIDTH,					0,				0	},
		{	_INDEX_WORDWRAP,				0,				0	},
		{	0,								0,				0	},
	};
	const u32 gnProps_oleboundSize = sizeof(gsProps_olebound) / sizeof(SPropertyMap) - 1;

	SPropertyMap gsProps_olecontain[] =
	{
		{	_INDEX_AUTOACTIVATE,			0,				0	},
		{	_INDEX_AUTOSIZE,				0,				0	},
		{	_INDEX_AUTOVERBMENU,			0,				0	},
		{	_INDEX_DOCUMENTFILE,			0,				0	},
		{	_INDEX_HOSTNAME,				0,				0	},
		{	_INDEX_OBJECT,					0,				0	},
		{	_INDEX_ALIGN,					0,				0	},
		{	_INDEX_ANCHOR,					0,				0	},
		{	_INDEX_APPLICATION,				0,				0	},
		{	_INDEX_BASECLASS,				0,				0	},
		{	_INDEX_CLASS,					0,				0	},
		{	_INDEX_CLASSLIBRARY,			0,				0	},
		{	_INDEX_CANCEL,					0,				0	},
		{	_INDEX_DEFAULT,					0,				0	},
		{	_INDEX_COMMENT,					0,				0	},
		{	_INDEX_CONTROLSOURCE,			0,				0	},
		{	_INDEX_DRAGICON,				0,				0	},
		{	_INDEX_DRAGMODE,				0,				0	},
		{	_INDEX_ENABLED,					0,				0	},
		{	_INDEX_HEIGHT,					0,				0	},
		{	_INDEX_HELPCONTEXTID,			0,				0	},
		{	_INDEX_LEFT,					0,				0	},
		{	_INDEX_MOUSEICON,				0,				0	},
		{	_INDEX_MOUSEPOINTER,			0,				0	},
		{	_INDEX_NAME,					0,				0	},
		{	_INDEX_OLECLASS,				0,				0	},
		{	_INDEX_OLELCID,					0,				0	},
		{	_INDEX_OLETYPEALLOWED,			0,				0	},
		{	_INDEX_PARENT,					0,				0	},
		{	_INDEX_PARENTCLASS,				0,				0	},
		{	_INDEX_SIZABLE,					0,				0	},
		{	_INDEX_STRETCH,					0,				0	},
		{	_INDEX_TABINDEX,				0,				0	},
		{	_INDEX_TABSTOP,					0,				0	},
		{	_INDEX_TAG,						0,				0	},
		{	_INDEX_TOP,						0,				0	},
		{	_INDEX_VISIBLE,					0,				0	},
		{	_INDEX_WHATSTHISHELPID,			0,				0	},
		{	_INDEX_WIDTH,					0,				0	},
		{	0,								0,				0	},
	};
	const u32 gnProps_olecontainSize = sizeof(gsProps_olecontain) / sizeof(SPropertyMap) - 1;

	SPropertyMap gsProps_spinner[] =
	{
		{	_INDEX_SPINNERHIGHVALUE,		0,				0	},
		{	_INDEX_SPINNERLOWVALUE,			0,				0	},
		{	_INDEX_KEYBOARDHIGHVALUE,		0,				0	},
		{	_INDEX_KEYBOARDLOWVALUE,		0,				0	},
		{	_INDEX_INCREMENT,				0,				0	},
		{	_INDEX_ALIGNMENT,				0,				0	},
		{	_INDEX_ANCHOR,					0,				0	},
		{	_INDEX_APPLICATION,				0,				0	},
		{	_INDEX_BASECLASS,				0,				0	},
		{	_INDEX_CLASS,					0,				0	},
		{	_INDEX_CLASSLIBRARY,			0,				0	},
		{	_INDEX_BORDERCOLOR,				0,				0	},
		{	_INDEX_BORDERSTYLE,				0,				0	},
		{	_INDEX_COLORSCHEME,				0,				0	},
		{	_INDEX_COLORSOURCE,				0,				0	},
		{	_INDEX_FORECOLOR,				0,				0	},
		{	_INDEX_BACKCOLOR,				0,				0	},
		{	_INDEX_DISABLEDBACKCOLOR,		0,				0	},
		{	_INDEX_DISABLEDFORECOLOR,		0,				0	},
		{	_INDEX_COMMENT,					0,				0	},
		{	_INDEX_CONTROLSOURCE,			0,				0	},
		{	_INDEX_DRAGICON,				0,				0	},
		{	_INDEX_DRAGMODE,				0,				0	},
		{	_INDEX_ENABLED,					0,				0	},
		{	_INDEX_FONTBOLD,				0,				0	},
		{	_INDEX_FONTCHARSET,				0,				0	},
		{	_INDEX_FONTCONDENSE,			0,				0	},
		{	_INDEX_FONTEXTEND,				0,				0	},
		{	_INDEX_FONTITALIC,				0,				0	},
		{	_INDEX_FONTNAME,				0,				0	},
		{	_INDEX_FONTOUTLINE,				0,				0	},
		{	_INDEX_FONTSHADOW,				0,				0	},
		{	_INDEX_FONTSIZE,				0,				0	},
		{	_INDEX_FONTSTRIKETHRU,			0,				0	},
		{	_INDEX_FONTUNDERLINE,			0,				0	},
		{	_INDEX_FORMAT,					0,				0	},
		{	_INDEX_HEIGHT,					0,				0	},
		{	_INDEX_HELPCONTEXTID,			0,				0	},
		{	_INDEX_HIDESELECTION,			0,				0	},
		{	_INDEX_INPUTMASK,				0,				0	},
		{	_INDEX_LEFT,					0,				0	},
		{	_INDEX_MARGIN,					0,				0	},
		{	_INDEX_MOUSEICON,				0,				0	},
		{	_INDEX_MOUSEPOINTER,			0,				0	},
		{	_INDEX_NAME,					0,				0	},
		{	_INDEX_NULLDISPLAY,				0,				0	},
		{	_INDEX_OLEDRAGMODE,				0,				0	},
		{	_INDEX_OLEDRAGPICTURE,			0,				0	},
		{	_INDEX_OLEDROPEFFECTS,			0,				0	},
		{	_INDEX_OLEDROPHASDATA,			0,				0	},
		{	_INDEX_OLEDROPMODE,				0,				0	},
		{	_INDEX_OLEDROPTEXTINSERTION,	0,				0	},
		{	_INDEX_PARENT,					0,				0	},
		{	_INDEX_PARENTCLASS,				0,				0	},
		{	_INDEX_READONLY,				0,				0	},
		{	_INDEX_RIGHTTOLEFT,				0,				0	},
		{	_INDEX_SELECTEDBACKCOLOR,		0,				0	},
		{	_INDEX_SELECTEDFORECOLOR,		0,				0	},
		{	_INDEX_SELECTONENTRY,			0,				0	},
		{	_INDEX_SELLENGTH,				0,				0	},
		{	_INDEX_SELSTART,				0,				0	},
		{	_INDEX_SELTEXT,					0,				0	},
		{	_INDEX_SPECIALEFFECT,			0,				0	},
		{	_INDEX_STATUSBARTEXT,			0,				0	},
		{	_INDEX_TABINDEX,				0,				0	},
		{	_INDEX_TABSTOP,					0,				0	},
		{	_INDEX_TAG,						0,				0	},
		{	_INDEX_TERMINATEREAD,			0,				0	},
		{	_INDEX_TEXT,					0,				0	},
		{	_INDEX_THEMES,					0,				0	},
		{	_INDEX_TOOLTIPTEXT,				0,				0	},
		{	_INDEX_TOP,						0,				0	},
		{	_INDEX_VALUE,					0,				0	},
		{	_INDEX_VISIBLE,					0,				0	},
		{	_INDEX_WHATSTHISHELPID,			0,				0	},
		{	_INDEX_WIDTH,					0,				0	},
		{	0,								0,				0	},
	};
	const u32 gnProps_spinnerSize = sizeof(gsProps_spinner) / sizeof(SPropertyMap) - 1;

	SPropertyMap gsProps_timer[] =
	{
		{	_INDEX_INTERVAL,				0,				0	},
		{	_INDEX_APPLICATION,				0,				0	},
		{	_INDEX_BASECLASS,				0,				0	},
		{	_INDEX_CLASS,					0,				0	},
		{	_INDEX_CLASSLIBRARY,			0,				0	},
		{	_INDEX_COMMENT,					0,				0	},
		{	_INDEX_ENABLED,					0,				0	},
		{	_INDEX_HEIGHT,					0,				0	},
		{	_INDEX_LEFT,					0,				0	},
		{	_INDEX_NAME,					0,				0	},
		{	_INDEX_PARENT,					0,				0	},
		{	_INDEX_PARENTCLASS,				0,				0	},
		{	_INDEX_TAG,						0,				0	},
		{	_INDEX_TOP,						0,				0	},
		{	_INDEX_WIDTH,					0,				0	},
		{	0,								0,				0	},
	};
	const u32 gnProps_timerSize = sizeof(gsProps_timer) / sizeof(SPropertyMap) - 1;

	SPropertyMap gsProps_hyperlink[] =
	{
		{	_INDEX_APPLICATION,				0,				0	},
		{	_INDEX_BASECLASS,				0,				0	},
		{	_INDEX_CLASS,					0,				0	},
		{	_INDEX_CLASSLIBRARY,			0,				0	},
		{	_INDEX_COMMENT,					0,				0	},
		{	_INDEX_NAME,					0,				0	},
		{	_INDEX_PARENT,					0,				0	},
		{	_INDEX_PARENTCLASS,				0,				0	},
		{	_INDEX_TAG,						0,				0	},
		{	0,								0,				0	},
	};
	const u32 gnProps_hyperlinkSize = sizeof(gsProps_hyperlink) / sizeof(SPropertyMap) - 1;

	SPropertyMap gsProps_collection[] =
	{
		{	_INDEX_KEYSORT,					0,				0	},
		{	_INDEX_BASECLASS,				0,				0	},
		{	_INDEX_CLASS,					0,				0	},
		{	_INDEX_CLASSLIBRARY,			0,				0	},
		{	_INDEX_COUNT,					0,				0	},
		{	_INDEX_COMMENT,					0,				0	},
		{	_INDEX_NAME,					0,				0	},
		{	_INDEX_PARENT,					0,				0	},
		{	_INDEX_PARENTCLASS,				0,				0	},
		{	_INDEX_TAG,						0,				0	},
		{	0,								0,				0	},
	};
	const u32 gnProps_collectionSize = sizeof(gsProps_collection) / sizeof(SPropertyMap) - 1;

	SPropertyMap gsProps_page[] =
	{
		{	_INDEX_ACTIVECONTROL,			0,				0	},
		{	_INDEX_PAGEORDER,				0,				0	},
		{	_INDEX_APPLICATION,				0,				0	},
		{	_INDEX_BACKSTYLE,				0,				0	},
		{	_INDEX_BASECLASS,				0,				0	},
		{	_INDEX_CLASS,					0,				0	},
		{	_INDEX_CLASSLIBRARY,			0,				0	},
		{	_INDEX_CONTROLS,				0,				0	},
		{	_INDEX_CONTROLCOUNT,			0,				0	},
		{	_INDEX_OBJECTS,					0,				0	},
		{	_INDEX_CAPTION,					0,				0	},
		{	_INDEX_COLORSOURCE,				0,				0	},
		{	_INDEX_FORECOLOR,				0,				0	},
		{	_INDEX_BACKCOLOR,				0,				0	},
		{	_INDEX_COMMENT,					0,				0	},
		{	_INDEX_DRAGICON,				0,				0	},
		{	_INDEX_DRAGMODE,				0,				0	},
		{	_INDEX_ENABLED,					0,				0	},
		{	_INDEX_FONTBOLD,				0,				0	},
		{	_INDEX_FONTCHARSET,				0,				0	},
		{	_INDEX_FONTCONDENSE,			0,				0	},
		{	_INDEX_FONTEXTEND,				0,				0	},
		{	_INDEX_FONTITALIC,				0,				0	},
		{	_INDEX_FONTNAME,				0,				0	},
		{	_INDEX_FONTOUTLINE,				0,				0	},
		{	_INDEX_FONTSHADOW,				0,				0	},
		{	_INDEX_FONTSIZE,				0,				0	},
		{	_INDEX_FONTSTRIKETHRU,			0,				0	},
		{	_INDEX_FONTUNDERLINE,			0,				0	},
		{	_INDEX_HELPCONTEXTID,			0,				0	},
		{	_INDEX_MOUSEICON,				0,				0	},
		{	_INDEX_MOUSEPOINTER,			0,				0	},
		{	_INDEX_NAME,					0,				0	},
		{	_INDEX_OLEDRAGMODE,				0,				0	},
		{	_INDEX_OLEDRAGPICTURE,			0,				0	},
		{	_INDEX_OLEDROPEFFECTS,			0,				0	},
		{	_INDEX_OLEDROPHASDATA,			0,				0	},
		{	_INDEX_OLEDROPMODE,				0,				0	},
		{	_INDEX_PARENT,					0,				0	},
		{	_INDEX_PARENTCLASS,				0,				0	},
		{	_INDEX_PICTURE,					0,				0	},
		{	_INDEX_TAG,						0,				0	},
		{	_INDEX_TOOLTIPTEXT,				0,				0	},
		{	_INDEX_WHATSTHISHELPID,			0,				0	},
		{	0,								0,				0	},
	};
	const u32 gnProps_pageSize = sizeof(gsProps_page) / sizeof(SPropertyMap) - 1;

	SPropertyMap gsProps_pageframe[] =
	{
		{	_INDEX_ACTIVEPAGE,				0,				0	},
		{	_INDEX_TABORIENTATION,			0,				0	},
		{	_INDEX_TABS,					0,				0	},
		{	_INDEX_PAGEHEIGHT,				0,				0	},
		{	_INDEX_PAGEWIDTH,				0,				0	},
		{	_INDEX_ANCHOR,					0,				0	},
		{	_INDEX_APPLICATION,				0,				0	},
		{	_INDEX_BASECLASS,				0,				0	},
		{	_INDEX_CLASS,					0,				0	},
		{	_INDEX_CLASSLIBRARY,			0,				0	},
		{	_INDEX_PAGES,					0,				0	},
		{	_INDEX_PAGECOUNT,				0,				0	},
		{	_INDEX_OBJECTS,					0,				0	},
		{	_INDEX_BORDERCOLOR,				0,				0	},
		{	_INDEX_BORDERWIDTH,				0,				0	},
		{	_INDEX_COLORSOURCE,				0,				0	},
		{	_INDEX_COMMENT,					0,				0	},
		{	_INDEX_DRAGICON,				0,				0	},
		{	_INDEX_DRAGMODE,				0,				0	},
		{	_INDEX_ENABLED,					0,				0	},
		{	_INDEX_HEIGHT,					0,				0	},
		{	_INDEX_HELPCONTEXTID,			0,				0	},
		{	_INDEX_LEFT,					0,				0	},
		{	_INDEX_MEMBERCLASS,				0,				0	},
		{	_INDEX_MEMBERCLASSLIBRARY,		0,				0	},
		{	_INDEX_MOUSEICON,				0,				0	},
		{	_INDEX_MOUSEPOINTER,			0,				0	},
		{	_INDEX_NAME,					0,				0	},
		{	_INDEX_OLEDRAGMODE,				0,				0	},
		{	_INDEX_OLEDRAGPICTURE,			0,				0	},
		{	_INDEX_OLEDROPEFFECTS,			0,				0	},
		{	_INDEX_OLEDROPHASDATA,			0,				0	},
		{	_INDEX_OLEDROPMODE,				0,				0	},
		{	_INDEX_PARENT,					0,				0	},
		{	_INDEX_PARENTCLASS,				0,				0	},
		{	_INDEX_RIGHTTOLEFT,				0,				0	},
		{	_INDEX_SPECIALEFFECT,			0,				0	},
		{	_INDEX_STATUSBARTEXT,			0,				0	},
		{	_INDEX_TABSTYLE,				0,				0	},
		{	_INDEX_TABINDEX,				0,				0	},
		{	_INDEX_TABSTOP,					0,				0	},
		{	_INDEX_TAG,						0,				0	},
		{	_INDEX_THEMES,					0,				0	},
		{	_INDEX_TOOLTIPTEXT,				0,				0	},
		{	_INDEX_TOP,						0,				0	},
		{	_INDEX_VISIBLE,					0,				0	},
		{	_INDEX_WHATSTHISHELPID,			0,				0	},
		{	_INDEX_WIDTH,					0,				0	},
		{	0,								0,				0	},
	};
	const u32 gnProps_pageframeSize = sizeof(gsProps_pageframe) / sizeof(SPropertyMap) - 1;

	SPropertyMap gsProps_session[] =
	{
		{	_INDEX_DATASESSION,				0,				0	},
		{	_INDEX_DATASESSIONID,			0,				0	},
		{	_INDEX_APPLICATION,				0,				0	},
		{	_INDEX_BASECLASS,				0,				0	},
		{	_INDEX_CLASS,					0,				0	},
		{	_INDEX_CLASSLIBRARY,			0,				0	},
		{	_INDEX_COMMENT,					0,				0	},
		{	_INDEX_NAME,					0,				0	},
		{	_INDEX_PARENT,					0,				0	},
		{	_INDEX_PARENTCLASS,				0,				0	},
		{	_INDEX_TAG,						0,				0	},
		{	0,								0,				0	},
	};
	const u32 gnProps_sessionSize = sizeof(gsProps_session) / sizeof(SPropertyMap) - 1;

	SPropertyMap gsProps_custom[] =
	{
		{	_INDEX_APPLICATION,				0,				0	},
		{	_INDEX_BASECLASS,				0,				0	},
		{	_INDEX_CLASS,					0,				0	},
		{	_INDEX_CLASSLIBRARY,			0,				0	},
		{	_INDEX_CONTROLS,				0,				0	},
		{	_INDEX_CONTROLCOUNT,			0,				0	},
		{	_INDEX_OBJECTS,					0,				0	},
		{	_INDEX_COMMENT,					0,				0	},
		{	_INDEX_HEIGHT,					0,				0	},
		{	_INDEX_HELPCONTEXTID,			0,				0	},
		{	_INDEX_LEFT,					0,				0	},
		{	_INDEX_NAME,					0,				0	},
		{	_INDEX_PARENT,					0,				0	},
		{	_INDEX_PARENTCLASS,				0,				0	},
		{	_INDEX_PICTURE,					0,				0	},
		{	_INDEX_TAG,						0,				0	},
		{	_INDEX_TOP,						0,				0	},
		{	_INDEX_WHATSTHISHELPID,			0,				0	},
		{	_INDEX_WIDTH,					0,				0	},
		{	0,								0,				0	},
	};
	const u32 gnProps_customSize = sizeof(gsProps_custom) / sizeof(SPropertyMap) - 1;

	SPropertyMap gsProps_exception[] =
	{
		{	_INDEX_DETAILS,					0,				0	},
		{	_INDEX_ERRORNO,					0,				0	},
		{	_INDEX_LINECONTENTS,			0,				0	},
		{	_INDEX_LINENO,					0,				0	},
		{	_INDEX_MESSAGE,					0,				0	},
		{	_INDEX_PROCEDURE,				0,				0	},
		{	_INDEX_STACKLEVEL,				0,				0	},
		{	_INDEX_USERVALUE,				0,				0	},
		{	_INDEX_BASECLASS,				0,				0	},
		{	_INDEX_CLASS,					0,				0	},
		{	_INDEX_CLASSLIBRARY,			0,				0	},
		{	_INDEX_COMMENT,					0,				0	},
		{	_INDEX_NAME,					0,				0	},
		{	_INDEX_PARENT,					0,				0	},
		{	_INDEX_PARENTCLASS,				0,				0	},
		{	_INDEX_TAG,						0,				0	},
		{	0,								0,				0	},
	};
	const u32 gnProps_exceptionSize = sizeof(gsProps_exception) / sizeof(SPropertyMap) - 1;




//////////
// Baseclass translation text name to objType, and objType to full record
//////
	SBaseclassList gsKnownBaseclasses[] = {
		//	objType					Text name				Length of name						Base object property list
		//	------------------		-----------------		-------------------------------		-------------------------------
		{	_OBJ_TYPE_EMPTY,		cgcName_empty,			sizeof(cgcName_empty)		- 1,	(u32)&gsProps_empty[0]			},
		{	_OBJ_TYPE_SUBFORM,		cgcName_subform,		sizeof(cgcName_subform)		- 1,	(u32)&gsProps_subform[0]		},
		{	_OBJ_TYPE_BUTTON,		cgcName_button,			sizeof(cgcName_button)		- 1,	(u32)&gsProps_button[0]			},
		{	_OBJ_TYPE_RADIO,		cgcName_radio,			sizeof(cgcName_radio)		- 1,	(u32)&gsProps_radio[0]			},
		{	_OBJ_TYPE_CHECKBOX,		cgcName_checkbox,		sizeof(cgcName_checkbox)	- 1,	(u32)&gsProps_checkbox[0]		},
		{	_OBJ_TYPE_CMDGROUP,		cgcName_cmdgroup,		sizeof(cgcName_cmdgroup)	- 1,	(u32)&gsProps_cmdgroup[0]		},
		{	_OBJ_TYPE_LABEL,		cgcName_label,			sizeof(cgcName_label)		- 1,	(u32)&gsProps_label[0]			},
		{	_OBJ_TYPE_OPTION,		cgcName_option,			sizeof(cgcName_option)		- 1,	(u32)&gsProps_option[0]			},
		{	_OBJ_TYPE_OPTGROUP,		cgcName_optgroup,		sizeof(cgcName_optgroup)	- 1,	(u32)&gsProps_optgroup[0]		},
		{	_OBJ_TYPE_TEXTBOX,		cgcName_textbox,		sizeof(cgcName_textbox)		- 1,	(u32)&gsProps_textbox[0]		},
		{	_OBJ_TYPE_LISTBOX,		cgcName_listbox,		sizeof(cgcName_listbox)		- 1,	(u32)&gsProps_listbox[0]		},
		{	_OBJ_TYPE_COMBOBOX,		cgcName_combobox,		sizeof(cgcName_combobox)	- 1,	(u32)&gsProps_combobox[0]		},
		{	_OBJ_TYPE_FORM,			cgcName_form,			sizeof(cgcName_form)		- 1,	(u32)&gsProps_form[0]			},
		{	_OBJ_TYPE_FORMSET,		cgcName_formset,		sizeof(cgcName_formset)		- 1,	(u32)&gsProps_formset[0]		},
		{	_OBJ_TYPE_TOOLBAR,		cgcName_toolbar,		sizeof(cgcName_toolbar)		- 1,	(u32)&gsProps_toolbar[0]		},
		{	_OBJ_TYPE_SEPARATOR,	cgcName_separator,		sizeof(cgcName_separator)	- 1,	(u32)&gsProps_separator[0]		},
		{	_OBJ_TYPE_LINE,			cgcName_line,			sizeof(cgcName_line)		- 1,	(u32)&gsProps_line[0]			},
		{	_OBJ_TYPE_SHAPE,		cgcName_shape,			sizeof(cgcName_shape)		- 1,	(u32)&gsProps_shape[0]			},
		{	_OBJ_TYPE_IMAGE,		cgcName_image,			sizeof(cgcName_image)		- 1,	(u32)&gsProps_image[0]			},
		{	_OBJ_TYPE_CONTAINER,	cgcName_container,		sizeof(cgcName_container)	- 1,	(u32)&gsProps_container[0]		},
		{	_OBJ_TYPE_CONTROL,		cgcName_control,		sizeof(cgcName_control)		- 1,	(u32)&gsProps_control[0]		},
		{	_OBJ_TYPE_GRID,			cgcName_grid,			sizeof(cgcName_grid)		- 1,	(u32)&gsProps_grid[0]			},
		{	_OBJ_TYPE_COLUMN,		cgcName_column,			sizeof(cgcName_column)		- 1,	(u32)&gsProps_column[0]			},
		{	_OBJ_TYPE_HEADER,		cgcName_header,			sizeof(cgcName_header)		- 1,	(u32)&gsProps_header[0]			},
		{	_OBJ_TYPE_OLEBOUND,		cgcName_olebound,		sizeof(cgcName_olebound)	- 1,	(u32)&gsProps_olebound[0]		},
		{	_OBJ_TYPE_OLECONTAIN,	cgcName_olecontain,		sizeof(cgcName_olecontain)	- 1,	(u32)&gsProps_olecontain[0]		},
		{	_OBJ_TYPE_SPINNER,		cgcName_spinner,		sizeof(cgcName_spinner)		- 1,	(u32)&gsProps_spinner[0]		},
		{	_OBJ_TYPE_TIMER,		cgcName_timer,			sizeof(cgcName_timer)		- 1,	(u32)&gsProps_timer[0]			},
		{	_OBJ_TYPE_HYPERLINK,	cgcName_hyperlink,		sizeof(cgcName_hyperlink)	- 1,	(u32)&gsProps_hyperlink[0]		},
		{	_OBJ_TYPE_COLLECTION,	cgcName_collection,		sizeof(cgcName_collection)	- 1,	(u32)&gsProps_collection[0]		},
		{	_OBJ_TYPE_PAGE,			cgcName_page,			sizeof(cgcName_page)		- 1,	(u32)&gsProps_page[0]			},
		{	_OBJ_TYPE_PAGEFRAME,	cgcName_pageframe,		sizeof(cgcName_pageframe)	- 1,	(u32)&gsProps_pageframe[0]		},
		{	_OBJ_TYPE_SESSION,		cgcName_session,		sizeof(cgcName_session)		- 1,	(u32)&gsProps_session[0]		},
		{	_OBJ_TYPE_CUSTOM,		cgcName_custom,			sizeof(cgcName_custom)		- 1,	(u32)&gsProps_custom[0]			},
		{	_OBJ_TYPE_EXCEPTION,	cgcName_exception,		sizeof(cgcName_exception)	- 1,	(u32)&gsProps_exception[0]		},
		// Note:  Do not delete this line, it is used to terminate the search list
		{	0,						NULL,					0,									0	}
	};

