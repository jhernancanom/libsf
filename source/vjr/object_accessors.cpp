//////////
//
// /libsf/source/vjr/object_accessors.cpp
//
//////
// Version 0.31
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
			iError_reportByNumber(errorNum, NULL);
			return(false);
		}

		// Test min/max
		if (tlUseMinMaxTest && (value < tnMin || value > tnMax))
		{
			iError_reportByNumber(_ERROR_OUT_OF_RANGE, NULL);
			return(false);
		}

		// Test with extra function
		if (tnExtraTestFunction)
		{
			_extraTestFunction = tnExtraTestFunction;
			if (!extraTestFunction(value))
			{
				iError_reportByNumber(_ERROR_OUT_OF_RANGE, NULL);
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
	iError_reportByNumber(_ERROR_FEATURE_NOT_AVAILABLE, NULL);
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
		var->obj = obj->objParent;
		return(var);
	}
	// If we get here, failure
	return(NULL);
}

bool iObj_setProperty_tabIndex(SObject* obj, SVariable* var)
{
	return(iObj_setInteger(obj, var, &obj->tabIndex, 0, 0, false, 0));
}

SVariable* iObj_getProperty_tabIndex(SObject* obj)
{
	return(iObj_getInteger(obj, obj->tabIndex));
}

bool iObj_setProperty_tabStop(SObject* obj, SVariable* var)
{
	return(iObj_setLogical(obj, var, &obj->tabStop));
}

SVariable* iObj_getProperty_tabStop(SObject* obj)
{
	return(iObj_getLogical(obj, obj->tabStop));
}

bool iObj_setProperty_helpContextId(SObject* obj, SVariable* var)
{
	return(iObj_setInteger(obj, var, &obj->helpContextId, 0, 0, false, 0));
}

SVariable* iObj_getProperty_helpContextId(SObject* obj)
{
	return(iObj_getInteger(obj, obj->helpContextId));
}

bool iObj_setProperty_hasWhatsThisButton(SObject* obj, SVariable* var)
{
	return(iObj_setLogical(obj, var, &obj->hasWhatsThisButton));
}

SVariable* iObj_getProperty_hasWhatsThisButton(SObject* obj)
{
	return(iObj_getLogical(obj, obj->hasWhatsThisButton));
}

bool iObj_setProperty_hasWhatsThisHelp(SObject* obj, SVariable* var)
{
	return(iObj_setLogical(obj, var, &obj->hasWhatsThisHelp));
}

SVariable* iObj_getProperty_hasWhatsThisHelp(SObject* obj)
{
	return(iObj_getLogical(obj, obj->hasWhatsThisHelp));
}

bool iObj_setProperty_whatsThisHelpId(SObject* obj, SVariable* var)
{
	return(iObj_setInteger(obj, var, &obj->whatsThisHelpId, 0, 0, false, 0));
}

SVariable* iObj_getProperty_whatsThisHelpId(SObject* obj)
{
	return(iObj_getInteger(obj, obj->whatsThisHelpId));
}

bool iObj_setProperty_name(SObject* obj, SVariable* var)
{
	return(iObj_setCharacter(obj, var, &obj->name, var->value.data, var->value.length));
}

SVariable* iObj_getProperty_name(SObject* obj)
{
	return(iObj_getCharacter(obj, &obj->name));
}

SVariable* iObj_getProperty_className(SObject* obj)
{
	return(iObj_getCharacter(obj, &obj->className));
}

SVariable* iObj_getProperty_classLibrary(SObject* obj)
{
	return(iObj_getCharacter(obj, &obj->classLibrary));
}

bool iObj_setProperty_comment(SObject* obj, SVariable* var)
{
	return(iObj_setCharacter(obj, var, &obj->comment, var->value.data, var->value.length));
}

SVariable* iObj_getProperty_comment(SObject* obj)
{
	return(iObj_getCharacter(obj, &obj->comment));
}

bool iObj_setProperty_toolTip(SObject* obj, SVariable* var)
{
	return(iObj_setCharacter(obj, var, &obj->tooltip, var->value.data, var->value.length));
}

SVariable* iObj_getProperty_toolTip(SObject* obj)
{
	return(iObj_getCharacter(obj, &obj->tooltip));
}

bool iObj_setProperty_tag(SObject* obj, SVariable* var)
{
	return(iObj_setCharacter(obj, var, &obj->tag, var->value.data, var->value.length));
}

SVariable* iObj_getProperty_tag(SObject* obj)
{
	return(iObj_getCharacter(obj, &obj->tag));
}

bool iObj_setProperty_mousePointer(SObject* obj, SVariable* var)
{
	return(iObj_setInteger(obj, var, &obj->mousePointer, 0, 17, true, (u32)&iObj_setProperty_mousePointer_extraSetTest));
}

bool iObj_setProperty_mousePointer_extraSetTest(s32 value)
{
	if (value == 99)	return(true);		// A value of 99 is valid
	else				return(false);
}

SVariable* iObj_getProperty_mousePointer(SObject* obj)
{
	return(iObj_getInteger(obj, obj->mousePointer));
}

bool iObj_setProperty_isEnabled(SObject* obj, SVariable* var)
{
	return(iObj_setLogical(obj, var, &obj->isEnabled));
}

SVariable* iObj_getProperty_isEnabled(SObject* obj)
{
	return(iObj_getLogical(obj, obj->isEnabled));
}

bool iObj_setProperty_hasFocus(SObject* obj, SVariable* var)
{
	return(iObj_setLogical(obj, var, &obj->hasFocus));
}

SVariable* iObj_getProperty_hasFocus(SObject* obj)
{
	return(iObj_getLogical(obj, obj->hasFocus));
}

bool iObj_setProperty_isMovable(SObject* obj, SVariable* var)
{
	return(iObj_setLogical(obj, var, &obj->isMovable));
}

SVariable* iObj_getProperty_isMovable(SObject* obj)
{
	return(iObj_getLogical(obj, obj->isMovable));
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
	return(iObj_setLogical(obj, var, &obj->isVisible));
}

SVariable* iObj_getProperty_isVisible(SObject* obj)
{
	return(iObj_getLogical(obj, obj->isVisible));
}

bool iObj_setProperty_isDirty(SObject* obj, SVariable* var)
{
	return(iObj_setLogical(obj, var, &obj->isDirty));
}

SVariable* iObj_getProperty_isDirty(SObject* obj)
{
	return(iObj_getLogical(obj, obj->isDirty));
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
			iError_reportByNumber(errorNum, NULL);
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
			iError_reportByNumber(errorNum, NULL);
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
			iError_reportByNumber(errorNum, NULL);
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
			iError_reportByNumber(errorNum, NULL);
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
	return(iObj_setInteger(obj, var, &obj->anchor, 0, 0, false, 0));
}

SVariable* iObj_getProperty_anchor(SObject* obj)
{
	return(iObj_getInteger(obj, obj->anchor));
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
			iError_reportByNumber(errorNum, NULL);
			return(false);
		}
		if (value <= 0.0f)
		{
			iError_reportByNumber(_ERROR_OUT_OF_RANGE, NULL);
			return(false);
		}

		// Set the value
		// Note:  This is done by resizing the underlying bitmap.
		lnNewWidth = (s32)((f32)(obj->rc.right - obj->rc.left) / value);
		obj->bmp = iBmp_verifySizeOrResize(obj->bmp, lnNewWidth, obj->bmp->bi.biHeight);

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
			iError_reportByNumber(errorNum, NULL);
			return(false);
		}
		if (value <= 0.0f)
		{
			iError_reportByNumber(_ERROR_OUT_OF_RANGE, NULL);
			return(false);
		}

		// Set the value
		// Note:  This is done by resizing the underlying bitmap.
		lnNewHeight = (s32)((f32)(obj->rc.bottom - obj->rc.top) / value);
		obj->bmp = iBmp_verifySizeOrResize(obj->bmp, obj->bmp->bi.biWidth, lnNewHeight);

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





//////////
// FORM Properties
//////
bool iObj_setMinLeft(SObject* obj, SVariable* var)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_setInteger(obj, var, &form->rcMin.left, 0, 0, false, 0));

	// If we get here, failure
	return(false);
}

SVariable* iObj_getMinLeft(SObject* obj)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_getInteger(obj, form->rcMin.left));

	// If we get here, failure
	return(NULL);
}

bool iObj_setMinTop(SObject* obj, SVariable* var)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_setInteger(obj, var, &form->rcMin.top, 0, 0, false, 0));

	// If we get here, failure
	return(false);
}

SVariable* iObj_getMinTop(SObject* obj)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_getInteger(obj, form->rcMin.top));

	// If we get here, failure
	return(NULL);
}

bool iObj_setMinWidth(SObject* obj, SVariable* var)
{
	s32				value;
	bool			error;
	u32				errorNum;
	SSubObjForm*	form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form && iVariable_isTypeNumeric(var))
	{
		value = iiVariable_getAs_s32(var, false, &error, &errorNum);
		if (error)
		{
			iError_reportByNumber(errorNum, NULL);
			return(false);
		}

		// Set the value
		form->rcMin.right = form->rcMin.left + value;
	}

	// If we get here, failure
	return(false);
}

SVariable* iObj_getMinWidth(SObject* obj)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_getInteger(obj, form->rcMin.right - form->rcMin.left));

	// If we get here, failure
	return(NULL);
}

bool iObj_setMinHeight(SObject* obj, SVariable* var)
{
	s32				value;
	bool			error;
	u32				errorNum;
	SSubObjForm*	form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form && iVariable_isTypeNumeric(var))
	{
		value = iiVariable_getAs_s32(var, false, &error, &errorNum);
		if (error)
		{
			iError_reportByNumber(errorNum, NULL);
			return(false);
		}

		// Set the value
		form->rcMin.bottom = form->rcMin.top + value;
	}

	// If we get here, failure
	return(false);
}

SVariable* iObj_getMinHeight(SObject* obj)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_getInteger(obj, form->rcMin.bottom - form->rcMin.top));

	// If we get here, failure
	return(NULL);
}

bool iObj_setMaxLeft(SObject* obj, SVariable* var)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_setInteger(obj, var, &form->rcMax.left, 0, 0, false, 0));

	// If we get here, failure
	return(false);
}

SVariable* iObj_getMaxLeft(SObject* obj)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_getInteger(obj, form->rcMax.left));

	// If we get here, failure
	return(NULL);
}

bool iObj_setMaxTop(SObject* obj, SVariable* var)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_setInteger(obj, var, &form->rcMax.top, 0, 0, false, 0));

	// If we get here, failure
	return(false);
}

SVariable* iObj_getMaxTop(SObject* obj)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_getInteger(obj, form->rcMin.top));

	// If we get here, failure
	return(NULL);
}

bool iObj_setMaxWidth(SObject* obj, SVariable* var)
{
	s32				value;
	bool			error;
	u32				errorNum;
	SSubObjForm*	form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form && iVariable_isTypeNumeric(var))
	{
		value = iiVariable_getAs_s32(var, false, &error, &errorNum);
		if (error)
		{
			iError_reportByNumber(errorNum, NULL);
			return(false);
		}

		// Set the value
		form->rcMax.right = form->rcMax.left + value;
	}

	// If we get here, failure
	return(false);
}

SVariable* iObj_getMaxWidth(SObject* obj)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_getInteger(obj, form->rcMax.right - form->rcMax.left));

	// If we get here, failure
	return(NULL);
}

bool iObj_setMaxHeight(SObject* obj, SVariable* var)
{
	s32				value;
	bool			error;
	u32				errorNum;
	SSubObjForm*	form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form && iVariable_isTypeNumeric(var))
	{
		value = iiVariable_getAs_s32(var, false, &error, &errorNum);
		if (error)
		{
			iError_reportByNumber(errorNum, NULL);
			return(false);
		}

		// Set the value
		form->rcMax.bottom = form->rcMax.top + value;
	}

	// If we get here, failure
	return(false);
}

SVariable* iObj_getMaxHeight(SObject* obj)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_getInteger(obj, form->rcMin.bottom - form->rcMin.top));

	// If we get here, failure
	return(NULL);
}

bool iObj_setFontName(SObject* obj, SVariable* var)
{
	bool			llResult;
	SSubObjForm*	form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
	{
		// Perform the update
		llResult = iObj_setCharacter(obj, var, &form->font->name, var->value.data, var->value.length);
		if (llResult)
			iiFont_refresh(form->font);		// Refresh the font with its new settings

		// Indicate our status
		return(llResult);
	}

	// If we get here, failure
	return(false);
}

SVariable* iObj_getFontName(SObject* obj)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_getCharacter(obj, &form->font->name));

	// If we get here, failure
	return(false);
}

bool iObj_setFontSize(SObject* obj, SVariable* var)
{
	bool			llResult;
	SSubObjForm*	form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
	{
		// Perform the update
		llResult = iObj_setInteger(obj, var, (s32*)&form->font->_size, 0, 0, false, 0);
		if (llResult)
			iiFont_refresh(form->font);		// Refresh the font with its new settings

		// Indicate our status
		return(llResult);
	}

	// If we get here, failure
	return(false);
}

SVariable* iObj_getFontSize(SObject* obj)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_getInteger(obj, form->font->_size));

	// If we get here, failure
	return(NULL);
}

bool iObj_setFontBold(SObject* obj, SVariable* var)
{
	bool			llResult;
	SSubObjForm*	form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
	{
		// Perform the update
		llResult = iObj_setLogical(obj, var, &form->font->isBold);
		if (llResult)
			iiFont_refresh(form->font);		// Refresh the font with its new settings

		// Indicate our status
		return(llResult);
	}

	// If we get here, failure
	return(false);
}

SVariable* iObj_getFontBold(SObject* obj)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_getLogical(obj, form->font->isBold));

	// If we get here, failure
	return(NULL);
}

bool iObj_setFontItalic(SObject* obj, SVariable* var)
{
	bool			llResult;
	SSubObjForm*	form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
	{
		// Perform the update
		llResult = iObj_setLogical(obj, var, &form->font->isItalic);
		if (llResult)
			iiFont_refresh(form->font);		// Refresh the font with its new settings

		// Indicate our status
		return(llResult);
	}

	// If we get here, failure
	return(false);
}

SVariable* iObj_getFontItalic(SObject* obj)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_getLogical(obj, form->font->isItalic));

	// If we get here, failure
	return(NULL);
}

bool iObj_setFontUnderline(SObject* obj, SVariable* var)
{
	bool			llResult;
	SSubObjForm*	form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
	{
		// Perform the update
		llResult = iObj_setLogical(obj, var, &form->font->isUnderline);
		if (llResult)
			iiFont_refresh(form->font);		// Refresh the font with its new settings

		// Indicate our status
		return(llResult);
	}

	// If we get here, failure
	return(false);
}

SVariable* iObj_getFontUnderline(SObject* obj)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_getLogical(obj, form->font->isUnderline));

	// If we get here, failure
	return(NULL);
}

bool iObj_setFontStrikethrough(SObject* obj, SVariable* var)
{
	bool			llResult;
	SSubObjForm*	form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
	{
		// Perform the update
		llResult = iObj_setLogical(obj, var, &form->font->isStrikethrough);
		if (llResult)
			iiFont_refresh(form->font);		// Refresh the font with its new settings

		// Indicate our status
		return(llResult);
	}

	// If we get here, failure
	return(false);
}

SVariable* iObj_getFontStrikethrough(SObject* obj)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_getLogical(obj, form->font->isStrikethrough));

	// If we get here, failure
	return(NULL);
}

bool iObj_setFontCondensed(SObject* obj, SVariable* var)
{
	bool			llResult;
	SSubObjForm*	form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
	{
		// Perform the update
		llResult = iObj_setLogical(obj, var, &form->font->isCondensed);
		if (llResult)
			iiFont_refresh(form->font);		// Refresh the font with its new settings

		// Indicate our status
		return(llResult);
	}

	// If we get here, failure
	return(false);
}

SVariable* iObj_getFontCondensed(SObject* obj)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_getLogical(obj, form->font->isCondensed));

	// If we get here, failure
	return(NULL);
}

bool iObj_setFontExtended(SObject* obj, SVariable* var)
{
	bool			llResult;
	SSubObjForm*	form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
	{
		// Perform the update
		llResult = iObj_setLogical(obj, var, &form->font->isExtended);
		if (llResult)
			iiFont_refresh(form->font);		// Refresh the font with its new settings

		// Indicate our status
		return(llResult);
	}

	// If we get here, failure
	return(false);
}

SVariable* iObj_getFontExtended(SObject* obj)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_getLogical(obj, form->font->isExtended));

	// If we get here, failure
	return(NULL);
}

bool iObj_setFontOutline(SObject* obj, SVariable* var)
{
	bool			llResult;
	SSubObjForm*	form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
	{
		// Perform the update
		llResult = iObj_setLogical(obj, var, &form->font->isOutline);
		if (llResult)
			iiFont_refresh(form->font);		// Refresh the font with its new settings

		// Indicate our status
		return(llResult);
	}

	// If we get here, failure
	return(false);
}

SVariable* iObj_getFontOutline(SObject* obj)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_getLogical(obj, form->font->isOutline));

	// If we get here, failure
	return(NULL);
}

bool iObj_setFontShadow(SObject* obj, SVariable* var)
{
	bool			llResult;
	SSubObjForm*	form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
	{
		// Perform the update
		llResult = iObj_setLogical(obj, var, &form->font->isShadow);
		if (llResult)
			iiFont_refresh(form->font);		// Refresh the font with its new settings

		// Indicate our status
		return(llResult);
	}

	// If we get here, failure
	return(false);
}

SVariable* iObj_getFontShadow(SObject* obj)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_getLogical(obj, form->font->isShadow));

	// If we get here, failure
	return(NULL);
}

bool iObj_setNwColor(SObject* obj, SVariable* var)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_setInteger(obj, var, (s32*)&form->nwRgba.color, 0, 0, false, 0));

	// If we get here, failure
	return(false);
}

SVariable* iObj_getNwColor(SObject* obj)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_getInteger(obj, form->nwRgba.color));

	// If we get here, failure
	return(NULL);
}

bool iObj_setNeColor(SObject* obj, SVariable* var)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_setInteger(obj, var, (s32*)&form->neRgba.color, 0, 0, false, 0));

	// If we get here, failure
	return(false);
}

SVariable* iObj_getNeColor(SObject* obj)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_getInteger(obj, form->neRgba.color));

	// If we get here, failure
	return(NULL);
}

bool iObj_setSwColor(SObject* obj, SVariable* var)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_setInteger(obj, var, (s32*)&form->swRgba.color, 0, 0, false, 0));

	// If we get here, failure
	return(false);
}

SVariable* iObj_getSwColor(SObject* obj)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_getInteger(obj, form->swRgba.color));

	// If we get here, failure
	return(NULL);
}

bool iObj_setSeColor(SObject* obj, SVariable* var)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_setInteger(obj, var, (s32*)&form->seRgba.color, 0, 0, false, 0));

	// If we get here, failure
	return(false);
}

SVariable* iObj_getSeColor(SObject* obj)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_getInteger(obj, form->seRgba.color));

	// If we get here, failure
	return(NULL);
}

bool iObj_setBackColor(SObject* obj, SVariable* var)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_setInteger(obj, var, (s32*)&form->backColor.color, 0, 0, false, 0));

	// If we get here, failure
	return(false);
}

SVariable* iObj_getBackColor(SObject* obj)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_getInteger(obj, form->backColor.color));

	// If we get here, failure
	return(NULL);
}

bool iObj_setForeColor(SObject* obj, SVariable* var)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_setInteger(obj, var, (s32*)&form->foreColor.color, 0, 0, false, 0));

	// If we get here, failure
	return(false);
}

SVariable* iObj_getForeColor(SObject* obj)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_getInteger(obj, form->foreColor.color));

	// If we get here, failure
	return(NULL);
}

bool iObj_setCaptionColor(SObject* obj, SVariable* var)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_setInteger(obj, var, (s32*)&form->captionColor.color, 0, 0, false, 0));

	// If we get here, failure
	return(false);
}

SVariable* iObj_getCaptionColor(SObject* obj)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_getInteger(obj, form->captionColor.color));

	// If we get here, failure
	return(NULL);
}

bool iObj_setCaption(SObject* obj, SVariable* var)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_setCharacter(obj, var, &form->caption, var->value.data, var->value.length));

	// If we get here, failure
	return(false);
}

SVariable* iObj_getCaption(SObject* obj)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_getCharacter(obj, &form->caption));

	// If we get here, failure
	return(false);
}

bool iObj_setPicture(SObject* obj, SVariable* var)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_setCharacter(obj, var, &form->pictureName, var->value.data, var->value.length));

	// If we get here, failure
	return(false);
}

SVariable* iObj_getPicture(SObject* obj)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_getCharacter(obj, &form->pictureName));

	// If we get here, failure
	return(false);
}

bool iObj_setAllowOutput(SObject* obj, SVariable* var)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_setLogical(obj, var, &form->allowOutput));

	// If we get here, failure
	return(false);
}

SVariable* iObj_getAllowOutput(SObject* obj)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_getLogical(obj, form->allowOutput));

	// If we get here, failure
	return(NULL);
}

bool iObj_setAlwaysOnBottom(SObject* obj, SVariable* var)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_setLogical(obj, var, &form->alwaysOnBottom));

	// If we get here, failure
	return(false);
}

SVariable* iObj_getAlwaysOnBottom(SObject* obj)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_getLogical(obj, form->alwaysOnBottom));

	// If we get here, failure
	return(NULL);
}

bool iObj_setAlwaysOnTop(SObject* obj, SVariable* var)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_setLogical(obj, var, &form->alwaysOnTop));

	// If we get here, failure
	return(false);
}

SVariable* iObj_getAlwaysOnTop(SObject* obj)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_getLogical(obj, form->alwaysOnTop));

	// If we get here, failure
	return(NULL);
}

bool iObj_setAutoCenter(SObject* obj, SVariable* var)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_setLogical(obj, var, &form->autoCenter));

	// If we get here, failure
	return(false);
}

SVariable* iObj_getAutoCenter(SObject* obj)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_getLogical(obj, form->autoCenter));

	// If we get here, failure
	return(NULL);
}

bool iObj_setBorderStyle(SObject* obj, SVariable* var)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_setInteger(obj, var, (s32*)&form->borderStyle, 0, 3, true, 0));

	// If we get here, failure
	return(false);
}

SVariable* iObj_getBorderStyle(SObject* obj)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_getInteger(obj, form->borderStyle));

	// If we get here, failure
	return(NULL);
}

bool iObj_setIsCloseable(SObject* obj, SVariable* var)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_setLogical(obj, var, &form->isClosable));

	// If we get here, failure
	return(false);
}

SVariable* iObj_getIsCloseable(SObject* obj)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_getLogical(obj, form->isClosable));

	// If we get here, failure
	return(NULL);
}

bool iObj_setProcessKeyPreviewEvents(SObject* obj, SVariable* var)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_setLogical(obj, var, &form->processKeyPreviewEvents));

	// If we get here, failure
	return(false);
}

SVariable* iObj_getProcessKeyPreviewEvents(SObject* obj)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_getLogical(obj, form->processKeyPreviewEvents));

	// If we get here, failure
	return(NULL);
}

bool iObj_setHasControlBox(SObject* obj, SVariable* var)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_setLogical(obj, var, &form->hasControlBox));

	// If we get here, failure
	return(false);
}

SVariable* iObj_getHasControlBox(SObject* obj)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_getLogical(obj, form->hasControlBox));

	// If we get here, failure
	return(NULL);
}

bool iObj_setHasMinButton(SObject* obj, SVariable* var)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_setLogical(obj, var, &form->hasMinButton));

	// If we get here, failure
	return(false);
}

SVariable* iObj_getHasMinButton(SObject* obj)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_getLogical(obj, form->hasMinButton));

	// If we get here, failure
	return(NULL);
}

bool iObj_setHasCloseButton(SObject* obj, SVariable* var)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_setLogical(obj, var, &form->hasCloseButton));

	// If we get here, failure
	return(false);
}

SVariable* iObj_getHasCloseButton(SObject* obj)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_getLogical(obj, form->hasCloseButton));

	// If we get here, failure
	return(NULL);
}

bool iObj_setScaleMode(SObject* obj, SVariable* var)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_setInteger(obj, var, (s32*)&form->scaleMode, 0, 0, false, (u32)&iObj_setScaleMode_extraTest));

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
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_getInteger(obj, form->scaleMode));

	// If we get here, failure
	return(NULL);
}

bool iObj_setShowInTaskBar(SObject* obj, SVariable* var)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_setLogical(obj, var, &form->showInTaskBar));

	// If we get here, failure
	return(false);
}

SVariable* iObj_getShowInTaskBar(SObject* obj)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_getLogical(obj, form->showInTaskBar));

	// If we get here, failure
	return(NULL);
}

bool iObj_setWindowState(SObject* obj, SVariable* var)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_setInteger(obj, var, (s32*)&form->windowState, 0, 1, true, 0));

	// If we get here, failure
	return(false);
}

SVariable* iObj_getWindowState(SObject* obj)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_getInteger(obj, form->windowState));

	// If we get here, failure
	return(NULL);
}

bool iObj_setBindControls(SObject* obj, SVariable* var)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_setLogical(obj, var, &form->bindControls));

	// If we get here, failure
	return(false);
}

SVariable* iObj_getBindControls(SObject* obj)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_getLogical(obj, form->bindControls));

	// If we get here, failure
	return(NULL);
}

bool iObj_setBufferMode(SObject* obj, SVariable* var)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_setInteger(obj, var, (s32*)&form->bufferMode, 0, 1, true, 0));

	// If we get here, failure
	return(false);
}

SVariable* iObj_getBufferMode(SObject* obj)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_getInteger(obj, form->bufferMode));

	// If we get here, failure
	return(NULL);
}

bool iObj_setClipControls(SObject* obj, SVariable* var)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_setLogical(obj, var, &form->clipControls));

	// If we get here, failure
	return(false);
}

SVariable* iObj_getClipControls(SObject* obj)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_getLogical(obj, form->clipControls));

	// If we get here, failure
	return(NULL);
}

bool iObj_setColorSource(SObject* obj, SVariable* var)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_setInteger(obj, var, (s32*)&form->colorSource, 0, 0, false, 0));

	// If we get here, failure
	return(false);
}

SVariable* iObj_getColorSource(SObject* obj)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_getInteger(obj, form->colorSource));

	// If we get here, failure
	return(NULL);
}

bool iObj_setContinuousScroll(SObject* obj, SVariable* var)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_setLogical(obj, var, &form->continuousScroll));

	// If we get here, failure
	return(false);
}

SVariable* iObj_getContinuousScroll(SObject* obj)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_getLogical(obj, form->continuousScroll));

	// If we get here, failure
	return(NULL);
}

bool iObj_setDataSession(SObject* obj, SVariable* var)
{
	SSubObjForm* form;


	// Make sure the environment is sane
	if (obj && obj->sub_obj && var && iVariable_isTypeObject(var))
	{
		// Grab the form
		form = (SSubObjForm*)obj->sub_obj;

		// Set the value
		form->dataSession = var->obj;

		// Indicate success
		return(true);
	}

	// If we get here, failure
	return(false);
}

SVariable* iObj_getDataSession(SObject* obj)
{
	SSubObjForm*	form;
	SVariable*		var;


	// Make sure our environment is sane
	if (obj && obj->sub_obj)
	{
		// Grab the form
		form = (SSubObjForm*)obj->sub_obj;

		// Create a new variable
		var = iVariable_create(_VAR_TYPE_OBJECT, NULL);
		var->obj = form->dataSession;
		return(var);
	}

	// If we get here, failure
	return(NULL);
}

bool iObj_setDataSessionId(SObject* obj, SVariable* var)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_setInteger(obj, var, (s32*)&form->dataSessionId, 0, 0, false, 0));

	// If we get here, failure
	return(false);
}

SVariable* iObj_getDataSessionId(SObject* obj)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_getInteger(obj, form->dataSessionId));

	// If we get here, failure
	return(NULL);
}

bool iObj_setDeClass(SObject* obj, SVariable* var)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_setCharacter(obj, var, &form->declass, var->value.data, var->value.length));

	// If we get here, failure
	return(false);
}

SVariable* iObj_getDeClass(SObject* obj)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_getCharacter(obj, &form->declass));

	// If we get here, failure
	return(false);
}

bool iObj_setDeClassLibrary(SObject* obj, SVariable* var)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_setCharacter(obj, var, &form->declasslibrary, var->value.data, var->value.length));

	// If we get here, failure
	return(false);
}

SVariable* iObj_getDeClassLibrary(SObject* obj)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_getCharacter(obj, &form->declasslibrary));

	// If we get here, failure
	return(false);
}

bool iObj_setDefOleCid(SObject* obj, SVariable* var)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_setInteger(obj, var, (s32*)&form->defolecid, 0, 0, false, 0));

	// If we get here, failure
	return(false);
}

SVariable* iObj_getDefOleCid(SObject* obj)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_getInteger(obj, form->defolecid));

	// If we get here, failure
	return(NULL);
}

bool iObj_setDesktop(SObject* obj, SVariable* var)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_setLogical(obj, var, &form->desktop));

	// If we get here, failure
	return(false);
}

SVariable* iObj_getDesktop(SObject* obj)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_getLogical(obj, form->desktop));

	// If we get here, failure
	return(NULL);
}

bool iObj_setIsDockable(SObject* obj, SVariable* var)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_setLogical(obj, var, &form->isDockable));

	// If we get here, failure
	return(false);
}

SVariable* iObj_getIsDockable(SObject* obj)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_getLogical(obj, form->isDockable));

	// If we get here, failure
	return(NULL);
}

bool iObj_setIsDocked(SObject* obj, SVariable* var)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_setLogical(obj, var, &form->isDocked));

	// If we get here, failure
	return(false);
}

SVariable* iObj_getIsDocked(SObject* obj)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_getLogical(obj, form->isDocked));

	// If we get here, failure
	return(NULL);
}

bool iObj_setDockPosition(SObject* obj, SVariable* var)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_setInteger(obj, var, (s32*)&form->dockPosition, 0, 0, false, 0));

	// If we get here, failure
	return(false);
}

SVariable* iObj_getDockPosition(SObject* obj)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_getInteger(obj, form->dockPosition));

	// If we get here, failure
	return(NULL);
}

bool iObj_setDrawMode(SObject* obj, SVariable* var)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_setInteger(obj, var, (s32*)&form->drawmode, 0, 0, false, 0));

	// If we get here, failure
	return(false);
}

SVariable* iObj_getDrawMode(SObject* obj)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_getInteger(obj, form->drawmode));

	// If we get here, failure
	return(NULL);
}

bool iObj_setDrawStyle(SObject* obj, SVariable* var)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_setInteger(obj, var, (s32*)&form->drawstyle, 0, 0, false, 0));

	// If we get here, failure
	return(false);
}

SVariable* iObj_getDrawStyle(SObject* obj)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_getInteger(obj, form->drawstyle));

	// If we get here, failure
	return(NULL);
}

bool iObj_setDrawWidth(SObject* obj, SVariable* var)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_setInteger(obj, var, (s32*)&form->drawwidth, 0, 0, false, 0));

	// If we get here, failure
	return(false);
}

SVariable* iObj_getDrawWidth(SObject* obj)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_getInteger(obj, form->drawwidth));

	// If we get here, failure
	return(NULL);
}

bool iObj_setFillColor(SObject* obj, SVariable* var)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_setInteger(obj, var, (s32*)&form->fillColor.color, 0, 0, false, 0));

	// If we get here, failure
	return(false);
}

SVariable* iObj_getFillColor(SObject* obj)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_getInteger(obj, form->fillColor.color));

	// If we get here, failure
	return(NULL);
}

bool iObj_setFillStyle(SObject* obj, SVariable* var)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_setInteger(obj, var, (s32*)&form->fillStyle, 0, 0, false, 0));

	// If we get here, failure
	return(false);
}

SVariable* iObj_getFillStyle(SObject* obj)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_getInteger(obj, form->fillStyle));

	// If we get here, failure
	return(NULL);
}

bool iObj_setHalfHeightCaption(SObject* obj, SVariable* var)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_setLogical(obj, var, &form->halfHeightCaption));

	// If we get here, failure
	return(false);
}

SVariable* iObj_getHalfHeightCaption(SObject* obj)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_getLogical(obj, form->halfHeightCaption));

	// If we get here, failure
	return(NULL);
}

bool iObj_setHScrollSmallChange(SObject* obj, SVariable* var)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_setInteger(obj, var, (s32*)&form->hScrollSmallChange, 0, 0, false, 0));

	// If we get here, failure
	return(false);
}

SVariable* iObj_getHScrollSmallChange(SObject* obj)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_getInteger(obj, form->hScrollSmallChange));

	// If we get here, failure
	return(NULL);
}

bool iObj_setVScrollSmallChange(SObject* obj, SVariable* var)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_setInteger(obj, var, (s32*)&form->vScrollSmallChange, 0, 0, false, 0));

	// If we get here, failure
	return(false);
}

SVariable* iObj_getVScrollSmallChange(SObject* obj)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_getInteger(obj, form->vScrollSmallChange));

	// If we get here, failure
	return(NULL);
}

bool iObj_setMacDesktop(SObject* obj, SVariable* var)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_setLogical(obj, var, &form->macDesktop));

	// If we get here, failure
	return(false);
}

SVariable* iObj_getMacDesktop(SObject* obj)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_getLogical(obj, form->macDesktop));

	// If we get here, failure
	return(NULL);
}

bool iObj_setMdiForm(SObject* obj, SVariable* var)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_setLogical(obj, var, &form->mdiForm));

	// If we get here, failure
	return(false);
}

SVariable* iObj_getMdiForm(SObject* obj)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_getLogical(obj, form->mdiForm));

	// If we get here, failure
	return(NULL);
}

bool iObj_setOleDragMode(SObject* obj, SVariable* var)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_setInteger(obj, var, (s32*)&form->oleDragMode, 0, 0, false, 0));

	// If we get here, failure
	return(false);
}

SVariable* iObj_getOleDragMode(SObject* obj)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_getInteger(obj, form->oleDragMode));

	// If we get here, failure
	return(NULL);
}

bool iObj_setOleDropEffects(SObject* obj, SVariable* var)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_setInteger(obj, var, (s32*)&form->oleDropEffects, 0, 0, false, 0));

	// If we get here, failure
	return(false);
}

SVariable* iObj_getOleDropEffects(SObject* obj)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_getInteger(obj, form->oleDropEffects));

	// If we get here, failure
	return(NULL);
}

bool iObj_setOleDropHasData(SObject* obj, SVariable* var)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_setInteger(obj, var, (s32*)&form->oleDropHasData, 0, 0, false, 0));

	// If we get here, failure
	return(false);
}

SVariable* iObj_getOleDropHasData(SObject* obj)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_getInteger(obj, form->oleDropHasData));

	// If we get here, failure
	return(NULL);
}

bool iObj_setOleDropMode(SObject* obj, SVariable* var)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_setInteger(obj, var, (s32*)&form->oleDropMode, 0, 0, false, 0));

	// If we get here, failure
	return(false);
}

SVariable* iObj_getOleDropMode(SObject* obj)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_getInteger(obj, form->oleDropMode));

	// If we get here, failure
	return(NULL);
}

bool iObj_setReleaseType(SObject* obj, SVariable* var)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_setInteger(obj, var, (s32*)&form->releaseType, 0, 0, false, 0));

	// If we get here, failure
	return(false);
}

SVariable* iObj_getReleaseType(SObject* obj)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_getInteger(obj, form->releaseType));

	// If we get here, failure
	return(NULL);
}

bool iObj_setRightToLeft(SObject* obj, SVariable* var)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_setLogical(obj, var, &form->rightToLeft));

	// If we get here, failure
	return(false);
}

SVariable* iObj_getRightToLeft(SObject* obj)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_getLogical(obj, form->rightToLeft));

	// If we get here, failure
	return(NULL);
}

bool iObj_setScrollbars(SObject* obj, SVariable* var)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_setInteger(obj, var, (s32*)&form->scrollbars, 0, 0, false, 0));

	// If we get here, failure
	return(false);
}

SVariable* iObj_getScrollbars(SObject* obj)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_getInteger(obj, form->scrollbars));

	// If we get here, failure
	return(NULL);
}

bool iObj_setShowTips(SObject* obj, SVariable* var)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_setInteger(obj, var, (s32*)&form->showTips, 0, 0, false, 0));

	// If we get here, failure
	return(false);
}

SVariable* iObj_getShowTips(SObject* obj)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_getInteger(obj, form->showTips));

	// If we get here, failure
	return(NULL);
}

bool iObj_setShowWindow(SObject* obj, SVariable* var)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_setInteger(obj, var, (s32*)&form->showWindow, 0, 0, false, 0));

	// If we get here, failure
	return(false);
}

SVariable* iObj_getShowWindow(SObject* obj)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_getInteger(obj, form->showWindow));

	// If we get here, failure
	return(NULL);
}

bool iObj_setSizeBox(SObject* obj, SVariable* var)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_setLogical(obj, var, &form->sizeBox));

	// If we get here, failure
	return(false);
}

SVariable* iObj_getSizeBox(SObject* obj)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_getLogical(obj, form->sizeBox));

	// If we get here, failure
	return(NULL);
}

bool iObj_setThemes(SObject* obj, SVariable* var)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_setLogical(obj, var, &form->themes));

	// If we get here, failure
	return(false);
}

SVariable* iObj_getThemes(SObject* obj)
{
	return(NULL);
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_getLogical(obj, form->themes));

	// If we get here, failure
	return(NULL);
}

bool iObj_setTitleBar(SObject* obj, SVariable* var)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_setInteger(obj, var, (s32*)&form->titleBar, 0, 0, false, 0));

	// If we get here, failure
	return(false);
}

SVariable* iObj_getTitleBar(SObject* obj)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_getInteger(obj, form->titleBar));

	// If we get here, failure
	return(NULL);
}

bool iObj_setWindowType(SObject* obj, SVariable* var)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_setInteger(obj, var, (s32*)&form->windowType, 0, 0, false, 0));

	// If we get here, failure
	return(false);
}

SVariable* iObj_getWindowType(SObject* obj)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_getInteger(obj, form->windowType));

	// If we get here, failure
	return(NULL);
}

bool iObj_setZoomBox(SObject* obj, SVariable* var)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_setLogical(obj, var, &form->zoomBox));

	// If we get here, failure
	return(false);
}

SVariable* iObj_getZoomBox(SObject* obj)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_getLogical(obj, form->zoomBox));

	// If we get here, failure
	return(NULL);
}
