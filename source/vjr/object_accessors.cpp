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
