//////////
//
// /libsf/source/vjr/objects.cpp
//
//////
// Version 0.31
// Copyright (c) 2014 by Rick C. Hodgin
//////
// Last update:
//     Jun.14.2014
//////
// Change log:
//     Jun.14.2014 - Initial creation
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
//     http://www.libsf.org/
//     http://www.libsf.org/licenses/
//     http://www.visual-freepro.org/vjr/indexmain.html
//     http://www.visual-freepro.org/wiki/index.php/PBL
//     http://www.visual-freepro.org/wiki/index.php/Repeat_License
//
// Thank you.  And may The Lord bless you richly as you lift up your life, your
// talents, your gifts, your praise, unto Him.  In Jesus' name I pray.  Amen.
//
//







//////////
// Property translation text name to property value
//////
	SPropertyList gsBaseObjectProperties[] = {
		{	cgcName_parent,					sizeof(cgcName_parent) - 1,					(u32)&iObj_setError,							(u32)&iObj_getProperty_parent				},
		{	cgcName_tabIndex,				sizeof(cgcName_tabIndex) - 1,				(u32)&iObj_setProperty_tabIndex,				(u32)&iObj_getProperty_tabIndex				},
		{	cgcName_tabStop,				sizeof(cgcName_tabStop) - 1,				(u32)&iObj_setProperty_tabStop,					(u32)&iObj_getProperty_tabStop				},
		{	cgcName_helpContextId,			sizeof(cgcName_helpContextId) - 1,			(u32)&iObj_setProperty_helpContextId,			(u32)&iObj_getProperty_helpContextId		},
		{	cgcName_hasWhatsThisButton,		sizeof(cgcName_hasWhatsThisButton) - 1,		(u32)&iObj_setProperty_hasWhatsThisButton,		(u32)&iObj_getProperty_hasWhatsThisButton	},
		{	cgcName_hasWhatsThisHelp,		sizeof(cgcName_hasWhatsThisHelp) - 1,		(u32)&iObj_setProperty_hasWhatsThisHelp,		(u32)&iObj_getProperty_hasWhatsThisHelp		},
		{	cgcName_whatsThisHelpId,		sizeof(cgcName_whatsThisHelpId) - 1,		(u32)&iObj_setProperty_whatsThisHelpId,			(u32)&iObj_getProperty_whatsThisHelpId		},
		{	cgcName_name,					sizeof(cgcName_name) - 1,					(u32)&iObj_setProperty_name,					(u32)&iObj_getProperty_name					},
		{	cgcName_className,				sizeof(cgcName_className) - 1,				(u32)&iObj_setError,							(u32)&iObj_getProperty_className			},
		{	cgcName_classLibrary,			sizeof(cgcName_classLibrary) - 1,			(u32)&iObj_setError,							(u32)&iObj_getProperty_classLibrary			},
		{	cgcName_comment,				sizeof(cgcName_comment) - 1,				(u32)&iObj_setProperty_comment,					(u32)&iObj_getProperty_comment				},
		{	cgcName_toolTip,				sizeof(cgcName_toolTip) - 1,				(u32)&iObj_setProperty_toolTip,					(u32)&iObj_getProperty_toolTip				},
		{	cgcName_tag,					sizeof(cgcName_tag) - 1,					(u32)&iObj_setProperty_tag,						(u32)&iObj_getProperty_tag					},
		{	cgcName_mousePointer,			sizeof(cgcName_mousePointer) - 1,			(u32)&iObj_setProperty_mousePointer,			(u32)&iObj_getProperty_mousePointer			},
		{	cgcName_isEnabled,				sizeof(cgcName_isEnabled) - 1,				(u32)&iObj_setProperty_isEnabled,				(u32)&iObj_getProperty_isEnabled			},
		{	cgcName_hasFocus,				sizeof(cgcName_hasFocus) - 1,				(u32)&iObj_setProperty_hasFocus,				(u32)&iObj_getProperty_hasFocus				},
		{	cgcName_isMovable,				sizeof(cgcName_isMovable) - 1,				(u32)&iObj_setProperty_isMovable,				(u32)&iObj_getProperty_isMovable			},
		{	cgcName_isRendered,				sizeof(cgcName_isRendered) - 1,				(u32)&iObj_setProperty_isRendered,				(u32)&iObj_getProperty_isRendered			},
		{	cgcName_isPublished,			sizeof(cgcName_isPublished) - 1,			(u32)&iObj_setProperty_isPublished,				(u32)&iObj_getProperty_isPublished			},
		{	cgcName_isVisible,				sizeof(cgcName_isVisible) - 1,				(u32)&iObj_setProperty_isVisible,				(u32)&iObj_getProperty_isVisible			},
		{	cgcName_isDirty,				sizeof(cgcName_isDirty) - 1,				(u32)&iObj_setProperty_isDirty,					(u32)&iObj_getProperty_isDirty				},
		{	cgcName_left,					sizeof(cgcName_left) - 1,					(u32)&iObj_setProperty_left,					(u32)&iObj_getProperty_left					},
		{	cgcName_top,					sizeof(cgcName_top) - 1,					(u32)&iObj_setProperty_top,						(u32)&iObj_getProperty_top					},
		{	cgcName_width,					sizeof(cgcName_width) - 1,					(u32)&iObj_setProperty_width,					(u32)&iObj_getProperty_width				},
		{	cgcName_height,					sizeof(cgcName_height) - 1,					(u32)&iObj_setProperty_height,					(u32)&iObj_getProperty_height				},
		{	cgcName_anchor,					sizeof(cgcName_anchor) - 1,					(u32)&iObj_setProperty_anchor,					(u32)&iObj_getProperty_anchor				},
		{	cgcName_scrollX,				sizeof(cgcName_scrollX) - 1,				(u32)&iObj_setProperty_scrollX,					(u32)&iObj_getProperty_scrollX				},
		{	cgcName_scrollY,				sizeof(cgcName_scrollY) - 1,				(u32)&iObj_setProperty_scrollY,					(u32)&iObj_getProperty_scrollY				},
		{	cgcName_scaleX,					sizeof(cgcName_scaleX) - 1,					(u32)&iObj_setProperty_scaleX,					(u32)&iObj_getProperty_scaleX				},
		{	cgcName_scaleY,					sizeof(cgcName_scaleY) - 1,					(u32)&iObj_setProperty_scaleY,					(u32)&iObj_getProperty_scaleY				},
		// Note:  Do not delete this line, it is used to terminate the search list
		{	0, 0, 0, 0	}
	};

	SPropertyList gsEmptyProperties[] = {
//		{	cgcName_parent,					sizeof(cgcName_parent) - 1,					(u32)&iObj_setError,							(u32)&iObj_getProperty_parent				},
		// Note:  Do not delete this line, it is used to terminate the search list
		{	0, 0, 0, 0	}
	};

	SPropertyList gsFormProperties[] = {
		{	cgcName_minLeft,				sizeof(cgcName_minLeft) - 1,				(u32)&iiSubobj_form_setMinLeft,                  (u32)&iiSubobj_form_getMinLeft					},
		{	cgcName_minTop,					sizeof(cgcName_minTop) - 1,					(u32)&iiSubobj_form_setMinTop,                   (u32)&iiSubobj_form_getMinTop					},
		{	cgcName_minWidth,				sizeof(cgcName_minWidth) - 1,				(u32)&iiSubobj_form_setMinWidth,                 (u32)&iiSubobj_form_getMinWidth				},
		{	cgcName_minHeight,				sizeof(cgcName_minHeight) - 1,				(u32)&iiSubobj_form_setMinHeight,                (u32)&iiSubobj_form_getMinHeight				},
		{	cgcName_maxLeft,				sizeof(cgcName_maxLeft) - 1,				(u32)&iiSubobj_form_setMaxLeft,                  (u32)&iiSubobj_form_getMaxLeft					},
		{	cgcName_maxTop,					sizeof(cgcName_maxTop) - 1,					(u32)&iiSubobj_form_setMaxTop,                   (u32)&iiSubobj_form_getMaxTop					},
		{	cgcName_maxWidth,				sizeof(cgcName_maxWidth) - 1,				(u32)&iiSubobj_form_setMaxWidth,                 (u32)&iiSubobj_form_getMaxWidth				},
		{	cgcName_maxHeight,				sizeof(cgcName_maxHeight) - 1,				(u32)&iiSubobj_form_setMaxHeight,                (u32)&iiSubobj_form_getMaxHeight				},
		{	cgcName_fontName,				sizeof(cgcName_fontName) - 1,				(u32)&iiSubobj_form_setFontName,                 (u32)&iiSubobj_form_getFontName				},
		{	cgcName_fontSize,				sizeof(cgcName_fontSize) - 1,				(u32)&iiSubobj_form_setFontSize,                 (u32)&iiSubobj_form_getFontSize				},
		{	cgcName_fontBold,				sizeof(cgcName_fontBold) - 1,				(u32)&iiSubobj_form_setFontBold,                 (u32)&iiSubobj_form_getFontBold				},
		{	cgcName_fontItalic,				sizeof(cgcName_fontItalic) - 1,				(u32)&iiSubobj_form_setFontItalic,               (u32)&iiSubobj_form_getFontItalic				},
		{	cgcName_fontUnderline,			sizeof(cgcName_fontUnderline) - 1,			(u32)&iiSubobj_form_setFontUnderline,            (u32)&iiSubobj_form_getFontUnderline			},
		{	cgcName_fontStrikethrough,		sizeof(cgcName_fontStrikethrough) - 1,		(u32)&iiSubobj_form_setFontStrikethrough,        (u32)&iiSubobj_form_getFontStrikethrough		},
		{	cgcName_fontCondensed,			sizeof(cgcName_fontCondensed) - 1,			(u32)&iiSubobj_form_setFontCondensed,            (u32)&iiSubobj_form_getFontCondensed			},
		{	cgcName_fontExtended,			sizeof(cgcName_fontExtended) - 1,			(u32)&iiSubobj_form_setFontExtended,             (u32)&iiSubobj_form_getFontExtended			},
		{	cgcName_fontOutline,			sizeof(cgcName_fontOutline) - 1,			(u32)&iiSubobj_form_setFontOutline,              (u32)&iiSubobj_form_getFontOutline				},
		{	cgcName_fontShadow,				sizeof(cgcName_fontShadow) - 1,				(u32)&iiSubobj_form_setFontShadow,               (u32)&iiSubobj_form_getFontShadow				},
		{	cgcName_nwColor,				sizeof(cgcName_nwColor) - 1,				(u32)&iiSubobj_form_setNwColor,                  (u32)&iiSubobj_form_getNwColor					},
		{	cgcName_neColor,				sizeof(cgcName_neColor) - 1,				(u32)&iiSubobj_form_setNeColor,                  (u32)&iiSubobj_form_getNeColor					},
		{	cgcName_swColor,				sizeof(cgcName_swColor) - 1,				(u32)&iiSubobj_form_setSwColor,                  (u32)&iiSubobj_form_getSwColor					},
		{	cgcName_seColor,				sizeof(cgcName_seColor) - 1,				(u32)&iiSubobj_form_setSeColor,                  (u32)&iiSubobj_form_getSeColor					},
		{	cgcName_backColor,				sizeof(cgcName_backColor) - 1,				(u32)&iiSubobj_form_setBackColor,                (u32)&iiSubobj_form_getBackColor				},
		{	cgcName_foreColor,				sizeof(cgcName_foreColor) - 1,				(u32)&iiSubobj_form_setForeColor,                (u32)&iiSubobj_form_getForeColor				},
		{	cgcName_captionColor,			sizeof(cgcName_captionColor) - 1,			(u32)&iiSubobj_form_setCaptionColor,             (u32)&iiSubobj_form_getCaptionColor			},
		{	cgcName_caption,				sizeof(cgcName_caption) - 1,				(u32)&iiSubobj_form_setCaption,                  (u32)&iiSubobj_form_getCaption					},
		{	cgcName_picture,				sizeof(cgcName_picture) - 1,				(u32)&iiSubobj_form_setPicture,                  (u32)&iiSubobj_form_getPicture					},
		{	cgcName_allowOutput,			sizeof(cgcName_allowOutput) - 1,			(u32)&iiSubobj_form_setAllowOutput,              (u32)&iiSubobj_form_getAllowOutput				},
		{	cgcName_alwaysOnBottom,			sizeof(cgcName_alwaysOnBottom) - 1,			(u32)&iiSubobj_form_setAlwaysOnBottom,           (u32)&iiSubobj_form_getAlwaysOnBottom			},
		{	cgcName_alwaysOnTop,			sizeof(cgcName_alwaysOnTop) - 1,			(u32)&iiSubobj_form_setAlwaysOnTop,              (u32)&iiSubobj_form_getAlwaysOnTop				},
		{	cgcName_autoCenter,				sizeof(cgcName_autoCenter) - 1,				(u32)&iiSubobj_form_setAutoCenter,               (u32)&iiSubobj_form_getAutoCenter				},
		{	cgcName_borderStyle,			sizeof(cgcName_borderStyle) - 1,			(u32)&iiSubobj_form_setBorderStyle,              (u32)&iiSubobj_form_getBorderStyle				},
		{	cgcName_isCloseable,			sizeof(cgcName_isCloseable) - 1,			(u32)&iiSubobj_form_setIsCloseable,              (u32)&iiSubobj_form_getIsCloseable				},
		{	cgcName_processKeyPreviewEvents,sizeof(cgcName_processKeyPreviewEvents) - 1,(u32)&iiSubobj_form_setProcessKeyPreviewEvents,  (u32)&iiSubobj_form_getProcessKeyPreviewEvents	},
		{	cgcName_hasControlBox,			sizeof(cgcName_hasControlBox) - 1,			(u32)&iiSubobj_form_setHasControlBox,            (u32)&iiSubobj_form_getHasControlBox			},
		{	cgcName_hasMinButton,			sizeof(cgcName_hasMinButton) - 1,			(u32)&iiSubobj_form_setHasMinButton,             (u32)&iiSubobj_form_getHasMinButton			},
		{	cgcName_hasCloseButton,			sizeof(cgcName_hasCloseButton) - 1,			(u32)&iiSubobj_form_setHasCloseButton,           (u32)&iiSubobj_form_getHasCloseButton			},
		{	cgcName_scaleMode,				sizeof(cgcName_scaleMode) - 1,				(u32)&iiSubobj_form_setScaleMode,                (u32)&iiSubobj_form_getScaleMode				},
		{	cgcName_showInTaskBar,			sizeof(cgcName_showInTaskBar) - 1,			(u32)&iiSubobj_form_setShowInTaskBar,            (u32)&iiSubobj_form_getShowInTaskBar			},
		{	cgcName_windowState,			sizeof(cgcName_windowState) - 1,			(u32)&iiSubobj_form_setWindowState,              (u32)&iiSubobj_form_getWindowState				},
		{	cgcName_bindControls,			sizeof(cgcName_bindControls) - 1,			(u32)&iiSubobj_form_setBindControls,             (u32)&iiSubobj_form_getBindControls			},
		{	cgcName_bufferMode,				sizeof(cgcName_bufferMode) - 1,				(u32)&iiSubobj_form_setBufferMode,               (u32)&iiSubobj_form_getBufferMode				},
		{	cgcName_clipControls,			sizeof(cgcName_clipControls) - 1,			(u32)&iiSubobj_form_setClipControls,             (u32)&iiSubobj_form_getClipControls			},
		{	cgcName_colorSource,			sizeof(cgcName_colorSource) - 1,			(u32)&iiSubobj_form_setColorSource,              (u32)&iiSubobj_form_getColorSource				},
		{	cgcName_continuousScroll,		sizeof(cgcName_continuousScroll) - 1,		(u32)&iiSubobj_form_setContinuousScroll,         (u32)&iiSubobj_form_getContinuousScroll		},
		{	cgcName_dataSession,			sizeof(cgcName_dataSession) - 1,			(u32)&iiSubobj_form_setDataSession,              (u32)&iiSubobj_form_getDataSession				},
		{	cgcName_dataSessionId,			sizeof(cgcName_dataSessionId) - 1,			(u32)&iiSubobj_form_setDataSessionId,            (u32)&iiSubobj_form_getDataSessionId			},
		{	cgcName_deClass,				sizeof(cgcName_deClass) - 1,				(u32)&iiSubobj_form_setDeClass,                  (u32)&iiSubobj_form_getDeClass					},
		{	cgcName_deClassLibrary,			sizeof(cgcName_deClassLibrary) - 1,			(u32)&iiSubobj_form_setDeClassLibrary,           (u32)&iiSubobj_form_getDeClassLibrary			},
		{	cgcName_defOleCid,				sizeof(cgcName_defOleCid) - 1,				(u32)&iiSubobj_form_setDefOleCid,                (u32)&iiSubobj_form_getDefOleCid				},
		{	cgcName_desktop,				sizeof(cgcName_desktop) - 1,				(u32)&iiSubobj_form_setDesktop,                  (u32)&iiSubobj_form_getDesktop					},
		{	cgcName_isDockable,				sizeof(cgcName_isDockable) - 1,				(u32)&iiSubobj_form_setIsDockable,               (u32)&iiSubobj_form_getIsDockable				},
		{	cgcName_isDocked,				sizeof(cgcName_isDocked) - 1,				(u32)&iiSubobj_form_setIsDocked,                 (u32)&iiSubobj_form_getIsDocked				},
		{	cgcName_dockPosition,			sizeof(cgcName_dockPosition) - 1,			(u32)&iiSubobj_form_setDockPosition,             (u32)&iiSubobj_form_getDockPosition			},
		{	cgcName_drawMode,				sizeof(cgcName_drawMode) - 1,				(u32)&iiSubobj_form_setDrawMode,                 (u32)&iiSubobj_form_getDrawMode				},
		{	cgcName_drawStyle,				sizeof(cgcName_drawStyle) - 1,				(u32)&iiSubobj_form_setDrawStyle,                (u32)&iiSubobj_form_getDrawStyle				},
		{	cgcName_drawWidth,				sizeof(cgcName_drawWidth) - 1,				(u32)&iiSubobj_form_setDrawWidth,                (u32)&iiSubobj_form_getDrawWidth				},
		{	cgcName_fillColor,				sizeof(cgcName_fillColor) - 1,				(u32)&iiSubobj_form_setFillColor,                (u32)&iiSubobj_form_getFillColor				},
		{	cgcName_fillStyle,				sizeof(cgcName_fillStyle) - 1,				(u32)&iiSubobj_form_setFillStyle,                (u32)&iiSubobj_form_getFillStyle				},
		{	cgcName_halfHeightCaption,		sizeof(cgcName_halfHeightCaption) - 1,		(u32)&iiSubobj_form_setHalfHeightCaption,        (u32)&iiSubobj_form_getHalfHeightCaption		},
		{	cgcName_hScrollSmallChange,		sizeof(cgcName_hScrollSmallChange) - 1,		(u32)&iiSubobj_form_setHScrollSmallChange,       (u32)&iiSubobj_form_getHScrollSmallChange		},
		{	cgcName_vScrollSmallChange,		sizeof(cgcName_vScrollSmallChange) - 1,		(u32)&iiSubobj_form_setVScrollSmallChange,       (u32)&iiSubobj_form_getVScrollSmallChange		},
		{	cgcName_macDesktop,				sizeof(cgcName_macDesktop) - 1,				(u32)&iiSubobj_form_setMacDesktop,               (u32)&iiSubobj_form_getMacDesktop				},
		{	cgcName_mdiForm,				sizeof(cgcName_mdiForm) - 1,				(u32)&iiSubobj_form_setMdiForm,                  (u32)&iiSubobj_form_getMdiForm					},
		{	cgcName_oleDragMode,			sizeof(cgcName_oleDragMode) - 1,			(u32)&iiSubobj_form_setOleDragMode,              (u32)&iiSubobj_form_getOleDragMode				},
		{	cgcName_oleDragPicture,			sizeof(cgcName_oleDragPicture) - 1,			(u32)&iObj_setError,							(u32)&iObj_getError								},
		{	cgcName_oleDropEffects,			sizeof(cgcName_oleDropEffects) - 1,			(u32)&iiSubobj_form_setOleDropEffects,           (u32)&iiSubobj_form_getOleDropEffects			},
		{	cgcName_oleDropHasData,			sizeof(cgcName_oleDropHasData) - 1,			(u32)&iiSubobj_form_setOleDropHasData,           (u32)&iiSubobj_form_getOleDropHasData			},
		{	cgcName_oleDropMode,			sizeof(cgcName_oleDropMode) - 1,			(u32)&iiSubobj_form_setOleDropMode,              (u32)&iiSubobj_form_getOleDropMode				},
		{	cgcName_releaseType,			sizeof(cgcName_releaseType) - 1,			(u32)&iiSubobj_form_setReleaseType,              (u32)&iiSubobj_form_getReleaseType				},
		{	cgcName_rightToLeft,			sizeof(cgcName_rightToLeft) - 1,			(u32)&iiSubobj_form_setRightToLeft,              (u32)&iiSubobj_form_getRightToLeft				},
		{	cgcName_scrollbars,				sizeof(cgcName_scrollbars) - 1,				(u32)&iiSubobj_form_setScrollbars,               (u32)&iiSubobj_form_getScrollbars				},
		{	cgcName_showTips,				sizeof(cgcName_showTips) - 1,				(u32)&iiSubobj_form_setShowTips,                 (u32)&iiSubobj_form_getShowTips				},
		{	cgcName_showWindow,				sizeof(cgcName_showWindow) - 1,				(u32)&iiSubobj_form_setShowWindow,               (u32)&iiSubobj_form_getShowWindow				},
		{	cgcName_sizeBox,				sizeof(cgcName_sizeBox) - 1,				(u32)&iiSubobj_form_setSizeBox,                  (u32)&iiSubobj_form_getSizeBox					},
		{	cgcName_themes,					sizeof(cgcName_themes) - 1,					(u32)&iiSubobj_form_setThemes,                   (u32)&iiSubobj_form_getThemes					},
		{	cgcName_titleBar,				sizeof(cgcName_titleBar) - 1,				(u32)&iiSubobj_form_setTitleBar,                 (u32)&iiSubobj_form_getTitleBar				},
		{	cgcName_windowType,				sizeof(cgcName_windowType) - 1,				(u32)&iiSubobj_form_setWindowType,               (u32)&iiSubobj_form_getWindowType				},
		{	cgcName_zoomBox,				sizeof(cgcName_zoomBox) - 1,				(u32)&iiSubobj_form_setZoomBox,                  (u32)&iiSubobj_form_getZoomBox					},
		// Note:  Do not delete this line, it is used to terminate the search list
		{	0, 0, 0, 0	}
	};

	SPropertyList gsSubformProperties[] = {
		{	cgcName_minLeft,				sizeof(cgcName_minLeft) - 1,				(u32)&iiSubobj_subform_setMinLeft,                  (u32)&iiSubobj_subform_getMinLeft					},
		{	cgcName_minTop,					sizeof(cgcName_minTop) - 1,					(u32)&iiSubobj_subform_setMinTop,                   (u32)&iiSubobj_subform_getMinTop					},
		{	cgcName_minWidth,				sizeof(cgcName_minWidth) - 1,				(u32)&iiSubobj_subform_setMinWidth,                 (u32)&iiSubobj_subform_getMinWidth					},
		{	cgcName_minHeight,				sizeof(cgcName_minHeight) - 1,				(u32)&iiSubobj_subform_setMinHeight,                (u32)&iiSubobj_subform_getMinHeight					},
		{	cgcName_maxLeft,				sizeof(cgcName_maxLeft) - 1,				(u32)&iiSubobj_subform_setMaxLeft,                  (u32)&iiSubobj_subform_getMaxLeft					},
		{	cgcName_maxTop,					sizeof(cgcName_maxTop) - 1,					(u32)&iiSubobj_subform_setMaxTop,                   (u32)&iiSubobj_subform_getMaxTop					},
		{	cgcName_maxWidth,				sizeof(cgcName_maxWidth) - 1,				(u32)&iiSubobj_subform_setMaxWidth,                 (u32)&iiSubobj_subform_getMaxWidth					},
		{	cgcName_maxHeight,				sizeof(cgcName_maxHeight) - 1,				(u32)&iiSubobj_subform_setMaxHeight,                (u32)&iiSubobj_subform_getMaxHeight					},
		{	cgcName_fontName,				sizeof(cgcName_fontName) - 1,				(u32)&iiSubobj_subform_setFontName,                 (u32)&iiSubobj_subform_getFontName					},
		{	cgcName_fontSize,				sizeof(cgcName_fontSize) - 1,				(u32)&iiSubobj_subform_setFontSize,                 (u32)&iiSubobj_subform_getFontSize					},
		{	cgcName_fontBold,				sizeof(cgcName_fontBold) - 1,				(u32)&iiSubobj_subform_setFontBold,                 (u32)&iiSubobj_subform_getFontBold					},
		{	cgcName_fontItalic,				sizeof(cgcName_fontItalic) - 1,				(u32)&iiSubobj_subform_setFontItalic,               (u32)&iiSubobj_subform_getFontItalic				},
		{	cgcName_fontUnderline,			sizeof(cgcName_fontUnderline) - 1,			(u32)&iiSubobj_subform_setFontUnderline,            (u32)&iiSubobj_subform_getFontUnderline				},
		{	cgcName_fontStrikethrough,		sizeof(cgcName_fontStrikethrough) - 1,		(u32)&iiSubobj_subform_setFontStrikethrough,        (u32)&iiSubobj_subform_getFontStrikethrough			},
		{	cgcName_fontCondensed,			sizeof(cgcName_fontCondensed) - 1,			(u32)&iiSubobj_subform_setFontCondensed,            (u32)&iiSubobj_subform_getFontCondensed				},
		{	cgcName_fontExtended,			sizeof(cgcName_fontExtended) - 1,			(u32)&iiSubobj_subform_setFontExtended,             (u32)&iiSubobj_subform_getFontExtended				},
		{	cgcName_fontOutline,			sizeof(cgcName_fontOutline) - 1,			(u32)&iiSubobj_subform_setFontOutline,              (u32)&iiSubobj_subform_getFontOutline				},
		{	cgcName_fontShadow,				sizeof(cgcName_fontShadow) - 1,				(u32)&iiSubobj_subform_setFontShadow,               (u32)&iiSubobj_subform_getFontShadow				},
		{	cgcName_nwColor,				sizeof(cgcName_nwColor) - 1,				(u32)&iiSubobj_subform_setNwColor,                  (u32)&iiSubobj_subform_getNwColor					},
		{	cgcName_neColor,				sizeof(cgcName_neColor) - 1,				(u32)&iiSubobj_subform_setNeColor,                  (u32)&iiSubobj_subform_getNeColor					},
		{	cgcName_swColor,				sizeof(cgcName_swColor) - 1,				(u32)&iiSubobj_subform_setSwColor,                  (u32)&iiSubobj_subform_getSwColor					},
		{	cgcName_seColor,				sizeof(cgcName_seColor) - 1,				(u32)&iiSubobj_subform_setSeColor,                  (u32)&iiSubobj_subform_getSeColor					},
		{	cgcName_backColor,				sizeof(cgcName_backColor) - 1,				(u32)&iiSubobj_subform_setBackColor,                (u32)&iiSubobj_subform_getBackColor					},
		{	cgcName_foreColor,				sizeof(cgcName_foreColor) - 1,				(u32)&iiSubobj_subform_setForeColor,                (u32)&iiSubobj_subform_getForeColor					},
		{	cgcName_captionColor,			sizeof(cgcName_captionColor) - 1,			(u32)&iiSubobj_subform_setCaptionColor,             (u32)&iiSubobj_subform_getCaptionColor				},
		{	cgcName_caption,				sizeof(cgcName_caption) - 1,				(u32)&iiSubobj_subform_setCaption,                  (u32)&iiSubobj_subform_getCaption					},
		{	cgcName_picture,				sizeof(cgcName_picture) - 1,				(u32)&iiSubobj_subform_setPicture,                  (u32)&iiSubobj_subform_getPicture					},
		{	cgcName_allowOutput,			sizeof(cgcName_allowOutput) - 1,			(u32)&iiSubobj_subform_setAllowOutput,              (u32)&iiSubobj_subform_getAllowOutput				},
		{	cgcName_borderStyle,			sizeof(cgcName_borderStyle) - 1,			(u32)&iiSubobj_subform_setBorderStyle,              (u32)&iiSubobj_subform_getBorderStyle				},
		{	cgcName_processKeyPreviewEvents,sizeof(cgcName_processKeyPreviewEvents) - 1,(u32)&iiSubobj_subform_setProcessKeyPreviewEvents,  (u32)&iiSubobj_subform_getProcessKeyPreviewEvents	},
		{	cgcName_scaleMode,				sizeof(cgcName_scaleMode) - 1,				(u32)&iiSubobj_subform_setScaleMode,                (u32)&iiSubobj_subform_getScaleMode					},
		{	cgcName_windowState,			sizeof(cgcName_windowState) - 1,			(u32)&iiSubobj_subform_setWindowState,              (u32)&iiSubobj_subform_getWindowState				},
		// Note:  Do not delete this line, it is used to terminate the search list
		{	0, 0, 0, 0	}
	};

	SPropertyList gsLabelProperties[] = {
//		{	cgcName_parent,					sizeof(cgcName_parent) - 1,					(u32)&iObj_setError,							(u32)&iObj_getProperty_parent				},
		// Note:  Do not delete this line, it is used to terminate the search list
		{	0, 0, 0, 0	}
	};

	SPropertyList gsTextboxProperties[] = {
//		{	cgcName_parent,					sizeof(cgcName_parent) - 1,					(u32)&iObj_setError,							(u32)&iObj_getProperty_parent				},
		// Note:  Do not delete this line, it is used to terminate the search list
		{	0, 0, 0, 0	}
	};

	SPropertyList gsButtonProperties[] = {
//		{	cgcName_parent,					sizeof(cgcName_parent) - 1,					(u32)&iObj_setError,							(u32)&iObj_getProperty_parent				},
		// Note:  Do not delete this line, it is used to terminate the search list
		{	0, 0, 0, 0	}
	};

	SPropertyList gsEditboxProperties[] = {
//		{	cgcName_parent,					sizeof(cgcName_parent) - 1,					(u32)&iObj_setError,							(u32)&iObj_getProperty_parent				},
		// Note:  Do not delete this line, it is used to terminate the search list
		{	0, 0, 0, 0	}
	};

	SPropertyList gsImageProperties[] = {
//		{	cgcName_parent,					sizeof(cgcName_parent) - 1,					(u32)&iObj_setError,							(u32)&iObj_getProperty_parent				},
		// Note:  Do not delete this line, it is used to terminate the search list
		{	0, 0, 0, 0	}
	};

	SPropertyList gsCheckboxProperties[] = {
//		{	cgcName_parent,					sizeof(cgcName_parent) - 1,					(u32)&iObj_setError,							(u32)&iObj_getProperty_parent				},
		// Note:  Do not delete this line, it is used to terminate the search list
		{	0, 0, 0, 0	}
	};

	SPropertyList gsOptionProperties[] = {
//		{	cgcName_parent,					sizeof(cgcName_parent) - 1,					(u32)&iObj_setError,							(u32)&iObj_getProperty_parent				},
		// Note:  Do not delete this line, it is used to terminate the search list
		{	0, 0, 0, 0	}
	};

	SPropertyList gsRadioProperties[] = {
//		{	cgcName_parent,					sizeof(cgcName_parent) - 1,					(u32)&iObj_setError,							(u32)&iObj_getProperty_parent				},
		// Note:  Do not delete this line, it is used to terminate the search list
		{	0, 0, 0, 0	}
	};


//////////
// Baseclass translation text name to objType, and objType to full record
//////
	SBaseclassList gsKnownBaseclasses[] = {
		//	objType					Text name				Length of name						Base object property list			Sub-object property list
		//  ------------------		-----------------		-------------------------------		-------------------------------		---------------------------
		{	_OBJ_TYPE_EMPTY,		cgcName_empty,			sizeof(cgcName_empty)		- 1,	(u32)&gsBaseObjectProperties[0],	(u32)&gsEmptyProperties[0]		},
		{	_OBJ_TYPE_FORM,			cgcName_form,			sizeof(cgcName_form)		- 1,	(u32)&gsBaseObjectProperties[0],	(u32)&gsFormProperties[0]		},
		{	_OBJ_TYPE_SUBFORM,		cgcName_subform,		sizeof(cgcName_subform)		- 1,	(u32)&gsBaseObjectProperties[0],	(u32)&gsSubformProperties[0]	},
		{	_OBJ_TYPE_LABEL,		cgcName_label,			sizeof(cgcName_label)		- 1,	(u32)&gsBaseObjectProperties[0],	(u32)&gsLabelProperties[0]		},
		{	_OBJ_TYPE_TEXTBOX,		cgcName_textbox,		sizeof(cgcName_textbox)		- 1,	(u32)&gsBaseObjectProperties[0],	(u32)&gsTextboxProperties[0]	},
		{	_OBJ_TYPE_BUTTON,		cgcName_button,			sizeof(cgcName_button)		- 1,	(u32)&gsBaseObjectProperties[0],	(u32)&gsButtonProperties[0]		},
		{	_OBJ_TYPE_EDITBOX,		cgcName_editbox,		sizeof(cgcName_editbox)		- 1,	(u32)&gsBaseObjectProperties[0],	(u32)&gsEditboxProperties[0]	},
		{	_OBJ_TYPE_IMAGE,		cgcName_image,			sizeof(cgcName_image)		- 1,	(u32)&gsBaseObjectProperties[0],	(u32)&gsImageProperties[0]		},
		{	_OBJ_TYPE_CHECKBOX,		cgcName_checkbox,		sizeof(cgcName_checkbox)	- 1,	(u32)&gsBaseObjectProperties[0],	(u32)&gsCheckboxProperties[0]	},
		{	_OBJ_TYPE_OPTION,		cgcName_option,			sizeof(cgcName_option)		- 1,	(u32)&gsBaseObjectProperties[0],	(u32)&gsOptionProperties[0]		},
		{	_OBJ_TYPE_RADIO,		cgcName_radio,			sizeof(cgcName_radio)		- 1,	(u32)&gsBaseObjectProperties[0],	(u32)&gsRadioProperties[0]		},
		// Note:  Do not delete this line, it is used to terminate the search list
		{	0,						NULL,					0,									NULL,								NULL	}
	};




//////////
//
// Creates the object structure
//
//////
	SObject* iObj_create(u32 tnBaseType, void* obj_data)
	{
		SObject* obj;


		//////////
		// Create the indicated item
		//////
			obj = (SObject*)malloc(sizeof(SObject));


		//////////
		// If successful, initialize it
		//////
			if (obj)
			{
				// Initialize
				memset(obj, 0, sizeof(SObject));

				// Initially populate
				obj->objType = tnBaseType;

				// If they gave us a child, we'll use that
				if (obj_data)
				{
					// Whatever they handed off to us we assume
					obj->sub_obj = obj_data;

				} else {
					// We need to create it
					switch (tnBaseType)
					{
						case _OBJ_TYPE_EMPTY:		// Empty, used as a placeholder object that is not drawn
							iDatum_duplicate(&obj->name,		cgcName_empty, -1);
							iDatum_duplicate(&obj->className,	cgcName_empty, -1);
							obj->sub_obj = (void*)iSubobj_createEmpty(NULL, obj);
							break;

						case _OBJ_TYPE_FORM:			// Form class, the main outer window the OS sees
							iDatum_duplicate(&obj->name,		cgcName_form, -1);
							iDatum_duplicate(&obj->className,	cgcName_form, -1);
							obj->sub_obj = (void*)iSubobj_createForm(NULL, obj);
							break;

						case _OBJ_TYPE_SUBFORM:		// A new class which has its own drawing content and can be moved about using UI features
							iDatum_duplicate(&obj->name,		cgcName_subform, -1);
							iDatum_duplicate(&obj->className,	cgcName_subform, -1);
							obj->sub_obj = (void*)iSubobj_createSubform(NULL, obj);
							break;

						case _OBJ_TYPE_LABEL:		// A label
							iDatum_duplicate(&obj->name,		cgcName_label, -1);
							iDatum_duplicate(&obj->className,	cgcName_label, -1);
							obj->sub_obj = (void*)iSubobj_createLabel(NULL, obj);
							break;

						case _OBJ_TYPE_TEXTBOX:		// An input textbox
							iDatum_duplicate(&obj->name,		cgcName_textbox, -1);
							iDatum_duplicate(&obj->className,	cgcName_textbox, -1);
							obj->sub_obj = (void*)iSubobj_createTextbox(NULL, obj);
							break;

						case _OBJ_TYPE_BUTTON:		// A push button
							iDatum_duplicate(&obj->name,		cgcName_button, -1);
							iDatum_duplicate(&obj->className,	cgcName_button, -1);
							obj->sub_obj = (void*)iSubobj_createButton(NULL, obj);
							break;

						case _OBJ_TYPE_EDITBOX:		// An input multi-line editbox
							iDatum_duplicate(&obj->name,		cgcName_editbox, -1);
							iDatum_duplicate(&obj->className,	cgcName_editbox, -1);
							obj->sub_obj = (void*)iSubobj_createEditbox(NULL, obj);
							break;

						case _OBJ_TYPE_IMAGE:		// A graphical image
							iDatum_duplicate(&obj->name,		cgcName_image, -1);
							iDatum_duplicate(&obj->className,	cgcName_image, -1);
							obj->sub_obj = (void*)iSubobj_createImage(NULL, obj);
							break;

						case _OBJ_TYPE_CHECKBOX:		// A checkbox
							iDatum_duplicate(&obj->name,		cgcName_checkbox, -1);
							iDatum_duplicate(&obj->className,	cgcName_checkbox, -1);
							obj->sub_obj = (void*)iSubobj_createCheckbox(NULL, obj);
							break;

						case _OBJ_TYPE_OPTION:		// A combination selection
							iDatum_duplicate(&obj->name,		cgcName_option, -1);
							iDatum_duplicate(&obj->className,	cgcName_option, -1);
							obj->sub_obj = (void*)iSubobj_createOption(NULL, obj);
							break;

						case _OBJ_TYPE_RADIO:		// A radio dial, which can also present as a slider or spinner
							iDatum_duplicate(&obj->name,		cgcName_radio, -1);
							iDatum_duplicate(&obj->className,	cgcName_radio, -1);
							obj->sub_obj = (void*)iSubobj_createRadio(NULL, obj);
							break;

						default:
// TODO:  We should never get here... we should fire off an internal consistency error
							break;
					}

				}
			}


		//////////
		// Indicate our success or failure
		//////
			return(obj);
	}




//////////
//
// Copy the indicated object
//
//////
	SObject* iObj_copy(SObject* template_obj, SObject* next, SObject* parent, bool tlCopyChildren, bool tlCopySubobjects, bool tlCreateSeparateBitmapBuffers)
	{
		SObject* obj;


		// Create the object
		obj = (SObject*)malloc(sizeof(SObject));
		if (obj)
		{
			//////////
			// Initialize the object
			//////
				memset(obj, 0, sizeof(SObject));


			//////////
			// Populate the object
			//////
				if (template_obj)
					memcpy(obj, template_obj, sizeof(SObject));		// Copy the existing object contents


			//////////
			// Update the next and parent, and clear out any bmpScaled
			//////
				obj->ll.next	= (SLL*)next;
				obj->parent		= parent;
				obj->bmpScaled	= NULL;


			//////////
			// Copy the bitmap, subojects, and/or children (if need be)
			//////
				if (template_obj)
				{
					// Duplicate the bitmap buffer if need be
					if (tlCreateSeparateBitmapBuffers)
						obj->bmp = iBmp_copy(template_obj->bmp);

					// Copy subobject data
					if (tlCopySubobjects)
						obj->sub_obj = iObj_copySubobj(template_obj);

					// Copy children if need be
					if (tlCopyChildren && template_obj->firstChild)
						obj->firstChild = iObj_copy(template_obj->firstChild, NULL, obj, true, true, tlCreateSeparateBitmapBuffers);
				}
		}

		// Indicate our success or failure
		return(obj);
	}




//////////
//
// Delete the indicated object.
//
//////
	void iObj_delete(SObject** objRoot, bool tlDeleteSelf)
	{
		SObject* obj;


		// Make sure our environment is sane
		if (objRoot && *objRoot)
		{
			obj = *objRoot;
// TODO:  write this code
		}
	}




//////////
//
// Called to render the indicated object
//
//////
	u32 iObj_render(SObject* obj, bool tlRenderChildren, bool tlRenderSiblings)
	{
		u32 lnPixelsRendered;


		// Make sure our environment is sane
		lnPixelsRendered = 0;
		if (obj)
		{
			switch (obj->objType)
			{
				case _OBJ_TYPE_EMPTY:		// Empty, used as a placeholder object that is not drawn
					lnPixelsRendered += iSubobj_renderEmpty(obj, (SSubObjEmpty*)obj->sub_obj, tlRenderChildren, tlRenderSiblings);
					break;

				case _OBJ_TYPE_FORM:			// Form class, the main outer window the OS sees
					lnPixelsRendered += iSubobj_renderForm(obj, (SSubObjForm*)obj->sub_obj, tlRenderChildren, tlRenderSiblings);
					break;

				case _OBJ_TYPE_SUBFORM:		// A new class which has its own drawing content and can be moved about using UI features
					lnPixelsRendered += iSubobj_renderSubform(obj, (SSubObjSubform*)obj->sub_obj, tlRenderChildren, tlRenderSiblings);
					break;

				case _OBJ_TYPE_LABEL:		// A label
					lnPixelsRendered += iSubobj_renderLabel(obj, (SSubObjLabel*)obj->sub_obj, tlRenderChildren, tlRenderSiblings);
					break;

				case _OBJ_TYPE_TEXTBOX:		// An input textbox
					lnPixelsRendered += iSubobj_renderTextbox(obj, (SSubObjTextbox*)obj->sub_obj, tlRenderChildren, tlRenderSiblings);
					break;

				case _OBJ_TYPE_BUTTON:		// A push button
					lnPixelsRendered += iSubobj_renderButton(obj, (SSubObjButton*)obj->sub_obj, tlRenderChildren, tlRenderSiblings);
					break;

				case _OBJ_TYPE_EDITBOX:		// An input multi-line editbox
					lnPixelsRendered += iSubobj_renderEditbox(obj, (SSubObjEditbox*)obj->sub_obj, tlRenderChildren, tlRenderSiblings);
					break;

				case _OBJ_TYPE_IMAGE:		// A graphical image
					lnPixelsRendered += iSubobj_renderImage(obj, (SSubObjImage*)obj->sub_obj, tlRenderChildren, tlRenderSiblings);
					break;

				case _OBJ_TYPE_CHECKBOX:		// A checkbox
					lnPixelsRendered += iSubobj_renderCheckbox(obj, (SSubObjCheckbox*)obj->sub_obj, tlRenderChildren, tlRenderSiblings);
					break;

				case _OBJ_TYPE_OPTION:		// A combination selection
					lnPixelsRendered += iSubobj_renderOption(obj, (SSubObjOption*)obj->sub_obj, tlRenderChildren, tlRenderSiblings);
					break;

				case _OBJ_TYPE_RADIO:		// A radio dial, which can also present as a slider or spinner
					lnPixelsRendered += iSubobj_renderRadio(obj, (SSubObjRadio*)obj->sub_obj, tlRenderChildren, tlRenderSiblings);
					break;

				default:
// TODO:  We should never get here... we should fire off an internal consistency error
					break;
			}
		}

		// Indicate how many pixels were rendered
		return(lnPixelsRendered);
	}




//////////
//
// Called from subobjects to render any object children and sibling they may have based on flags
//
//////
	void iObj_renderChildrenAndSiblings(SObject* obj, bool tlRenderChildren, bool tlRenderSiblings)
	{
		SObject* objSib;


		//////////
		// Render any children
		//////
			if (tlRenderChildren && obj->firstChild)
				iObj_render(obj->firstChild, true, true);


		//////////
		// Render any siblings
		//////
			if (tlRenderSiblings && obj->ll.next)
			{
				objSib = (SObject*)obj->ll.next;
				while (objSib)
				{
					// Render this sibling
					iObj_render(objSib, true, true);

					// Move to next sibling
					objSib = (SObject*)objSib->ll.next;
				}
			}
	}





//////////
//
// Called to publish the indicated object, which takes the rendered bitmaps of all child objects
// and overlays them where they should be
//
//////
	u32 iObj_publish(SBitmap* bmpDst, RECT* trc, SObject* obj, bool tlPublishChildren, bool tlPublishSiblings)
	{
		u32			lnWidth, lnHeight, lnPixelsRendered;
		RECT		lrc;
		SObject*	objSib;


		//////////
		// Determine the position within the parent's rectangle where this object will go
		//////
			lnPixelsRendered = 0;
			SetRect(&lrc, trc->left + obj->rc.left, trc->top + obj->rc.top, trc->left + obj->rc.right, trc->top + obj->rc.bottom);


		//////////
		// Publish any children
		//////
			if (tlPublishChildren && obj->firstChild)
				lnPixelsRendered += iObj_publish(bmpDst, &lrc, obj->firstChild, true, true);


		//////////
		// Publish this item
		//////
			// The size of the bitmap should equal the size of the rectangle on the parent.
			lnWidth		= obj->rc.right - obj->rc.left;
			lnHeight	= obj->rc.bottom - obj->rc.top;
			// If it's different, then we need to scale the content
			if (lnWidth != obj->bmp->bi.biWidth || lnHeight != obj->bmp->bi.biHeight)
			{
				// Need to scale, but do we need to create or alter our scaled target bitmap?
				if (!obj->bmpScaled || lnWidth != obj->bmpScaled->bi.biWidth || lnHeight != obj->bmpScaled->bi.biHeight)
				{
					// Delete any existing bitmap
					iBmp_delete(&obj->bmpScaled, true, true);

					// Create the new one
					obj->bmpScaled = iBmp_allocate();
					iBmp_createBySize(obj->bmpScaled, lnWidth, lnHeight, 32);
					// Now when we scale into it, it will be the right size
				}

				// Perform the scale
				iBmp_scale(obj->bmpScaled, obj->bmp);

				// Perform the bitblt
				lnPixelsRendered += iBmp_bitBlt(bmpDst, &lrc, obj->bmpScaled);

			} else {
				// We can just copy
				lnPixelsRendered += iBmp_bitBlt(bmpDst, &lrc, obj->bmp);
			}


		//////////
		// Publish any siblings
		//////
			if (tlPublishSiblings && obj->ll.next)
			{
				// Begin at the next sibling
				objSib = (SObject*)obj->ll.next;
				while (objSib)
				{
					// Render this sibling
					lnPixelsRendered += iObj_publish(bmpDst, trc, objSib, tlPublishChildren, false);

					// Move to next sibling
					objSib = (SObject*)objSib->ll.next;
				}
			}


		//////////
		// Indicate how many pixels were painted
		//////
			return(lnPixelsRendered);
	}




//////////
//
// Duplicate the chain of ObjectLabels, so the destination has a copy of each.
//
//////
	void iObj_duplicateChain(SObject** root, SObject* chain)
	{
		SObject*		obj;
		SObject**		oPrevPtr;
		void**			objDataPtr;


		// Create the master record
		if (root)
		{
			// Repeat adding as many entries as there are
			oPrevPtr = root;
			while (chain)
			{
				// Create this object
				obj = iObj_copy(chain, NULL, chain, true, true, true);
				if (obj)
				{
					// Update the duplicate object's forward pointer in the chain
					*oPrevPtr = obj;

					// Setup the next forward pointer
					oPrevPtr = (SObject**)&obj->ll.next;

					// Get the location of our sub-object update pointer
					objDataPtr = &obj->sub_obj;

					// Copy the sub-object
					obj->sub_obj = iObj_copySubobj(chain);
				}

				// Move to next item in the chain
				chain = (SObject*)chain->ll.next;
			}
		}
	}




//////////
//
// Called to append the indicated object to the parent
//
//////
	void iObj_appendObjToParent(SObject* parent, SObject* obj)
	{
		// Make sure our environment is sane
		if (parent && obj)
			iLl_appendExistingNodeAtEnd((SLL**)&parent->firstChild, (SLL*)obj);
	}




//////////
//
// Called to duplicate the child objects to this object
//
//////
	void iObj_duplicateChildren(SObject* objDst, SObject* objSrc)
	{
		SObject*	objChild;
//		SObject*	objCopy;


		// Make sure our environment is sane
		if (objSrc && objSrc->firstChild)
		{
//_asm int 3;
			// Duplicate this entry
			objChild = objSrc->firstChild;
			while (objChild)
			{
				// Copy this item

				// Append any children here

				// Move to next
// TODO:  working here
				objChild = (SObject*)objChild->ll.next;
			}
		}
	}




//////////
//
// Called to set the object size
//
//////
	void iObj_setSize(SObject* obj, s32 tnLeft, s32 tnTop, s32 tnWidth, s32 tnHeight)
	{
		// Resize if need be
		obj->bmp = iBmp_verifySizeOrResize(obj->bmp, tnWidth, tnHeight);

		// Position and size its rectangle
		SetRect(&obj->rc, tnLeft, tnTop, tnLeft + tnWidth, tnTop + tnHeight);

		// Mark it dirty for a full re-render
		obj->isDirty = true;
	}




//////////
//
// Called to create the Windows-side window for the form.  The normal bit buffer is
// rendered regardless of whether or not the form is presented outwardly.  It can be
// used as an off-screen buffer in that way.
//
//////
	SWindow* iObj_createWindowForForm(SObject* obj_form, SWindow* win, s32 icon)
	{
		SWindow* winNew;


		// Make sure our environment is sane
		winNew = NULL;
		if (obj_form)
			winNew = iWindow_createForObject(obj_form, win, icon);

		// Indicate our status
		return(winNew);
	}




//////////
//
// Called to set the visible status of the indicated object.
// Returns the previous visible status.
//
//////
	bool iObj_setVisible(SObject* obj, bool tlNewVisible)
	{
		bool llOldVisible;


		// Make sure our environment is sane
		llOldVisible = false;
		if (obj)
		{
			llOldVisible	= obj->isVisible;
			obj->isVisible	= tlNewVisible;
		}

		// Indicate prior visible
		return(llOldVisible);
	}




//////////
//
// Called to copy the sub-object based on type
//
//////
	void* iObj_copySubobj(SObject* template_obj)
	{
		void* ptr;


		ptr = NULL;
		if (template_obj)
		{
			// Update the sub-object data
			switch (template_obj->objType)
			{
				case _OBJ_TYPE_EMPTY:		// Empty, used as a placeholder object that is not drawn
					ptr = (void*)iSubobj_createEmpty((SSubObjEmpty*)template_obj->sub_obj, template_obj);
					break;

				case _OBJ_TYPE_FORM:			// Form class, the main outer window the OS sees
					ptr = (void*)iSubobj_createForm((SSubObjForm*)template_obj->sub_obj, template_obj);
					break;

				case _OBJ_TYPE_SUBFORM:		// A new class which has its own drawing content and can be moved about using UI features
					ptr = (void*)iSubobj_createSubform((SSubObjSubform*)template_obj->sub_obj, template_obj);
					break;

				case _OBJ_TYPE_LABEL:		// A label
					ptr = (void*)iSubobj_createLabel((SSubObjLabel*)template_obj->sub_obj, template_obj);
					break;

				case _OBJ_TYPE_TEXTBOX:		// An input textbox
					ptr = (void*)iSubobj_createTextbox((SSubObjTextbox*)template_obj->sub_obj, template_obj);
					break;

				case _OBJ_TYPE_BUTTON:		// A push button
					ptr = (void*)iSubobj_createButton((SSubObjButton*)template_obj->sub_obj, template_obj);
					break;

				case _OBJ_TYPE_EDITBOX:		// An input multi-line editbox
					ptr = (void*)iSubobj_createEditbox((SSubObjEditbox*)template_obj->sub_obj, template_obj);
					break;

				case _OBJ_TYPE_IMAGE:		// A graphical image
					ptr = (void*)iSubobj_createImage((SSubObjImage*)template_obj->sub_obj, template_obj);
					break;

				case _OBJ_TYPE_CHECKBOX:		// A checkbox
					ptr = (void*)iSubobj_createCheckbox((SSubObjCheckbox*)template_obj->sub_obj, template_obj);
					break;

				case _OBJ_TYPE_OPTION:		// A combination selection
					ptr = (void*)iSubobj_createOption((SSubObjOption*)template_obj->sub_obj, template_obj);
					break;

				case _OBJ_TYPE_RADIO:		// A radio dial, which can also present as a slider or spinner
					ptr = (void*)iSubobj_createRadio((SSubObjRadio*)template_obj->sub_obj, template_obj);
					break;

				default:
// TODO:  We should never get here... we should fire off an internal consistency error
					break;
			}
		}

		// Indicate our success or failure
		return(ptr);
	}




//////////
//
// Searches the indicated object for the indicated property
//
//////
	SVariable* iObj_getPropertyAsVariable(SObject* obj, s8* tcPropertyName, u32 tnPropertyNameLength, SComp* comp)
	{
		SBaseclassList* lbcl;
		SPropertyList*	lpl;


		// Make sure our environment is sane
		if (obj)
		{
			// Find out our property interface
			lbcl = iiObj_getBaseclass_byType(obj->objType);
			if (lbcl)
			{
				// Search through the properties
				lpl = lbcl->objProps;
				while (lpl && lpl->textName)
				{
					// Is this the name?
					if (lpl->textNameLength == tnPropertyNameLength && _memicmp(tcPropertyName, lpl->textName, tnPropertyNameLength) == 0)
					{
						// This is the property, retrieve its value
						return(lpl->get(obj));
					}

					// Move to next property
					++lpl;
				}
				// If we get here, we didn't find it on the object

				// Search the sub-object
				lpl = lbcl->subobjProps;
				while (lpl && lpl->textName)
				{
					// Is this the name?
					if (lpl->textNameLength == tnPropertyNameLength && _memicmp(tcPropertyName, lpl->textName, tnPropertyNameLength) == 0)
					{
						// This is the property, retrieve its value
						return(lpl->get(obj));
					}

					// Move to next property
					++lpl;
				}
				// If we get here, it wasn't found
			}
		}
		// If we get here, wasn't found
		return(NULL);
	}




//////////
//
// Called to reset the object's properties to their default values.
// Only an internal function, and only used during initialization.
// After that the main gobj_default* objects are used for creating
// all default base class objects thereafter.
//
//////
	void iiObj_resetToDefault(SObject* obj, bool tlResetProperties, bool tlResetMethods)
	{
		// Make sure our environment is sane
		if (obj)
		{
			// Update the sub-object data
			switch (obj->objType)
			{
				case _OBJ_TYPE_EMPTY:		// Empty, used as a placeholder object that is not drawn
					iiSubobj_resetToDefaultEmpty((SSubObjEmpty*)obj->sub_obj, true, tlResetProperties, tlResetMethods);
					break;

				case _OBJ_TYPE_FORM:			// Form class, the main outer window the OS sees
					iiSubobj_resetToDefaultForm((SSubObjForm*)obj->sub_obj, true, tlResetProperties, tlResetMethods);
					break;

				case _OBJ_TYPE_SUBFORM:		// A new class which has its own drawing content and can be moved about using UI features
					iiSubobj_resetToDefaultSubform((SSubObjSubform*)obj->sub_obj, true, tlResetProperties, tlResetMethods);
					break;

				case _OBJ_TYPE_LABEL:		// A label
					iiSubobj_resetToDefaultLabel((SSubObjLabel*)obj->sub_obj, true, tlResetProperties, tlResetMethods);
					break;

				case _OBJ_TYPE_TEXTBOX:		// An input textbox
					iiSubobj_resetToDefaultTextbox((SSubObjTextbox*)obj->sub_obj, true, tlResetProperties, tlResetMethods);
					break;

				case _OBJ_TYPE_BUTTON:		// A push button
					iiSubobj_resetToDefaultButton((SSubObjButton*)obj->sub_obj, true, tlResetProperties, tlResetMethods);
					break;

				case _OBJ_TYPE_EDITBOX:		// An input multi-line editbox
					iiSubobj_resetToDefaultEditbox((SSubObjEditbox*)obj->sub_obj, true, tlResetProperties, tlResetMethods);
					break;

				case _OBJ_TYPE_IMAGE:		// A graphical image
					iiSubobj_resetToDefaultImage((SSubObjImage*)obj->sub_obj, true, tlResetProperties, tlResetMethods);
					break;

				case _OBJ_TYPE_CHECKBOX:		// A checkbox
					iiSubobj_resetToDefaultCheckbox((SSubObjCheckbox*)obj->sub_obj, true, tlResetProperties, tlResetMethods);
					break;

				case _OBJ_TYPE_OPTION:		// A combination selection
					iiSubobj_resetToDefaultOption((SSubObjOption*)obj->sub_obj, true, tlResetProperties, tlResetMethods);
					break;

				case _OBJ_TYPE_RADIO:		// A radio dial, which can also present as a slider or spinner
					iiSubobj_resetToDefaultRadio((SSubObjRadio*)obj->sub_obj, true, tlResetProperties, tlResetMethods);
					break;

				default:
// TODO:  We should never get here... we should fire off an internal consistency error
					break;
			}
		}
	}




//////////
//
// Resets common object properties to their defaults
//
//////
	void iiObj_resetToDefaultCommon(SObject* obj, bool tlResetProperties, bool tlResetMethods)
	{
		/////////
		// Information about the object itself
		//////
			obj->tabIndex					= 0;
			obj->tabStop					= true;
			obj->helpContextId				= -1;
			obj->hasWhatsThisButton			= false;
			obj->hasWhatsThisHelp			= false;
			obj->whatsThisHelpId			= -1;


		//////////
		// Clear out the comment and tag
		//////
			iDatum_delete(&obj->tag, false);


		//////////
		// Clear out the mouse information
		//////
			iBmp_delete(&obj->mouseIcon, true, true);
			obj->mousePointer				= _MOUSE_POINTER_DEFAULT;


		//////////
		// Object flags
		//////
			obj->isEnabled					= true;
			obj->hasFocus					= false;
			obj->isMovable					= true;
			obj->isRendered					= true;
			obj->isPublished				= true;
			obj->isVisible					= false;
			obj->isDirty					= true;


		//////////
		// Any properties within
		//////
			if (tlResetProperties)
				iVariable_politelyDeleteChain(&obj->firstProperty, true);


		//////////
		// Any methods defined
		//////
			if (tlResetMethods)
				iEditChainManager_deleteChain(&obj->firstMethod, true);


		//////////
		// Events
		//////
			iEvents_resetToDefault(&obj->ev);


		//////////
		// Remove any prior renderings, and reset render parameters
		//////
			iBmp_delete(&obj->bmp, true, true);
			iBmp_delete(&obj->bmpPriorRendered, true, true);
			iBmp_delete(&obj->bmpScaled, true, true);
			obj->scrollOffsetX	= 0;
			obj->scrollOffsetY	= 0;
			obj->isScaled		= false;
	}




//////////
//
// Called to translate the text-based class name to its internal object type.
//
//////
	s32 iiObj_getBaseclass_byName(s8* tcTextname, s32 tnTextnameLength)
	{
		SBaseclassList* lbcl;
		
		
		// Iterate through each function for matches
		lbcl = &gsKnownBaseclasses[0];
		while (lbcl && lbcl->textName != NULL)
		{
			// Is this the named function?
			if (lbcl->textNameLength == tnTextnameLength && _memicmp(tcTextname, (s8*)lbcl->textName, tnTextnameLength) == 0)
				return(lbcl->objType);

			// Move to next function
			++lbcl;
		}
		// If we get here, not found
		return(-1);
	}




//////////
//
// Called to translate the class object type to its text-base name
//
//////
	SBaseclassList* iiObj_getBaseclass_byType(u32 tnObjType)
	{
		SBaseclassList* lbcl;
		
		
		// Iterate through each function for matches
		lbcl = &gsKnownBaseclasses[0];
		while (lbcl && lbcl->textName != NULL)
		{
			// Is this the named function?
			if (lbcl->objType == tnObjType)
				return(lbcl);

			// Move to next function
			++lbcl;
		}
		// If we get here, not found
		return(NULL);
	}




//////////
//
// Creates the empty object structure
//
//////
	SSubObjEmpty* iSubobj_createEmpty(SSubObjEmpty* template_subobj, SObject* parent)
	{
		SSubObjEmpty* subobj;


		//////////
		// Create the indicated item
		//////
			subobj = (SSubObjEmpty*)malloc(sizeof(SSubObjEmpty));


		//////////
		// If successful, initialize it
		//////
			if (subobj)
			{
				// Initialize
				memset(subobj, 0, sizeof(SSubObjEmpty));

				// Initially populate
				subobj->parent	= parent;

				// Initialize based on template
				if (template_subobj)
				{
					// Copy from indicated template
					iiSubobj_copyEmpty(subobj, template_subobj);

				} else {
					// Use VJr defaults
					iiSubobj_resetToDefaultEmpty(subobj, true, true, true);
				}

			}


		//////////
		// Indicate our success or failure
		//////
			return(subobj);
	}




//////////
//
// Creates the form object structure
//
//////
	SSubObjForm* iSubobj_createForm(SSubObjForm* template_subobj, SObject* parent)
	{
		SSubObjForm*	subobj;
		SObject*		icon;
		SObject*		caption;
		SObject*		move;
		SObject*		minimize;
		SObject*		maximize;
		SObject*		close;


		//////////
		// Create the indicated item
		//////
			subobj = (SSubObjForm*)malloc(sizeof(SSubObjForm));


		//////////
		// If successful, initialize it
		//////
			if (subobj)
			{
				// Initialize
				memset(subobj, 0, sizeof(SSubObjForm));

				// Initially populate
				subobj->parent = parent;

				// Initialize based on template
				if (template_subobj)
				{
					// Copy from indicated template
					iiSubobj_copyForm(subobj, template_subobj);

				} else {
					// Use VJr defaults
					iiSubobj_resetToDefaultForm(subobj, true, true, true);


					//////////
					// Create the default children for this object
					//////
						icon		= iObj_create(_OBJ_TYPE_IMAGE, NULL);
						caption		= iObj_create(_OBJ_TYPE_LABEL, NULL);
						move		= iObj_create(_OBJ_TYPE_IMAGE, NULL);
						minimize	= iObj_create(_OBJ_TYPE_IMAGE, NULL);
						maximize	= iObj_create(_OBJ_TYPE_IMAGE, NULL);
						close		= iObj_create(_OBJ_TYPE_IMAGE, NULL);


					//////////
					// Give them proper names
					//////
						iDatum_duplicate(&icon->name,		cgcName_icon,			-1);
						iDatum_duplicate(&caption->name,	cgcCaption_icon,		-1);
						iDatum_duplicate(&move->name,		cgcName_iconMove,		-1);
						iDatum_duplicate(&minimize->name,	cgcName_iconMinimize,	-1);
						iDatum_duplicate(&maximize->name,	cgcName_iconMaximize,	-1);
						iDatum_duplicate(&close->name,		cgcName_iconClose,		-1);


					//////////
					// Append to the parent
					//////
						iObj_appendObjToParent(parent, icon);
						iObj_appendObjToParent(parent, caption);
						iObj_appendObjToParent(parent, move);
						iObj_appendObjToParent(parent, minimize);
						iObj_appendObjToParent(parent, maximize);
						iObj_appendObjToParent(parent, close);
				}
			}


		//////////
		// Indicate our success or failure
		//////
			return(subobj);
	}




//////////
//
// Creates the subform object structure
//
//////
	SSubObjSubform* iSubobj_createSubform(SSubObjSubform* template_subobj, SObject* parent)
	{
		SSubObjSubform* subobj;


		//////////
		// Create the indicated item
		//////
			subobj = (SSubObjSubform*)malloc(sizeof(SSubObjSubform));


		//////////
		// If successful, initialize it
		//////
			if (subobj)
			{
				// Initialize
				memset(subobj, 0, sizeof(SSubObjSubform));

				// Initially populate
				subobj->parent = parent;

				// Initialize based on template
				if (template_subobj)
				{
					// Copy from indicated template
					iiSubobj_copySubform(subobj, template_subobj);

				} else {
					// Use VJr defaults
					iiSubobj_resetToDefaultSubform(subobj, true, true, true);
				}
			}


		//////////
		// Indicate our success or failure
		//////
			return(subobj);
	}




//////////
//
// Creates the label object structure
//
//////
	SSubObjLabel* iSubobj_createLabel(SSubObjLabel* template_subobj, SObject* parent)
	{
		SSubObjLabel* subobj;


		//////////
		// Create the indicated item
		//////
			subobj = (SSubObjLabel*)malloc(sizeof(SSubObjLabel));


		//////////
		// If successful, initialize it
		//////
			if (subobj)
			{
				// Initialize
				memset(subobj, 0, sizeof(SSubObjLabel));

				// Initially populate
				subobj->parent = parent;

				// Initialize based on template
				if (template_subobj)
				{
					// Copy from indicated template
					iiSubobj_copyLabel(subobj, template_subobj);

				} else {
					// Use VJr defaults
					iiSubobj_resetToDefaultLabel(subobj, true, true, true);
				}
			}


		//////////
		// Indicate our success or failure
		//////
			return(subobj);
	}




//////////
//
// Creates the textbox object structure
//
//////
	SSubObjTextbox* iSubobj_createTextbox(SSubObjTextbox* template_subobj, SObject* parent)
	{
		SSubObjTextbox* subobj;


		//////////
		// Create the indicated item
		//////
			subobj = (SSubObjTextbox*)malloc(sizeof(SSubObjTextbox));


		//////////
		// If successful, initialize it
		//////
			if (subobj)
			{
				// Initialize
				memset(subobj, 0, sizeof(SSubObjTextbox));

				// Initially populate
				subobj->parent = parent;

				// Initialize based on template
				if (template_subobj)
				{
					// Copy from indicated template
					iiSubobj_copyTextbox(subobj, template_subobj);

				} else {
					// Use VJr defaults
					iiSubobj_resetToDefaultTextbox(subobj, true, true, true);
				}
			}


		//////////
		// Indicate our success or failure
		//////
			return(subobj);
	}




//////////
//
// Creates the button object structure
//
//////
	SSubObjButton* iSubobj_createButton(SSubObjButton* template_subobj, SObject* parent)
	{
		SSubObjButton* subobj;


		//////////
		// Create the indicated item
		//////
			subobj = (SSubObjButton*)malloc(sizeof(SSubObjButton));


		//////////
		// If successful, initialize it
		//////
			if (subobj)
			{
				// Initialize
				memset(subobj, 0, sizeof(SSubObjButton));

				// Initially populate
				subobj->parent = parent;

				// Initialize based on template
				if (template_subobj)
				{
					// Copy from indicated template
					iiSubobj_copyButton(subobj, template_subobj);

				} else {
					// Use VJr defaults
					iiSubobj_resetToDefaultButton(subobj, true, true, true);
				}
			}


		//////////
		// Indicate our success or failure
		//////
			return(subobj);
	}




//////////
//
// Creates the editbox object structure
//
//////
	SSubObjEditbox* iSubobj_createEditbox(SSubObjEditbox* template_subobj, SObject* parent)
	{
		SSubObjEditbox* subobj;


		//////////
		// Create the indicated item
		//////
			subobj = (SSubObjEditbox*)malloc(sizeof(SSubObjEditbox));


		//////////
		// If successful, initialize it
		//////
			if (subobj)
			{
				// Initialize
				memset(subobj, 0, sizeof(SSubObjEditbox));

				// Initially populate
				subobj->parent = parent;

				// Initialize based on template
				if (template_subobj)
				{
					// Copy from indicated template
					iiSubobj_copyEditbox(subobj, template_subobj);

				} else {
					// Use VJr defaults
					iiSubobj_resetToDefaultEditbox(subobj, true, true, true);
				}
			}


		//////////
		// Indicate our success or failure
		//////
			return(subobj);
	}




//////////
//
// Creates the image object structure
//
//////
	SSubObjImage* iSubobj_createImage(SSubObjImage* template_subobj, SObject* parent)
	{
		SSubObjImage* subobj;


		//////////
		// Create the indicated item
		//////
			subobj = (SSubObjImage*)malloc(sizeof(SSubObjImage));


		//////////
		// If successful, initialize it
		//////
			if (subobj)
			{
				// Initialize
				memset(subobj, 0, sizeof(SSubObjImage));

				// Initially populate
				subobj->parent = parent;

				// Initialize based on template
				if (template_subobj)
				{
					// Copy from indicated template
					iiSubobj_copyImage(subobj, template_subobj);

				} else {
					// Use VJr defaults
					iiSubobj_resetToDefaultImage(subobj, true, true, true);
				}
			}


		//////////
		// Indicate our success or failure
		//////
			return(subobj);
	}




//////////
//
// Creates the checkbox object structure
//
//////
	SSubObjCheckbox* iSubobj_createCheckbox(SSubObjCheckbox* template_subobj, SObject* parent)
	{
		SSubObjCheckbox* subobj;


		//////////
		// Create the indicated item
		//////
			subobj = (SSubObjCheckbox*)malloc(sizeof(SSubObjCheckbox));


		//////////
		// If successful, initialize it
		//////
			if (subobj)
			{
				// Initialize
				memset(subobj, 0, sizeof(SSubObjCheckbox));

				// Initially populate
				subobj->parent = parent;

				// Initialize based on template
				if (template_subobj)
				{
					// Copy from indicated template
					iiSubobj_copyCheckbox(subobj, template_subobj);

				} else {
					// Use VJr defaults
					iiSubobj_resetToDefaultCheckbox(subobj, true, true, true);
				}
			}


		//////////
		// Indicate our success or failure
		//////
			return(subobj);
	}




//////////
//
// Creates the combo object structure
//
//////
	SSubObjOption* iSubobj_createOption(SSubObjOption* template_subobj, SObject* parent)
	{
		SSubObjOption* subobj;


		//////////
		// Create the indicated item
		//////
			subobj = (SSubObjOption*)malloc(sizeof(SSubObjOption));


		//////////
		// If successful, initialize it
		//////
			if (subobj)
			{
				// Initialize
				memset(subobj, 0, sizeof(SSubObjOption));

				// Initially populate
				subobj->parent = parent;

				// Initialize based on template
				if (template_subobj)
				{
					// Copy from indicated template
					iiSubobj_copyOption(subobj, template_subobj);

				} else {
					// Use VJr defaults
					iiSubobj_resetToDefaultOption(subobj, true, true, true);
				}
			}


		//////////
		// Indicate our success or failure
		//////
			return(subobj);
	}




//////////
//
// Creates the radio object structure
//
//////
	SSubObjRadio* iSubobj_createRadio(SSubObjRadio* template_subobj, SObject* parent)
	{
		SSubObjRadio* subobj;


		//////////
		// Create the indicated item
		//////
			subobj = (SSubObjRadio*)malloc(sizeof(SSubObjRadio));


		//////////
		// If successful, initialize it
		//////
			if (subobj)
			{
				// Initialize
				memset(subobj, 0, sizeof(SSubObjRadio));

				// Initially populate
				subobj->parent = parent;

				// Initialize based on template
				if (template_subobj)
				{
					// Copy from indicated template
					iiSubobj_copyRadio(subobj, template_subobj);

				} else {
					// Use VJr defaults
					iiSubobj_resetToDefaultRadio(subobj, true, true, true);
				}
			}


		//////////
		// Indicate our success or failure
		//////
			return(subobj);
	}




//////////
//
// Called to copy the indicated empty from source to destination
//
//////
	void iiSubobj_copyEmpty(SSubObjEmpty* subobjDst, SSubObjEmpty* subobjSrc)
	{
		//////////
		// Duplicate all children for this object
		//////
			iObj_duplicateChildren(subobjDst->parent, subobjSrc->parent);
	}




//////////
//
// Called to copy the indicated form from source to destination
//
//////
	void iiSubobj_copyForm(SSubObjForm* subobjDst, SSubObjForm* subobjSrc)
	{
		//////////
		// Copy our min/max
		//////
			CopyRect(&subobjDst->rcMax, &subobjSrc->rcMax);
			CopyRect(&subobjDst->rcMin, &subobjSrc->rcMin);


		//////////
		// Copy the font
		//////
			subobjDst->font						= iFont_duplicate(subobjSrc->font);


		//////////
		// Copy the colors
		//////
			subobjDst->nwRgba.color				= subobjSrc->nwRgba.color;
			subobjDst->neRgba.color				= subobjSrc->neRgba.color;
			subobjDst->swRgba.color				= subobjSrc->swRgba.color;
			subobjDst->seRgba.color				= subobjSrc->seRgba.color;
			subobjDst->backColor.color			= subobjSrc->backColor.color;
			subobjDst->foreColor.color			= subobjSrc->foreColor.color;
			subobjDst->captionColor.color		= subobjSrc->captionColor.color;


		//////////
		// Copy the form icon
		//////
			subobjDst->bmpFormIcon				= iBmp_copy(subobjSrc->bmpFormIcon);
			iDatum_duplicate(&subobjDst->caption, &subobjSrc->caption);


		//////////
		// Copy the caption
		//////
			iDatum_duplicate(&subobjDst->caption, &subobjSrc->caption);


		//////////
		// Copy the picture
		//////
			iBmp_delete(&subobjDst->bmpPicture, true, true);
			subobjDst->bmpPicture = iBmp_copy(subobjSrc->bmpPicture);
			iDatum_duplicate(&subobjDst->pictureName, &subobjSrc->pictureName);


		//////////
		// General flags and settings
		//////
			subobjDst->allowOutput				= subobjSrc->allowOutput;
			subobjDst->alwaysOnBottom			= subobjSrc->alwaysOnBottom;
			subobjDst->alwaysOnTop				= subobjSrc->alwaysOnTop;
			subobjDst->autoCenter				= subobjSrc->autoCenter;
			subobjDst->borderStyle				= subobjSrc->borderStyle;
			subobjDst->isClosable				= subobjSrc->isClosable;
			subobjDst->processKeyPreviewEvents	= subobjSrc->processKeyPreviewEvents;
			subobjDst->hasControlBox			= subobjSrc->hasControlBox;
			subobjDst->hasMinButton				= subobjSrc->hasMinButton;
			subobjDst->hasMaxButton				= subobjSrc->hasMaxButton;
			subobjDst->hasCloseButton			= subobjSrc->hasCloseButton;
			subobjDst->scaleMode				= subobjSrc->scaleMode;
			subobjDst->showInTaskBar			= subobjSrc->showInTaskBar;
			subobjDst->windowState				= subobjSrc->windowState;

			// The following are ignored, maintained only for backward compatibility
			subobjDst->bindControls				= subobjSrc->bindControls;
			subobjDst->bufferMode				= subobjSrc->bufferMode;
			subobjDst->clipControls				= subobjSrc->clipControls;
			subobjDst->colorSource				= subobjSrc->colorSource;
			subobjDst->continuousScroll			= subobjSrc->continuousScroll;
			iObj_delete(&subobjDst->dataSession, true);
			subobjDst->dataSessionId			= subobjSrc->dataSessionId;
			iDatum_duplicate(&subobjDst->declass,			&subobjSrc->declass);
			iDatum_duplicate(&subobjDst->declasslibrary,	&subobjSrc->declasslibrary);
			subobjDst->defolecid				= subobjSrc->defolecid;
			subobjDst->desktop					= subobjSrc->desktop;
			subobjDst->isDockable				= subobjSrc->isDockable;
			subobjDst->isDocked					= subobjSrc->isDocked;
			subobjDst->dockPosition				= subobjSrc->dockPosition;
			subobjDst->drawmode					= subobjSrc->drawmode;
			subobjDst->drawstyle				= subobjSrc->drawstyle;
			subobjDst->drawwidth				= subobjSrc->drawwidth;
			subobjDst->fillColor.color			= subobjSrc->fillColor.color;
			subobjDst->fillStyle				= subobjSrc->fillStyle;
			subobjDst->halfHeightCaption		= subobjSrc->halfHeightCaption;
			subobjDst->hScrollSmallChange		= subobjSrc->hScrollSmallChange;
			subobjDst->vScrollSmallChange		= subobjSrc->vScrollSmallChange;
			subobjDst->macDesktop				= subobjSrc->macDesktop;
			subobjDst->mdiForm					= subobjSrc->mdiForm;
			subobjDst->oleDragMode				= subobjSrc->oleDragMode;
			iBmp_delete(&subobjDst->oleDragPicture, true, true);
			subobjDst->oleDragPicture			= iBmp_copy(subobjSrc->oleDragPicture);
			subobjDst->oleDropEffects			= subobjSrc->oleDropEffects;
			subobjDst->oleDropHasData			= subobjSrc->oleDropHasData;
			subobjDst->oleDropMode				= subobjSrc->oleDropMode;
			subobjDst->releaseType				= subobjSrc->releaseType;
			subobjDst->rightToLeft				= subobjSrc->rightToLeft;
			subobjDst->scrollbars				= subobjSrc->scrollbars;
			subobjDst->showTips					= subobjSrc->showTips;
			subobjDst->showWindow				= subobjSrc->showWindow;
			subobjDst->sizeBox					= subobjSrc->sizeBox;
			subobjDst->themes					= subobjSrc->themes;
			subobjDst->titleBar					= subobjSrc->titleBar;
			subobjDst->windowType				= subobjSrc->windowType;
			subobjDst->zoomBox					= subobjSrc->zoomBox;


		//////////
		// Copy the form-specific event handlers
		//////
			*(u32*)&subobjDst->activate			= (u32)&subobjSrc->activate;
			*(u32*)&subobjDst->deactivate		= (u32)&subobjSrc->deactivate;


		//////////
		// Duplicate all children for this object
		//////
			iObj_duplicateChildren(subobjDst->parent, subobjSrc->parent);
	}




//////////
//
// Called to copy the indicated empty subfrom source to destination
//
//////
	void iiSubobj_copySubform(SSubObjSubform* subobjDst, SSubObjSubform* subobjSrc)
	{
		//////////
		// Copy our min/max
		//////
			CopyRect(&subobjDst->rcMax, &subobjSrc->rcMax);
			CopyRect(&subobjDst->rcMin, &subobjSrc->rcMin);


		//////////
		// Copy the font
		//////
			subobjDst->font						= iFont_duplicate(subobjSrc->font);


		//////////
		// Copy the colors
		//////
			subobjDst->nwRgba.color				= subobjSrc->nwRgba.color;
			subobjDst->neRgba.color				= subobjSrc->neRgba.color;
			subobjDst->swRgba.color				= subobjSrc->swRgba.color;
			subobjDst->seRgba.color				= subobjSrc->seRgba.color;
			subobjDst->backColor.color			= subobjSrc->backColor.color;
			subobjDst->foreColor.color			= subobjSrc->foreColor.color;
			subobjDst->captionColor.color		= subobjSrc->captionColor.color;


		//////////
		// Copy the form icon
		//////
			subobjDst->bmpFormIcon				= iBmp_copy(subobjSrc->bmpFormIcon);
			iDatum_duplicate(&subobjDst->caption, &subobjSrc->caption);


		//////////
		// Copy the caption
		//////
			iDatum_duplicate(&subobjDst->caption, &subobjSrc->caption);


		//////////
		// Copy the picture
		//////
			iBmp_delete(&subobjDst->bmpPicture, true, true);
			subobjDst->bmpPicture = iBmp_copy(subobjSrc->bmpPicture);
			iDatum_duplicate(&subobjDst->pictureName, &subobjSrc->pictureName);


		//////////
		// General flags and settings
		//////
			subobjDst->allowOutput				= subobjSrc->allowOutput;
			subobjDst->borderStyle				= subobjSrc->borderStyle;
			subobjDst->processKeyPreviewEvents	= subobjSrc->processKeyPreviewEvents;
			subobjDst->scaleMode				= subobjSrc->scaleMode;
			subobjDst->windowState				= subobjSrc->windowState;


		//////////
		// Copy the subform-specific event handlers
		//////
			*(u32*)&subobjDst->activate			= (u32)&subobjSrc->activate;
			*(u32*)&subobjDst->deactivate		= (u32)&subobjSrc->deactivate;


		//////////
		// Duplicate all children for this object
		//////
			iObj_duplicateChildren(subobjDst->parent, subobjSrc->parent);
	}




//////////
//
// Called to copy the indicated label from source to destination
//
//////
	void iiSubobj_copyLabel(SSubObjLabel* subobjDst, SSubObjLabel* subobjSrc)
	{
		//////////
		// Copy the font
		//////
			subobjDst->font						= iFont_duplicate(subobjSrc->font);


		//////////
		// Copy the colors
		//////
			subobjDst->backColor.color			= subobjSrc->backColor.color;
			subobjDst->foreColor.color			= subobjSrc->foreColor.color;


		//////////
		// Copy the caption
		//////
			iDatum_duplicate(&subobjDst->caption, &subobjSrc->caption);


		//////////
		// General settings
		//////
			subobjDst->alignment					= subobjSrc->alignment;
			subobjDst->isOpaque						= subobjSrc->isOpaque;
			subobjDst->isBorder						= subobjSrc->isBorder;
			subobjDst->borderColor.color			= subobjSrc->borderColor.color;
			subobjDst->disabledBackColor.color		= subobjSrc->disabledBackColor.color;
			subobjDst->disabledForeColor.color		= subobjSrc->disabledForeColor.color;


		//////////
		// Duplicate all children for this object
		//////
			iObj_duplicateChildren(subobjDst->parent, subobjSrc->parent);
	}




//////////
//
// Called to copy the indicated textbox from source to destination
//
//////
	void iiSubobj_copyTextbox(SSubObjTextbox* subobjDst, SSubObjTextbox* subobjSrc)
	{
		//////////
		// Copy the font
		//////
			subobjDst->font						= iFont_duplicate(subobjSrc->font);


		//////////
		// Copy the colors
		//////
			subobjDst->backColor.color			= subobjSrc->backColor.color;
			subobjDst->foreColor.color			= subobjSrc->foreColor.color;


		//////////
		// General settings
		//////
			subobjDst->style						= subobjSrc->style;
			subobjDst->alignment					= subobjSrc->alignment;
			iDatum_duplicate(&subobjDst->value,		&subobjSrc->value);
			subobjDst->valueLength					= subobjSrc->valueLength;
			iDatum_duplicate(&subobjDst->picture,	&subobjSrc->picture);
			iDatum_duplicate(&subobjDst->mask,		&subobjSrc->mask);
			subobjDst->isOpaque						= subobjSrc->isOpaque;
			subobjDst->isBorder						= subobjSrc->isBorder;
			subobjDst->borderColor.color			= subobjSrc->borderColor.color;
			subobjDst->selectedBackColor.color		= subobjSrc->selectedBackColor.color;
			subobjDst->selectedForeColor.color		= subobjSrc->selectedForeColor.color;
			subobjDst->disabledBackColor.color		= subobjSrc->disabledBackColor.color;
			subobjDst->disabledForeColor.color		= subobjSrc->disabledForeColor.color;


		//////////
		// Editor settings
		//////
			subobjDst->cursor						= subobjSrc->cursor;
			subobjDst->selectStart					= subobjSrc->selectStart;
			subobjDst->selectEnd					= subobjSrc->selectEnd;


		//////////
		// Copy the textbox-specific event handlers
		//////
			*(u32*)&subobjDst->interactiveChange	= *(u32*)&subobjSrc->interactiveChange;
			*(u32*)&subobjDst->programmaticChange	= *(u32*)&subobjSrc->programmaticChange;


		//////////
		// Duplicate all children for this object
		//////
			iObj_duplicateChildren(subobjDst->parent, subobjSrc->parent);
	}




//////////
//
// Called to copy the indicated button from source to destination
//
//////
	void iiSubobj_copyButton(SSubObjButton* subobjDst, SSubObjButton* subobjSrc)
	{
		//////////
		// Copy the font
		//////
			subobjDst->font						= iFont_duplicate(subobjSrc->font);


		//////////
		// Copy the colors
		//////
			subobjDst->backColor.color			= subobjSrc->backColor.color;
			subobjDst->foreColor.color			= subobjSrc->foreColor.color;


		//////////
		// General settings
		//////
			subobjDst->style						= subobjSrc->style;
			subobjDst->alignment					= subobjSrc->alignment;
			iDatum_duplicate(&subobjDst->caption,	&subobjSrc->caption);
			subobjDst->disabledBackColor.color		= subobjSrc->disabledBackColor.color;
			subobjDst->disabledForeColor.color		= subobjSrc->disabledForeColor.color;


		//////////
		// Copy the button-specific event handlers
		//////
			*(u32*)&subobjDst->interactiveChange	= *(u32*)&subobjSrc->interactiveChange;
			*(u32*)&subobjDst->programmaticChange	= *(u32*)&subobjSrc->programmaticChange;


		//////////
		// Duplicate all children for this object
		//////
			iObj_duplicateChildren(subobjDst->parent, subobjSrc->parent);
	}




//////////
//
// Called to copy the indicated editbox from source to destination
//
//////
	void iiSubobj_copyEditbox(SSubObjEditbox* subobjDst, SSubObjEditbox* subobjSrc)
	{
		//////////
		// Copy the font
		//////
			subobjDst->font						= iFont_duplicate(subobjSrc->font);


		//////////
		// Copy the colors
		//////
			subobjDst->backColor.color			= subobjSrc->backColor.color;
			subobjDst->foreColor.color			= subobjSrc->foreColor.color;


		//////////
		// General settings
		//////
			subobjDst->style						= subobjSrc->style;
			subobjDst->alignment					= subobjSrc->alignment;
			iEditChainManager_duplicate(&subobjDst->codeBlock, subobjSrc->codeBlock, true);
			subobjDst->isOpaque						= subobjSrc->isOpaque;
			subobjDst->isBorder						= subobjSrc->isBorder;
			subobjDst->borderColor.color			= subobjSrc->borderColor.color;
			subobjDst->selectedBackColor.color		= subobjSrc->selectedBackColor.color;
			subobjDst->selectedForeColor.color		= subobjSrc->selectedForeColor.color;
			subobjDst->disabledBackColor.color		= subobjSrc->disabledBackColor.color;
			subobjDst->disabledForeColor.color		= subobjSrc->disabledForeColor.color;


		//////////
		// Editor settings
		//////
			subobjDst->cursor						= subobjSrc->cursor;
			subobjDst->selectStart					= subobjSrc->selectStart;
			subobjDst->selectEnd					= subobjSrc->selectEnd;


		//////////
		// Copy the editbox-specific event handlers
		//////
			*(u32*)&subobjDst->interactiveChange	= *(u32*)&subobjSrc->interactiveChange;
			*(u32*)&subobjDst->programmaticChange	= *(u32*)&subobjSrc->programmaticChange;


		//////////
		// Duplicate all children for this object
		//////
			iObj_duplicateChildren(subobjDst->parent, subobjSrc->parent);
	}




//////////
//
// Called to copy the indicated image from source to destination
//
//////
	void iiSubobj_copyImage(SSubObjImage* subobjDst, SSubObjImage* subobjSrc)
	{
		//////////
		// General settings
		//////
			subobjDst->style						= subobjSrc->style;
			subobjDst->image						= iBmp_copy(subobjSrc->image);
			subobjDst->imageOver					= iBmp_copy(subobjSrc->imageOver);


		//////////
		// Copy the editbox-specific event handlers
		//////
			*(u32*)&subobjDst->programmaticChange	= *(u32*)&subobjSrc->programmaticChange;


		//////////
		// Duplicate all children for this object
		//////
			iObj_duplicateChildren(subobjDst->parent, subobjSrc->parent);
	}




//////////
//
// Called to copy the indicated checkbox from source to destination
//
//////
	void iiSubobj_copyCheckbox(SSubObjCheckbox* subobjDst, SSubObjCheckbox* subobjSrc)
	{
		//////////
		// Copy the font
		//////
			subobjDst->font						= iFont_duplicate(subobjSrc->font);


		//////////
		// Copy the colors
		//////
			subobjDst->backColor.color			= subobjSrc->backColor.color;
			subobjDst->foreColor.color			= subobjSrc->foreColor.color;


		//////////
		// General settings
		//////
			subobjDst->alignment					= subobjSrc->alignment;
			subobjDst->style						= subobjSrc->style;
			subobjDst->value						= subobjSrc->value;
			iDatum_duplicate(&subobjDst->caption,	&subobjSrc->caption);
			subobjDst->isOpaque						= subobjSrc->isOpaque;
			subobjDst->isBorder						= subobjSrc->isBorder;
			subobjDst->borderColor.color			= subobjSrc->borderColor.color;
			subobjDst->disabledBackColor.color		= subobjSrc->disabledBackColor.color;
			subobjDst->disabledForeColor.color		= subobjSrc->disabledForeColor.color;


		//////////
		// Copy the checkbox-specific event handlers
		//////
			*(u32*)&subobjDst->interactiveChange	= *(u32*)&subobjSrc->interactiveChange;
			*(u32*)&subobjDst->programmaticChange	= *(u32*)&subobjSrc->programmaticChange;


		//////////
		// Duplicate all children for this object
		//////
			iObj_duplicateChildren(subobjDst->parent, subobjSrc->parent);
	}




//////////
//
// Called to copy the indicated option from source to destination
//
//////
	void iiSubobj_copyOption(SSubObjOption* subobjDst, SSubObjOption* subobjSrc)
	{
		//////////
		// Copy the colors
		//////
			subobjDst->backColor.color			= subobjSrc->backColor.color;
			subobjDst->foreColor.color			= subobjSrc->foreColor.color;


		//////////
		// General settings
		//////
			subobjDst->alignment					= subobjSrc->alignment;
			subobjDst->style						= subobjSrc->style;
			subobjDst->optionCount					= subobjSrc->optionCount;		// How many options are there?
			subobjDst->multiSelect					= subobjSrc->multiSelect;		// Can multiple items be selected?


		//////////
		// Copy the label objects
		//////
			iObj_duplicateChain(&subobjDst->firstOption, subobjSrc->firstOption);	// Each option has its own set of properties, and each is of _OBJECT_TYPE_LABEL


		//////////
		// Copy the option-specific event handlers
		//////
			*(u32*)&subobjDst->onSelect				= *(u32*)&subobjSrc->onSelect;
			*(u32*)&subobjDst->onDeselect			= *(u32*)&subobjSrc->onDeselect;
			*(u32*)&subobjDst->interactiveChange	= *(u32*)&subobjSrc->interactiveChange;
			*(u32*)&subobjDst->programmaticChange	= *(u32*)&subobjSrc->programmaticChange;


		//////////
		// Duplicate all children for this object
		//////
			iObj_duplicateChildren(subobjDst->parent, subobjSrc->parent);
	}




//////////
//
// Called to copy the indicated radio from source to destination
//
//////
	void iiSubobj_copyRadio(SSubObjRadio* subobjDst, SSubObjRadio* subobjSrc)
	{
		//////////
		// Copy the font
		//////
			subobjDst->font						= iFont_duplicate(subobjSrc->font);


		//////////
		// Copy the colors
		//////
			subobjDst->backColor.color			= subobjSrc->backColor.color;
			subobjDst->foreColor.color			= subobjSrc->foreColor.color;


		//////////
		// General settings
		//////
			subobjDst->alignment					= subobjSrc->alignment;
			subobjDst->style						= subobjSrc->style;
			subobjDst->value						= subobjSrc->value;
			subobjDst->minValue						= subobjSrc->minValue;
			subobjDst->maxValue						= subobjSrc->maxValue;
			subobjDst->roundTo						= subobjSrc->roundTo;
			subobjDst->isOpaque						= subobjSrc->isOpaque;
			subobjDst->isBorder						= subobjSrc->isBorder;
			subobjDst->borderColor.color			= subobjSrc->borderColor.color;
			subobjDst->disabledBackColor.color		= subobjSrc->disabledBackColor.color;
			subobjDst->disabledForeColor.color		= subobjSrc->disabledForeColor.color;


		//////////
		// Copy the option-specific event handlers
		//////
			*(u32*)&subobjDst->interactiveChange	= *(u32*)&subobjSrc->interactiveChange;
			*(u32*)&subobjDst->programmaticChange	= *(u32*)&subobjSrc->programmaticChange;


		//////////
		// Duplicate all children for this object
		//////
			iObj_duplicateChildren(subobjDst->parent, subobjSrc->parent);
	}




//////////
//
// Called to reset the object to its hard defaults.
//
//////
	void iiSubobj_resetToDefaultEmpty(SSubObjEmpty* empty, bool tlResetObject, bool tlResetProperties, bool tlResetMethods)
	{
		SObject* obj;


		// Do we need to reset the object as well (Note that subobj->parent is the obj here)
		obj = empty->parent;
		if (obj && tlResetObject)
		{
			//////////
			// Reset the common settings
			//////
				iiObj_resetToDefaultCommon(obj, true, true);
		}

		// No object-specific initialization because empty objects do nothing except exist as placeholders
	}

	void iiSubobj_resetToDefaultForm(SSubObjForm* form, bool tlResetObject, bool tlResetProperties, bool tlResetMethods)
	{
		SObject* obj;


		// Do we need to reset the object as well (Note that subobj->parent is the obj here)
		obj = form->parent;
		if (obj && tlResetObject)
		{
			//////////
			// Reset the common settings
			//////
				iiObj_resetToDefaultCommon(obj, true, true);


			//////////
			// Set default size and position
			//////
				SetRect(&obj->rc, 0, 0, 375, 250);
				SetRect(&obj->rco, 0, 0, 375, 250);
				SetRect(&obj->rcp, 0, 0, 375, 250);


			//////////
			// Set default anchor to fixed in all positions, no resize
			//////
				obj->anchor = _ANCHOR_FIXED_NORESIZE;
		}

		//////////
		// Set the default font
		//////
			iFont_delete(&form->font, true);
			form->font					= iFont_duplicate(gsFont);


		//////////
		// Set the default colors
		//////
			form->nwRgba.color			= NwColor.color;
			form->neRgba.color			= NeColor.color;
			form->swRgba.color			= SwColor.color;
			form->seRgba.color			= SeColor.color;
			form->backColor.color		= white.color;
			form->foreColor.color		= black.color;
			form->captionColor.color	= dark_blue.color;


		//////////
		// Set the default form icon
		//////
			iBmp_delete(&form->bmpFormIcon, true, true);
			form->bmpFormIcon			= iBmp_copy(bmpVjrIcon);


		//////////
		// Set the default caption
		//////
			iDatum_duplicate(&form->caption, cgcName_form, -1);


		//////////
		// Set the default form-specific events
		//////
			*(u32*)&form->activate		= (u32)&iDefaultCallback_onActivate;
			*(u32*)&form->deactivate	= (u32)&iDefaultCallback_onDeactivate;


		//////////
		// Reset our min/max
		//////
			SetRect(&form->rcMax, -1, -1, -1, -1);
			SetRect(&form->rcMin, -1, -1, -1, -1);


		//////////
		// Clear the picture
		//////
			iBmp_delete(&form->bmpPicture, true, true);


		//////////
		// General flags and settings
		//////
			form->allowOutput						= true;
			form->alwaysOnBottom					= false;
			form->alwaysOnTop						= false;
			form->autoCenter						= false;
			form->borderStyle						= _BORDER_STYLE_SIZABLE;
			form->isClosable						= true;
			form->processKeyPreviewEvents			= false;
			form->hasControlBox						= true;
			form->hasMinButton						= true;
			form->hasMaxButton						= true;
			form->hasCloseButton					= true;
			form->scaleMode							= _SCALE_MODE_PIXELS;
			form->showInTaskBar						= true;
			form->windowState						= _WINDOW_STATE_NORMAL;

			// The following are ignored, maintained only for backward compatibility
			form->bindControls						= true;
			form->bufferMode						= 2;
			form->clipControls						= false;
			form->colorSource						= 4;
			form->continuousScroll					= true;
			iObj_delete(&form->dataSession, true);
			form->dataSessionId						= -1;
			iDatum_delete(&form->declass, false);
			iDatum_delete(&form->declasslibrary, false);
			form->defolecid							= -1;
			form->desktop							= false;
			form->isDockable						= false;
			form->isDocked							= false;
			form->dockPosition						= -1;
			form->drawmode							= -1;
			form->drawstyle							= 13;
			form->drawwidth							= 1;
			form->fillColor.color					= rgba(255,255,255,255);
			form->fillStyle							= 0;
			form->halfHeightCaption					= false;
			form->hScrollSmallChange				= 10;
			form->vScrollSmallChange				= 10;
			form->macDesktop						= false;
			form->mdiForm							= false;
			form->oleDragMode						= 0;
			iBmp_delete(&form->oleDragPicture, true, true);
			form->oleDropEffects					= 3;
			form->oleDropHasData					= -1;
			form->oleDropMode						= 0;
			form->releaseType						= 0;
			form->rightToLeft						= false;
			form->scrollbars						= 3;
			form->showTips							= true;
			form->showWindow						= 2;
			form->sizeBox							= false;
			form->themes							= true;
			form->titleBar							= 1;
			form->windowType						= 0;
			form->zoomBox							= false;
	}

	void iiSubobj_resetToDefaultSubform(SSubObjSubform* subform, bool tlResetObject, bool tlResetProperties, bool tlResetMethods)
	{
		SObject* obj;


		// Do we need to reset the object as well (Note that subobj->parent is the obj here)
		obj = subform->parent;
		if (tlResetObject)
		{
			//////////
			// Reset the common settings
			//////
				iiObj_resetToDefaultCommon(obj, true, true);


			//////////
			// Set default size and position
			//////
				SetRect(&obj->rc, 0, 0, 275, 150);
				SetRect(&obj->rco, 0, 0, 275, 150);
				SetRect(&obj->rcp, 0, 0, 275, 150);


			//////////
			// Set default anchor to fixed in all positions, no resize
			//////
				obj->anchor = _ANCHOR_FIXED_NORESIZE;
		}


		//////////
		// Set the default font
		//////
			iFont_delete(&subform->font, true);
			subform->font					= iFont_duplicate(gsFont);


		//////////
		// Set the default colors
		//////
			subform->nwRgba.color			= NwColor.color;
			subform->neRgba.color			= NeColor.color;
			subform->swRgba.color			= SwColor.color;
			subform->seRgba.color			= SeColor.color;
			subform->backColor.color		= white.color;
			subform->foreColor.color		= black.color;
			subform->captionColor.color		= dark_blue.color;


		//////////
		// Set the default form icon
		//////
			iBmp_delete(&subform->bmpFormIcon, true, true);
			subform->bmpFormIcon			= iBmp_copy(bmpVjrIcon);


		//////////
		// Set the default caption
		//////
			iDatum_duplicate(&subform->caption, cgcName_subform, -1);


		//////////
		// Set the default form-specific events
		//////
			*(u32*)&subform->activate		= (u32)&iDefaultCallback_onActivate;
			*(u32*)&subform->deactivate		= (u32)&iDefaultCallback_onDeactivate;
	}

	void iiSubobj_resetToDefaultLabel(SSubObjLabel* label, bool tlResetObject, bool tlResetProperties, bool tlResetMethods)
	{
		u32			lnHeight;
		SObject*	obj;


		// Do we need to reset the object as well (Note that subobj->parent is the obj here)
		obj = label->parent;
		if (tlResetObject)
		{
			//////////
			// Reset the common settings
			//////
				iiObj_resetToDefaultCommon(obj, true, true);


			//////////
			// Set default size and position
			//////
				lnHeight = max(gsFont->tm.tmHeight + 2, 10);
				SetRect(&obj->rc, 0, 0, 275, lnHeight);
				SetRect(&obj->rco, 0, 0, 275, lnHeight);
				SetRect(&obj->rcp, 0, 0, 275, lnHeight);


			//////////
			// Set default anchor to fixed in all positions, no resize
			//////
				obj->anchor = _ANCHOR_FIXED_NORESIZE;
		}


		//////////
		// Set the default font
		//////
			iFont_delete(&label->font, true);
			label->font							= iFont_duplicate(gsFont);


		//////////
		// Set the default colors
		//////
			label->backColor.color				= white.color;
			label->foreColor.color				= black.color;


		//////////
		// Set the characteristics
		//////
			label->alignment					= _ALIGNMENT_LEFT;
			iDatum_duplicate(&label->caption, cgcName_label, 5);
			label->isOpaque						= true;
			label->isBorder						= false;
			label->borderColor.color			= black.color;
			label->disabledBackColor.color		= disabledBackColor.color;
			label->disabledForeColor.color		= disabledForeColor.color;
	}

	void iiSubobj_resetToDefaultTextbox(SSubObjTextbox* textbox, bool tlResetObject, bool tlResetProperties, bool tlResetMethods)
	{
		SObject* obj;


		// Do we need to reset the object as well (Note that subobj->parent is the obj here)
		obj = textbox->parent;
		if (tlResetObject)
		{
			//////////
			// Reset the common settings
			//////
				iiObj_resetToDefaultCommon(obj, true, true);


			//////////
			// Set default size and position
			//////
				SetRect(&obj->rc, 0, 0, 100, 75);
				SetRect(&obj->rco, 0, 0, 100, 75);
				SetRect(&obj->rcp, 0, 0, 100, 75);


			//////////
			// Set default anchor to fixed in all positions, no resize
			//////
				obj->anchor = _ANCHOR_FIXED_NORESIZE;
		}


		//////////
		// Set the default font
		//////
			iFont_delete(&textbox->font, true);
			textbox->font						= iFont_duplicate(gsFont);


		//////////
		// Set the default colors
		//////
			textbox->backColor.color			= white.color;
			textbox->foreColor.color			= black.color;


		//////////
		// Set the characteristics
		//////
			textbox->style						= _STYLE_3D;
			textbox->alignment					= _ALIGNMENT_LEFT;
			textbox->valueLength				= 0;

			textbox->cursor						= 0;
			textbox->selectStart				= -1;
			textbox->selectEnd					= -1;

			textbox->isOpaque					= true;
			textbox->isBorder					= false;
			textbox->borderColor.color			= black.color;
			textbox->selectedBackColor.color	= selectedBackColor.color;
			textbox->selectedForeColor.color	= selectedForeColor.color;
			textbox->disabledBackColor.color	= disabledBackColor.color;
			textbox->disabledForeColor.color	= disabledForeColor.color;


		//////////
		// Indicate the callback handler
		//////
			*(u32*)&textbox->interactiveChange	= *(u32*)&iDefaultCallback_onInteractiveChange;
			*(u32*)&textbox->programmaticChange	= *(u32*)&iDefaultCallback_onProgrammaticChange;
	}

	void iiSubobj_resetToDefaultButton(SSubObjButton* button, bool tlResetObject, bool tlResetProperties, bool tlResetMethods)
	{
		SObject* obj;


		// Do we need to reset the object as well (Note that subobj->parent is the obj here)
		obj = button->parent;
		if (tlResetObject)
		{
			button->font						= iFont_duplicate(gsFont);
			button->backColor.color				= white.color;
			button->foreColor.color				= black.color;

			button->style						= _STYLE_3D;
			button->alignment					= _ALIGNMENT_LEFT;
			iDatum_duplicate(&button->caption,	"Button", 6);

			button->disabledBackColor.color		= disabledBackColor.color;
			button->disabledForeColor.color		= disabledForeColor.color;

			*(u32*)&button->interactiveChange	= *(u32*)&iDefaultCallback_onInteractiveChange;
			*(u32*)&button->programmaticChange	= *(u32*)&iDefaultCallback_onProgrammaticChange;
		}
	}

	void iiSubobj_resetToDefaultEditbox(SSubObjEditbox* editbox, bool tlResetObject, bool tlResetProperties, bool tlResetMethods)
	{
		SObject* obj;


		// Do we need to reset the object as well (Note that subobj->parent is the obj here)
		obj = editbox->parent;
		if (tlResetObject)
		{
			editbox->font							= iFont_duplicate(gsFont);
			editbox->backColor.color				= white.color;
			editbox->foreColor.color				= black.color;

			editbox->style							= _STYLE_3D;
			editbox->alignment						= _ALIGNMENT_LEFT;

			editbox->cursor							= 0;
			editbox->selectStart					= -1;
			editbox->selectEnd						= -1;

			editbox->isOpaque						= true;
			editbox->isBorder						= false;
			editbox->borderColor.color				= black.color;
			editbox->selectedBackColor.color		= selectedBackColor.color;
			editbox->selectedForeColor.color		= selectedForeColor.color;
			editbox->disabledBackColor.color		= disabledBackColor.color;
			editbox->disabledForeColor.color		= disabledForeColor.color;

			*(u32*)&editbox->interactiveChange		= *(u32*)&iDefaultCallback_onInteractiveChange;
			*(u32*)&editbox->programmaticChange		= *(u32*)&iDefaultCallback_onProgrammaticChange;
		}
	}

	void iiSubobj_resetToDefaultImage(SSubObjImage* image, bool tlResetObject, bool tlResetProperties, bool tlResetMethods)
	{
		SObject* obj;


		// Do we need to reset the object as well (Note that subobj->parent is the obj here)
		obj = image->parent;
		if (tlResetObject)
		{
			image->style						= _IMAGE_STYLE_OPAQUE;
			image->image						= iBmp_copy(bmpNoImage);

			*(u32*)&image->programmaticChange	= *(u32*)&iDefaultCallback_onProgrammaticChange;
		}
	}

	void iiSubobj_resetToDefaultCheckbox(SSubObjCheckbox* checkbox, bool tlResetObject, bool tlResetProperties, bool tlResetMethods)
	{
		SObject* obj;


		// Do we need to reset the object as well (Note that subobj->parent is the obj here)
		obj = checkbox->parent;
		if (tlResetObject)
		{
			checkbox->font							= iFont_duplicate(gsFont);
			checkbox->backColor.color				= white.color;
			checkbox->foreColor.color				= black.color;

			checkbox->alignment						= _ALIGNMENT_LEFT;
			checkbox->style							= _STYLE_3D;
			checkbox->value							= 0;
			iDatum_duplicate(&checkbox->caption, cgcName_checkbox, 8);

			checkbox->isOpaque						= true;
			checkbox->isBorder						= false;
			checkbox->borderColor.color				= black.color;
			checkbox->disabledBackColor.color		= disabledBackColor.color;
			checkbox->disabledForeColor.color		= disabledForeColor.color;

			*(u32*)&checkbox->interactiveChange		= *(u32*)&iDefaultCallback_onInteractiveChange;
			*(u32*)&checkbox->programmaticChange	= *(u32*)&iDefaultCallback_onProgrammaticChange;
		}
	}

	void iiSubobj_resetToDefaultOption(SSubObjOption* option, bool tlResetObject, bool tlResetProperties, bool tlResetMethods)
	{
		SObject* obj;


		// Do we need to reset the object as well (Note that subobj->parent is the obj here)
		obj = option->parent;
		if (tlResetObject)
		{
			option->backColor.color				= white.color;
			option->foreColor.color				= black.color;

			option->alignment					= _ALIGNMENT_LEFT;
			option->style						= _STYLE_3D;

			option->optionCount					= 2;
			option->multiSelect					= false;

			// Create the two objects
			option->firstOption					= iObj_create(_OBJ_TYPE_LABEL, NULL);
			if (option->firstOption)
				option->firstOption->ll.next	= (SLL*)iObj_create(_OBJ_TYPE_LABEL, NULL);

			// Copy the events
			*(u32*)&option->onSelect			= *(u32*)&iDefaultCallback_onSelect;
			*(u32*)&option->onDeselect			= *(u32*)&iDefaultCallback_onDeselect;
			*(u32*)&option->interactiveChange	= *(u32*)&iDefaultCallback_onInteractiveChange;
			*(u32*)&option->programmaticChange	= *(u32*)&iDefaultCallback_onProgrammaticChange;
		}
	}

	void iiSubobj_resetToDefaultRadio(SSubObjRadio* radio, bool tlResetObject, bool tlResetProperties, bool tlResetMethods)
	{
		SObject* obj;


		// Do we need to reset the object as well (Note that subobj->parent is the obj here)
		obj = radio->parent;
		if (tlResetObject)
		{
			radio->font							= iFont_duplicate(gsFont);
			radio->backColor.color				= white.color;
			radio->foreColor.color				= black.color;

			radio->alignment					= _ALIGNMENT_LEFT;
			radio->style						= _STYLE_3D;
			radio->value						= 0;
			radio->minValue						= 0;
			radio->maxValue						= 100;
			radio->roundTo						= 1.0f;

			radio->isOpaque						= true;
			radio->isBorder						= false;
			radio->borderColor.color			= black.color;
			radio->disabledBackColor.color		= disabledBackColor.color;
			radio->disabledForeColor.color		= disabledForeColor.color;

			*(u32*)&radio->interactiveChange	= *(u32*)&iDefaultCallback_onInteractiveChange;
			*(u32*)&radio->programmaticChange	= *(u32*)&iDefaultCallback_onProgrammaticChange;
		}
	}




//////////
//
// Called to set the form's icon
//
//////
	void iiSubobj_form_setIcon(SObject* obj, SBitmap* bmp)
	{
		SSubObjForm* form;


		// Make sure our environment is sane
		if (obj && bmp && obj->objType == _OBJ_TYPE_FORM)
		{
			// Grab the form data
			form = (SSubObjForm*)obj->sub_obj;

			// Delete the old icon if any
			if (form->bmpFormIcon)
				iBmp_delete(&form->bmpFormIcon, true, true);

			// Create a new icon that is 24x24
			form->bmpFormIcon = iBmp_allocate();
			iBmp_createBySize(form->bmpFormIcon, 24, 24, 32);

			// Scale the indicated icon into this one
			iBmp_scale(form->bmpFormIcon, bmp);
		}
	}




//////////
//
// Called to delete the empty.
//
//////
	void iSubobj_deleteEmpty(SSubObjEmpty* empty, bool tlDeleteSelf)
	{
		//////////
		// Free self
		//////
			if (tlDeleteSelf)
				free(empty);
	}




//////////
//
// Called to delete the form.
//
//////
	void iSubobj_deleteForm(SSubObjForm* form, bool tlDeleteSelf)
	{
		//////////
		// Free subobject components
		//////
			iFont_delete(&form->font, true);
			iBmp_delete(&form->bmpFormIcon, true, true);
			iDatum_delete(&form->caption, false);


		//////////
		// Free self
		//////
			if (tlDeleteSelf)
				free(form);
	}




//////////
//
// Called to delete the subform.
//
//////
	void iSubobj_deleteSubform(SSubObjSubform* subform, bool tlDeleteSelf)
	{
		//////////
		// Free subobject components
		//////
			iFont_delete(&subform->font, true);
			iBmp_delete(&subform->bmpFormIcon, true, true);
			iDatum_delete(&subform->caption, false);


		//////////
		// Free self
		//////
			if (tlDeleteSelf)
				free(subform);
	}




//////////
//
// Called to delete the label.
//
//////
	void iSubobj_deleteLabel(SSubObjLabel* label, bool tlDeleteSelf)
	{
		//////////
		// Free subobject components
		//////
			iFont_delete(&label->font, true);
			iDatum_delete(&label->caption, false);


		//////////
		// Free self
		//////
			if (tlDeleteSelf)
				free(label);
	}




//////////
//
// Called to delete the textbox.
//
//////
	void iSubobj_deleteTextbox(SSubObjTextbox* textbox, bool tlDeleteSelf)
	{
		//////////
		// Free subobject components
		//////
			iFont_delete(&textbox->font, true);
			iDatum_delete(&textbox->value, false);
			iDatum_delete(&textbox->picture, false);
			iDatum_delete(&textbox->mask, false);


		//////////
		// Free self
		//////
			if (tlDeleteSelf)
				free(textbox);
	}




//////////
//
// Called to delete the button.
//
//////
	void iSubobj_deleteButton(SSubObjButton* button, bool tlDeleteSelf)
	{
		//////////
		// Free subobject components
		//////
			iFont_delete(&button->font, true);
			iDatum_delete(&button->caption, false);


		//////////
		// Free self
		//////
			if (tlDeleteSelf)
				free(button);
	}




//////////
//
// Called to delete the editbox.
//
//////
	void iSubobj_deleteEditbox(SSubObjEditbox* editbox, bool tlDeleteSelf)
	{
		//////////
		// Free subobject components
		//////
			iFont_delete(&editbox->font, true);
			iEditChainManager_delete(&editbox->codeBlock, true);


		//////////
		// Free self
		//////
			if (tlDeleteSelf)
				free(editbox);
	}




//////////
//
// Called to delete the image.
//
//////
	void iSubobj_deleteImage(SSubObjImage* image, bool tlDeleteSelf)
	{
		//////////
		// Free subobject components
		//////


		//////////
		// Free self
		//////
			if (tlDeleteSelf)
				free(image);
	}




//////////
//
// Called to delete the checkbox.
//
//////
	void iSubobj_deleteCheckbox(SSubObjCheckbox* checkbox, bool tlDeleteSelf)
	{
		//////////
		// Free subobject components
		//////


		//////////
		// Free self
		//////
			if (tlDeleteSelf)
				free(checkbox);
	}




//////////
//
// Called to delete the option.
//
//////
	void iSubobj_deleteOption(SSubObjOption* option, bool tlDeleteSelf)
	{
		//////////
		// Free subobject components
		//////


		//////////
		// Free self
		//////
			if (tlDeleteSelf)
				free(option);
	}




//////////
//
// Called to delete the radio.
//
//////
	void iSubobj_deleteRadio(SSubObjRadio* radio, bool tlDeleteSelf)
	{
		//////////
		// Free subobject components
		//////


		//////////
		// Free self
		//////
			if (tlDeleteSelf)
				free(radio);
	}




//////////
//
// Renders an empty.  Note, empty objects are not rendered.  This control, however,
// can have controls within which are rendered to off-screen buffers, used for whatever
// non-visual purposes exist.  As such, render calls are still made to it.
//
//////
	u32 iSubobj_renderEmpty(SObject* obj, SSubObjEmpty* empty, bool tlRenderChildren, bool tlRenderSiblings)
	{
		//////////
		// Do any requisite processing
		//////
			iObj_renderChildrenAndSiblings(obj, tlRenderChildren, tlRenderSiblings);


		//////////
		// Success!
		//////
			obj->isDirty = false;
			return(0);		// Indicate that nothing was rendered which will affect the screen
	}




//////////
//
// Renders the form, which traverses through all child objects and renders to the
// furthest extent before rendering itself.
//
// Note:  The object rendering is independent of the publication of the constructed
//        bitmap.  The render operation only populates the bit buffer.  It will be
//        published at a later time, if indeed it is visible, however, it can after
//        rendering be re-directed to some other source, a disk file, or over a
//        network resource.
//
//////
	u32 iSubobj_renderForm(SObject* obj, SSubObjForm* form, bool tlRenderChildren, bool tlRenderSiblings)
	{
		u32				lnPixelsRendered;
//		SObject*		objSib;
		RECT			lrc, lrc2, lrc3, lrc4;
		HFONT			lhfontOld;


		// Make sure our environment is sane
		lnPixelsRendered = 0;
		if (obj && form)
		{
			//////////
			// Traverse and render any children
			//////
				if (tlRenderChildren && obj->firstChild)
					lnPixelsRendered += iObj_render(obj->firstChild, true, tlRenderSiblings);


			//////////
			// If we need re-rendering, re-render
			//////
				// The entire bmp
				SetRect(&lrc, 0, 0, obj->bmp->bi.biWidth, obj->bmp->bi.biHeight);

				// Do we need to redraw?  Or can we just copy?
				if (obj->isDirty)
				{
					//////////
					// Frame it
					//////
						// Draw the window border
						iBmp_fillRect(obj->bmp, &lrc, form->nwRgba, form->neRgba, form->swRgba, form->seRgba, true);

						// Frame it
						iBmp_frameRect(obj->bmp, &lrc, black, black, black, black, false);

						// Draw the client area
						SetRect(&lrc2, 8, form->bmpFormIcon->bi.biHeight + 2, lrc.right - form->bmpFormIcon->bi.biHeight - 2, lrc.bottom - form->bmpFormIcon->bi.biHeight - 1);
						iBmp_fillRect(obj->bmp, &lrc2, white, white, white, white, false);
// These rc* copies were added temporarily until the full object structure is coded and working
CopyRect(&form->rcClient, &lrc2);

						// Put a border around the client area
						InflateRect(&lrc2, 1, 1);
						iBmp_frameRect(obj->bmp, &lrc2, black, black, black, black, false);


					//////////
					// Form icon and standard controls
					//////
						// Form icon
						SetRect(&lrc3,	bmpArrowUl->bi.biWidth + 8, 1, bmpArrowUl->bi.biWidth + 8 + form->bmpFormIcon->bi.biWidth, 1 + form->bmpFormIcon->bi.biHeight);
						iBmp_bitBltMask(obj->bmp, &lrc3, form->bmpFormIcon);
CopyRect(&form->rcIcon, &lrc3);

						// Close
						SetRect(&lrc2,	lrc.right - bmpArrowUr->bi.biWidth - 8 - bmpClose->bi.biWidth, lrc.top + 1, lrc.right - bmpArrowUr->bi.biWidth - 8, lrc.bottom - 1);
						iBmp_bitBltMask(obj->bmp, &lrc2, bmpClose);
CopyRect(&form->rcClose, &lrc2);

						// Maximize
						SetRect(&lrc2,	lrc2.left - bmpMaximize->bi.biWidth - 1, lrc2.top, lrc2.left - 1, lrc2.bottom);
						iBmp_bitBltMask(obj->bmp, &lrc2, bmpMaximize);
CopyRect(&form->rcMaximize, &lrc2);

						// Minimize
						SetRect(&lrc2,	lrc2.left - bmpMinimize->bi.biWidth - 1, lrc2.top, lrc2.left - 1, lrc2.bottom);
						iBmp_bitBltMask(obj->bmp, &lrc2, bmpMinimize);
CopyRect(&form->rcMinimize, &lrc2);

						// Move
						SetRect(&lrc4,	lrc2.left - bmpMove->bi.biWidth - 1, lrc2.top, lrc2.left - 1, lrc2.bottom);
						iBmp_bitBltMask(obj->bmp, &lrc4, bmpMove);
CopyRect(&form->rcMove, &lrc4);


					//////////
					// Resizing arrows
					//////
						// Upper left arrow
						SetRect(&lrc2, lrc.left, lrc.top, lrc.left + bmpArrowUl->bi.biWidth, lrc.top + bmpArrowUl->bi.biHeight);
						iBmp_bitBltMask(obj->bmp, &lrc2, bmpArrowUl);
CopyRect(&form->rcArrowUl, &lrc2);

						// Upper right arrow
						SetRect(&lrc2, lrc.right - bmpArrowUr->bi.biWidth, lrc.top, lrc.right, lrc.top + bmpArrowUr->bi.biHeight);
						iBmp_bitBltMask(obj->bmp, &lrc2, bmpArrowUr);
CopyRect(&form->rcArrowUr, &lrc2);

						// Lower left arrow
						SetRect(&lrc2, lrc.right - bmpArrowLr->bi.biWidth, lrc.bottom - bmpArrowLr->bi.biHeight, lrc.right, lrc.bottom);
						iBmp_bitBltMask(obj->bmp, &lrc2, bmpArrowLr);
CopyRect(&form->rcArrowLl, &lrc2);

						// Lower right arrow
						SetRect(&lrc2, lrc.left, lrc.bottom - bmpArrowLl->bi.biHeight, lrc.left + bmpArrowLl->bi.biWidth, lrc.bottom);
						iBmp_bitBltMask(obj->bmp, &lrc2, bmpArrowLl);
CopyRect(&form->rcArrowLr, &lrc2);


					//////////
					// Form caption
					//////
						SetRect(&lrc2, lrc3.right + 8, lrc3.top, lrc4.right - 8, lrc3.bottom);
CopyRect(&form->rcCaption, &lrc2);
						lhfontOld = (HFONT)SelectObject(obj->bmp->hdc, gsWindowTitleBarFont->hfont);
						SetTextColor(obj->bmp->hdc, (COLORREF)RGB(form->captionColor.red, form->captionColor.grn, form->captionColor.blu));
						SetBkMode(obj->bmp->hdc, TRANSPARENT);
						DrawTextA(obj->bmp->hdc, form->caption.data, form->caption.length, &lrc2, DT_VCENTER);
						SelectObject(obj->bmp->hdc, lhfontOld);


					//////////
					// Copy to prior rendered bitmap
					//////
						// Make sure our bmpPriorRendered exists
						obj->bmpPriorRendered = iBmp_verifyCopyIsSameSize(obj->bmpPriorRendered, obj->bmp);

						// Copy to the prior rendered version
						lnPixelsRendered += iBmp_bitBlt(obj->bmpPriorRendered, &lrc, obj->bmp);
						// Right now, we can use the bmpPriorRendered for a fast copy rather than 

				} else {
					// Render from its prior rendered version
					lnPixelsRendered += iBmp_bitBlt(obj->bmp, &lrc, obj->bmpPriorRendered);
				}


//////////
// For temporary, we are adding additional renderings for _screen and _jdebi objects
//////
	if (obj == gobj_screen)
	{
		iEditChainManager_render(screenData, gobj_screen);
		if (gWinScreen)
			InvalidateRect(gWinScreen->hwnd, 0, FALSE);
	}

	if (obj == gobj_jdebi)
	{
		iEditChainManager_render(commandHistory, gobj_jdebi);
		if (gWinJDebi)
			InvalidateRect(gWinJDebi->hwnd, 0, FALSE);
	}


			//////////
			// Indicate we're no longer dirty, that we have everything
			//////
				obj->isDirty = false;


			//////////
			// Render any siblings
			//////
// 				if (tlRenderSiblings && obj->ll.next)
// 				{
// 					objSib = (SObject*)obj->ll.next;
// 					while (objSib)
// 					{
// 						// Render this sibling
// 						lnPixelsRendered += iObj_render(objSib, tlRenderChildren, false);
// 
// 						// Move to next sibling
// 						objSib = (SObject*)objSib->ll.next;
// 					}
// 				}
		}

		// Indicate how many pixels were drawn
		return(lnPixelsRendered);
	}




//////////
//
// Renders the subform, which traverses through all child objects and renders to the
// furthest extent before rendering itself.
//
// Note:  See "Note" on iRenderForm().
//
//////
	u32 iSubobj_renderSubform(SObject* obj, SSubObjSubform* subform, bool tlRenderChildren, bool tlRenderSiblings)
	{


			//////////
			// Indicate we're no longer dirty, that we have everything
			//////
				obj->isDirty = false;
		return(0);
	}




//////////
//
// Renders the label, and traverses any child objects contained within to render them.
//
// Note:  See "Note" on iRenderForm().
//
//////
	u32 iSubobj_renderLabel(SObject* obj, SSubObjLabel* label, bool tlRenderChildren, bool tlRenderSiblings)
	{


			//////////
			// Indicate we're no longer dirty, that we have everything
			//////
				obj->isDirty = false;
		return(0);
	}




//////////
//
// Renders the textbox, and traverses any child objects contained within to render them.
//
// Note:  See "Note" on iRenderForm().
//
//////
	u32 iSubobj_renderTextbox(SObject* obj, SSubObjTextbox* textbox, bool tlRenderChildren, bool tlRenderSiblings)
	{


			//////////
			// Indicate we're no longer dirty, that we have everything
			//////
				obj->isDirty = false;
		return(0);
	}




//////////
//
// Renders the button, and traverses any child objects contained within to render them.
//
// Note:  See "Note" on iRenderForm().
//
//////
	u32 iSubobj_renderButton(SObject* obj, SSubObjButton* button, bool tlRenderChildren, bool tlRenderSiblings)
	{


			//////////
			// Indicate we're no longer dirty, that we have everything
			//////
				obj->isDirty = false;
		return(0);
	}




//////////
//
// Renders the editbox, and traverses any child objects contained within to render them.
//
// Note:  See "Note" on iRenderForm().
//
//////
	u32 iSubobj_renderEditbox(SObject* obj, SSubObjEditbox* editbox, bool tlRenderChildren, bool tlRenderSiblings)
	{


			//////////
			// Indicate we're no longer dirty, that we have everything
			//////
				obj->isDirty = false;
		return(0);
	}




//////////
//
// Renders the image, and traverses any child objects contained within to render them.
//
// Note:  See "Note" on iRenderForm().
//
//////
	u32 iSubobj_renderImage(SObject* obj, SSubObjImage* image, bool tlRenderChildren, bool tlRenderSiblings)
	{


			//////////
			// Indicate we're no longer dirty, that we have everything
			//////
				obj->isDirty = false;
		return(0);
	}




//////////
//
// Renders the checkbox, and traverses any child objects contained within to render them.
//
// Note:  See "Note" on iRenderForm().
//
//////
	u32 iSubobj_renderCheckbox(SObject* obj, SSubObjCheckbox* checkbox, bool tlRenderChildren, bool tlRenderSiblings)
	{


			//////////
			// Indicate we're no longer dirty, that we have everything
			//////
				obj->isDirty = false;
		return(0);
	}




//////////
//
// Renders the option, and traverses any child objects contained within to render them.
//
// Note:  See "Note" on iRenderForm().
//
//////
	u32 iSubobj_renderOption(SObject* obj, SSubObjOption* option, bool tlRenderChildren, bool tlRenderSiblings)
	{


			//////////
			// Indicate we're no longer dirty, that we have everything
			//////
				obj->isDirty = false;
		return(0);
	}




//////////
//
// Renders the radio, and traverses any child objects contained within to render them.
//
// Note:  See "Note" on iRenderForm().
//
//////
	u32 iSubobj_renderRadio(SObject* obj, SSubObjRadio* radio, bool tlRenderChildren, bool tlRenderSiblings)
	{


			//////////
			// Indicate we're no longer dirty, that we have everything
			//////
				obj->isDirty = false;
		return(0);
	}
