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
	const s8			cgc_activeColumn[]							   = "activeColumn";
	const s8			cgc_activeControl[]							   = "activeControl";
	const s8			cgc_activeForm[]							   = "activeForm";
	const s8			cgc_activePage[]							   = "activePage";
	const s8			cgc_activeRow[]								   = "activeRow";
	const s8			cgc_addLineFeeds[]							   = "addLineFeeds";
	const s8			cgc_align[]									   = "align";
	const s8			cgc_alignment[]								   = "alignment";
	const s8			cgc_allowAddNew[]							   = "allowAddNew";
	const s8			cgc_allowAutoColumnFit[]					   = "allowAutoColumnFit";
	const s8			cgc_allowCellSelection[]					   = "allowCellSelection";
	const s8			cgc_allowHeaderSizing[]						   = "allowHeaderSizing";
	const s8			cgc_allowOutput[]							   = "allowOutput";
	const s8			cgc_allowRowSizing[]						   = "allowRowSizing";
	const s8			cgc_allowTabs[]								   = "allowTabs";
	const s8			cgc_alwaysOnBottom[]						   = "alwaysOnBottom";
	const s8			cgc_alwaysOnTop[]							   = "alwaysOnTop";
	const s8			cgc_anchor[]								   = "anchor";
	const s8			cgc_application[]							   = "application";
	const s8			cgc_autoActivate[]							   = "autoActivate";
	const s8			cgc_autoCenter[]							   = "autoCenter";
	const s8			cgc_autoCompSource[]						   = "autoCompSource";
	const s8			cgc_autoCompTable[]							   = "autoCompTable";
	const s8			cgc_autoComplete[]							   = "autoComplete";
	const s8			cgc_autoHideScrollBar[]						   = "autoHideScrollBar";
	const s8			cgc_autoRelease[]							   = "autoRelease";
	const s8			cgc_autoSize[]								   = "autoSize";
	const s8			cgc_autoVerbMenu[]							   = "autoVerbMenu";
	const s8			cgc_backColor[]								   = "backColor";
	const s8			cgc_backStyle[]								   = "backStyle";
	const s8			cgc_baseClass[]								   = "baseClass";
	const s8			cgc_bindControls[]							   = "bindControls";
	const s8			cgc_borderColor[]							   = "borderColor";
	const s8			cgc_borderStyle[]							   = "borderStyle";
	const s8			cgc_borderWidth[]							   = "borderWidth";
	const s8			cgc_bound[]									   = "bound";
	const s8			cgc_boundColumn[]							   = "boundColumn";
	const s8			cgc_boundTo[]								   = "boundTo";
	const s8			cgc_bufferMode[]							   = "bufferMode";
	const s8			cgc_buttonCount[]							   = "buttonCount";
	const s8			cgc_cancel[]								   = "cancel";
	const s8			cgc_caption[]								   = "caption";
	const s8			cgc_centered[]								   = "centered";
	const s8			cgc_century[]								   = "century";
	const s8			cgc_childOrder[]							   = "childOrder";
	const s8			cgc_class[]									   = "class";
	const s8			cgc_classLibrary[]							   = "classLibrary";
	const s8			cgc_clipControls[]							   = "clipControls";
	const s8			cgc_closable[]								   = "closable";
	const s8			cgc_colorScheme[]							   = "colorScheme";
	const s8			cgc_colorSource[]							   = "colorSource";
	const s8			cgc_columnCount[]							   = "columnCount";
	const s8			cgc_columnLines[]							   = "columnLines";
	const s8			cgc_columnOrder[]							   = "columnOrder";
	const s8			cgc_columnWidths[]							   = "columnWidths";
	const s8			cgc_columns[]								   = "columns";
	const s8			cgc_comment[]								   = "comment";
	const s8			cgc_continuousScroll[]						   = "continuousScroll";
	const s8			cgc_controlBox[]							   = "controlBox";
	const s8			cgc_controlCount[]							   = "controlCount";
	const s8			cgc_controlSource[]							   = "controlSource";
	const s8			cgc_controls[]								   = "controls";
	const s8			cgc_count[]									   = "count";
	const s8			cgc_currentControl[]						   = "currentControl";
	const s8			cgc_currentX[]								   = "currentX";
	const s8			cgc_currentY[]								   = "currentY";
	const s8			cgc_curvature[]								   = "curvature";
	const s8			cgc_dEClass[]								   = "dEClass";
	const s8			cgc_dEClassLibrary[]						   = "dEClassLibrary";
	const s8			cgc_dataEnvironment[]						   = "dataEnvironment";
	const s8			cgc_dataSession[]							   = "dataSession";
	const s8			cgc_dataSessionID[]							   = "dataSessionID";
	const s8			cgc_dateFormat[]							   = "dateFormat";
	const s8			cgc_dateMark[]								   = "dateMark";
	const s8			cgc_defOLELCID[]							   = "defOLELCID";
	const s8			cgc_default[]								   = "default";
	const s8			cgc_deleteMark[]							   = "deleteMark";
	const s8			cgc_desktop[]								   = "desktop";
	const s8			cgc_details[]								   = "details";
	const s8			cgc_disabledBackColor[]						   = "disabledBackColor";
	const s8			cgc_disabledForeColor[]						   = "disabledForeColor";
	const s8			cgc_disabledItemBackColor[]					   = "disabledItemBackColor";
	const s8			cgc_disabledItemForeColor[]					   = "disabledItemForeColor";
	const s8			cgc_disabledPicture[]						   = "disabledPicture";
	const s8			cgc_displayCount[]							   = "displayCount";
	const s8			cgc_displayValue[]							   = "displayValue";
	const s8			cgc_doCreate[]								   = "doCreate";
	const s8			cgc_dockPosition[]							   = "dockPosition";
	const s8			cgc_dockable[]								   = "dockable";
	const s8			cgc_docked[]								   = "docked";
	const s8			cgc_documentFile[]							   = "documentFile";
	const s8			cgc_downPicture[]							   = "downPicture";
	const s8			cgc_dragIcon[]								   = "dragIcon";
	const s8			cgc_dragMode[]								   = "dragMode";
	const s8			cgc_drawMode[]								   = "drawMode";
	const s8			cgc_drawStyle[]								   = "drawStyle";
	const s8			cgc_drawWidth[]								   = "drawWidth";
	const s8			cgc_dynamicAlignment[]						   = "dynamicAlignment";
	const s8			cgc_dynamicBackColor[]						   = "dynamicBackColor";
	const s8			cgc_dynamicCurrentControl[]					   = "dynamicCurrentControl";
	const s8			cgc_dynamicFontBold[]						   = "dynamicFontBold";
	const s8			cgc_dynamicFontItalic[]						   = "dynamicFontItalic";
	const s8			cgc_dynamicFontName[]						   = "dynamicFontName";
	const s8			cgc_dynamicFontOutline[]					   = "dynamicFontOutline";
	const s8			cgc_dynamicFontShadow[]						   = "dynamicFontShadow";
	const s8			cgc_dynamicFontSize[]						   = "dynamicFontSize";
	const s8			cgc_dynamicFontStrikeThru[]					   = "dynamicFontStrikeThru";
	const s8			cgc_dynamicFontUnderline[]					   = "dynamicFontUnderline";
	const s8			cgc_dynamicForeColor[]						   = "dynamicForeColor";
	const s8			cgc_dynamicInputMask[]						   = "dynamicInputMask";
	const s8			cgc_enableHyperlinks[]						   = "enableHyperlinks";
	const s8			cgc_enabled[]								   = "enabled";
	const s8			cgc_errorNo[]								   = "errorNo";
	const s8			cgc_fillColor[]								   = "fillColor";
	const s8			cgc_fillStyle[]								   = "fillStyle";
	const s8			cgc_firstElement[]							   = "firstElement";
	const s8			cgc_fontBold[]								   = "fontBold";
	const s8			cgc_fontCharSet[]							   = "fontCharSet";
	const s8			cgc_fontCondense[]							   = "fontCondense";
	const s8			cgc_fontExtend[]							   = "fontExtend";
	const s8			cgc_fontItalic[]							   = "fontItalic";
	const s8			cgc_fontName[]								   = "fontName";
	const s8			cgc_fontOutline[]							   = "fontOutline";
	const s8			cgc_fontShadow[]							   = "fontShadow";
	const s8			cgc_fontSize[]								   = "fontSize";
	const s8			cgc_fontStrikeThru[]						   = "fontStrikeThru";
	const s8			cgc_fontUnderLine[]							   = "fontUnderLine";
	const s8			cgc_fontUnderline[]							   = "fontUnderline";
	const s8			cgc_foreColor[]								   = "foreColor";
	const s8			cgc_formCount[]								   = "formCount";
	const s8			cgc_format[]								   = "format";
	const s8			cgc_forms[]									   = "forms";
	const s8			cgc_gridLineColor[]							   = "gridLineColor";
	const s8			cgc_gridLineWidth[]							   = "gridLineWidth";
	const s8			cgc_gridLines[]								   = "gridLines";
	const s8			cgc_hScrollSmallChange[]					   = "hScrollSmallChange";
	const s8			cgc_hWnd[]									   = "hWnd";
	const s8			cgc_halfHeightCaption[]						   = "halfHeightCaption";
	const s8			cgc_headerClass[]							   = "headerClass";
	const s8			cgc_headerClassLibrary[]					   = "headerClassLibrary";
	const s8			cgc_headerHeight[]							   = "headerHeight";
	const s8			cgc_height[]								   = "height";
	const s8			cgc_helpContextID[]							   = "helpContextID";
	const s8			cgc_hideSelection[]							   = "hideSelection";
	const s8			cgc_highLight[]								   = "highLight";
	const s8			cgc_highLightRow[]							   = "highLightRow";
	const s8			cgc_highlightBackColor[]					   = "highlightBackColor";
	const s8			cgc_highlightForeColor[]					   = "highlightForeColor";
	const s8			cgc_highlightRowLineWidth[]					   = "highlightRowLineWidth";
	const s8			cgc_highlightStyle[]						   = "highlightStyle";
	const s8			cgc_hostName[]								   = "hostName";
	const s8			cgc_hours[]									   = "hours";
	const s8			cgc_iMEMode[]								   = "iMEMode";
	const s8			cgc_icon[]									   = "icon";
	const s8			cgc_increment[]								   = "increment";
	const s8			cgc_incrementalSearch[]						   = "incrementalSearch";
	const s8			cgc_inputMask[]								   = "inputMask";
	const s8			cgc_integralHeight[]						   = "integralHeight";
	const s8			cgc_interval[]								   = "interval";
	const s8			cgc_itemBackColor[]							   = "itemBackColor";
	const s8			cgc_itemData[]								   = "itemData";
	const s8			cgc_itemForeColor[]							   = "itemForeColor";
	const s8			cgc_itemIDData[]							   = "itemIDData";
	const s8			cgc_itemTips[]								   = "itemTips";
	const s8			cgc_keyPreview[]							   = "keyPreview";
	const s8			cgc_keySort[]								   = "keySort";
	const s8			cgc_keyboardHighValue[]						   = "keyboardHighValue";
	const s8			cgc_keyboardLowValue[]						   = "keyboardLowValue";
	const s8			cgc_left[]									   = "left";
	const s8			cgc_leftColumn[]							   = "leftColumn";
	const s8			cgc_lineContents[]							   = "lineContents";
	const s8			cgc_lineNo[]								   = "lineNo";
	const s8			cgc_lineSlant[]								   = "lineSlant";
	const s8			cgc_linkMaster[]							   = "linkMaster";
	const s8			cgc_list[]									   = "list";
	const s8			cgc_listCount[]								   = "listCount";
	const s8			cgc_listIndex[]								   = "listIndex";
	const s8			cgc_listItem[]								   = "listItem";
	const s8			cgc_listItemID[]							   = "listItemID";
	const s8			cgc_lockColumns[]							   = "lockColumns";
	const s8			cgc_lockColumnsLeft[]						   = "lockColumnsLeft";
	const s8			cgc_lockScreen[]							   = "lockScreen";
	const s8			cgc_mDIForm[]								   = "mDIForm";
	const s8			cgc_macDesktop[]							   = "macDesktop";
	const s8			cgc_margin[]								   = "margin";
	const s8			cgc_maxButton[]								   = "maxButton";
	const s8			cgc_maxHeight[]								   = "maxHeight";
	const s8			cgc_maxLeft[]								   = "maxLeft";
	const s8			cgc_maxLength[]								   = "maxLength";
	const s8			cgc_maxTop[]								   = "maxTop";
	const s8			cgc_maxWidth[]								   = "maxWidth";
	const s8			cgc_memberClass[]							   = "memberClass";
	const s8			cgc_memberClassLibrary[]					   = "memberClassLibrary";
	const s8			cgc_memoWindow[]							   = "memoWindow";
	const s8			cgc_message[]								   = "message";
	const s8			cgc_minButton[]								   = "minButton";
	const s8			cgc_minHeight[]								   = "minHeight";
	const s8			cgc_minWidth[]								   = "minWidth";
	const s8			cgc_mouseIcon[]								   = "mouseIcon";
	const s8			cgc_mousePointer[]							   = "mousePointer";
	const s8			cgc_movable[]								   = "movable";
	const s8			cgc_moverBars[]								   = "moverBars";
	const s8			cgc_multiSelect[]							   = "multiSelect";
	const s8			cgc_name[]									   = "name";
	const s8			cgc_newIndex[]								   = "newIndex";
	const s8			cgc_newItemID[]								   = "newItemID";
	const s8			cgc_nullDisplay[]							   = "nullDisplay";
	const s8			cgc_numberOfElements[]						   = "numberOfElements";
	const s8			cgc_oLEClass[]								   = "oLEClass";
	const s8			cgc_oLEDragMode[]							   = "oLEDragMode";
	const s8			cgc_oLEDragPicture[]						   = "oLEDragPicture";
	const s8			cgc_oLEDropEffects[]						   = "oLEDropEffects";
	const s8			cgc_oLEDropHasData[]						   = "oLEDropHasData";
	const s8			cgc_oLEDropMode[]							   = "oLEDropMode";
	const s8			cgc_oLEDropTextInsertion[]					   = "oLEDropTextInsertion";
	const s8			cgc_oLELCID[]								   = "oLELCID";
	const s8			cgc_oLETypeAllowed[]						   = "oLETypeAllowed";
	const s8			cgc_object[]								   = "object";
	const s8			cgc_objects[]								   = "objects";
	const s8			cgc_openWindow[]							   = "openWindow";
	const s8			cgc_optimize[]								   = "optimize";
	const s8			cgc_pageCount[]								   = "pageCount";
	const s8			cgc_pageHeight[]							   = "pageHeight";
	const s8			cgc_pageOrder[]								   = "pageOrder";
	const s8			cgc_pageWidth[]								   = "pageWidth";
	const s8			cgc_pages[]									   = "pages";
	const s8			cgc_panel[]									   = "panel";
	const s8			cgc_panelLink[]								   = "panelLink";
	const s8			cgc_parent[]								   = "parent";
	const s8			cgc_parentClass[]							   = "parentClass";
	const s8			cgc_partition[]								   = "partition";
	const s8			cgc_passwordChar[]							   = "passwordChar";
	const s8			cgc_picture[]								   = "picture";
	const s8			cgc_pictureMargin[]							   = "pictureMargin";
	const s8			cgc_picturePosition[]						   = "picturePosition";
	const s8			cgc_pictureSelectionDisplay[]				   = "pictureSelectionDisplay";
	const s8			cgc_pictureSpacing[]						   = "pictureSpacing";
	const s8			cgc_pictureVal[]							   = "pictureVal";
	const s8			cgc_polyPoints[]							   = "polyPoints";
	const s8			cgc_procedure[]								   = "procedure";
	const s8			cgc_readBackColor[]							   = "readBackColor";
	const s8			cgc_readCycle[]								   = "readCycle";
	const s8			cgc_readForeColor[]							   = "readForeColor";
	const s8			cgc_readLock[]								   = "readLock";
	const s8			cgc_readMouse[]								   = "readMouse";
	const s8			cgc_readOnly[]								   = "readOnly";
	const s8			cgc_readSave[]								   = "readSave";
	const s8			cgc_readTimeOut[]							   = "readTimeOut";
	const s8			cgc_recordMark[]							   = "recordMark";
	const s8			cgc_recordSource[]							   = "recordSource";
	const s8			cgc_recordSourceType[]						   = "recordSourceType";
	const s8			cgc_relationalExpr[]						   = "relationalExpr";
	const s8			cgc_relativeColumn[]						   = "relativeColumn";
	const s8			cgc_relativeRow[]							   = "relativeRow";
	const s8			cgc_releaseType[]							   = "releaseType";
	const s8			cgc_resizable[]								   = "resizable";
	const s8			cgc_rightToLeft[]							   = "rightToLeft";
	const s8			cgc_rotateFlip[]							   = "rotateFlip";
	const s8			cgc_rotation[]								   = "rotation";
	const s8			cgc_rowColChange[]							   = "rowColChange";
	const s8			cgc_rowHeight[]								   = "rowHeight";
	const s8			cgc_rowSource[]								   = "rowSource";
	const s8			cgc_rowSourceType[]							   = "rowSourceType";
	const s8			cgc_scaleMode[]								   = "scaleMode";
	const s8			cgc_scrollBars[]							   = "scrollBars";
	const s8			cgc_seconds[]								   = "seconds";
	const s8			cgc_selLength[]								   = "selLength";
	const s8			cgc_selStart[]								   = "selStart";
	const s8			cgc_selText[]								   = "selText";
	const s8			cgc_selectOnEntry[]							   = "selectOnEntry";
	const s8			cgc_selected[]								   = "selected";
	const s8			cgc_selectedBackColor[]						   = "selectedBackColor";
	const s8			cgc_selectedForeColor[]						   = "selectedForeColor";
	const s8			cgc_selectedID[]							   = "selectedID";
	const s8			cgc_selectedItemBackColor[]					   = "selectedItemBackColor";
	const s8			cgc_selectedItemForeColor[]					   = "selectedItemForeColor";
	const s8			cgc_showInTaskbar[]							   = "showInTaskbar";
	const s8			cgc_showTips[]								   = "showTips";
	const s8			cgc_showWindow[]							   = "showWindow";
	const s8			cgc_sizable[]								   = "sizable";
	const s8			cgc_sizeBox[]								   = "sizeBox";
	const s8			cgc_sorted[]								   = "sorted";
	const s8			cgc_sparse[]								   = "sparse";
	const s8			cgc_specialEffect[]							   = "specialEffect";
	const s8			cgc_spinnerHighValue[]						   = "spinnerHighValue";
	const s8			cgc_spinnerLowValue[]						   = "spinnerLowValue";
	const s8			cgc_splitBar[]								   = "splitBar";
	const s8			cgc_stackLevel[]							   = "stackLevel";
	const s8			cgc_statusBarText[]							   = "statusBarText";
	const s8			cgc_stretch[]								   = "stretch";
	const s8			cgc_strictDateEntry[]						   = "strictDateEntry";
	const s8			cgc_style[]									   = "style";
	const s8			cgc_tabIndex[]								   = "tabIndex";
	const s8			cgc_tabOrientation[]						   = "tabOrientation";
	const s8			cgc_tabStop[]								   = "tabStop";
	const s8			cgc_tabStyle[]								   = "tabStyle";
	const s8			cgc_tabs[]									   = "tabs";
	const s8			cgc_tag[]									   = "tag";
	const s8			cgc_terminateRead[]							   = "terminateRead";
	const s8			cgc_text[]									   = "text";
	const s8			cgc_themes[]								   = "themes";
	const s8			cgc_titleBar[]								   = "titleBar";
	const s8			cgc_toolTipText[]							   = "toolTipText";
	const s8			cgc_top[]									   = "top";
	const s8			cgc_topIndex[]								   = "topIndex";
	const s8			cgc_topItemID[]								   = "topItemID";
	const s8			cgc_userValue[]								   = "userValue";
	const s8			cgc_vScrollSmallChange[]					   = "vScrollSmallChange";
	const s8			cgc_value[]									   = "value";
	const s8			cgc_view[]									   = "view";
	const s8			cgc_viewPortHeight[]						   = "viewPortHeight";
	const s8			cgc_viewPortLeft[]							   = "viewPortLeft";
	const s8			cgc_viewPortTop[]							   = "viewPortTop";
	const s8			cgc_viewPortWidth[]							   = "viewPortWidth";
	const s8			cgc_visible[]								   = "visible";
	const s8			cgc_visualEffect[]							   = "visualEffect";
	const s8			cgc_whatsThisButton[]						   = "whatsThisButton";
	const s8			cgc_whatsThisHelp[]							   = "whatsThisHelp";
	const s8			cgc_whatsThisHelpID[]						   = "whatsThisHelpID";
	const s8			cgc_width[]									   = "width";
	const s8			cgc_windowList[]							   = "windowList";
	const s8			cgc_windowState[]							   = "windowState";
	const s8			cgc_windowType[]							   = "windowType";
	const s8			cgc_wordWrap[]								   = "wordWrap";
	const s8			cgc_zoomBox[]								   = "zoomBox";

	bool			iObj_set_activeColumn									 (SObject* obj, SVariable* var);
	bool			iObj_set_activeControl									 (SObject* obj, SVariable* var);
	bool			iObj_set_activeForm										 (SObject* obj, SVariable* var);
	bool			iObj_set_activePage										 (SObject* obj, SVariable* var);
	bool			iObj_set_activeRow										 (SObject* obj, SVariable* var);
	bool			iObj_set_addLineFeeds									 (SObject* obj, SVariable* var);
	bool			iObj_set_align											 (SObject* obj, SVariable* var);
	bool			iObj_set_alignment										 (SObject* obj, SVariable* var);
	bool			iObj_set_allowAddNew									 (SObject* obj, SVariable* var);
	bool			iObj_set_allowAutoColumnFit								 (SObject* obj, SVariable* var);
	bool			iObj_set_allowCellSelection								 (SObject* obj, SVariable* var);
	bool			iObj_set_allowHeaderSizing								 (SObject* obj, SVariable* var);
	bool			iObj_set_allowOutput									 (SObject* obj, SVariable* var);
	bool			iObj_set_allowRowSizing									 (SObject* obj, SVariable* var);
	bool			iObj_set_allowTabs										 (SObject* obj, SVariable* var);
	bool			iObj_set_alwaysOnBottom									 (SObject* obj, SVariable* var);
	bool			iObj_set_alwaysOnTop									 (SObject* obj, SVariable* var);
	bool			iObj_set_anchor											 (SObject* obj, SVariable* var);
	bool			iObj_set_application									 (SObject* obj, SVariable* var);
	bool			iObj_set_autoActivate									 (SObject* obj, SVariable* var);
	bool			iObj_set_autoCenter										 (SObject* obj, SVariable* var);
	bool			iObj_set_autoCompSource									 (SObject* obj, SVariable* var);
	bool			iObj_set_autoCompTable									 (SObject* obj, SVariable* var);
	bool			iObj_set_autoComplete									 (SObject* obj, SVariable* var);
	bool			iObj_set_autoHideScrollBar								 (SObject* obj, SVariable* var);
	bool			iObj_set_autoRelease									 (SObject* obj, SVariable* var);
	bool			iObj_set_autoSize										 (SObject* obj, SVariable* var);
	bool			iObj_set_autoVerbMenu									 (SObject* obj, SVariable* var);
	bool			iObj_set_backColor										 (SObject* obj, SVariable* var);
	bool			iObj_set_backStyle										 (SObject* obj, SVariable* var);
	bool			iObj_set_baseClass										 (SObject* obj, SVariable* var);
	bool			iObj_set_bindControls									 (SObject* obj, SVariable* var);
	bool			iObj_set_borderColor									 (SObject* obj, SVariable* var);
	bool			iObj_set_borderStyle									 (SObject* obj, SVariable* var);
	bool			iObj_set_borderWidth									 (SObject* obj, SVariable* var);
	bool			iObj_set_bound											 (SObject* obj, SVariable* var);
	bool			iObj_set_boundColumn									 (SObject* obj, SVariable* var);
	bool			iObj_set_boundTo										 (SObject* obj, SVariable* var);
	bool			iObj_set_bufferMode										 (SObject* obj, SVariable* var);
	bool			iObj_set_buttonCount									 (SObject* obj, SVariable* var);
	bool			iObj_set_cancel											 (SObject* obj, SVariable* var);
	bool			iObj_set_caption										 (SObject* obj, SVariable* var);
	bool			iObj_set_centered										 (SObject* obj, SVariable* var);
	bool			iObj_set_century										 (SObject* obj, SVariable* var);
	bool			iObj_set_childOrder										 (SObject* obj, SVariable* var);
	bool			iObj_set_class											 (SObject* obj, SVariable* var);
	bool			iObj_set_classLibrary									 (SObject* obj, SVariable* var);
	bool			iObj_set_clipControls									 (SObject* obj, SVariable* var);
	bool			iObj_set_closable										 (SObject* obj, SVariable* var);
	bool			iObj_set_colorScheme									 (SObject* obj, SVariable* var);
	bool			iObj_set_colorSource									 (SObject* obj, SVariable* var);
	bool			iObj_set_columnCount									 (SObject* obj, SVariable* var);
	bool			iObj_set_columnLines									 (SObject* obj, SVariable* var);
	bool			iObj_set_columnOrder									 (SObject* obj, SVariable* var);
	bool			iObj_set_columnWidths									 (SObject* obj, SVariable* var);
	bool			iObj_set_columns										 (SObject* obj, SVariable* var);
	bool			iObj_set_comment										 (SObject* obj, SVariable* var);
	bool			iObj_set_continuousScroll								 (SObject* obj, SVariable* var);
	bool			iObj_set_controlBox										 (SObject* obj, SVariable* var);
	bool			iObj_set_controlCount									 (SObject* obj, SVariable* var);
	bool			iObj_set_controlSource									 (SObject* obj, SVariable* var);
	bool			iObj_set_controls										 (SObject* obj, SVariable* var);
	bool			iObj_set_count											 (SObject* obj, SVariable* var);
	bool			iObj_set_currentControl									 (SObject* obj, SVariable* var);
	bool			iObj_set_currentX										 (SObject* obj, SVariable* var);
	bool			iObj_set_currentY										 (SObject* obj, SVariable* var);
	bool			iObj_set_curvature										 (SObject* obj, SVariable* var);
	bool			iObj_set_dEClass										 (SObject* obj, SVariable* var);
	bool			iObj_set_dEClassLibrary									 (SObject* obj, SVariable* var);
	bool			iObj_set_dataEnvironment								 (SObject* obj, SVariable* var);
	bool			iObj_set_dataSession									 (SObject* obj, SVariable* var);
	bool			iObj_set_dataSessionID									 (SObject* obj, SVariable* var);
	bool			iObj_set_dateFormat										 (SObject* obj, SVariable* var);
	bool			iObj_set_dateMark										 (SObject* obj, SVariable* var);
	bool			iObj_set_defOLELCID										 (SObject* obj, SVariable* var);
	bool			iObj_set_default										 (SObject* obj, SVariable* var);
	bool			iObj_set_deleteMark										 (SObject* obj, SVariable* var);
	bool			iObj_set_desktop										 (SObject* obj, SVariable* var);
	bool			iObj_set_details										 (SObject* obj, SVariable* var);
	bool			iObj_set_disabledBackColor								 (SObject* obj, SVariable* var);
	bool			iObj_set_disabledForeColor								 (SObject* obj, SVariable* var);
	bool			iObj_set_disabledItemBackColor							 (SObject* obj, SVariable* var);
	bool			iObj_set_disabledItemForeColor							 (SObject* obj, SVariable* var);
	bool			iObj_set_disabledPicture								 (SObject* obj, SVariable* var);
	bool			iObj_set_displayCount									 (SObject* obj, SVariable* var);
	bool			iObj_set_displayValue									 (SObject* obj, SVariable* var);
	bool			iObj_set_doCreate										 (SObject* obj, SVariable* var);
	bool			iObj_set_dockPosition									 (SObject* obj, SVariable* var);
	bool			iObj_set_dockable										 (SObject* obj, SVariable* var);
	bool			iObj_set_docked											 (SObject* obj, SVariable* var);
	bool			iObj_set_documentFile									 (SObject* obj, SVariable* var);
	bool			iObj_set_downPicture									 (SObject* obj, SVariable* var);
	bool			iObj_set_dragIcon										 (SObject* obj, SVariable* var);
	bool			iObj_set_dragMode										 (SObject* obj, SVariable* var);
	bool			iObj_set_drawMode										 (SObject* obj, SVariable* var);
	bool			iObj_set_drawStyle										 (SObject* obj, SVariable* var);
	bool			iObj_set_drawWidth										 (SObject* obj, SVariable* var);
	bool			iObj_set_dynamicAlignment								 (SObject* obj, SVariable* var);
	bool			iObj_set_dynamicBackColor								 (SObject* obj, SVariable* var);
	bool			iObj_set_dynamicCurrentControl							 (SObject* obj, SVariable* var);
	bool			iObj_set_dynamicFontBold								 (SObject* obj, SVariable* var);
	bool			iObj_set_dynamicFontItalic								 (SObject* obj, SVariable* var);
	bool			iObj_set_dynamicFontName								 (SObject* obj, SVariable* var);
	bool			iObj_set_dynamicFontOutline								 (SObject* obj, SVariable* var);
	bool			iObj_set_dynamicFontShadow								 (SObject* obj, SVariable* var);
	bool			iObj_set_dynamicFontSize								 (SObject* obj, SVariable* var);
	bool			iObj_set_dynamicFontStrikeThru							 (SObject* obj, SVariable* var);
	bool			iObj_set_dynamicFontUnderline							 (SObject* obj, SVariable* var);
	bool			iObj_set_dynamicForeColor								 (SObject* obj, SVariable* var);
	bool			iObj_set_dynamicInputMask								 (SObject* obj, SVariable* var);
	bool			iObj_set_enableHyperlinks								 (SObject* obj, SVariable* var);
	bool			iObj_set_enabled										 (SObject* obj, SVariable* var);
	bool			iObj_set_errorNo										 (SObject* obj, SVariable* var);
	bool			iObj_set_fillColor										 (SObject* obj, SVariable* var);
	bool			iObj_set_fillStyle										 (SObject* obj, SVariable* var);
	bool			iObj_set_firstElement									 (SObject* obj, SVariable* var);
	bool			iObj_set_fontBold										 (SObject* obj, SVariable* var);
	bool			iObj_set_fontCharSet									 (SObject* obj, SVariable* var);
	bool			iObj_set_fontCondense									 (SObject* obj, SVariable* var);
	bool			iObj_set_fontExtend										 (SObject* obj, SVariable* var);
	bool			iObj_set_fontItalic										 (SObject* obj, SVariable* var);
	bool			iObj_set_fontName										 (SObject* obj, SVariable* var);
	bool			iObj_set_fontOutline									 (SObject* obj, SVariable* var);
	bool			iObj_set_fontShadow										 (SObject* obj, SVariable* var);
	bool			iObj_set_fontSize										 (SObject* obj, SVariable* var);
	bool			iObj_set_fontStrikeThru									 (SObject* obj, SVariable* var);
	bool			iObj_set_fontUnderLine									 (SObject* obj, SVariable* var);
	bool			iObj_set_fontUnderline									 (SObject* obj, SVariable* var);
	bool			iObj_set_foreColor										 (SObject* obj, SVariable* var);
	bool			iObj_set_formCount										 (SObject* obj, SVariable* var);
	bool			iObj_set_format											 (SObject* obj, SVariable* var);
	bool			iObj_set_forms											 (SObject* obj, SVariable* var);
	bool			iObj_set_gridLineColor									 (SObject* obj, SVariable* var);
	bool			iObj_set_gridLineWidth									 (SObject* obj, SVariable* var);
	bool			iObj_set_gridLines										 (SObject* obj, SVariable* var);
	bool			iObj_set_hScrollSmallChange								 (SObject* obj, SVariable* var);
	bool			iObj_set_hWnd											 (SObject* obj, SVariable* var);
	bool			iObj_set_halfHeightCaption								 (SObject* obj, SVariable* var);
	bool			iObj_set_headerClass									 (SObject* obj, SVariable* var);
	bool			iObj_set_headerClassLibrary								 (SObject* obj, SVariable* var);
	bool			iObj_set_headerHeight									 (SObject* obj, SVariable* var);
	bool			iObj_set_height											 (SObject* obj, SVariable* var);
	bool			iObj_set_helpContextID									 (SObject* obj, SVariable* var);
	bool			iObj_set_hideSelection									 (SObject* obj, SVariable* var);
	bool			iObj_set_highLight										 (SObject* obj, SVariable* var);
	bool			iObj_set_highLightRow									 (SObject* obj, SVariable* var);
	bool			iObj_set_highlightBackColor								 (SObject* obj, SVariable* var);
	bool			iObj_set_highlightForeColor								 (SObject* obj, SVariable* var);
	bool			iObj_set_highlightRowLineWidth							 (SObject* obj, SVariable* var);
	bool			iObj_set_highlightStyle									 (SObject* obj, SVariable* var);
	bool			iObj_set_hostName										 (SObject* obj, SVariable* var);
	bool			iObj_set_hours											 (SObject* obj, SVariable* var);
	bool			iObj_set_iMEMode										 (SObject* obj, SVariable* var);
	bool			iObj_set_icon											 (SObject* obj, SBitmap* bmp);
	bool			iObj_set_increment										 (SObject* obj, SVariable* var);
	bool			iObj_set_incrementalSearch								 (SObject* obj, SVariable* var);
	bool			iObj_set_inputMask										 (SObject* obj, SVariable* var);
	bool			iObj_set_integralHeight									 (SObject* obj, SVariable* var);
	bool			iObj_set_interval										 (SObject* obj, SVariable* var);
	bool			iObj_set_itemBackColor									 (SObject* obj, SVariable* var);
	bool			iObj_set_itemData										 (SObject* obj, SVariable* var);
	bool			iObj_set_itemForeColor									 (SObject* obj, SVariable* var);
	bool			iObj_set_itemIDData										 (SObject* obj, SVariable* var);
	bool			iObj_set_itemTips										 (SObject* obj, SVariable* var);
	bool			iObj_set_keyPreview										 (SObject* obj, SVariable* var);
	bool			iObj_set_keySort										 (SObject* obj, SVariable* var);
	bool			iObj_set_keyboardHighValue								 (SObject* obj, SVariable* var);
	bool			iObj_set_keyboardLowValue								 (SObject* obj, SVariable* var);
	bool			iObj_set_left											 (SObject* obj, SVariable* var);
	bool			iObj_set_leftColumn										 (SObject* obj, SVariable* var);
	bool			iObj_set_lineContents									 (SObject* obj, SVariable* var);
	bool			iObj_set_lineNo											 (SObject* obj, SVariable* var);
	bool			iObj_set_lineSlant										 (SObject* obj, SVariable* var);
	bool			iObj_set_linkMaster										 (SObject* obj, SVariable* var);
	bool			iObj_set_list											 (SObject* obj, SVariable* var);
	bool			iObj_set_listCount										 (SObject* obj, SVariable* var);
	bool			iObj_set_listIndex										 (SObject* obj, SVariable* var);
	bool			iObj_set_listItem										 (SObject* obj, SVariable* var);
	bool			iObj_set_listItemID										 (SObject* obj, SVariable* var);
	bool			iObj_set_lockColumns									 (SObject* obj, SVariable* var);
	bool			iObj_set_lockColumnsLeft								 (SObject* obj, SVariable* var);
	bool			iObj_set_lockScreen										 (SObject* obj, SVariable* var);
	bool			iObj_set_mDIForm										 (SObject* obj, SVariable* var);
	bool			iObj_set_macDesktop										 (SObject* obj, SVariable* var);
	bool			iObj_set_margin											 (SObject* obj, SVariable* var);
	bool			iObj_set_maxButton										 (SObject* obj, SVariable* var);
	bool			iObj_set_maxHeight										 (SObject* obj, SVariable* var);
	bool			iObj_set_maxLeft										 (SObject* obj, SVariable* var);
	bool			iObj_set_maxLength										 (SObject* obj, SVariable* var);
	bool			iObj_set_maxTop											 (SObject* obj, SVariable* var);
	bool			iObj_set_maxWidth										 (SObject* obj, SVariable* var);
	bool			iObj_set_memberClass									 (SObject* obj, SVariable* var);
	bool			iObj_set_memberClassLibrary								 (SObject* obj, SVariable* var);
	bool			iObj_set_memoWindow										 (SObject* obj, SVariable* var);
	bool			iObj_set_message										 (SObject* obj, SVariable* var);
	bool			iObj_set_minButton										 (SObject* obj, SVariable* var);
	bool			iObj_set_minHeight										 (SObject* obj, SVariable* var);
	bool			iObj_set_minWidth										 (SObject* obj, SVariable* var);
	bool			iObj_set_mouseIcon										 (SObject* obj, SBitmap* bmp);
	bool			iObj_set_mousePointer									 (SObject* obj, SVariable* var);
	bool			iObj_set_movable										 (SObject* obj, SVariable* var);
	bool			iObj_set_moverBars										 (SObject* obj, SVariable* var);
	bool			iObj_set_multiSelect									 (SObject* obj, SVariable* var);
	bool			iObj_set_name											 (SObject* obj, SVariable* var);
	bool			iObj_set_newIndex										 (SObject* obj, SVariable* var);
	bool			iObj_set_newItemID										 (SObject* obj, SVariable* var);
	bool			iObj_set_nullDisplay									 (SObject* obj, SVariable* var);
	bool			iObj_set_numberOfElements								 (SObject* obj, SVariable* var);
	bool			iObj_set_oLEClass										 (SObject* obj, SVariable* var);
	bool			iObj_set_oLEDragMode									 (SObject* obj, SVariable* var);
	bool			iObj_set_oLEDragPicture									 (SObject* obj, SBitmap* bmp);
	bool			iObj_set_oLEDropEffects									 (SObject* obj, SVariable* var);
	bool			iObj_set_oLEDropHasData									 (SObject* obj, SVariable* var);
	bool			iObj_set_oLEDropMode									 (SObject* obj, SVariable* var);
	bool			iObj_set_oLEDropTextInsertion							 (SObject* obj, SVariable* var);
	bool			iObj_set_oLELCID										 (SObject* obj, SVariable* var);
	bool			iObj_set_oLETypeAllowed									 (SObject* obj, SVariable* var);
	bool			iObj_set_object											 (SObject* obj, SVariable* var);
	bool			iObj_set_objects										 (SObject* obj, SVariable* var);
	bool			iObj_set_openWindow										 (SObject* obj, SVariable* var);
	bool			iObj_set_optimize										 (SObject* obj, SVariable* var);
	bool			iObj_set_pageCount										 (SObject* obj, SVariable* var);
	bool			iObj_set_pageHeight										 (SObject* obj, SVariable* var);
	bool			iObj_set_pageOrder										 (SObject* obj, SVariable* var);
	bool			iObj_set_pageWidth										 (SObject* obj, SVariable* var);
	bool			iObj_set_pages											 (SObject* obj, SVariable* var);
	bool			iObj_set_panel											 (SObject* obj, SVariable* var);
	bool			iObj_set_panelLink										 (SObject* obj, SVariable* var);
	bool			iObj_set_parent											 (SObject* obj, SVariable* var);
	bool			iObj_set_parentClass									 (SObject* obj, SVariable* var);
	bool			iObj_set_partition										 (SObject* obj, SVariable* var);
	bool			iObj_set_passwordChar									 (SObject* obj, SVariable* var);
	bool			iObj_set_picture										 (SObject* obj, SVariable* var);
	bool			iObj_set_pictureMargin									 (SObject* obj, SVariable* var);
	bool			iObj_set_picturePosition								 (SObject* obj, SVariable* var);
	bool			iObj_set_pictureSelectionDisplay						 (SObject* obj, SVariable* var);
	bool			iObj_set_pictureSpacing									 (SObject* obj, SVariable* var);
	bool			iObj_set_pictureVal										 (SObject* obj, SVariable* var);
	bool			iObj_set_polyPoints										 (SObject* obj, SVariable* var);
	bool			iObj_set_procedure										 (SObject* obj, SVariable* var);
	bool			iObj_set_readBackColor									 (SObject* obj, SVariable* var);
	bool			iObj_set_readCycle										 (SObject* obj, SVariable* var);
	bool			iObj_set_readForeColor									 (SObject* obj, SVariable* var);
	bool			iObj_set_readLock										 (SObject* obj, SVariable* var);
	bool			iObj_set_readMouse										 (SObject* obj, SVariable* var);
	bool			iObj_set_readOnly										 (SObject* obj, SVariable* var);
	bool			iObj_set_readSave										 (SObject* obj, SVariable* var);
	bool			iObj_set_readTimeOut									 (SObject* obj, SVariable* var);
	bool			iObj_set_recordMark										 (SObject* obj, SVariable* var);
	bool			iObj_set_recordSource									 (SObject* obj, SVariable* var);
	bool			iObj_set_recordSourceType								 (SObject* obj, SVariable* var);
	bool			iObj_set_relationalExpr									 (SObject* obj, SVariable* var);
	bool			iObj_set_relativeColumn									 (SObject* obj, SVariable* var);
	bool			iObj_set_relativeRow									 (SObject* obj, SVariable* var);
	bool			iObj_set_releaseType									 (SObject* obj, SVariable* var);
	bool			iObj_set_resizable										 (SObject* obj, SVariable* var);
	bool			iObj_set_rightToLeft									 (SObject* obj, SVariable* var);
	bool			iObj_set_rotateFlip										 (SObject* obj, SVariable* var);
	bool			iObj_set_rotation										 (SObject* obj, SVariable* var);
	bool			iObj_set_rowColChange									 (SObject* obj, SVariable* var);
	bool			iObj_set_rowHeight										 (SObject* obj, SVariable* var);
	bool			iObj_set_rowSource										 (SObject* obj, SVariable* var);
	bool			iObj_set_rowSourceType									 (SObject* obj, SVariable* var);
	bool			iObj_set_scaleMode										 (SObject* obj, SVariable* var);
	bool			iObj_set_scrollBars										 (SObject* obj, SVariable* var);
	bool			iObj_set_seconds										 (SObject* obj, SVariable* var);
	bool			iObj_set_selLength										 (SObject* obj, SVariable* var);
	bool			iObj_set_selStart										 (SObject* obj, SVariable* var);
	bool			iObj_set_selText										 (SObject* obj, SVariable* var);
	bool			iObj_set_selectOnEntry									 (SObject* obj, SVariable* var);
	bool			iObj_set_selected										 (SObject* obj, SVariable* var);
	bool			iObj_set_selectedBackColor								 (SObject* obj, SVariable* var);
	bool			iObj_set_selectedForeColor								 (SObject* obj, SVariable* var);
	bool			iObj_set_selectedID										 (SObject* obj, SVariable* var);
	bool			iObj_set_selectedItemBackColor							 (SObject* obj, SVariable* var);
	bool			iObj_set_selectedItemForeColor							 (SObject* obj, SVariable* var);
	bool			iObj_set_showInTaskbar									 (SObject* obj, SVariable* var);
	bool			iObj_set_showTips										 (SObject* obj, SVariable* var);
	bool			iObj_set_showWindow										 (SObject* obj, SVariable* var);
	bool			iObj_set_sizable										 (SObject* obj, SVariable* var);
	bool			iObj_set_sizeBox										 (SObject* obj, SVariable* var);
	bool			iObj_set_sorted											 (SObject* obj, SVariable* var);
	bool			iObj_set_sparse											 (SObject* obj, SVariable* var);
	bool			iObj_set_specialEffect									 (SObject* obj, SVariable* var);
	bool			iObj_set_spinnerHighValue								 (SObject* obj, SVariable* var);
	bool			iObj_set_spinnerLowValue								 (SObject* obj, SVariable* var);
	bool			iObj_set_splitBar										 (SObject* obj, SVariable* var);
	bool			iObj_set_stackLevel										 (SObject* obj, SVariable* var);
	bool			iObj_set_statusBarText									 (SObject* obj, SVariable* var);
	bool			iObj_set_stretch										 (SObject* obj, SVariable* var);
	bool			iObj_set_strictDateEntry								 (SObject* obj, SVariable* var);
	bool			iObj_set_style											 (SObject* obj, SVariable* var);
	bool			iObj_set_tabIndex										 (SObject* obj, SVariable* var);
	bool			iObj_set_tabOrientation									 (SObject* obj, SVariable* var);
	bool			iObj_set_tabStop										 (SObject* obj, SVariable* var);
	bool			iObj_set_tabStyle										 (SObject* obj, SVariable* var);
	bool			iObj_set_tabs											 (SObject* obj, SVariable* var);
	bool			iObj_set_tag											 (SObject* obj, SVariable* var);
	bool			iObj_set_terminateRead									 (SObject* obj, SVariable* var);
	bool			iObj_set_text											 (SObject* obj, SVariable* var);
	bool			iObj_set_themes											 (SObject* obj, SVariable* var);
	bool			iObj_set_titleBar										 (SObject* obj, SVariable* var);
	bool			iObj_set_toolTipText									 (SObject* obj, SVariable* var);
	bool			iObj_set_top											 (SObject* obj, SVariable* var);
	bool			iObj_set_topIndex										 (SObject* obj, SVariable* var);
	bool			iObj_set_topItemID										 (SObject* obj, SVariable* var);
	bool			iObj_set_userValue										 (SObject* obj, SVariable* var);
	bool			iObj_set_vScrollSmallChange								 (SObject* obj, SVariable* var);
	bool			iObj_set_value											 (SObject* obj, SVariable* var);
	bool			iObj_set_view											 (SObject* obj, SVariable* var);
	bool			iObj_set_viewPortHeight									 (SObject* obj, SVariable* var);
	bool			iObj_set_viewPortLeft									 (SObject* obj, SVariable* var);
	bool			iObj_set_viewPortTop									 (SObject* obj, SVariable* var);
	bool			iObj_set_viewPortWidth									 (SObject* obj, SVariable* var);
	bool			iObj_set_visible										 (SObject* obj, SVariable* var);
	bool			iObj_set_visualEffect									 (SObject* obj, SVariable* var);
	bool			iObj_set_whatsThisButton								 (SObject* obj, SVariable* var);
	bool			iObj_set_whatsThisHelp									 (SObject* obj, SVariable* var);
	bool			iObj_set_whatsThisHelpID								 (SObject* obj, SVariable* var);
	bool			iObj_set_width											 (SObject* obj, SVariable* var);
	bool			iObj_set_windowList										 (SObject* obj, SVariable* var);
	bool			iObj_set_windowState									 (SObject* obj, SVariable* var);
	bool			iObj_set_windowType										 (SObject* obj, SVariable* var);
	bool			iObj_set_wordWrap										 (SObject* obj, SVariable* var);
	bool			iObj_set_zoomBox										 (SObject* obj, SVariable* var);

	SVariable*		iObj_get_activeColumn									 (SObject* obj);
	SVariable*		iObj_get_activeControl									 (SObject* obj);
	SVariable*		iObj_get_activeForm										 (SObject* obj);
	SVariable*		iObj_get_activePage										 (SObject* obj);
	SVariable*		iObj_get_activeRow										 (SObject* obj);
	SVariable*		iObj_get_addLineFeeds									 (SObject* obj);
	SVariable*		iObj_get_align											 (SObject* obj);
	SVariable*		iObj_get_alignment										 (SObject* obj);
	SVariable*		iObj_get_allowAddNew									 (SObject* obj);
	SVariable*		iObj_get_allowAutoColumnFit								 (SObject* obj);
	SVariable*		iObj_get_allowCellSelection								 (SObject* obj);
	SVariable*		iObj_get_allowHeaderSizing								 (SObject* obj);
	SVariable*		iObj_get_allowOutput									 (SObject* obj);
	SVariable*		iObj_get_allowRowSizing									 (SObject* obj);
	SVariable*		iObj_get_allowTabs										 (SObject* obj);
	SVariable*		iObj_get_alwaysOnBottom									 (SObject* obj);
	SVariable*		iObj_get_alwaysOnTop									 (SObject* obj);
	SVariable*		iObj_get_anchor											 (SObject* obj);
	SVariable*		iObj_get_application									 (SObject* obj);
	SVariable*		iObj_get_autoActivate									 (SObject* obj);
	SVariable*		iObj_get_autoCenter										 (SObject* obj);
	SVariable*		iObj_get_autoCompSource									 (SObject* obj);
	SVariable*		iObj_get_autoCompTable									 (SObject* obj);
	SVariable*		iObj_get_autoComplete									 (SObject* obj);
	SVariable*		iObj_get_autoHideScrollBar								 (SObject* obj);
	SVariable*		iObj_get_autoRelease									 (SObject* obj);
	SVariable*		iObj_get_autoSize										 (SObject* obj);
	SVariable*		iObj_get_autoVerbMenu									 (SObject* obj);
	SVariable*		iObj_get_backColor										 (SObject* obj);
	SVariable*		iObj_get_backStyle										 (SObject* obj);
	SVariable*		iObj_get_baseClass										 (SObject* obj);
	SVariable*		iObj_get_bindControls									 (SObject* obj);
	SVariable*		iObj_get_borderColor									 (SObject* obj);
	SVariable*		iObj_get_borderStyle									 (SObject* obj);
	SVariable*		iObj_get_borderWidth									 (SObject* obj);
	SVariable*		iObj_get_bound											 (SObject* obj);
	SVariable*		iObj_get_boundColumn									 (SObject* obj);
	SVariable*		iObj_get_boundTo										 (SObject* obj);
	SVariable*		iObj_get_bufferMode										 (SObject* obj);
	SVariable*		iObj_get_buttonCount									 (SObject* obj);
	SVariable*		iObj_get_cancel											 (SObject* obj);
	SVariable*		iObj_get_caption										 (SObject* obj);
	SVariable*		iObj_get_centered										 (SObject* obj);
	SVariable*		iObj_get_century										 (SObject* obj);
	SVariable*		iObj_get_childOrder										 (SObject* obj);
	SVariable*		iObj_get_class											 (SObject* obj);
	SVariable*		iObj_get_classLibrary									 (SObject* obj);
	SVariable*		iObj_get_clipControls									 (SObject* obj);
	SVariable*		iObj_get_closable										 (SObject* obj);
	SVariable*		iObj_get_colorScheme									 (SObject* obj);
	SVariable*		iObj_get_colorSource									 (SObject* obj);
	SVariable*		iObj_get_columnCount									 (SObject* obj);
	SVariable*		iObj_get_columnLines									 (SObject* obj);
	SVariable*		iObj_get_columnOrder									 (SObject* obj);
	SVariable*		iObj_get_columnWidths									 (SObject* obj);
	SVariable*		iObj_get_columns										 (SObject* obj);
	SVariable*		iObj_get_comment										 (SObject* obj);
	SVariable*		iObj_get_continuousScroll								 (SObject* obj);
	SVariable*		iObj_get_controlBox										 (SObject* obj);
	SVariable*		iObj_get_controlCount									 (SObject* obj);
	SVariable*		iObj_get_controlSource									 (SObject* obj);
	SVariable*		iObj_get_controls										 (SObject* obj);
	SVariable*		iObj_get_count											 (SObject* obj);
	SVariable*		iObj_get_currentControl									 (SObject* obj);
	SVariable*		iObj_get_currentX										 (SObject* obj);
	SVariable*		iObj_get_currentY										 (SObject* obj);
	SVariable*		iObj_get_curvature										 (SObject* obj);
	SVariable*		iObj_get_dEClass										 (SObject* obj);
	SVariable*		iObj_get_dEClassLibrary									 (SObject* obj);
	SVariable*		iObj_get_dataEnvironment								 (SObject* obj);
	SVariable*		iObj_get_dataSession									 (SObject* obj);
	SVariable*		iObj_get_dataSessionID									 (SObject* obj);
	SVariable*		iObj_get_dateFormat										 (SObject* obj);
	SVariable*		iObj_get_dateMark										 (SObject* obj);
	SVariable*		iObj_get_defOLELCID										 (SObject* obj);
	SVariable*		iObj_get_default										 (SObject* obj);
	SVariable*		iObj_get_deleteMark										 (SObject* obj);
	SVariable*		iObj_get_desktop										 (SObject* obj);
	SVariable*		iObj_get_details										 (SObject* obj);
	SVariable*		iObj_get_disabledBackColor								 (SObject* obj);
	SVariable*		iObj_get_disabledForeColor								 (SObject* obj);
	SVariable*		iObj_get_disabledItemBackColor							 (SObject* obj);
	SVariable*		iObj_get_disabledItemForeColor							 (SObject* obj);
	SVariable*		iObj_get_disabledPicture								 (SObject* obj);
	SVariable*		iObj_get_displayCount									 (SObject* obj);
	SVariable*		iObj_get_displayValue									 (SObject* obj);
	SVariable*		iObj_get_doCreate										 (SObject* obj);
	SVariable*		iObj_get_dockPosition									 (SObject* obj);
	SVariable*		iObj_get_dockable										 (SObject* obj);
	SVariable*		iObj_get_docked											 (SObject* obj);
	SVariable*		iObj_get_documentFile									 (SObject* obj);
	SVariable*		iObj_get_downPicture									 (SObject* obj);
	SVariable*		iObj_get_dragIcon										 (SObject* obj);
	SVariable*		iObj_get_dragMode										 (SObject* obj);
	SVariable*		iObj_get_drawMode										 (SObject* obj);
	SVariable*		iObj_get_drawStyle										 (SObject* obj);
	SVariable*		iObj_get_drawWidth										 (SObject* obj);
	SVariable*		iObj_get_dynamicAlignment								 (SObject* obj);
	SVariable*		iObj_get_dynamicBackColor								 (SObject* obj);
	SVariable*		iObj_get_dynamicCurrentControl							 (SObject* obj);
	SVariable*		iObj_get_dynamicFontBold								 (SObject* obj);
	SVariable*		iObj_get_dynamicFontItalic								 (SObject* obj);
	SVariable*		iObj_get_dynamicFontName								 (SObject* obj);
	SVariable*		iObj_get_dynamicFontOutline								 (SObject* obj);
	SVariable*		iObj_get_dynamicFontShadow								 (SObject* obj);
	SVariable*		iObj_get_dynamicFontSize								 (SObject* obj);
	SVariable*		iObj_get_dynamicFontStrikeThru							 (SObject* obj);
	SVariable*		iObj_get_dynamicFontUnderline							 (SObject* obj);
	SVariable*		iObj_get_dynamicForeColor								 (SObject* obj);
	SVariable*		iObj_get_dynamicInputMask								 (SObject* obj);
	SVariable*		iObj_get_enableHyperlinks								 (SObject* obj);
	SVariable*		iObj_get_enabled										 (SObject* obj);
	SVariable*		iObj_get_errorNo										 (SObject* obj);
	SVariable*		iObj_get_fillColor										 (SObject* obj);
	SVariable*		iObj_get_fillStyle										 (SObject* obj);
	SVariable*		iObj_get_firstElement									 (SObject* obj);
	SVariable*		iObj_get_fontBold										 (SObject* obj);
	SVariable*		iObj_get_fontCharSet									 (SObject* obj);
	SVariable*		iObj_get_fontCondense									 (SObject* obj);
	SVariable*		iObj_get_fontExtend										 (SObject* obj);
	SVariable*		iObj_get_fontItalic										 (SObject* obj);
	SVariable*		iObj_get_fontName										 (SObject* obj);
	SVariable*		iObj_get_fontOutline									 (SObject* obj);
	SVariable*		iObj_get_fontShadow										 (SObject* obj);
	SVariable*		iObj_get_fontSize										 (SObject* obj);
	SVariable*		iObj_get_fontStrikeThru									 (SObject* obj);
	SVariable*		iObj_get_fontUnderLine									 (SObject* obj);
	SVariable*		iObj_get_fontUnderline									 (SObject* obj);
	SVariable*		iObj_get_foreColor										 (SObject* obj);
	SVariable*		iObj_get_formCount										 (SObject* obj);
	SVariable*		iObj_get_format											 (SObject* obj);
	SVariable*		iObj_get_forms											 (SObject* obj);
	SVariable*		iObj_get_gridLineColor									 (SObject* obj);
	SVariable*		iObj_get_gridLineWidth									 (SObject* obj);
	SVariable*		iObj_get_gridLines										 (SObject* obj);
	SVariable*		iObj_get_hScrollSmallChange								 (SObject* obj);
	SVariable*		iObj_get_hWnd											 (SObject* obj);
	SVariable*		iObj_get_halfHeightCaption								 (SObject* obj);
	SVariable*		iObj_get_headerClass									 (SObject* obj);
	SVariable*		iObj_get_headerClassLibrary								 (SObject* obj);
	SVariable*		iObj_get_headerHeight									 (SObject* obj);
	SVariable*		iObj_get_height											 (SObject* obj);
	SVariable*		iObj_get_helpContextID									 (SObject* obj);
	SVariable*		iObj_get_hideSelection									 (SObject* obj);
	SVariable*		iObj_get_highLight										 (SObject* obj);
	SVariable*		iObj_get_highLightRow									 (SObject* obj);
	SVariable*		iObj_get_highlightBackColor								 (SObject* obj);
	SVariable*		iObj_get_highlightForeColor								 (SObject* obj);
	SVariable*		iObj_get_highlightRowLineWidth							 (SObject* obj);
	SVariable*		iObj_get_highlightStyle									 (SObject* obj);
	SVariable*		iObj_get_hostName										 (SObject* obj);
	SVariable*		iObj_get_hours											 (SObject* obj);
	SVariable*		iObj_get_iMEMode										 (SObject* obj);
	SBitmap*		iObj_get_icon											 (SObject* obj);
	SVariable*		iObj_get_increment										 (SObject* obj);
	SVariable*		iObj_get_incrementalSearch								 (SObject* obj);
	SVariable*		iObj_get_inputMask										 (SObject* obj);
	SVariable*		iObj_get_integralHeight									 (SObject* obj);
	SVariable*		iObj_get_interval										 (SObject* obj);
	SVariable*		iObj_get_itemBackColor									 (SObject* obj);
	SVariable*		iObj_get_itemData										 (SObject* obj);
	SVariable*		iObj_get_itemForeColor									 (SObject* obj);
	SVariable*		iObj_get_itemIDData										 (SObject* obj);
	SVariable*		iObj_get_itemTips										 (SObject* obj);
	SVariable*		iObj_get_keyPreview										 (SObject* obj);
	SVariable*		iObj_get_keySort										 (SObject* obj);
	SVariable*		iObj_get_keyboardHighValue								 (SObject* obj);
	SVariable*		iObj_get_keyboardLowValue								 (SObject* obj);
	SVariable*		iObj_get_left											 (SObject* obj);
	SVariable*		iObj_get_leftColumn										 (SObject* obj);
	SVariable*		iObj_get_lineContents									 (SObject* obj);
	SVariable*		iObj_get_lineNo											 (SObject* obj);
	SVariable*		iObj_get_lineSlant										 (SObject* obj);
	SVariable*		iObj_get_linkMaster										 (SObject* obj);
	SVariable*		iObj_get_list											 (SObject* obj);
	SVariable*		iObj_get_listCount										 (SObject* obj);
	SVariable*		iObj_get_listIndex										 (SObject* obj);
	SVariable*		iObj_get_listItem										 (SObject* obj);
	SVariable*		iObj_get_listItemID										 (SObject* obj);
	SVariable*		iObj_get_lockColumns									 (SObject* obj);
	SVariable*		iObj_get_lockColumnsLeft								 (SObject* obj);
	SVariable*		iObj_get_lockScreen										 (SObject* obj);
	SVariable*		iObj_get_mDIForm										 (SObject* obj);
	SVariable*		iObj_get_macDesktop										 (SObject* obj);
	SVariable*		iObj_get_margin											 (SObject* obj);
	SVariable*		iObj_get_maxButton										 (SObject* obj);
	SVariable*		iObj_get_maxHeight										 (SObject* obj);
	SVariable*		iObj_get_maxLeft										 (SObject* obj);
	SVariable*		iObj_get_maxLength										 (SObject* obj);
	SVariable*		iObj_get_maxTop											 (SObject* obj);
	SVariable*		iObj_get_maxWidth										 (SObject* obj);
	SVariable*		iObj_get_memberClass									 (SObject* obj);
	SVariable*		iObj_get_memberClassLibrary								 (SObject* obj);
	SVariable*		iObj_get_memoWindow										 (SObject* obj);
	SVariable*		iObj_get_message										 (SObject* obj);
	SVariable*		iObj_get_minButton										 (SObject* obj);
	SVariable*		iObj_get_minHeight										 (SObject* obj);
	SVariable*		iObj_get_minWidth										 (SObject* obj);
	SBitmap*		iObj_get_mouseIcon										 (SObject* obj);
	SVariable*		iObj_get_mousePointer									 (SObject* obj);
	SVariable*		iObj_get_movable										 (SObject* obj);
	SVariable*		iObj_get_moverBars										 (SObject* obj);
	SVariable*		iObj_get_multiSelect									 (SObject* obj);
	SVariable*		iObj_get_name											 (SObject* obj);
	SVariable*		iObj_get_newIndex										 (SObject* obj);
	SVariable*		iObj_get_newItemID										 (SObject* obj);
	SVariable*		iObj_get_nullDisplay									 (SObject* obj);
	SVariable*		iObj_get_numberOfElements								 (SObject* obj);
	SVariable*		iObj_get_oLEClass										 (SObject* obj);
	SVariable*		iObj_get_oLEDragMode									 (SObject* obj);
	SBitmap*		iObj_get_oLEDragPicture									 (SObject* obj);
	SVariable*		iObj_get_oLEDropEffects									 (SObject* obj);
	SVariable*		iObj_get_oLEDropHasData									 (SObject* obj);
	SVariable*		iObj_get_oLEDropMode									 (SObject* obj);
	SVariable*		iObj_get_oLEDropTextInsertion							 (SObject* obj);
	SVariable*		iObj_get_oLELCID										 (SObject* obj);
	SVariable*		iObj_get_oLETypeAllowed									 (SObject* obj);
	SVariable*		iObj_get_object											 (SObject* obj);
	SVariable*		iObj_get_objects										 (SObject* obj);
	SVariable*		iObj_get_openWindow										 (SObject* obj);
	SVariable*		iObj_get_optimize										 (SObject* obj);
	SVariable*		iObj_get_pageCount										 (SObject* obj);
	SVariable*		iObj_get_pageHeight										 (SObject* obj);
	SVariable*		iObj_get_pageOrder										 (SObject* obj);
	SVariable*		iObj_get_pageWidth										 (SObject* obj);
	SVariable*		iObj_get_pages											 (SObject* obj);
	SVariable*		iObj_get_panel											 (SObject* obj);
	SVariable*		iObj_get_panelLink										 (SObject* obj);
	SVariable*		iObj_get_parent											 (SObject* obj);
	SVariable*		iObj_get_parentClass									 (SObject* obj);
	SVariable*		iObj_get_partition										 (SObject* obj);
	SVariable*		iObj_get_passwordChar									 (SObject* obj);
	SVariable*		iObj_get_picture										 (SObject* obj);
	SVariable*		iObj_get_pictureMargin									 (SObject* obj);
	SVariable*		iObj_get_picturePosition								 (SObject* obj);
	SVariable*		iObj_get_pictureSelectionDisplay						 (SObject* obj);
	SVariable*		iObj_get_pictureSpacing									 (SObject* obj);
	SVariable*		iObj_get_pictureVal										 (SObject* obj);
	SVariable*		iObj_get_polyPoints										 (SObject* obj);
	SVariable*		iObj_get_procedure										 (SObject* obj);
	SVariable*		iObj_get_readBackColor									 (SObject* obj);
	SVariable*		iObj_get_readCycle										 (SObject* obj);
	SVariable*		iObj_get_readForeColor									 (SObject* obj);
	SVariable*		iObj_get_readLock										 (SObject* obj);
	SVariable*		iObj_get_readMouse										 (SObject* obj);
	SVariable*		iObj_get_readOnly										 (SObject* obj);
	SVariable*		iObj_get_readSave										 (SObject* obj);
	SVariable*		iObj_get_readTimeOut									 (SObject* obj);
	SVariable*		iObj_get_recordMark										 (SObject* obj);
	SVariable*		iObj_get_recordSource									 (SObject* obj);
	SVariable*		iObj_get_recordSourceType								 (SObject* obj);
	SVariable*		iObj_get_relationalExpr									 (SObject* obj);
	SVariable*		iObj_get_relativeColumn									 (SObject* obj);
	SVariable*		iObj_get_relativeRow									 (SObject* obj);
	SVariable*		iObj_get_releaseType									 (SObject* obj);
	SVariable*		iObj_get_resizable										 (SObject* obj);
	SVariable*		iObj_get_rightToLeft									 (SObject* obj);
	SVariable*		iObj_get_rotateFlip										 (SObject* obj);
	SVariable*		iObj_get_rotation										 (SObject* obj);
	SVariable*		iObj_get_rowColChange									 (SObject* obj);
	SVariable*		iObj_get_rowHeight										 (SObject* obj);
	SVariable*		iObj_get_rowSource										 (SObject* obj);
	SVariable*		iObj_get_rowSourceType									 (SObject* obj);
	SVariable*		iObj_get_scaleMode										 (SObject* obj);
	SVariable*		iObj_get_scrollBars										 (SObject* obj);
	SVariable*		iObj_get_seconds										 (SObject* obj);
	SVariable*		iObj_get_selLength										 (SObject* obj);
	SVariable*		iObj_get_selStart										 (SObject* obj);
	SVariable*		iObj_get_selText										 (SObject* obj);
	SVariable*		iObj_get_selectOnEntry									 (SObject* obj);
	SVariable*		iObj_get_selected										 (SObject* obj);
	SVariable*		iObj_get_selectedBackColor								 (SObject* obj);
	SVariable*		iObj_get_selectedForeColor								 (SObject* obj);
	SVariable*		iObj_get_selectedID										 (SObject* obj);
	SVariable*		iObj_get_selectedItemBackColor							 (SObject* obj);
	SVariable*		iObj_get_selectedItemForeColor							 (SObject* obj);
	SVariable*		iObj_get_showInTaskbar									 (SObject* obj);
	SVariable*		iObj_get_showTips										 (SObject* obj);
	SVariable*		iObj_get_showWindow										 (SObject* obj);
	SVariable*		iObj_get_sizable										 (SObject* obj);
	SVariable*		iObj_get_sizeBox										 (SObject* obj);
	SVariable*		iObj_get_sorted											 (SObject* obj);
	SVariable*		iObj_get_sparse											 (SObject* obj);
	SVariable*		iObj_get_specialEffect									 (SObject* obj);
	SVariable*		iObj_get_spinnerHighValue								 (SObject* obj);
	SVariable*		iObj_get_spinnerLowValue								 (SObject* obj);
	SVariable*		iObj_get_splitBar										 (SObject* obj);
	SVariable*		iObj_get_stackLevel										 (SObject* obj);
	SVariable*		iObj_get_statusBarText									 (SObject* obj);
	SVariable*		iObj_get_stretch										 (SObject* obj);
	SVariable*		iObj_get_strictDateEntry								 (SObject* obj);
	SVariable*		iObj_get_style											 (SObject* obj);
	SVariable*		iObj_get_tabIndex										 (SObject* obj);
	SVariable*		iObj_get_tabOrientation									 (SObject* obj);
	SVariable*		iObj_get_tabStop										 (SObject* obj);
	SVariable*		iObj_get_tabStyle										 (SObject* obj);
	SVariable*		iObj_get_tabs											 (SObject* obj);
	SVariable*		iObj_get_tag											 (SObject* obj);
	SVariable*		iObj_get_terminateRead									 (SObject* obj);
	SVariable*		iObj_get_text											 (SObject* obj);
	SVariable*		iObj_get_themes											 (SObject* obj);
	SVariable*		iObj_get_titleBar										 (SObject* obj);
	SVariable*		iObj_get_toolTipText									 (SObject* obj);
	SVariable*		iObj_get_top											 (SObject* obj);
	SVariable*		iObj_get_topIndex										 (SObject* obj);
	SVariable*		iObj_get_topItemID										 (SObject* obj);
	SVariable*		iObj_get_userValue										 (SObject* obj);
	SVariable*		iObj_get_vScrollSmallChange								 (SObject* obj);
	SVariable*		iObj_get_value											 (SObject* obj);
	SVariable*		iObj_get_view											 (SObject* obj);
	SVariable*		iObj_get_viewPortHeight									 (SObject* obj);
	SVariable*		iObj_get_viewPortLeft									 (SObject* obj);
	SVariable*		iObj_get_viewPortTop									 (SObject* obj);
	SVariable*		iObj_get_viewPortWidth									 (SObject* obj);
	SVariable*		iObj_get_visible										 (SObject* obj);
	SVariable*		iObj_get_visualEffect									 (SObject* obj);
	SVariable*		iObj_get_whatsThisButton								 (SObject* obj);
	SVariable*		iObj_get_whatsThisHelp									 (SObject* obj);
	SVariable*		iObj_get_whatsThisHelpID								 (SObject* obj);
	SVariable*		iObj_get_width											 (SObject* obj);
	SVariable*		iObj_get_windowList										 (SObject* obj);
	SVariable*		iObj_get_windowState									 (SObject* obj);
	SVariable*		iObj_get_windowType										 (SObject* obj);
	SVariable*		iObj_get_wordWrap										 (SObject* obj);
	SVariable*		iObj_get_zoomBox										 (SObject* obj);


	struct SPropertyInits
	{
		cs8*		prop;								// Property
		u32			length;								// Length of the property name
		s32			objType;							// What is the object type if not a bitmap?

		// Default values
		union {
			u32		default_u32;
			f64		default_f64;
			f32		default_f32;
			s64		default_s64;
			s32		default_s32;
			s16		default_s16;
			s8		default_s8;
			u64		default_u64;
			u16		default_u16;
			u8		default_u8;
			s8*		default_data_s8;
			u8*		default_data_u8;
		};
	};

	// Initialization parameters
	SPropertyInits gsInitialization[] =
	{
		{	cgc_activeColumn,				sizeof(cgc_activeColumn) - 1,				_VAR_TYPE_S32,			0	},
		{	cgc_activeControl,				sizeof(cgc_activeControl) - 1,				_VAR_TYPE_OBJECT,		NULL	},
		{	cgc_activeForm,					sizeof(cgc_activeForm) - 1,					_VAR_TYPE_OBJECT,		NULL	},
		{	cgc_activePage,					sizeof(cgc_activePage) - 1,					_VAR_TYPE_S32,			0	},
		{	cgc_activeRow,					sizeof(cgc_activeRow) - 1,					_VAR_TYPE_S32,			0	},
		{	cgc_addLineFeeds,				sizeof(cgc_addLineFeeds) - 1,				_VAR_TYPE_LOGICAL,		1	},						// .t.=yes (default), .f.=no
		{	cgc_align,						sizeof(cgc_align) - 1,						_VAR_TYPE_S32,			0	},						// 0=Standard alignment, 1=top, 2=bottom, 3=left, 4=right
		{	cgc_alignment,					sizeof(cgc_alignment) - 1,					_VAR_TYPE_S32,			0	},						// 0=vertical left, 1=vertical right, 2=centered, 4=top left, 5=top right, 6=top center, 7=bottom left, 8=bottom right, 9=bottom center
		{	cgc_allowAddNew,				sizeof(cgc_allowAddNew) - 1,				_VAR_TYPE_LOGICAL,		0	},						// .t.=yes, .f.=no (default)
		{	cgc_allowAutoColumnFit,			sizeof(cgc_allowAutoColumnFit) - 1,			_VAR_TYPE_S32,			0	},						// 0=all automatically, 1=individual columns, 2=disabled
		{	cgc_allowCellSelection,			sizeof(cgc_allowCellSelection) - 1,			_VAR_TYPE_LOGICAL,		1	},						// .t.=yes (default), .f.=no
		{	cgc_allowHeaderSizing,			sizeof(cgc_allowHeaderSizing) - 1,			_VAR_TYPE_LOGICAL,		1	},						// .t.=yes (default), .f.=no
		{	cgc_allowOutput,				sizeof(cgc_allowOutput) - 1,				_VAR_TYPE_LOGICAL,		1	},						// .t.=yes (default), .f.=no
		{	cgc_allowRowSizing,				sizeof(cgc_allowRowSizing) - 1,				_VAR_TYPE_LOGICAL,		1	},						// .t.=yes (default), .f.=no
		{	cgc_allowTabs,					sizeof(cgc_allowTabs) - 1,					_VAR_TYPE_LOGICAL,		1	},						// .t.=yes, .f.=no (default) (in editboxes)
		{	cgc_alwaysOnBottom,				sizeof(cgc_alwaysOnBottom) - 1,				_VAR_TYPE_LOGICAL,		1	},						// .t.=yes, .f.=no (default)
		{	cgc_alwaysOnTop,				sizeof(cgc_alwaysOnTop) - 1,				_VAR_TYPE_LOGICAL,		1	},						// .t.=yes, .f.=no (default)
		{	cgc_anchor,						sizeof(cgc_anchor) - 1,						_VAR_TYPE_S32,			0	},						// 0=top left (default), 1=top absolute, 2=left absolute, 4=bottom absolute, 8=right absolute, 16=top relative, 32=left relative, 64=bottom relative, 128=right relative, 256=horizontal fixed, 512=vertical fixed
		{	cgc_application,				sizeof(cgc_application) - 1,				_VAR_TYPE_OBJECT,		NULL	},
		{	cgc_autoActivate,				sizeof(cgc_autoActivate) - 1,				_VAR_TYPE_S32,			0	},						// 0=manual, 1=got focus, 2=double click (default), 3=automatic
		{	cgc_autoCenter,					sizeof(cgc_autoCenter) - 1,					_VAR_TYPE_LOGICAL,		0	},						// .t.=yes, .f.=no (default)
		{	cgc_autoCompSource,				sizeof(cgc_autoCompSource) - 1,				_VAR_TYPE_CHARACTER,	(u32)&cgcEmptyString[0]	},	// Field to track for auto complete
		{	cgc_autoCompTable,				sizeof(cgc_autoCompTable) - 1,				_VAR_TYPE_CHARACTER,	(u32)&cgcEmptyString[0]	},	// Table to for auto complete
		{	cgc_autoComplete,				sizeof(cgc_autoComplete) - 1,				_VAR_TYPE_S32,			0	},						// 0=no display, 1=alphabetical, 2=most frequent, 3=most recent, 4=custom weighting
		{	cgc_autoHideScrollBar,			sizeof(cgc_autoHideScrollBar) - 1,			_VAR_TYPE_S32,			0	},						// 0=no (default), 1=yes
		{	cgc_autoRelease,				sizeof(cgc_autoRelease) - 1,				_VAR_TYPE_CHARACTER,	1	},						// .t.=released when last form is released, .f.=persists even after last form is released (in formsets)
		{	cgc_autoSize,					sizeof(cgc_autoSize) - 1,					_VAR_TYPE_S32,			0	},
		{	cgc_autoVerbMenu,				sizeof(cgc_autoVerbMenu) - 1,				_VAR_TYPE_S32,			0	},
		{	cgc_backColor,					sizeof(cgc_backColor) - 1,					_VAR_TYPE_S32,			0	},
		{	cgc_backStyle,					sizeof(cgc_backStyle) - 1,					_VAR_TYPE_S32,			0	},
		{	cgc_baseClass,					sizeof(cgc_baseClass) - 1,					_VAR_TYPE_S32,			0	},
		{	cgc_bindControls,				sizeof(cgc_bindControls) - 1,				_VAR_TYPE_S32,			0	},
		{	cgc_borderColor,				sizeof(cgc_borderColor) - 1,				_VAR_TYPE_S32,			0	},
		{	cgc_borderStyle,				sizeof(cgc_borderStyle) - 1,				_VAR_TYPE_S32,			0	},
		{	cgc_borderWidth,				sizeof(cgc_borderWidth) - 1,				_VAR_TYPE_S32,			0	},
		{	cgc_bound,						sizeof(cgc_bound) - 1,						_VAR_TYPE_S32,			0	},
		{	cgc_boundColumn,				sizeof(cgc_boundColumn) - 1,				_VAR_TYPE_S32,			0	},
		{	cgc_boundTo,					sizeof(cgc_boundTo) - 1,					_VAR_TYPE_S32,			0	},
		{	cgc_bufferMode,					sizeof(cgc_bufferMode) - 1,					_VAR_TYPE_S32,			0	},
		{	cgc_buttonCount,				sizeof(cgc_buttonCount) - 1,				_VAR_TYPE_S32,			0	},
		{	cgc_cancel,						sizeof(cgc_cancel) - 1,						_VAR_TYPE_S32,			0	},
		{	cgc_caption,					sizeof(cgc_caption) - 1,					_VAR_TYPE_S32,			0	},
		{	cgc_centered,					sizeof(cgc_centered) - 1,					_VAR_TYPE_S32,			0	},
		{	cgc_century,					sizeof(cgc_century) - 1,					_VAR_TYPE_S32,			0	},
		{	cgc_childOrder,					sizeof(cgc_childOrder) - 1,					_VAR_TYPE_S32,			0	},
		{	cgc_class,						sizeof(cgc_class) - 1,						_VAR_TYPE_S32,			0	},
		{	cgc_classLibrary,				sizeof(cgc_classLibrary) - 1,				_VAR_TYPE_S32,			0	},
		{	cgc_clipControls,				sizeof(cgc_clipControls) - 1,				_VAR_TYPE_S32,			0	},
		{	cgc_closable,					sizeof(cgc_closable) - 1,					_VAR_TYPE_S32,			0	},
		{	cgc_colorScheme,				sizeof(cgc_colorScheme) - 1,				_VAR_TYPE_S32,			0	},
		{	cgc_colorSource,				sizeof(cgc_colorSource) - 1,				_VAR_TYPE_S32,			0	},
		{	cgc_columnCount,				sizeof(cgc_columnCount) - 1,				_VAR_TYPE_S32,			0	},
		{	cgc_columnLines,				sizeof(cgc_columnLines) - 1,				_VAR_TYPE_S32,			0	},
		{	cgc_columnOrder,				sizeof(cgc_columnOrder) - 1,				_VAR_TYPE_S32,			0	},
		{	cgc_columnWidths,				sizeof(cgc_columnWidths) - 1,				_VAR_TYPE_S32,			0	},
		{	cgc_columns,					sizeof(cgc_columns) - 1,					_VAR_TYPE_S32,			0	},
		{	cgc_comment,					sizeof(cgc_comment) - 1,					_VAR_TYPE_S32,			0	},
		{	cgc_continuousScroll,			sizeof(cgc_continuousScroll) - 1,			_VAR_TYPE_S32,			0	},
		{	cgc_controlBox,					sizeof(cgc_controlBox) - 1,					_VAR_TYPE_S32,			0	},
		{	cgc_controlCount,				sizeof(cgc_controlCount) - 1,				_VAR_TYPE_S32,			0	},
		{	cgc_controlSource,				sizeof(cgc_controlSource) - 1,				_VAR_TYPE_S32,			0	},
		{	cgc_controls,					sizeof(cgc_controls) - 1,					_VAR_TYPE_S32,			0	},
		{	cgc_count,						sizeof(cgc_count) - 1,						_VAR_TYPE_S32,			0	},
		{	cgc_currentControl,				sizeof(cgc_currentControl) - 1,				_VAR_TYPE_S32,			0	},
		{	cgc_currentX,					sizeof(cgc_currentX) - 1,					_VAR_TYPE_S32,			0	},
		{	cgc_currentY,					sizeof(cgc_currentY) - 1,					_VAR_TYPE_S32,			0	},
		{	cgc_curvature,					sizeof(cgc_curvature) - 1,					_VAR_TYPE_S32,			0	},
		{	cgc_dEClass,					sizeof(cgc_dEClass) - 1,					_VAR_TYPE_S32,			0	},
		{	cgc_dEClassLibrary,				sizeof(cgc_dEClassLibrary) - 1,				_VAR_TYPE_S32,			0	},
		{	cgc_dataEnvironment,			sizeof(cgc_dataEnvironment) - 1,			_VAR_TYPE_S32,			0	},
		{	cgc_dataSession,				sizeof(cgc_dataSession) - 1,				_VAR_TYPE_S32,			0	},
		{	cgc_dataSessionID,				sizeof(cgc_dataSessionID) - 1,				_VAR_TYPE_S32,			0	},
		{	cgc_dateFormat,					sizeof(cgc_dateFormat) - 1,					_VAR_TYPE_S32,			0	},
		{	cgc_dateMark,					sizeof(cgc_dateMark) - 1,					_VAR_TYPE_S32,			0	},
		{	cgc_defOLELCID,					sizeof(cgc_defOLELCID) - 1,					_VAR_TYPE_S32,			0	},
		{	cgc_default,					sizeof(cgc_default) - 1,					_VAR_TYPE_S32,			0	},
		{	cgc_deleteMark,					sizeof(cgc_deleteMark) - 1,					_VAR_TYPE_S32,			0	},
		{	cgc_desktop,					sizeof(cgc_desktop) - 1,					_VAR_TYPE_S32,			0	},
		{	cgc_details,					sizeof(cgc_details) - 1,					_VAR_TYPE_S32,			0	},
		{	cgc_disabledBackColor,			sizeof(cgc_disabledBackColor) - 1,			_VAR_TYPE_S32,			0	},
		{	cgc_disabledForeColor,			sizeof(cgc_disabledForeColor) - 1,			_VAR_TYPE_S32,			0	},
		{	cgc_disabledItemBackColor,		sizeof(cgc_disabledItemBackColor) - 1,		_VAR_TYPE_S32,			0	},
		{	cgc_disabledItemForeColor,		sizeof(cgc_disabledItemForeColor) - 1,		_VAR_TYPE_S32,			0	},
		{	cgc_disabledPicture,			sizeof(cgc_disabledPicture) - 1,			_VAR_TYPE_S32,			0	},
		{	cgc_displayCount,				sizeof(cgc_displayCount) - 1,				_VAR_TYPE_S32,			0	},
		{	cgc_displayValue,				sizeof(cgc_displayValue) - 1,				_VAR_TYPE_S32,			0	},
		{	cgc_doCreate,					sizeof(cgc_doCreate) - 1,					_VAR_TYPE_S32,			0	},
		{	cgc_dockPosition,				sizeof(cgc_dockPosition) - 1,				_VAR_TYPE_S32,			0	},
		{	cgc_dockable,					sizeof(cgc_dockable) - 1,					_VAR_TYPE_S32,			0	},
		{	cgc_docked,						sizeof(cgc_docked) - 1,						_VAR_TYPE_S32,			0	},
		{	cgc_documentFile,				sizeof(cgc_documentFile) - 1,				_VAR_TYPE_S32,			0	},
		{	cgc_downPicture,				sizeof(cgc_downPicture) - 1,				_VAR_TYPE_S32,			0	},
		{	cgc_dragIcon,					sizeof(cgc_dragIcon) - 1,					_VAR_TYPE_S32,			0	},
		{	cgc_dragMode,					sizeof(cgc_dragMode) - 1,					_VAR_TYPE_S32,			0	},
		{	cgc_drawMode,					sizeof(cgc_drawMode) - 1,					_VAR_TYPE_S32,			0	},
		{	cgc_drawStyle,					sizeof(cgc_drawStyle) - 1,					_VAR_TYPE_S32,			0	},
		{	cgc_drawWidth,					sizeof(cgc_drawWidth) - 1,					_VAR_TYPE_S32,			0	},
		{	cgc_dynamicAlignment,			sizeof(cgc_dynamicAlignment) - 1,			_VAR_TYPE_S32,			0	},
		{	cgc_dynamicBackColor,			sizeof(cgc_dynamicBackColor) - 1,			_VAR_TYPE_S32,			0	},
		{	cgc_dynamicCurrentControl,		sizeof(cgc_dynamicCurrentControl) - 1,		_VAR_TYPE_S32,			0	},
		{	cgc_dynamicFontBold,			sizeof(cgc_dynamicFontBold) - 1,			_VAR_TYPE_S32,			0	},
		{	cgc_dynamicFontItalic,			sizeof(cgc_dynamicFontItalic) - 1,			_VAR_TYPE_S32,			0	},
		{	cgc_dynamicFontName,			sizeof(cgc_dynamicFontName) - 1,			_VAR_TYPE_S32,			0	},
		{	cgc_dynamicFontOutline,			sizeof(cgc_dynamicFontOutline) - 1,			_VAR_TYPE_S32,			0	},
		{	cgc_dynamicFontShadow,			sizeof(cgc_dynamicFontShadow) - 1,			_VAR_TYPE_S32,			0	},
		{	cgc_dynamicFontSize,			sizeof(cgc_dynamicFontSize) - 1,			_VAR_TYPE_S32,			0	},
		{	cgc_dynamicFontStrikeThru,		sizeof(cgc_dynamicFontStrikeThru) - 1,		_VAR_TYPE_S32,			0	},
		{	cgc_dynamicFontUnderline,		sizeof(cgc_dynamicFontUnderline) - 1,		_VAR_TYPE_S32,			0	},
		{	cgc_dynamicForeColor,			sizeof(cgc_dynamicForeColor) - 1,			_VAR_TYPE_S32,			0	},
		{	cgc_dynamicInputMask,			sizeof(cgc_dynamicInputMask) - 1,			_VAR_TYPE_S32,			0	},
		{	cgc_enableHyperlinks,			sizeof(cgc_enableHyperlinks) - 1,			_VAR_TYPE_S32,			0	},
		{	cgc_enabled,					sizeof(cgc_enabled) - 1,					_VAR_TYPE_S32,			0	},
		{	cgc_errorNo,					sizeof(cgc_errorNo) - 1,					_VAR_TYPE_S32,			0	},
		{	cgc_fillColor,					sizeof(cgc_fillColor) - 1,					_VAR_TYPE_S32,			0	},
		{	cgc_fillStyle,					sizeof(cgc_fillStyle) - 1,					_VAR_TYPE_S32,			0	},
		{	cgc_firstElement,				sizeof(cgc_firstElement) - 1,				_VAR_TYPE_S32,			0	},
		{	cgc_fontBold,					sizeof(cgc_fontBold) - 1,					_VAR_TYPE_S32,			0	},
		{	cgc_fontCharSet,				sizeof(cgc_fontCharSet) - 1,				_VAR_TYPE_S32,			0	},
		{	cgc_fontCondense,				sizeof(cgc_fontCondense) - 1,				_VAR_TYPE_S32,			0	},
		{	cgc_fontExtend,					sizeof(cgc_fontExtend) - 1,					_VAR_TYPE_S32,			0	},
		{	cgc_fontItalic,					sizeof(cgc_fontItalic) - 1,					_VAR_TYPE_S32,			0	},
		{	cgc_fontName,					sizeof(cgc_fontName) - 1,					_VAR_TYPE_S32,			0	},
		{	cgc_fontOutline,				sizeof(cgc_fontOutline) - 1,				_VAR_TYPE_S32,			0	},
		{	cgc_fontShadow,					sizeof(cgc_fontShadow) - 1,					_VAR_TYPE_S32,			0	},
		{	cgc_fontSize,					sizeof(cgc_fontSize) - 1,					_VAR_TYPE_S32,			0	},
		{	cgc_fontStrikeThru,				sizeof(cgc_fontStrikeThru) - 1,				_VAR_TYPE_S32,			0	},
		{	cgc_fontUnderLine,				sizeof(cgc_fontUnderLine) - 1,				_VAR_TYPE_S32,			0	},
		{	cgc_fontUnderline,				sizeof(cgc_fontUnderline) - 1,				_VAR_TYPE_S32,			0	},
		{	cgc_foreColor,					sizeof(cgc_foreColor) - 1,					_VAR_TYPE_S32,			0	},
		{	cgc_formCount,					sizeof(cgc_formCount) - 1,					_VAR_TYPE_S32,			0	},
		{	cgc_format,						sizeof(cgc_format) - 1,						_VAR_TYPE_S32,			0	},
		{	cgc_forms,						sizeof(cgc_forms) - 1,						_VAR_TYPE_S32,			0	},
		{	cgc_gridLineColor,				sizeof(cgc_gridLineColor) - 1,				_VAR_TYPE_S32,			0	},
		{	cgc_gridLineWidth,				sizeof(cgc_gridLineWidth) - 1,				_VAR_TYPE_S32,			0	},
		{	cgc_gridLines,					sizeof(cgc_gridLines) - 1,					_VAR_TYPE_S32,			0	},
		{	cgc_hScrollSmallChange,			sizeof(cgc_hScrollSmallChange) - 1,			_VAR_TYPE_S32,			0	},
		{	cgc_hWnd,						sizeof(cgc_hWnd) - 1,						_VAR_TYPE_S32,			0	},
		{	cgc_halfHeightCaption,			sizeof(cgc_halfHeightCaption) - 1,			_VAR_TYPE_S32,			0	},
		{	cgc_headerClass,				sizeof(cgc_headerClass) - 1,				_VAR_TYPE_S32,			0	},
		{	cgc_headerClassLibrary,			sizeof(cgc_headerClassLibrary) - 1,			_VAR_TYPE_S32,			0	},
		{	cgc_headerHeight,				sizeof(cgc_headerHeight) - 1,				_VAR_TYPE_S32,			0	},
		{	cgc_height,						sizeof(cgc_height) - 1,						_VAR_TYPE_S32,			0	},
		{	cgc_helpContextID,				sizeof(cgc_helpContextID) - 1,				_VAR_TYPE_S32,			0	},
		{	cgc_hideSelection,				sizeof(cgc_hideSelection) - 1,				_VAR_TYPE_S32,			0	},
		{	cgc_highLight,					sizeof(cgc_highLight) - 1,					_VAR_TYPE_S32,			0	},
		{	cgc_highLightRow,				sizeof(cgc_highLightRow) - 1,				_VAR_TYPE_S32,			0	},
		{	cgc_highlightBackColor,			sizeof(cgc_highlightBackColor) - 1,			_VAR_TYPE_S32,			0	},
		{	cgc_highlightForeColor,			sizeof(cgc_highlightForeColor) - 1,			_VAR_TYPE_S32,			0	},
		{	cgc_highlightRowLineWidth,		sizeof(cgc_highlightRowLineWidth) - 1,		_VAR_TYPE_S32,			0	},
		{	cgc_highlightStyle,				sizeof(cgc_highlightStyle) - 1,				_VAR_TYPE_S32,			0	},
		{	cgc_hostName,					sizeof(cgc_hostName) - 1,					_VAR_TYPE_S32,			0	},
		{	cgc_hours,						sizeof(cgc_hours) - 1,						_VAR_TYPE_S32,			0	},
		{	cgc_iMEMode,					sizeof(cgc_iMEMode) - 1,					_VAR_TYPE_S32,			0	},
		{	cgc_increment,					sizeof(cgc_increment) - 1,					_VAR_TYPE_S32,			0	},
		{	cgc_incrementalSearch,			sizeof(cgc_incrementalSearch) - 1,			_VAR_TYPE_S32,			0	},
		{	cgc_inputMask,					sizeof(cgc_inputMask) - 1,					_VAR_TYPE_S32,			0	},
		{	cgc_integralHeight,				sizeof(cgc_integralHeight) - 1,				_VAR_TYPE_S32,			0	},
		{	cgc_interval,					sizeof(cgc_interval) - 1,					_VAR_TYPE_S32,			0	},
		{	cgc_itemBackColor,				sizeof(cgc_itemBackColor) - 1,				_VAR_TYPE_S32,			0	},
		{	cgc_itemData,					sizeof(cgc_itemData) - 1,					_VAR_TYPE_S32,			0	},
		{	cgc_itemForeColor,				sizeof(cgc_itemForeColor) - 1,				_VAR_TYPE_S32,			0	},
		{	cgc_itemIDData,					sizeof(cgc_itemIDData) - 1,					_VAR_TYPE_S32,			0	},
		{	cgc_itemTips,					sizeof(cgc_itemTips) - 1,					_VAR_TYPE_S32,			0	},
		{	cgc_keyPreview,					sizeof(cgc_keyPreview) - 1,					_VAR_TYPE_S32,			0	},
		{	cgc_keySort,					sizeof(cgc_keySort) - 1,					_VAR_TYPE_S32,			0	},
		{	cgc_keyboardHighValue,			sizeof(cgc_keyboardHighValue) - 1,			_VAR_TYPE_S32,			0	},
		{	cgc_keyboardLowValue,			sizeof(cgc_keyboardLowValue) - 1,			_VAR_TYPE_S32,			0	},
		{	cgc_left,						sizeof(cgc_left) - 1,						_VAR_TYPE_S32,			0	},
		{	cgc_leftColumn,					sizeof(cgc_leftColumn) - 1,					_VAR_TYPE_S32,			0	},
		{	cgc_lineContents,				sizeof(cgc_lineContents) - 1,				_VAR_TYPE_S32,			0	},
		{	cgc_lineNo,						sizeof(cgc_lineNo) - 1,						_VAR_TYPE_S32,			0	},
		{	cgc_lineSlant,					sizeof(cgc_lineSlant) - 1,					_VAR_TYPE_S32,			0	},
		{	cgc_linkMaster,					sizeof(cgc_linkMaster) - 1,					_VAR_TYPE_S32,			0	},
		{	cgc_list,						sizeof(cgc_list) - 1,						_VAR_TYPE_S32,			0	},
		{	cgc_listCount,					sizeof(cgc_listCount) - 1,					_VAR_TYPE_S32,			0	},
		{	cgc_listIndex,					sizeof(cgc_listIndex) - 1,					_VAR_TYPE_S32,			0	},
		{	cgc_listItem,					sizeof(cgc_listItem) - 1,					_VAR_TYPE_S32,			0	},
		{	cgc_listItemID,					sizeof(cgc_listItemID) - 1,					_VAR_TYPE_S32,			0	},
		{	cgc_lockColumns,				sizeof(cgc_lockColumns) - 1,				_VAR_TYPE_S32,			0	},
		{	cgc_lockColumnsLeft,			sizeof(cgc_lockColumnsLeft) - 1,			_VAR_TYPE_S32,			0	},
		{	cgc_lockScreen,					sizeof(cgc_lockScreen) - 1,					_VAR_TYPE_S32,			0	},
		{	cgc_mDIForm,					sizeof(cgc_mDIForm) - 1,					_VAR_TYPE_S32,			0	},
		{	cgc_macDesktop,					sizeof(cgc_macDesktop) - 1,					_VAR_TYPE_S32,			0	},
		{	cgc_margin,						sizeof(cgc_margin) - 1,						_VAR_TYPE_S32,			0	},
		{	cgc_maxButton,					sizeof(cgc_maxButton) - 1,					_VAR_TYPE_S32,			0	},
		{	cgc_maxHeight,					sizeof(cgc_maxHeight) - 1,					_VAR_TYPE_S32,			0	},
		{	cgc_maxLeft,					sizeof(cgc_maxLeft) - 1,					_VAR_TYPE_S32,			0	},
		{	cgc_maxLength,					sizeof(cgc_maxLength) - 1,					_VAR_TYPE_S32,			0	},
		{	cgc_maxTop,						sizeof(cgc_maxTop) - 1,						_VAR_TYPE_S32,			0	},
		{	cgc_maxWidth,					sizeof(cgc_maxWidth) - 1,					_VAR_TYPE_S32,			0	},
		{	cgc_memberClass,				sizeof(cgc_memberClass) - 1,				_VAR_TYPE_S32,			0	},
		{	cgc_memberClassLibrary,			sizeof(cgc_memberClassLibrary) - 1,			_VAR_TYPE_S32,			0	},
		{	cgc_memoWindow,					sizeof(cgc_memoWindow) - 1,					_VAR_TYPE_S32,			0	},
		{	cgc_message,					sizeof(cgc_message) - 1,					_VAR_TYPE_S32,			0	},
		{	cgc_minButton,					sizeof(cgc_minButton) - 1,					_VAR_TYPE_S32,			0	},
		{	cgc_minHeight,					sizeof(cgc_minHeight) - 1,					_VAR_TYPE_S32,			0	},
		{	cgc_minWidth,					sizeof(cgc_minWidth) - 1,					_VAR_TYPE_S32,			0	},
		{	cgc_mousePointer,				sizeof(cgc_mousePointer) - 1,				_VAR_TYPE_S32,			0	},
		{	cgc_movable,					sizeof(cgc_movable) - 1,					_VAR_TYPE_S32,			0	},
		{	cgc_moverBars,					sizeof(cgc_moverBars) - 1,					_VAR_TYPE_S32,			0	},
		{	cgc_multiSelect,				sizeof(cgc_multiSelect) - 1,				_VAR_TYPE_S32,			0	},
		{	cgc_name,						sizeof(cgc_name) - 1,						_VAR_TYPE_S32,			0	},
		{	cgc_newIndex,					sizeof(cgc_newIndex) - 1,					_VAR_TYPE_S32,			0	},
		{	cgc_newItemID,					sizeof(cgc_newItemID) - 1,					_VAR_TYPE_S32,			0	},
		{	cgc_nullDisplay,				sizeof(cgc_nullDisplay) - 1,				_VAR_TYPE_S32,			0	},
		{	cgc_numberOfElements,			sizeof(cgc_numberOfElements) - 1,			_VAR_TYPE_S32,			0	},
		{	cgc_oLEClass,					sizeof(cgc_oLEClass) - 1,					_VAR_TYPE_S32,			0	},
		{	cgc_oLEDragMode,				sizeof(cgc_oLEDragMode) - 1,				_VAR_TYPE_S32,			0	},
		{	cgc_oLEDropEffects,				sizeof(cgc_oLEDropEffects) - 1,				_VAR_TYPE_S32,			0	},
		{	cgc_oLEDropHasData,				sizeof(cgc_oLEDropHasData) - 1,				_VAR_TYPE_S32,			0	},
		{	cgc_oLEDropMode,				sizeof(cgc_oLEDropMode) - 1,				_VAR_TYPE_S32,			0	},
		{	cgc_oLEDropTextInsertion,		sizeof(cgc_oLEDropTextInsertion) - 1,		_VAR_TYPE_S32,			0	},
		{	cgc_oLELCID,					sizeof(cgc_oLELCID) - 1,					_VAR_TYPE_S32,			0	},
		{	cgc_oLETypeAllowed,				sizeof(cgc_oLETypeAllowed) - 1,				_VAR_TYPE_S32,			0	},
		{	cgc_object,						sizeof(cgc_object) - 1,						_VAR_TYPE_S32,			0	},
		{	cgc_objects,					sizeof(cgc_objects) - 1,					_VAR_TYPE_S32,			0	},
		{	cgc_openWindow,					sizeof(cgc_openWindow) - 1,					_VAR_TYPE_S32,			0	},
		{	cgc_optimize,					sizeof(cgc_optimize) - 1,					_VAR_TYPE_S32,			0	},
		{	cgc_pageCount,					sizeof(cgc_pageCount) - 1,					_VAR_TYPE_S32,			0	},
		{	cgc_pageHeight,					sizeof(cgc_pageHeight) - 1,					_VAR_TYPE_S32,			0	},
		{	cgc_pageOrder,					sizeof(cgc_pageOrder) - 1,					_VAR_TYPE_S32,			0	},
		{	cgc_pageWidth,					sizeof(cgc_pageWidth) - 1,					_VAR_TYPE_S32,			0	},
		{	cgc_pages,						sizeof(cgc_pages) - 1,						_VAR_TYPE_S32,			0	},
		{	cgc_panel,						sizeof(cgc_panel) - 1,						_VAR_TYPE_S32,			0	},
		{	cgc_panelLink,					sizeof(cgc_panelLink) - 1,					_VAR_TYPE_S32,			0	},
		{	cgc_parent,						sizeof(cgc_parent) - 1,						_VAR_TYPE_S32,			0	},
		{	cgc_parentClass,				sizeof(cgc_parentClass) - 1,				_VAR_TYPE_S32,			0	},
		{	cgc_partition,					sizeof(cgc_partition) - 1,					_VAR_TYPE_S32,			0	},
		{	cgc_passwordChar,				sizeof(cgc_passwordChar) - 1,				_VAR_TYPE_S32,			0	},
		{	cgc_picture,					sizeof(cgc_picture) - 1,					_VAR_TYPE_S32,			0	},
		{	cgc_pictureMargin,				sizeof(cgc_pictureMargin) - 1,				_VAR_TYPE_S32,			0	},
		{	cgc_picturePosition,			sizeof(cgc_picturePosition) - 1,			_VAR_TYPE_S32,			0	},
		{	cgc_pictureSelectionDisplay,	sizeof(cgc_pictureSelectionDisplay) - 1,	_VAR_TYPE_S32,			0	},
		{	cgc_pictureSpacing,				sizeof(cgc_pictureSpacing) - 1,				_VAR_TYPE_S32,			0	},
		{	cgc_pictureVal,					sizeof(cgc_pictureVal) - 1,					_VAR_TYPE_S32,			0	},
		{	cgc_polyPoints,					sizeof(cgc_polyPoints) - 1,					_VAR_TYPE_S32,			0	},
		{	cgc_procedure,					sizeof(cgc_procedure) - 1,					_VAR_TYPE_S32,			0	},
		{	cgc_readBackColor,				sizeof(cgc_readBackColor) - 1,				_VAR_TYPE_S32,			0	},
		{	cgc_readCycle,					sizeof(cgc_readCycle) - 1,					_VAR_TYPE_S32,			0	},
		{	cgc_readForeColor,				sizeof(cgc_readForeColor) - 1,				_VAR_TYPE_S32,			0	},
		{	cgc_readLock,					sizeof(cgc_readLock) - 1,					_VAR_TYPE_S32,			0	},
		{	cgc_readMouse,					sizeof(cgc_readMouse) - 1,					_VAR_TYPE_S32,			0	},
		{	cgc_readOnly,					sizeof(cgc_readOnly) - 1,					_VAR_TYPE_S32,			0	},
		{	cgc_readSave,					sizeof(cgc_readSave) - 1,					_VAR_TYPE_S32,			0	},
		{	cgc_readTimeOut,				sizeof(cgc_readTimeOut) - 1,				_VAR_TYPE_S32,			0	},
		{	cgc_recordMark,					sizeof(cgc_recordMark) - 1,					_VAR_TYPE_S32,			0	},
		{	cgc_recordSource,				sizeof(cgc_recordSource) - 1,				_VAR_TYPE_S32,			0	},
		{	cgc_recordSourceType,			sizeof(cgc_recordSourceType) - 1,			_VAR_TYPE_S32,			0	},
		{	cgc_relationalExpr,				sizeof(cgc_relationalExpr) - 1,				_VAR_TYPE_S32,			0	},
		{	cgc_relativeColumn,				sizeof(cgc_relativeColumn) - 1,				_VAR_TYPE_S32,			0	},
		{	cgc_relativeRow,				sizeof(cgc_relativeRow) - 1,				_VAR_TYPE_S32,			0	},
		{	cgc_releaseType,				sizeof(cgc_releaseType) - 1,				_VAR_TYPE_S32,			0	},
		{	cgc_resizable,					sizeof(cgc_resizable) - 1,					_VAR_TYPE_S32,			0	},
		{	cgc_rightToLeft,				sizeof(cgc_rightToLeft) - 1,				_VAR_TYPE_S32,			0	},
		{	cgc_rotateFlip,					sizeof(cgc_rotateFlip) - 1,					_VAR_TYPE_S32,			0	},
		{	cgc_rotation,					sizeof(cgc_rotation) - 1,					_VAR_TYPE_S32,			0	},
		{	cgc_rowColChange,				sizeof(cgc_rowColChange) - 1,				_VAR_TYPE_S32,			0	},
		{	cgc_rowHeight,					sizeof(cgc_rowHeight) - 1,					_VAR_TYPE_S32,			0	},
		{	cgc_rowSource,					sizeof(cgc_rowSource) - 1,					_VAR_TYPE_S32,			0	},
		{	cgc_rowSourceType,				sizeof(cgc_rowSourceType) - 1,				_VAR_TYPE_S32,			0	},
		{	cgc_scaleMode,					sizeof(cgc_scaleMode) - 1,					_VAR_TYPE_S32,			0	},
		{	cgc_scrollBars,					sizeof(cgc_scrollBars) - 1,					_VAR_TYPE_S32,			0	},
		{	cgc_seconds,					sizeof(cgc_seconds) - 1,					_VAR_TYPE_S32,			0	},
		{	cgc_selLength,					sizeof(cgc_selLength) - 1,					_VAR_TYPE_S32,			0	},
		{	cgc_selStart,					sizeof(cgc_selStart) - 1,					_VAR_TYPE_S32,			0	},
		{	cgc_selText,					sizeof(cgc_selText) - 1,					_VAR_TYPE_S32,			0	},
		{	cgc_selectOnEntry,				sizeof(cgc_selectOnEntry) - 1,				_VAR_TYPE_S32,			0	},
		{	cgc_selected,					sizeof(cgc_selected) - 1,					_VAR_TYPE_S32,			0	},
		{	cgc_selectedBackColor,			sizeof(cgc_selectedBackColor) - 1,			_VAR_TYPE_S32,			0	},
		{	cgc_selectedForeColor,			sizeof(cgc_selectedForeColor) - 1,			_VAR_TYPE_S32,			0	},
		{	cgc_selectedID,					sizeof(cgc_selectedID) - 1,					_VAR_TYPE_S32,			0	},
		{	cgc_selectedItemBackColor,		sizeof(cgc_selectedItemBackColor) - 1,		_VAR_TYPE_S32,			0	},
		{	cgc_selectedItemForeColor,		sizeof(cgc_selectedItemForeColor) - 1,		_VAR_TYPE_S32,			0	},
		{	cgc_showInTaskbar,				sizeof(cgc_showInTaskbar) - 1,				_VAR_TYPE_S32,			0	},
		{	cgc_showTips,					sizeof(cgc_showTips) - 1,					_VAR_TYPE_S32,			0	},
		{	cgc_showWindow,					sizeof(cgc_showWindow) - 1,					_VAR_TYPE_S32,			0	},
		{	cgc_sizable,					sizeof(cgc_sizable) - 1,					_VAR_TYPE_S32,			0	},
		{	cgc_sizeBox,					sizeof(cgc_sizeBox) - 1,					_VAR_TYPE_S32,			0	},
		{	cgc_sorted,						sizeof(cgc_sorted) - 1,						_VAR_TYPE_S32,			0	},
		{	cgc_sparse,						sizeof(cgc_sparse) - 1,						_VAR_TYPE_S32,			0	},
		{	cgc_specialEffect,				sizeof(cgc_specialEffect) - 1,				_VAR_TYPE_S32,			0	},
		{	cgc_spinnerHighValue,			sizeof(cgc_spinnerHighValue) - 1,			_VAR_TYPE_S32,			0	},
		{	cgc_spinnerLowValue,			sizeof(cgc_spinnerLowValue) - 1,			_VAR_TYPE_S32,			0	},
		{	cgc_splitBar,					sizeof(cgc_splitBar) - 1,					_VAR_TYPE_S32,			0	},
		{	cgc_stackLevel,					sizeof(cgc_stackLevel) - 1,					_VAR_TYPE_S32,			0	},
		{	cgc_statusBarText,				sizeof(cgc_statusBarText) - 1,				_VAR_TYPE_S32,			0	},
		{	cgc_stretch,					sizeof(cgc_stretch) - 1,					_VAR_TYPE_S32,			0	},
		{	cgc_strictDateEntry,			sizeof(cgc_strictDateEntry) - 1,			_VAR_TYPE_S32,			0	},
		{	cgc_style,						sizeof(cgc_style) - 1,						_VAR_TYPE_S32,			0	},
		{	cgc_tabIndex,					sizeof(cgc_tabIndex) - 1,					_VAR_TYPE_S32,			0	},
		{	cgc_tabOrientation,				sizeof(cgc_tabOrientation) - 1,				_VAR_TYPE_S32,			0	},
		{	cgc_tabStop,					sizeof(cgc_tabStop) - 1,					_VAR_TYPE_S32,			0	},
		{	cgc_tabStyle,					sizeof(cgc_tabStyle) - 1,					_VAR_TYPE_S32,			0	},
		{	cgc_tabs,						sizeof(cgc_tabs) - 1,						_VAR_TYPE_S32,			0	},
		{	cgc_tag,						sizeof(cgc_tag) - 1,						_VAR_TYPE_S32,			0	},
		{	cgc_terminateRead,				sizeof(cgc_terminateRead) - 1,				_VAR_TYPE_S32,			0	},
		{	cgc_text,						sizeof(cgc_text) - 1,						_VAR_TYPE_S32,			0	},
		{	cgc_themes,						sizeof(cgc_themes) - 1,						_VAR_TYPE_S32,			0	},
		{	cgc_titleBar,					sizeof(cgc_titleBar) - 1,					_VAR_TYPE_S32,			0	},
		{	cgc_toolTipText,				sizeof(cgc_toolTipText) - 1,				_VAR_TYPE_S32,			0	},
		{	cgc_top,						sizeof(cgc_top) - 1,						_VAR_TYPE_S32,			0	},
		{	cgc_topIndex,					sizeof(cgc_topIndex) - 1,					_VAR_TYPE_S32,			0	},
		{	cgc_topItemID,					sizeof(cgc_topItemID) - 1,					_VAR_TYPE_S32,			0	},
		{	cgc_userValue,					sizeof(cgc_userValue) - 1,					_VAR_TYPE_S32,			0	},
		{	cgc_vScrollSmallChange,			sizeof(cgc_vScrollSmallChange) - 1,			_VAR_TYPE_S32,			0	},
		{	cgc_value,						sizeof(cgc_value) - 1,						_VAR_TYPE_S32,			0	},
		{	cgc_view,						sizeof(cgc_view) - 1,						_VAR_TYPE_S32,			0	},
		{	cgc_viewPortHeight,				sizeof(cgc_viewPortHeight) - 1,				_VAR_TYPE_S32,			0	},
		{	cgc_viewPortLeft,				sizeof(cgc_viewPortLeft) - 1,				_VAR_TYPE_S32,			0	},
		{	cgc_viewPortTop,				sizeof(cgc_viewPortTop) - 1,				_VAR_TYPE_S32,			0	},
		{	cgc_viewPortWidth,				sizeof(cgc_viewPortWidth) - 1,				_VAR_TYPE_S32,			0	},
		{	cgc_visible,					sizeof(cgc_visible) - 1,					_VAR_TYPE_S32,			0	},
		{	cgc_visualEffect,				sizeof(cgc_visualEffect) - 1,				_VAR_TYPE_S32,			0	},
		{	cgc_whatsThisButton,			sizeof(cgc_whatsThisButton) - 1,			_VAR_TYPE_S32,			0	},
		{	cgc_whatsThisHelp,				sizeof(cgc_whatsThisHelp) - 1,				_VAR_TYPE_S32,			0	},
		{	cgc_whatsThisHelpID,			sizeof(cgc_whatsThisHelpID) - 1,			_VAR_TYPE_S32,			0	},
		{	cgc_width,						sizeof(cgc_width) - 1,						_VAR_TYPE_S32,			0	},
		{	cgc_windowList,					sizeof(cgc_windowList) - 1,					_VAR_TYPE_S32,			0	},
		{	cgc_windowState,				sizeof(cgc_windowState) - 1,				_VAR_TYPE_S32,			0	},
		{	cgc_windowType,					sizeof(cgc_windowType) - 1,					_VAR_TYPE_S32,			0	},
		{	cgc_wordWrap,					sizeof(cgc_wordWrap) - 1,					_VAR_TYPE_S32,			0	},
		{	cgc_zoomBox,					sizeof(cgc_zoomBox) - 1,					_VAR_TYPE_S32,			0	},

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
		union {
			cs8*		property;
			s8			property_s8;
		};
		u32			length;

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
		{	NULL,							0,											 0,										 0										 }
	};

	SPropertyMap gcProps_subform[] =
	{
		{	cgc_activeControl,				sizeof(cgc_activeControl) - 1,				 (u32)&iObj_set_activeControl,			 (u32)&iObj_get_activeControl				  },
		{	cgc_allowOutput,				sizeof(cgc_allowOutput) - 1,				 (u32)&iObj_set_allowOutput,			 (u32)&iObj_get_allowOutput					  },
		{	cgc_fillColor,					sizeof(cgc_fillColor) - 1,					 (u32)&iObj_set_fillColor,				 (u32)&iObj_get_fillColor					  },
		{	cgc_fillStyle,					sizeof(cgc_fillStyle) - 1,					 (u32)&iObj_set_fillStyle,				 (u32)&iObj_get_fillStyle					  },
		{	cgc_maxHeight,					sizeof(cgc_maxHeight) - 1,					 (u32)&iObj_set_maxHeight,				 (u32)&iObj_get_maxHeight					  },
		{	cgc_maxWidth,					sizeof(cgc_maxWidth) - 1,					 (u32)&iObj_set_maxWidth,				 (u32)&iObj_get_maxWidth					  },
		{	cgc_maxTop,						sizeof(cgc_maxTop) - 1,						 (u32)&iObj_set_maxTop,					 (u32)&iObj_get_maxTop						  },
		{	cgc_maxLeft,					sizeof(cgc_maxLeft) - 1,					 (u32)&iObj_set_maxLeft,				 (u32)&iObj_get_maxLeft						  },
		{	cgc_minHeight,					sizeof(cgc_minHeight) - 1,					 (u32)&iObj_set_minHeight,				 (u32)&iObj_get_minHeight					  },
		{	cgc_minWidth,					sizeof(cgc_minWidth) - 1,					 (u32)&iObj_set_minWidth,				 (u32)&iObj_get_minWidth					  },
		{	cgc_baseClass,					sizeof(cgc_baseClass) - 1,					 (u32)&iObj_set_baseClass,				 (u32)&iObj_get_baseClass					  },
		{	cgc_class,						sizeof(cgc_class) - 1,						 (u32)&iObj_set_class,					 (u32)&iObj_get_class						  },
		{	cgc_classLibrary,				sizeof(cgc_classLibrary) - 1,				 (u32)&iObj_set_classLibrary,			 (u32)&iObj_get_classLibrary				  },
		{	cgc_controls,					sizeof(cgc_controls) - 1,					 (u32)&iObj_set_controls,				 (u32)&iObj_get_controls					  },
		{	cgc_controlCount,				sizeof(cgc_controlCount) - 1,				 (u32)&iObj_set_controlCount,			 (u32)&iObj_get_controlCount				  },
		{	cgc_objects,					sizeof(cgc_objects) - 1,					 (u32)&iObj_set_objects,				 (u32)&iObj_get_objects						  },
		{	cgc_borderStyle,				sizeof(cgc_borderStyle) - 1,				 (u32)&iObj_set_borderStyle,			 (u32)&iObj_get_borderStyle					  },
		{	cgc_caption,					sizeof(cgc_caption) - 1,					 (u32)&iObj_set_caption,				 (u32)&iObj_get_caption						  },
		{	cgc_foreColor,					sizeof(cgc_foreColor) - 1,					 (u32)&iObj_set_foreColor,				 (u32)&iObj_get_foreColor					  },
		{	cgc_backColor,					sizeof(cgc_backColor) - 1,					 (u32)&iObj_set_backColor,				 (u32)&iObj_get_backColor					  },
		{	cgc_comment,					sizeof(cgc_comment) - 1,					 (u32)&iObj_set_comment,				 (u32)&iObj_get_comment						  },
		{	cgc_enabled,					sizeof(cgc_enabled) - 1,					 (u32)&iObj_set_enabled,				 (u32)&iObj_get_enabled						  },
		{	cgc_fontBold,					sizeof(cgc_fontBold) - 1,					 (u32)&iObj_set_fontBold,				 (u32)&iObj_get_fontBold					  },
		{	cgc_fontCharSet,				sizeof(cgc_fontCharSet) - 1,				 (u32)&iObj_set_fontCharSet,			 (u32)&iObj_get_fontCharSet					  },
		{	cgc_fontCondense,				sizeof(cgc_fontCondense) - 1,				 (u32)&iObj_set_fontCondense,			 (u32)&iObj_get_fontCondense				  },
		{	cgc_fontExtend,					sizeof(cgc_fontExtend) - 1,					 (u32)&iObj_set_fontExtend,				 (u32)&iObj_get_fontExtend					  },
		{	cgc_fontItalic,					sizeof(cgc_fontItalic) - 1,					 (u32)&iObj_set_fontItalic,				 (u32)&iObj_get_fontItalic					  },
		{	cgc_fontName,					sizeof(cgc_fontName) - 1,					 (u32)&iObj_set_fontName,				 (u32)&iObj_get_fontName					  },
		{	cgc_fontOutline,				sizeof(cgc_fontOutline) - 1,				 (u32)&iObj_set_fontOutline,			 (u32)&iObj_get_fontOutline					  },
		{	cgc_fontShadow,					sizeof(cgc_fontShadow) - 1,					 (u32)&iObj_set_fontShadow,				 (u32)&iObj_get_fontShadow					  },
		{	cgc_fontSize,					sizeof(cgc_fontSize) - 1,					 (u32)&iObj_set_fontSize,				 (u32)&iObj_get_fontSize					  },
		{	cgc_fontStrikeThru,				sizeof(cgc_fontStrikeThru) - 1,				 (u32)&iObj_set_fontStrikeThru,			 (u32)&iObj_get_fontStrikeThru				  },
		{	cgc_fontUnderline,				sizeof(cgc_fontUnderline) - 1,				 (u32)&iObj_set_fontUnderline,			 (u32)&iObj_get_fontUnderline				  },
		{	cgc_height,						sizeof(cgc_height) - 1,						 (u32)&iObj_set_height,					 (u32)&iObj_get_height						  },
		{	cgc_helpContextID,				sizeof(cgc_helpContextID) - 1,				 (u32)&iObj_set_helpContextID,			 (u32)&iObj_get_helpContextID				  },
		{	cgc_hWnd,						sizeof(cgc_hWnd) - 1,						 (u32)&iObj_set_hWnd,					 (u32)&iObj_get_hWnd						  },
		{	cgc_keyPreview,					sizeof(cgc_keyPreview) - 1,					 (u32)&iObj_set_keyPreview,				 (u32)&iObj_get_keyPreview					  },
		{	cgc_left,						sizeof(cgc_left) - 1,						 (u32)&iObj_set_left,					 (u32)&iObj_get_left						  },
		{	cgc_mouseIcon,					sizeof(cgc_mouseIcon) - 1,					 (u32)&iObj_set_mouseIcon,				 (u32)&iObj_get_mouseIcon					  },
		{	cgc_mousePointer,				sizeof(cgc_mousePointer) - 1,				 (u32)&iObj_set_mousePointer,			 (u32)&iObj_get_mousePointer				  },
		{	cgc_name,						sizeof(cgc_name) - 1,						 (u32)&iObj_set_name,					 (u32)&iObj_get_name						  },
		{	cgc_parent,						sizeof(cgc_parent) - 1,						 (u32)&iObj_set_parent,					 (u32)&iObj_get_parent						  },
		{	cgc_parentClass,				sizeof(cgc_parentClass) - 1,				 (u32)&iObj_set_parentClass,			 (u32)&iObj_get_parentClass					  },
		{	cgc_icon,						sizeof(cgc_icon) - 1,						 (u32)&iObj_set_icon,					 (u32)&iObj_get_icon						  },
		{	cgc_picture,					sizeof(cgc_picture) - 1,					 (u32)&iObj_set_picture,				 (u32)&iObj_get_picture						  },
		{	cgc_tag,						sizeof(cgc_tag) - 1,						 (u32)&iObj_set_tag,					 (u32)&iObj_get_tag							  },
		{	cgc_top,						sizeof(cgc_top) - 1,						 (u32)&iObj_set_top,					 (u32)&iObj_get_top							  },
		{	cgc_visible,					sizeof(cgc_visible) - 1,					 (u32)&iObj_set_visible,				 (u32)&iObj_get_visible						  },
		{	cgc_width,						sizeof(cgc_width) - 1,						 (u32)&iObj_set_width,					 (u32)&iObj_get_width						  },
		{	cgc_zoomBox,					sizeof(cgc_zoomBox) - 1,					 (u32)&iObj_set_zoomBox,				 (u32)&iObj_get_zoomBox						  },
		{	NULL,							0,											 0,										 0										 }
	};

	SPropertyMap gcProps_radio[] =
	{
		{	NULL,							0,											 0,										 0										 }
	};

	SPropertyMap gcProps_checkbox[] = 
	{
		{	cgc_alignment,					sizeof(cgc_alignment) - 1,					 (u32)&iObj_set_alignment,				 (u32)&iObj_get_alignment					  },
		{	cgc_anchor,						sizeof(cgc_anchor) - 1,						 (u32)&iObj_set_anchor,					 (u32)&iObj_get_anchor						  },
		{	cgc_application,				sizeof(cgc_application) - 1,				 (u32)&iObj_set_application,			 (u32)&iObj_get_application					  },
		{	cgc_autoSize,					sizeof(cgc_autoSize) - 1,					 (u32)&iObj_set_autoSize,				 (u32)&iObj_get_autoSize					  },
		{	cgc_backStyle,					sizeof(cgc_backStyle) - 1,					 (u32)&iObj_set_backStyle,				 (u32)&iObj_get_backStyle					  },
		{	cgc_baseClass,					sizeof(cgc_baseClass) - 1,					 (u32)&iObj_set_baseClass,				 (u32)&iObj_get_baseClass					  },
		{	cgc_class,						sizeof(cgc_class) - 1,						 (u32)&iObj_set_class,					 (u32)&iObj_get_class						  },
		{	cgc_classLibrary,				sizeof(cgc_classLibrary) - 1,				 (u32)&iObj_set_classLibrary,			 (u32)&iObj_get_classLibrary				  },
		{	cgc_caption,					sizeof(cgc_caption) - 1,					 (u32)&iObj_set_caption,				 (u32)&iObj_get_caption						  },
		{	cgc_centered,					sizeof(cgc_centered) - 1,					 (u32)&iObj_set_centered,				 (u32)&iObj_get_centered					  },
		{	cgc_colorScheme,				sizeof(cgc_colorScheme) - 1,				 (u32)&iObj_set_colorScheme,			 (u32)&iObj_get_colorScheme					  },
		{	cgc_colorSource,				sizeof(cgc_colorSource) - 1,				 (u32)&iObj_set_colorSource,			 (u32)&iObj_get_colorSource					  },
		{	cgc_foreColor,					sizeof(cgc_foreColor) - 1,					 (u32)&iObj_set_foreColor,				 (u32)&iObj_get_foreColor					  },
		{	cgc_backColor,					sizeof(cgc_backColor) - 1,					 (u32)&iObj_set_backColor,				 (u32)&iObj_get_backColor					  },
		{	cgc_disabledBackColor,			sizeof(cgc_disabledBackColor) - 1,			 (u32)&iObj_set_disabledBackColor,		 (u32)&iObj_get_disabledBackColor			  },
		{	cgc_disabledForeColor,			sizeof(cgc_disabledForeColor) - 1,			 (u32)&iObj_set_disabledForeColor,		 (u32)&iObj_get_disabledForeColor			  },
		{	cgc_comment,					sizeof(cgc_comment) - 1,					 (u32)&iObj_set_comment,				 (u32)&iObj_get_comment						  },
		{	cgc_controlSource,				sizeof(cgc_controlSource) - 1,				 (u32)&iObj_set_controlSource,			 (u32)&iObj_get_controlSource				  },
		{	cgc_dragIcon,					sizeof(cgc_dragIcon) - 1,					 (u32)&iObj_set_dragIcon,				 (u32)&iObj_get_dragIcon					  },
		{	cgc_dragMode,					sizeof(cgc_dragMode) - 1,					 (u32)&iObj_set_dragMode,				 (u32)&iObj_get_dragMode					  },
		{	cgc_enabled,					sizeof(cgc_enabled) - 1,					 (u32)&iObj_set_enabled,				 (u32)&iObj_get_enabled						  },
		{	cgc_fontBold,					sizeof(cgc_fontBold) - 1,					 (u32)&iObj_set_fontBold,				 (u32)&iObj_get_fontBold					  },
		{	cgc_fontCharSet,				sizeof(cgc_fontCharSet) - 1,				 (u32)&iObj_set_fontCharSet,			 (u32)&iObj_get_fontCharSet					  },
		{	cgc_fontCondense,				sizeof(cgc_fontCondense) - 1,				 (u32)&iObj_set_fontCondense,			 (u32)&iObj_get_fontCondense				  },
		{	cgc_fontExtend,					sizeof(cgc_fontExtend) - 1,					 (u32)&iObj_set_fontExtend,				 (u32)&iObj_get_fontExtend					  },
		{	cgc_fontItalic,					sizeof(cgc_fontItalic) - 1,					 (u32)&iObj_set_fontItalic,				 (u32)&iObj_get_fontItalic					  },
		{	cgc_fontName,					sizeof(cgc_fontName) - 1,					 (u32)&iObj_set_fontName,				 (u32)&iObj_get_fontName					  },
		{	cgc_fontOutline,				sizeof(cgc_fontOutline) - 1,				 (u32)&iObj_set_fontOutline,			 (u32)&iObj_get_fontOutline					  },
		{	cgc_fontShadow,					sizeof(cgc_fontShadow) - 1,					 (u32)&iObj_set_fontShadow,				 (u32)&iObj_get_fontShadow					  },
		{	cgc_fontStrikeThru,				sizeof(cgc_fontStrikeThru) - 1,				 (u32)&iObj_set_fontStrikeThru,			 (u32)&iObj_get_fontStrikeThru				  },
		{	cgc_fontUnderline,				sizeof(cgc_fontUnderline) - 1,				 (u32)&iObj_set_fontUnderline,			 (u32)&iObj_get_fontUnderline				  },
		{	cgc_height,						sizeof(cgc_height) - 1,						 (u32)&iObj_set_height,					 (u32)&iObj_get_height						  },
		{	cgc_helpContextID,				sizeof(cgc_helpContextID) - 1,				 (u32)&iObj_set_helpContextID,			 (u32)&iObj_get_helpContextID				  },
		{	cgc_left,						sizeof(cgc_left) - 1,						 (u32)&iObj_set_left,					 (u32)&iObj_get_left						  },
		{	cgc_mouseIcon,					sizeof(cgc_mouseIcon) - 1,					 (u32)&iObj_set_mouseIcon,				 (u32)&iObj_get_mouseIcon					  },
		{	cgc_mousePointer,				sizeof(cgc_mousePointer) - 1,				 (u32)&iObj_set_mousePointer,			 (u32)&iObj_get_mousePointer				  },
		{	cgc_name,						sizeof(cgc_name) - 1,						 (u32)&iObj_set_name,					 (u32)&iObj_get_name						  },
		{	cgc_oLEDragMode,				sizeof(cgc_oLEDragMode) - 1,				 (u32)&iObj_set_oLEDragMode,			 (u32)&iObj_get_oLEDragMode					  },
		{	cgc_oLEDragPicture,				sizeof(cgc_oLEDragPicture) - 1,				 (u32)&iObj_set_oLEDragPicture,			 (u32)&iObj_get_oLEDragPicture				  },
		{	cgc_oLEDropEffects,				sizeof(cgc_oLEDropEffects) - 1,				 (u32)&iObj_set_oLEDropEffects,			 (u32)&iObj_get_oLEDropEffects				  },
		{	cgc_oLEDropHasData,				sizeof(cgc_oLEDropHasData) - 1,				 (u32)&iObj_set_oLEDropHasData,			 (u32)&iObj_get_oLEDropHasData				  },
		{	cgc_parent,						sizeof(cgc_parent) - 1,						 (u32)&iObj_set_parent,					 (u32)&iObj_get_parent						  },
		{	cgc_parentClass,				sizeof(cgc_parentClass) - 1,				 (u32)&iObj_set_parentClass,			 (u32)&iObj_get_parentClass					  },
		{	cgc_picture,					sizeof(cgc_picture) - 1,					 (u32)&iObj_set_picture,				 (u32)&iObj_get_picture						  },
		{	cgc_pictureMargin,				sizeof(cgc_pictureMargin) - 1,				 (u32)&iObj_set_pictureMargin,			 (u32)&iObj_get_pictureMargin				  },
		{	cgc_picturePosition,			sizeof(cgc_picturePosition) - 1,			 (u32)&iObj_set_picturePosition,		 (u32)&iObj_get_picturePosition				  },
		{	cgc_pictureSpacing,				sizeof(cgc_pictureSpacing) - 1,				 (u32)&iObj_set_pictureSpacing,			 (u32)&iObj_get_pictureSpacing				  },
		{	cgc_disabledPicture,			sizeof(cgc_disabledPicture) - 1,			 (u32)&iObj_set_disabledPicture,		 (u32)&iObj_get_disabledPicture				  },
		{	cgc_downPicture,				sizeof(cgc_downPicture) - 1,				 (u32)&iObj_set_downPicture,			 (u32)&iObj_get_downPicture					  },
		{	cgc_readOnly,					sizeof(cgc_readOnly) - 1,					 (u32)&iObj_set_readOnly,				 (u32)&iObj_get_readOnly					  },
		{	cgc_rightToLeft,				sizeof(cgc_rightToLeft) - 1,				 (u32)&iObj_set_rightToLeft,			 (u32)&iObj_get_rightToLeft					  },
		{	cgc_specialEffect,				sizeof(cgc_specialEffect) - 1,				 (u32)&iObj_set_specialEffect,			 (u32)&iObj_get_specialEffect				  },
		{	cgc_statusBarText,				sizeof(cgc_statusBarText) - 1,				 (u32)&iObj_set_statusBarText,			 (u32)&iObj_get_statusBarText				  },
		{	cgc_style,						sizeof(cgc_style) - 1,						 (u32)&iObj_set_style,					 (u32)&iObj_get_style						  },
		{	cgc_tabIndex,					sizeof(cgc_tabIndex) - 1,					 (u32)&iObj_set_tabIndex,				 (u32)&iObj_get_tabIndex					  },
		{	cgc_tabStop,					sizeof(cgc_tabStop) - 1,					 (u32)&iObj_set_tabStop,				 (u32)&iObj_get_tabStop						  },
		{	cgc_tag,						sizeof(cgc_tag) - 1,						 (u32)&iObj_set_tag,					 (u32)&iObj_get_tag							  },
		{	cgc_terminateRead,				sizeof(cgc_terminateRead) - 1,				 (u32)&iObj_set_terminateRead,			 (u32)&iObj_get_terminateRead				  },
		{	cgc_themes,						sizeof(cgc_themes) - 1,						 (u32)&iObj_set_themes,					 (u32)&iObj_get_themes						  },
		{	cgc_toolTipText,				sizeof(cgc_toolTipText) - 1,				 (u32)&iObj_set_toolTipText,			 (u32)&iObj_get_toolTipText					  },
		{	cgc_top,						sizeof(cgc_top) - 1,						 (u32)&iObj_set_top,					 (u32)&iObj_get_top							  },
		{	cgc_value,						sizeof(cgc_value) - 1,						 (u32)&iObj_set_value,					 (u32)&iObj_get_value						  },
		{	cgc_visible,					sizeof(cgc_visible) - 1,					 (u32)&iObj_set_visible,				 (u32)&iObj_get_visible						  },
		{	cgc_whatsThisHelpID,			sizeof(cgc_whatsThisHelpID) - 1,			 (u32)&iObj_set_whatsThisHelpID,		 (u32)&iObj_get_whatsThisHelpID				  },
		{	cgc_width,						sizeof(cgc_width) - 1,						 (u32)&iObj_set_width,					 (u32)&iObj_get_width						  },
		{	cgc_wordWrap,					sizeof(cgc_wordWrap) - 1,					 (u32)&iObj_set_wordWrap,				 (u32)&iObj_get_wordWrap					  },
		{	NULL,							0,											 0,										 0										 }
	};

	SPropertyMap gcProps_button[] = 
	{
		{	cgc_alignment,					sizeof(cgc_alignment) - 1,					 (u32)&iObj_set_alignment,				 (u32)&iObj_get_alignment					  },
		{	cgc_anchor,						sizeof(cgc_anchor) - 1,						 (u32)&iObj_set_anchor,					 (u32)&iObj_get_anchor						  },
		{	cgc_application,				sizeof(cgc_application) - 1,				 (u32)&iObj_set_application,			 (u32)&iObj_get_application					  },
		{	cgc_autoSize,					sizeof(cgc_autoSize) - 1,					 (u32)&iObj_set_autoSize,				 (u32)&iObj_get_autoSize					  },
		{	cgc_baseClass,					sizeof(cgc_baseClass) - 1,					 (u32)&iObj_set_baseClass,				 (u32)&iObj_get_baseClass					  },
		{	cgc_class,						sizeof(cgc_class) - 1,						 (u32)&iObj_set_class,					 (u32)&iObj_get_class						  },
		{	cgc_classLibrary,				sizeof(cgc_classLibrary) - 1,				 (u32)&iObj_set_classLibrary,			 (u32)&iObj_get_classLibrary				  },
		{	cgc_cancel,						sizeof(cgc_cancel) - 1,						 (u32)&iObj_set_cancel,					 (u32)&iObj_get_cancel						  },
		{	cgc_default,					sizeof(cgc_default) - 1,					 (u32)&iObj_set_default,				 (u32)&iObj_get_default						  },
		{	cgc_caption,					sizeof(cgc_caption) - 1,					 (u32)&iObj_set_caption,				 (u32)&iObj_get_caption						  },
		{	cgc_colorScheme,				sizeof(cgc_colorScheme) - 1,				 (u32)&iObj_set_colorScheme,			 (u32)&iObj_get_colorScheme					  },
		{	cgc_colorSource,				sizeof(cgc_colorSource) - 1,				 (u32)&iObj_set_colorSource,			 (u32)&iObj_get_colorSource					  },
		{	cgc_foreColor,					sizeof(cgc_foreColor) - 1,					 (u32)&iObj_set_foreColor,				 (u32)&iObj_get_foreColor					  },
		{	cgc_backColor,					sizeof(cgc_backColor) - 1,					 (u32)&iObj_set_backColor,				 (u32)&iObj_get_backColor					  },
		{	cgc_disabledBackColor,			sizeof(cgc_disabledBackColor) - 1,			 (u32)&iObj_set_disabledBackColor,		 (u32)&iObj_get_disabledBackColor			  },
		{	cgc_disabledForeColor,			sizeof(cgc_disabledForeColor) - 1,			 (u32)&iObj_set_disabledForeColor,		 (u32)&iObj_get_disabledForeColor			  },
		{	cgc_comment,					sizeof(cgc_comment) - 1,					 (u32)&iObj_set_comment,				 (u32)&iObj_get_comment						  },
		{	cgc_dragIcon,					sizeof(cgc_dragIcon) - 1,					 (u32)&iObj_set_dragIcon,				 (u32)&iObj_get_dragIcon					  },
		{	cgc_dragMode,					sizeof(cgc_dragMode) - 1,					 (u32)&iObj_set_dragMode,				 (u32)&iObj_get_dragMode					  },
		{	cgc_enabled,					sizeof(cgc_enabled) - 1,					 (u32)&iObj_set_enabled,				 (u32)&iObj_get_enabled						  },
		{	cgc_fontBold,					sizeof(cgc_fontBold) - 1,					 (u32)&iObj_set_fontBold,				 (u32)&iObj_get_fontBold					  },
		{	cgc_fontCharSet,				sizeof(cgc_fontCharSet) - 1,				 (u32)&iObj_set_fontCharSet,			 (u32)&iObj_get_fontCharSet					  },
		{	cgc_fontCondense,				sizeof(cgc_fontCondense) - 1,				 (u32)&iObj_set_fontCondense,			 (u32)&iObj_get_fontCondense				  },
		{	cgc_fontExtend,					sizeof(cgc_fontExtend) - 1,					 (u32)&iObj_set_fontExtend,				 (u32)&iObj_get_fontExtend					  },
		{	cgc_fontItalic,					sizeof(cgc_fontItalic) - 1,					 (u32)&iObj_set_fontItalic,				 (u32)&iObj_get_fontItalic					  },
		{	cgc_fontName,					sizeof(cgc_fontName) - 1,					 (u32)&iObj_set_fontName,				 (u32)&iObj_get_fontName					  },
		{	cgc_fontOutline,				sizeof(cgc_fontOutline) - 1,				 (u32)&iObj_set_fontOutline,			 (u32)&iObj_get_fontOutline					  },
		{	cgc_fontShadow,					sizeof(cgc_fontShadow) - 1,					 (u32)&iObj_set_fontShadow,				 (u32)&iObj_get_fontShadow					  },
		{	cgc_fontSize,					sizeof(cgc_fontSize) - 1,					 (u32)&iObj_set_fontSize,				 (u32)&iObj_get_fontSize					  },
		{	cgc_fontStrikeThru,				sizeof(cgc_fontStrikeThru) - 1,				 (u32)&iObj_set_fontStrikeThru,			 (u32)&iObj_get_fontStrikeThru				  },
		{	cgc_fontUnderline,				sizeof(cgc_fontUnderline) - 1,				 (u32)&iObj_set_fontUnderline,			 (u32)&iObj_get_fontUnderline				  },
		{	cgc_height,						sizeof(cgc_height) - 1,						 (u32)&iObj_set_height,					 (u32)&iObj_get_height						  },
		{	cgc_helpContextID,				sizeof(cgc_helpContextID) - 1,				 (u32)&iObj_set_helpContextID,			 (u32)&iObj_get_helpContextID				  },
		{	cgc_left,						sizeof(cgc_left) - 1,						 (u32)&iObj_set_left,					 (u32)&iObj_get_left						  },
		{	cgc_mouseIcon,					sizeof(cgc_mouseIcon) - 1,					 (u32)&iObj_set_mouseIcon,				 (u32)&iObj_get_mouseIcon					  },
		{	cgc_mousePointer,				sizeof(cgc_mousePointer) - 1,				 (u32)&iObj_set_mousePointer,			 (u32)&iObj_get_mousePointer				  },
		{	cgc_name,						sizeof(cgc_name) - 1,						 (u32)&iObj_set_name,					 (u32)&iObj_get_name						  },
		{	cgc_oLEDragMode,				sizeof(cgc_oLEDragMode) - 1,				 (u32)&iObj_set_oLEDragMode,			 (u32)&iObj_get_oLEDragMode					  },
		{	cgc_oLEDragPicture,				sizeof(cgc_oLEDragPicture) - 1,				 (u32)&iObj_set_oLEDragPicture,			 (u32)&iObj_get_oLEDragPicture				  },
		{	cgc_oLEDropEffects,				sizeof(cgc_oLEDropEffects) - 1,				 (u32)&iObj_set_oLEDropEffects,			 (u32)&iObj_get_oLEDropEffects				  },
		{	cgc_oLEDropHasData,				sizeof(cgc_oLEDropHasData) - 1,				 (u32)&iObj_set_oLEDropHasData,			 (u32)&iObj_get_oLEDropHasData				  },
		{	cgc_oLEDropMode,				sizeof(cgc_oLEDropMode) - 1,				 (u32)&iObj_set_oLEDropMode,			 (u32)&iObj_get_oLEDropMode					  },
		{	cgc_parent,						sizeof(cgc_parent) - 1,						 (u32)&iObj_set_parent,					 (u32)&iObj_get_parent						  },
		{	cgc_parentClass,				sizeof(cgc_parentClass) - 1,				 (u32)&iObj_set_parentClass,			 (u32)&iObj_get_parentClass					  },
		{	cgc_picture,					sizeof(cgc_picture) - 1,					 (u32)&iObj_set_picture,				 (u32)&iObj_get_picture						  },
		{	cgc_pictureMargin,				sizeof(cgc_pictureMargin) - 1,				 (u32)&iObj_set_pictureMargin,			 (u32)&iObj_get_pictureMargin				  },
		{	cgc_picturePosition,			sizeof(cgc_picturePosition) - 1,			 (u32)&iObj_set_picturePosition,		 (u32)&iObj_get_picturePosition				  },
		{	cgc_pictureSpacing,				sizeof(cgc_pictureSpacing) - 1,				 (u32)&iObj_set_pictureSpacing,			 (u32)&iObj_get_pictureSpacing				  },
		{	cgc_disabledPicture,			sizeof(cgc_disabledPicture) - 1,			 (u32)&iObj_set_disabledPicture,		 (u32)&iObj_get_disabledPicture				  },
		{	cgc_downPicture,				sizeof(cgc_downPicture) - 1,				 (u32)&iObj_set_downPicture,			 (u32)&iObj_get_downPicture					  },
		{	cgc_rightToLeft,				sizeof(cgc_rightToLeft) - 1,				 (u32)&iObj_set_rightToLeft,			 (u32)&iObj_get_rightToLeft					  },
		{	cgc_specialEffect,				sizeof(cgc_specialEffect) - 1,				 (u32)&iObj_set_specialEffect,			 (u32)&iObj_get_specialEffect				  },
		{	cgc_statusBarText,				sizeof(cgc_statusBarText) - 1,				 (u32)&iObj_set_statusBarText,			 (u32)&iObj_get_statusBarText				  },
		{	cgc_style,						sizeof(cgc_style) - 1,						 (u32)&iObj_set_style,					 (u32)&iObj_get_style						  },
		{	cgc_tabIndex,					sizeof(cgc_tabIndex) - 1,					 (u32)&iObj_set_tabIndex,				 (u32)&iObj_get_tabIndex					  },
		{	cgc_tabStop,					sizeof(cgc_tabStop) - 1,					 (u32)&iObj_set_tabStop,				 (u32)&iObj_get_tabStop						  },
		{	cgc_tag,						sizeof(cgc_tag) - 1,						 (u32)&iObj_set_tag,					 (u32)&iObj_get_tag							  },
		{	cgc_terminateRead,				sizeof(cgc_terminateRead) - 1,				 (u32)&iObj_set_terminateRead,			 (u32)&iObj_get_terminateRead				  },
		{	cgc_themes,						sizeof(cgc_themes) - 1,						 (u32)&iObj_set_themes,					 (u32)&iObj_get_themes						  },
		{	cgc_toolTipText,				sizeof(cgc_toolTipText) - 1,				 (u32)&iObj_set_toolTipText,			 (u32)&iObj_get_toolTipText					  },
		{	cgc_top,						sizeof(cgc_top) - 1,						 (u32)&iObj_set_top,					 (u32)&iObj_get_top							  },
		{	cgc_visible,					sizeof(cgc_visible) - 1,					 (u32)&iObj_set_visible,				 (u32)&iObj_get_visible						  },
		{	cgc_visualEffect,				sizeof(cgc_visualEffect) - 1,				 (u32)&iObj_set_visualEffect,			 (u32)&iObj_get_visualEffect				  },
		{	cgc_whatsThisHelpID,			sizeof(cgc_whatsThisHelpID) - 1,			 (u32)&iObj_set_whatsThisHelpID,		 (u32)&iObj_get_whatsThisHelpID				  },
		{	cgc_width,						sizeof(cgc_width) - 1,						 (u32)&iObj_set_width,					 (u32)&iObj_get_width						  },
		{	cgc_wordWrap,					sizeof(cgc_wordWrap) - 1,					 (u32)&iObj_set_wordWrap,				 (u32)&iObj_get_wordWrap					  },
		{	NULL,							0,											 0,										 0										 }
	};

	SPropertyMap gcProps_cmdgroup[] = 
	{
		{	cgc_anchor,						sizeof(cgc_anchor) - 1,						 (u32)&iObj_set_anchor,					 (u32)&iObj_get_anchor						  },
		{	cgc_autoSize,					sizeof(cgc_autoSize) - 1,					 (u32)&iObj_set_autoSize,				 (u32)&iObj_get_autoSize					  },
		{	cgc_backStyle,					sizeof(cgc_backStyle) - 1,					 (u32)&iObj_set_backStyle,				 (u32)&iObj_get_backStyle					  },
		{	cgc_buttonCount,				sizeof(cgc_buttonCount) - 1,				 (u32)&iObj_set_buttonCount,			 (u32)&iObj_get_buttonCount					  },
		{	cgc_borderColor,				sizeof(cgc_borderColor) - 1,				 (u32)&iObj_set_borderColor,			 (u32)&iObj_get_borderColor					  },
		{	cgc_borderStyle,				sizeof(cgc_borderStyle) - 1,				 (u32)&iObj_set_borderStyle,			 (u32)&iObj_get_borderStyle					  },
		{	cgc_colorSource,				sizeof(cgc_colorSource) - 1,				 (u32)&iObj_set_colorSource,			 (u32)&iObj_get_colorSource					  },
		{	cgc_backColor,					sizeof(cgc_backColor) - 1,					 (u32)&iObj_set_backColor,				 (u32)&iObj_get_backColor					  },
		{	cgc_comment,					sizeof(cgc_comment) - 1,					 (u32)&iObj_set_comment,				 (u32)&iObj_get_comment						  },
		{	cgc_controlSource,				sizeof(cgc_controlSource) - 1,				 (u32)&iObj_set_controlSource,			 (u32)&iObj_get_controlSource				  },
		{	cgc_dragIcon,					sizeof(cgc_dragIcon) - 1,					 (u32)&iObj_set_dragIcon,				 (u32)&iObj_get_dragIcon					  },
		{	cgc_dragMode,					sizeof(cgc_dragMode) - 1,					 (u32)&iObj_set_dragMode,				 (u32)&iObj_get_dragMode					  },
		{	cgc_enabled,					sizeof(cgc_enabled) - 1,					 (u32)&iObj_set_enabled,				 (u32)&iObj_get_enabled						  },
		{	cgc_height,						sizeof(cgc_height) - 1,						 (u32)&iObj_set_height,					 (u32)&iObj_get_height						  },
		{	cgc_helpContextID,				sizeof(cgc_helpContextID) - 1,				 (u32)&iObj_set_helpContextID,			 (u32)&iObj_get_helpContextID				  },
		{	cgc_left,						sizeof(cgc_left) - 1,						 (u32)&iObj_set_left,					 (u32)&iObj_get_left						  },
		{	cgc_memberClass,				sizeof(cgc_memberClass) - 1,				 (u32)&iObj_set_memberClass,			 (u32)&iObj_get_memberClass					  },
		{	cgc_memberClassLibrary,			sizeof(cgc_memberClassLibrary) - 1,			 (u32)&iObj_set_memberClassLibrary,		 (u32)&iObj_get_memberClassLibrary			  },
		{	cgc_mouseIcon,					sizeof(cgc_mouseIcon) - 1,					 (u32)&iObj_set_mouseIcon,				 (u32)&iObj_get_mouseIcon					  },
		{	cgc_mousePointer,				sizeof(cgc_mousePointer) - 1,				 (u32)&iObj_set_mousePointer,			 (u32)&iObj_get_mousePointer				  },
		{	cgc_name,						sizeof(cgc_name) - 1,						 (u32)&iObj_set_name,					 (u32)&iObj_get_name						  },
		{	cgc_oLEDragMode,				sizeof(cgc_oLEDragMode) - 1,				 (u32)&iObj_set_oLEDragMode,			 (u32)&iObj_get_oLEDragMode					  },
		{	cgc_oLEDragPicture,				sizeof(cgc_oLEDragPicture) - 1,				 (u32)&iObj_set_oLEDragPicture,			 (u32)&iObj_get_oLEDragPicture				  },
		{	cgc_oLEDropEffects,				sizeof(cgc_oLEDropEffects) - 1,				 (u32)&iObj_set_oLEDropEffects,			 (u32)&iObj_get_oLEDropEffects				  },
		{	cgc_oLEDropMode,				sizeof(cgc_oLEDropMode) - 1,				 (u32)&iObj_set_oLEDropMode,			 (u32)&iObj_get_oLEDropMode					  },
		{	cgc_specialEffect,				sizeof(cgc_specialEffect) - 1,				 (u32)&iObj_set_specialEffect,			 (u32)&iObj_get_specialEffect				  },
		{	cgc_statusBarText,				sizeof(cgc_statusBarText) - 1,				 (u32)&iObj_set_statusBarText,			 (u32)&iObj_get_statusBarText				  },
		{	cgc_tag,						sizeof(cgc_tag) - 1,						 (u32)&iObj_set_tag,					 (u32)&iObj_get_tag							  },
		{	cgc_terminateRead,				sizeof(cgc_terminateRead) - 1,				 (u32)&iObj_set_terminateRead,			 (u32)&iObj_get_terminateRead				  },
		{	cgc_themes,						sizeof(cgc_themes) - 1,						 (u32)&iObj_set_themes,					 (u32)&iObj_get_themes						  },
		{	cgc_toolTipText,				sizeof(cgc_toolTipText) - 1,				 (u32)&iObj_set_toolTipText,			 (u32)&iObj_get_toolTipText					  },
		{	cgc_top,						sizeof(cgc_top) - 1,						 (u32)&iObj_set_top,					 (u32)&iObj_get_top							  },
		{	cgc_value,						sizeof(cgc_value) - 1,						 (u32)&iObj_set_value,					 (u32)&iObj_get_value						  },
		{	cgc_visible,					sizeof(cgc_visible) - 1,					 (u32)&iObj_set_visible,				 (u32)&iObj_get_visible						  },
		{	cgc_whatsThisHelpID,			sizeof(cgc_whatsThisHelpID) - 1,			 (u32)&iObj_set_whatsThisHelpID,		 (u32)&iObj_get_whatsThisHelpID				  },
		{	cgc_width,						sizeof(cgc_width) - 1,						 (u32)&iObj_set_width,					 (u32)&iObj_get_width						  },
		{	NULL,							0,											 0,										 0										 }
	};

	SPropertyMap gcProps_label[] = 
	{
		{	cgc_alignment,					sizeof(cgc_alignment) - 1,					 (u32)&iObj_set_alignment,				 (u32)&iObj_get_alignment					  },
		{	cgc_anchor,						sizeof(cgc_anchor) - 1,						 (u32)&iObj_set_anchor,					 (u32)&iObj_get_anchor						  },
		{	cgc_application,				sizeof(cgc_application) - 1,				 (u32)&iObj_set_application,			 (u32)&iObj_get_application					  },
		{	cgc_autoSize,					sizeof(cgc_autoSize) - 1,					 (u32)&iObj_set_autoSize,				 (u32)&iObj_get_autoSize					  },
		{	cgc_backStyle,					sizeof(cgc_backStyle) - 1,					 (u32)&iObj_set_backStyle,				 (u32)&iObj_get_backStyle					  },
		{	cgc_baseClass,					sizeof(cgc_baseClass) - 1,					 (u32)&iObj_set_baseClass,				 (u32)&iObj_get_baseClass					  },
		{	cgc_class,						sizeof(cgc_class) - 1,						 (u32)&iObj_set_class,					 (u32)&iObj_get_class						  },
		{	cgc_classLibrary,				sizeof(cgc_classLibrary) - 1,				 (u32)&iObj_set_classLibrary,			 (u32)&iObj_get_classLibrary				  },
		{	cgc_borderStyle,				sizeof(cgc_borderStyle) - 1,				 (u32)&iObj_set_borderStyle,			 (u32)&iObj_get_borderStyle					  },
		{	cgc_caption,					sizeof(cgc_caption) - 1,					 (u32)&iObj_set_caption,				 (u32)&iObj_get_caption						  },
		{	cgc_colorScheme,				sizeof(cgc_colorScheme) - 1,				 (u32)&iObj_set_colorScheme,			 (u32)&iObj_get_colorScheme					  },
		{	cgc_colorSource,				sizeof(cgc_colorSource) - 1,				 (u32)&iObj_set_colorSource,			 (u32)&iObj_get_colorSource					  },
		{	cgc_foreColor,					sizeof(cgc_foreColor) - 1,					 (u32)&iObj_set_foreColor,				 (u32)&iObj_get_foreColor					  },
		{	cgc_backColor,					sizeof(cgc_backColor) - 1,					 (u32)&iObj_set_backColor,				 (u32)&iObj_get_backColor					  },
		{	cgc_disabledBackColor,			sizeof(cgc_disabledBackColor) - 1,			 (u32)&iObj_set_disabledBackColor,		 (u32)&iObj_get_disabledBackColor			  },
		{	cgc_disabledForeColor,			sizeof(cgc_disabledForeColor) - 1,			 (u32)&iObj_set_disabledForeColor,		 (u32)&iObj_get_disabledForeColor			  },
		{	cgc_comment,					sizeof(cgc_comment) - 1,					 (u32)&iObj_set_comment,				 (u32)&iObj_get_comment						  },
		{	cgc_dragIcon,					sizeof(cgc_dragIcon) - 1,					 (u32)&iObj_set_dragIcon,				 (u32)&iObj_get_dragIcon					  },
		{	cgc_dragMode,					sizeof(cgc_dragMode) - 1,					 (u32)&iObj_set_dragMode,				 (u32)&iObj_get_dragMode					  },
		{	cgc_enabled,					sizeof(cgc_enabled) - 1,					 (u32)&iObj_set_enabled,				 (u32)&iObj_get_enabled						  },
		{	cgc_fontBold,					sizeof(cgc_fontBold) - 1,					 (u32)&iObj_set_fontBold,				 (u32)&iObj_get_fontBold					  },
		{	cgc_fontCharSet,				sizeof(cgc_fontCharSet) - 1,				 (u32)&iObj_set_fontCharSet,			 (u32)&iObj_get_fontCharSet					  },
		{	cgc_fontCondense,				sizeof(cgc_fontCondense) - 1,				 (u32)&iObj_set_fontCondense,			 (u32)&iObj_get_fontCondense				  },
		{	cgc_fontExtend,					sizeof(cgc_fontExtend) - 1,					 (u32)&iObj_set_fontExtend,				 (u32)&iObj_get_fontExtend					  },
		{	cgc_fontItalic,					sizeof(cgc_fontItalic) - 1,					 (u32)&iObj_set_fontItalic,				 (u32)&iObj_get_fontItalic					  },
		{	cgc_fontName,					sizeof(cgc_fontName) - 1,					 (u32)&iObj_set_fontName,				 (u32)&iObj_get_fontName					  },
		{	cgc_fontOutline,				sizeof(cgc_fontOutline) - 1,				 (u32)&iObj_set_fontOutline,			 (u32)&iObj_get_fontOutline					  },
		{	cgc_fontShadow,					sizeof(cgc_fontShadow) - 1,					 (u32)&iObj_set_fontShadow,				 (u32)&iObj_get_fontShadow					  },
		{	cgc_fontSize,					sizeof(cgc_fontSize) - 1,					 (u32)&iObj_set_fontSize,				 (u32)&iObj_get_fontSize					  },
		{	cgc_fontStrikeThru,				sizeof(cgc_fontStrikeThru) - 1,				 (u32)&iObj_set_fontStrikeThru,			 (u32)&iObj_get_fontStrikeThru				  },
		{	cgc_fontUnderline,				sizeof(cgc_fontUnderline) - 1,				 (u32)&iObj_set_fontUnderline,			 (u32)&iObj_get_fontUnderline				  },
		{	cgc_height,						sizeof(cgc_height) - 1,						 (u32)&iObj_set_height,					 (u32)&iObj_get_height						  },
		{	cgc_helpContextID,				sizeof(cgc_helpContextID) - 1,				 (u32)&iObj_set_helpContextID,			 (u32)&iObj_get_helpContextID				  },
		{	cgc_left,						sizeof(cgc_left) - 1,						 (u32)&iObj_set_left,					 (u32)&iObj_get_left						  },
		{	cgc_mouseIcon,					sizeof(cgc_mouseIcon) - 1,					 (u32)&iObj_set_mouseIcon,				 (u32)&iObj_get_mouseIcon					  },
		{	cgc_mousePointer,				sizeof(cgc_mousePointer) - 1,				 (u32)&iObj_set_mousePointer,			 (u32)&iObj_get_mousePointer				  },
		{	cgc_name,						sizeof(cgc_name) - 1,						 (u32)&iObj_set_name,					 (u32)&iObj_get_name						  },
		{	cgc_oLEDragMode,				sizeof(cgc_oLEDragMode) - 1,				 (u32)&iObj_set_oLEDragMode,			 (u32)&iObj_get_oLEDragMode					  },
		{	cgc_oLEDragPicture,				sizeof(cgc_oLEDragPicture) - 1,				 (u32)&iObj_set_oLEDragPicture,			 (u32)&iObj_get_oLEDragPicture				  },
		{	cgc_oLEDropEffects,				sizeof(cgc_oLEDropEffects) - 1,				 (u32)&iObj_set_oLEDropEffects,			 (u32)&iObj_get_oLEDropEffects				  },
		{	cgc_oLEDropHasData,				sizeof(cgc_oLEDropHasData) - 1,				 (u32)&iObj_set_oLEDropHasData,			 (u32)&iObj_get_oLEDropHasData				  },
		{	cgc_oLEDropMode,				sizeof(cgc_oLEDropMode) - 1,				 (u32)&iObj_set_oLEDropMode,			 (u32)&iObj_get_oLEDropMode					  },
		{	cgc_parent,						sizeof(cgc_parent) - 1,						 (u32)&iObj_set_parent,					 (u32)&iObj_get_parent						  },
		{	cgc_parentClass,				sizeof(cgc_parentClass) - 1,				 (u32)&iObj_set_parentClass,			 (u32)&iObj_get_parentClass					  },
		{	cgc_rightToLeft,				sizeof(cgc_rightToLeft) - 1,				 (u32)&iObj_set_rightToLeft,			 (u32)&iObj_get_rightToLeft					  },
		{	cgc_rotation,					sizeof(cgc_rotation) - 1,					 (u32)&iObj_set_rotation,				 (u32)&iObj_get_rotation					  },
		{	cgc_statusBarText,				sizeof(cgc_statusBarText) - 1,				 (u32)&iObj_set_statusBarText,			 (u32)&iObj_get_statusBarText				  },
		{	cgc_style,						sizeof(cgc_style) - 1,						 (u32)&iObj_set_style,					 (u32)&iObj_get_style						  },
		{	cgc_tabIndex,					sizeof(cgc_tabIndex) - 1,					 (u32)&iObj_set_tabIndex,				 (u32)&iObj_get_tabIndex					  },
		{	cgc_tag,						sizeof(cgc_tag) - 1,						 (u32)&iObj_set_tag,					 (u32)&iObj_get_tag							  },
		{	cgc_toolTipText,				sizeof(cgc_toolTipText) - 1,				 (u32)&iObj_set_toolTipText,			 (u32)&iObj_get_toolTipText					  },
		{	cgc_top,						sizeof(cgc_top) - 1,						 (u32)&iObj_set_top,					 (u32)&iObj_get_top							  },
		{	cgc_visible,					sizeof(cgc_visible) - 1,					 (u32)&iObj_set_visible,				 (u32)&iObj_get_visible						  },
		{	cgc_whatsThisHelpID,			sizeof(cgc_whatsThisHelpID) - 1,			 (u32)&iObj_set_whatsThisHelpID,		 (u32)&iObj_get_whatsThisHelpID				  },
		{	cgc_width,						sizeof(cgc_width) - 1,						 (u32)&iObj_set_width,					 (u32)&iObj_get_width						  },
		{	cgc_wordWrap,					sizeof(cgc_wordWrap) - 1,					 (u32)&iObj_set_wordWrap,				 (u32)&iObj_get_wordWrap					  },
		{	NULL,							0,											 0,										 0										 }
	};

	SPropertyMap gcProps_option[] = 
	{
		{	cgc_alignment,					sizeof(cgc_alignment) - 1,					 (u32)&iObj_set_alignment,				 (u32)&iObj_get_alignment					  },
		{	cgc_anchor,						sizeof(cgc_anchor) - 1,						 (u32)&iObj_set_anchor,					 (u32)&iObj_get_anchor						  },
		{	cgc_autoSize,					sizeof(cgc_autoSize) - 1,					 (u32)&iObj_set_autoSize,				 (u32)&iObj_get_autoSize					  },
		{	cgc_backStyle,					sizeof(cgc_backStyle) - 1,					 (u32)&iObj_set_backStyle,				 (u32)&iObj_get_backStyle					  },
		{	cgc_caption,					sizeof(cgc_caption) - 1,					 (u32)&iObj_set_caption,				 (u32)&iObj_get_caption						  },
		{	cgc_colorScheme,				sizeof(cgc_colorScheme) - 1,				 (u32)&iObj_set_colorScheme,			 (u32)&iObj_get_colorScheme					  },
		{	cgc_colorSource,				sizeof(cgc_colorSource) - 1,				 (u32)&iObj_set_colorSource,			 (u32)&iObj_get_colorSource					  },
		{	cgc_foreColor,					sizeof(cgc_foreColor) - 1,					 (u32)&iObj_set_foreColor,				 (u32)&iObj_get_foreColor					  },
		{	cgc_backColor,					sizeof(cgc_backColor) - 1,					 (u32)&iObj_set_backColor,				 (u32)&iObj_get_backColor					  },
		{	cgc_disabledBackColor,			sizeof(cgc_disabledBackColor) - 1,			 (u32)&iObj_set_disabledBackColor,		 (u32)&iObj_get_disabledBackColor			  },
		{	cgc_disabledForeColor,			sizeof(cgc_disabledForeColor) - 1,			 (u32)&iObj_set_disabledForeColor,		 (u32)&iObj_get_disabledForeColor			  },
		{	cgc_comment,					sizeof(cgc_comment) - 1,					 (u32)&iObj_set_comment,				 (u32)&iObj_get_comment						  },
		{	cgc_controlSource,				sizeof(cgc_controlSource) - 1,				 (u32)&iObj_set_controlSource,			 (u32)&iObj_get_controlSource				  },
		{	cgc_dragIcon,					sizeof(cgc_dragIcon) - 1,					 (u32)&iObj_set_dragIcon,				 (u32)&iObj_get_dragIcon					  },
		{	cgc_dragMode,					sizeof(cgc_dragMode) - 1,					 (u32)&iObj_set_dragMode,				 (u32)&iObj_get_dragMode					  },
		{	cgc_enabled,					sizeof(cgc_enabled) - 1,					 (u32)&iObj_set_enabled,				 (u32)&iObj_get_enabled						  },
		{	cgc_fontBold,					sizeof(cgc_fontBold) - 1,					 (u32)&iObj_set_fontBold,				 (u32)&iObj_get_fontBold					  },
		{	cgc_fontCharSet,				sizeof(cgc_fontCharSet) - 1,				 (u32)&iObj_set_fontCharSet,			 (u32)&iObj_get_fontCharSet					  },
		{	cgc_fontCondense,				sizeof(cgc_fontCondense) - 1,				 (u32)&iObj_set_fontCondense,			 (u32)&iObj_get_fontCondense				  },
		{	cgc_fontExtend,					sizeof(cgc_fontExtend) - 1,					 (u32)&iObj_set_fontExtend,				 (u32)&iObj_get_fontExtend					  },
		{	cgc_fontItalic,					sizeof(cgc_fontItalic) - 1,					 (u32)&iObj_set_fontItalic,				 (u32)&iObj_get_fontItalic					  },
		{	cgc_fontName,					sizeof(cgc_fontName) - 1,					 (u32)&iObj_set_fontName,				 (u32)&iObj_get_fontName					  },
		{	cgc_fontOutline,				sizeof(cgc_fontOutline) - 1,				 (u32)&iObj_set_fontOutline,			 (u32)&iObj_get_fontOutline					  },
		{	cgc_fontShadow,					sizeof(cgc_fontShadow) - 1,					 (u32)&iObj_set_fontShadow,				 (u32)&iObj_get_fontShadow					  },
		{	cgc_fontSize,					sizeof(cgc_fontSize) - 1,					 (u32)&iObj_set_fontSize,				 (u32)&iObj_get_fontSize					  },
		{	cgc_fontStrikeThru,				sizeof(cgc_fontStrikeThru) - 1,				 (u32)&iObj_set_fontStrikeThru,			 (u32)&iObj_get_fontStrikeThru				  },
		{	cgc_fontUnderline,				sizeof(cgc_fontUnderline) - 1,				 (u32)&iObj_set_fontUnderline,			 (u32)&iObj_get_fontUnderline				  },
		{	cgc_height,						sizeof(cgc_height) - 1,						 (u32)&iObj_set_height,					 (u32)&iObj_get_height						  },
		{	cgc_helpContextID,				sizeof(cgc_helpContextID) - 1,				 (u32)&iObj_set_helpContextID,			 (u32)&iObj_get_helpContextID				  },
		{	cgc_left,						sizeof(cgc_left) - 1,						 (u32)&iObj_set_left,					 (u32)&iObj_get_left						  },
		{	cgc_mouseIcon,					sizeof(cgc_mouseIcon) - 1,					 (u32)&iObj_set_mouseIcon,				 (u32)&iObj_get_mouseIcon					  },
		{	cgc_mousePointer,				sizeof(cgc_mousePointer) - 1,				 (u32)&iObj_set_mousePointer,			 (u32)&iObj_get_mousePointer				  },
		{	cgc_name,						sizeof(cgc_name) - 1,						 (u32)&iObj_set_name,					 (u32)&iObj_get_name						  },
		{	cgc_oLEDragMode,				sizeof(cgc_oLEDragMode) - 1,				 (u32)&iObj_set_oLEDragMode,			 (u32)&iObj_get_oLEDragMode					  },
		{	cgc_oLEDragPicture,				sizeof(cgc_oLEDragPicture) - 1,				 (u32)&iObj_set_oLEDragPicture,			 (u32)&iObj_get_oLEDragPicture				  },
		{	cgc_oLEDropEffects,				sizeof(cgc_oLEDropEffects) - 1,				 (u32)&iObj_set_oLEDropEffects,			 (u32)&iObj_get_oLEDropEffects				  },
		{	cgc_oLEDropMode,				sizeof(cgc_oLEDropMode) - 1,				 (u32)&iObj_set_oLEDropMode,			 (u32)&iObj_get_oLEDropMode					  },
		{	cgc_picture,					sizeof(cgc_picture) - 1,					 (u32)&iObj_set_picture,				 (u32)&iObj_get_picture						  },
		{	cgc_pictureMargin,				sizeof(cgc_pictureMargin) - 1,				 (u32)&iObj_set_pictureMargin,			 (u32)&iObj_get_pictureMargin				  },
		{	cgc_picturePosition,			sizeof(cgc_picturePosition) - 1,			 (u32)&iObj_set_picturePosition,		 (u32)&iObj_get_picturePosition				  },
		{	cgc_pictureSpacing,				sizeof(cgc_pictureSpacing) - 1,				 (u32)&iObj_set_pictureSpacing,			 (u32)&iObj_get_pictureSpacing				  },
		{	cgc_disabledPicture,			sizeof(cgc_disabledPicture) - 1,			 (u32)&iObj_set_disabledPicture,		 (u32)&iObj_get_disabledPicture				  },
		{	cgc_downPicture,				sizeof(cgc_downPicture) - 1,				 (u32)&iObj_set_downPicture,			 (u32)&iObj_get_downPicture					  },
		{	cgc_rightToLeft,				sizeof(cgc_rightToLeft) - 1,				 (u32)&iObj_set_rightToLeft,			 (u32)&iObj_get_rightToLeft					  },
		{	cgc_specialEffect,				sizeof(cgc_specialEffect) - 1,				 (u32)&iObj_set_specialEffect,			 (u32)&iObj_get_specialEffect				  },
		{	cgc_statusBarText,				sizeof(cgc_statusBarText) - 1,				 (u32)&iObj_set_statusBarText,			 (u32)&iObj_get_statusBarText				  },
		{	cgc_style,						sizeof(cgc_style) - 1,						 (u32)&iObj_set_style,					 (u32)&iObj_get_style						  },
		{	cgc_tabIndex,					sizeof(cgc_tabIndex) - 1,					 (u32)&iObj_set_tabIndex,				 (u32)&iObj_get_tabIndex					  },
		{	cgc_tabStop,					sizeof(cgc_tabStop) - 1,					 (u32)&iObj_set_tabStop,				 (u32)&iObj_get_tabStop						  },
		{	cgc_tag,						sizeof(cgc_tag) - 1,						 (u32)&iObj_set_tag,					 (u32)&iObj_get_tag							  },
		{	cgc_terminateRead,				sizeof(cgc_terminateRead) - 1,				 (u32)&iObj_set_terminateRead,			 (u32)&iObj_get_terminateRead				  },
		{	cgc_themes,						sizeof(cgc_themes) - 1,						 (u32)&iObj_set_themes,					 (u32)&iObj_get_themes						  },
		{	cgc_toolTipText,				sizeof(cgc_toolTipText) - 1,				 (u32)&iObj_set_toolTipText,			 (u32)&iObj_get_toolTipText					  },
		{	cgc_top,						sizeof(cgc_top) - 1,						 (u32)&iObj_set_top,					 (u32)&iObj_get_top							  },
		{	cgc_value,						sizeof(cgc_value) - 1,						 (u32)&iObj_set_value,					 (u32)&iObj_get_value						  },
		{	cgc_visible,					sizeof(cgc_visible) - 1,					 (u32)&iObj_set_visible,				 (u32)&iObj_get_visible						  },
		{	cgc_whatsThisHelpID,			sizeof(cgc_whatsThisHelpID) - 1,			 (u32)&iObj_set_whatsThisHelpID,		 (u32)&iObj_get_whatsThisHelpID				  },
		{	cgc_width,						sizeof(cgc_width) - 1,						 (u32)&iObj_set_width,					 (u32)&iObj_get_width						  },
		{	cgc_wordWrap,					sizeof(cgc_wordWrap) - 1,					 (u32)&iObj_set_wordWrap,				 (u32)&iObj_get_wordWrap					  },
		{	NULL,							0,											 0,										 0										 }
	};

	SPropertyMap gcProps_optgroup[] = 
	{
		{	cgc_anchor,						sizeof(cgc_anchor) - 1,						 (u32)&iObj_set_anchor,					 (u32)&iObj_get_anchor						  },
		{	cgc_autoSize,					sizeof(cgc_autoSize) - 1,					 (u32)&iObj_set_autoSize,				 (u32)&iObj_get_autoSize					  },
		{	cgc_backStyle,					sizeof(cgc_backStyle) - 1,					 (u32)&iObj_set_backStyle,				 (u32)&iObj_get_backStyle					  },
		{	cgc_buttonCount,				sizeof(cgc_buttonCount) - 1,				 (u32)&iObj_set_buttonCount,			 (u32)&iObj_get_buttonCount					  },
		{	cgc_borderColor,				sizeof(cgc_borderColor) - 1,				 (u32)&iObj_set_borderColor,			 (u32)&iObj_get_borderColor					  },
		{	cgc_borderStyle,				sizeof(cgc_borderStyle) - 1,				 (u32)&iObj_set_borderStyle,			 (u32)&iObj_get_borderStyle					  },
		{	cgc_colorSource,				sizeof(cgc_colorSource) - 1,				 (u32)&iObj_set_colorSource,			 (u32)&iObj_get_colorSource					  },
		{	cgc_backColor,					sizeof(cgc_backColor) - 1,					 (u32)&iObj_set_backColor,				 (u32)&iObj_get_backColor					  },
		{	cgc_comment,					sizeof(cgc_comment) - 1,					 (u32)&iObj_set_comment,				 (u32)&iObj_get_comment						  },
		{	cgc_controlSource,				sizeof(cgc_controlSource) - 1,				 (u32)&iObj_set_controlSource,			 (u32)&iObj_get_controlSource				  },
		{	cgc_dragIcon,					sizeof(cgc_dragIcon) - 1,					 (u32)&iObj_set_dragIcon,				 (u32)&iObj_get_dragIcon					  },
		{	cgc_dragMode,					sizeof(cgc_dragMode) - 1,					 (u32)&iObj_set_dragMode,				 (u32)&iObj_get_dragMode					  },
		{	cgc_enabled,					sizeof(cgc_enabled) - 1,					 (u32)&iObj_set_enabled,				 (u32)&iObj_get_enabled						  },
		{	cgc_height,						sizeof(cgc_height) - 1,						 (u32)&iObj_set_height,					 (u32)&iObj_get_height						  },
		{	cgc_helpContextID,				sizeof(cgc_helpContextID) - 1,				 (u32)&iObj_set_helpContextID,			 (u32)&iObj_get_helpContextID				  },
		{	cgc_left,						sizeof(cgc_left) - 1,						 (u32)&iObj_set_left,					 (u32)&iObj_get_left						  },
		{	cgc_memberClass,				sizeof(cgc_memberClass) - 1,				 (u32)&iObj_set_memberClass,			 (u32)&iObj_get_memberClass					  },
		{	cgc_memberClassLibrary,			sizeof(cgc_memberClassLibrary) - 1,			 (u32)&iObj_set_memberClassLibrary,		 (u32)&iObj_get_memberClassLibrary			  },
		{	cgc_mouseIcon,					sizeof(cgc_mouseIcon) - 1,					 (u32)&iObj_set_mouseIcon,				 (u32)&iObj_get_mouseIcon					  },
		{	cgc_mousePointer,				sizeof(cgc_mousePointer) - 1,				 (u32)&iObj_set_mousePointer,			 (u32)&iObj_get_mousePointer				  },
		{	cgc_name,						sizeof(cgc_name) - 1,						 (u32)&iObj_set_name,					 (u32)&iObj_get_name						  },
		{	cgc_oLEDragMode,				sizeof(cgc_oLEDragMode) - 1,				 (u32)&iObj_set_oLEDragMode,			 (u32)&iObj_get_oLEDragMode					  },
		{	cgc_oLEDragPicture,				sizeof(cgc_oLEDragPicture) - 1,				 (u32)&iObj_set_oLEDragPicture,			 (u32)&iObj_get_oLEDragPicture				  },
		{	cgc_oLEDropEffects,				sizeof(cgc_oLEDropEffects) - 1,				 (u32)&iObj_set_oLEDropEffects,			 (u32)&iObj_get_oLEDropEffects				  },
		{	cgc_oLEDropMode,				sizeof(cgc_oLEDropMode) - 1,				 (u32)&iObj_set_oLEDropMode,			 (u32)&iObj_get_oLEDropMode					  },
		{	cgc_specialEffect,				sizeof(cgc_specialEffect) - 1,				 (u32)&iObj_set_specialEffect,			 (u32)&iObj_get_specialEffect				  },
		{	cgc_statusBarText,				sizeof(cgc_statusBarText) - 1,				 (u32)&iObj_set_statusBarText,			 (u32)&iObj_get_statusBarText				  },
		{	cgc_tabIndex,					sizeof(cgc_tabIndex) - 1,					 (u32)&iObj_set_tabIndex,				 (u32)&iObj_get_tabIndex					  },
		{	cgc_tag,						sizeof(cgc_tag) - 1,						 (u32)&iObj_set_tag,					 (u32)&iObj_get_tag							  },
		{	cgc_terminateRead,				sizeof(cgc_terminateRead) - 1,				 (u32)&iObj_set_terminateRead,			 (u32)&iObj_get_terminateRead				  },
		{	cgc_themes,						sizeof(cgc_themes) - 1,						 (u32)&iObj_set_themes,					 (u32)&iObj_get_themes						  },
		{	cgc_toolTipText,				sizeof(cgc_toolTipText) - 1,				 (u32)&iObj_set_toolTipText,			 (u32)&iObj_get_toolTipText					  },
		{	cgc_top,						sizeof(cgc_top) - 1,						 (u32)&iObj_set_top,					 (u32)&iObj_get_top							  },
		{	cgc_value,						sizeof(cgc_value) - 1,						 (u32)&iObj_set_value,					 (u32)&iObj_get_value						  },
		{	cgc_visible,					sizeof(cgc_visible) - 1,					 (u32)&iObj_set_visible,				 (u32)&iObj_get_visible						  },
		{	cgc_whatsThisHelpID,			sizeof(cgc_whatsThisHelpID) - 1,			 (u32)&iObj_set_whatsThisHelpID,		 (u32)&iObj_get_whatsThisHelpID				  },
		{	cgc_width,						sizeof(cgc_width) - 1,						 (u32)&iObj_set_width,					 (u32)&iObj_get_width						  },
		{	NULL,							0,											 0,										 0										 }
	};

	SPropertyMap gcProps_textbox[] = 
	{
		{	cgc_alignment,					sizeof(cgc_alignment) - 1,					 (u32)&iObj_set_alignment,				 (u32)&iObj_get_alignment					  },
		{	cgc_anchor,						sizeof(cgc_anchor) - 1,						 (u32)&iObj_set_anchor,					 (u32)&iObj_get_anchor						  },
		{	cgc_application,				sizeof(cgc_application) - 1,				 (u32)&iObj_set_application,			 (u32)&iObj_get_application					  },
		{	cgc_autoComplete,				sizeof(cgc_autoComplete) - 1,				 (u32)&iObj_set_autoComplete,			 (u32)&iObj_get_autoComplete				  },
		{	cgc_autoCompTable,				sizeof(cgc_autoCompTable) - 1,				 (u32)&iObj_set_autoCompTable,			 (u32)&iObj_get_autoCompTable				  },
		{	cgc_autoCompSource,				sizeof(cgc_autoCompSource) - 1,				 (u32)&iObj_set_autoCompSource,			 (u32)&iObj_get_autoCompSource				  },
		{	cgc_backStyle,					sizeof(cgc_backStyle) - 1,					 (u32)&iObj_set_backStyle,				 (u32)&iObj_get_backStyle					  },
		{	cgc_baseClass,					sizeof(cgc_baseClass) - 1,					 (u32)&iObj_set_baseClass,				 (u32)&iObj_get_baseClass					  },
		{	cgc_class,						sizeof(cgc_class) - 1,						 (u32)&iObj_set_class,					 (u32)&iObj_get_class						  },
		{	cgc_classLibrary,				sizeof(cgc_classLibrary) - 1,				 (u32)&iObj_set_classLibrary,			 (u32)&iObj_get_classLibrary				  },
		{	cgc_borderColor,				sizeof(cgc_borderColor) - 1,				 (u32)&iObj_set_borderColor,			 (u32)&iObj_get_borderColor					  },
		{	cgc_borderStyle,				sizeof(cgc_borderStyle) - 1,				 (u32)&iObj_set_borderStyle,			 (u32)&iObj_get_borderStyle					  },
		{	cgc_century,					sizeof(cgc_century) - 1,					 (u32)&iObj_set_century,				 (u32)&iObj_get_century						  },
		{	cgc_colorScheme,				sizeof(cgc_colorScheme) - 1,				 (u32)&iObj_set_colorScheme,			 (u32)&iObj_get_colorScheme					  },
		{	cgc_colorSource,				sizeof(cgc_colorSource) - 1,				 (u32)&iObj_set_colorSource,			 (u32)&iObj_get_colorSource					  },
		{	cgc_foreColor,					sizeof(cgc_foreColor) - 1,					 (u32)&iObj_set_foreColor,				 (u32)&iObj_get_foreColor					  },
		{	cgc_backColor,					sizeof(cgc_backColor) - 1,					 (u32)&iObj_set_backColor,				 (u32)&iObj_get_backColor					  },
		{	cgc_disabledBackColor,			sizeof(cgc_disabledBackColor) - 1,			 (u32)&iObj_set_disabledBackColor,		 (u32)&iObj_get_disabledBackColor			  },
		{	cgc_disabledForeColor,			sizeof(cgc_disabledForeColor) - 1,			 (u32)&iObj_set_disabledForeColor,		 (u32)&iObj_get_disabledForeColor			  },
		{	cgc_comment,					sizeof(cgc_comment) - 1,					 (u32)&iObj_set_comment,				 (u32)&iObj_get_comment						  },
		{	cgc_controlSource,				sizeof(cgc_controlSource) - 1,				 (u32)&iObj_set_controlSource,			 (u32)&iObj_get_controlSource				  },
		{	cgc_dateFormat,					sizeof(cgc_dateFormat) - 1,					 (u32)&iObj_set_dateFormat,				 (u32)&iObj_get_dateFormat					  },
		{	cgc_dateMark,					sizeof(cgc_dateMark) - 1,					 (u32)&iObj_set_dateMark,				 (u32)&iObj_get_dateMark					  },
		{	cgc_dragIcon,					sizeof(cgc_dragIcon) - 1,					 (u32)&iObj_set_dragIcon,				 (u32)&iObj_get_dragIcon					  },
		{	cgc_dragMode,					sizeof(cgc_dragMode) - 1,					 (u32)&iObj_set_dragMode,				 (u32)&iObj_get_dragMode					  },
		{	cgc_enabled,					sizeof(cgc_enabled) - 1,					 (u32)&iObj_set_enabled,				 (u32)&iObj_get_enabled						  },
		{	cgc_enableHyperlinks,			sizeof(cgc_enableHyperlinks) - 1,			 (u32)&iObj_set_enableHyperlinks,		 (u32)&iObj_get_enableHyperlinks			  },
		{	cgc_fontBold,					sizeof(cgc_fontBold) - 1,					 (u32)&iObj_set_fontBold,				 (u32)&iObj_get_fontBold					  },
		{	cgc_fontCharSet,				sizeof(cgc_fontCharSet) - 1,				 (u32)&iObj_set_fontCharSet,			 (u32)&iObj_get_fontCharSet					  },
		{	cgc_fontCondense,				sizeof(cgc_fontCondense) - 1,				 (u32)&iObj_set_fontCondense,			 (u32)&iObj_get_fontCondense				  },
		{	cgc_fontExtend,					sizeof(cgc_fontExtend) - 1,					 (u32)&iObj_set_fontExtend,				 (u32)&iObj_get_fontExtend					  },
		{	cgc_fontItalic,					sizeof(cgc_fontItalic) - 1,					 (u32)&iObj_set_fontItalic,				 (u32)&iObj_get_fontItalic					  },
		{	cgc_fontName,					sizeof(cgc_fontName) - 1,					 (u32)&iObj_set_fontName,				 (u32)&iObj_get_fontName					  },
		{	cgc_fontOutline,				sizeof(cgc_fontOutline) - 1,				 (u32)&iObj_set_fontOutline,			 (u32)&iObj_get_fontOutline					  },
		{	cgc_fontShadow,					sizeof(cgc_fontShadow) - 1,					 (u32)&iObj_set_fontShadow,				 (u32)&iObj_get_fontShadow					  },
		{	cgc_fontSize,					sizeof(cgc_fontSize) - 1,					 (u32)&iObj_set_fontSize,				 (u32)&iObj_get_fontSize					  },
		{	cgc_fontStrikeThru,				sizeof(cgc_fontStrikeThru) - 1,				 (u32)&iObj_set_fontStrikeThru,			 (u32)&iObj_get_fontStrikeThru				  },
		{	cgc_fontUnderline,				sizeof(cgc_fontUnderline) - 1,				 (u32)&iObj_set_fontUnderline,			 (u32)&iObj_get_fontUnderline				  },
		{	cgc_format,						sizeof(cgc_format) - 1,						 (u32)&iObj_set_format,					 (u32)&iObj_get_format						  },
		{	cgc_height,						sizeof(cgc_height) - 1,						 (u32)&iObj_set_height,					 (u32)&iObj_get_height						  },
		{	cgc_helpContextID,				sizeof(cgc_helpContextID) - 1,				 (u32)&iObj_set_helpContextID,			 (u32)&iObj_get_helpContextID				  },
		{	cgc_hideSelection,				sizeof(cgc_hideSelection) - 1,				 (u32)&iObj_set_hideSelection,			 (u32)&iObj_get_hideSelection				  },
		{	cgc_hours,						sizeof(cgc_hours) - 1,						 (u32)&iObj_set_hours,					 (u32)&iObj_get_hours						  },
		{	cgc_iMEMode,					sizeof(cgc_iMEMode) - 1,					 (u32)&iObj_set_iMEMode,				 (u32)&iObj_get_iMEMode						  },
		{	cgc_inputMask,					sizeof(cgc_inputMask) - 1,					 (u32)&iObj_set_inputMask,				 (u32)&iObj_get_inputMask					  },
		{	cgc_integralHeight,				sizeof(cgc_integralHeight) - 1,				 (u32)&iObj_set_integralHeight,			 (u32)&iObj_get_integralHeight				  },
		{	cgc_left,						sizeof(cgc_left) - 1,						 (u32)&iObj_set_left,					 (u32)&iObj_get_left						  },
		{	cgc_margin,						sizeof(cgc_margin) - 1,						 (u32)&iObj_set_margin,					 (u32)&iObj_get_margin						  },
		{	cgc_maxLength,					sizeof(cgc_maxLength) - 1,					 (u32)&iObj_set_maxLength,				 (u32)&iObj_get_maxLength					  },
		{	cgc_mouseIcon,					sizeof(cgc_mouseIcon) - 1,					 (u32)&iObj_set_mouseIcon,				 (u32)&iObj_get_mouseIcon					  },
		{	cgc_mousePointer,				sizeof(cgc_mousePointer) - 1,				 (u32)&iObj_set_mousePointer,			 (u32)&iObj_get_mousePointer				  },
		{	cgc_memoWindow,					sizeof(cgc_memoWindow) - 1,					 (u32)&iObj_set_memoWindow,				 (u32)&iObj_get_memoWindow					  },
		{	cgc_name,						sizeof(cgc_name) - 1,						 (u32)&iObj_set_name,					 (u32)&iObj_get_name						  },
		{	cgc_nullDisplay,				sizeof(cgc_nullDisplay) - 1,				 (u32)&iObj_set_nullDisplay,			 (u32)&iObj_get_nullDisplay					  },
		{	cgc_oLEDragMode,				sizeof(cgc_oLEDragMode) - 1,				 (u32)&iObj_set_oLEDragMode,			 (u32)&iObj_get_oLEDragMode					  },
		{	cgc_oLEDragPicture,				sizeof(cgc_oLEDragPicture) - 1,				 (u32)&iObj_set_oLEDragPicture,			 (u32)&iObj_get_oLEDragPicture				  },
		{	cgc_oLEDropEffects,				sizeof(cgc_oLEDropEffects) - 1,				 (u32)&iObj_set_oLEDropEffects,			 (u32)&iObj_get_oLEDropEffects				  },
		{	cgc_oLEDropHasData,				sizeof(cgc_oLEDropHasData) - 1,				 (u32)&iObj_set_oLEDropHasData,			 (u32)&iObj_get_oLEDropHasData				  },
		{	cgc_oLEDropMode,				sizeof(cgc_oLEDropMode) - 1,				 (u32)&iObj_set_oLEDropMode,			 (u32)&iObj_get_oLEDropMode					  },
		{	cgc_oLEDropTextInsertion,		sizeof(cgc_oLEDropTextInsertion) - 1,		 (u32)&iObj_set_oLEDropTextInsertion,	 (u32)&iObj_get_oLEDropTextInsertion		  },
		{	cgc_openWindow,					sizeof(cgc_openWindow) - 1,					 (u32)&iObj_set_openWindow,				 (u32)&iObj_get_openWindow					  },
		{	cgc_parent,						sizeof(cgc_parent) - 1,						 (u32)&iObj_set_parent,					 (u32)&iObj_get_parent						  },
		{	cgc_parentClass,				sizeof(cgc_parentClass) - 1,				 (u32)&iObj_set_parentClass,			 (u32)&iObj_get_parentClass					  },
		{	cgc_passwordChar,				sizeof(cgc_passwordChar) - 1,				 (u32)&iObj_set_passwordChar,			 (u32)&iObj_get_passwordChar				  },
		{	cgc_readOnly,					sizeof(cgc_readOnly) - 1,					 (u32)&iObj_set_readOnly,				 (u32)&iObj_get_readOnly					  },
		{	cgc_rightToLeft,				sizeof(cgc_rightToLeft) - 1,				 (u32)&iObj_set_rightToLeft,			 (u32)&iObj_get_rightToLeft					  },
		{	cgc_seconds,					sizeof(cgc_seconds) - 1,					 (u32)&iObj_set_seconds,				 (u32)&iObj_get_seconds						  },
		{	cgc_selectedBackColor,			sizeof(cgc_selectedBackColor) - 1,			 (u32)&iObj_set_selectedBackColor,		 (u32)&iObj_get_selectedBackColor			  },
		{	cgc_selectedForeColor,			sizeof(cgc_selectedForeColor) - 1,			 (u32)&iObj_set_selectedForeColor,		 (u32)&iObj_get_selectedForeColor			  },
		{	cgc_selectOnEntry,				sizeof(cgc_selectOnEntry) - 1,				 (u32)&iObj_set_selectOnEntry,			 (u32)&iObj_get_selectOnEntry				  },
		{	cgc_selLength,					sizeof(cgc_selLength) - 1,					 (u32)&iObj_set_selLength,				 (u32)&iObj_get_selLength					  },
		{	cgc_selStart,					sizeof(cgc_selStart) - 1,					 (u32)&iObj_set_selStart,				 (u32)&iObj_get_selStart					  },
		{	cgc_selText,					sizeof(cgc_selText) - 1,					 (u32)&iObj_set_selText,				 (u32)&iObj_get_selText						  },
		{	cgc_specialEffect,				sizeof(cgc_specialEffect) - 1,				 (u32)&iObj_set_specialEffect,			 (u32)&iObj_get_specialEffect				  },
		{	cgc_statusBarText,				sizeof(cgc_statusBarText) - 1,				 (u32)&iObj_set_statusBarText,			 (u32)&iObj_get_statusBarText				  },
		{	cgc_strictDateEntry,			sizeof(cgc_strictDateEntry) - 1,			 (u32)&iObj_set_strictDateEntry,		 (u32)&iObj_get_strictDateEntry				  },
		{	cgc_style,						sizeof(cgc_style) - 1,						 (u32)&iObj_set_style,					 (u32)&iObj_get_style						  },
		{	cgc_tabIndex,					sizeof(cgc_tabIndex) - 1,					 (u32)&iObj_set_tabIndex,				 (u32)&iObj_get_tabIndex					  },
		{	cgc_tabStop,					sizeof(cgc_tabStop) - 1,					 (u32)&iObj_set_tabStop,				 (u32)&iObj_get_tabStop						  },
		{	cgc_tag,						sizeof(cgc_tag) - 1,						 (u32)&iObj_set_tag,					 (u32)&iObj_get_tag							  },
		{	cgc_terminateRead,				sizeof(cgc_terminateRead) - 1,				 (u32)&iObj_set_terminateRead,			 (u32)&iObj_get_terminateRead				  },
		{	cgc_text,						sizeof(cgc_text) - 1,						 (u32)&iObj_set_text,					 (u32)&iObj_get_text						  },
		{	cgc_themes,						sizeof(cgc_themes) - 1,						 (u32)&iObj_set_themes,					 (u32)&iObj_get_themes						  },
		{	cgc_toolTipText,				sizeof(cgc_toolTipText) - 1,				 (u32)&iObj_set_toolTipText,			 (u32)&iObj_get_toolTipText					  },
		{	cgc_top,						sizeof(cgc_top) - 1,						 (u32)&iObj_set_top,					 (u32)&iObj_get_top							  },
		{	cgc_value,						sizeof(cgc_value) - 1,						 (u32)&iObj_set_value,					 (u32)&iObj_get_value						  },
		{	cgc_visible,					sizeof(cgc_visible) - 1,					 (u32)&iObj_set_visible,				 (u32)&iObj_get_visible						  },
		{	cgc_whatsThisHelpID,			sizeof(cgc_whatsThisHelpID) - 1,			 (u32)&iObj_set_whatsThisHelpID,		 (u32)&iObj_get_whatsThisHelpID				  },
		{	cgc_width,						sizeof(cgc_width) - 1,						 (u32)&iObj_set_width,					 (u32)&iObj_get_width						  },
		{	NULL,							0,											 0,										 0										 }
	};

	SPropertyMap gcProps_editbox[] = 
	{
		{	cgc_addLineFeeds,				sizeof(cgc_addLineFeeds) - 1,				 (u32)&iObj_set_addLineFeeds,			 (u32)&iObj_get_addLineFeeds				  },
		{	cgc_alignment,					sizeof(cgc_alignment) - 1,					 (u32)&iObj_set_alignment,				 (u32)&iObj_get_alignment					  },
		{	cgc_allowTabs,					sizeof(cgc_allowTabs) - 1,					 (u32)&iObj_set_allowTabs,				 (u32)&iObj_get_allowTabs					  },
		{	cgc_anchor,						sizeof(cgc_anchor) - 1,						 (u32)&iObj_set_anchor,					 (u32)&iObj_get_anchor						  },
		{	cgc_application,				sizeof(cgc_application) - 1,				 (u32)&iObj_set_application,			 (u32)&iObj_get_application					  },
		{	cgc_backStyle,					sizeof(cgc_backStyle) - 1,					 (u32)&iObj_set_backStyle,				 (u32)&iObj_get_backStyle					  },
		{	cgc_baseClass,					sizeof(cgc_baseClass) - 1,					 (u32)&iObj_set_baseClass,				 (u32)&iObj_get_baseClass					  },
		{	cgc_class,						sizeof(cgc_class) - 1,						 (u32)&iObj_set_class,					 (u32)&iObj_get_class						  },
		{	cgc_classLibrary,				sizeof(cgc_classLibrary) - 1,				 (u32)&iObj_set_classLibrary,			 (u32)&iObj_get_classLibrary				  },
		{	cgc_borderColor,				sizeof(cgc_borderColor) - 1,				 (u32)&iObj_set_borderColor,			 (u32)&iObj_get_borderColor					  },
		{	cgc_borderStyle,				sizeof(cgc_borderStyle) - 1,				 (u32)&iObj_set_borderStyle,			 (u32)&iObj_get_borderStyle					  },
		{	cgc_colorScheme,				sizeof(cgc_colorScheme) - 1,				 (u32)&iObj_set_colorScheme,			 (u32)&iObj_get_colorScheme					  },
		{	cgc_colorSource,				sizeof(cgc_colorSource) - 1,				 (u32)&iObj_set_colorSource,			 (u32)&iObj_get_colorSource					  },
		{	cgc_foreColor,					sizeof(cgc_foreColor) - 1,					 (u32)&iObj_set_foreColor,				 (u32)&iObj_get_foreColor					  },
		{	cgc_backColor,					sizeof(cgc_backColor) - 1,					 (u32)&iObj_set_backColor,				 (u32)&iObj_get_backColor					  },
		{	cgc_disabledBackColor,			sizeof(cgc_disabledBackColor) - 1,			 (u32)&iObj_set_disabledBackColor,		 (u32)&iObj_get_disabledBackColor			  },
		{	cgc_disabledForeColor,			sizeof(cgc_disabledForeColor) - 1,			 (u32)&iObj_set_disabledForeColor,		 (u32)&iObj_get_disabledForeColor			  },
		{	cgc_comment,					sizeof(cgc_comment) - 1,					 (u32)&iObj_set_comment,				 (u32)&iObj_get_comment						  },
		{	cgc_controlSource,				sizeof(cgc_controlSource) - 1,				 (u32)&iObj_set_controlSource,			 (u32)&iObj_get_controlSource				  },
		{	cgc_dragIcon,					sizeof(cgc_dragIcon) - 1,					 (u32)&iObj_set_dragIcon,				 (u32)&iObj_get_dragIcon					  },
		{	cgc_dragMode,					sizeof(cgc_dragMode) - 1,					 (u32)&iObj_set_dragMode,				 (u32)&iObj_get_dragMode					  },
		{	cgc_enabled,					sizeof(cgc_enabled) - 1,					 (u32)&iObj_set_enabled,				 (u32)&iObj_get_enabled						  },
		{	cgc_enableHyperlinks,			sizeof(cgc_enableHyperlinks) - 1,			 (u32)&iObj_set_enableHyperlinks,		 (u32)&iObj_get_enableHyperlinks			  },
		{	cgc_fontBold,					sizeof(cgc_fontBold) - 1,					 (u32)&iObj_set_fontBold,				 (u32)&iObj_get_fontBold					  },
		{	cgc_fontCharSet,				sizeof(cgc_fontCharSet) - 1,				 (u32)&iObj_set_fontCharSet,			 (u32)&iObj_get_fontCharSet					  },
		{	cgc_fontCondense,				sizeof(cgc_fontCondense) - 1,				 (u32)&iObj_set_fontCondense,			 (u32)&iObj_get_fontCondense				  },
		{	cgc_fontExtend,					sizeof(cgc_fontExtend) - 1,					 (u32)&iObj_set_fontExtend,				 (u32)&iObj_get_fontExtend					  },
		{	cgc_fontItalic,					sizeof(cgc_fontItalic) - 1,					 (u32)&iObj_set_fontItalic,				 (u32)&iObj_get_fontItalic					  },
		{	cgc_fontName,					sizeof(cgc_fontName) - 1,					 (u32)&iObj_set_fontName,				 (u32)&iObj_get_fontName					  },
		{	cgc_fontOutline,				sizeof(cgc_fontOutline) - 1,				 (u32)&iObj_set_fontOutline,			 (u32)&iObj_get_fontOutline					  },
		{	cgc_fontShadow,					sizeof(cgc_fontShadow) - 1,					 (u32)&iObj_set_fontShadow,				 (u32)&iObj_get_fontShadow					  },
		{	cgc_fontSize,					sizeof(cgc_fontSize) - 1,					 (u32)&iObj_set_fontSize,				 (u32)&iObj_get_fontSize					  },
		{	cgc_fontStrikeThru,				sizeof(cgc_fontStrikeThru) - 1,				 (u32)&iObj_set_fontStrikeThru,			 (u32)&iObj_get_fontStrikeThru				  },
		{	cgc_fontUnderline,				sizeof(cgc_fontUnderline) - 1,				 (u32)&iObj_set_fontUnderline,			 (u32)&iObj_get_fontUnderline				  },
		{	cgc_format,						sizeof(cgc_format) - 1,						 (u32)&iObj_set_format,					 (u32)&iObj_get_format						  },
		{	cgc_height,						sizeof(cgc_height) - 1,						 (u32)&iObj_set_height,					 (u32)&iObj_get_height						  },
		{	cgc_helpContextID,				sizeof(cgc_helpContextID) - 1,				 (u32)&iObj_set_helpContextID,			 (u32)&iObj_get_helpContextID				  },
		{	cgc_hideSelection,				sizeof(cgc_hideSelection) - 1,				 (u32)&iObj_set_hideSelection,			 (u32)&iObj_get_hideSelection				  },
		{	cgc_iMEMode,					sizeof(cgc_iMEMode) - 1,					 (u32)&iObj_set_iMEMode,				 (u32)&iObj_get_iMEMode						  },
		{	cgc_integralHeight,				sizeof(cgc_integralHeight) - 1,				 (u32)&iObj_set_integralHeight,			 (u32)&iObj_get_integralHeight				  },
		{	cgc_left,						sizeof(cgc_left) - 1,						 (u32)&iObj_set_left,					 (u32)&iObj_get_left						  },
		{	cgc_margin,						sizeof(cgc_margin) - 1,						 (u32)&iObj_set_margin,					 (u32)&iObj_get_margin						  },
		{	cgc_maxLength,					sizeof(cgc_maxLength) - 1,					 (u32)&iObj_set_maxLength,				 (u32)&iObj_get_maxLength					  },
		{	cgc_mouseIcon,					sizeof(cgc_mouseIcon) - 1,					 (u32)&iObj_set_mouseIcon,				 (u32)&iObj_get_mouseIcon					  },
		{	cgc_mousePointer,				sizeof(cgc_mousePointer) - 1,				 (u32)&iObj_set_mousePointer,			 (u32)&iObj_get_mousePointer				  },
		{	cgc_name,						sizeof(cgc_name) - 1,						 (u32)&iObj_set_name,					 (u32)&iObj_get_name						  },
		{	cgc_nullDisplay,				sizeof(cgc_nullDisplay) - 1,				 (u32)&iObj_set_nullDisplay,			 (u32)&iObj_get_nullDisplay					  },
		{	cgc_oLEDragMode,				sizeof(cgc_oLEDragMode) - 1,				 (u32)&iObj_set_oLEDragMode,			 (u32)&iObj_get_oLEDragMode					  },
		{	cgc_oLEDragPicture,				sizeof(cgc_oLEDragPicture) - 1,				 (u32)&iObj_set_oLEDragPicture,			 (u32)&iObj_get_oLEDragPicture				  },
		{	cgc_oLEDropEffects,				sizeof(cgc_oLEDropEffects) - 1,				 (u32)&iObj_set_oLEDropEffects,			 (u32)&iObj_get_oLEDropEffects				  },
		{	cgc_oLEDropHasData,				sizeof(cgc_oLEDropHasData) - 1,				 (u32)&iObj_set_oLEDropHasData,			 (u32)&iObj_get_oLEDropHasData				  },
		{	cgc_oLEDropMode,				sizeof(cgc_oLEDropMode) - 1,				 (u32)&iObj_set_oLEDropMode,			 (u32)&iObj_get_oLEDropMode					  },
		{	cgc_oLEDropTextInsertion,		sizeof(cgc_oLEDropTextInsertion) - 1,		 (u32)&iObj_set_oLEDropTextInsertion,	 (u32)&iObj_get_oLEDropTextInsertion		  },
		{	cgc_parent,						sizeof(cgc_parent) - 1,						 (u32)&iObj_set_parent,					 (u32)&iObj_get_parent						  },
		{	cgc_parentClass,				sizeof(cgc_parentClass) - 1,				 (u32)&iObj_set_parentClass,			 (u32)&iObj_get_parentClass					  },
		{	cgc_passwordChar,				sizeof(cgc_passwordChar) - 1,				 (u32)&iObj_set_passwordChar,			 (u32)&iObj_get_passwordChar				  },
		{	cgc_readOnly,					sizeof(cgc_readOnly) - 1,					 (u32)&iObj_set_readOnly,				 (u32)&iObj_get_readOnly					  },
		{	cgc_rightToLeft,				sizeof(cgc_rightToLeft) - 1,				 (u32)&iObj_set_rightToLeft,			 (u32)&iObj_get_rightToLeft					  },
		{	cgc_scrollBars,					sizeof(cgc_scrollBars) - 1,					 (u32)&iObj_set_scrollBars,				 (u32)&iObj_get_scrollBars					  },
		{	cgc_selectedBackColor,			sizeof(cgc_selectedBackColor) - 1,			 (u32)&iObj_set_selectedBackColor,		 (u32)&iObj_get_selectedBackColor			  },
		{	cgc_selectedForeColor,			sizeof(cgc_selectedForeColor) - 1,			 (u32)&iObj_set_selectedForeColor,		 (u32)&iObj_get_selectedForeColor			  },
		{	cgc_selectOnEntry,				sizeof(cgc_selectOnEntry) - 1,				 (u32)&iObj_set_selectOnEntry,			 (u32)&iObj_get_selectOnEntry				  },
		{	cgc_selLength,					sizeof(cgc_selLength) - 1,					 (u32)&iObj_set_selLength,				 (u32)&iObj_get_selLength					  },
		{	cgc_selStart,					sizeof(cgc_selStart) - 1,					 (u32)&iObj_set_selStart,				 (u32)&iObj_get_selStart					  },
		{	cgc_selText,					sizeof(cgc_selText) - 1,					 (u32)&iObj_set_selText,				 (u32)&iObj_get_selText						  },
		{	cgc_specialEffect,				sizeof(cgc_specialEffect) - 1,				 (u32)&iObj_set_specialEffect,			 (u32)&iObj_get_specialEffect				  },
		{	cgc_statusBarText,				sizeof(cgc_statusBarText) - 1,				 (u32)&iObj_set_statusBarText,			 (u32)&iObj_get_statusBarText				  },
		{	cgc_tabIndex,					sizeof(cgc_tabIndex) - 1,					 (u32)&iObj_set_tabIndex,				 (u32)&iObj_get_tabIndex					  },
		{	cgc_tabStop,					sizeof(cgc_tabStop) - 1,					 (u32)&iObj_set_tabStop,				 (u32)&iObj_get_tabStop						  },
		{	cgc_tag,						sizeof(cgc_tag) - 1,						 (u32)&iObj_set_tag,					 (u32)&iObj_get_tag							  },
		{	cgc_terminateRead,				sizeof(cgc_terminateRead) - 1,				 (u32)&iObj_set_terminateRead,			 (u32)&iObj_get_terminateRead				  },
		{	cgc_text,						sizeof(cgc_text) - 1,						 (u32)&iObj_set_text,					 (u32)&iObj_get_text						  },
		{	cgc_toolTipText,				sizeof(cgc_toolTipText) - 1,				 (u32)&iObj_set_toolTipText,			 (u32)&iObj_get_toolTipText					  },
		{	cgc_top,						sizeof(cgc_top) - 1,						 (u32)&iObj_set_top,					 (u32)&iObj_get_top							  },
		{	cgc_value,						sizeof(cgc_value) - 1,						 (u32)&iObj_set_value,					 (u32)&iObj_get_value						  },
		{	cgc_visible,					sizeof(cgc_visible) - 1,					 (u32)&iObj_set_visible,				 (u32)&iObj_get_visible						  },
		{	cgc_whatsThisHelpID,			sizeof(cgc_whatsThisHelpID) - 1,			 (u32)&iObj_set_whatsThisHelpID,		 (u32)&iObj_get_whatsThisHelpID				  },
		{	cgc_width,						sizeof(cgc_width) - 1,						 (u32)&iObj_set_width,					 (u32)&iObj_get_width						  },
		{	NULL,							0,											 0,										 0										 }
	};

	SPropertyMap gcProps_listbox[] = 
	{
		{	cgc_anchor,						sizeof(cgc_anchor) - 1,						 (u32)&iObj_set_anchor,					 (u32)&iObj_get_anchor						  },
		{	cgc_application,				sizeof(cgc_application) - 1,				 (u32)&iObj_set_application,			 (u32)&iObj_get_application					  },
		{	cgc_autoHideScrollBar,			sizeof(cgc_autoHideScrollBar) - 1,			 (u32)&iObj_set_autoHideScrollBar,		 (u32)&iObj_get_autoHideScrollBar			  },
		{	cgc_baseClass,					sizeof(cgc_baseClass) - 1,					 (u32)&iObj_set_baseClass,				 (u32)&iObj_get_baseClass					  },
		{	cgc_class,						sizeof(cgc_class) - 1,						 (u32)&iObj_set_class,					 (u32)&iObj_get_class						  },
		{	cgc_classLibrary,				sizeof(cgc_classLibrary) - 1,				 (u32)&iObj_set_classLibrary,			 (u32)&iObj_get_classLibrary				  },
		{	cgc_listCount,					sizeof(cgc_listCount) - 1,					 (u32)&iObj_set_listCount,				 (u32)&iObj_get_listCount					  },
		{	cgc_columnCount,				sizeof(cgc_columnCount) - 1,				 (u32)&iObj_set_columnCount,			 (u32)&iObj_get_columnCount					  },
		{	cgc_borderColor,				sizeof(cgc_borderColor) - 1,				 (u32)&iObj_set_borderColor,			 (u32)&iObj_get_borderColor					  },
		{	cgc_boundColumn,				sizeof(cgc_boundColumn) - 1,				 (u32)&iObj_set_boundColumn,			 (u32)&iObj_get_boundColumn					  },
		{	cgc_boundTo,					sizeof(cgc_boundTo) - 1,					 (u32)&iObj_set_boundTo,				 (u32)&iObj_get_boundTo						  },
		{	cgc_colorScheme,				sizeof(cgc_colorScheme) - 1,				 (u32)&iObj_set_colorScheme,			 (u32)&iObj_get_colorScheme					  },
		{	cgc_colorSource,				sizeof(cgc_colorSource) - 1,				 (u32)&iObj_set_colorSource,			 (u32)&iObj_get_colorSource					  },
		{	cgc_disabledBackColor,			sizeof(cgc_disabledBackColor) - 1,			 (u32)&iObj_set_disabledBackColor,		 (u32)&iObj_get_disabledBackColor			  },
		{	cgc_disabledForeColor,			sizeof(cgc_disabledForeColor) - 1,			 (u32)&iObj_set_disabledForeColor,		 (u32)&iObj_get_disabledForeColor			  },
		{	cgc_disabledItemBackColor,		sizeof(cgc_disabledItemBackColor) - 1,		 (u32)&iObj_set_disabledItemBackColor,	 (u32)&iObj_get_disabledItemBackColor		  },
		{	cgc_disabledItemForeColor,		sizeof(cgc_disabledItemForeColor) - 1,		 (u32)&iObj_set_disabledItemForeColor,	 (u32)&iObj_get_disabledItemForeColor		  },
		{	cgc_columnLines,				sizeof(cgc_columnLines) - 1,				 (u32)&iObj_set_columnLines,			 (u32)&iObj_get_columnLines					  },
		{	cgc_columnWidths,				sizeof(cgc_columnWidths) - 1,				 (u32)&iObj_set_columnWidths,			 (u32)&iObj_get_columnWidths				  },
		{	cgc_comment,					sizeof(cgc_comment) - 1,					 (u32)&iObj_set_comment,				 (u32)&iObj_get_comment						  },
		{	cgc_controlSource,				sizeof(cgc_controlSource) - 1,				 (u32)&iObj_set_controlSource,			 (u32)&iObj_get_controlSource				  },
		{	cgc_rowSource,					sizeof(cgc_rowSource) - 1,					 (u32)&iObj_set_rowSource,				 (u32)&iObj_get_rowSource					  },
		{	cgc_rowSourceType,				sizeof(cgc_rowSourceType) - 1,				 (u32)&iObj_set_rowSourceType,			 (u32)&iObj_get_rowSourceType				  },
		{	cgc_displayValue,				sizeof(cgc_displayValue) - 1,				 (u32)&iObj_set_displayValue,			 (u32)&iObj_get_displayValue				  },
		{	cgc_dragIcon,					sizeof(cgc_dragIcon) - 1,					 (u32)&iObj_set_dragIcon,				 (u32)&iObj_get_dragIcon					  },
		{	cgc_dragMode,					sizeof(cgc_dragMode) - 1,					 (u32)&iObj_set_dragMode,				 (u32)&iObj_get_dragMode					  },
		{	cgc_enabled,					sizeof(cgc_enabled) - 1,					 (u32)&iObj_set_enabled,				 (u32)&iObj_get_enabled						  },
		{	cgc_firstElement,				sizeof(cgc_firstElement) - 1,				 (u32)&iObj_set_firstElement,			 (u32)&iObj_get_firstElement				  },
		{	cgc_fontBold,					sizeof(cgc_fontBold) - 1,					 (u32)&iObj_set_fontBold,				 (u32)&iObj_get_fontBold					  },
		{	cgc_fontCharSet,				sizeof(cgc_fontCharSet) - 1,				 (u32)&iObj_set_fontCharSet,			 (u32)&iObj_get_fontCharSet					  },
		{	cgc_fontCondense,				sizeof(cgc_fontCondense) - 1,				 (u32)&iObj_set_fontCondense,			 (u32)&iObj_get_fontCondense				  },
		{	cgc_fontExtend,					sizeof(cgc_fontExtend) - 1,					 (u32)&iObj_set_fontExtend,				 (u32)&iObj_get_fontExtend					  },
		{	cgc_fontItalic,					sizeof(cgc_fontItalic) - 1,					 (u32)&iObj_set_fontItalic,				 (u32)&iObj_get_fontItalic					  },
		{	cgc_fontName,					sizeof(cgc_fontName) - 1,					 (u32)&iObj_set_fontName,				 (u32)&iObj_get_fontName					  },
		{	cgc_fontOutline,				sizeof(cgc_fontOutline) - 1,				 (u32)&iObj_set_fontOutline,			 (u32)&iObj_get_fontOutline					  },
		{	cgc_fontShadow,					sizeof(cgc_fontShadow) - 1,					 (u32)&iObj_set_fontShadow,				 (u32)&iObj_get_fontShadow					  },
		{	cgc_fontSize,					sizeof(cgc_fontSize) - 1,					 (u32)&iObj_set_fontSize,				 (u32)&iObj_get_fontSize					  },
		{	cgc_fontStrikeThru,				sizeof(cgc_fontStrikeThru) - 1,				 (u32)&iObj_set_fontStrikeThru,			 (u32)&iObj_get_fontStrikeThru				  },
		{	cgc_fontUnderLine,				sizeof(cgc_fontUnderLine) - 1,				 (u32)&iObj_set_fontUnderLine,			 (u32)&iObj_get_fontUnderLine				  },
		{	cgc_height,						sizeof(cgc_height) - 1,						 (u32)&iObj_set_height,					 (u32)&iObj_get_height						  },
		{	cgc_helpContextID,				sizeof(cgc_helpContextID) - 1,				 (u32)&iObj_set_helpContextID,			 (u32)&iObj_get_helpContextID				  },
		{	cgc_incrementalSearch,			sizeof(cgc_incrementalSearch) - 1,			 (u32)&iObj_set_incrementalSearch,		 (u32)&iObj_get_incrementalSearch			  },
		{	cgc_integralHeight,				sizeof(cgc_integralHeight) - 1,				 (u32)&iObj_set_integralHeight,			 (u32)&iObj_get_integralHeight				  },
		{	cgc_itemBackColor,				sizeof(cgc_itemBackColor) - 1,				 (u32)&iObj_set_itemBackColor,			 (u32)&iObj_get_itemBackColor				  },
		{	cgc_itemForeColor,				sizeof(cgc_itemForeColor) - 1,				 (u32)&iObj_set_itemForeColor,			 (u32)&iObj_get_itemForeColor				  },
		{	cgc_itemData,					sizeof(cgc_itemData) - 1,					 (u32)&iObj_set_itemData,				 (u32)&iObj_get_itemData					  },
		{	cgc_itemIDData,					sizeof(cgc_itemIDData) - 1,					 (u32)&iObj_set_itemIDData,				 (u32)&iObj_get_itemIDData					  },
		{	cgc_itemTips,					sizeof(cgc_itemTips) - 1,					 (u32)&iObj_set_itemTips,				 (u32)&iObj_get_itemTips					  },
		{	cgc_left,						sizeof(cgc_left) - 1,						 (u32)&iObj_set_left,					 (u32)&iObj_get_left						  },
		{	cgc_list,						sizeof(cgc_list) - 1,						 (u32)&iObj_set_list,					 (u32)&iObj_get_list						  },
		{	cgc_listIndex,					sizeof(cgc_listIndex) - 1,					 (u32)&iObj_set_listIndex,				 (u32)&iObj_get_listIndex					  },
		{	cgc_listItem,					sizeof(cgc_listItem) - 1,					 (u32)&iObj_set_listItem,				 (u32)&iObj_get_listItem					  },
		{	cgc_listItemID,					sizeof(cgc_listItemID) - 1,					 (u32)&iObj_set_listItemID,				 (u32)&iObj_get_listItemID					  },
		{	cgc_mouseIcon,					sizeof(cgc_mouseIcon) - 1,					 (u32)&iObj_set_mouseIcon,				 (u32)&iObj_get_mouseIcon					  },
		{	cgc_mousePointer,				sizeof(cgc_mousePointer) - 1,				 (u32)&iObj_set_mousePointer,			 (u32)&iObj_get_mousePointer				  },
		{	cgc_moverBars,					sizeof(cgc_moverBars) - 1,					 (u32)&iObj_set_moverBars,				 (u32)&iObj_get_moverBars					  },
		{	cgc_multiSelect,				sizeof(cgc_multiSelect) - 1,				 (u32)&iObj_set_multiSelect,			 (u32)&iObj_get_multiSelect					  },
		{	cgc_name,						sizeof(cgc_name) - 1,						 (u32)&iObj_set_name,					 (u32)&iObj_get_name						  },
		{	cgc_newIndex,					sizeof(cgc_newIndex) - 1,					 (u32)&iObj_set_newIndex,				 (u32)&iObj_get_newIndex					  },
		{	cgc_newItemID,					sizeof(cgc_newItemID) - 1,					 (u32)&iObj_set_newItemID,				 (u32)&iObj_get_newItemID					  },
		{	cgc_nullDisplay,				sizeof(cgc_nullDisplay) - 1,				 (u32)&iObj_set_nullDisplay,			 (u32)&iObj_get_nullDisplay					  },
		{	cgc_numberOfElements,			sizeof(cgc_numberOfElements) - 1,			 (u32)&iObj_set_numberOfElements,		 (u32)&iObj_get_numberOfElements			  },
		{	cgc_oLEDragMode,				sizeof(cgc_oLEDragMode) - 1,				 (u32)&iObj_set_oLEDragMode,			 (u32)&iObj_get_oLEDragMode					  },
		{	cgc_oLEDragPicture,				sizeof(cgc_oLEDragPicture) - 1,				 (u32)&iObj_set_oLEDragPicture,			 (u32)&iObj_get_oLEDragPicture				  },
		{	cgc_oLEDropEffects,				sizeof(cgc_oLEDropEffects) - 1,				 (u32)&iObj_set_oLEDropEffects,			 (u32)&iObj_get_oLEDropEffects				  },
		{	cgc_oLEDropHasData,				sizeof(cgc_oLEDropHasData) - 1,				 (u32)&iObj_set_oLEDropHasData,			 (u32)&iObj_get_oLEDropHasData				  },
		{	cgc_oLEDropMode,				sizeof(cgc_oLEDropMode) - 1,				 (u32)&iObj_set_oLEDropMode,			 (u32)&iObj_get_oLEDropMode					  },
		{	cgc_parent,						sizeof(cgc_parent) - 1,						 (u32)&iObj_set_parent,					 (u32)&iObj_get_parent						  },
		{	cgc_parentClass,				sizeof(cgc_parentClass) - 1,				 (u32)&iObj_set_parentClass,			 (u32)&iObj_get_parentClass					  },
		{	cgc_picture,					sizeof(cgc_picture) - 1,					 (u32)&iObj_set_picture,				 (u32)&iObj_get_picture						  },
		{	cgc_rightToLeft,				sizeof(cgc_rightToLeft) - 1,				 (u32)&iObj_set_rightToLeft,			 (u32)&iObj_get_rightToLeft					  },
		{	cgc_selected,					sizeof(cgc_selected) - 1,					 (u32)&iObj_set_selected,				 (u32)&iObj_get_selected					  },
		{	cgc_selectedID,					sizeof(cgc_selectedID) - 1,					 (u32)&iObj_set_selectedID,				 (u32)&iObj_get_selectedID					  },
		{	cgc_selectedItemBackColor,		sizeof(cgc_selectedItemBackColor) - 1,		 (u32)&iObj_set_selectedItemBackColor,	 (u32)&iObj_get_selectedItemBackColor		  },
		{	cgc_selectedItemForeColor,		sizeof(cgc_selectedItemForeColor) - 1,		 (u32)&iObj_set_selectedItemForeColor,	 (u32)&iObj_get_selectedItemForeColor		  },
		{	cgc_sorted,						sizeof(cgc_sorted) - 1,						 (u32)&iObj_set_sorted,					 (u32)&iObj_get_sorted						  },
		{	cgc_specialEffect,				sizeof(cgc_specialEffect) - 1,				 (u32)&iObj_set_specialEffect,			 (u32)&iObj_get_specialEffect				  },
		{	cgc_statusBarText,				sizeof(cgc_statusBarText) - 1,				 (u32)&iObj_set_statusBarText,			 (u32)&iObj_get_statusBarText				  },
		{	cgc_tabIndex,					sizeof(cgc_tabIndex) - 1,					 (u32)&iObj_set_tabIndex,				 (u32)&iObj_get_tabIndex					  },
		{	cgc_tabStop,					sizeof(cgc_tabStop) - 1,					 (u32)&iObj_set_tabStop,				 (u32)&iObj_get_tabStop						  },
		{	cgc_tag,						sizeof(cgc_tag) - 1,						 (u32)&iObj_set_tag,					 (u32)&iObj_get_tag							  },
		{	cgc_terminateRead,				sizeof(cgc_terminateRead) - 1,				 (u32)&iObj_set_terminateRead,			 (u32)&iObj_get_terminateRead				  },
		{	cgc_themes,						sizeof(cgc_themes) - 1,						 (u32)&iObj_set_themes,					 (u32)&iObj_get_themes						  },
		{	cgc_toolTipText,				sizeof(cgc_toolTipText) - 1,				 (u32)&iObj_set_toolTipText,			 (u32)&iObj_get_toolTipText					  },
		{	cgc_top,						sizeof(cgc_top) - 1,						 (u32)&iObj_set_top,					 (u32)&iObj_get_top							  },
		{	cgc_topIndex,					sizeof(cgc_topIndex) - 1,					 (u32)&iObj_set_topIndex,				 (u32)&iObj_get_topIndex					  },
		{	cgc_topItemID,					sizeof(cgc_topItemID) - 1,					 (u32)&iObj_set_topItemID,				 (u32)&iObj_get_topItemID					  },
		{	cgc_value,						sizeof(cgc_value) - 1,						 (u32)&iObj_set_value,					 (u32)&iObj_get_value						  },
		{	cgc_visible,					sizeof(cgc_visible) - 1,					 (u32)&iObj_set_visible,				 (u32)&iObj_get_visible						  },
		{	cgc_whatsThisHelpID,			sizeof(cgc_whatsThisHelpID) - 1,			 (u32)&iObj_set_whatsThisHelpID,		 (u32)&iObj_get_whatsThisHelpID				  },
		{	cgc_width,						sizeof(cgc_width) - 1,						 (u32)&iObj_set_width,					 (u32)&iObj_get_width						  },
		{	NULL,							0,											 0,										 0										 }
	};

	SPropertyMap gcProps_combobox[] = 
	{
		{	cgc_alignment,					sizeof(cgc_alignment) - 1,					 (u32)&iObj_set_alignment,				 (u32)&iObj_get_alignment					  },
		{	cgc_anchor,						sizeof(cgc_anchor) - 1,						 (u32)&iObj_set_anchor,					 (u32)&iObj_get_anchor						  },
		{	cgc_application,				sizeof(cgc_application) - 1,				 (u32)&iObj_set_application,			 (u32)&iObj_get_application					  },
		{	cgc_baseClass,					sizeof(cgc_baseClass) - 1,					 (u32)&iObj_set_baseClass,				 (u32)&iObj_get_baseClass					  },
		{	cgc_class,						sizeof(cgc_class) - 1,						 (u32)&iObj_set_class,					 (u32)&iObj_get_class						  },
		{	cgc_classLibrary,				sizeof(cgc_classLibrary) - 1,				 (u32)&iObj_set_classLibrary,			 (u32)&iObj_get_classLibrary				  },
		{	cgc_listCount,					sizeof(cgc_listCount) - 1,					 (u32)&iObj_set_listCount,				 (u32)&iObj_get_listCount					  },
		{	cgc_columnCount,				sizeof(cgc_columnCount) - 1,				 (u32)&iObj_set_columnCount,			 (u32)&iObj_get_columnCount					  },
		{	cgc_borderColor,				sizeof(cgc_borderColor) - 1,				 (u32)&iObj_set_borderColor,			 (u32)&iObj_get_borderColor					  },
		{	cgc_borderStyle,				sizeof(cgc_borderStyle) - 1,				 (u32)&iObj_set_borderStyle,			 (u32)&iObj_get_borderStyle					  },
		{	cgc_boundColumn,				sizeof(cgc_boundColumn) - 1,				 (u32)&iObj_set_boundColumn,			 (u32)&iObj_get_boundColumn					  },
		{	cgc_boundTo,					sizeof(cgc_boundTo) - 1,					 (u32)&iObj_set_boundTo,				 (u32)&iObj_get_boundTo						  },
		{	cgc_colorScheme,				sizeof(cgc_colorScheme) - 1,				 (u32)&iObj_set_colorScheme,			 (u32)&iObj_get_colorScheme					  },
		{	cgc_colorSource,				sizeof(cgc_colorSource) - 1,				 (u32)&iObj_set_colorSource,			 (u32)&iObj_get_colorSource					  },
		{	cgc_foreColor,					sizeof(cgc_foreColor) - 1,					 (u32)&iObj_set_foreColor,				 (u32)&iObj_get_foreColor					  },
		{	cgc_backColor,					sizeof(cgc_backColor) - 1,					 (u32)&iObj_set_backColor,				 (u32)&iObj_get_backColor					  },
		{	cgc_disabledBackColor,			sizeof(cgc_disabledBackColor) - 1,			 (u32)&iObj_set_disabledBackColor,		 (u32)&iObj_get_disabledBackColor			  },
		{	cgc_disabledForeColor,			sizeof(cgc_disabledForeColor) - 1,			 (u32)&iObj_set_disabledForeColor,		 (u32)&iObj_get_disabledForeColor			  },
		{	cgc_disabledItemBackColor,		sizeof(cgc_disabledItemBackColor) - 1,		 (u32)&iObj_set_disabledItemBackColor,	 (u32)&iObj_get_disabledItemBackColor		  },
		{	cgc_disabledItemForeColor,		sizeof(cgc_disabledItemForeColor) - 1,		 (u32)&iObj_set_disabledItemForeColor,	 (u32)&iObj_get_disabledItemForeColor		  },
		{	cgc_columnLines,				sizeof(cgc_columnLines) - 1,				 (u32)&iObj_set_columnLines,			 (u32)&iObj_get_columnLines					  },
		{	cgc_columnWidths,				sizeof(cgc_columnWidths) - 1,				 (u32)&iObj_set_columnWidths,			 (u32)&iObj_get_columnWidths				  },
		{	cgc_comment,					sizeof(cgc_comment) - 1,					 (u32)&iObj_set_comment,				 (u32)&iObj_get_comment						  },
		{	cgc_controlSource,				sizeof(cgc_controlSource) - 1,				 (u32)&iObj_set_controlSource,			 (u32)&iObj_get_controlSource				  },
		{	cgc_rowSource,					sizeof(cgc_rowSource) - 1,					 (u32)&iObj_set_rowSource,				 (u32)&iObj_get_rowSource					  },
		{	cgc_rowSourceType,				sizeof(cgc_rowSourceType) - 1,				 (u32)&iObj_set_rowSourceType,			 (u32)&iObj_get_rowSourceType				  },
		{	cgc_displayCount,				sizeof(cgc_displayCount) - 1,				 (u32)&iObj_set_displayCount,			 (u32)&iObj_get_displayCount				  },
		{	cgc_displayValue,				sizeof(cgc_displayValue) - 1,				 (u32)&iObj_set_displayValue,			 (u32)&iObj_get_displayValue				  },
		{	cgc_dragIcon,					sizeof(cgc_dragIcon) - 1,					 (u32)&iObj_set_dragIcon,				 (u32)&iObj_get_dragIcon					  },
		{	cgc_dragMode,					sizeof(cgc_dragMode) - 1,					 (u32)&iObj_set_dragMode,				 (u32)&iObj_get_dragMode					  },
		{	cgc_enabled,					sizeof(cgc_enabled) - 1,					 (u32)&iObj_set_enabled,				 (u32)&iObj_get_enabled						  },
		{	cgc_firstElement,				sizeof(cgc_firstElement) - 1,				 (u32)&iObj_set_firstElement,			 (u32)&iObj_get_firstElement				  },
		{	cgc_fontBold,					sizeof(cgc_fontBold) - 1,					 (u32)&iObj_set_fontBold,				 (u32)&iObj_get_fontBold					  },
		{	cgc_fontCharSet,				sizeof(cgc_fontCharSet) - 1,				 (u32)&iObj_set_fontCharSet,			 (u32)&iObj_get_fontCharSet					  },
		{	cgc_fontCondense,				sizeof(cgc_fontCondense) - 1,				 (u32)&iObj_set_fontCondense,			 (u32)&iObj_get_fontCondense				  },
		{	cgc_fontExtend,					sizeof(cgc_fontExtend) - 1,					 (u32)&iObj_set_fontExtend,				 (u32)&iObj_get_fontExtend					  },
		{	cgc_fontItalic,					sizeof(cgc_fontItalic) - 1,					 (u32)&iObj_set_fontItalic,				 (u32)&iObj_get_fontItalic					  },
		{	cgc_fontName,					sizeof(cgc_fontName) - 1,					 (u32)&iObj_set_fontName,				 (u32)&iObj_get_fontName					  },
		{	cgc_fontOutline,				sizeof(cgc_fontOutline) - 1,				 (u32)&iObj_set_fontOutline,			 (u32)&iObj_get_fontOutline					  },
		{	cgc_fontShadow,					sizeof(cgc_fontShadow) - 1,					 (u32)&iObj_set_fontShadow,				 (u32)&iObj_get_fontShadow					  },
		{	cgc_fontSize,					sizeof(cgc_fontSize) - 1,					 (u32)&iObj_set_fontSize,				 (u32)&iObj_get_fontSize					  },
		{	cgc_fontStrikeThru,				sizeof(cgc_fontStrikeThru) - 1,				 (u32)&iObj_set_fontStrikeThru,			 (u32)&iObj_get_fontStrikeThru				  },
		{	cgc_fontUnderline,				sizeof(cgc_fontUnderline) - 1,				 (u32)&iObj_set_fontUnderline,			 (u32)&iObj_get_fontUnderline				  },
		{	cgc_format,						sizeof(cgc_format) - 1,						 (u32)&iObj_set_format,					 (u32)&iObj_get_format						  },
		{	cgc_height,						sizeof(cgc_height) - 1,						 (u32)&iObj_set_height,					 (u32)&iObj_get_height						  },
		{	cgc_helpContextID,				sizeof(cgc_helpContextID) - 1,				 (u32)&iObj_set_helpContextID,			 (u32)&iObj_get_helpContextID				  },
		{	cgc_hideSelection,				sizeof(cgc_hideSelection) - 1,				 (u32)&iObj_set_hideSelection,			 (u32)&iObj_get_hideSelection				  },
		{	cgc_iMEMode,					sizeof(cgc_iMEMode) - 1,					 (u32)&iObj_set_iMEMode,				 (u32)&iObj_get_iMEMode						  },
		{	cgc_incrementalSearch,			sizeof(cgc_incrementalSearch) - 1,			 (u32)&iObj_set_incrementalSearch,		 (u32)&iObj_get_incrementalSearch			  },
		{	cgc_inputMask,					sizeof(cgc_inputMask) - 1,					 (u32)&iObj_set_inputMask,				 (u32)&iObj_get_inputMask					  },
		{	cgc_itemBackColor,				sizeof(cgc_itemBackColor) - 1,				 (u32)&iObj_set_itemBackColor,			 (u32)&iObj_get_itemBackColor				  },
		{	cgc_itemForeColor,				sizeof(cgc_itemForeColor) - 1,				 (u32)&iObj_set_itemForeColor,			 (u32)&iObj_get_itemForeColor				  },
		{	cgc_itemData,					sizeof(cgc_itemData) - 1,					 (u32)&iObj_set_itemData,				 (u32)&iObj_get_itemData					  },
		{	cgc_itemIDData,					sizeof(cgc_itemIDData) - 1,					 (u32)&iObj_set_itemIDData,				 (u32)&iObj_get_itemIDData					  },
		{	cgc_itemTips,					sizeof(cgc_itemTips) - 1,					 (u32)&iObj_set_itemTips,				 (u32)&iObj_get_itemTips					  },
		{	cgc_left,						sizeof(cgc_left) - 1,						 (u32)&iObj_set_left,					 (u32)&iObj_get_left						  },
		{	cgc_list,						sizeof(cgc_list) - 1,						 (u32)&iObj_set_list,					 (u32)&iObj_get_list						  },
		{	cgc_listIndex,					sizeof(cgc_listIndex) - 1,					 (u32)&iObj_set_listIndex,				 (u32)&iObj_get_listIndex					  },
		{	cgc_listItem,					sizeof(cgc_listItem) - 1,					 (u32)&iObj_set_listItem,				 (u32)&iObj_get_listItem					  },
		{	cgc_listItemID,					sizeof(cgc_listItemID) - 1,					 (u32)&iObj_set_listItemID,				 (u32)&iObj_get_listItemID					  },
		{	cgc_margin,						sizeof(cgc_margin) - 1,						 (u32)&iObj_set_margin,					 (u32)&iObj_get_margin						  },
		{	cgc_maxLength,					sizeof(cgc_maxLength) - 1,					 (u32)&iObj_set_maxLength,				 (u32)&iObj_get_maxLength					  },
		{	cgc_mouseIcon,					sizeof(cgc_mouseIcon) - 1,					 (u32)&iObj_set_mouseIcon,				 (u32)&iObj_get_mouseIcon					  },
		{	cgc_mousePointer,				sizeof(cgc_mousePointer) - 1,				 (u32)&iObj_set_mousePointer,			 (u32)&iObj_get_mousePointer				  },
		{	cgc_name,						sizeof(cgc_name) - 1,						 (u32)&iObj_set_name,					 (u32)&iObj_get_name						  },
		{	cgc_newIndex,					sizeof(cgc_newIndex) - 1,					 (u32)&iObj_set_newIndex,				 (u32)&iObj_get_newIndex					  },
		{	cgc_newItemID,					sizeof(cgc_newItemID) - 1,					 (u32)&iObj_set_newItemID,				 (u32)&iObj_get_newItemID					  },
		{	cgc_nullDisplay,				sizeof(cgc_nullDisplay) - 1,				 (u32)&iObj_set_nullDisplay,			 (u32)&iObj_get_nullDisplay					  },
		{	cgc_numberOfElements,			sizeof(cgc_numberOfElements) - 1,			 (u32)&iObj_set_numberOfElements,		 (u32)&iObj_get_numberOfElements			  },
		{	cgc_oLEDragMode,				sizeof(cgc_oLEDragMode) - 1,				 (u32)&iObj_set_oLEDragMode,			 (u32)&iObj_get_oLEDragMode					  },
		{	cgc_oLEDragPicture,				sizeof(cgc_oLEDragPicture) - 1,				 (u32)&iObj_set_oLEDragPicture,			 (u32)&iObj_get_oLEDragPicture				  },
		{	cgc_oLEDropEffects,				sizeof(cgc_oLEDropEffects) - 1,				 (u32)&iObj_set_oLEDropEffects,			 (u32)&iObj_get_oLEDropEffects				  },
		{	cgc_oLEDropHasData,				sizeof(cgc_oLEDropHasData) - 1,				 (u32)&iObj_set_oLEDropHasData,			 (u32)&iObj_get_oLEDropHasData				  },
		{	cgc_oLEDropMode,				sizeof(cgc_oLEDropMode) - 1,				 (u32)&iObj_set_oLEDropMode,			 (u32)&iObj_get_oLEDropMode					  },
		{	cgc_oLEDropTextInsertion,		sizeof(cgc_oLEDropTextInsertion) - 1,		 (u32)&iObj_set_oLEDropTextInsertion,	 (u32)&iObj_get_oLEDropTextInsertion		  },
		{	cgc_parent,						sizeof(cgc_parent) - 1,						 (u32)&iObj_set_parent,					 (u32)&iObj_get_parent						  },
		{	cgc_parentClass,				sizeof(cgc_parentClass) - 1,				 (u32)&iObj_set_parentClass,			 (u32)&iObj_get_parentClass					  },
		{	cgc_picture,					sizeof(cgc_picture) - 1,					 (u32)&iObj_set_picture,				 (u32)&iObj_get_picture						  },
		{	cgc_pictureSelectionDisplay,	sizeof(cgc_pictureSelectionDisplay) - 1,	 (u32)&iObj_set_pictureSelectionDisplay, (u32)&iObj_get_pictureSelectionDisplay		  },
		{	cgc_readOnly,					sizeof(cgc_readOnly) - 1,					 (u32)&iObj_set_readOnly,				 (u32)&iObj_get_readOnly					  },
		{	cgc_rightToLeft,				sizeof(cgc_rightToLeft) - 1,				 (u32)&iObj_set_rightToLeft,			 (u32)&iObj_get_rightToLeft					  },
		{	cgc_selected,					sizeof(cgc_selected) - 1,					 (u32)&iObj_set_selected,				 (u32)&iObj_get_selected					  },
		{	cgc_selectedID,					sizeof(cgc_selectedID) - 1,					 (u32)&iObj_set_selectedID,				 (u32)&iObj_get_selectedID					  },
		{	cgc_selectedBackColor,			sizeof(cgc_selectedBackColor) - 1,			 (u32)&iObj_set_selectedBackColor,		 (u32)&iObj_get_selectedBackColor			  },
		{	cgc_selectedForeColor,			sizeof(cgc_selectedForeColor) - 1,			 (u32)&iObj_set_selectedForeColor,		 (u32)&iObj_get_selectedForeColor			  },
		{	cgc_selectedItemBackColor,		sizeof(cgc_selectedItemBackColor) - 1,		 (u32)&iObj_set_selectedItemBackColor,	 (u32)&iObj_get_selectedItemBackColor		  },
		{	cgc_selectedItemForeColor,		sizeof(cgc_selectedItemForeColor) - 1,		 (u32)&iObj_set_selectedItemForeColor,	 (u32)&iObj_get_selectedItemForeColor		  },
		{	cgc_selectOnEntry,				sizeof(cgc_selectOnEntry) - 1,				 (u32)&iObj_set_selectOnEntry,			 (u32)&iObj_get_selectOnEntry				  },
		{	cgc_selLength,					sizeof(cgc_selLength) - 1,					 (u32)&iObj_set_selLength,				 (u32)&iObj_get_selLength					  },
		{	cgc_selStart,					sizeof(cgc_selStart) - 1,					 (u32)&iObj_set_selStart,				 (u32)&iObj_get_selStart					  },
		{	cgc_selText,					sizeof(cgc_selText) - 1,					 (u32)&iObj_set_selText,				 (u32)&iObj_get_selText						  },
		{	cgc_sorted,						sizeof(cgc_sorted) - 1,						 (u32)&iObj_set_sorted,					 (u32)&iObj_get_sorted						  },
		{	cgc_specialEffect,				sizeof(cgc_specialEffect) - 1,				 (u32)&iObj_set_specialEffect,			 (u32)&iObj_get_specialEffect				  },
		{	cgc_statusBarText,				sizeof(cgc_statusBarText) - 1,				 (u32)&iObj_set_statusBarText,			 (u32)&iObj_get_statusBarText				  },
		{	cgc_style,						sizeof(cgc_style) - 1,						 (u32)&iObj_set_style,					 (u32)&iObj_get_style						  },
		{	cgc_tabIndex,					sizeof(cgc_tabIndex) - 1,					 (u32)&iObj_set_tabIndex,				 (u32)&iObj_get_tabIndex					  },
		{	cgc_tabStop,					sizeof(cgc_tabStop) - 1,					 (u32)&iObj_set_tabStop,				 (u32)&iObj_get_tabStop						  },
		{	cgc_tag,						sizeof(cgc_tag) - 1,						 (u32)&iObj_set_tag,					 (u32)&iObj_get_tag							  },
		{	cgc_terminateRead,				sizeof(cgc_terminateRead) - 1,				 (u32)&iObj_set_terminateRead,			 (u32)&iObj_get_terminateRead				  },
		{	cgc_text,						sizeof(cgc_text) - 1,						 (u32)&iObj_set_text,					 (u32)&iObj_get_text						  },
		{	cgc_themes,						sizeof(cgc_themes) - 1,						 (u32)&iObj_set_themes,					 (u32)&iObj_get_themes						  },
		{	cgc_toolTipText,				sizeof(cgc_toolTipText) - 1,				 (u32)&iObj_set_toolTipText,			 (u32)&iObj_get_toolTipText					  },
		{	cgc_top,						sizeof(cgc_top) - 1,						 (u32)&iObj_set_top,					 (u32)&iObj_get_top							  },
		{	cgc_topIndex,					sizeof(cgc_topIndex) - 1,					 (u32)&iObj_set_topIndex,				 (u32)&iObj_get_topIndex					  },
		{	cgc_topItemID,					sizeof(cgc_topItemID) - 1,					 (u32)&iObj_set_topItemID,				 (u32)&iObj_get_topItemID					  },
		{	cgc_value,						sizeof(cgc_value) - 1,						 (u32)&iObj_set_value,					 (u32)&iObj_get_value						  },
		{	cgc_visible,					sizeof(cgc_visible) - 1,					 (u32)&iObj_set_visible,				 (u32)&iObj_get_visible						  },
		{	cgc_whatsThisHelpID,			sizeof(cgc_whatsThisHelpID) - 1,			 (u32)&iObj_set_whatsThisHelpID,		 (u32)&iObj_get_whatsThisHelpID				  },
		{	cgc_width,						sizeof(cgc_width) - 1,						 (u32)&iObj_set_width,					 (u32)&iObj_get_width						  },
		{	NULL,							0,											 0,										 0										 }
	};

	SPropertyMap gcProps_form[] = 
	{
		{	cgc_activeControl,				sizeof(cgc_activeControl) - 1,				 (u32)&iObj_set_activeControl,			 (u32)&iObj_get_activeControl				  },
		{	cgc_activeForm,					sizeof(cgc_activeForm) - 1,					 (u32)&iObj_set_activeForm,				 (u32)&iObj_get_activeForm					  },
		{	cgc_allowOutput,				sizeof(cgc_allowOutput) - 1,				 (u32)&iObj_set_allowOutput,			 (u32)&iObj_get_allowOutput					  },
		{	cgc_alwaysOnTop,				sizeof(cgc_alwaysOnTop) - 1,				 (u32)&iObj_set_alwaysOnTop,			 (u32)&iObj_get_alwaysOnTop					  },
		{	cgc_alwaysOnBottom,				sizeof(cgc_alwaysOnBottom) - 1,				 (u32)&iObj_set_alwaysOnBottom,			 (u32)&iObj_get_alwaysOnBottom				  },
		{	cgc_bindControls,				sizeof(cgc_bindControls) - 1,				 (u32)&iObj_set_bindControls,			 (u32)&iObj_get_bindControls				  },
		{	cgc_bufferMode,					sizeof(cgc_bufferMode) - 1,					 (u32)&iObj_set_bufferMode,				 (u32)&iObj_get_bufferMode					  },
		{	cgc_controlBox,					sizeof(cgc_controlBox) - 1,					 (u32)&iObj_set_controlBox,				 (u32)&iObj_get_controlBox					  },
		{	cgc_closable,					sizeof(cgc_closable) - 1,					 (u32)&iObj_set_closable,				 (u32)&iObj_get_closable					  },
		{	cgc_continuousScroll,			sizeof(cgc_continuousScroll) - 1,			 (u32)&iObj_set_continuousScroll,		 (u32)&iObj_get_continuousScroll			  },
		{	cgc_dataSession,				sizeof(cgc_dataSession) - 1,				 (u32)&iObj_set_dataSession,			 (u32)&iObj_get_dataSession					  },
		{	cgc_dataSessionID,				sizeof(cgc_dataSessionID) - 1,				 (u32)&iObj_set_dataSessionID,			 (u32)&iObj_get_dataSessionID				  },
		{	cgc_dataEnvironment,			sizeof(cgc_dataEnvironment) - 1,			 (u32)&iObj_set_dataEnvironment,		 (u32)&iObj_get_dataEnvironment				  },
		{	cgc_dEClass,					sizeof(cgc_dEClass) - 1,					 (u32)&iObj_set_dEClass,				 (u32)&iObj_get_dEClass						  },
		{	cgc_dEClassLibrary,				sizeof(cgc_dEClassLibrary) - 1,				 (u32)&iObj_set_dEClassLibrary,			 (u32)&iObj_get_dEClassLibrary				  },
		{	cgc_defOLELCID,					sizeof(cgc_defOLELCID) - 1,					 (u32)&iObj_set_defOLELCID,				 (u32)&iObj_get_defOLELCID					  },
		{	cgc_desktop,					sizeof(cgc_desktop) - 1,					 (u32)&iObj_set_desktop,				 (u32)&iObj_get_desktop						  },
		{	cgc_macDesktop,					sizeof(cgc_macDesktop) - 1,					 (u32)&iObj_set_macDesktop,				 (u32)&iObj_get_macDesktop					  },
		{	cgc_dockPosition,				sizeof(cgc_dockPosition) - 1,				 (u32)&iObj_set_dockPosition,			 (u32)&iObj_get_dockPosition				  },
		{	cgc_dockable,					sizeof(cgc_dockable) - 1,					 (u32)&iObj_set_dockable,				 (u32)&iObj_get_dockable					  },
		{	cgc_docked,						sizeof(cgc_docked) - 1,						 (u32)&iObj_set_docked,					 (u32)&iObj_get_docked						  },
		{	cgc_mDIForm,					sizeof(cgc_mDIForm) - 1,					 (u32)&iObj_set_mDIForm,				 (u32)&iObj_get_mDIForm						  },
		{	cgc_doCreate,					sizeof(cgc_doCreate) - 1,					 (u32)&iObj_set_doCreate,				 (u32)&iObj_get_doCreate					  },
		{	cgc_fillColor,					sizeof(cgc_fillColor) - 1,					 (u32)&iObj_set_fillColor,				 (u32)&iObj_get_fillColor					  },
		{	cgc_fillStyle,					sizeof(cgc_fillStyle) - 1,					 (u32)&iObj_set_fillStyle,				 (u32)&iObj_get_fillStyle					  },
		{	cgc_hScrollSmallChange,			sizeof(cgc_hScrollSmallChange) - 1,			 (u32)&iObj_set_hScrollSmallChange,		 (u32)&iObj_get_hScrollSmallChange			  },
		{	cgc_vScrollSmallChange,			sizeof(cgc_vScrollSmallChange) - 1,			 (u32)&iObj_set_vScrollSmallChange,		 (u32)&iObj_get_vScrollSmallChange			  },
		{	cgc_lockScreen,					sizeof(cgc_lockScreen) - 1,					 (u32)&iObj_set_lockScreen,				 (u32)&iObj_get_lockScreen					  },
		{	cgc_maxButton,					sizeof(cgc_maxButton) - 1,					 (u32)&iObj_set_maxButton,				 (u32)&iObj_get_maxButton					  },
		{	cgc_minButton,					sizeof(cgc_minButton) - 1,					 (u32)&iObj_set_minButton,				 (u32)&iObj_get_minButton					  },
		{	cgc_movable,					sizeof(cgc_movable) - 1,					 (u32)&iObj_set_movable,				 (u32)&iObj_get_movable						  },
		{	cgc_maxHeight,					sizeof(cgc_maxHeight) - 1,					 (u32)&iObj_set_maxHeight,				 (u32)&iObj_get_maxHeight					  },
		{	cgc_maxWidth,					sizeof(cgc_maxWidth) - 1,					 (u32)&iObj_set_maxWidth,				 (u32)&iObj_get_maxWidth					  },
		{	cgc_maxTop,						sizeof(cgc_maxTop) - 1,						 (u32)&iObj_set_maxTop,					 (u32)&iObj_get_maxTop						  },
		{	cgc_maxLeft,					sizeof(cgc_maxLeft) - 1,					 (u32)&iObj_set_maxLeft,				 (u32)&iObj_get_maxLeft						  },
		{	cgc_minHeight,					sizeof(cgc_minHeight) - 1,					 (u32)&iObj_set_minHeight,				 (u32)&iObj_get_minHeight					  },
		{	cgc_minWidth,					sizeof(cgc_minWidth) - 1,					 (u32)&iObj_set_minWidth,				 (u32)&iObj_get_minWidth					  },
		{	cgc_scaleMode,					sizeof(cgc_scaleMode) - 1,					 (u32)&iObj_set_scaleMode,				 (u32)&iObj_get_scaleMode					  },
		{	cgc_showTips,					sizeof(cgc_showTips) - 1,					 (u32)&iObj_set_showTips,				 (u32)&iObj_get_showTips					  },
		{	cgc_showWindow,					sizeof(cgc_showWindow) - 1,					 (u32)&iObj_set_showWindow,				 (u32)&iObj_get_showWindow					  },
		{	cgc_showInTaskbar,				sizeof(cgc_showInTaskbar) - 1,				 (u32)&iObj_set_showInTaskbar,			 (u32)&iObj_get_showInTaskbar				  },
		{	cgc_sizeBox,					sizeof(cgc_sizeBox) - 1,					 (u32)&iObj_set_sizeBox,				 (u32)&iObj_get_sizeBox						  },
		{	cgc_windowType,					sizeof(cgc_windowType) - 1,					 (u32)&iObj_set_windowType,				 (u32)&iObj_get_windowType					  },
		{	cgc_windowState,				sizeof(cgc_windowState) - 1,				 (u32)&iObj_set_windowState,			 (u32)&iObj_get_windowState					  },
		{	cgc_autoCenter,					sizeof(cgc_autoCenter) - 1,					 (u32)&iObj_set_autoCenter,				 (u32)&iObj_get_autoCenter					  },
		{	cgc_baseClass,					sizeof(cgc_baseClass) - 1,					 (u32)&iObj_set_baseClass,				 (u32)&iObj_get_baseClass					  },
		{	cgc_class,						sizeof(cgc_class) - 1,						 (u32)&iObj_set_class,					 (u32)&iObj_get_class						  },
		{	cgc_classLibrary,				sizeof(cgc_classLibrary) - 1,				 (u32)&iObj_set_classLibrary,			 (u32)&iObj_get_classLibrary				  },
		{	cgc_controls,					sizeof(cgc_controls) - 1,					 (u32)&iObj_set_controls,				 (u32)&iObj_get_controls					  },
		{	cgc_controlCount,				sizeof(cgc_controlCount) - 1,				 (u32)&iObj_set_controlCount,			 (u32)&iObj_get_controlCount				  },
		{	cgc_objects,					sizeof(cgc_objects) - 1,					 (u32)&iObj_set_objects,				 (u32)&iObj_get_objects						  },
		{	cgc_borderStyle,				sizeof(cgc_borderStyle) - 1,				 (u32)&iObj_set_borderStyle,			 (u32)&iObj_get_borderStyle					  },
		{	cgc_clipControls,				sizeof(cgc_clipControls) - 1,				 (u32)&iObj_set_clipControls,			 (u32)&iObj_get_clipControls				  },
		{	cgc_caption,					sizeof(cgc_caption) - 1,					 (u32)&iObj_set_caption,				 (u32)&iObj_get_caption						  },
		{	cgc_halfHeightCaption,			sizeof(cgc_halfHeightCaption) - 1,			 (u32)&iObj_set_halfHeightCaption,		 (u32)&iObj_get_halfHeightCaption			  },
		{	cgc_colorSource,				sizeof(cgc_colorSource) - 1,				 (u32)&iObj_set_colorSource,			 (u32)&iObj_get_colorSource					  },
		{	cgc_foreColor,					sizeof(cgc_foreColor) - 1,					 (u32)&iObj_set_foreColor,				 (u32)&iObj_get_foreColor					  },
		{	cgc_backColor,					sizeof(cgc_backColor) - 1,					 (u32)&iObj_set_backColor,				 (u32)&iObj_get_backColor					  },
		{	cgc_currentX,					sizeof(cgc_currentX) - 1,					 (u32)&iObj_set_currentX,				 (u32)&iObj_get_currentX					  },
		{	cgc_currentY,					sizeof(cgc_currentY) - 1,					 (u32)&iObj_set_currentY,				 (u32)&iObj_get_currentY					  },
		{	cgc_comment,					sizeof(cgc_comment) - 1,					 (u32)&iObj_set_comment,				 (u32)&iObj_get_comment						  },
		{	cgc_drawMode,					sizeof(cgc_drawMode) - 1,					 (u32)&iObj_set_drawMode,				 (u32)&iObj_get_drawMode					  },
		{	cgc_drawStyle,					sizeof(cgc_drawStyle) - 1,					 (u32)&iObj_set_drawStyle,				 (u32)&iObj_get_drawStyle					  },
		{	cgc_drawWidth,					sizeof(cgc_drawWidth) - 1,					 (u32)&iObj_set_drawWidth,				 (u32)&iObj_get_drawWidth					  },
		{	cgc_enabled,					sizeof(cgc_enabled) - 1,					 (u32)&iObj_set_enabled,				 (u32)&iObj_get_enabled						  },
		{	cgc_fontBold,					sizeof(cgc_fontBold) - 1,					 (u32)&iObj_set_fontBold,				 (u32)&iObj_get_fontBold					  },
		{	cgc_fontCharSet,				sizeof(cgc_fontCharSet) - 1,				 (u32)&iObj_set_fontCharSet,			 (u32)&iObj_get_fontCharSet					  },
		{	cgc_fontCondense,				sizeof(cgc_fontCondense) - 1,				 (u32)&iObj_set_fontCondense,			 (u32)&iObj_get_fontCondense				  },
		{	cgc_fontExtend,					sizeof(cgc_fontExtend) - 1,					 (u32)&iObj_set_fontExtend,				 (u32)&iObj_get_fontExtend					  },
		{	cgc_fontItalic,					sizeof(cgc_fontItalic) - 1,					 (u32)&iObj_set_fontItalic,				 (u32)&iObj_get_fontItalic					  },
		{	cgc_fontName,					sizeof(cgc_fontName) - 1,					 (u32)&iObj_set_fontName,				 (u32)&iObj_get_fontName					  },
		{	cgc_fontOutline,				sizeof(cgc_fontOutline) - 1,				 (u32)&iObj_set_fontOutline,			 (u32)&iObj_get_fontOutline					  },
		{	cgc_fontShadow,					sizeof(cgc_fontShadow) - 1,					 (u32)&iObj_set_fontShadow,				 (u32)&iObj_get_fontShadow					  },
		{	cgc_fontSize,					sizeof(cgc_fontSize) - 1,					 (u32)&iObj_set_fontSize,				 (u32)&iObj_get_fontSize					  },
		{	cgc_fontStrikeThru,				sizeof(cgc_fontStrikeThru) - 1,				 (u32)&iObj_set_fontStrikeThru,			 (u32)&iObj_get_fontStrikeThru				  },
		{	cgc_fontUnderline,				sizeof(cgc_fontUnderline) - 1,				 (u32)&iObj_set_fontUnderline,			 (u32)&iObj_get_fontUnderline				  },
		{	cgc_height,						sizeof(cgc_height) - 1,						 (u32)&iObj_set_height,					 (u32)&iObj_get_height						  },
		{	cgc_helpContextID,				sizeof(cgc_helpContextID) - 1,				 (u32)&iObj_set_helpContextID,			 (u32)&iObj_get_helpContextID				  },
		{	cgc_hWnd,						sizeof(cgc_hWnd) - 1,						 (u32)&iObj_set_hWnd,					 (u32)&iObj_get_hWnd						  },
		{	cgc_keyPreview,					sizeof(cgc_keyPreview) - 1,					 (u32)&iObj_set_keyPreview,				 (u32)&iObj_get_keyPreview					  },
		{	cgc_left,						sizeof(cgc_left) - 1,						 (u32)&iObj_set_left,					 (u32)&iObj_get_left						  },
		{	cgc_lockScreen,					sizeof(cgc_lockScreen) - 1,					 (u32)&iObj_set_lockScreen,				 (u32)&iObj_get_lockScreen					  },
		{	cgc_mouseIcon,					sizeof(cgc_mouseIcon) - 1,					 (u32)&iObj_set_mouseIcon,				 (u32)&iObj_get_mouseIcon					  },
		{	cgc_mousePointer,				sizeof(cgc_mousePointer) - 1,				 (u32)&iObj_set_mousePointer,			 (u32)&iObj_get_mousePointer				  },
		{	cgc_name,						sizeof(cgc_name) - 1,						 (u32)&iObj_set_name,					 (u32)&iObj_get_name						  },
		{	cgc_oLEDragMode,				sizeof(cgc_oLEDragMode) - 1,				 (u32)&iObj_set_oLEDragMode,			 (u32)&iObj_get_oLEDragMode					  },
		{	cgc_oLEDragPicture,				sizeof(cgc_oLEDragPicture) - 1,				 (u32)&iObj_set_oLEDragPicture,			 (u32)&iObj_get_oLEDragPicture				  },
		{	cgc_oLEDropEffects,				sizeof(cgc_oLEDropEffects) - 1,				 (u32)&iObj_set_oLEDropEffects,			 (u32)&iObj_get_oLEDropEffects				  },
		{	cgc_oLEDropHasData,				sizeof(cgc_oLEDropHasData) - 1,				 (u32)&iObj_set_oLEDropHasData,			 (u32)&iObj_get_oLEDropHasData				  },
		{	cgc_oLEDropMode,				sizeof(cgc_oLEDropMode) - 1,				 (u32)&iObj_set_oLEDropMode,			 (u32)&iObj_get_oLEDropMode					  },
		{	cgc_parent,						sizeof(cgc_parent) - 1,						 (u32)&iObj_set_parent,					 (u32)&iObj_get_parent						  },
		{	cgc_parentClass,				sizeof(cgc_parentClass) - 1,				 (u32)&iObj_set_parentClass,			 (u32)&iObj_get_parentClass					  },
		{	cgc_icon,						sizeof(cgc_icon) - 1,						 (u32)&iObj_set_icon,					 (u32)&iObj_get_icon						  },
		{	cgc_picture,					sizeof(cgc_picture) - 1,					 (u32)&iObj_set_picture,				 (u32)&iObj_get_picture						  },
		{	cgc_releaseType,				sizeof(cgc_releaseType) - 1,				 (u32)&iObj_set_releaseType,			 (u32)&iObj_get_releaseType					  },
		{	cgc_rightToLeft,				sizeof(cgc_rightToLeft) - 1,				 (u32)&iObj_set_rightToLeft,			 (u32)&iObj_get_rightToLeft					  },
		{	cgc_scrollBars,					sizeof(cgc_scrollBars) - 1,					 (u32)&iObj_set_scrollBars,				 (u32)&iObj_get_scrollBars					  },
		{	cgc_tabIndex,					sizeof(cgc_tabIndex) - 1,					 (u32)&iObj_set_tabIndex,				 (u32)&iObj_get_tabIndex					  },
		{	cgc_tabStop,					sizeof(cgc_tabStop) - 1,					 (u32)&iObj_set_tabStop,				 (u32)&iObj_get_tabStop						  },
		{	cgc_tag,						sizeof(cgc_tag) - 1,						 (u32)&iObj_set_tag,					 (u32)&iObj_get_tag							  },
		{	cgc_themes,						sizeof(cgc_themes) - 1,						 (u32)&iObj_set_themes,					 (u32)&iObj_get_themes						  },
		{	cgc_titleBar,					sizeof(cgc_titleBar) - 1,					 (u32)&iObj_set_titleBar,				 (u32)&iObj_get_titleBar					  },
		{	cgc_top,						sizeof(cgc_top) - 1,						 (u32)&iObj_set_top,					 (u32)&iObj_get_top							  },
		{	cgc_visible,					sizeof(cgc_visible) - 1,					 (u32)&iObj_set_visible,				 (u32)&iObj_get_visible						  },
		{	cgc_viewPortHeight,				sizeof(cgc_viewPortHeight) - 1,				 (u32)&iObj_set_viewPortHeight,			 (u32)&iObj_get_viewPortHeight				  },
		{	cgc_viewPortLeft,				sizeof(cgc_viewPortLeft) - 1,				 (u32)&iObj_set_viewPortLeft,			 (u32)&iObj_get_viewPortLeft				  },
		{	cgc_viewPortTop,				sizeof(cgc_viewPortTop) - 1,				 (u32)&iObj_set_viewPortTop,			 (u32)&iObj_get_viewPortTop					  },
		{	cgc_viewPortWidth,				sizeof(cgc_viewPortWidth) - 1,				 (u32)&iObj_set_viewPortWidth,			 (u32)&iObj_get_viewPortWidth				  },
		{	cgc_whatsThisHelpID,			sizeof(cgc_whatsThisHelpID) - 1,			 (u32)&iObj_set_whatsThisHelpID,		 (u32)&iObj_get_whatsThisHelpID				  },
		{	cgc_whatsThisHelp,				sizeof(cgc_whatsThisHelp) - 1,				 (u32)&iObj_set_whatsThisHelp,			 (u32)&iObj_get_whatsThisHelp				  },
		{	cgc_whatsThisButton,			sizeof(cgc_whatsThisButton) - 1,			 (u32)&iObj_set_whatsThisButton,		 (u32)&iObj_get_whatsThisButton				  },
		{	cgc_width,						sizeof(cgc_width) - 1,						 (u32)&iObj_set_width,					 (u32)&iObj_get_width						  },
		{	cgc_zoomBox,					sizeof(cgc_zoomBox) - 1,					 (u32)&iObj_set_zoomBox,				 (u32)&iObj_get_zoomBox						  },
		{	NULL,							0,											 0,										 0										 }
	};

	SPropertyMap gcProps_formset[] = 
	{
		{	cgc_activeForm,					sizeof(cgc_activeForm) - 1,					 (u32)&iObj_set_activeForm,				 (u32)&iObj_get_activeForm					  },
		{	cgc_autoRelease,				sizeof(cgc_autoRelease) - 1,				 (u32)&iObj_set_autoRelease,			 (u32)&iObj_get_autoRelease					  },
		{	cgc_bufferMode,					sizeof(cgc_bufferMode) - 1,					 (u32)&iObj_set_bufferMode,				 (u32)&iObj_get_bufferMode					  },
		{	cgc_dataSession,				sizeof(cgc_dataSession) - 1,				 (u32)&iObj_set_dataSession,			 (u32)&iObj_get_dataSession					  },
		{	cgc_dataSessionID,				sizeof(cgc_dataSessionID) - 1,				 (u32)&iObj_set_dataSessionID,			 (u32)&iObj_get_dataSessionID				  },
		{	cgc_dataEnvironment,			sizeof(cgc_dataEnvironment) - 1,			 (u32)&iObj_set_dataEnvironment,		 (u32)&iObj_get_dataEnvironment				  },
		{	cgc_application,				sizeof(cgc_application) - 1,				 (u32)&iObj_set_application,			 (u32)&iObj_get_application					  },
		{	cgc_baseClass,					sizeof(cgc_baseClass) - 1,					 (u32)&iObj_set_baseClass,				 (u32)&iObj_get_baseClass					  },
		{	cgc_class,						sizeof(cgc_class) - 1,						 (u32)&iObj_set_class,					 (u32)&iObj_get_class						  },
		{	cgc_classLibrary,				sizeof(cgc_classLibrary) - 1,				 (u32)&iObj_set_classLibrary,			 (u32)&iObj_get_classLibrary				  },
		{	cgc_forms,						sizeof(cgc_forms) - 1,						 (u32)&iObj_set_forms,					 (u32)&iObj_get_forms						  },
		{	cgc_formCount,					sizeof(cgc_formCount) - 1,					 (u32)&iObj_set_formCount,				 (u32)&iObj_get_formCount					  },
		{	cgc_objects,					sizeof(cgc_objects) - 1,					 (u32)&iObj_set_objects,				 (u32)&iObj_get_objects						  },
		{	cgc_comment,					sizeof(cgc_comment) - 1,					 (u32)&iObj_set_comment,				 (u32)&iObj_get_comment						  },
		{	cgc_name,						sizeof(cgc_name) - 1,						 (u32)&iObj_set_name,					 (u32)&iObj_get_name						  },
		{	cgc_parent,						sizeof(cgc_parent) - 1,						 (u32)&iObj_set_parent,					 (u32)&iObj_get_parent						  },
		{	cgc_parentClass,				sizeof(cgc_parentClass) - 1,				 (u32)&iObj_set_parentClass,			 (u32)&iObj_get_parentClass					  },
		{	cgc_readBackColor,				sizeof(cgc_readBackColor) - 1,				 (u32)&iObj_set_readBackColor,			 (u32)&iObj_get_readBackColor				  },
		{	cgc_readCycle,					sizeof(cgc_readCycle) - 1,					 (u32)&iObj_set_readCycle,				 (u32)&iObj_get_readCycle					  },
		{	cgc_readForeColor,				sizeof(cgc_readForeColor) - 1,				 (u32)&iObj_set_readForeColor,			 (u32)&iObj_get_readForeColor				  },
		{	cgc_readLock,					sizeof(cgc_readLock) - 1,					 (u32)&iObj_set_readLock,				 (u32)&iObj_get_readLock					  },
		{	cgc_readMouse,					sizeof(cgc_readMouse) - 1,					 (u32)&iObj_set_readMouse,				 (u32)&iObj_get_readMouse					  },
		{	cgc_readSave,					sizeof(cgc_readSave) - 1,					 (u32)&iObj_set_readSave,				 (u32)&iObj_get_readSave					  },
		{	cgc_readTimeOut,				sizeof(cgc_readTimeOut) - 1,				 (u32)&iObj_set_readTimeOut,			 (u32)&iObj_get_readTimeOut					  },
		{	cgc_tag,						sizeof(cgc_tag) - 1,						 (u32)&iObj_set_tag,					 (u32)&iObj_get_tag							  },
		{	cgc_visible,					sizeof(cgc_visible) - 1,					 (u32)&iObj_set_visible,				 (u32)&iObj_get_visible						  },
		{	cgc_windowList,					sizeof(cgc_windowList) - 1,					 (u32)&iObj_set_windowList,				 (u32)&iObj_get_windowList					  },
		{	cgc_windowType,					sizeof(cgc_windowType) - 1,					 (u32)&iObj_set_windowType,				 (u32)&iObj_get_windowType					  },
		{	NULL,							0,											 0,										 0										 }
	};

	SPropertyMap gcProps_toolbar[] = 
	{
		{	cgc_activeControl,				sizeof(cgc_activeControl) - 1,				 (u32)&iObj_set_activeControl,			 (u32)&iObj_get_activeControl				  },
		{	cgc_controlBox,					sizeof(cgc_controlBox) - 1,					 (u32)&iObj_set_controlBox,				 (u32)&iObj_get_controlBox					  },
		{	cgc_dataSession,				sizeof(cgc_dataSession) - 1,				 (u32)&iObj_set_dataSession,			 (u32)&iObj_get_dataSession					  },
		{	cgc_dataSessionID,				sizeof(cgc_dataSessionID) - 1,				 (u32)&iObj_set_dataSessionID,			 (u32)&iObj_get_dataSessionID				  },
		{	cgc_dockPosition,				sizeof(cgc_dockPosition) - 1,				 (u32)&iObj_set_dockPosition,			 (u32)&iObj_get_dockPosition				  },
		{	cgc_docked,						sizeof(cgc_docked) - 1,						 (u32)&iObj_set_docked,					 (u32)&iObj_get_docked						  },
		{	cgc_movable,					sizeof(cgc_movable) - 1,					 (u32)&iObj_set_movable,				 (u32)&iObj_get_movable						  },
		{	cgc_scaleMode,					sizeof(cgc_scaleMode) - 1,					 (u32)&iObj_set_scaleMode,				 (u32)&iObj_get_scaleMode					  },
		{	cgc_showTips,					sizeof(cgc_showTips) - 1,					 (u32)&iObj_set_showTips,				 (u32)&iObj_get_showTips					  },
		{	cgc_showWindow,					sizeof(cgc_showWindow) - 1,					 (u32)&iObj_set_showWindow,				 (u32)&iObj_get_showWindow					  },
		{	cgc_application,				sizeof(cgc_application) - 1,				 (u32)&iObj_set_application,			 (u32)&iObj_get_application					  },
		{	cgc_baseClass,					sizeof(cgc_baseClass) - 1,					 (u32)&iObj_set_baseClass,				 (u32)&iObj_get_baseClass					  },
		{	cgc_class,						sizeof(cgc_class) - 1,						 (u32)&iObj_set_class,					 (u32)&iObj_get_class						  },
		{	cgc_classLibrary,				sizeof(cgc_classLibrary) - 1,				 (u32)&iObj_set_classLibrary,			 (u32)&iObj_get_classLibrary				  },
		{	cgc_controls,					sizeof(cgc_controls) - 1,					 (u32)&iObj_set_controls,				 (u32)&iObj_get_controls					  },
		{	cgc_controlCount,				sizeof(cgc_controlCount) - 1,				 (u32)&iObj_set_controlCount,			 (u32)&iObj_get_controlCount				  },
		{	cgc_objects,					sizeof(cgc_objects) - 1,					 (u32)&iObj_set_objects,				 (u32)&iObj_get_objects						  },
		{	cgc_caption,					sizeof(cgc_caption) - 1,					 (u32)&iObj_set_caption,				 (u32)&iObj_get_caption						  },
		{	cgc_colorSource,				sizeof(cgc_colorSource) - 1,				 (u32)&iObj_set_colorSource,			 (u32)&iObj_get_colorSource					  },
		{	cgc_foreColor,					sizeof(cgc_foreColor) - 1,					 (u32)&iObj_set_foreColor,				 (u32)&iObj_get_foreColor					  },
		{	cgc_backColor,					sizeof(cgc_backColor) - 1,					 (u32)&iObj_set_backColor,				 (u32)&iObj_get_backColor					  },
		{	cgc_comment,					sizeof(cgc_comment) - 1,					 (u32)&iObj_set_comment,				 (u32)&iObj_get_comment						  },
		{	cgc_enabled,					sizeof(cgc_enabled) - 1,					 (u32)&iObj_set_enabled,				 (u32)&iObj_get_enabled						  },
		{	cgc_height,						sizeof(cgc_height) - 1,						 (u32)&iObj_set_height,					 (u32)&iObj_get_height						  },
		{	cgc_helpContextID,				sizeof(cgc_helpContextID) - 1,				 (u32)&iObj_set_helpContextID,			 (u32)&iObj_get_helpContextID				  },
		{	cgc_hWnd,						sizeof(cgc_hWnd) - 1,						 (u32)&iObj_set_hWnd,					 (u32)&iObj_get_hWnd						  },
		{	cgc_keyPreview,					sizeof(cgc_keyPreview) - 1,					 (u32)&iObj_set_keyPreview,				 (u32)&iObj_get_keyPreview					  },
		{	cgc_left,						sizeof(cgc_left) - 1,						 (u32)&iObj_set_left,					 (u32)&iObj_get_left						  },
		{	cgc_lockScreen,					sizeof(cgc_lockScreen) - 1,					 (u32)&iObj_set_lockScreen,				 (u32)&iObj_get_lockScreen					  },
		{	cgc_mouseIcon,					sizeof(cgc_mouseIcon) - 1,					 (u32)&iObj_set_mouseIcon,				 (u32)&iObj_get_mouseIcon					  },
		{	cgc_mousePointer,				sizeof(cgc_mousePointer) - 1,				 (u32)&iObj_set_mousePointer,			 (u32)&iObj_get_mousePointer				  },
		{	cgc_name,						sizeof(cgc_name) - 1,						 (u32)&iObj_set_name,					 (u32)&iObj_get_name						  },
		{	cgc_oLEDragMode,				sizeof(cgc_oLEDragMode) - 1,				 (u32)&iObj_set_oLEDragMode,			 (u32)&iObj_get_oLEDragMode					  },
		{	cgc_oLEDragPicture,				sizeof(cgc_oLEDragPicture) - 1,				 (u32)&iObj_set_oLEDragPicture,			 (u32)&iObj_get_oLEDragPicture				  },
		{	cgc_oLEDropEffects,				sizeof(cgc_oLEDropEffects) - 1,				 (u32)&iObj_set_oLEDropEffects,			 (u32)&iObj_get_oLEDropEffects				  },
		{	cgc_oLEDropHasData,				sizeof(cgc_oLEDropHasData) - 1,				 (u32)&iObj_set_oLEDropHasData,			 (u32)&iObj_get_oLEDropHasData				  },
		{	cgc_oLEDropMode,				sizeof(cgc_oLEDropMode) - 1,				 (u32)&iObj_set_oLEDropMode,			 (u32)&iObj_get_oLEDropMode					  },
		{	cgc_parent,						sizeof(cgc_parent) - 1,						 (u32)&iObj_set_parent,					 (u32)&iObj_get_parent						  },
		{	cgc_parentClass,				sizeof(cgc_parentClass) - 1,				 (u32)&iObj_set_parentClass,			 (u32)&iObj_get_parentClass					  },
		{	cgc_sizable,					sizeof(cgc_sizable) - 1,					 (u32)&iObj_set_sizable,				 (u32)&iObj_get_sizable						  },
		{	cgc_tag,						sizeof(cgc_tag) - 1,						 (u32)&iObj_set_tag,					 (u32)&iObj_get_tag							  },
		{	cgc_themes,						sizeof(cgc_themes) - 1,						 (u32)&iObj_set_themes,					 (u32)&iObj_get_themes						  },
		{	cgc_top,						sizeof(cgc_top) - 1,						 (u32)&iObj_set_top,					 (u32)&iObj_get_top							  },
		{	cgc_visible,					sizeof(cgc_visible) - 1,					 (u32)&iObj_set_visible,				 (u32)&iObj_get_visible						  },
		{	cgc_whatsThisHelpID,			sizeof(cgc_whatsThisHelpID) - 1,			 (u32)&iObj_set_whatsThisHelpID,		 (u32)&iObj_get_whatsThisHelpID				  },
		{	cgc_width,						sizeof(cgc_width) - 1,						 (u32)&iObj_set_width,					 (u32)&iObj_get_width						  },
		{	NULL,							0,											 0,										 0										 }
	};

	SPropertyMap gcProps_separator[] = 
	{
		{	cgc_application,				sizeof(cgc_application) - 1,				 (u32)&iObj_set_application,			 (u32)&iObj_get_application					  },
		{	cgc_baseClass,					sizeof(cgc_baseClass) - 1,					 (u32)&iObj_set_baseClass,				 (u32)&iObj_get_baseClass					  },
		{	cgc_class,						sizeof(cgc_class) - 1,						 (u32)&iObj_set_class,					 (u32)&iObj_get_class						  },
		{	cgc_classLibrary,				sizeof(cgc_classLibrary) - 1,				 (u32)&iObj_set_classLibrary,			 (u32)&iObj_get_classLibrary				  },
		{	cgc_comment,					sizeof(cgc_comment) - 1,					 (u32)&iObj_set_comment,				 (u32)&iObj_get_comment						  },
		{	cgc_enabled,					sizeof(cgc_enabled) - 1,					 (u32)&iObj_set_enabled,				 (u32)&iObj_get_enabled						  },
		{	cgc_name,						sizeof(cgc_name) - 1,						 (u32)&iObj_set_name,					 (u32)&iObj_get_name						  },
		{	cgc_parent,						sizeof(cgc_parent) - 1,						 (u32)&iObj_set_parent,					 (u32)&iObj_get_parent						  },
		{	cgc_parentClass,				sizeof(cgc_parentClass) - 1,				 (u32)&iObj_set_parentClass,			 (u32)&iObj_get_parentClass					  },
		{	cgc_style,						sizeof(cgc_style) - 1,						 (u32)&iObj_set_style,					 (u32)&iObj_get_style						  },
		{	cgc_tag,						sizeof(cgc_tag) - 1,						 (u32)&iObj_set_tag,					 (u32)&iObj_get_tag							  },
		{	cgc_visible,					sizeof(cgc_visible) - 1,					 (u32)&iObj_set_visible,				 (u32)&iObj_get_visible						  },
		{	NULL,							0,											 0,										 0										 }
	};

	SPropertyMap gcProps_line[] = 
	{
		{	cgc_anchor,						sizeof(cgc_anchor) - 1,						 (u32)&iObj_set_anchor,					 (u32)&iObj_get_anchor						  },
		{	cgc_application,				sizeof(cgc_application) - 1,				 (u32)&iObj_set_application,			 (u32)&iObj_get_application					  },
		{	cgc_baseClass,					sizeof(cgc_baseClass) - 1,					 (u32)&iObj_set_baseClass,				 (u32)&iObj_get_baseClass					  },
		{	cgc_class,						sizeof(cgc_class) - 1,						 (u32)&iObj_set_class,					 (u32)&iObj_get_class						  },
		{	cgc_classLibrary,				sizeof(cgc_classLibrary) - 1,				 (u32)&iObj_set_classLibrary,			 (u32)&iObj_get_classLibrary				  },
		{	cgc_borderColor,				sizeof(cgc_borderColor) - 1,				 (u32)&iObj_set_borderColor,			 (u32)&iObj_get_borderColor					  },
		{	cgc_borderWidth,				sizeof(cgc_borderWidth) - 1,				 (u32)&iObj_set_borderWidth,			 (u32)&iObj_get_borderWidth					  },
		{	cgc_borderStyle,				sizeof(cgc_borderStyle) - 1,				 (u32)&iObj_set_borderStyle,			 (u32)&iObj_get_borderStyle					  },
		{	cgc_colorSource,				sizeof(cgc_colorSource) - 1,				 (u32)&iObj_set_colorSource,			 (u32)&iObj_get_colorSource					  },
		{	cgc_comment,					sizeof(cgc_comment) - 1,					 (u32)&iObj_set_comment,				 (u32)&iObj_get_comment						  },
		{	cgc_dragIcon,					sizeof(cgc_dragIcon) - 1,					 (u32)&iObj_set_dragIcon,				 (u32)&iObj_get_dragIcon					  },
		{	cgc_dragMode,					sizeof(cgc_dragMode) - 1,					 (u32)&iObj_set_dragMode,				 (u32)&iObj_get_dragMode					  },
		{	cgc_drawMode,					sizeof(cgc_drawMode) - 1,					 (u32)&iObj_set_drawMode,				 (u32)&iObj_get_drawMode					  },
		{	cgc_enabled,					sizeof(cgc_enabled) - 1,					 (u32)&iObj_set_enabled,				 (u32)&iObj_get_enabled						  },
		{	cgc_height,						sizeof(cgc_height) - 1,						 (u32)&iObj_set_height,					 (u32)&iObj_get_height						  },
		{	cgc_helpContextID,				sizeof(cgc_helpContextID) - 1,				 (u32)&iObj_set_helpContextID,			 (u32)&iObj_get_helpContextID				  },
		{	cgc_left,						sizeof(cgc_left) - 1,						 (u32)&iObj_set_left,					 (u32)&iObj_get_left						  },
		{	cgc_lineSlant,					sizeof(cgc_lineSlant) - 1,					 (u32)&iObj_set_lineSlant,				 (u32)&iObj_get_lineSlant					  },
		{	cgc_mousePointer,				sizeof(cgc_mousePointer) - 1,				 (u32)&iObj_set_mousePointer,			 (u32)&iObj_get_mousePointer				  },
		{	cgc_name,						sizeof(cgc_name) - 1,						 (u32)&iObj_set_name,					 (u32)&iObj_get_name						  },
		{	cgc_oLEDragMode,				sizeof(cgc_oLEDragMode) - 1,				 (u32)&iObj_set_oLEDragMode,			 (u32)&iObj_get_oLEDragMode					  },
		{	cgc_oLEDragPicture,				sizeof(cgc_oLEDragPicture) - 1,				 (u32)&iObj_set_oLEDragPicture,			 (u32)&iObj_get_oLEDragPicture				  },
		{	cgc_oLEDropEffects,				sizeof(cgc_oLEDropEffects) - 1,				 (u32)&iObj_set_oLEDropEffects,			 (u32)&iObj_get_oLEDropEffects				  },
		{	cgc_oLEDropHasData,				sizeof(cgc_oLEDropHasData) - 1,				 (u32)&iObj_set_oLEDropHasData,			 (u32)&iObj_get_oLEDropHasData				  },
		{	cgc_oLEDropMode,				sizeof(cgc_oLEDropMode) - 1,				 (u32)&iObj_set_oLEDropMode,			 (u32)&iObj_get_oLEDropMode					  },
		{	cgc_parent,						sizeof(cgc_parent) - 1,						 (u32)&iObj_set_parent,					 (u32)&iObj_get_parent						  },
		{	cgc_parentClass,				sizeof(cgc_parentClass) - 1,				 (u32)&iObj_set_parentClass,			 (u32)&iObj_get_parentClass					  },
		{	cgc_polyPoints,					sizeof(cgc_polyPoints) - 1,					 (u32)&iObj_set_polyPoints,				 (u32)&iObj_get_polyPoints					  },
		{	cgc_rotation,					sizeof(cgc_rotation) - 1,					 (u32)&iObj_set_rotation,				 (u32)&iObj_get_rotation					  },
		{	cgc_statusBarText,				sizeof(cgc_statusBarText) - 1,				 (u32)&iObj_set_statusBarText,			 (u32)&iObj_get_statusBarText				  },
		{	cgc_tag,						sizeof(cgc_tag) - 1,						 (u32)&iObj_set_tag,					 (u32)&iObj_get_tag							  },
		{	cgc_toolTipText,				sizeof(cgc_toolTipText) - 1,				 (u32)&iObj_set_toolTipText,			 (u32)&iObj_get_toolTipText					  },
		{	cgc_top,						sizeof(cgc_top) - 1,						 (u32)&iObj_set_top,					 (u32)&iObj_get_top							  },
		{	cgc_visible,					sizeof(cgc_visible) - 1,					 (u32)&iObj_set_visible,				 (u32)&iObj_get_visible						  },
		{	cgc_whatsThisHelpID,			sizeof(cgc_whatsThisHelpID) - 1,			 (u32)&iObj_set_whatsThisHelpID,		 (u32)&iObj_get_whatsThisHelpID				  },
		{	cgc_width,						sizeof(cgc_width) - 1,						 (u32)&iObj_set_width,					 (u32)&iObj_get_width						  },
		{	NULL,							0,											 0,										 0										 }
	};

	SPropertyMap gcProps_shape[] = 
	{
		{	cgc_fillColor,					sizeof(cgc_fillColor) - 1,					 (u32)&iObj_set_fillColor,				 (u32)&iObj_get_fillColor					  },
		{	cgc_fillStyle,					sizeof(cgc_fillStyle) - 1,					 (u32)&iObj_set_fillStyle,				 (u32)&iObj_get_fillStyle					  },
		{	cgc_anchor,						sizeof(cgc_anchor) - 1,						 (u32)&iObj_set_anchor,					 (u32)&iObj_get_anchor						  },
		{	cgc_application,				sizeof(cgc_application) - 1,				 (u32)&iObj_set_application,			 (u32)&iObj_get_application					  },
		{	cgc_backStyle,					sizeof(cgc_backStyle) - 1,					 (u32)&iObj_set_backStyle,				 (u32)&iObj_get_backStyle					  },
		{	cgc_baseClass,					sizeof(cgc_baseClass) - 1,					 (u32)&iObj_set_baseClass,				 (u32)&iObj_get_baseClass					  },
		{	cgc_class,						sizeof(cgc_class) - 1,						 (u32)&iObj_set_class,					 (u32)&iObj_get_class						  },
		{	cgc_classLibrary,				sizeof(cgc_classLibrary) - 1,				 (u32)&iObj_set_classLibrary,			 (u32)&iObj_get_classLibrary				  },
		{	cgc_borderColor,				sizeof(cgc_borderColor) - 1,				 (u32)&iObj_set_borderColor,			 (u32)&iObj_get_borderColor					  },
		{	cgc_borderWidth,				sizeof(cgc_borderWidth) - 1,				 (u32)&iObj_set_borderWidth,			 (u32)&iObj_get_borderWidth					  },
		{	cgc_borderStyle,				sizeof(cgc_borderStyle) - 1,				 (u32)&iObj_set_borderStyle,			 (u32)&iObj_get_borderStyle					  },
		{	cgc_curvature,					sizeof(cgc_curvature) - 1,					 (u32)&iObj_set_curvature,				 (u32)&iObj_get_curvature					  },
		{	cgc_colorScheme,				sizeof(cgc_colorScheme) - 1,				 (u32)&iObj_set_colorScheme,			 (u32)&iObj_get_colorScheme					  },
		{	cgc_colorSource,				sizeof(cgc_colorSource) - 1,				 (u32)&iObj_set_colorSource,			 (u32)&iObj_get_colorSource					  },
		{	cgc_backColor,					sizeof(cgc_backColor) - 1,					 (u32)&iObj_set_backColor,				 (u32)&iObj_get_backColor					  },
		{	cgc_comment,					sizeof(cgc_comment) - 1,					 (u32)&iObj_set_comment,				 (u32)&iObj_get_comment						  },
		{	cgc_dragIcon,					sizeof(cgc_dragIcon) - 1,					 (u32)&iObj_set_dragIcon,				 (u32)&iObj_get_dragIcon					  },
		{	cgc_dragMode,					sizeof(cgc_dragMode) - 1,					 (u32)&iObj_set_dragMode,				 (u32)&iObj_get_dragMode					  },
		{	cgc_drawMode,					sizeof(cgc_drawMode) - 1,					 (u32)&iObj_set_drawMode,				 (u32)&iObj_get_drawMode					  },
		{	cgc_enabled,					sizeof(cgc_enabled) - 1,					 (u32)&iObj_set_enabled,				 (u32)&iObj_get_enabled						  },
		{	cgc_height,						sizeof(cgc_height) - 1,						 (u32)&iObj_set_height,					 (u32)&iObj_get_height						  },
		{	cgc_helpContextID,				sizeof(cgc_helpContextID) - 1,				 (u32)&iObj_set_helpContextID,			 (u32)&iObj_get_helpContextID				  },
		{	cgc_left,						sizeof(cgc_left) - 1,						 (u32)&iObj_set_left,					 (u32)&iObj_get_left						  },
		{	cgc_mouseIcon,					sizeof(cgc_mouseIcon) - 1,					 (u32)&iObj_set_mouseIcon,				 (u32)&iObj_get_mouseIcon					  },
		{	cgc_mousePointer,				sizeof(cgc_mousePointer) - 1,				 (u32)&iObj_set_mousePointer,			 (u32)&iObj_get_mousePointer				  },
		{	cgc_name,						sizeof(cgc_name) - 1,						 (u32)&iObj_set_name,					 (u32)&iObj_get_name						  },
		{	cgc_oLEDragMode,				sizeof(cgc_oLEDragMode) - 1,				 (u32)&iObj_set_oLEDragMode,			 (u32)&iObj_get_oLEDragMode					  },
		{	cgc_oLEDragPicture,				sizeof(cgc_oLEDragPicture) - 1,				 (u32)&iObj_set_oLEDragPicture,			 (u32)&iObj_get_oLEDragPicture				  },
		{	cgc_oLEDropEffects,				sizeof(cgc_oLEDropEffects) - 1,				 (u32)&iObj_set_oLEDropEffects,			 (u32)&iObj_get_oLEDropEffects				  },
		{	cgc_oLEDropHasData,				sizeof(cgc_oLEDropHasData) - 1,				 (u32)&iObj_set_oLEDropHasData,			 (u32)&iObj_get_oLEDropHasData				  },
		{	cgc_oLEDropMode,				sizeof(cgc_oLEDropMode) - 1,				 (u32)&iObj_set_oLEDropMode,			 (u32)&iObj_get_oLEDropMode					  },
		{	cgc_parent,						sizeof(cgc_parent) - 1,						 (u32)&iObj_set_parent,					 (u32)&iObj_get_parent						  },
		{	cgc_parentClass,				sizeof(cgc_parentClass) - 1,				 (u32)&iObj_set_parentClass,			 (u32)&iObj_get_parentClass					  },
		{	cgc_polyPoints,					sizeof(cgc_polyPoints) - 1,					 (u32)&iObj_set_polyPoints,				 (u32)&iObj_get_polyPoints					  },
		{	cgc_rotation,					sizeof(cgc_rotation) - 1,					 (u32)&iObj_set_rotation,				 (u32)&iObj_get_rotation					  },
		{	cgc_specialEffect,				sizeof(cgc_specialEffect) - 1,				 (u32)&iObj_set_specialEffect,			 (u32)&iObj_get_specialEffect				  },
		{	cgc_tag,						sizeof(cgc_tag) - 1,						 (u32)&iObj_set_tag,					 (u32)&iObj_get_tag							  },
		{	cgc_toolTipText,				sizeof(cgc_toolTipText) - 1,				 (u32)&iObj_set_toolTipText,			 (u32)&iObj_get_toolTipText					  },
		{	cgc_top,						sizeof(cgc_top) - 1,						 (u32)&iObj_set_top,					 (u32)&iObj_get_top							  },
		{	cgc_visible,					sizeof(cgc_visible) - 1,					 (u32)&iObj_set_visible,				 (u32)&iObj_get_visible						  },
		{	cgc_whatsThisHelpID,			sizeof(cgc_whatsThisHelpID) - 1,			 (u32)&iObj_set_whatsThisHelpID,		 (u32)&iObj_get_whatsThisHelpID				  },
		{	cgc_width,						sizeof(cgc_width) - 1,						 (u32)&iObj_set_width,					 (u32)&iObj_get_width						  },
		{	NULL,							0,											 0,										 0										 }
	};

	SPropertyMap gcProps_image[] = 
	{
		{	cgc_anchor,						sizeof(cgc_anchor) - 1,						 (u32)&iObj_set_anchor,					 (u32)&iObj_get_anchor						  },
		{	cgc_application,				sizeof(cgc_application) - 1,				 (u32)&iObj_set_application,			 (u32)&iObj_get_application					  },
		{	cgc_backStyle,					sizeof(cgc_backStyle) - 1,					 (u32)&iObj_set_backStyle,				 (u32)&iObj_get_backStyle					  },
		{	cgc_baseClass,					sizeof(cgc_baseClass) - 1,					 (u32)&iObj_set_baseClass,				 (u32)&iObj_get_baseClass					  },
		{	cgc_class,						sizeof(cgc_class) - 1,						 (u32)&iObj_set_class,					 (u32)&iObj_get_class						  },
		{	cgc_classLibrary,				sizeof(cgc_classLibrary) - 1,				 (u32)&iObj_set_classLibrary,			 (u32)&iObj_get_classLibrary				  },
		{	cgc_borderColor,				sizeof(cgc_borderColor) - 1,				 (u32)&iObj_set_borderColor,			 (u32)&iObj_get_borderColor					  },
		{	cgc_borderStyle,				sizeof(cgc_borderStyle) - 1,				 (u32)&iObj_set_borderStyle,			 (u32)&iObj_get_borderStyle					  },
		{	cgc_colorSource,				sizeof(cgc_colorSource) - 1,				 (u32)&iObj_set_colorSource,			 (u32)&iObj_get_colorSource					  },
		{	cgc_comment,					sizeof(cgc_comment) - 1,					 (u32)&iObj_set_comment,				 (u32)&iObj_get_comment						  },
		{	cgc_dragIcon,					sizeof(cgc_dragIcon) - 1,					 (u32)&iObj_set_dragIcon,				 (u32)&iObj_get_dragIcon					  },
		{	cgc_dragMode,					sizeof(cgc_dragMode) - 1,					 (u32)&iObj_set_dragMode,				 (u32)&iObj_get_dragMode					  },
		{	cgc_enabled,					sizeof(cgc_enabled) - 1,					 (u32)&iObj_set_enabled,				 (u32)&iObj_get_enabled						  },
		{	cgc_height,						sizeof(cgc_height) - 1,						 (u32)&iObj_set_height,					 (u32)&iObj_get_height						  },
		{	cgc_helpContextID,				sizeof(cgc_helpContextID) - 1,				 (u32)&iObj_set_helpContextID,			 (u32)&iObj_get_helpContextID				  },
		{	cgc_left,						sizeof(cgc_left) - 1,						 (u32)&iObj_set_left,					 (u32)&iObj_get_left						  },
		{	cgc_mousePointer,				sizeof(cgc_mousePointer) - 1,				 (u32)&iObj_set_mousePointer,			 (u32)&iObj_get_mousePointer				  },
		{	cgc_name,						sizeof(cgc_name) - 1,						 (u32)&iObj_set_name,					 (u32)&iObj_get_name						  },
		{	cgc_oLEDragMode,				sizeof(cgc_oLEDragMode) - 1,				 (u32)&iObj_set_oLEDragMode,			 (u32)&iObj_get_oLEDragMode					  },
		{	cgc_oLEDragPicture,				sizeof(cgc_oLEDragPicture) - 1,				 (u32)&iObj_set_oLEDragPicture,			 (u32)&iObj_get_oLEDragPicture				  },
		{	cgc_oLEDropEffects,				sizeof(cgc_oLEDropEffects) - 1,				 (u32)&iObj_set_oLEDropEffects,			 (u32)&iObj_get_oLEDropEffects				  },
		{	cgc_oLEDropHasData,				sizeof(cgc_oLEDropHasData) - 1,				 (u32)&iObj_set_oLEDropHasData,			 (u32)&iObj_get_oLEDropHasData				  },
		{	cgc_oLEDropMode,				sizeof(cgc_oLEDropMode) - 1,				 (u32)&iObj_set_oLEDropMode,			 (u32)&iObj_get_oLEDropMode					  },
		{	cgc_parent,						sizeof(cgc_parent) - 1,						 (u32)&iObj_set_parent,					 (u32)&iObj_get_parent						  },
		{	cgc_parentClass,				sizeof(cgc_parentClass) - 1,				 (u32)&iObj_set_parentClass,			 (u32)&iObj_get_parentClass					  },
		{	cgc_picture,					sizeof(cgc_picture) - 1,					 (u32)&iObj_set_picture,				 (u32)&iObj_get_picture						  },
		{	cgc_pictureVal,					sizeof(cgc_pictureVal) - 1,					 (u32)&iObj_set_pictureVal,				 (u32)&iObj_get_pictureVal					  },
		{	cgc_rotateFlip,					sizeof(cgc_rotateFlip) - 1,					 (u32)&iObj_set_rotateFlip,				 (u32)&iObj_get_rotateFlip					  },
		{	cgc_stretch,					sizeof(cgc_stretch) - 1,					 (u32)&iObj_set_stretch,				 (u32)&iObj_get_stretch						  },
		{	cgc_statusBarText,				sizeof(cgc_statusBarText) - 1,				 (u32)&iObj_set_statusBarText,			 (u32)&iObj_get_statusBarText				  },
		{	cgc_tag,						sizeof(cgc_tag) - 1,						 (u32)&iObj_set_tag,					 (u32)&iObj_get_tag							  },
		{	cgc_themes,						sizeof(cgc_themes) - 1,						 (u32)&iObj_set_themes,					 (u32)&iObj_get_themes						  },
		{	cgc_toolTipText,				sizeof(cgc_toolTipText) - 1,				 (u32)&iObj_set_toolTipText,			 (u32)&iObj_get_toolTipText					  },
		{	cgc_top,						sizeof(cgc_top) - 1,						 (u32)&iObj_set_top,					 (u32)&iObj_get_top							  },
		{	cgc_visible,					sizeof(cgc_visible) - 1,					 (u32)&iObj_set_visible,				 (u32)&iObj_get_visible						  },
		{	cgc_whatsThisHelpID,			sizeof(cgc_whatsThisHelpID) - 1,			 (u32)&iObj_set_whatsThisHelpID,		 (u32)&iObj_get_whatsThisHelpID				  },
		{	cgc_width,						sizeof(cgc_width) - 1,						 (u32)&iObj_set_width,					 (u32)&iObj_get_width						  },
		{	NULL,							0,											 0,										 0										 }
	};

	SPropertyMap gcProps_container[] = 
	{
		{	cgc_activeControl,				sizeof(cgc_activeControl) - 1,				 (u32)&iObj_set_activeControl,			 (u32)&iObj_get_activeControl				  },
		{	cgc_anchor,						sizeof(cgc_anchor) - 1,						 (u32)&iObj_set_anchor,					 (u32)&iObj_get_anchor						  },
		{	cgc_application,				sizeof(cgc_application) - 1,				 (u32)&iObj_set_application,			 (u32)&iObj_get_application					  },
		{	cgc_backStyle,					sizeof(cgc_backStyle) - 1,					 (u32)&iObj_set_backStyle,				 (u32)&iObj_get_backStyle					  },
		{	cgc_baseClass,					sizeof(cgc_baseClass) - 1,					 (u32)&iObj_set_baseClass,				 (u32)&iObj_get_baseClass					  },
		{	cgc_class,						sizeof(cgc_class) - 1,						 (u32)&iObj_set_class,					 (u32)&iObj_get_class						  },
		{	cgc_classLibrary,				sizeof(cgc_classLibrary) - 1,				 (u32)&iObj_set_classLibrary,			 (u32)&iObj_get_classLibrary				  },
		{	cgc_controls,					sizeof(cgc_controls) - 1,					 (u32)&iObj_set_controls,				 (u32)&iObj_get_controls					  },
		{	cgc_controlCount,				sizeof(cgc_controlCount) - 1,				 (u32)&iObj_set_controlCount,			 (u32)&iObj_get_controlCount				  },
		{	cgc_objects,					sizeof(cgc_objects) - 1,					 (u32)&iObj_set_objects,				 (u32)&iObj_get_objects						  },
		{	cgc_borderColor,				sizeof(cgc_borderColor) - 1,				 (u32)&iObj_set_borderColor,			 (u32)&iObj_get_borderColor					  },
		{	cgc_borderWidth,				sizeof(cgc_borderWidth) - 1,				 (u32)&iObj_set_borderWidth,			 (u32)&iObj_get_borderWidth					  },
		{	cgc_colorSource,				sizeof(cgc_colorSource) - 1,				 (u32)&iObj_set_colorSource,			 (u32)&iObj_get_colorSource					  },
		{	cgc_foreColor,					sizeof(cgc_foreColor) - 1,					 (u32)&iObj_set_foreColor,				 (u32)&iObj_get_foreColor					  },
		{	cgc_backColor,					sizeof(cgc_backColor) - 1,					 (u32)&iObj_set_backColor,				 (u32)&iObj_get_backColor					  },
		{	cgc_comment,					sizeof(cgc_comment) - 1,					 (u32)&iObj_set_comment,				 (u32)&iObj_get_comment						  },
		{	cgc_dragIcon,					sizeof(cgc_dragIcon) - 1,					 (u32)&iObj_set_dragIcon,				 (u32)&iObj_get_dragIcon					  },
		{	cgc_dragMode,					sizeof(cgc_dragMode) - 1,					 (u32)&iObj_set_dragMode,				 (u32)&iObj_get_dragMode					  },
		{	cgc_enabled,					sizeof(cgc_enabled) - 1,					 (u32)&iObj_set_enabled,				 (u32)&iObj_get_enabled						  },
		{	cgc_height,						sizeof(cgc_height) - 1,						 (u32)&iObj_set_height,					 (u32)&iObj_get_height						  },
		{	cgc_helpContextID,				sizeof(cgc_helpContextID) - 1,				 (u32)&iObj_set_helpContextID,			 (u32)&iObj_get_helpContextID				  },
		{	cgc_left,						sizeof(cgc_left) - 1,						 (u32)&iObj_set_left,					 (u32)&iObj_get_left						  },
		{	cgc_mouseIcon,					sizeof(cgc_mouseIcon) - 1,					 (u32)&iObj_set_mouseIcon,				 (u32)&iObj_get_mouseIcon					  },
		{	cgc_mousePointer,				sizeof(cgc_mousePointer) - 1,				 (u32)&iObj_set_mousePointer,			 (u32)&iObj_get_mousePointer				  },
		{	cgc_name,						sizeof(cgc_name) - 1,						 (u32)&iObj_set_name,					 (u32)&iObj_get_name						  },
		{	cgc_oLEDragMode,				sizeof(cgc_oLEDragMode) - 1,				 (u32)&iObj_set_oLEDragMode,			 (u32)&iObj_get_oLEDragMode					  },
		{	cgc_oLEDragPicture,				sizeof(cgc_oLEDragPicture) - 1,				 (u32)&iObj_set_oLEDragPicture,			 (u32)&iObj_get_oLEDragPicture				  },
		{	cgc_oLEDropEffects,				sizeof(cgc_oLEDropEffects) - 1,				 (u32)&iObj_set_oLEDropEffects,			 (u32)&iObj_get_oLEDropEffects				  },
		{	cgc_oLEDropHasData,				sizeof(cgc_oLEDropHasData) - 1,				 (u32)&iObj_set_oLEDropHasData,			 (u32)&iObj_get_oLEDropHasData				  },
		{	cgc_oLEDropMode,				sizeof(cgc_oLEDropMode) - 1,				 (u32)&iObj_set_oLEDropMode,			 (u32)&iObj_get_oLEDropMode					  },
		{	cgc_parent,						sizeof(cgc_parent) - 1,						 (u32)&iObj_set_parent,					 (u32)&iObj_get_parent						  },
		{	cgc_parentClass,				sizeof(cgc_parentClass) - 1,				 (u32)&iObj_set_parentClass,			 (u32)&iObj_get_parentClass					  },
		{	cgc_picture,					sizeof(cgc_picture) - 1,					 (u32)&iObj_set_picture,				 (u32)&iObj_get_picture						  },
		{	cgc_specialEffect,				sizeof(cgc_specialEffect) - 1,				 (u32)&iObj_set_specialEffect,			 (u32)&iObj_get_specialEffect				  },
		{	cgc_statusBarText,				sizeof(cgc_statusBarText) - 1,				 (u32)&iObj_set_statusBarText,			 (u32)&iObj_get_statusBarText				  },
		{	cgc_tabIndex,					sizeof(cgc_tabIndex) - 1,					 (u32)&iObj_set_tabIndex,				 (u32)&iObj_get_tabIndex					  },
		{	cgc_tabStop,					sizeof(cgc_tabStop) - 1,					 (u32)&iObj_set_tabStop,				 (u32)&iObj_get_tabStop						  },
		{	cgc_tag,						sizeof(cgc_tag) - 1,						 (u32)&iObj_set_tag,					 (u32)&iObj_get_tag							  },
		{	cgc_toolTipText,				sizeof(cgc_toolTipText) - 1,				 (u32)&iObj_set_toolTipText,			 (u32)&iObj_get_toolTipText					  },
		{	cgc_top,						sizeof(cgc_top) - 1,						 (u32)&iObj_set_top,					 (u32)&iObj_get_top							  },
		{	cgc_visible,					sizeof(cgc_visible) - 1,					 (u32)&iObj_set_visible,				 (u32)&iObj_get_visible						  },
		{	cgc_whatsThisHelpID,			sizeof(cgc_whatsThisHelpID) - 1,			 (u32)&iObj_set_whatsThisHelpID,		 (u32)&iObj_get_whatsThisHelpID				  },
		{	cgc_width,						sizeof(cgc_width) - 1,						 (u32)&iObj_set_width,					 (u32)&iObj_get_width						  },
		{	NULL,							0,											 0,										 0										 }
	};

	SPropertyMap gcProps_control[] = 
	{
		{	cgc_activeControl,				sizeof(cgc_activeControl) - 1,				 (u32)&iObj_set_activeControl,			 (u32)&iObj_get_activeControl				  },
		{	cgc_anchor,						sizeof(cgc_anchor) - 1,						 (u32)&iObj_set_anchor,					 (u32)&iObj_get_anchor						  },
		{	cgc_application,				sizeof(cgc_application) - 1,				 (u32)&iObj_set_application,			 (u32)&iObj_get_application					  },
		{	cgc_backStyle,					sizeof(cgc_backStyle) - 1,					 (u32)&iObj_set_backStyle,				 (u32)&iObj_get_backStyle					  },
		{	cgc_baseClass,					sizeof(cgc_baseClass) - 1,					 (u32)&iObj_set_baseClass,				 (u32)&iObj_get_baseClass					  },
		{	cgc_class,						sizeof(cgc_class) - 1,						 (u32)&iObj_set_class,					 (u32)&iObj_get_class						  },
		{	cgc_classLibrary,				sizeof(cgc_classLibrary) - 1,				 (u32)&iObj_set_classLibrary,			 (u32)&iObj_get_classLibrary				  },
		{	cgc_controls,					sizeof(cgc_controls) - 1,					 (u32)&iObj_set_controls,				 (u32)&iObj_get_controls					  },
		{	cgc_controlCount,				sizeof(cgc_controlCount) - 1,				 (u32)&iObj_set_controlCount,			 (u32)&iObj_get_controlCount				  },
		{	cgc_objects,					sizeof(cgc_objects) - 1,					 (u32)&iObj_set_objects,				 (u32)&iObj_get_objects						  },
		{	cgc_borderColor,				sizeof(cgc_borderColor) - 1,				 (u32)&iObj_set_borderColor,			 (u32)&iObj_get_borderColor					  },
		{	cgc_borderWidth,				sizeof(cgc_borderWidth) - 1,				 (u32)&iObj_set_borderWidth,			 (u32)&iObj_get_borderWidth					  },
		{	cgc_colorSource,				sizeof(cgc_colorSource) - 1,				 (u32)&iObj_set_colorSource,			 (u32)&iObj_get_colorSource					  },
		{	cgc_foreColor,					sizeof(cgc_foreColor) - 1,					 (u32)&iObj_set_foreColor,				 (u32)&iObj_get_foreColor					  },
		{	cgc_backColor,					sizeof(cgc_backColor) - 1,					 (u32)&iObj_set_backColor,				 (u32)&iObj_get_backColor					  },
		{	cgc_comment,					sizeof(cgc_comment) - 1,					 (u32)&iObj_set_comment,				 (u32)&iObj_get_comment						  },
		{	cgc_dragIcon,					sizeof(cgc_dragIcon) - 1,					 (u32)&iObj_set_dragIcon,				 (u32)&iObj_get_dragIcon					  },
		{	cgc_dragMode,					sizeof(cgc_dragMode) - 1,					 (u32)&iObj_set_dragMode,				 (u32)&iObj_get_dragMode					  },
		{	cgc_enabled,					sizeof(cgc_enabled) - 1,					 (u32)&iObj_set_enabled,				 (u32)&iObj_get_enabled						  },
		{	cgc_height,						sizeof(cgc_height) - 1,						 (u32)&iObj_set_height,					 (u32)&iObj_get_height						  },
		{	cgc_helpContextID,				sizeof(cgc_helpContextID) - 1,				 (u32)&iObj_set_helpContextID,			 (u32)&iObj_get_helpContextID				  },
		{	cgc_left,						sizeof(cgc_left) - 1,						 (u32)&iObj_set_left,					 (u32)&iObj_get_left						  },
		{	cgc_mouseIcon,					sizeof(cgc_mouseIcon) - 1,					 (u32)&iObj_set_mouseIcon,				 (u32)&iObj_get_mouseIcon					  },
		{	cgc_mousePointer,				sizeof(cgc_mousePointer) - 1,				 (u32)&iObj_set_mousePointer,			 (u32)&iObj_get_mousePointer				  },
		{	cgc_name,						sizeof(cgc_name) - 1,						 (u32)&iObj_set_name,					 (u32)&iObj_get_name						  },
		{	cgc_oLEDragMode,				sizeof(cgc_oLEDragMode) - 1,				 (u32)&iObj_set_oLEDragMode,			 (u32)&iObj_get_oLEDragMode					  },
		{	cgc_oLEDragPicture,				sizeof(cgc_oLEDragPicture) - 1,				 (u32)&iObj_set_oLEDragPicture,			 (u32)&iObj_get_oLEDragPicture				  },
		{	cgc_oLEDropEffects,				sizeof(cgc_oLEDropEffects) - 1,				 (u32)&iObj_set_oLEDropEffects,			 (u32)&iObj_get_oLEDropEffects				  },
		{	cgc_oLEDropHasData,				sizeof(cgc_oLEDropHasData) - 1,				 (u32)&iObj_set_oLEDropHasData,			 (u32)&iObj_get_oLEDropHasData				  },
		{	cgc_oLEDropMode,				sizeof(cgc_oLEDropMode) - 1,				 (u32)&iObj_set_oLEDropMode,			 (u32)&iObj_get_oLEDropMode					  },
		{	cgc_parent,						sizeof(cgc_parent) - 1,						 (u32)&iObj_set_parent,					 (u32)&iObj_get_parent						  },
		{	cgc_parentClass,				sizeof(cgc_parentClass) - 1,				 (u32)&iObj_set_parentClass,			 (u32)&iObj_get_parentClass					  },
		{	cgc_picture,					sizeof(cgc_picture) - 1,					 (u32)&iObj_set_picture,				 (u32)&iObj_get_picture						  },
		{	cgc_specialEffect,				sizeof(cgc_specialEffect) - 1,				 (u32)&iObj_set_specialEffect,			 (u32)&iObj_get_specialEffect				  },
		{	cgc_statusBarText,				sizeof(cgc_statusBarText) - 1,				 (u32)&iObj_set_statusBarText,			 (u32)&iObj_get_statusBarText				  },
		{	cgc_tabIndex,					sizeof(cgc_tabIndex) - 1,					 (u32)&iObj_set_tabIndex,				 (u32)&iObj_get_tabIndex					  },
		{	cgc_tabStop,					sizeof(cgc_tabStop) - 1,					 (u32)&iObj_set_tabStop,				 (u32)&iObj_get_tabStop						  },
		{	cgc_tag,						sizeof(cgc_tag) - 1,						 (u32)&iObj_set_tag,					 (u32)&iObj_get_tag							  },
		{	cgc_toolTipText,				sizeof(cgc_toolTipText) - 1,				 (u32)&iObj_set_toolTipText,			 (u32)&iObj_get_toolTipText					  },
		{	cgc_top,						sizeof(cgc_top) - 1,						 (u32)&iObj_set_top,					 (u32)&iObj_get_top							  },
		{	cgc_visible,					sizeof(cgc_visible) - 1,					 (u32)&iObj_set_visible,				 (u32)&iObj_get_visible						  },
		{	cgc_whatsThisHelpID,			sizeof(cgc_whatsThisHelpID) - 1,			 (u32)&iObj_set_whatsThisHelpID,		 (u32)&iObj_get_whatsThisHelpID				  },
		{	cgc_width,						sizeof(cgc_width) - 1,						 (u32)&iObj_set_width,					 (u32)&iObj_get_width						  },
		{	NULL,							0,											 0,										 0										 }
	};

	SPropertyMap gcProps_grid[] = 
	{
		{	cgc_activeColumn,				sizeof(cgc_activeColumn) - 1,				 (u32)&iObj_set_activeColumn,			 (u32)&iObj_get_activeColumn				  },
		{	cgc_activeRow,					sizeof(cgc_activeRow) - 1,					 (u32)&iObj_set_activeRow,				 (u32)&iObj_get_activeRow					  },
		{	cgc_allowAddNew,				sizeof(cgc_allowAddNew) - 1,				 (u32)&iObj_set_allowAddNew,			 (u32)&iObj_get_allowAddNew					  },
		{	cgc_allowAutoColumnFit,			sizeof(cgc_allowAutoColumnFit) - 1,			 (u32)&iObj_set_allowAutoColumnFit,		 (u32)&iObj_get_allowAutoColumnFit			  },
		{	cgc_allowCellSelection,			sizeof(cgc_allowCellSelection) - 1,			 (u32)&iObj_set_allowCellSelection,		 (u32)&iObj_get_allowCellSelection			  },
		{	cgc_allowHeaderSizing,			sizeof(cgc_allowHeaderSizing) - 1,			 (u32)&iObj_set_allowHeaderSizing,		 (u32)&iObj_get_allowHeaderSizing			  },
		{	cgc_allowRowSizing,				sizeof(cgc_allowRowSizing) - 1,				 (u32)&iObj_set_allowRowSizing,			 (u32)&iObj_get_allowRowSizing				  },
		{	cgc_gridLineColor,				sizeof(cgc_gridLineColor) - 1,				 (u32)&iObj_set_gridLineColor,			 (u32)&iObj_get_gridLineColor				  },
		{	cgc_gridLines,					sizeof(cgc_gridLines) - 1,					 (u32)&iObj_set_gridLines,				 (u32)&iObj_get_gridLines					  },
		{	cgc_gridLineWidth,				sizeof(cgc_gridLineWidth) - 1,				 (u32)&iObj_set_gridLineWidth,			 (u32)&iObj_get_gridLineWidth				  },
		{	cgc_headerHeight,				sizeof(cgc_headerHeight) - 1,				 (u32)&iObj_set_headerHeight,			 (u32)&iObj_get_headerHeight				  },
		{	cgc_highLight,					sizeof(cgc_highLight) - 1,					 (u32)&iObj_set_highLight,				 (u32)&iObj_get_highLight					  },
		{	cgc_highlightBackColor,			sizeof(cgc_highlightBackColor) - 1,			 (u32)&iObj_set_highlightBackColor,		 (u32)&iObj_get_highlightBackColor			  },
		{	cgc_highlightForeColor,			sizeof(cgc_highlightForeColor) - 1,			 (u32)&iObj_set_highlightForeColor,		 (u32)&iObj_get_highlightForeColor			  },
		{	cgc_highlightStyle,				sizeof(cgc_highlightStyle) - 1,				 (u32)&iObj_set_highlightStyle,			 (u32)&iObj_get_highlightStyle				  },
		{	cgc_highLightRow,				sizeof(cgc_highLightRow) - 1,				 (u32)&iObj_set_highLightRow,			 (u32)&iObj_get_highLightRow				  },
		{	cgc_highlightRowLineWidth,		sizeof(cgc_highlightRowLineWidth) - 1,		 (u32)&iObj_set_highlightRowLineWidth,	 (u32)&iObj_get_highlightRowLineWidth		  },
		{	cgc_leftColumn,					sizeof(cgc_leftColumn) - 1,					 (u32)&iObj_set_leftColumn,				 (u32)&iObj_get_leftColumn					  },
		{	cgc_linkMaster,					sizeof(cgc_linkMaster) - 1,					 (u32)&iObj_set_linkMaster,				 (u32)&iObj_get_linkMaster					  },
		{	cgc_childOrder,					sizeof(cgc_childOrder) - 1,					 (u32)&iObj_set_childOrder,				 (u32)&iObj_get_childOrder					  },
		{	cgc_lockColumns,				sizeof(cgc_lockColumns) - 1,				 (u32)&iObj_set_lockColumns,			 (u32)&iObj_get_lockColumns					  },
		{	cgc_lockColumnsLeft,			sizeof(cgc_lockColumnsLeft) - 1,			 (u32)&iObj_set_lockColumnsLeft,		 (u32)&iObj_get_lockColumnsLeft				  },
		{	cgc_memberClass,				sizeof(cgc_memberClass) - 1,				 (u32)&iObj_set_memberClass,			 (u32)&iObj_get_memberClass					  },
		{	cgc_memberClassLibrary,			sizeof(cgc_memberClassLibrary) - 1,			 (u32)&iObj_set_memberClassLibrary,		 (u32)&iObj_get_memberClassLibrary			  },
		{	cgc_optimize,					sizeof(cgc_optimize) - 1,					 (u32)&iObj_set_optimize,				 (u32)&iObj_get_optimize					  },
		{	cgc_partition,					sizeof(cgc_partition) - 1,					 (u32)&iObj_set_partition,				 (u32)&iObj_get_partition					  },
		{	cgc_panelLink,					sizeof(cgc_panelLink) - 1,					 (u32)&iObj_set_panelLink,				 (u32)&iObj_get_panelLink					  },
		{	cgc_panel,						sizeof(cgc_panel) - 1,						 (u32)&iObj_set_panel,					 (u32)&iObj_get_panel						  },
		{	cgc_splitBar,					sizeof(cgc_splitBar) - 1,					 (u32)&iObj_set_splitBar,				 (u32)&iObj_get_splitBar					  },
		{	cgc_deleteMark,					sizeof(cgc_deleteMark) - 1,					 (u32)&iObj_set_deleteMark,				 (u32)&iObj_get_deleteMark					  },
		{	cgc_recordMark,					sizeof(cgc_recordMark) - 1,					 (u32)&iObj_set_recordMark,				 (u32)&iObj_get_recordMark					  },
		{	cgc_relativeColumn,				sizeof(cgc_relativeColumn) - 1,				 (u32)&iObj_set_relativeColumn,			 (u32)&iObj_get_relativeColumn				  },
		{	cgc_relativeRow,				sizeof(cgc_relativeRow) - 1,				 (u32)&iObj_set_relativeRow,			 (u32)&iObj_get_relativeRow					  },
		{	cgc_view,						sizeof(cgc_view) - 1,						 (u32)&iObj_set_view,					 (u32)&iObj_get_view						  },
		{	cgc_anchor,						sizeof(cgc_anchor) - 1,						 (u32)&iObj_set_anchor,					 (u32)&iObj_get_anchor						  },
		{	cgc_application,				sizeof(cgc_application) - 1,				 (u32)&iObj_set_application,			 (u32)&iObj_get_application					  },
		{	cgc_baseClass,					sizeof(cgc_baseClass) - 1,					 (u32)&iObj_set_baseClass,				 (u32)&iObj_get_baseClass					  },
		{	cgc_class,						sizeof(cgc_class) - 1,						 (u32)&iObj_set_class,					 (u32)&iObj_get_class						  },
		{	cgc_classLibrary,				sizeof(cgc_classLibrary) - 1,				 (u32)&iObj_set_classLibrary,			 (u32)&iObj_get_classLibrary				  },
		{	cgc_columns,					sizeof(cgc_columns) - 1,					 (u32)&iObj_set_columns,				 (u32)&iObj_get_columns						  },
		{	cgc_columnCount,				sizeof(cgc_columnCount) - 1,				 (u32)&iObj_set_columnCount,			 (u32)&iObj_get_columnCount					  },
		{	cgc_objects,					sizeof(cgc_objects) - 1,					 (u32)&iObj_set_objects,				 (u32)&iObj_get_objects						  },
		{	cgc_foreColor,					sizeof(cgc_foreColor) - 1,					 (u32)&iObj_set_foreColor,				 (u32)&iObj_get_foreColor					  },
		{	cgc_backColor,					sizeof(cgc_backColor) - 1,					 (u32)&iObj_set_backColor,				 (u32)&iObj_get_backColor					  },
		{	cgc_comment,					sizeof(cgc_comment) - 1,					 (u32)&iObj_set_comment,				 (u32)&iObj_get_comment						  },
		{	cgc_recordSource,				sizeof(cgc_recordSource) - 1,				 (u32)&iObj_set_recordSource,			 (u32)&iObj_get_recordSource				  },
		{	cgc_recordSourceType,			sizeof(cgc_recordSourceType) - 1,			 (u32)&iObj_set_recordSourceType,		 (u32)&iObj_get_recordSourceType			  },
		{	cgc_dragIcon,					sizeof(cgc_dragIcon) - 1,					 (u32)&iObj_set_dragIcon,				 (u32)&iObj_get_dragIcon					  },
		{	cgc_dragMode,					sizeof(cgc_dragMode) - 1,					 (u32)&iObj_set_dragMode,				 (u32)&iObj_get_dragMode					  },
		{	cgc_enabled,					sizeof(cgc_enabled) - 1,					 (u32)&iObj_set_enabled,				 (u32)&iObj_get_enabled						  },
		{	cgc_fontBold,					sizeof(cgc_fontBold) - 1,					 (u32)&iObj_set_fontBold,				 (u32)&iObj_get_fontBold					  },
		{	cgc_fontCharSet,				sizeof(cgc_fontCharSet) - 1,				 (u32)&iObj_set_fontCharSet,			 (u32)&iObj_get_fontCharSet					  },
		{	cgc_fontCondense,				sizeof(cgc_fontCondense) - 1,				 (u32)&iObj_set_fontCondense,			 (u32)&iObj_get_fontCondense				  },
		{	cgc_fontExtend,					sizeof(cgc_fontExtend) - 1,					 (u32)&iObj_set_fontExtend,				 (u32)&iObj_get_fontExtend					  },
		{	cgc_fontItalic,					sizeof(cgc_fontItalic) - 1,					 (u32)&iObj_set_fontItalic,				 (u32)&iObj_get_fontItalic					  },
		{	cgc_fontName,					sizeof(cgc_fontName) - 1,					 (u32)&iObj_set_fontName,				 (u32)&iObj_get_fontName					  },
		{	cgc_fontOutline,				sizeof(cgc_fontOutline) - 1,				 (u32)&iObj_set_fontOutline,			 (u32)&iObj_get_fontOutline					  },
		{	cgc_fontShadow,					sizeof(cgc_fontShadow) - 1,					 (u32)&iObj_set_fontShadow,				 (u32)&iObj_get_fontShadow					  },
		{	cgc_fontSize,					sizeof(cgc_fontSize) - 1,					 (u32)&iObj_set_fontSize,				 (u32)&iObj_get_fontSize					  },
		{	cgc_fontStrikeThru,				sizeof(cgc_fontStrikeThru) - 1,				 (u32)&iObj_set_fontStrikeThru,			 (u32)&iObj_get_fontStrikeThru				  },
		{	cgc_fontUnderline,				sizeof(cgc_fontUnderline) - 1,				 (u32)&iObj_set_fontUnderline,			 (u32)&iObj_get_fontUnderline				  },
		{	cgc_headerHeight,				sizeof(cgc_headerHeight) - 1,				 (u32)&iObj_set_headerHeight,			 (u32)&iObj_get_headerHeight				  },
		{	cgc_height,						sizeof(cgc_height) - 1,						 (u32)&iObj_set_height,					 (u32)&iObj_get_height						  },
		{	cgc_helpContextID,				sizeof(cgc_helpContextID) - 1,				 (u32)&iObj_set_helpContextID,			 (u32)&iObj_get_helpContextID				  },
		{	cgc_left,						sizeof(cgc_left) - 1,						 (u32)&iObj_set_left,					 (u32)&iObj_get_left						  },
		{	cgc_mouseIcon,					sizeof(cgc_mouseIcon) - 1,					 (u32)&iObj_set_mouseIcon,				 (u32)&iObj_get_mouseIcon					  },
		{	cgc_mousePointer,				sizeof(cgc_mousePointer) - 1,				 (u32)&iObj_set_mousePointer,			 (u32)&iObj_get_mousePointer				  },
		{	cgc_name,						sizeof(cgc_name) - 1,						 (u32)&iObj_set_name,					 (u32)&iObj_get_name						  },
		{	cgc_oLEDragMode,				sizeof(cgc_oLEDragMode) - 1,				 (u32)&iObj_set_oLEDragMode,			 (u32)&iObj_get_oLEDragMode					  },
		{	cgc_oLEDragPicture,				sizeof(cgc_oLEDragPicture) - 1,				 (u32)&iObj_set_oLEDragPicture,			 (u32)&iObj_get_oLEDragPicture				  },
		{	cgc_oLEDropEffects,				sizeof(cgc_oLEDropEffects) - 1,				 (u32)&iObj_set_oLEDropEffects,			 (u32)&iObj_get_oLEDropEffects				  },
		{	cgc_oLEDropHasData,				sizeof(cgc_oLEDropHasData) - 1,				 (u32)&iObj_set_oLEDropHasData,			 (u32)&iObj_get_oLEDropHasData				  },
		{	cgc_oLEDropMode,				sizeof(cgc_oLEDropMode) - 1,				 (u32)&iObj_set_oLEDropMode,			 (u32)&iObj_get_oLEDropMode					  },
		{	cgc_parent,						sizeof(cgc_parent) - 1,						 (u32)&iObj_set_parent,					 (u32)&iObj_get_parent						  },
		{	cgc_parentClass,				sizeof(cgc_parentClass) - 1,				 (u32)&iObj_set_parentClass,			 (u32)&iObj_get_parentClass					  },
		{	cgc_readOnly,					sizeof(cgc_readOnly) - 1,					 (u32)&iObj_set_readOnly,				 (u32)&iObj_get_readOnly					  },
		{	cgc_relationalExpr,				sizeof(cgc_relationalExpr) - 1,				 (u32)&iObj_set_relationalExpr,			 (u32)&iObj_get_relationalExpr				  },
		{	cgc_rightToLeft,				sizeof(cgc_rightToLeft) - 1,				 (u32)&iObj_set_rightToLeft,			 (u32)&iObj_get_rightToLeft					  },
		{	cgc_rowColChange,				sizeof(cgc_rowColChange) - 1,				 (u32)&iObj_set_rowColChange,			 (u32)&iObj_get_rowColChange				  },
		{	cgc_rowHeight,					sizeof(cgc_rowHeight) - 1,					 (u32)&iObj_set_rowHeight,				 (u32)&iObj_get_rowHeight					  },
		{	cgc_scrollBars,					sizeof(cgc_scrollBars) - 1,					 (u32)&iObj_set_scrollBars,				 (u32)&iObj_get_scrollBars					  },
		{	cgc_selectedItemBackColor,		sizeof(cgc_selectedItemBackColor) - 1,		 (u32)&iObj_set_selectedItemBackColor,	 (u32)&iObj_get_selectedItemBackColor		  },
		{	cgc_selectedItemForeColor,		sizeof(cgc_selectedItemForeColor) - 1,		 (u32)&iObj_set_selectedItemForeColor,	 (u32)&iObj_get_selectedItemForeColor		  },
		{	cgc_statusBarText,				sizeof(cgc_statusBarText) - 1,				 (u32)&iObj_set_statusBarText,			 (u32)&iObj_get_statusBarText				  },
		{	cgc_tabIndex,					sizeof(cgc_tabIndex) - 1,					 (u32)&iObj_set_tabIndex,				 (u32)&iObj_get_tabIndex					  },
		{	cgc_tabStop,					sizeof(cgc_tabStop) - 1,					 (u32)&iObj_set_tabStop,				 (u32)&iObj_get_tabStop						  },
		{	cgc_tag,						sizeof(cgc_tag) - 1,						 (u32)&iObj_set_tag,					 (u32)&iObj_get_tag							  },
		{	cgc_themes,						sizeof(cgc_themes) - 1,						 (u32)&iObj_set_themes,					 (u32)&iObj_get_themes						  },
		{	cgc_toolTipText,				sizeof(cgc_toolTipText) - 1,				 (u32)&iObj_set_toolTipText,			 (u32)&iObj_get_toolTipText					  },
		{	cgc_top,						sizeof(cgc_top) - 1,						 (u32)&iObj_set_top,					 (u32)&iObj_get_top							  },
		{	cgc_value,						sizeof(cgc_value) - 1,						 (u32)&iObj_set_value,					 (u32)&iObj_get_value						  },
		{	cgc_visible,					sizeof(cgc_visible) - 1,					 (u32)&iObj_set_visible,				 (u32)&iObj_get_visible						  },
		{	cgc_whatsThisHelpID,			sizeof(cgc_whatsThisHelpID) - 1,			 (u32)&iObj_set_whatsThisHelpID,		 (u32)&iObj_get_whatsThisHelpID				  },
		{	cgc_width,						sizeof(cgc_width) - 1,						 (u32)&iObj_set_width,					 (u32)&iObj_get_width						  },
		{	NULL,							0,											 0,										 0										 }
	};

	SPropertyMap gcProps_column[] = 
	{
		{	cgc_currentControl,				sizeof(cgc_currentControl) - 1,				 (u32)&iObj_set_currentControl,			 (u32)&iObj_get_currentControl				  },
		{	cgc_dynamicAlignment,			sizeof(cgc_dynamicAlignment) - 1,			 (u32)&iObj_set_dynamicAlignment,		 (u32)&iObj_get_dynamicAlignment			  },
		{	cgc_dynamicBackColor,			sizeof(cgc_dynamicBackColor) - 1,			 (u32)&iObj_set_dynamicBackColor,		 (u32)&iObj_get_dynamicBackColor			  },
		{	cgc_dynamicCurrentControl,		sizeof(cgc_dynamicCurrentControl) - 1,		 (u32)&iObj_set_dynamicCurrentControl,	 (u32)&iObj_get_dynamicCurrentControl		  },
		{	cgc_dynamicFontBold,			sizeof(cgc_dynamicFontBold) - 1,			 (u32)&iObj_set_dynamicFontBold,		 (u32)&iObj_get_dynamicFontBold				  },
		{	cgc_dynamicFontItalic,			sizeof(cgc_dynamicFontItalic) - 1,			 (u32)&iObj_set_dynamicFontItalic,		 (u32)&iObj_get_dynamicFontItalic			  },
		{	cgc_dynamicFontName,			sizeof(cgc_dynamicFontName) - 1,			 (u32)&iObj_set_dynamicFontName,		 (u32)&iObj_get_dynamicFontName				  },
		{	cgc_dynamicFontOutline,			sizeof(cgc_dynamicFontOutline) - 1,			 (u32)&iObj_set_dynamicFontOutline,		 (u32)&iObj_get_dynamicFontOutline			  },
		{	cgc_dynamicFontShadow,			sizeof(cgc_dynamicFontShadow) - 1,			 (u32)&iObj_set_dynamicFontShadow,		 (u32)&iObj_get_dynamicFontShadow			  },
		{	cgc_dynamicFontSize,			sizeof(cgc_dynamicFontSize) - 1,			 (u32)&iObj_set_dynamicFontSize,		 (u32)&iObj_get_dynamicFontSize				  },
		{	cgc_dynamicFontStrikeThru,		sizeof(cgc_dynamicFontStrikeThru) - 1,		 (u32)&iObj_set_dynamicFontStrikeThru,	 (u32)&iObj_get_dynamicFontStrikeThru		  },
		{	cgc_dynamicFontUnderline,		sizeof(cgc_dynamicFontUnderline) - 1,		 (u32)&iObj_set_dynamicFontUnderline,	 (u32)&iObj_get_dynamicFontUnderline		  },
		{	cgc_dynamicForeColor,			sizeof(cgc_dynamicForeColor) - 1,			 (u32)&iObj_set_dynamicForeColor,		 (u32)&iObj_get_dynamicForeColor			  },
		{	cgc_dynamicInputMask,			sizeof(cgc_dynamicInputMask) - 1,			 (u32)&iObj_set_dynamicInputMask,		 (u32)&iObj_get_dynamicInputMask			  },
		{	cgc_sparse,						sizeof(cgc_sparse) - 1,						 (u32)&iObj_set_sparse,					 (u32)&iObj_get_sparse						  },
		{	cgc_columnOrder,				sizeof(cgc_columnOrder) - 1,				 (u32)&iObj_set_columnOrder,			 (u32)&iObj_get_columnOrder					  },
		{	cgc_headerClass,				sizeof(cgc_headerClass) - 1,				 (u32)&iObj_set_headerClass,			 (u32)&iObj_get_headerClass					  },
		{	cgc_headerClassLibrary,			sizeof(cgc_headerClassLibrary) - 1,			 (u32)&iObj_set_headerClassLibrary,		 (u32)&iObj_get_headerClassLibrary			  },
		{	cgc_movable,					sizeof(cgc_movable) - 1,					 (u32)&iObj_set_movable,				 (u32)&iObj_get_movable						  },
		{	cgc_alignment,					sizeof(cgc_alignment) - 1,					 (u32)&iObj_set_alignment,				 (u32)&iObj_get_alignment					  },
		{	cgc_application,				sizeof(cgc_application) - 1,				 (u32)&iObj_set_application,			 (u32)&iObj_get_application					  },
		{	cgc_baseClass,					sizeof(cgc_baseClass) - 1,					 (u32)&iObj_set_baseClass,				 (u32)&iObj_get_baseClass					  },
		{	cgc_class,						sizeof(cgc_class) - 1,						 (u32)&iObj_set_class,					 (u32)&iObj_get_class						  },
		{	cgc_classLibrary,				sizeof(cgc_classLibrary) - 1,				 (u32)&iObj_set_classLibrary,			 (u32)&iObj_get_classLibrary				  },
		{	cgc_controls,					sizeof(cgc_controls) - 1,					 (u32)&iObj_set_controls,				 (u32)&iObj_get_controls					  },
		{	cgc_controlCount,				sizeof(cgc_controlCount) - 1,				 (u32)&iObj_set_controlCount,			 (u32)&iObj_get_controlCount				  },
		{	cgc_objects,					sizeof(cgc_objects) - 1,					 (u32)&iObj_set_objects,				 (u32)&iObj_get_objects						  },
		{	cgc_bound,						sizeof(cgc_bound) - 1,						 (u32)&iObj_set_bound,					 (u32)&iObj_get_bound						  },
		{	cgc_foreColor,					sizeof(cgc_foreColor) - 1,					 (u32)&iObj_set_foreColor,				 (u32)&iObj_get_foreColor					  },
		{	cgc_backColor,					sizeof(cgc_backColor) - 1,					 (u32)&iObj_set_backColor,				 (u32)&iObj_get_backColor					  },
		{	cgc_comment,					sizeof(cgc_comment) - 1,					 (u32)&iObj_set_comment,				 (u32)&iObj_get_comment						  },
		{	cgc_controlSource,				sizeof(cgc_controlSource) - 1,				 (u32)&iObj_set_controlSource,			 (u32)&iObj_get_controlSource				  },
		{	cgc_enabled,					sizeof(cgc_enabled) - 1,					 (u32)&iObj_set_enabled,				 (u32)&iObj_get_enabled						  },
		{	cgc_fontBold,					sizeof(cgc_fontBold) - 1,					 (u32)&iObj_set_fontBold,				 (u32)&iObj_get_fontBold					  },
		{	cgc_fontCharSet,				sizeof(cgc_fontCharSet) - 1,				 (u32)&iObj_set_fontCharSet,			 (u32)&iObj_get_fontCharSet					  },
		{	cgc_fontCondense,				sizeof(cgc_fontCondense) - 1,				 (u32)&iObj_set_fontCondense,			 (u32)&iObj_get_fontCondense				  },
		{	cgc_fontExtend,					sizeof(cgc_fontExtend) - 1,					 (u32)&iObj_set_fontExtend,				 (u32)&iObj_get_fontExtend					  },
		{	cgc_fontItalic,					sizeof(cgc_fontItalic) - 1,					 (u32)&iObj_set_fontItalic,				 (u32)&iObj_get_fontItalic					  },
		{	cgc_fontName,					sizeof(cgc_fontName) - 1,					 (u32)&iObj_set_fontName,				 (u32)&iObj_get_fontName					  },
		{	cgc_fontOutline,				sizeof(cgc_fontOutline) - 1,				 (u32)&iObj_set_fontOutline,			 (u32)&iObj_get_fontOutline					  },
		{	cgc_fontShadow,					sizeof(cgc_fontShadow) - 1,					 (u32)&iObj_set_fontShadow,				 (u32)&iObj_get_fontShadow					  },
		{	cgc_fontSize,					sizeof(cgc_fontSize) - 1,					 (u32)&iObj_set_fontSize,				 (u32)&iObj_get_fontSize					  },
		{	cgc_fontStrikeThru,				sizeof(cgc_fontStrikeThru) - 1,				 (u32)&iObj_set_fontStrikeThru,			 (u32)&iObj_get_fontStrikeThru				  },
		{	cgc_fontUnderline,				sizeof(cgc_fontUnderline) - 1,				 (u32)&iObj_set_fontUnderline,			 (u32)&iObj_get_fontUnderline				  },
		{	cgc_format,						sizeof(cgc_format) - 1,						 (u32)&iObj_set_format,					 (u32)&iObj_get_format						  },
		{	cgc_inputMask,					sizeof(cgc_inputMask) - 1,					 (u32)&iObj_set_inputMask,				 (u32)&iObj_get_inputMask					  },
		{	cgc_mouseIcon,					sizeof(cgc_mouseIcon) - 1,					 (u32)&iObj_set_mouseIcon,				 (u32)&iObj_get_mouseIcon					  },
		{	cgc_mousePointer,				sizeof(cgc_mousePointer) - 1,				 (u32)&iObj_set_mousePointer,			 (u32)&iObj_get_mousePointer				  },
		{	cgc_name,						sizeof(cgc_name) - 1,						 (u32)&iObj_set_name,					 (u32)&iObj_get_name						  },
		{	cgc_parent,						sizeof(cgc_parent) - 1,						 (u32)&iObj_set_parent,					 (u32)&iObj_get_parent						  },
		{	cgc_parentClass,				sizeof(cgc_parentClass) - 1,				 (u32)&iObj_set_parentClass,			 (u32)&iObj_get_parentClass					  },
		{	cgc_readOnly,					sizeof(cgc_readOnly) - 1,					 (u32)&iObj_set_readOnly,				 (u32)&iObj_get_readOnly					  },
		{	cgc_selectOnEntry,				sizeof(cgc_selectOnEntry) - 1,				 (u32)&iObj_set_selectOnEntry,			 (u32)&iObj_get_selectOnEntry				  },
		{	cgc_resizable,					sizeof(cgc_resizable) - 1,					 (u32)&iObj_set_resizable,				 (u32)&iObj_get_resizable					  },
		{	cgc_statusBarText,				sizeof(cgc_statusBarText) - 1,				 (u32)&iObj_set_statusBarText,			 (u32)&iObj_get_statusBarText				  },
		{	cgc_tag,						sizeof(cgc_tag) - 1,						 (u32)&iObj_set_tag,					 (u32)&iObj_get_tag							  },
		{	cgc_toolTipText,				sizeof(cgc_toolTipText) - 1,				 (u32)&iObj_set_toolTipText,			 (u32)&iObj_get_toolTipText					  },
		{	cgc_visible,					sizeof(cgc_visible) - 1,					 (u32)&iObj_set_visible,				 (u32)&iObj_get_visible						  },
		{	cgc_width,						sizeof(cgc_width) - 1,						 (u32)&iObj_set_width,					 (u32)&iObj_get_width						  },
		{	NULL,							0,											 0,										 0										 }
	};

	SPropertyMap gcProps_header[] = 
	{
		{	cgc_alignment,					sizeof(cgc_alignment) - 1,					 (u32)&iObj_set_alignment,				 (u32)&iObj_get_alignment					  },
		{	cgc_anchor,						sizeof(cgc_anchor) - 1,						 (u32)&iObj_set_anchor,					 (u32)&iObj_get_anchor						  },
		{	cgc_application,				sizeof(cgc_application) - 1,				 (u32)&iObj_set_application,			 (u32)&iObj_get_application					  },
		{	cgc_baseClass,					sizeof(cgc_baseClass) - 1,					 (u32)&iObj_set_baseClass,				 (u32)&iObj_get_baseClass					  },
		{	cgc_class,						sizeof(cgc_class) - 1,						 (u32)&iObj_set_class,					 (u32)&iObj_get_class						  },
		{	cgc_classLibrary,				sizeof(cgc_classLibrary) - 1,				 (u32)&iObj_set_classLibrary,			 (u32)&iObj_get_classLibrary				  },
		{	cgc_caption,					sizeof(cgc_caption) - 1,					 (u32)&iObj_set_caption,				 (u32)&iObj_get_caption						  },
		{	cgc_foreColor,					sizeof(cgc_foreColor) - 1,					 (u32)&iObj_set_foreColor,				 (u32)&iObj_get_foreColor					  },
		{	cgc_backColor,					sizeof(cgc_backColor) - 1,					 (u32)&iObj_set_backColor,				 (u32)&iObj_get_backColor					  },
		{	cgc_comment,					sizeof(cgc_comment) - 1,					 (u32)&iObj_set_comment,				 (u32)&iObj_get_comment						  },
		{	cgc_fontBold,					sizeof(cgc_fontBold) - 1,					 (u32)&iObj_set_fontBold,				 (u32)&iObj_get_fontBold					  },
		{	cgc_fontCharSet,				sizeof(cgc_fontCharSet) - 1,				 (u32)&iObj_set_fontCharSet,			 (u32)&iObj_get_fontCharSet					  },
		{	cgc_fontCondense,				sizeof(cgc_fontCondense) - 1,				 (u32)&iObj_set_fontCondense,			 (u32)&iObj_get_fontCondense				  },
		{	cgc_fontExtend,					sizeof(cgc_fontExtend) - 1,					 (u32)&iObj_set_fontExtend,				 (u32)&iObj_get_fontExtend					  },
		{	cgc_fontItalic,					sizeof(cgc_fontItalic) - 1,					 (u32)&iObj_set_fontItalic,				 (u32)&iObj_get_fontItalic					  },
		{	cgc_fontName,					sizeof(cgc_fontName) - 1,					 (u32)&iObj_set_fontName,				 (u32)&iObj_get_fontName					  },
		{	cgc_fontOutline,				sizeof(cgc_fontOutline) - 1,				 (u32)&iObj_set_fontOutline,			 (u32)&iObj_get_fontOutline					  },
		{	cgc_fontShadow,					sizeof(cgc_fontShadow) - 1,					 (u32)&iObj_set_fontShadow,				 (u32)&iObj_get_fontShadow					  },
		{	cgc_fontSize,					sizeof(cgc_fontSize) - 1,					 (u32)&iObj_set_fontSize,				 (u32)&iObj_get_fontSize					  },
		{	cgc_fontStrikeThru,				sizeof(cgc_fontStrikeThru) - 1,				 (u32)&iObj_set_fontStrikeThru,			 (u32)&iObj_get_fontStrikeThru				  },
		{	cgc_fontUnderline,				sizeof(cgc_fontUnderline) - 1,				 (u32)&iObj_set_fontUnderline,			 (u32)&iObj_get_fontUnderline				  },
		{	cgc_mouseIcon,					sizeof(cgc_mouseIcon) - 1,					 (u32)&iObj_set_mouseIcon,				 (u32)&iObj_get_mouseIcon					  },
		{	cgc_mousePointer,				sizeof(cgc_mousePointer) - 1,				 (u32)&iObj_set_mousePointer,			 (u32)&iObj_get_mousePointer				  },
		{	cgc_name,						sizeof(cgc_name) - 1,						 (u32)&iObj_set_name,					 (u32)&iObj_get_name						  },
		{	cgc_parent,						sizeof(cgc_parent) - 1,						 (u32)&iObj_set_parent,					 (u32)&iObj_get_parent						  },
		{	cgc_parentClass,				sizeof(cgc_parentClass) - 1,				 (u32)&iObj_set_parentClass,			 (u32)&iObj_get_parentClass					  },
		{	cgc_picture,					sizeof(cgc_picture) - 1,					 (u32)&iObj_set_picture,				 (u32)&iObj_get_picture						  },
		{	cgc_statusBarText,				sizeof(cgc_statusBarText) - 1,				 (u32)&iObj_set_statusBarText,			 (u32)&iObj_get_statusBarText				  },
		{	cgc_tag,						sizeof(cgc_tag) - 1,						 (u32)&iObj_set_tag,					 (u32)&iObj_get_tag							  },
		{	cgc_toolTipText,				sizeof(cgc_toolTipText) - 1,				 (u32)&iObj_set_toolTipText,			 (u32)&iObj_get_toolTipText					  },
		{	cgc_wordWrap,					sizeof(cgc_wordWrap) - 1,					 (u32)&iObj_set_wordWrap,				 (u32)&iObj_get_wordWrap					  },
		{	NULL,							0,											 0,										 0										 }
	};

	SPropertyMap gcProps_olebound[] = 
	{
		{	cgc_autoActivate,				sizeof(cgc_autoActivate) - 1,				 (u32)&iObj_set_autoActivate,			 (u32)&iObj_get_autoActivate				  },
		{	cgc_autoSize,					sizeof(cgc_autoSize) - 1,					 (u32)&iObj_set_autoSize,				 (u32)&iObj_get_autoSize					  },
		{	cgc_autoVerbMenu,				sizeof(cgc_autoVerbMenu) - 1,				 (u32)&iObj_set_autoVerbMenu,			 (u32)&iObj_get_autoVerbMenu				  },
		{	cgc_documentFile,				sizeof(cgc_documentFile) - 1,				 (u32)&iObj_set_documentFile,			 (u32)&iObj_get_documentFile				  },
		{	cgc_hostName,					sizeof(cgc_hostName) - 1,					 (u32)&iObj_set_hostName,				 (u32)&iObj_get_hostName					  },
		{	cgc_object,						sizeof(cgc_object) - 1,						 (u32)&iObj_set_object,					 (u32)&iObj_get_object						  },
		{	cgc_anchor,						sizeof(cgc_anchor) - 1,						 (u32)&iObj_set_anchor,					 (u32)&iObj_get_anchor						  },
		{	cgc_application,				sizeof(cgc_application) - 1,				 (u32)&iObj_set_application,			 (u32)&iObj_get_application					  },
		{	cgc_baseClass,					sizeof(cgc_baseClass) - 1,					 (u32)&iObj_set_baseClass,				 (u32)&iObj_get_baseClass					  },
		{	cgc_class,						sizeof(cgc_class) - 1,						 (u32)&iObj_set_class,					 (u32)&iObj_get_class						  },
		{	cgc_classLibrary,				sizeof(cgc_classLibrary) - 1,				 (u32)&iObj_set_classLibrary,			 (u32)&iObj_get_classLibrary				  },
		{	cgc_comment,					sizeof(cgc_comment) - 1,					 (u32)&iObj_set_comment,				 (u32)&iObj_get_comment						  },
		{	cgc_controlSource,				sizeof(cgc_controlSource) - 1,				 (u32)&iObj_set_controlSource,			 (u32)&iObj_get_controlSource				  },
		{	cgc_dragIcon,					sizeof(cgc_dragIcon) - 1,					 (u32)&iObj_set_dragIcon,				 (u32)&iObj_get_dragIcon					  },
		{	cgc_dragMode,					sizeof(cgc_dragMode) - 1,					 (u32)&iObj_set_dragMode,				 (u32)&iObj_get_dragMode					  },
		{	cgc_enabled,					sizeof(cgc_enabled) - 1,					 (u32)&iObj_set_enabled,				 (u32)&iObj_get_enabled						  },
		{	cgc_height,						sizeof(cgc_height) - 1,						 (u32)&iObj_set_height,					 (u32)&iObj_get_height						  },
		{	cgc_helpContextID,				sizeof(cgc_helpContextID) - 1,				 (u32)&iObj_set_helpContextID,			 (u32)&iObj_get_helpContextID				  },
		{	cgc_left,						sizeof(cgc_left) - 1,						 (u32)&iObj_set_left,					 (u32)&iObj_get_left						  },
		{	cgc_mousePointer,				sizeof(cgc_mousePointer) - 1,				 (u32)&iObj_set_mousePointer,			 (u32)&iObj_get_mousePointer				  },
		{	cgc_name,						sizeof(cgc_name) - 1,						 (u32)&iObj_set_name,					 (u32)&iObj_get_name						  },
		{	cgc_oLEClass,					sizeof(cgc_oLEClass) - 1,					 (u32)&iObj_set_oLEClass,				 (u32)&iObj_get_oLEClass					  },
		{	cgc_oLELCID,					sizeof(cgc_oLELCID) - 1,					 (u32)&iObj_set_oLELCID,				 (u32)&iObj_get_oLELCID						  },
		{	cgc_oLETypeAllowed,				sizeof(cgc_oLETypeAllowed) - 1,				 (u32)&iObj_set_oLETypeAllowed,			 (u32)&iObj_get_oLETypeAllowed				  },
		{	cgc_parentClass,				sizeof(cgc_parentClass) - 1,				 (u32)&iObj_set_parentClass,			 (u32)&iObj_get_parentClass					  },
		{	cgc_sizable,					sizeof(cgc_sizable) - 1,					 (u32)&iObj_set_sizable,				 (u32)&iObj_get_sizable						  },
		{	cgc_stretch,					sizeof(cgc_stretch) - 1,					 (u32)&iObj_set_stretch,				 (u32)&iObj_get_stretch						  },
		{	cgc_statusBarText,				sizeof(cgc_statusBarText) - 1,				 (u32)&iObj_set_statusBarText,			 (u32)&iObj_get_statusBarText				  },
		{	cgc_tabIndex,					sizeof(cgc_tabIndex) - 1,					 (u32)&iObj_set_tabIndex,				 (u32)&iObj_get_tabIndex					  },
		{	cgc_tabStop,					sizeof(cgc_tabStop) - 1,					 (u32)&iObj_set_tabStop,				 (u32)&iObj_get_tabStop						  },
		{	cgc_tag,						sizeof(cgc_tag) - 1,						 (u32)&iObj_set_tag,					 (u32)&iObj_get_tag							  },
		{	cgc_toolTipText,				sizeof(cgc_toolTipText) - 1,				 (u32)&iObj_set_toolTipText,			 (u32)&iObj_get_toolTipText					  },
		{	cgc_top,						sizeof(cgc_top) - 1,						 (u32)&iObj_set_top,					 (u32)&iObj_get_top							  },
		{	cgc_visible,					sizeof(cgc_visible) - 1,					 (u32)&iObj_set_visible,				 (u32)&iObj_get_visible						  },
		{	cgc_whatsThisHelpID,			sizeof(cgc_whatsThisHelpID) - 1,			 (u32)&iObj_set_whatsThisHelpID,		 (u32)&iObj_get_whatsThisHelpID				  },
		{	cgc_width,						sizeof(cgc_width) - 1,						 (u32)&iObj_set_width,					 (u32)&iObj_get_width						  },
		{	cgc_wordWrap,					sizeof(cgc_wordWrap) - 1,					 (u32)&iObj_set_wordWrap,				 (u32)&iObj_get_wordWrap					  },
		{	NULL,							0,											 0,										 0										 }
	};

	SPropertyMap gcProps_olecontain[] = 
	{
		{	cgc_autoActivate,				sizeof(cgc_autoActivate) - 1,				 (u32)&iObj_set_autoActivate,			 (u32)&iObj_get_autoActivate				  },
		{	cgc_autoSize,					sizeof(cgc_autoSize) - 1,					 (u32)&iObj_set_autoSize,				 (u32)&iObj_get_autoSize					  },
		{	cgc_autoVerbMenu,				sizeof(cgc_autoVerbMenu) - 1,				 (u32)&iObj_set_autoVerbMenu,			 (u32)&iObj_get_autoVerbMenu				  },
		{	cgc_documentFile,				sizeof(cgc_documentFile) - 1,				 (u32)&iObj_set_documentFile,			 (u32)&iObj_get_documentFile				  },
		{	cgc_hostName,					sizeof(cgc_hostName) - 1,					 (u32)&iObj_set_hostName,				 (u32)&iObj_get_hostName					  },
		{	cgc_object,						sizeof(cgc_object) - 1,						 (u32)&iObj_set_object,					 (u32)&iObj_get_object						  },
		{	cgc_align,						sizeof(cgc_align) - 1,						 (u32)&iObj_set_align,					 (u32)&iObj_get_align						  },
		{	cgc_anchor,						sizeof(cgc_anchor) - 1,						 (u32)&iObj_set_anchor,					 (u32)&iObj_get_anchor						  },
		{	cgc_application,				sizeof(cgc_application) - 1,				 (u32)&iObj_set_application,			 (u32)&iObj_get_application					  },
		{	cgc_baseClass,					sizeof(cgc_baseClass) - 1,					 (u32)&iObj_set_baseClass,				 (u32)&iObj_get_baseClass					  },
		{	cgc_class,						sizeof(cgc_class) - 1,						 (u32)&iObj_set_class,					 (u32)&iObj_get_class						  },
		{	cgc_classLibrary,				sizeof(cgc_classLibrary) - 1,				 (u32)&iObj_set_classLibrary,			 (u32)&iObj_get_classLibrary				  },
		{	cgc_cancel,						sizeof(cgc_cancel) - 1,						 (u32)&iObj_set_cancel,					 (u32)&iObj_get_cancel						  },
		{	cgc_default,					sizeof(cgc_default) - 1,					 (u32)&iObj_set_default,				 (u32)&iObj_get_default						  },
		{	cgc_comment,					sizeof(cgc_comment) - 1,					 (u32)&iObj_set_comment,				 (u32)&iObj_get_comment						  },
		{	cgc_controlSource,				sizeof(cgc_controlSource) - 1,				 (u32)&iObj_set_controlSource,			 (u32)&iObj_get_controlSource				  },
		{	cgc_dragIcon,					sizeof(cgc_dragIcon) - 1,					 (u32)&iObj_set_dragIcon,				 (u32)&iObj_get_dragIcon					  },
		{	cgc_dragMode,					sizeof(cgc_dragMode) - 1,					 (u32)&iObj_set_dragMode,				 (u32)&iObj_get_dragMode					  },
		{	cgc_enabled,					sizeof(cgc_enabled) - 1,					 (u32)&iObj_set_enabled,				 (u32)&iObj_get_enabled						  },
		{	cgc_height,						sizeof(cgc_height) - 1,						 (u32)&iObj_set_height,					 (u32)&iObj_get_height						  },
		{	cgc_helpContextID,				sizeof(cgc_helpContextID) - 1,				 (u32)&iObj_set_helpContextID,			 (u32)&iObj_get_helpContextID				  },
		{	cgc_left,						sizeof(cgc_left) - 1,						 (u32)&iObj_set_left,					 (u32)&iObj_get_left						  },
		{	cgc_mouseIcon,					sizeof(cgc_mouseIcon) - 1,					 (u32)&iObj_set_mouseIcon,				 (u32)&iObj_get_mouseIcon					  },
		{	cgc_mousePointer,				sizeof(cgc_mousePointer) - 1,				 (u32)&iObj_set_mousePointer,			 (u32)&iObj_get_mousePointer				  },
		{	cgc_name,						sizeof(cgc_name) - 1,						 (u32)&iObj_set_name,					 (u32)&iObj_get_name						  },
		{	cgc_oLEClass,					sizeof(cgc_oLEClass) - 1,					 (u32)&iObj_set_oLEClass,				 (u32)&iObj_get_oLEClass					  },
		{	cgc_oLELCID,					sizeof(cgc_oLELCID) - 1,					 (u32)&iObj_set_oLELCID,				 (u32)&iObj_get_oLELCID						  },
		{	cgc_oLETypeAllowed,				sizeof(cgc_oLETypeAllowed) - 1,				 (u32)&iObj_set_oLETypeAllowed,			 (u32)&iObj_get_oLETypeAllowed				  },
		{	cgc_parent,						sizeof(cgc_parent) - 1,						 (u32)&iObj_set_parent,					 (u32)&iObj_get_parent						  },
		{	cgc_parentClass,				sizeof(cgc_parentClass) - 1,				 (u32)&iObj_set_parentClass,			 (u32)&iObj_get_parentClass					  },
		{	cgc_sizable,					sizeof(cgc_sizable) - 1,					 (u32)&iObj_set_sizable,				 (u32)&iObj_get_sizable						  },
		{	cgc_stretch,					sizeof(cgc_stretch) - 1,					 (u32)&iObj_set_stretch,				 (u32)&iObj_get_stretch						  },
		{	cgc_tabIndex,					sizeof(cgc_tabIndex) - 1,					 (u32)&iObj_set_tabIndex,				 (u32)&iObj_get_tabIndex					  },
		{	cgc_tabStop,					sizeof(cgc_tabStop) - 1,					 (u32)&iObj_set_tabStop,				 (u32)&iObj_get_tabStop						  },
		{	cgc_tag,						sizeof(cgc_tag) - 1,						 (u32)&iObj_set_tag,					 (u32)&iObj_get_tag							  },
		{	cgc_top,						sizeof(cgc_top) - 1,						 (u32)&iObj_set_top,					 (u32)&iObj_get_top							  },
		{	cgc_visible,					sizeof(cgc_visible) - 1,					 (u32)&iObj_set_visible,				 (u32)&iObj_get_visible						  },
		{	cgc_whatsThisHelpID,			sizeof(cgc_whatsThisHelpID) - 1,			 (u32)&iObj_set_whatsThisHelpID,		 (u32)&iObj_get_whatsThisHelpID				  },
		{	cgc_width,						sizeof(cgc_width) - 1,						 (u32)&iObj_set_width,					 (u32)&iObj_get_width						  },
		{	NULL,							0,											 0,										 0										 }
	};

	SPropertyMap gcProps_spinner[] = 
	{
		{	cgc_spinnerHighValue,			sizeof(cgc_spinnerHighValue) - 1,			 (u32)&iObj_set_spinnerHighValue,		 (u32)&iObj_get_spinnerHighValue			  },
		{	cgc_spinnerLowValue,			sizeof(cgc_spinnerLowValue) - 1,			 (u32)&iObj_set_spinnerLowValue,		 (u32)&iObj_get_spinnerLowValue				  },
		{	cgc_keyboardHighValue,			sizeof(cgc_keyboardHighValue) - 1,			 (u32)&iObj_set_keyboardHighValue,		 (u32)&iObj_get_keyboardHighValue			  },
		{	cgc_keyboardLowValue,			sizeof(cgc_keyboardLowValue) - 1,			 (u32)&iObj_set_keyboardLowValue,		 (u32)&iObj_get_keyboardLowValue			  },
		{	cgc_increment,					sizeof(cgc_increment) - 1,					 (u32)&iObj_set_increment,				 (u32)&iObj_get_increment					  },
		{	cgc_alignment,					sizeof(cgc_alignment) - 1,					 (u32)&iObj_set_alignment,				 (u32)&iObj_get_alignment					  },
		{	cgc_anchor,						sizeof(cgc_anchor) - 1,						 (u32)&iObj_set_anchor,					 (u32)&iObj_get_anchor						  },
		{	cgc_application,				sizeof(cgc_application) - 1,				 (u32)&iObj_set_application,			 (u32)&iObj_get_application					  },
		{	cgc_baseClass,					sizeof(cgc_baseClass) - 1,					 (u32)&iObj_set_baseClass,				 (u32)&iObj_get_baseClass					  },
		{	cgc_class,						sizeof(cgc_class) - 1,						 (u32)&iObj_set_class,					 (u32)&iObj_get_class						  },
		{	cgc_classLibrary,				sizeof(cgc_classLibrary) - 1,				 (u32)&iObj_set_classLibrary,			 (u32)&iObj_get_classLibrary				  },
		{	cgc_borderColor,				sizeof(cgc_borderColor) - 1,				 (u32)&iObj_set_borderColor,			 (u32)&iObj_get_borderColor					  },
		{	cgc_borderStyle,				sizeof(cgc_borderStyle) - 1,				 (u32)&iObj_set_borderStyle,			 (u32)&iObj_get_borderStyle					  },
		{	cgc_colorScheme,				sizeof(cgc_colorScheme) - 1,				 (u32)&iObj_set_colorScheme,			 (u32)&iObj_get_colorScheme					  },
		{	cgc_colorSource,				sizeof(cgc_colorSource) - 1,				 (u32)&iObj_set_colorSource,			 (u32)&iObj_get_colorSource					  },
		{	cgc_foreColor,					sizeof(cgc_foreColor) - 1,					 (u32)&iObj_set_foreColor,				 (u32)&iObj_get_foreColor					  },
		{	cgc_backColor,					sizeof(cgc_backColor) - 1,					 (u32)&iObj_set_backColor,				 (u32)&iObj_get_backColor					  },
		{	cgc_disabledBackColor,			sizeof(cgc_disabledBackColor) - 1,			 (u32)&iObj_set_disabledBackColor,		 (u32)&iObj_get_disabledBackColor			  },
		{	cgc_disabledForeColor,			sizeof(cgc_disabledForeColor) - 1,			 (u32)&iObj_set_disabledForeColor,		 (u32)&iObj_get_disabledForeColor			  },
		{	cgc_comment,					sizeof(cgc_comment) - 1,					 (u32)&iObj_set_comment,				 (u32)&iObj_get_comment						  },
		{	cgc_controlSource,				sizeof(cgc_controlSource) - 1,				 (u32)&iObj_set_controlSource,			 (u32)&iObj_get_controlSource				  },
		{	cgc_dragIcon,					sizeof(cgc_dragIcon) - 1,					 (u32)&iObj_set_dragIcon,				 (u32)&iObj_get_dragIcon					  },
		{	cgc_dragMode,					sizeof(cgc_dragMode) - 1,					 (u32)&iObj_set_dragMode,				 (u32)&iObj_get_dragMode					  },
		{	cgc_enabled,					sizeof(cgc_enabled) - 1,					 (u32)&iObj_set_enabled,				 (u32)&iObj_get_enabled						  },
		{	cgc_fontBold,					sizeof(cgc_fontBold) - 1,					 (u32)&iObj_set_fontBold,				 (u32)&iObj_get_fontBold					  },
		{	cgc_fontCharSet,				sizeof(cgc_fontCharSet) - 1,				 (u32)&iObj_set_fontCharSet,			 (u32)&iObj_get_fontCharSet					  },
		{	cgc_fontCondense,				sizeof(cgc_fontCondense) - 1,				 (u32)&iObj_set_fontCondense,			 (u32)&iObj_get_fontCondense				  },
		{	cgc_fontExtend,					sizeof(cgc_fontExtend) - 1,					 (u32)&iObj_set_fontExtend,				 (u32)&iObj_get_fontExtend					  },
		{	cgc_fontItalic,					sizeof(cgc_fontItalic) - 1,					 (u32)&iObj_set_fontItalic,				 (u32)&iObj_get_fontItalic					  },
		{	cgc_fontName,					sizeof(cgc_fontName) - 1,					 (u32)&iObj_set_fontName,				 (u32)&iObj_get_fontName					  },
		{	cgc_fontOutline,				sizeof(cgc_fontOutline) - 1,				 (u32)&iObj_set_fontOutline,			 (u32)&iObj_get_fontOutline					  },
		{	cgc_fontShadow,					sizeof(cgc_fontShadow) - 1,					 (u32)&iObj_set_fontShadow,				 (u32)&iObj_get_fontShadow					  },
		{	cgc_fontSize,					sizeof(cgc_fontSize) - 1,					 (u32)&iObj_set_fontSize,				 (u32)&iObj_get_fontSize					  },
		{	cgc_fontStrikeThru,				sizeof(cgc_fontStrikeThru) - 1,				 (u32)&iObj_set_fontStrikeThru,			 (u32)&iObj_get_fontStrikeThru				  },
		{	cgc_fontUnderline,				sizeof(cgc_fontUnderline) - 1,				 (u32)&iObj_set_fontUnderline,			 (u32)&iObj_get_fontUnderline				  },
		{	cgc_format,						sizeof(cgc_format) - 1,						 (u32)&iObj_set_format,					 (u32)&iObj_get_format						  },
		{	cgc_height,						sizeof(cgc_height) - 1,						 (u32)&iObj_set_height,					 (u32)&iObj_get_height						  },
		{	cgc_helpContextID,				sizeof(cgc_helpContextID) - 1,				 (u32)&iObj_set_helpContextID,			 (u32)&iObj_get_helpContextID				  },
		{	cgc_hideSelection,				sizeof(cgc_hideSelection) - 1,				 (u32)&iObj_set_hideSelection,			 (u32)&iObj_get_hideSelection				  },
		{	cgc_inputMask,					sizeof(cgc_inputMask) - 1,					 (u32)&iObj_set_inputMask,				 (u32)&iObj_get_inputMask					  },
		{	cgc_left,						sizeof(cgc_left) - 1,						 (u32)&iObj_set_left,					 (u32)&iObj_get_left						  },
		{	cgc_margin,						sizeof(cgc_margin) - 1,						 (u32)&iObj_set_margin,					 (u32)&iObj_get_margin						  },
		{	cgc_mouseIcon,					sizeof(cgc_mouseIcon) - 1,					 (u32)&iObj_set_mouseIcon,				 (u32)&iObj_get_mouseIcon					  },
		{	cgc_mousePointer,				sizeof(cgc_mousePointer) - 1,				 (u32)&iObj_set_mousePointer,			 (u32)&iObj_get_mousePointer				  },
		{	cgc_name,						sizeof(cgc_name) - 1,						 (u32)&iObj_set_name,					 (u32)&iObj_get_name						  },
		{	cgc_nullDisplay,				sizeof(cgc_nullDisplay) - 1,				 (u32)&iObj_set_nullDisplay,			 (u32)&iObj_get_nullDisplay					  },
		{	cgc_oLEDragMode,				sizeof(cgc_oLEDragMode) - 1,				 (u32)&iObj_set_oLEDragMode,			 (u32)&iObj_get_oLEDragMode					  },
		{	cgc_oLEDragPicture,				sizeof(cgc_oLEDragPicture) - 1,				 (u32)&iObj_set_oLEDragPicture,			 (u32)&iObj_get_oLEDragPicture				  },
		{	cgc_oLEDropEffects,				sizeof(cgc_oLEDropEffects) - 1,				 (u32)&iObj_set_oLEDropEffects,			 (u32)&iObj_get_oLEDropEffects				  },
		{	cgc_oLEDropHasData,				sizeof(cgc_oLEDropHasData) - 1,				 (u32)&iObj_set_oLEDropHasData,			 (u32)&iObj_get_oLEDropHasData				  },
		{	cgc_oLEDropMode,				sizeof(cgc_oLEDropMode) - 1,				 (u32)&iObj_set_oLEDropMode,			 (u32)&iObj_get_oLEDropMode					  },
		{	cgc_oLEDropTextInsertion,		sizeof(cgc_oLEDropTextInsertion) - 1,		 (u32)&iObj_set_oLEDropTextInsertion,	 (u32)&iObj_get_oLEDropTextInsertion		  },
		{	cgc_parent,						sizeof(cgc_parent) - 1,						 (u32)&iObj_set_parent,					 (u32)&iObj_get_parent						  },
		{	cgc_parentClass,				sizeof(cgc_parentClass) - 1,				 (u32)&iObj_set_parentClass,			 (u32)&iObj_get_parentClass					  },
		{	cgc_readOnly,					sizeof(cgc_readOnly) - 1,					 (u32)&iObj_set_readOnly,				 (u32)&iObj_get_readOnly					  },
		{	cgc_rightToLeft,				sizeof(cgc_rightToLeft) - 1,				 (u32)&iObj_set_rightToLeft,			 (u32)&iObj_get_rightToLeft					  },
		{	cgc_selectedBackColor,			sizeof(cgc_selectedBackColor) - 1,			 (u32)&iObj_set_selectedBackColor,		 (u32)&iObj_get_selectedBackColor			  },
		{	cgc_selectedForeColor,			sizeof(cgc_selectedForeColor) - 1,			 (u32)&iObj_set_selectedForeColor,		 (u32)&iObj_get_selectedForeColor			  },
		{	cgc_selectOnEntry,				sizeof(cgc_selectOnEntry) - 1,				 (u32)&iObj_set_selectOnEntry,			 (u32)&iObj_get_selectOnEntry				  },
		{	cgc_selLength,					sizeof(cgc_selLength) - 1,					 (u32)&iObj_set_selLength,				 (u32)&iObj_get_selLength					  },
		{	cgc_selStart,					sizeof(cgc_selStart) - 1,					 (u32)&iObj_set_selStart,				 (u32)&iObj_get_selStart					  },
		{	cgc_selText,					sizeof(cgc_selText) - 1,					 (u32)&iObj_set_selText,				 (u32)&iObj_get_selText						  },
		{	cgc_specialEffect,				sizeof(cgc_specialEffect) - 1,				 (u32)&iObj_set_specialEffect,			 (u32)&iObj_get_specialEffect				  },
		{	cgc_statusBarText,				sizeof(cgc_statusBarText) - 1,				 (u32)&iObj_set_statusBarText,			 (u32)&iObj_get_statusBarText				  },
		{	cgc_tabIndex,					sizeof(cgc_tabIndex) - 1,					 (u32)&iObj_set_tabIndex,				 (u32)&iObj_get_tabIndex					  },
		{	cgc_tabStop,					sizeof(cgc_tabStop) - 1,					 (u32)&iObj_set_tabStop,				 (u32)&iObj_get_tabStop						  },
		{	cgc_tag,						sizeof(cgc_tag) - 1,						 (u32)&iObj_set_tag,					 (u32)&iObj_get_tag							  },
		{	cgc_terminateRead,				sizeof(cgc_terminateRead) - 1,				 (u32)&iObj_set_terminateRead,			 (u32)&iObj_get_terminateRead				  },
		{	cgc_text,						sizeof(cgc_text) - 1,						 (u32)&iObj_set_text,					 (u32)&iObj_get_text						  },
		{	cgc_themes,						sizeof(cgc_themes) - 1,						 (u32)&iObj_set_themes,					 (u32)&iObj_get_themes						  },
		{	cgc_toolTipText,				sizeof(cgc_toolTipText) - 1,				 (u32)&iObj_set_toolTipText,			 (u32)&iObj_get_toolTipText					  },
		{	cgc_top,						sizeof(cgc_top) - 1,						 (u32)&iObj_set_top,					 (u32)&iObj_get_top							  },
		{	cgc_value,						sizeof(cgc_value) - 1,						 (u32)&iObj_set_value,					 (u32)&iObj_get_value						  },
		{	cgc_visible,					sizeof(cgc_visible) - 1,					 (u32)&iObj_set_visible,				 (u32)&iObj_get_visible						  },
		{	cgc_whatsThisHelpID,			sizeof(cgc_whatsThisHelpID) - 1,			 (u32)&iObj_set_whatsThisHelpID,		 (u32)&iObj_get_whatsThisHelpID				  },
		{	cgc_width,						sizeof(cgc_width) - 1,						 (u32)&iObj_set_width,					 (u32)&iObj_get_width						  },
		{	NULL,							0,											 0,										 0										 }
	};

	SPropertyMap gcProps_timer[] = 
	{
		{	cgc_interval,					sizeof(cgc_interval) - 1,					 (u32)&iObj_set_interval,				 (u32)&iObj_get_interval					  },
		{	cgc_application,				sizeof(cgc_application) - 1,				 (u32)&iObj_set_application,			 (u32)&iObj_get_application					  },
		{	cgc_baseClass,					sizeof(cgc_baseClass) - 1,					 (u32)&iObj_set_baseClass,				 (u32)&iObj_get_baseClass					  },
		{	cgc_class,						sizeof(cgc_class) - 1,						 (u32)&iObj_set_class,					 (u32)&iObj_get_class						  },
		{	cgc_classLibrary,				sizeof(cgc_classLibrary) - 1,				 (u32)&iObj_set_classLibrary,			 (u32)&iObj_get_classLibrary				  },
		{	cgc_comment,					sizeof(cgc_comment) - 1,					 (u32)&iObj_set_comment,				 (u32)&iObj_get_comment						  },
		{	cgc_enabled,					sizeof(cgc_enabled) - 1,					 (u32)&iObj_set_enabled,				 (u32)&iObj_get_enabled						  },
		{	cgc_height,						sizeof(cgc_height) - 1,						 (u32)&iObj_set_height,					 (u32)&iObj_get_height						  },
		{	cgc_left,						sizeof(cgc_left) - 1,						 (u32)&iObj_set_left,					 (u32)&iObj_get_left						  },
		{	cgc_name,						sizeof(cgc_name) - 1,						 (u32)&iObj_set_name,					 (u32)&iObj_get_name						  },
		{	cgc_parent,						sizeof(cgc_parent) - 1,						 (u32)&iObj_set_parent,					 (u32)&iObj_get_parent						  },
		{	cgc_parentClass,				sizeof(cgc_parentClass) - 1,				 (u32)&iObj_set_parentClass,			 (u32)&iObj_get_parentClass					  },
		{	cgc_tag,						sizeof(cgc_tag) - 1,						 (u32)&iObj_set_tag,					 (u32)&iObj_get_tag							  },
		{	cgc_top,						sizeof(cgc_top) - 1,						 (u32)&iObj_set_top,					 (u32)&iObj_get_top							  },
		{	cgc_width,						sizeof(cgc_width) - 1,						 (u32)&iObj_set_width,					 (u32)&iObj_get_width						  },
		{	NULL,							0,											 0,										 0										 }
	};

	SPropertyMap gcProps_hyperlink[] = 
	{
		{	cgc_application,				sizeof(cgc_application) - 1,				 (u32)&iObj_set_application,			 (u32)&iObj_get_application					  },
		{	cgc_baseClass,					sizeof(cgc_baseClass) - 1,					 (u32)&iObj_set_baseClass,				 (u32)&iObj_get_baseClass					  },
		{	cgc_class,						sizeof(cgc_class) - 1,						 (u32)&iObj_set_class,					 (u32)&iObj_get_class						  },
		{	cgc_classLibrary,				sizeof(cgc_classLibrary) - 1,				 (u32)&iObj_set_classLibrary,			 (u32)&iObj_get_classLibrary				  },
		{	cgc_comment,					sizeof(cgc_comment) - 1,					 (u32)&iObj_set_comment,				 (u32)&iObj_get_comment						  },
		{	cgc_name,						sizeof(cgc_name) - 1,						 (u32)&iObj_set_name,					 (u32)&iObj_get_name						  },
		{	cgc_parent,						sizeof(cgc_parent) - 1,						 (u32)&iObj_set_parent,					 (u32)&iObj_get_parent						  },
		{	cgc_parentClass,				sizeof(cgc_parentClass) - 1,				 (u32)&iObj_set_parentClass,			 (u32)&iObj_get_parentClass					  },
		{	cgc_tag,						sizeof(cgc_tag) - 1,						 (u32)&iObj_set_tag,					 (u32)&iObj_get_tag							  },
		{	NULL,							0,											 0,										 0										 }
	};

	SPropertyMap gcProps_collection[] = 
	{
		{	cgc_keySort,					sizeof(cgc_keySort) - 1,					 (u32)&iObj_set_keySort,				 (u32)&iObj_get_keySort						  },
		{	cgc_baseClass,					sizeof(cgc_baseClass) - 1,					 (u32)&iObj_set_baseClass,				 (u32)&iObj_get_baseClass					  },
		{	cgc_class,						sizeof(cgc_class) - 1,						 (u32)&iObj_set_class,					 (u32)&iObj_get_class						  },
		{	cgc_classLibrary,				sizeof(cgc_classLibrary) - 1,				 (u32)&iObj_set_classLibrary,			 (u32)&iObj_get_classLibrary				  },
		{	cgc_count,						sizeof(cgc_count) - 1,						 (u32)&iObj_set_count,					 (u32)&iObj_get_count						  },
		{	cgc_comment,					sizeof(cgc_comment) - 1,					 (u32)&iObj_set_comment,				 (u32)&iObj_get_comment						  },
		{	cgc_name,						sizeof(cgc_name) - 1,						 (u32)&iObj_set_name,					 (u32)&iObj_get_name						  },
		{	cgc_parent,						sizeof(cgc_parent) - 1,						 (u32)&iObj_set_parent,					 (u32)&iObj_get_parent						  },
		{	cgc_parentClass,				sizeof(cgc_parentClass) - 1,				 (u32)&iObj_set_parentClass,			 (u32)&iObj_get_parentClass					  },
		{	cgc_tag,						sizeof(cgc_tag) - 1,						 (u32)&iObj_set_tag,					 (u32)&iObj_get_tag							  },
		{	NULL,							0,											 0,										 0										 }
	};

	SPropertyMap gcProps_page[] = 
	{
		{	cgc_activeControl,				sizeof(cgc_activeControl) - 1,				 (u32)&iObj_set_activeControl,			 (u32)&iObj_get_activeControl				  },
		{	cgc_pageOrder,					sizeof(cgc_pageOrder) - 1,					 (u32)&iObj_set_pageOrder,				 (u32)&iObj_get_pageOrder					  },
		{	cgc_application,				sizeof(cgc_application) - 1,				 (u32)&iObj_set_application,			 (u32)&iObj_get_application					  },
		{	cgc_backStyle,					sizeof(cgc_backStyle) - 1,					 (u32)&iObj_set_backStyle,				 (u32)&iObj_get_backStyle					  },
		{	cgc_baseClass,					sizeof(cgc_baseClass) - 1,					 (u32)&iObj_set_baseClass,				 (u32)&iObj_get_baseClass					  },
		{	cgc_class,						sizeof(cgc_class) - 1,						 (u32)&iObj_set_class,					 (u32)&iObj_get_class						  },
		{	cgc_classLibrary,				sizeof(cgc_classLibrary) - 1,				 (u32)&iObj_set_classLibrary,			 (u32)&iObj_get_classLibrary				  },
		{	cgc_controls,					sizeof(cgc_controls) - 1,					 (u32)&iObj_set_controls,				 (u32)&iObj_get_controls					  },
		{	cgc_controlCount,				sizeof(cgc_controlCount) - 1,				 (u32)&iObj_set_controlCount,			 (u32)&iObj_get_controlCount				  },
		{	cgc_objects,					sizeof(cgc_objects) - 1,					 (u32)&iObj_set_objects,				 (u32)&iObj_get_objects						  },
		{	cgc_caption,					sizeof(cgc_caption) - 1,					 (u32)&iObj_set_caption,				 (u32)&iObj_get_caption						  },
		{	cgc_colorSource,				sizeof(cgc_colorSource) - 1,				 (u32)&iObj_set_colorSource,			 (u32)&iObj_get_colorSource					  },
		{	cgc_foreColor,					sizeof(cgc_foreColor) - 1,					 (u32)&iObj_set_foreColor,				 (u32)&iObj_get_foreColor					  },
		{	cgc_backColor,					sizeof(cgc_backColor) - 1,					 (u32)&iObj_set_backColor,				 (u32)&iObj_get_backColor					  },
		{	cgc_comment,					sizeof(cgc_comment) - 1,					 (u32)&iObj_set_comment,				 (u32)&iObj_get_comment						  },
		{	cgc_dragIcon,					sizeof(cgc_dragIcon) - 1,					 (u32)&iObj_set_dragIcon,				 (u32)&iObj_get_dragIcon					  },
		{	cgc_dragMode,					sizeof(cgc_dragMode) - 1,					 (u32)&iObj_set_dragMode,				 (u32)&iObj_get_dragMode					  },
		{	cgc_enabled,					sizeof(cgc_enabled) - 1,					 (u32)&iObj_set_enabled,				 (u32)&iObj_get_enabled						  },
		{	cgc_fontBold,					sizeof(cgc_fontBold) - 1,					 (u32)&iObj_set_fontBold,				 (u32)&iObj_get_fontBold					  },
		{	cgc_fontCharSet,				sizeof(cgc_fontCharSet) - 1,				 (u32)&iObj_set_fontCharSet,			 (u32)&iObj_get_fontCharSet					  },
		{	cgc_fontCondense,				sizeof(cgc_fontCondense) - 1,				 (u32)&iObj_set_fontCondense,			 (u32)&iObj_get_fontCondense				  },
		{	cgc_fontExtend,					sizeof(cgc_fontExtend) - 1,					 (u32)&iObj_set_fontExtend,				 (u32)&iObj_get_fontExtend					  },
		{	cgc_fontItalic,					sizeof(cgc_fontItalic) - 1,					 (u32)&iObj_set_fontItalic,				 (u32)&iObj_get_fontItalic					  },
		{	cgc_fontName,					sizeof(cgc_fontName) - 1,					 (u32)&iObj_set_fontName,				 (u32)&iObj_get_fontName					  },
		{	cgc_fontOutline,				sizeof(cgc_fontOutline) - 1,				 (u32)&iObj_set_fontOutline,			 (u32)&iObj_get_fontOutline					  },
		{	cgc_fontShadow,					sizeof(cgc_fontShadow) - 1,					 (u32)&iObj_set_fontShadow,				 (u32)&iObj_get_fontShadow					  },
		{	cgc_fontSize,					sizeof(cgc_fontSize) - 1,					 (u32)&iObj_set_fontSize,				 (u32)&iObj_get_fontSize					  },
		{	cgc_fontStrikeThru,				sizeof(cgc_fontStrikeThru) - 1,				 (u32)&iObj_set_fontStrikeThru,			 (u32)&iObj_get_fontStrikeThru				  },
		{	cgc_fontUnderline,				sizeof(cgc_fontUnderline) - 1,				 (u32)&iObj_set_fontUnderline,			 (u32)&iObj_get_fontUnderline				  },
		{	cgc_helpContextID,				sizeof(cgc_helpContextID) - 1,				 (u32)&iObj_set_helpContextID,			 (u32)&iObj_get_helpContextID				  },
		{	cgc_mouseIcon,					sizeof(cgc_mouseIcon) - 1,					 (u32)&iObj_set_mouseIcon,				 (u32)&iObj_get_mouseIcon					  },
		{	cgc_mousePointer,				sizeof(cgc_mousePointer) - 1,				 (u32)&iObj_set_mousePointer,			 (u32)&iObj_get_mousePointer				  },
		{	cgc_name,						sizeof(cgc_name) - 1,						 (u32)&iObj_set_name,					 (u32)&iObj_get_name						  },
		{	cgc_oLEDragMode,				sizeof(cgc_oLEDragMode) - 1,				 (u32)&iObj_set_oLEDragMode,			 (u32)&iObj_get_oLEDragMode					  },
		{	cgc_oLEDragPicture,				sizeof(cgc_oLEDragPicture) - 1,				 (u32)&iObj_set_oLEDragPicture,			 (u32)&iObj_get_oLEDragPicture				  },
		{	cgc_oLEDropEffects,				sizeof(cgc_oLEDropEffects) - 1,				 (u32)&iObj_set_oLEDropEffects,			 (u32)&iObj_get_oLEDropEffects				  },
		{	cgc_oLEDropHasData,				sizeof(cgc_oLEDropHasData) - 1,				 (u32)&iObj_set_oLEDropHasData,			 (u32)&iObj_get_oLEDropHasData				  },
		{	cgc_oLEDropMode,				sizeof(cgc_oLEDropMode) - 1,				 (u32)&iObj_set_oLEDropMode,			 (u32)&iObj_get_oLEDropMode					  },
		{	cgc_parent,						sizeof(cgc_parent) - 1,						 (u32)&iObj_set_parent,					 (u32)&iObj_get_parent						  },
		{	cgc_parentClass,				sizeof(cgc_parentClass) - 1,				 (u32)&iObj_set_parentClass,			 (u32)&iObj_get_parentClass					  },
		{	cgc_picture,					sizeof(cgc_picture) - 1,					 (u32)&iObj_set_picture,				 (u32)&iObj_get_picture						  },
		{	cgc_tag,						sizeof(cgc_tag) - 1,						 (u32)&iObj_set_tag,					 (u32)&iObj_get_tag							  },
		{	cgc_toolTipText,				sizeof(cgc_toolTipText) - 1,				 (u32)&iObj_set_toolTipText,			 (u32)&iObj_get_toolTipText					  },
		{	cgc_whatsThisHelpID,			sizeof(cgc_whatsThisHelpID) - 1,			 (u32)&iObj_set_whatsThisHelpID,		 (u32)&iObj_get_whatsThisHelpID				  },
		{	NULL,							0,											 0,										 0										 }
	};

	SPropertyMap gcProps_pageframe[] = 
	{
		{	cgc_activePage,					sizeof(cgc_activePage) - 1,					 (u32)&iObj_set_activePage,				 (u32)&iObj_get_activePage					  },
		{	cgc_tabOrientation,				sizeof(cgc_tabOrientation) - 1,				 (u32)&iObj_set_tabOrientation,			 (u32)&iObj_get_tabOrientation				  },
		{	cgc_tabs,						sizeof(cgc_tabs) - 1,						 (u32)&iObj_set_tabs,					 (u32)&iObj_get_tabs						  },
		{	cgc_pageHeight,					sizeof(cgc_pageHeight) - 1,					 (u32)&iObj_set_pageHeight,				 (u32)&iObj_get_pageHeight					  },
		{	cgc_pageWidth,					sizeof(cgc_pageWidth) - 1,					 (u32)&iObj_set_pageWidth,				 (u32)&iObj_get_pageWidth					  },
		{	cgc_anchor,						sizeof(cgc_anchor) - 1,						 (u32)&iObj_set_anchor,					 (u32)&iObj_get_anchor						  },
		{	cgc_application,				sizeof(cgc_application) - 1,				 (u32)&iObj_set_application,			 (u32)&iObj_get_application					  },
		{	cgc_baseClass,					sizeof(cgc_baseClass) - 1,					 (u32)&iObj_set_baseClass,				 (u32)&iObj_get_baseClass					  },
		{	cgc_class,						sizeof(cgc_class) - 1,						 (u32)&iObj_set_class,					 (u32)&iObj_get_class						  },
		{	cgc_classLibrary,				sizeof(cgc_classLibrary) - 1,				 (u32)&iObj_set_classLibrary,			 (u32)&iObj_get_classLibrary				  },
		{	cgc_pages,						sizeof(cgc_pages) - 1,						 (u32)&iObj_set_pages,					 (u32)&iObj_get_pages						  },
		{	cgc_pageCount,					sizeof(cgc_pageCount) - 1,					 (u32)&iObj_set_pageCount,				 (u32)&iObj_get_pageCount					  },
		{	cgc_objects,					sizeof(cgc_objects) - 1,					 (u32)&iObj_set_objects,				 (u32)&iObj_get_objects						  },
		{	cgc_borderColor,				sizeof(cgc_borderColor) - 1,				 (u32)&iObj_set_borderColor,			 (u32)&iObj_get_borderColor					  },
		{	cgc_borderWidth,				sizeof(cgc_borderWidth) - 1,				 (u32)&iObj_set_borderWidth,			 (u32)&iObj_get_borderWidth					  },
		{	cgc_colorSource,				sizeof(cgc_colorSource) - 1,				 (u32)&iObj_set_colorSource,			 (u32)&iObj_get_colorSource					  },
		{	cgc_comment,					sizeof(cgc_comment) - 1,					 (u32)&iObj_set_comment,				 (u32)&iObj_get_comment						  },
		{	cgc_dragIcon,					sizeof(cgc_dragIcon) - 1,					 (u32)&iObj_set_dragIcon,				 (u32)&iObj_get_dragIcon					  },
		{	cgc_dragMode,					sizeof(cgc_dragMode) - 1,					 (u32)&iObj_set_dragMode,				 (u32)&iObj_get_dragMode					  },
		{	cgc_enabled,					sizeof(cgc_enabled) - 1,					 (u32)&iObj_set_enabled,				 (u32)&iObj_get_enabled						  },
		{	cgc_height,						sizeof(cgc_height) - 1,						 (u32)&iObj_set_height,					 (u32)&iObj_get_height						  },
		{	cgc_helpContextID,				sizeof(cgc_helpContextID) - 1,				 (u32)&iObj_set_helpContextID,			 (u32)&iObj_get_helpContextID				  },
		{	cgc_left,						sizeof(cgc_left) - 1,						 (u32)&iObj_set_left,					 (u32)&iObj_get_left						  },
		{	cgc_memberClass,				sizeof(cgc_memberClass) - 1,				 (u32)&iObj_set_memberClass,			 (u32)&iObj_get_memberClass					  },
		{	cgc_memberClassLibrary,			sizeof(cgc_memberClassLibrary) - 1,			 (u32)&iObj_set_memberClassLibrary,		 (u32)&iObj_get_memberClassLibrary			  },
		{	cgc_mouseIcon,					sizeof(cgc_mouseIcon) - 1,					 (u32)&iObj_set_mouseIcon,				 (u32)&iObj_get_mouseIcon					  },
		{	cgc_mousePointer,				sizeof(cgc_mousePointer) - 1,				 (u32)&iObj_set_mousePointer,			 (u32)&iObj_get_mousePointer				  },
		{	cgc_name,						sizeof(cgc_name) - 1,						 (u32)&iObj_set_name,					 (u32)&iObj_get_name						  },
		{	cgc_oLEDragMode,				sizeof(cgc_oLEDragMode) - 1,				 (u32)&iObj_set_oLEDragMode,			 (u32)&iObj_get_oLEDragMode					  },
		{	cgc_oLEDragPicture,				sizeof(cgc_oLEDragPicture) - 1,				 (u32)&iObj_set_oLEDragPicture,			 (u32)&iObj_get_oLEDragPicture				  },
		{	cgc_oLEDropEffects,				sizeof(cgc_oLEDropEffects) - 1,				 (u32)&iObj_set_oLEDropEffects,			 (u32)&iObj_get_oLEDropEffects				  },
		{	cgc_oLEDropHasData,				sizeof(cgc_oLEDropHasData) - 1,				 (u32)&iObj_set_oLEDropHasData,			 (u32)&iObj_get_oLEDropHasData				  },
		{	cgc_oLEDropMode,				sizeof(cgc_oLEDropMode) - 1,				 (u32)&iObj_set_oLEDropMode,			 (u32)&iObj_get_oLEDropMode					  },
		{	cgc_parent,						sizeof(cgc_parent) - 1,						 (u32)&iObj_set_parent,					 (u32)&iObj_get_parent						  },
		{	cgc_parentClass,				sizeof(cgc_parentClass) - 1,				 (u32)&iObj_set_parentClass,			 (u32)&iObj_get_parentClass					  },
		{	cgc_rightToLeft,				sizeof(cgc_rightToLeft) - 1,				 (u32)&iObj_set_rightToLeft,			 (u32)&iObj_get_rightToLeft					  },
		{	cgc_specialEffect,				sizeof(cgc_specialEffect) - 1,				 (u32)&iObj_set_specialEffect,			 (u32)&iObj_get_specialEffect				  },
		{	cgc_statusBarText,				sizeof(cgc_statusBarText) - 1,				 (u32)&iObj_set_statusBarText,			 (u32)&iObj_get_statusBarText				  },
		{	cgc_tabStyle,					sizeof(cgc_tabStyle) - 1,					 (u32)&iObj_set_tabStyle,				 (u32)&iObj_get_tabStyle					  },
		{	cgc_tabIndex,					sizeof(cgc_tabIndex) - 1,					 (u32)&iObj_set_tabIndex,				 (u32)&iObj_get_tabIndex					  },
		{	cgc_tabStop,					sizeof(cgc_tabStop) - 1,					 (u32)&iObj_set_tabStop,				 (u32)&iObj_get_tabStop						  },
		{	cgc_tag,						sizeof(cgc_tag) - 1,						 (u32)&iObj_set_tag,					 (u32)&iObj_get_tag							  },
		{	cgc_themes,						sizeof(cgc_themes) - 1,						 (u32)&iObj_set_themes,					 (u32)&iObj_get_themes						  },
		{	cgc_toolTipText,				sizeof(cgc_toolTipText) - 1,				 (u32)&iObj_set_toolTipText,			 (u32)&iObj_get_toolTipText					  },
		{	cgc_top,						sizeof(cgc_top) - 1,						 (u32)&iObj_set_top,					 (u32)&iObj_get_top							  },
		{	cgc_visible,					sizeof(cgc_visible) - 1,					 (u32)&iObj_set_visible,				 (u32)&iObj_get_visible						  },
		{	cgc_whatsThisHelpID,			sizeof(cgc_whatsThisHelpID) - 1,			 (u32)&iObj_set_whatsThisHelpID,		 (u32)&iObj_get_whatsThisHelpID				  },
		{	cgc_width,						sizeof(cgc_width) - 1,						 (u32)&iObj_set_width,					 (u32)&iObj_get_width						  },
		{	NULL,							0,											 0,										 0										 }
	};

	SPropertyMap gcProps_session[] = 
	{
		{	cgc_dataSession,				sizeof(cgc_dataSession) - 1,				 (u32)&iObj_set_dataSession,			 (u32)&iObj_get_dataSession					  },
		{	cgc_dataSessionID,				sizeof(cgc_dataSessionID) - 1,				 (u32)&iObj_set_dataSessionID,			 (u32)&iObj_get_dataSessionID				  },
		{	cgc_application,				sizeof(cgc_application) - 1,				 (u32)&iObj_set_application,			 (u32)&iObj_get_application					  },
		{	cgc_baseClass,					sizeof(cgc_baseClass) - 1,					 (u32)&iObj_set_baseClass,				 (u32)&iObj_get_baseClass					  },
		{	cgc_class,						sizeof(cgc_class) - 1,						 (u32)&iObj_set_class,					 (u32)&iObj_get_class						  },
		{	cgc_classLibrary,				sizeof(cgc_classLibrary) - 1,				 (u32)&iObj_set_classLibrary,			 (u32)&iObj_get_classLibrary				  },
		{	cgc_comment,					sizeof(cgc_comment) - 1,					 (u32)&iObj_set_comment,				 (u32)&iObj_get_comment						  },
		{	cgc_name,						sizeof(cgc_name) - 1,						 (u32)&iObj_set_name,					 (u32)&iObj_get_name						  },
		{	cgc_parent,						sizeof(cgc_parent) - 1,						 (u32)&iObj_set_parent,					 (u32)&iObj_get_parent						  },
		{	cgc_parentClass,				sizeof(cgc_parentClass) - 1,				 (u32)&iObj_set_parentClass,			 (u32)&iObj_get_parentClass					  },
		{	cgc_tag,						sizeof(cgc_tag) - 1,						 (u32)&iObj_set_tag,					 (u32)&iObj_get_tag							  },
		{	NULL,							0,											 0,										 0										 }
	};

	SPropertyMap gcProps_custom[] = 
	{
		{	cgc_application,				sizeof(cgc_application) - 1,				 (u32)&iObj_set_application,			 (u32)&iObj_get_application					  },
		{	cgc_baseClass,					sizeof(cgc_baseClass) - 1,					 (u32)&iObj_set_baseClass,				 (u32)&iObj_get_baseClass					  },
		{	cgc_class,						sizeof(cgc_class) - 1,						 (u32)&iObj_set_class,					 (u32)&iObj_get_class						  },
		{	cgc_classLibrary,				sizeof(cgc_classLibrary) - 1,				 (u32)&iObj_set_classLibrary,			 (u32)&iObj_get_classLibrary				  },
		{	cgc_controls,					sizeof(cgc_controls) - 1,					 (u32)&iObj_set_controls,				 (u32)&iObj_get_controls					  },
		{	cgc_controlCount,				sizeof(cgc_controlCount) - 1,				 (u32)&iObj_set_controlCount,			 (u32)&iObj_get_controlCount				  },
		{	cgc_objects,					sizeof(cgc_objects) - 1,					 (u32)&iObj_set_objects,				 (u32)&iObj_get_objects						  },
		{	cgc_comment,					sizeof(cgc_comment) - 1,					 (u32)&iObj_set_comment,				 (u32)&iObj_get_comment						  },
		{	cgc_height,						sizeof(cgc_height) - 1,						 (u32)&iObj_set_height,					 (u32)&iObj_get_height						  },
		{	cgc_helpContextID,				sizeof(cgc_helpContextID) - 1,				 (u32)&iObj_set_helpContextID,			 (u32)&iObj_get_helpContextID				  },
		{	cgc_left,						sizeof(cgc_left) - 1,						 (u32)&iObj_set_left,					 (u32)&iObj_get_left						  },
		{	cgc_name,						sizeof(cgc_name) - 1,						 (u32)&iObj_set_name,					 (u32)&iObj_get_name						  },
		{	cgc_parent,						sizeof(cgc_parent) - 1,						 (u32)&iObj_set_parent,					 (u32)&iObj_get_parent						  },
		{	cgc_parentClass,				sizeof(cgc_parentClass) - 1,				 (u32)&iObj_set_parentClass,			 (u32)&iObj_get_parentClass					  },
		{	cgc_picture,					sizeof(cgc_picture) - 1,					 (u32)&iObj_set_picture,				 (u32)&iObj_get_picture						  },
		{	cgc_tag,						sizeof(cgc_tag) - 1,						 (u32)&iObj_set_tag,					 (u32)&iObj_get_tag							  },
		{	cgc_top,						sizeof(cgc_top) - 1,						 (u32)&iObj_set_top,					 (u32)&iObj_get_top							  },
		{	cgc_whatsThisHelpID,			sizeof(cgc_whatsThisHelpID) - 1,			 (u32)&iObj_set_whatsThisHelpID,		 (u32)&iObj_get_whatsThisHelpID				  },
		{	cgc_width,						sizeof(cgc_width) - 1,						 (u32)&iObj_set_width,					 (u32)&iObj_get_width						  },
		{	NULL,							0,											 0,										 0										 }
	};

	SPropertyMap gcProps_exception[] = 
	{
		{	cgc_details,					sizeof(cgc_details) - 1,					 (u32)&iObj_set_details,				 (u32)&iObj_get_details						  },
		{	cgc_errorNo,					sizeof(cgc_errorNo) - 1,					 (u32)&iObj_set_errorNo,				 (u32)&iObj_get_errorNo						  },
		{	cgc_lineContents,				sizeof(cgc_lineContents) - 1,				 (u32)&iObj_set_lineContents,			 (u32)&iObj_get_lineContents				  },
		{	cgc_lineNo,						sizeof(cgc_lineNo) - 1,						 (u32)&iObj_set_lineNo,					 (u32)&iObj_get_lineNo						  },
		{	cgc_message,					sizeof(cgc_message) - 1,					 (u32)&iObj_set_message,				 (u32)&iObj_get_message						  },
		{	cgc_procedure,					sizeof(cgc_procedure) - 1,					 (u32)&iObj_set_procedure,				 (u32)&iObj_get_procedure					  },
		{	cgc_stackLevel,					sizeof(cgc_stackLevel) - 1,					 (u32)&iObj_set_stackLevel,				 (u32)&iObj_get_stackLevel					  },
		{	cgc_userValue,					sizeof(cgc_userValue) - 1,					 (u32)&iObj_set_userValue,				 (u32)&iObj_get_userValue					  },
		{	cgc_baseClass,					sizeof(cgc_baseClass) - 1,					 (u32)&iObj_set_baseClass,				 (u32)&iObj_get_baseClass					  },
		{	cgc_class,						sizeof(cgc_class) - 1,						 (u32)&iObj_set_class,					 (u32)&iObj_get_class						  },
		{	cgc_classLibrary,				sizeof(cgc_classLibrary) - 1,				 (u32)&iObj_set_classLibrary,			 (u32)&iObj_get_classLibrary				  },
		{	cgc_comment,					sizeof(cgc_comment) - 1,					 (u32)&iObj_set_comment,				 (u32)&iObj_get_comment						  },
		{	cgc_name,						sizeof(cgc_name) - 1,						 (u32)&iObj_set_name,					 (u32)&iObj_get_name						  },
		{	cgc_parent,						sizeof(cgc_parent) - 1,						 (u32)&iObj_set_parent,					 (u32)&iObj_get_parent						  },
		{	cgc_parentClass,				sizeof(cgc_parentClass) - 1,				 (u32)&iObj_set_parentClass,			 (u32)&iObj_get_parentClass					  },
		{	cgc_tag,						sizeof(cgc_tag) - 1,						 (u32)&iObj_set_tag,					 (u32)&iObj_get_tag							  },
		{	NULL,							0,											 0,										 0										 }
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
