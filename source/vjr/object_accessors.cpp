//////////
//
// /libsf/source/vjr/object_accessors.cpp
//
//////
// Version 0.52
// Copyright (c) 2014 by Rick C. Hodgin
//////
// Last update:
//     Jul.12.2014
//////
// Change log:
//     Jul.12.2014 - Initial creation
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
// To jump immediately to a section, search for one of these here or in object_accessors.h:
//		OBJECT Properties
//		FORM Properties
//		SUBFORM Properties
//
//////









bool iObj_setLogical(SObject* obj, SVariable* var, bool* tlDest)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_isTypeLogical(var))
	{
		// Set the value
		*tlDest = ((var->value.data[0] == _LOGICAL_FALSE) ? false : true);

		// Indicate success
		return(true);
	}
	// If we get here, failure
	return(false);
}

SVariable* iObj_getLogical(SObject* obj, bool tlValue)
{
	SVariable* var;


	// Make sure the environment is sane
	if (obj)
	{
		// Create a new variable
		var = iVariable_create(_VAR_TYPE_LOGICAL, NULL);
		*(u8*)var->value.data = (tlValue ? _LOGICAL_TRUE : _LOGICAL_FALSE);
		return(var);
	}
	// If we get here, failure
	return(NULL);
}

bool iObj_setInteger(SObject* obj, SVariable* var, s32* tnDest, s32 tnMin, s32 tnMax, bool tlUseMinMaxTest, u32 tnExtraTestFunction)
{
	s32		value;
	bool	error;
	u32		errorNum;
	union {
		u32		_extraTestFunction;
		bool	(*extraTestFunction)	(s32 value);
	};


	// Make sure the environment is sane
	if (obj && var && iVariable_isTypeNumeric(var))
	{
		// Try to get the value
		value = iiVariable_getAs_s32(var, false, &error, &errorNum);
		if (error)
		{
			iError_reportByNumber(errorNum, var->compRelated);
			return(false);
		}

		// Test min/max
		if (tlUseMinMaxTest && (value < tnMin || value > tnMax))
		{
			iError_reportByNumber(_ERROR_OUT_OF_RANGE, var->compRelated);
			return(false);
		}

		// Test with extra function
		if (tnExtraTestFunction)
		{
			_extraTestFunction = tnExtraTestFunction;
			if (!extraTestFunction(value))
			{
				iError_reportByNumber(_ERROR_OUT_OF_RANGE, var->compRelated);
				return(false);
			}
		}

		// Set the value
		*tnDest = value;

		// Indicate success
		return(true);
	}
	// If we get here, failure
	return(false);
}

SVariable* iObj_getInteger(SObject* obj, s32 value)
{
	SVariable* var;


	// Make sure the environment is sane
	if (obj)
	{
		// Create a new variable
		var = iVariable_create(_VAR_TYPE_INTEGER, NULL);
		*(s32*)var->value.data = value;
		return(var);
	}
	// If we get here, failure
	return(NULL);
}

bool iObj_setCharacter(SObject* obj, SVariable* var, SDatum* datum, s8* tcData, s32 tnDataLength)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_isTypeCharacter(var))
	{
		// Set the value
		iDatum_duplicate(datum, tcData, tnDataLength);

		// Indicate success
		return(true);
	}
	// If we get here, failure
	return(false);
}

SVariable* iObj_getCharacter(SObject* obj, SDatum* datum)
{
	SVariable* var;


	// Make sure the environment is sane
	if (obj)
	{
		// Create a new variable
		var = iVariable_create(_VAR_TYPE_CHARACTER, NULL);
		iDatum_duplicate(&var->value, datum);
		return(var);
	}
	// If we get here, failure
	return(NULL);
}

bool iObj_setError(SObject* obj, SVariable* var)
{
	iError_reportByNumber(_ERROR_FEATURE_NOT_AVAILABLE, var->compRelated);
	return(false);
}

SVariable* iObj_getError(SObject* obj)
{
	iError_reportByNumber(_ERROR_FEATURE_NOT_AVAILABLE, NULL);
	return(NULL);
}





//////////
// OBJECT Properties
//////
SVariable* iObj_getProperty_parent(SObject* obj)
{
	SVariable* var;


	// Make sure the environment is sane
	if (obj)
	{
		// Create a new variable
		var = iVariable_create(_VAR_TYPE_OBJECT, NULL);
		var->obj = obj->parent;
		return(var);
	}
	// If we get here, failure
	return(NULL);
}

bool iObj_setProperty_tabIndex(SObject* obj, SVariable* var)
{
	return(iObj_setInteger(obj, var, &obj->p.tabIndex, 0, 0, false, 0));
}

SVariable* iObj_getProperty_tabIndex(SObject* obj)
{
	return(iObj_getInteger(obj, obj->p.tabIndex));
}

bool iObj_setProperty_tabStop(SObject* obj, SVariable* var)
{
	return(iObj_setLogical(obj, var, &obj->p.tabStop));
}

SVariable* iObj_getProperty_tabStop(SObject* obj)
{
	return(iObj_getLogical(obj, obj->p.tabStop));
}

bool iObj_setProperty_helpContextId(SObject* obj, SVariable* var)
{
	return(iObj_setInteger(obj, var, &obj->p.helpContextId, 0, 0, false, 0));
}

SVariable* iObj_getProperty_helpContextId(SObject* obj)
{
	return(iObj_getInteger(obj, obj->p.helpContextId));
}

bool iObj_setProperty_hasWhatsThisButton(SObject* obj, SVariable* var)
{
	return(iObj_setLogical(obj, var, &obj->p.hasWhatsThisButton));
}

SVariable* iObj_getProperty_hasWhatsThisButton(SObject* obj)
{
	return(iObj_getLogical(obj, obj->p.hasWhatsThisButton));
}

bool iObj_setProperty_hasWhatsThisHelp(SObject* obj, SVariable* var)
{
	return(iObj_setLogical(obj, var, &obj->p.hasWhatsThisHelp));
}

SVariable* iObj_getProperty_hasWhatsThisHelp(SObject* obj)
{
	return(iObj_getLogical(obj, obj->p.hasWhatsThisHelp));
}

bool iObj_setProperty_whatsThisHelpId(SObject* obj, SVariable* var)
{
	return(iObj_setInteger(obj, var, &obj->p.whatsThisHelpId, 0, 0, false, 0));
}

SVariable* iObj_getProperty_whatsThisHelpId(SObject* obj)
{
	return(iObj_getInteger(obj, obj->p.whatsThisHelpId));
}

bool iObj_setProperty_name(SObject* obj, SVariable* var)
{
	return(iObj_setCharacter(obj, var, &obj->pa.name, var->value.data, var->value.length));
}

SVariable* iObj_getProperty_name(SObject* obj)
{
	return(iObj_getCharacter(obj, &obj->pa.name));
}

SVariable* iObj_getProperty_className(SObject* obj)
{
	return(iObj_getCharacter(obj, &obj->pa.className));
}

SVariable* iObj_getProperty_classLibrary(SObject* obj)
{
	return(iObj_getCharacter(obj, &obj->pa.classLibrary));
}

bool iObj_setProperty_comment(SObject* obj, SVariable* var)
{
	return(iObj_setCharacter(obj, var, &obj->pa.comment, var->value.data, var->value.length));
}

SVariable* iObj_getProperty_comment(SObject* obj)
{
	return(iObj_getCharacter(obj, &obj->pa.comment));
}

bool iObj_setProperty_toolTip(SObject* obj, SVariable* var)
{
	return(iObj_setCharacter(obj, var, &obj->pa.tooltip, var->value.data, var->value.length));
}

SVariable* iObj_getProperty_toolTip(SObject* obj)
{
	return(iObj_getCharacter(obj, &obj->pa.tooltip));
}

bool iObj_setProperty_tag(SObject* obj, SVariable* var)
{
	return(iObj_setCharacter(obj, var, &obj->pa.tag, var->value.data, var->value.length));
}

SVariable* iObj_getProperty_tag(SObject* obj)
{
	return(iObj_getCharacter(obj, &obj->pa.tag));
}

bool iObj_setProperty_mousePointer(SObject* obj, SVariable* var)
{
	return(iObj_setInteger(obj, var, &obj->p.mousePointer, 0, 17, true, (u32)&iObj_setProperty_mousePointer_extraSetTest));
}

bool iObj_setProperty_mousePointer_extraSetTest(s32 value)
{
	if (value == 99)	return(true);		// A value of 99 is valid
	else				return(false);
}

SVariable* iObj_getProperty_mousePointer(SObject* obj)
{
	return(iObj_getInteger(obj, obj->p.mousePointer));
}

bool iObj_setProperty_isEnabled(SObject* obj, SVariable* var)
{
	return(iObj_setLogical(obj, var, &obj->p.isEnabled));
}

SVariable* iObj_getProperty_isEnabled(SObject* obj)
{
	return(iObj_getLogical(obj, obj->p.isEnabled));
}

bool iObj_setProperty_hasFocus(SObject* obj, SVariable* var)
{
	return(iObj_setLogical(obj, var, &obj->p.hasFocus));
}

SVariable* iObj_getProperty_hasFocus(SObject* obj)
{
	return(iObj_getLogical(obj, obj->p.hasFocus));
}

bool iObj_setProperty_isMovable(SObject* obj, SVariable* var)
{
	return(iObj_setLogical(obj, var, &obj->p.isMovable));
}

SVariable* iObj_getProperty_isMovable(SObject* obj)
{
	return(iObj_getLogical(obj, obj->p.isMovable));
}

bool iObj_setProperty_isRendered(SObject* obj, SVariable* var)
{
	return(iObj_setLogical(obj, var, &obj->isRendered));
}

SVariable* iObj_getProperty_isRendered(SObject* obj)
{
	return(iObj_getLogical(obj, obj->isRendered));
}

bool iObj_setProperty_isPublished(SObject* obj, SVariable* var)
{
	return(iObj_setLogical(obj, var, &obj->isPublished));
}

SVariable* iObj_getProperty_isPublished(SObject* obj)
{
	return(iObj_getLogical(obj, obj->isPublished));
}

bool iObj_setProperty_isVisible(SObject* obj, SVariable* var)
{
	return(iObj_setLogical(obj, var, &obj->p.isVisible));
}

SVariable* iObj_getProperty_isVisible(SObject* obj)
{
	return(iObj_getLogical(obj, obj->p.isVisible));
}

bool iObj_setProperty_isDirty(SObject* obj, SVariable* var)
{
	return(iObj_setLogical(obj, var, &obj->isDirtyRender));
}

SVariable* iObj_getProperty_isDirty(SObject* obj)
{
	return(iObj_getLogical(obj, obj->isDirtyRender));
}

bool iObj_setProperty_left(SObject* obj, SVariable* var)
{
	s32		value, delta;
	bool	error;
	u32		errorNum;


	// Make sure the environment is sane
	if (obj && var && iVariable_isTypeNumeric(var))
	{
		// Try to get the value
		value = iiVariable_getAs_s32(var, false, &error, &errorNum);
		if (error)
		{
			iError_reportByNumber(errorNum, var->compRelated);
			return(false);
		}

		// Set the value
		delta			= value - obj->rc.left;
		obj->rc.left	= value;
		obj->rc.right	+= delta;

		// Indicate success
		return(true);
	}
	// If we get here, failure
	return(false);
}

SVariable* iObj_getProperty_left(SObject* obj)
{
	SVariable* var;


	// Make sure the environment is sane
	if (obj)
	{
		// Create a new variable
		var = iVariable_create(_VAR_TYPE_INTEGER, NULL);
		*(s32*)var->value.data = obj->rc.left;
		return(var);
	}
	// If we get here, failure
	return(NULL);
}

bool iObj_setProperty_top(SObject* obj, SVariable* var)
{
	s32		value, delta;
	bool	error;
	u32		errorNum;


	// Make sure the environment is sane
	if (obj && var && iVariable_isTypeNumeric(var))
	{
		// Try to get the value
		value = iiVariable_getAs_s32(var, false, &error, &errorNum);
		if (error)
		{
			iError_reportByNumber(errorNum, var->compRelated);
			return(false);
		}

		// Set the value
		delta			= value - obj->rc.top;
		obj->rc.top		= value;
		obj->rc.bottom	+= delta;

		// Indicate success
		return(true);
	}
	// If we get here, failure
	return(false);
}

SVariable* iObj_getProperty_top(SObject* obj)
{
	SVariable* var;


	// Make sure the environment is sane
	if (obj)
	{
		// Create a new variable
		var = iVariable_create(_VAR_TYPE_INTEGER, NULL);
		*(s32*)var->value.data = obj->rc.top;
		return(var);
	}
	// If we get here, failure
	return(NULL);
}

bool iObj_setProperty_width(SObject* obj, SVariable* var)
{
	s32		value;
	bool	error;
	u32		errorNum;


	// Make sure the environment is sane
	if (obj && var)
	{
		// Try to get the value
		value = iiVariable_getAs_s32(var, false, &error, &errorNum);
		if (error)
		{
			iError_reportByNumber(errorNum, var->compRelated);
			return(false);
		}

		// Set the value
		obj->rc.right = obj->rc.left + value;

		// Indicate success
		return(true);
	}
	// If we get here, failure
	return(false);
}

SVariable* iObj_getProperty_width(SObject* obj)
{
	SVariable* var;


	// Make sure the environment is sane
	if (obj)
	{
		// Create a new variable
		var = iVariable_create(_VAR_TYPE_INTEGER, NULL);
		*(s32*)var->value.data = obj->rc.right - obj->rc.left;
		return(var);
	}
	// If we get here, failure
	return(NULL);
}

bool iObj_setProperty_height(SObject* obj, SVariable* var)
{
	s32		value;
	bool	error;
	u32		errorNum;


	// Make sure the environment is sane
	if (obj && var)
	{
		// Try to get the value
		value = iiVariable_getAs_s32(var, false, &error, &errorNum);
		if (error)
		{
			iError_reportByNumber(errorNum, var->compRelated);
			return(false);
		}

		// Set the value
		obj->rc.bottom = obj->rc.top + value;

		// Indicate success
		return(true);
	}
	// If we get here, failure
	return(false);
}

SVariable* iObj_getProperty_height(SObject* obj)
{
	SVariable* var;


	// Make sure the environment is sane
	if (obj)
	{
		// Create a new variable
		var = iVariable_create(_VAR_TYPE_INTEGER, NULL);
		*(s32*)var->value.data = obj->rc.bottom - obj->rc.top;
		return(var);
	}
	// If we get here, failure
	return(NULL);
}

bool iObj_setProperty_anchor(SObject* obj, SVariable* var)
{
	return(iObj_setInteger(obj, var, &obj->p.anchor, 0, 0, false, 0));
}

SVariable* iObj_getProperty_anchor(SObject* obj)
{
	return(iObj_getInteger(obj, obj->p.anchor));
}

bool iObj_setProperty_scrollX(SObject* obj, SVariable* var)
{
	return(iObj_setInteger(obj, var, &obj->scrollOffsetX, 0, 0, false, 0));
}

SVariable* iObj_getProperty_scrollX(SObject* obj)
{
	SVariable* var;


	// Make sure the environment is sane
	if (obj)
	{
		// Create a new variable
		var = iVariable_create(_VAR_TYPE_INTEGER, NULL);
		*(s32*)var->value.data = obj->scrollOffsetX;
		return(var);
	}
	// If we get here, failure
	return(NULL);
}

bool iObj_setProperty_scrollY(SObject* obj, SVariable* var)
{
	return(iObj_setInteger(obj, var, &obj->scrollOffsetY, 0, 0, false, 0));
}

SVariable* iObj_getProperty_scrollY(SObject* obj)
{
	SVariable* var;


	// Make sure the environment is sane
	if (obj)
	{
		// Create a new variable
		var = iVariable_create(_VAR_TYPE_INTEGER, NULL);
		*(s32*)var->value.data = obj->scrollOffsetY;
		return(var);
	}
	// If we get here, failure
	return(NULL);
}

bool iObj_setProperty_scaleX(SObject* obj, SVariable* var)
{
	s32		lnNewWidth;
	f32		value;
	bool	error;
	u32		errorNum;


	// Make sure the environment is sane
	if (obj && var && iVariable_isTypeNumeric(var))
	{
		// Try to get the value
		value = iiVariable_getAs_f32(var, false, &error, &errorNum);
		if (error)
		{
			iError_reportByNumber(errorNum, var->compRelated);
			return(false);
		}
		if (value <= 0.0f)
		{
			iError_reportByNumber(_ERROR_OUT_OF_RANGE, var->compRelated);
			return(false);
		}

		// Set the value
		// Note:  This is done by resizing the underlying bitmap.
		lnNewWidth = (s32)((f32)(obj->rc.right - obj->rc.left) / value);
		obj->bmp = iBmp_verifySizeOrResize(obj->bmp, lnNewWidth, obj->bmp->bi.biHeight, obj->bmp->bi.biBitCount);

		// Indicate success
		return(true);
	}
	// If we get here, failure
	return(false);
}

SVariable* iObj_getProperty_scaleX(SObject* obj)
{
	SVariable* var;


	// Make sure the environment is sane
	if (obj)
	{
		// Create a new variable
		var = iVariable_create(_VAR_TYPE_F32, NULL);
		if (!obj->isScaled || !obj->bmpScaled)
		{
			// Invalid
			*(f32*)var->value.data = -1.0f;

		} else {
			// Compute the scale ratio
			*(f32*)var->value.data = ((f32)(obj->rc.right - obj->rc.left) / (f32)obj->bmp->bi.biWidth);
		}
		return(var);
	}
	// If we get here, failure
	return(NULL);
}

bool iObj_setProperty_scaleY(SObject* obj, SVariable* var)
{
	s32		lnNewHeight;
	f32		value;
	bool	error;
	u32		errorNum;


	// Make sure the environment is sane
	if (obj && var && iVariable_isTypeNumeric(var))
	{
		// Try to get the value
		value = iiVariable_getAs_f32(var, false, &error, &errorNum);
		if (error)
		{
			iError_reportByNumber(errorNum, var->compRelated);
			return(false);
		}
		if (value <= 0.0f)
		{
			iError_reportByNumber(_ERROR_OUT_OF_RANGE, var->compRelated);
			return(false);
		}

		// Set the value
		// Note:  This is done by resizing the underlying bitmap.
		lnNewHeight = (s32)((f32)(obj->rc.bottom - obj->rc.top) / value);
		obj->bmp = iBmp_verifySizeOrResize(obj->bmp, obj->bmp->bi.biWidth, lnNewHeight, obj->bmp->bi.biBitCount);

		// Indicate success
		return(true);
	}
	// If we get here, failure
	return(false);
}

SVariable* iObj_getProperty_scaleY(SObject* obj)
{
	SVariable* var;


	// Make sure the environment is sane
	if (obj)
	{
		// Create a new variable
		var = iVariable_create(_VAR_TYPE_F32, NULL);
		if (!obj->isScaled || !obj->bmpScaled)
		{
			// Invalid
			*(f32*)var->value.data = -1.0f;

		} else {
			// Compute the scale ratio
			*(f32*)var->value.data = ((f32)(obj->rc.bottom - obj->rc.top) / (f32)obj->bmp->bi.biHeight);
		}
		return(var);
	}
	// If we get here, failure
	return(NULL);
}

void iObj_setIcon(SObject* obj, SBitmap* bmp)
{
	SObject*	objChild;
	RECT		lrc;


	// Make sure the environment is sane
	if (obj && iBmp_validate(bmp))
	{
		// If it's a form, we also update the child icon
		switch (obj->objType)
		{
			case _OBJ_TYPE_FORM:
			case _OBJ_TYPE_SUBFORM:
				//////////
				// Create the icon at 24x24
				//////
					iBmp_delete(&obj->pa.bmpIcon, true, true);		// Delete the old
					obj->pa.bmpIcon = iBmp_allocate();
					iBmp_createBySize(obj->pa.bmpIcon, bmpArrowUl->bi.biWidth, bmpArrowUl->bi.biHeight, 24);
					iBmp_scale(obj->pa.bmpIcon, bmp);				// Scale the indicated icon into our 24x24 size


				//////////
				// Forms have child-objects which hold their icons (so they can respond to user events, etc.)
				//////
					objChild = obj->firstChild;
					while (objChild)
					{
						if (objChild->objType == _OBJ_TYPE_IMAGE && iDatum_compare(&objChild->pa.name, cgcName_icon, sizeof(cgcName_icon) - 1) == 0)
						{
							// Adjust the size
							iObj_setSize(objChild, objChild->rc.left, objChild->rc.top, bmpArrowUl->bi.biWidth, bmpArrowUl->bi.biHeight);

							// This is the one to update
							iBmp_delete(&objChild->pa.bmpPicture,		true, true);	// Delete the old
							iBmp_delete(&objChild->pa.bmpPictureOver,	true, true);	// Delete the old
							iBmp_delete(&objChild->pa.bmpPictureDown,	true, true);	// Delete the old
							objChild->pa.bmpPicture		= iBmp_copy(obj->pa.bmpIcon);	// Set the new
							objChild->pa.bmpPictureOver	= iBmp_copy(obj->pa.bmpIcon);	// Set the new
							objChild->pa.bmpPictureDown	= iBmp_copy(obj->pa.bmpIcon);	// Set the new

							// Add highlighting for the over and down
							SetRect(&lrc, 0, 0, 24, 24);
							iBmp_colorize(objChild->pa.bmpPictureOver, &lrc, colorMouseOver,	false, 0.25f);
							iBmp_colorize(objChild->pa.bmpPictureDown, &lrc, colorMouseDown,	false, 0.25f);

							// All done
							break;
						}

						// Move to next object
						objChild = (SObject*)objChild->ll.next;
					}
					break;
		}
	}
}

bool iObj_setMinLeft(SObject* obj, SVariable* var)
{
	if (obj)
		return(iObj_setInteger(obj, var, (s32*)&obj->p.rcMin.left, 0, 0, false, 0));

	// If we get here, failure
	return(false);
}

SVariable* iObj_getMinLeft(SObject* obj)
{
	if (obj)
		return(iObj_getInteger(obj, obj->p.rcMin.left));

	// If we get here, failure
	return(NULL);
}

bool iObj_setMinTop(SObject* obj, SVariable* var)
{
	if (obj)
		return(iObj_setInteger(obj, var, (s32*)&obj->p.rcMin.top, 0, 0, false, 0));

	// If we get here, failure
	return(false);
}

SVariable* iObj_getMinTop(SObject* obj)
{
	if (obj)
		return(iObj_getInteger(obj, obj->p.rcMin.top));

	// If we get here, failure
	return(NULL);
}

bool iObj_setMinWidth(SObject* obj, SVariable* var)
{
	s32		value;
	bool	error;
	u32		errorNum;


	// Make sure our environment is sane
	if (obj && iVariable_isTypeNumeric(var))
	{
		value = iiVariable_getAs_s32(var, false, &error, &errorNum);
		if (error)
		{
			iError_reportByNumber(errorNum, var->compRelated);
			return(false);
		}

		// Set the value
		obj->p.rcMin.right = obj->p.rcMin.left + value;
	}

	// If we get here, failure
	return(false);
}

SVariable* iObj_getMinWidth(SObject* obj)
{
	if (obj)
		return(iObj_getInteger(obj, obj->p.rcMin.right - obj->p.rcMin.left));

	// If we get here, failure
	return(NULL);
}

bool iObj_setMinHeight(SObject* obj, SVariable* var)
{
	s32		value;
	bool	error;
	u32		errorNum;


	// Make sure our environment is sane
	if (obj && iVariable_isTypeNumeric(var))
	{
		value = iiVariable_getAs_s32(var, false, &error, &errorNum);
		if (error)
		{
			iError_reportByNumber(errorNum, var->compRelated);
			return(false);
		}

		// Set the value
		obj->p.rcMin.bottom = obj->p.rcMin.top + value;
	}

	// If we get here, failure
	return(false);
}

SVariable* iObj_getMinHeight(SObject* obj)
{
	if (obj)
		return(iObj_getInteger(obj, obj->p.rcMin.bottom - obj->p.rcMin.top));

	// If we get here, failure
	return(NULL);
}

bool iObj_setMaxLeft(SObject* obj, SVariable* var)
{
	if (obj)
		return(iObj_setInteger(obj, var, (s32*)&obj->p.rcMax.left, 0, 0, false, 0));

	// If we get here, failure
	return(false);
}

SVariable* iObj_getMaxLeft(SObject* obj)
{
	if (obj)
		return(iObj_getInteger(obj, obj->p.rcMax.left));

	// If we get here, failure
	return(NULL);
}

bool iObj_setMaxTop(SObject* obj, SVariable* var)
{
	if (obj)
		return(iObj_setInteger(obj, var, (s32*)&obj->p.rcMax.top, 0, 0, false, 0));

	// If we get here, failure
	return(false);
}

SVariable* iObj_getMaxTop(SObject* obj)
{
	if (obj)
		return(iObj_getInteger(obj, obj->p.rcMin.top));

	// If we get here, failure
	return(NULL);
}

bool iObj_setMaxWidth(SObject* obj, SVariable* var)
{
	s32		value;
	bool	error;
	u32		errorNum;


	// Make sure our environment is sane
	if (obj && iVariable_isTypeNumeric(var))
	{
		value = iiVariable_getAs_s32(var, false, &error, &errorNum);
		if (error)
		{
			iError_reportByNumber(errorNum, var->compRelated);
			return(false);
		}

		// Set the value
		obj->p.rcMax.right = obj->p.rcMax.left + value;
	}

	// If we get here, failure
	return(false);
}

SVariable* iObj_getMaxWidth(SObject* obj)
{
	if (obj)
		return(iObj_getInteger(obj, obj->p.rcMax.right - obj->p.rcMax.left));

	// If we get here, failure
	return(NULL);
}

bool iObj_setMaxHeight(SObject* obj, SVariable* var)
{
	s32		value;
	bool	error;
	u32		errorNum;


	// Make sure our environment is sane
	if (obj && iVariable_isTypeNumeric(var))
	{
		value = iiVariable_getAs_s32(var, false, &error, &errorNum);
		if (error)
		{
			iError_reportByNumber(errorNum, var->compRelated);
			return(false);
		}

		// Set the value
		obj->p.rcMax.bottom = obj->p.rcMax.top + value;
	}

	// If we get here, failure
	return(false);
}

SVariable* iObj_getMaxHeight(SObject* obj)
{
	if (obj)
		return(iObj_getInteger(obj, obj->p.rcMin.bottom - obj->p.rcMin.top));

	// If we get here, failure
	return(NULL);
}

bool iObj_setFontName(SObject* obj, SVariable* var)
{
	bool	llResult;


	// Make sure our environment is sane
	if (obj)
	{
		// Perform the update
		llResult = iObj_setCharacter(obj, var, &obj->pa.font->name, var->value.data, var->value.length);
		if (llResult)
			iiFont_refresh(obj->pa.font);		// Refresh the font with its new settings

		// Indicate our status
		return(llResult);
	}

	// If we get here, failure
	return(false);
}

SVariable* iObj_getFontName(SObject* obj)
{
	if (obj)
		return(iObj_getCharacter(obj, &obj->pa.font->name));

	// If we get here, failure
	return(NULL);
}

bool iObj_setFontSize(SObject* obj, SVariable* var)
{
	bool	llResult;


	// Make sure our environment is sane
	if (obj)
	{
		// Perform the update
		llResult = iObj_setInteger(obj, var, (s32*)&obj->pa.font->_size, 0, 0, false, 0);
		if (llResult)
			iiFont_refresh(obj->pa.font);		// Refresh the font with its new settings

		// Indicate our status
		return(llResult);
	}

	// If we get here, failure
	return(false);
}

SVariable* iObj_getFontSize(SObject* obj)
{
	if (obj)
		return(iObj_getInteger(obj, obj->pa.font->_size));

	// If we get here, failure
	return(NULL);
}

bool iObj_setFontBold(SObject* obj, SVariable* var)
{
	bool	llResult;


	// Make sure our environment is sane
	if (obj)
	{
		// Perform the update
		llResult = iObj_setLogical(obj, var, &obj->pa.font->isBold);
		if (llResult)
			iiFont_refresh(obj->pa.font);		// Refresh the font with its new settings

		// Indicate our status
		return(llResult);
	}

	// If we get here, failure
	return(false);
}

SVariable* iObj_getFontBold(SObject* obj)
{
	if (obj)
		return(iObj_getLogical(obj, obj->pa.font->isBold));

	// If we get here, failure
	return(NULL);
}

bool iObj_setFontItalic(SObject* obj, SVariable* var)
{
	bool	llResult;


	// Make sure our environment is sane
	if (obj)
	{
		// Perform the update
		llResult = iObj_setLogical(obj, var, &obj->pa.font->isItalic);
		if (llResult)
			iiFont_refresh(obj->pa.font);		// Refresh the font with its new settings

		// Indicate our status
		return(llResult);
	}

	// If we get here, failure
	return(false);
}

SVariable* iObj_getFontItalic(SObject* obj)
{
	if (obj)
		return(iObj_getLogical(obj, obj->pa.font->isItalic));

	// If we get here, failure
	return(NULL);
}

bool iObj_setFontUnderline(SObject* obj, SVariable* var)
{
	bool	llResult;


	// Make sure our environment is sane
	if (obj)
	{
		// Perform the update
		llResult = iObj_setLogical(obj, var, &obj->pa.font->isUnderline);
		if (llResult)
			iiFont_refresh(obj->pa.font);		// Refresh the font with its new settings

		// Indicate our status
		return(llResult);
	}

	// If we get here, failure
	return(false);
}

SVariable* iObj_getFontUnderline(SObject* obj)
{
	if (obj)
		return(iObj_getLogical(obj, obj->pa.font->isUnderline));

	// If we get here, failure
	return(NULL);
}

bool iObj_setFontStrikethrough(SObject* obj, SVariable* var)
{
	bool	llResult;


	// Make sure our environment is sane
	if (obj)
	{
		// Perform the update
		llResult = iObj_setLogical(obj, var, &obj->pa.font->isStrikethrough);
		if (llResult)
			iiFont_refresh(obj->pa.font);		// Refresh the font with its new settings

		// Indicate our status
		return(llResult);
	}

	// If we get here, failure
	return(false);
}

SVariable* iObj_getFontStrikethrough(SObject* obj)
{
	if (obj)
		return(iObj_getLogical(obj, obj->pa.font->isStrikethrough));

	// If we get here, failure
	return(NULL);
}

bool iObj_setFontCondensed(SObject* obj, SVariable* var)
{
	bool	llResult;


	// Make sure our environment is sane
	if (obj)
	{
		// Perform the update
		llResult = iObj_setLogical(obj, var, &obj->pa.font->isCondensed);
		if (llResult)
			iiFont_refresh(obj->pa.font);		// Refresh the font with its new settings

		// Indicate our status
		return(llResult);
	}

	// If we get here, failure
	return(false);
}

SVariable* iObj_getFontCondensed(SObject* obj)
{
	if (obj)
		return(iObj_getLogical(obj, obj->pa.font->isCondensed));

	// If we get here, failure
	return(NULL);
}

bool iObj_setFontExtended(SObject* obj, SVariable* var)
{
	bool llResult;


	// Make sure our environment is sane
	if (obj)
	{
		// Perform the update
		llResult = iObj_setLogical(obj, var, &obj->pa.font->isExtended);
		if (llResult)
			iiFont_refresh(obj->pa.font);		// Refresh the font with its new settings

		// Indicate our status
		return(llResult);
	}

	// If we get here, failure
	return(false);
}

SVariable* iObj_getFontExtended(SObject* obj)
{
	if (obj)
		return(iObj_getLogical(obj, obj->pa.font->isExtended));

	// If we get here, failure
	return(NULL);
}

bool iObj_setFontOutline(SObject* obj, SVariable* var)
{
	bool	llResult;


	// Make sure our environment is sane
	if (obj)
	{
		// Perform the update
		llResult = iObj_setLogical(obj, var, &obj->pa.font->isOutline);
		if (llResult)
			iiFont_refresh(obj->pa.font);		// Refresh the font with its new settings

		// Indicate our status
		return(llResult);
	}

	// If we get here, failure
	return(false);
}

SVariable* iObj_getFontOutline(SObject* obj)
{
	if (obj)
		return(iObj_getLogical(obj, obj->pa.font->isOutline));

	// If we get here, failure
	return(NULL);
}

bool iObj_setFontShadow(SObject* obj, SVariable* var)
{
	bool	llResult;


	// Make sure our environment is sane
	if (obj)
	{
		// Perform the update
		llResult = iObj_setLogical(obj, var, &obj->pa.font->isShadow);
		if (llResult)
			iiFont_refresh(obj->pa.font);		// Refresh the font with its new settings

		// Indicate our status
		return(llResult);
	}

	// If we get here, failure
	return(false);
}

SVariable* iObj_getFontShadow(SObject* obj)
{
	if (obj)
		return(iObj_getLogical(obj, obj->pa.font->isShadow));

	// If we get here, failure
	return(NULL);
}

bool iObj_setNwColor(SObject* obj, SVariable* var)
{
	if (obj)
		return(iObj_setInteger(obj, var, (s32*)&obj->p.nwRgba.color, 0, 0, false, 0));

	// If we get here, failure
	return(false);
}

SVariable* iObj_getNwColor(SObject* obj)
{
	if (obj)
		return(iObj_getInteger(obj, obj->p.nwRgba.color));

	// If we get here, failure
	return(NULL);
}

bool iObj_setNeColor(SObject* obj, SVariable* var)
{
	if (obj)
		return(iObj_setInteger(obj, var, (s32*)&obj->p.neRgba.color, 0, 0, false, 0));

	// If we get here, failure
	return(false);
}

SVariable* iObj_getNeColor(SObject* obj)
{
	if (obj)
		return(iObj_getInteger(obj, obj->p.neRgba.color));

	// If we get here, failure
	return(NULL);
}

bool iObj_setSwColor(SObject* obj, SVariable* var)
{
	if (obj)
		return(iObj_setInteger(obj, var, (s32*)&obj->p.swRgba.color, 0, 0, false, 0));

	// If we get here, failure
	return(false);
}

SVariable* iObj_getSwColor(SObject* obj)
{
	if (obj)
		return(iObj_getInteger(obj, obj->p.swRgba.color));

	// If we get here, failure
	return(NULL);
}

bool iObj_setSeColor(SObject* obj, SVariable* var)
{
	if (obj)
		return(iObj_setInteger(obj, var, (s32*)&obj->p.seRgba.color, 0, 0, false, 0));

	// If we get here, failure
	return(false);
}

SVariable* iObj_getSeColor(SObject* obj)
{
	if (obj)
		return(iObj_getInteger(obj, obj->p.seRgba.color));

	// If we get here, failure
	return(NULL);
}

bool iObj_setBackColor(SObject* obj, SVariable* var)
{
	if (obj)
		return(iObj_setInteger(obj, var, (s32*)&obj->p.backColor.color, 0, 0, false, 0));

	// If we get here, failure
	return(false);
}

SVariable* iObj_getBackColor(SObject* obj)
{
	if (obj)
		return(iObj_getInteger(obj, obj->p.backColor.color));

	// If we get here, failure
	return(NULL);
}

bool iObj_setForeColor(SObject* obj, SVariable* var)
{
	if (obj)
		return(iObj_setInteger(obj, var, (s32*)&obj->p.foreColor.color, 0, 0, false, 0));

	// If we get here, failure
	return(false);
}

SVariable* iObj_getForeColor(SObject* obj)
{
	if (obj)
		return(iObj_getInteger(obj, obj->p.foreColor.color));

	// If we get here, failure
	return(NULL);
}

bool iObj_setCaptionColor(SObject* obj, SVariable* var)
{
	if (obj)
		return(iObj_setInteger(obj, var, (s32*)&obj->p.captionColor.color, 0, 0, false, 0));

	// If we get here, failure
	return(false);
}

SVariable* iObj_getCaptionColor(SObject* obj)
{
	if (obj)
		return(iObj_getInteger(obj, obj->p.captionColor.color));

	// If we get here, failure
	return(NULL);
}

bool iObj_setCaption(SObject* obj, SVariable* var)
{
	bool		llResult;
	SObject*	objChild;


	llResult = false;
	if (obj)
	{
		// Set the main caption
		obj->isDirtyRender = true;
		if ((llResult = iObj_setCharacter(obj, var, &obj->pa.caption, var->value.data, var->value.length)))
		{
			switch (obj->objType)
			{
				case _OBJ_TYPE_FORM:
				case _OBJ_TYPE_SUBFORM:
					objChild = obj->firstChild;
					while (objChild)
					{
						// Is this one
						if (objChild->objType == _OBJ_TYPE_LABEL && iDatum_compare(&objChild->pa.name, cgcCaption_icon, sizeof(cgcCaption_icon) - 1) == 0)
						{
							// Update this item
							llResult				= iObj_setCharacter(objChild, var, &objChild->pa.caption, var->value.data, var->value.length);
							objChild->isDirtyRender	= true;

							// All done
							break;
						}

						// Move to next sibling
						objChild = (SObject*)objChild->ll.next;
					}
					break;

				case _OBJ_TYPE_CHECKBOX:
					objChild = obj->firstChild;
					while (objChild)
					{
						// Is this one
						if (objChild->objType == _OBJ_TYPE_LABEL && iDatum_compare(&objChild->pa.name, cgcName_checkboxLabel, sizeof(cgcName_checkboxLabel) - 1) == 0)
						{
							// Update this item
							llResult				= iObj_setCharacter(objChild, var, &objChild->pa.caption, var->value.data, var->value.length);
							objChild->isDirtyRender	= true;

							// All done
							break;
						}

						// Move to next sibling
						objChild = (SObject*)objChild->ll.next;
					}
					break;
			}
		}
	}

	// Indicate our status
	return(llResult);
}

SVariable* iObj_getCaption(SObject* obj)
{
	if (obj)
		return(iObj_getCharacter(obj, &obj->pa.caption));

	// If we get here, failure
	return(NULL);
}

bool iObj_setPicture(SObject* obj, SVariable* var)
{
	if (obj)
		return(iObj_setCharacter(obj, var, &obj->pa.pictureName, var->value.data, var->value.length));

	// If we get here, failure
	return(false);
}

SVariable* iObj_getPicture(SObject* obj)
{
	if (obj)
		return(iObj_getCharacter(obj, &obj->pa.pictureName));

	// If we get here, failure
	return(NULL);
}

bool iObj_setAllowOutput(SObject* obj, SVariable* var)
{
	if (obj)
		return(iObj_setLogical(obj, var, &obj->p.allowOutput));

	// If we get here, failure
	return(false);
}

SVariable* iObj_getAllowOutput(SObject* obj)
{
	if (obj)
		return(iObj_getLogical(obj, obj->p.allowOutput));

	// If we get here, failure
	return(NULL);
}

bool iObj_setAlwaysOnBottom(SObject* obj, SVariable* var)
{
	if (obj)
		return(iObj_setLogical(obj, var, &obj->p.alwaysOnBottom));

	// If we get here, failure
	return(false);
}

SVariable* iObj_getAlwaysOnBottom(SObject* obj)
{
	if (obj)
		return(iObj_getLogical(obj, obj->p.alwaysOnBottom));

	// If we get here, failure
	return(NULL);
}

bool iObj_setAlwaysOnTop(SObject* obj, SVariable* var)
{
	if (obj)
		return(iObj_setLogical(obj, var, &obj->p.alwaysOnTop));

	// If we get here, failure
	return(false);
}

SVariable* iObj_getAlwaysOnTop(SObject* obj)
{
	if (obj)
		return(iObj_getLogical(obj, obj->p.alwaysOnTop));

	// If we get here, failure
	return(NULL);
}

bool iObj_setAutoCenter(SObject* obj, SVariable* var)
{
	if (obj)
		return(iObj_setLogical(obj, var, &obj->p.autoCenter));

	// If we get here, failure
	return(false);
}

SVariable* iObj_getAutoCenter(SObject* obj)
{
	if (obj)
		return(iObj_getLogical(obj, obj->p.autoCenter));

	// If we get here, failure
	return(NULL);
}

bool iObj_setBorderStyle(SObject* obj, SVariable* var)
{
	if (obj)
		return(iObj_setInteger(obj, var, (s32*)&obj->p.borderStyle, 0, 3, true, 0));

	// If we get here, failure
	return(false);
}

SVariable* iObj_getBorderStyle(SObject* obj)
{
	if (obj)
		return(iObj_getInteger(obj, obj->p.borderStyle));

	// If we get here, failure
	return(NULL);
}

bool iObj_setIsCloseable(SObject* obj, SVariable* var)
{
	if (obj)
		return(iObj_setLogical(obj, var, &obj->p.isClosable));

	// If we get here, failure
	return(false);
}

SVariable* iObj_getIsCloseable(SObject* obj)
{
	if (obj)
		return(iObj_getLogical(obj, obj->p.isClosable));

	// If we get here, failure
	return(NULL);
}

bool iObj_setProcessKeyPreviewEvents(SObject* obj, SVariable* var)
{
	if (obj)
		return(iObj_setLogical(obj, var, &obj->p.processKeyPreviewEvents));

	// If we get here, failure
	return(false);
}

SVariable* iObj_getProcessKeyPreviewEvents(SObject* obj)
{
	if (obj)
		return(iObj_getLogical(obj, obj->p.processKeyPreviewEvents));

	// If we get here, failure
	return(NULL);
}

bool iObj_setHasControlBox(SObject* obj, SVariable* var)
{
	if (obj)
		return(iObj_setLogical(obj, var, &obj->p.hasControlBox));

	// If we get here, failure
	return(false);
}

SVariable* iObj_getHasControlBox(SObject* obj)
{
	if (obj)
		return(iObj_getLogical(obj, obj->p.hasControlBox));

	// If we get here, failure
	return(NULL);
}

bool iObj_setHasMinButton(SObject* obj, SVariable* var)
{
	if (obj)
		return(iObj_setLogical(obj, var, &obj->p.hasMinButton));

	// If we get here, failure
	return(false);
}

SVariable* iObj_getHasMinButton(SObject* obj)
{
	if (obj)
		return(iObj_getLogical(obj, obj->p.hasMinButton));

	// If we get here, failure
	return(NULL);
}

bool iObj_setHasCloseButton(SObject* obj, SVariable* var)
{
	if (obj)
		return(iObj_setLogical(obj, var, &obj->p.hasCloseButton));

	// If we get here, failure
	return(false);
}

SVariable* iObj_getHasCloseButton(SObject* obj)
{
	if (obj)
		return(iObj_getLogical(obj, obj->p.hasCloseButton));

	// If we get here, failure
	return(NULL);
}

bool iObj_setScaleMode(SObject* obj, SVariable* var)
{
	if (obj)
		return(iObj_setInteger(obj, var, (s32*)&obj->p.scaleMode, 0, 0, false, (u32)&iObj_setScaleMode_extraTest));

	// If we get here, failure
	return(false);
}

bool iObj_setScaleMode_extraTest(s32 value)
{
	if (value == 0 || value == 3)		return(true);
	else								return(false);
}

SVariable* iObj_getScaleMode(SObject* obj)
{
	if (obj)
		return(iObj_getInteger(obj, obj->p.scaleMode));

	// If we get here, failure
	return(NULL);
}

bool iObj_setShowInTaskBar(SObject* obj, SVariable* var)
{
	if (obj)
		return(iObj_setLogical(obj, var, &obj->p.showInTaskBar));

	// If we get here, failure
	return(false);
}

SVariable* iObj_getShowInTaskBar(SObject* obj)
{
	if (obj)
		return(iObj_getLogical(obj, obj->p.showInTaskBar));

	// If we get here, failure
	return(NULL);
}

bool iObj_setWindowState(SObject* obj, SVariable* var)
{
	if (obj)
		return(iObj_setInteger(obj, var, (s32*)&obj->p.windowState, 0, 1, true, 0));

	// If we get here, failure
	return(false);
}

SVariable* iObj_getWindowState(SObject* obj)
{
	if (obj)
		return(iObj_getInteger(obj, obj->p.windowState));

	// If we get here, failure
	return(NULL);
}

bool iObj_setBindControls(SObject* obj, SVariable* var)
{
	if (obj)
		return(iObj_setLogical(obj, var, &obj->p.bindControls));

	// If we get here, failure
	return(false);
}

SVariable* iObj_getBindControls(SObject* obj)
{
	if (obj)
		return(iObj_getLogical(obj, obj->p.bindControls));

	// If we get here, failure
	return(NULL);
}

bool iObj_setBufferMode(SObject* obj, SVariable* var)
{
	if (obj)
		return(iObj_setInteger(obj, var, (s32*)&obj->p.bufferMode, 0, 1, true, 0));

	// If we get here, failure
	return(false);
}

SVariable* iObj_getBufferMode(SObject* obj)
{
	if (obj)
		return(iObj_getInteger(obj, obj->p.bufferMode));

	// If we get here, failure
	return(NULL);
}

bool iObj_setClipControls(SObject* obj, SVariable* var)
{
	if (obj)
		return(iObj_setLogical(obj, var, &obj->p.clipControls));

	// If we get here, failure
	return(false);
}

SVariable* iObj_getClipControls(SObject* obj)
{
	if (obj)
		return(iObj_getLogical(obj, obj->p.clipControls));

	// If we get here, failure
	return(NULL);
}

bool iObj_setColorSource(SObject* obj, SVariable* var)
{
	if (obj)
		return(iObj_setInteger(obj, var, (s32*)&obj->p.colorSource, 0, 0, false, 0));

	// If we get here, failure
	return(false);
}

SVariable* iObj_getColorSource(SObject* obj)
{
	if (obj)
		return(iObj_getInteger(obj, obj->p.colorSource));

	// If we get here, failure
	return(NULL);
}

bool iObj_setContinuousScroll(SObject* obj, SVariable* var)
{
	if (obj)
		return(iObj_setLogical(obj, var, &obj->p.continuousScroll));

	// If we get here, failure
	return(false);
}

SVariable* iObj_getContinuousScroll(SObject* obj)
{
	if (obj)
		return(iObj_getLogical(obj, obj->p.continuousScroll));

	// If we get here, failure
	return(NULL);
}

bool iObj_setDataSession(SObject* obj, SVariable* var)
{
	return(false);
}

SVariable* iObj_getDataSession(SObject* obj)
{
	return(NULL);
}

bool iObj_setDataSessionId(SObject* obj, SVariable* var)
{
	if (obj)
		return(iObj_setInteger(obj, var, (s32*)&obj->p.dataSessionId, 0, 0, false, 0));

	// If we get here, failure
	return(false);
}

SVariable* iObj_getDataSessionId(SObject* obj)
{
	if (obj)
		return(iObj_getInteger(obj, obj->p.dataSessionId));

	// If we get here, failure
	return(NULL);
}

bool iObj_setDeClass(SObject* obj, SVariable* var)
{
	if (obj)
		return(iObj_setCharacter(obj, var, &obj->pa.declass, var->value.data, var->value.length));

	// If we get here, failure
	return(false);
}

SVariable* iObj_getDeClass(SObject* obj)
{
	if (obj)
		return(iObj_getCharacter(obj, &obj->pa.declass));

	// If we get here, failure
	return(NULL);
}

bool iObj_setDeClassLibrary(SObject* obj, SVariable* var)
{
	if (obj)
		return(iObj_setCharacter(obj, var, &obj->pa.declasslibrary, var->value.data, var->value.length));

	// If we get here, failure
	return(false);
}

SVariable* iObj_getDeClassLibrary(SObject* obj)
{
	if (obj)
		return(iObj_getCharacter(obj, &obj->pa.declasslibrary));

	// If we get here, failure
	return(NULL);
}

bool iObj_setDefOleCid(SObject* obj, SVariable* var)
{
	if (obj)
		return(iObj_setInteger(obj, var, (s32*)&obj->p.defolecid, 0, 0, false, 0));

	// If we get here, failure
	return(false);
}

SVariable* iObj_getDefOleCid(SObject* obj)
{
	if (obj)
		return(iObj_getInteger(obj, obj->p.defolecid));

	// If we get here, failure
	return(NULL);
}

bool iObj_setDesktop(SObject* obj, SVariable* var)
{
	if (obj)
		return(iObj_setLogical(obj, var, &obj->p.desktop));

	// If we get here, failure
	return(false);
}

SVariable* iObj_getDesktop(SObject* obj)
{
	if (obj)
		return(iObj_getLogical(obj, obj->p.desktop));

	// If we get here, failure
	return(NULL);
}

bool iObj_setIsDockable(SObject* obj, SVariable* var)
{
	if (obj)
		return(iObj_setLogical(obj, var, &obj->p.isDockable));

	// If we get here, failure
	return(false);
}

SVariable* iObj_getIsDockable(SObject* obj)
{
	if (obj)
		return(iObj_getLogical(obj, obj->p.isDockable));

	// If we get here, failure
	return(NULL);
}

bool iObj_setIsDocked(SObject* obj, SVariable* var)
{
	if (obj)
		return(iObj_setLogical(obj, var, &obj->p.isDocked));

	// If we get here, failure
	return(false);
}

SVariable* iObj_getIsDocked(SObject* obj)
{
	if (obj)
		return(iObj_getLogical(obj, obj->p.isDocked));

	// If we get here, failure
	return(NULL);
}

bool iObj_setDockPosition(SObject* obj, SVariable* var)
{
	if (obj)
		return(iObj_setInteger(obj, var, (s32*)&obj->p.dockPosition, 0, 0, false, 0));

	// If we get here, failure
	return(false);
}

SVariable* iObj_getDockPosition(SObject* obj)
{
	if (obj)
		return(iObj_getInteger(obj, obj->p.dockPosition));

	// If we get here, failure
	return(NULL);
}

bool iObj_setDrawMode(SObject* obj, SVariable* var)
{
	if (obj)
		return(iObj_setInteger(obj, var, (s32*)&obj->p.drawmode, 0, 0, false, 0));

	// If we get here, failure
	return(false);
}

SVariable* iObj_getDrawMode(SObject* obj)
{
	if (obj)
		return(iObj_getInteger(obj, obj->p.drawmode));

	// If we get here, failure
	return(NULL);
}

bool iObj_setDrawStyle(SObject* obj, SVariable* var)
{
	if (obj)
		return(iObj_setInteger(obj, var, (s32*)&obj->p.drawstyle, 0, 0, false, 0));

	// If we get here, failure
	return(false);
}

SVariable* iObj_getDrawStyle(SObject* obj)
{
	if (obj)
		return(iObj_getInteger(obj, obj->p.drawstyle));

	// If we get here, failure
	return(NULL);
}

bool iObj_setDrawWidth(SObject* obj, SVariable* var)
{
	if (obj)
		return(iObj_setInteger(obj, var, (s32*)&obj->p.drawwidth, 0, 0, false, 0));

	// If we get here, failure
	return(false);
}

SVariable* iObj_getDrawWidth(SObject* obj)
{
	if (obj)
		return(iObj_getInteger(obj, obj->p.drawwidth));

	// If we get here, failure
	return(NULL);
}

bool iObj_setFillColor(SObject* obj, SVariable* var)
{
	if (obj)
		return(iObj_setInteger(obj, var, (s32*)&obj->p.fillColor.color, 0, 0, false, 0));

	// If we get here, failure
	return(false);
}

SVariable* iObj_getFillColor(SObject* obj)
{
	if (obj)
		return(iObj_getInteger(obj, obj->p.fillColor.color));

	// If we get here, failure
	return(NULL);
}

bool iObj_setFillStyle(SObject* obj, SVariable* var)
{
	if (obj)
		return(iObj_setInteger(obj, var, (s32*)&obj->p.fillStyle, 0, 0, false, 0));

	// If we get here, failure
	return(false);
}

SVariable* iObj_getFillStyle(SObject* obj)
{
	if (obj)
		return(iObj_getInteger(obj, obj->p.fillStyle));

	// If we get here, failure
	return(NULL);
}

bool iObj_setHalfHeightCaption(SObject* obj, SVariable* var)
{
	if (obj)
		return(iObj_setLogical(obj, var, &obj->p.halfHeightCaption));

	// If we get here, failure
	return(false);
}

SVariable* iObj_getHalfHeightCaption(SObject* obj)
{
	if (obj)
		return(iObj_getLogical(obj, obj->p.halfHeightCaption));

	// If we get here, failure
	return(NULL);
}

bool iObj_setHScrollSmallChange(SObject* obj, SVariable* var)
{
	if (obj)
		return(iObj_setInteger(obj, var, (s32*)&obj->p.hScrollSmallChange, 0, 0, false, 0));

	// If we get here, failure
	return(false);
}

SVariable* iObj_getHScrollSmallChange(SObject* obj)
{
	if (obj)
		return(iObj_getInteger(obj, obj->p.hScrollSmallChange));

	// If we get here, failure
	return(NULL);
}

bool iObj_setVScrollSmallChange(SObject* obj, SVariable* var)
{
	if (obj)
		return(iObj_setInteger(obj, var, (s32*)&obj->p.vScrollSmallChange, 0, 0, false, 0));

	// If we get here, failure
	return(false);
}

SVariable* iObj_getVScrollSmallChange(SObject* obj)
{
	if (obj)
		return(iObj_getInteger(obj, obj->p.vScrollSmallChange));

	// If we get here, failure
	return(NULL);
}

bool iObj_setMacDesktop(SObject* obj, SVariable* var)
{
	if (obj)
		return(iObj_setLogical(obj, var, &obj->p.macDesktop));

	// If we get here, failure
	return(false);
}

SVariable* iObj_getMacDesktop(SObject* obj)
{
	if (obj)
		return(iObj_getLogical(obj, obj->p.macDesktop));

	// If we get here, failure
	return(NULL);
}

bool iObj_setMdiForm(SObject* obj, SVariable* var)
{
	if (obj)
		return(iObj_setLogical(obj, var, &obj->p.mdiForm));

	// If we get here, failure
	return(false);
}

SVariable* iObj_getMdiForm(SObject* obj)
{
	if (obj)
		return(iObj_getLogical(obj, obj->p.mdiForm));

	// If we get here, failure
	return(NULL);
}

bool iObj_setOleDragMode(SObject* obj, SVariable* var)
{
	if (obj)
		return(iObj_setInteger(obj, var, (s32*)&obj->p.oleDragMode, 0, 0, false, 0));

	// If we get here, failure
	return(false);
}

SVariable* iObj_getOleDragMode(SObject* obj)
{
	if (obj)
		return(iObj_getInteger(obj, obj->p.oleDragMode));

	// If we get here, failure
	return(NULL);
}

bool iObj_setOleDropEffects(SObject* obj, SVariable* var)
{
	if (obj)
		return(iObj_setInteger(obj, var, (s32*)&obj->p.oleDropEffects, 0, 0, false, 0));

	// If we get here, failure
	return(false);
}

SVariable* iObj_getOleDropEffects(SObject* obj)
{
	if (obj)
		return(iObj_getInteger(obj, obj->p.oleDropEffects));

	// If we get here, failure
	return(NULL);
}

bool iObj_setOleDropHasData(SObject* obj, SVariable* var)
{
	if (obj)
		return(iObj_setInteger(obj, var, (s32*)&obj->p.oleDropHasData, 0, 0, false, 0));

	// If we get here, failure
	return(false);
}

SVariable* iObj_getOleDropHasData(SObject* obj)
{
	if (obj)
		return(iObj_getInteger(obj, obj->p.oleDropHasData));

	// If we get here, failure
	return(NULL);
}

bool iObj_setOleDropMode(SObject* obj, SVariable* var)
{
	if (obj)
		return(iObj_setInteger(obj, var, (s32*)&obj->p.oleDropMode, 0, 0, false, 0));

	// If we get here, failure
	return(false);
}

SVariable* iObj_getOleDropMode(SObject* obj)
{
	if (obj)
		return(iObj_getInteger(obj, obj->p.oleDropMode));

	// If we get here, failure
	return(NULL);
}

bool iObj_setReleaseType(SObject* obj, SVariable* var)
{
	if (obj)
		return(iObj_setInteger(obj, var, (s32*)&obj->p.releaseType, 0, 0, false, 0));

	// If we get here, failure
	return(false);
}

SVariable* iObj_getReleaseType(SObject* obj)
{
	if (obj)
		return(iObj_getInteger(obj, obj->p.releaseType));

	// If we get here, failure
	return(NULL);
}

bool iObj_setRightToLeft(SObject* obj, SVariable* var)
{
	if (obj)
		return(iObj_setLogical(obj, var, &obj->p.rightToLeft));

	// If we get here, failure
	return(false);
}

SVariable* iObj_getRightToLeft(SObject* obj)
{
	if (obj)
		return(iObj_getLogical(obj, obj->p.rightToLeft));

	// If we get here, failure
	return(NULL);
}

bool iObj_setScrollbars(SObject* obj, SVariable* var)
{
	if (obj)
		return(iObj_setInteger(obj, var, (s32*)&obj->p.scrollbars, 0, 0, false, 0));

	// If we get here, failure
	return(false);
}

SVariable* iObj_getScrollbars(SObject* obj)
{
	if (obj)
		return(iObj_getInteger(obj, obj->p.scrollbars));

	// If we get here, failure
	return(NULL);
}

bool iObj_setShowTips(SObject* obj, SVariable* var)
{
	if (obj)
		return(iObj_setInteger(obj, var, (s32*)&obj->p.showTips, 0, 0, false, 0));

	// If we get here, failure
	return(false);
}

SVariable* iObj_getShowTips(SObject* obj)
{
	if (obj)
		return(iObj_getInteger(obj, obj->p.showTips));

	// If we get here, failure
	return(NULL);
}

bool iObj_setShowWindow(SObject* obj, SVariable* var)
{
	if (obj)
		return(iObj_setInteger(obj, var, (s32*)&obj->p.showWindow, 0, 0, false, 0));

	// If we get here, failure
	return(false);
}

SVariable* iObj_getShowWindow(SObject* obj)
{
	if (obj)
		return(iObj_getInteger(obj, obj->p.showWindow));

	// If we get here, failure
	return(NULL);
}

bool iObj_setSizeBox(SObject* obj, SVariable* var)
{
	if (obj)
		return(iObj_setLogical(obj, var, &obj->p.sizeBox));

	// If we get here, failure
	return(false);
}

SVariable* iObj_getSizeBox(SObject* obj)
{
	if (obj)
		return(iObj_getLogical(obj, obj->p.sizeBox));

	// If we get here, failure
	return(NULL);
}

bool iObj_setThemes(SObject* obj, SVariable* var)
{
	if (obj)
		return(iObj_setLogical(obj, var, &obj->p.themes));

	// If we get here, failure
	return(false);
}

SVariable* iObj_getThemes(SObject* obj)
{
	if (obj)
		return(iObj_getLogical(obj, obj->p.themes));

	// If we get here, failure
	return(NULL);
}

bool iObj_setTitleBar(SObject* obj, SVariable* var)
{
	if (obj)
		return(iObj_setInteger(obj, var, (s32*)&obj->p.titleBar, 0, 0, false, 0));

	// If we get here, failure
	return(false);
}

SVariable* iObj_getTitleBar(SObject* obj)
{
	if (obj)
		return(iObj_getInteger(obj, obj->p.titleBar));

	// If we get here, failure
	return(NULL);
}

bool iObj_setWindowType(SObject* obj, SVariable* var)
{
	if (obj)
		return(iObj_setInteger(obj, var, (s32*)&obj->p.windowType, 0, 0, false, 0));

	// If we get here, failure
	return(false);
}

SVariable* iObj_getWindowType(SObject* obj)
{
	if (obj)
		return(iObj_getInteger(obj, obj->p.windowType));

	// If we get here, failure
	return(NULL);
}

bool iObj_setZoomBox(SObject* obj, SVariable* var)
{
	if (obj)
		return(iObj_setLogical(obj, var, &obj->p.zoomBox));

	// If we get here, failure
	return(false);
}

SVariable* iObj_getZoomBox(SObject* obj)
{
	if (obj)
		return(iObj_getLogical(obj, obj->p.zoomBox));

	// If we get here, failure
	return(NULL);
}


bool iObj_set_activeColumn(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_activeControl(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_activeForm(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_activePage(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_activeRow(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_addLineFeeds(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_align(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_alignment(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_allowAddNew(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_allowAutoColumnFit(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_allowCellSelection(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_allowHeaderSizing(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_allowOutput(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_allowRowSizing(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_allowTabs(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_alwaysOnBottom(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_alwaysOnTop(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_anchor(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_application(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_autoActivate(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_autoCenter(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_autoCompSource(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_autoCompTable(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_autoComplete(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_autoHideScrollBar(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_autoRelease(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_autoSize(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_autoVerbMenu(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_backColor(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_backStyle(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_baseClass(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_bindControls(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_borderColor(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_borderStyle(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_borderWidth(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_bound(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_boundColumn(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_boundTo(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_bufferMode(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_buttonCount(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_cancel(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_caption(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_centered(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_century(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_childOrder(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_class(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_classLibrary(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_clipControls(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_closable(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_colorScheme(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_colorSource(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_columnCount(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_columnLines(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_columnOrder(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_columnWidths(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_columns(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_comment(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_continuousScroll(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_controlBox(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_controlCount(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_controlSource(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_controls(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_count(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_currentControl(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_currentX(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_currentY(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_curvature(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_dEClass(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_dEClassLibrary(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_dataEnvironment(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_dataSession(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_dataSessionID(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_dateFormat(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_dateMark(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_defOLELCID(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_default(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_deleteMark(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_desktop(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_details(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_disabledBackColor(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_disabledForeColor(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_disabledItemBackColor(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_disabledItemForeColor(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_disabledPicture(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_displayCount(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_displayValue(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_doCreate(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_dockPosition(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_dockable(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_docked(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_documentFile(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_downPicture(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_dragIcon(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_dragMode(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_drawMode(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_drawStyle(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_drawWidth(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_dynamicAlignment(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_dynamicBackColor(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_dynamicCurrentControl(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_dynamicFontBold(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_dynamicFontItalic(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_dynamicFontName(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_dynamicFontOutline(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_dynamicFontShadow(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_dynamicFontSize(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_dynamicFontStrikeThru(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_dynamicFontUnderline(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_dynamicForeColor(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_dynamicInputMask(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_enableHyperlinks(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_enabled(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_errorNo(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_fillColor(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_fillStyle(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_firstElement(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_fontBold(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_fontCharSet(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_fontCondense(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_fontExtend(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_fontItalic(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_fontName(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_fontOutline(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_fontShadow(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_fontSize(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_fontStrikeThru(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_fontUnderLine(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_fontUnderline(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_foreColor(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_formCount(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_format(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_forms(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_gridLineColor(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_gridLineWidth(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_gridLines(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_hScrollSmallChange(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_hWnd(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_halfHeightCaption(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_headerClass(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_headerClassLibrary(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_headerHeight(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_height(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_helpContextID(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_hideSelection(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_highLight(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_highLightRow(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_highlightBackColor(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_highlightForeColor(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_highlightRowLineWidth(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_highlightStyle(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_hostName(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_hours(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_iMEMode(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_icon(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_increment(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_incrementalSearch(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_inputMask(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_integralHeight(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_interval(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_itemBackColor(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_itemData(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_itemForeColor(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_itemIDData(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_itemTips(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_keyPreview(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_keySort(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_keyboardHighValue(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_keyboardLowValue(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_left(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_leftColumn(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_lineContents(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_lineNo(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_lineSlant(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_linkMaster(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_list(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_listCount(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_listIndex(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_listItem(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_listItemID(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_lockColumns(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_lockColumnsLeft(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_lockScreen(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_mDIForm(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_macDesktop(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_margin(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_maxButton(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_maxHeight(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_maxLeft(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_maxLength(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_maxTop(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_maxWidth(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_memberClass(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_memberClassLibrary(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_memoWindow(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_message(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_minButton(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_minHeight(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_minWidth(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_mouseIcon(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_mousePointer(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_movable(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_moverBars(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_multiSelect(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_name(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_newIndex(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_newItemID(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_nullDisplay(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_numberOfElements(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_oLEClass(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_oLEDragMode(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_oLEDragPicture(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_oLEDropEffects(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_oLEDropHasData(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_oLEDropMode(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_oLEDropTextInsertion(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_oLELCID(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_oLETypeAllowed(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_object(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_objects(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_openWindow(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_optimize(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_pageCount(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_pageHeight(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_pageOrder(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_pageWidth(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_pages(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_panel(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_panelLink(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_parent(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_parentClass(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_partition(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_passwordChar(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_picture(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_pictureMargin(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_picturePosition(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_pictureSelectionDisplay(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_pictureSpacing(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_pictureVal(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_polyPoints(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_procedure(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_readBackColor(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_readCycle(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_readForeColor(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_readLock(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_readMouse(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_readOnly(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_readSave(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_readTimeOut(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_recordMark(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_recordSource(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_recordSourceType(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_relationalExpr(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_relativeColumn(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_relativeRow(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_releaseType(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_resizable(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_rightToLeft(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_rotateFlip(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_rotation(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_rowColChange(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_rowHeight(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_rowSource(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_rowSourceType(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_scaleMode(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_scrollBars(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_seconds(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_selLength(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_selStart(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_selText(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_selectOnEntry(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_selected(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_selectedBackColor(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_selectedForeColor(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_selectedID(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_selectedItemBackColor(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_selectedItemForeColor(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_showInTaskbar(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_showTips(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_showWindow(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_sizable(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_sizeBox(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_sorted(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_sparse(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_specialEffect(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_spinnerHighValue(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_spinnerLowValue(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_splitBar(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_stackLevel(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_statusBarText(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_stretch(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_strictDateEntry(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_style(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_tabIndex(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_tabOrientation(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_tabStop(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_tabStyle(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_tabs(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_tag(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_terminateRead(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_text(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_themes(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_titleBar(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_toolTipText(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_top(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_topIndex(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_topItemID(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_userValue(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_vScrollSmallChange(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_value(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_view(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_viewPortHeight(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_viewPortLeft(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_viewPortTop(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_viewPortWidth(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_visible(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_visualEffect(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_whatsThisButton(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_whatsThisHelp(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_whatsThisHelpID(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_width(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_windowList(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_windowState(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_windowType(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_wordWrap(SObject* obj, SVariable* var)
{
	return(false);
}

bool iObj_set_zoomBox(SObject* obj, SVariable* var)
{
	return(false);
}

SVariable* iObj_get_activeColumn(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_activeControl(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_activeForm(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_activePage(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_activeRow(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_addLineFeeds(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_align(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_alignment(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_allowAddNew(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_allowAutoColumnFit(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_allowCellSelection(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_allowHeaderSizing(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_allowOutput(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_allowRowSizing(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_allowTabs(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_alwaysOnBottom(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_alwaysOnTop(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_anchor(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_application(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_autoActivate(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_autoCenter(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_autoCompSource(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_autoCompTable(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_autoComplete(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_autoHideScrollBar(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_autoRelease(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_autoSize(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_autoVerbMenu(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_backColor(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_backStyle(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_baseClass(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_bindControls(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_borderColor(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_borderStyle(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_borderWidth(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_bound(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_boundColumn(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_boundTo(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_bufferMode(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_buttonCount(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_cancel(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_caption(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_centered(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_century(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_childOrder(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_class(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_classLibrary(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_clipControls(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_closable(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_colorScheme(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_colorSource(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_columnCount(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_columnLines(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_columnOrder(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_columnWidths(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_columns(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_comment(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_continuousScroll(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_controlBox(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_controlCount(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_controlSource(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_controls(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_count(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_currentControl(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_currentX(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_currentY(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_curvature(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_dEClass(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_dEClassLibrary(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_dataEnvironment(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_dataSession(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_dataSessionID(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_dateFormat(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_dateMark(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_defOLELCID(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_default(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_deleteMark(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_desktop(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_details(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_disabledBackColor(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_disabledForeColor(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_disabledItemBackColor(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_disabledItemForeColor(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_disabledPicture(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_displayCount(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_displayValue(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_doCreate(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_dockPosition(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_dockable(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_docked(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_documentFile(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_downPicture(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_dragIcon(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_dragMode(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_drawMode(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_drawStyle(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_drawWidth(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_dynamicAlignment(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_dynamicBackColor(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_dynamicCurrentControl(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_dynamicFontBold(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_dynamicFontItalic(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_dynamicFontName(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_dynamicFontOutline(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_dynamicFontShadow(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_dynamicFontSize(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_dynamicFontStrikeThru(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_dynamicFontUnderline(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_dynamicForeColor(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_dynamicInputMask(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_enableHyperlinks(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_enabled(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_errorNo(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_fillColor(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_fillStyle(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_firstElement(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_fontBold(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_fontCharSet(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_fontCondense(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_fontExtend(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_fontItalic(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_fontName(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_fontOutline(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_fontShadow(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_fontSize(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_fontStrikeThru(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_fontUnderLine(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_fontUnderline(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_foreColor(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_formCount(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_format(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_forms(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_gridLineColor(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_gridLineWidth(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_gridLines(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_hScrollSmallChange(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_hWnd(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_halfHeightCaption(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_headerClass(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_headerClassLibrary(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_headerHeight(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_height(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_helpContextID(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_hideSelection(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_highLight(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_highLightRow(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_highlightBackColor(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_highlightForeColor(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_highlightRowLineWidth(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_highlightStyle(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_hostName(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_hours(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_iMEMode(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_icon(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_increment(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_incrementalSearch(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_inputMask(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_integralHeight(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_interval(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_itemBackColor(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_itemData(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_itemForeColor(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_itemIDData(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_itemTips(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_keyPreview(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_keySort(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_keyboardHighValue(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_keyboardLowValue(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_left(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_leftColumn(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_lineContents(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_lineNo(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_lineSlant(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_linkMaster(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_list(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_listCount(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_listIndex(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_listItem(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_listItemID(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_lockColumns(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_lockColumnsLeft(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_lockScreen(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_mDIForm(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_macDesktop(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_margin(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_maxButton(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_maxHeight(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_maxLeft(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_maxLength(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_maxTop(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_maxWidth(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_memberClass(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_memberClassLibrary(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_memoWindow(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_message(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_minButton(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_minHeight(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_minWidth(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_mouseIcon(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_mousePointer(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_movable(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_moverBars(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_multiSelect(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_name(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_newIndex(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_newItemID(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_nullDisplay(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_numberOfElements(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_oLEClass(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_oLEDragMode(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_oLEDragPicture(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_oLEDropEffects(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_oLEDropHasData(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_oLEDropMode(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_oLEDropTextInsertion(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_oLELCID(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_oLETypeAllowed(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_object(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_objects(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_openWindow(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_optimize(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_pageCount(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_pageHeight(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_pageOrder(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_pageWidth(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_pages(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_panel(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_panelLink(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_parent(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_parentClass(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_partition(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_passwordChar(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_picture(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_pictureMargin(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_picturePosition(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_pictureSelectionDisplay(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_pictureSpacing(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_pictureVal(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_polyPoints(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_procedure(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_readBackColor(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_readCycle(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_readForeColor(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_readLock(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_readMouse(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_readOnly(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_readSave(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_readTimeOut(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_recordMark(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_recordSource(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_recordSourceType(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_relationalExpr(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_relativeColumn(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_relativeRow(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_releaseType(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_resizable(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_rightToLeft(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_rotateFlip(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_rotation(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_rowColChange(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_rowHeight(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_rowSource(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_rowSourceType(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_scaleMode(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_scrollBars(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_seconds(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_selLength(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_selStart(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_selText(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_selectOnEntry(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_selected(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_selectedBackColor(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_selectedForeColor(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_selectedID(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_selectedItemBackColor(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_selectedItemForeColor(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_showInTaskbar(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_showTips(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_showWindow(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_sizable(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_sizeBox(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_sorted(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_sparse(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_specialEffect(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_spinnerHighValue(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_spinnerLowValue(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_splitBar(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_stackLevel(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_statusBarText(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_stretch(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_strictDateEntry(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_style(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_tabIndex(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_tabOrientation(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_tabStop(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_tabStyle(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_tabs(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_tag(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_terminateRead(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_text(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_themes(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_titleBar(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_toolTipText(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_top(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_topIndex(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_topItemID(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_userValue(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_vScrollSmallChange(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_value(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_view(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_viewPortHeight(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_viewPortLeft(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_viewPortTop(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_viewPortWidth(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_visible(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_visualEffect(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_whatsThisButton(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_whatsThisHelp(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_whatsThisHelpID(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_width(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_windowList(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_windowState(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_windowType(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_wordWrap(SObject* obj)
{
	return(NULL);
}

SVariable* iObj_get_zoomBox(SObject* obj)
{
	return(NULL);
}
