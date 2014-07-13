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
// To jump immediately to a section, search for one of these here or in vjr_defs.h:
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
		var->obj = obj->parent;
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
bool iiSubobj_form_setMinLeft(SObject* obj, SVariable* var)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_setInteger(obj, var, &form->rcMin.left, 0, 0, false, 0));

	// If we get here, failure
	return(false);
}

SVariable* iiSubobj_form_getMinLeft(SObject* obj)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_getInteger(obj, form->rcMin.left));

	// If we get here, failure
	return(NULL);
}

bool iiSubobj_form_setMinTop(SObject* obj, SVariable* var)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_setInteger(obj, var, &form->rcMin.top, 0, 0, false, 0));

	// If we get here, failure
	return(false);
}

SVariable* iiSubobj_form_getMinTop(SObject* obj)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_getInteger(obj, form->rcMin.top));

	// If we get here, failure
	return(NULL);
}

bool iiSubobj_form_setMinWidth(SObject* obj, SVariable* var)
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

SVariable* iiSubobj_form_getMinWidth(SObject* obj)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_getInteger(obj, form->rcMin.right - form->rcMin.left));

	// If we get here, failure
	return(NULL);
}

bool iiSubobj_form_setMinHeight(SObject* obj, SVariable* var)
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

SVariable* iiSubobj_form_getMinHeight(SObject* obj)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_getInteger(obj, form->rcMin.bottom - form->rcMin.top));

	// If we get here, failure
	return(NULL);
}

bool iiSubobj_form_setMaxLeft(SObject* obj, SVariable* var)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_setInteger(obj, var, &form->rcMax.left, 0, 0, false, 0));

	// If we get here, failure
	return(false);
}

SVariable* iiSubobj_form_getMaxLeft(SObject* obj)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_getInteger(obj, form->rcMax.left));

	// If we get here, failure
	return(NULL);
}

bool iiSubobj_form_setMaxTop(SObject* obj, SVariable* var)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_setInteger(obj, var, &form->rcMax.top, 0, 0, false, 0));

	// If we get here, failure
	return(false);
}

SVariable* iiSubobj_form_getMaxTop(SObject* obj)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_getInteger(obj, form->rcMin.top));

	// If we get here, failure
	return(NULL);
}

bool iiSubobj_form_setMaxWidth(SObject* obj, SVariable* var)
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

SVariable* iiSubobj_form_getMaxWidth(SObject* obj)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_getInteger(obj, form->rcMax.right - form->rcMax.left));

	// If we get here, failure
	return(NULL);
}

bool iiSubobj_form_setMaxHeight(SObject* obj, SVariable* var)
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

SVariable* iiSubobj_form_getMaxHeight(SObject* obj)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_getInteger(obj, form->rcMin.bottom - form->rcMin.top));

	// If we get here, failure
	return(NULL);
}

bool iiSubobj_form_setFontName(SObject* obj, SVariable* var)
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

SVariable* iiSubobj_form_getFontName(SObject* obj)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_getCharacter(obj, &form->font->name));

	// If we get here, failure
	return(false);
}

bool iiSubobj_form_setFontSize(SObject* obj, SVariable* var)
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

SVariable* iiSubobj_form_getFontSize(SObject* obj)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_getInteger(obj, form->font->_size));

	// If we get here, failure
	return(NULL);
}

bool iiSubobj_form_setFontBold(SObject* obj, SVariable* var)
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

SVariable* iiSubobj_form_getFontBold(SObject* obj)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_getLogical(obj, form->font->isBold));

	// If we get here, failure
	return(NULL);
}

bool iiSubobj_form_setFontItalic(SObject* obj, SVariable* var)
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

SVariable* iiSubobj_form_getFontItalic(SObject* obj)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_getLogical(obj, form->font->isItalic));

	// If we get here, failure
	return(NULL);
}

bool iiSubobj_form_setFontUnderline(SObject* obj, SVariable* var)
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

SVariable* iiSubobj_form_getFontUnderline(SObject* obj)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_getLogical(obj, form->font->isUnderline));

	// If we get here, failure
	return(NULL);
}

bool iiSubobj_form_setFontStrikethrough(SObject* obj, SVariable* var)
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

SVariable* iiSubobj_form_getFontStrikethrough(SObject* obj)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_getLogical(obj, form->font->isStrikethrough));

	// If we get here, failure
	return(NULL);
}

bool iiSubobj_form_setFontCondensed(SObject* obj, SVariable* var)
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

SVariable* iiSubobj_form_getFontCondensed(SObject* obj)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_getLogical(obj, form->font->isCondensed));

	// If we get here, failure
	return(NULL);
}

bool iiSubobj_form_setFontExtended(SObject* obj, SVariable* var)
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

SVariable* iiSubobj_form_getFontExtended(SObject* obj)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_getLogical(obj, form->font->isExtended));

	// If we get here, failure
	return(NULL);
}

bool iiSubobj_form_setFontOutline(SObject* obj, SVariable* var)
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

SVariable* iiSubobj_form_getFontOutline(SObject* obj)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_getLogical(obj, form->font->isOutline));

	// If we get here, failure
	return(NULL);
}

bool iiSubobj_form_setFontShadow(SObject* obj, SVariable* var)
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

SVariable* iiSubobj_form_getFontShadow(SObject* obj)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_getLogical(obj, form->font->isShadow));

	// If we get here, failure
	return(NULL);
}

bool iiSubobj_form_setNwColor(SObject* obj, SVariable* var)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_setInteger(obj, var, (s32*)&form->nwRgba.color, 0, 0, false, 0));

	// If we get here, failure
	return(false);
}

SVariable* iiSubobj_form_getNwColor(SObject* obj)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_getInteger(obj, form->nwRgba.color));

	// If we get here, failure
	return(NULL);
}

bool iiSubobj_form_setNeColor(SObject* obj, SVariable* var)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_setInteger(obj, var, (s32*)&form->neRgba.color, 0, 0, false, 0));

	// If we get here, failure
	return(false);
}

SVariable* iiSubobj_form_getNeColor(SObject* obj)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_getInteger(obj, form->neRgba.color));

	// If we get here, failure
	return(NULL);
}

bool iiSubobj_form_setSwColor(SObject* obj, SVariable* var)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_setInteger(obj, var, (s32*)&form->swRgba.color, 0, 0, false, 0));

	// If we get here, failure
	return(false);
}

SVariable* iiSubobj_form_getSwColor(SObject* obj)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_getInteger(obj, form->swRgba.color));

	// If we get here, failure
	return(NULL);
}

bool iiSubobj_form_setSeColor(SObject* obj, SVariable* var)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_setInteger(obj, var, (s32*)&form->seRgba.color, 0, 0, false, 0));

	// If we get here, failure
	return(false);
}

SVariable* iiSubobj_form_getSeColor(SObject* obj)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_getInteger(obj, form->seRgba.color));

	// If we get here, failure
	return(NULL);
}

bool iiSubobj_form_setBackColor(SObject* obj, SVariable* var)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_setInteger(obj, var, (s32*)&form->backColor.color, 0, 0, false, 0));

	// If we get here, failure
	return(false);
}

SVariable* iiSubobj_form_getBackColor(SObject* obj)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_getInteger(obj, form->backColor.color));

	// If we get here, failure
	return(NULL);
}

bool iiSubobj_form_setForeColor(SObject* obj, SVariable* var)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_setInteger(obj, var, (s32*)&form->foreColor.color, 0, 0, false, 0));

	// If we get here, failure
	return(false);
}

SVariable* iiSubobj_form_getForeColor(SObject* obj)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_getInteger(obj, form->foreColor.color));

	// If we get here, failure
	return(NULL);
}

bool iiSubobj_form_setCaptionColor(SObject* obj, SVariable* var)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_setInteger(obj, var, (s32*)&form->captionColor.color, 0, 0, false, 0));

	// If we get here, failure
	return(false);
}

SVariable* iiSubobj_form_getCaptionColor(SObject* obj)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_getInteger(obj, form->captionColor.color));

	// If we get here, failure
	return(NULL);
}

bool iiSubobj_form_setCaption(SObject* obj, SVariable* var)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_setCharacter(obj, var, &form->caption, var->value.data, var->value.length));

	// If we get here, failure
	return(false);
}

SVariable* iiSubobj_form_getCaption(SObject* obj)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_getCharacter(obj, &form->caption));

	// If we get here, failure
	return(false);
}

bool iiSubobj_form_setPicture(SObject* obj, SVariable* var)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_setCharacter(obj, var, &form->pictureName, var->value.data, var->value.length));

	// If we get here, failure
	return(false);
}

SVariable* iiSubobj_form_getPicture(SObject* obj)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_getCharacter(obj, &form->pictureName));

	// If we get here, failure
	return(false);
}

bool iiSubobj_form_setAllowOutput(SObject* obj, SVariable* var)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_setLogical(obj, var, &form->allowOutput));

	// If we get here, failure
	return(false);
}

SVariable* iiSubobj_form_getAllowOutput(SObject* obj)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_getLogical(obj, form->allowOutput));

	// If we get here, failure
	return(NULL);
}

bool iiSubobj_form_setAlwaysOnBottom(SObject* obj, SVariable* var)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_setLogical(obj, var, &form->alwaysOnBottom));

	// If we get here, failure
	return(false);
}

SVariable* iiSubobj_form_getAlwaysOnBottom(SObject* obj)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_getLogical(obj, form->alwaysOnBottom));

	// If we get here, failure
	return(NULL);
}

bool iiSubobj_form_setAlwaysOnTop(SObject* obj, SVariable* var)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_setLogical(obj, var, &form->alwaysOnTop));

	// If we get here, failure
	return(false);
}

SVariable* iiSubobj_form_getAlwaysOnTop(SObject* obj)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_getLogical(obj, form->alwaysOnTop));

	// If we get here, failure
	return(NULL);
}

bool iiSubobj_form_setAutoCenter(SObject* obj, SVariable* var)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_setLogical(obj, var, &form->autoCenter));

	// If we get here, failure
	return(false);
}

SVariable* iiSubobj_form_getAutoCenter(SObject* obj)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_getLogical(obj, form->autoCenter));

	// If we get here, failure
	return(NULL);
}

bool iiSubobj_form_setBorderStyle(SObject* obj, SVariable* var)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_setInteger(obj, var, (s32*)&form->borderStyle, 0, 3, true, 0));

	// If we get here, failure
	return(false);
}

SVariable* iiSubobj_form_getBorderStyle(SObject* obj)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_getInteger(obj, form->borderStyle));

	// If we get here, failure
	return(NULL);
}

bool iiSubobj_form_setIsCloseable(SObject* obj, SVariable* var)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_setLogical(obj, var, &form->isClosable));

	// If we get here, failure
	return(false);
}

SVariable* iiSubobj_form_getIsCloseable(SObject* obj)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_getLogical(obj, form->isClosable));

	// If we get here, failure
	return(NULL);
}

bool iiSubobj_form_setProcessKeyPreviewEvents(SObject* obj, SVariable* var)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_setLogical(obj, var, &form->processKeyPreviewEvents));

	// If we get here, failure
	return(false);
}

SVariable* iiSubobj_form_getProcessKeyPreviewEvents(SObject* obj)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_getLogical(obj, form->processKeyPreviewEvents));

	// If we get here, failure
	return(NULL);
}

bool iiSubobj_form_setHasControlBox(SObject* obj, SVariable* var)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_setLogical(obj, var, &form->hasControlBox));

	// If we get here, failure
	return(false);
}

SVariable* iiSubobj_form_getHasControlBox(SObject* obj)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_getLogical(obj, form->hasControlBox));

	// If we get here, failure
	return(NULL);
}

bool iiSubobj_form_setHasMinButton(SObject* obj, SVariable* var)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_setLogical(obj, var, &form->hasMinButton));

	// If we get here, failure
	return(false);
}

SVariable* iiSubobj_form_getHasMinButton(SObject* obj)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_getLogical(obj, form->hasMinButton));

	// If we get here, failure
	return(NULL);
}

bool iiSubobj_form_setHasCloseButton(SObject* obj, SVariable* var)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_setLogical(obj, var, &form->hasCloseButton));

	// If we get here, failure
	return(false);
}

SVariable* iiSubobj_form_getHasCloseButton(SObject* obj)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_getLogical(obj, form->hasCloseButton));

	// If we get here, failure
	return(NULL);
}

bool iiSubobj_form_setScaleMode(SObject* obj, SVariable* var)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_setInteger(obj, var, (s32*)&form->scaleMode, 0, 0, false, (u32)&iiSubobj_form_setScaleMode_extraTest));

	// If we get here, failure
	return(false);
}

bool iiSubobj_form_setScaleMode_extraTest(s32 value)
{
	if (value == 0 || value == 3)		return(true);
	else								return(false);
}

SVariable* iiSubobj_form_getScaleMode(SObject* obj)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_getInteger(obj, form->scaleMode));

	// If we get here, failure
	return(NULL);
}

bool iiSubobj_form_setShowInTaskBar(SObject* obj, SVariable* var)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_setLogical(obj, var, &form->showInTaskBar));

	// If we get here, failure
	return(false);
}

SVariable* iiSubobj_form_getShowInTaskBar(SObject* obj)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_getLogical(obj, form->showInTaskBar));

	// If we get here, failure
	return(NULL);
}

bool iiSubobj_form_setWindowState(SObject* obj, SVariable* var)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_setInteger(obj, var, (s32*)&form->windowState, 0, 1, true, 0));

	// If we get here, failure
	return(false);
}

SVariable* iiSubobj_form_getWindowState(SObject* obj)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_getInteger(obj, form->windowState));

	// If we get here, failure
	return(NULL);
}

bool iiSubobj_form_setBindControls(SObject* obj, SVariable* var)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_setLogical(obj, var, &form->bindControls));

	// If we get here, failure
	return(false);
}

SVariable* iiSubobj_form_getBindControls(SObject* obj)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_getLogical(obj, form->bindControls));

	// If we get here, failure
	return(NULL);
}

bool iiSubobj_form_setBufferMode(SObject* obj, SVariable* var)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_setInteger(obj, var, (s32*)&form->bufferMode, 0, 1, true, 0));

	// If we get here, failure
	return(false);
}

SVariable* iiSubobj_form_getBufferMode(SObject* obj)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_getInteger(obj, form->bufferMode));

	// If we get here, failure
	return(NULL);
}

bool iiSubobj_form_setClipControls(SObject* obj, SVariable* var)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_setLogical(obj, var, &form->clipControls));

	// If we get here, failure
	return(false);
}

SVariable* iiSubobj_form_getClipControls(SObject* obj)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_getLogical(obj, form->clipControls));

	// If we get here, failure
	return(NULL);
}

bool iiSubobj_form_setColorSource(SObject* obj, SVariable* var)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_setInteger(obj, var, (s32*)&form->colorSource, 0, 0, false, 0));

	// If we get here, failure
	return(false);
}

SVariable* iiSubobj_form_getColorSource(SObject* obj)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_getInteger(obj, form->colorSource));

	// If we get here, failure
	return(NULL);
}

bool iiSubobj_form_setContinuousScroll(SObject* obj, SVariable* var)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_setLogical(obj, var, &form->continuousScroll));

	// If we get here, failure
	return(false);
}

SVariable* iiSubobj_form_getContinuousScroll(SObject* obj)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_getLogical(obj, form->continuousScroll));

	// If we get here, failure
	return(NULL);
}

bool iiSubobj_form_setDataSession(SObject* obj, SVariable* var)
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

SVariable* iiSubobj_form_getDataSession(SObject* obj)
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

bool iiSubobj_form_setDataSessionId(SObject* obj, SVariable* var)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_setInteger(obj, var, (s32*)&form->dataSessionId, 0, 0, false, 0));

	// If we get here, failure
	return(false);
}

SVariable* iiSubobj_form_getDataSessionId(SObject* obj)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_getInteger(obj, form->dataSessionId));

	// If we get here, failure
	return(NULL);
}

bool iiSubobj_form_setDeClass(SObject* obj, SVariable* var)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_setCharacter(obj, var, &form->declass, var->value.data, var->value.length));

	// If we get here, failure
	return(false);
}

SVariable* iiSubobj_form_getDeClass(SObject* obj)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_getCharacter(obj, &form->declass));

	// If we get here, failure
	return(false);
}

bool iiSubobj_form_setDeClassLibrary(SObject* obj, SVariable* var)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_setCharacter(obj, var, &form->declasslibrary, var->value.data, var->value.length));

	// If we get here, failure
	return(false);
}

SVariable* iiSubobj_form_getDeClassLibrary(SObject* obj)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_getCharacter(obj, &form->declasslibrary));

	// If we get here, failure
	return(false);
}

bool iiSubobj_form_setDefOleCid(SObject* obj, SVariable* var)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_setInteger(obj, var, (s32*)&form->defolecid, 0, 0, false, 0));

	// If we get here, failure
	return(false);
}

SVariable* iiSubobj_form_getDefOleCid(SObject* obj)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_getInteger(obj, form->defolecid));

	// If we get here, failure
	return(NULL);
}

bool iiSubobj_form_setDesktop(SObject* obj, SVariable* var)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_setLogical(obj, var, &form->desktop));

	// If we get here, failure
	return(false);
}

SVariable* iiSubobj_form_getDesktop(SObject* obj)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_getLogical(obj, form->desktop));

	// If we get here, failure
	return(NULL);
}

bool iiSubobj_form_setIsDockable(SObject* obj, SVariable* var)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_setLogical(obj, var, &form->isDockable));

	// If we get here, failure
	return(false);
}

SVariable* iiSubobj_form_getIsDockable(SObject* obj)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_getLogical(obj, form->isDockable));

	// If we get here, failure
	return(NULL);
}

bool iiSubobj_form_setIsDocked(SObject* obj, SVariable* var)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_setLogical(obj, var, &form->isDocked));

	// If we get here, failure
	return(false);
}

SVariable* iiSubobj_form_getIsDocked(SObject* obj)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_getLogical(obj, form->isDocked));

	// If we get here, failure
	return(NULL);
}

bool iiSubobj_form_setDockPosition(SObject* obj, SVariable* var)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_setInteger(obj, var, (s32*)&form->dockPosition, 0, 0, false, 0));

	// If we get here, failure
	return(false);
}

SVariable* iiSubobj_form_getDockPosition(SObject* obj)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_getInteger(obj, form->dockPosition));

	// If we get here, failure
	return(NULL);
}

bool iiSubobj_form_setDrawMode(SObject* obj, SVariable* var)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_setInteger(obj, var, (s32*)&form->drawmode, 0, 0, false, 0));

	// If we get here, failure
	return(false);
}

SVariable* iiSubobj_form_getDrawMode(SObject* obj)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_getInteger(obj, form->drawmode));

	// If we get here, failure
	return(NULL);
}

bool iiSubobj_form_setDrawStyle(SObject* obj, SVariable* var)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_setInteger(obj, var, (s32*)&form->drawstyle, 0, 0, false, 0));

	// If we get here, failure
	return(false);
}

SVariable* iiSubobj_form_getDrawStyle(SObject* obj)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_getInteger(obj, form->drawstyle));

	// If we get here, failure
	return(NULL);
}

bool iiSubobj_form_setDrawWidth(SObject* obj, SVariable* var)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_setInteger(obj, var, (s32*)&form->drawwidth, 0, 0, false, 0));

	// If we get here, failure
	return(false);
}

SVariable* iiSubobj_form_getDrawWidth(SObject* obj)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_getInteger(obj, form->drawwidth));

	// If we get here, failure
	return(NULL);
}

bool iiSubobj_form_setFillColor(SObject* obj, SVariable* var)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_setInteger(obj, var, (s32*)&form->fillColor.color, 0, 0, false, 0));

	// If we get here, failure
	return(false);
}

SVariable* iiSubobj_form_getFillColor(SObject* obj)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_getInteger(obj, form->fillColor.color));

	// If we get here, failure
	return(NULL);
}

bool iiSubobj_form_setFillStyle(SObject* obj, SVariable* var)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_setInteger(obj, var, (s32*)&form->fillStyle, 0, 0, false, 0));

	// If we get here, failure
	return(false);
}

SVariable* iiSubobj_form_getFillStyle(SObject* obj)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_getInteger(obj, form->fillStyle));

	// If we get here, failure
	return(NULL);
}

bool iiSubobj_form_setHalfHeightCaption(SObject* obj, SVariable* var)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_setLogical(obj, var, &form->halfHeightCaption));

	// If we get here, failure
	return(false);
}

SVariable* iiSubobj_form_getHalfHeightCaption(SObject* obj)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_getLogical(obj, form->halfHeightCaption));

	// If we get here, failure
	return(NULL);
}

bool iiSubobj_form_setHScrollSmallChange(SObject* obj, SVariable* var)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_setInteger(obj, var, (s32*)&form->hScrollSmallChange, 0, 0, false, 0));

	// If we get here, failure
	return(false);
}

SVariable* iiSubobj_form_getHScrollSmallChange(SObject* obj)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_getInteger(obj, form->hScrollSmallChange));

	// If we get here, failure
	return(NULL);
}

bool iiSubobj_form_setVScrollSmallChange(SObject* obj, SVariable* var)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_setInteger(obj, var, (s32*)&form->vScrollSmallChange, 0, 0, false, 0));

	// If we get here, failure
	return(false);
}

SVariable* iiSubobj_form_getVScrollSmallChange(SObject* obj)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_getInteger(obj, form->vScrollSmallChange));

	// If we get here, failure
	return(NULL);
}

bool iiSubobj_form_setMacDesktop(SObject* obj, SVariable* var)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_setLogical(obj, var, &form->macDesktop));

	// If we get here, failure
	return(false);
}

SVariable* iiSubobj_form_getMacDesktop(SObject* obj)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_getLogical(obj, form->macDesktop));

	// If we get here, failure
	return(NULL);
}

bool iiSubobj_form_setMdiForm(SObject* obj, SVariable* var)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_setLogical(obj, var, &form->mdiForm));

	// If we get here, failure
	return(false);
}

SVariable* iiSubobj_form_getMdiForm(SObject* obj)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_getLogical(obj, form->mdiForm));

	// If we get here, failure
	return(NULL);
}

bool iiSubobj_form_setOleDragMode(SObject* obj, SVariable* var)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_setInteger(obj, var, (s32*)&form->oleDragMode, 0, 0, false, 0));

	// If we get here, failure
	return(false);
}

SVariable* iiSubobj_form_getOleDragMode(SObject* obj)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_getInteger(obj, form->oleDragMode));

	// If we get here, failure
	return(NULL);
}

bool iiSubobj_form_setOleDropEffects(SObject* obj, SVariable* var)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_setInteger(obj, var, (s32*)&form->oleDropEffects, 0, 0, false, 0));

	// If we get here, failure
	return(false);
}

SVariable* iiSubobj_form_getOleDropEffects(SObject* obj)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_getInteger(obj, form->oleDropEffects));

	// If we get here, failure
	return(NULL);
}

bool iiSubobj_form_setOleDropHasData(SObject* obj, SVariable* var)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_setInteger(obj, var, (s32*)&form->oleDropHasData, 0, 0, false, 0));

	// If we get here, failure
	return(false);
}

SVariable* iiSubobj_form_getOleDropHasData(SObject* obj)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_getInteger(obj, form->oleDropHasData));

	// If we get here, failure
	return(NULL);
}

bool iiSubobj_form_setOleDropMode(SObject* obj, SVariable* var)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_setInteger(obj, var, (s32*)&form->oleDropMode, 0, 0, false, 0));

	// If we get here, failure
	return(false);
}

SVariable* iiSubobj_form_getOleDropMode(SObject* obj)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_getInteger(obj, form->oleDropMode));

	// If we get here, failure
	return(NULL);
}

bool iiSubobj_form_setReleaseType(SObject* obj, SVariable* var)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_setInteger(obj, var, (s32*)&form->releaseType, 0, 0, false, 0));

	// If we get here, failure
	return(false);
}

SVariable* iiSubobj_form_getReleaseType(SObject* obj)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_getInteger(obj, form->releaseType));

	// If we get here, failure
	return(NULL);
}

bool iiSubobj_form_setRightToLeft(SObject* obj, SVariable* var)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_setLogical(obj, var, &form->rightToLeft));

	// If we get here, failure
	return(false);
}

SVariable* iiSubobj_form_getRightToLeft(SObject* obj)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_getLogical(obj, form->rightToLeft));

	// If we get here, failure
	return(NULL);
}

bool iiSubobj_form_setScrollbars(SObject* obj, SVariable* var)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_setInteger(obj, var, (s32*)&form->scrollbars, 0, 0, false, 0));

	// If we get here, failure
	return(false);
}

SVariable* iiSubobj_form_getScrollbars(SObject* obj)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_getInteger(obj, form->scrollbars));

	// If we get here, failure
	return(NULL);
}

bool iiSubobj_form_setShowTips(SObject* obj, SVariable* var)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_setInteger(obj, var, (s32*)&form->showTips, 0, 0, false, 0));

	// If we get here, failure
	return(false);
}

SVariable* iiSubobj_form_getShowTips(SObject* obj)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_getInteger(obj, form->showTips));

	// If we get here, failure
	return(NULL);
}

bool iiSubobj_form_setShowWindow(SObject* obj, SVariable* var)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_setInteger(obj, var, (s32*)&form->showWindow, 0, 0, false, 0));

	// If we get here, failure
	return(false);
}

SVariable* iiSubobj_form_getShowWindow(SObject* obj)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_getInteger(obj, form->showWindow));

	// If we get here, failure
	return(NULL);
}

bool iiSubobj_form_setSizeBox(SObject* obj, SVariable* var)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_setLogical(obj, var, &form->sizeBox));

	// If we get here, failure
	return(false);
}

SVariable* iiSubobj_form_getSizeBox(SObject* obj)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_getLogical(obj, form->sizeBox));

	// If we get here, failure
	return(NULL);
}

bool iiSubobj_form_setThemes(SObject* obj, SVariable* var)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_setLogical(obj, var, &form->themes));

	// If we get here, failure
	return(false);
}

SVariable* iiSubobj_form_getThemes(SObject* obj)
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

bool iiSubobj_form_setTitleBar(SObject* obj, SVariable* var)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_setInteger(obj, var, (s32*)&form->titleBar, 0, 0, false, 0));

	// If we get here, failure
	return(false);
}

SVariable* iiSubobj_form_getTitleBar(SObject* obj)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_getInteger(obj, form->titleBar));

	// If we get here, failure
	return(NULL);
}

bool iiSubobj_form_setWindowType(SObject* obj, SVariable* var)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_setInteger(obj, var, (s32*)&form->windowType, 0, 0, false, 0));

	// If we get here, failure
	return(false);
}

SVariable* iiSubobj_form_getWindowType(SObject* obj)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_getInteger(obj, form->windowType));

	// If we get here, failure
	return(NULL);
}

bool iiSubobj_form_setZoomBox(SObject* obj, SVariable* var)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_setLogical(obj, var, &form->zoomBox));

	// If we get here, failure
	return(false);
}

SVariable* iiSubobj_form_getZoomBox(SObject* obj)
{
	SSubObjForm* form;


	// Make sure our environment is sane
	form = (SSubObjForm*)obj->sub_obj;
	if (form)
		return(iObj_getLogical(obj, form->zoomBox));

	// If we get here, failure
	return(NULL);
}









//////////
// SUBFORM Properties
//////
bool iiSubobj_subform_setMinLeft(SObject* obj, SVariable* var)
{
	SSubObjSubform* subform;


	// Make sure our environment is sane
	subform = (SSubObjSubform*)obj->sub_obj;
	if (subform)
		return(iObj_setInteger(obj, var, &subform->rcMin.left, 0, 0, false, 0));

	// If we get here, failure
	return(false);
}

SVariable* iiSubobj_subform_getMinLeft(SObject* obj)
{
	SSubObjSubform* subform;


	// Make sure our environment is sane
	subform = (SSubObjSubform*)obj->sub_obj;
	if (subform)
		return(iObj_getInteger(obj, subform->rcMin.left));

	// If we get here, failure
	return(NULL);
}

bool iiSubobj_subform_setMinTop(SObject* obj, SVariable* var)
{
	SSubObjSubform* subform;


	// Make sure our environment is sane
	subform = (SSubObjSubform*)obj->sub_obj;
	if (subform)
		return(iObj_setInteger(obj, var, &subform->rcMin.top, 0, 0, false, 0));

	// If we get here, failure
	return(false);
}

SVariable* iiSubobj_subform_getMinTop(SObject* obj)
{
	SSubObjSubform* subform;


	// Make sure our environment is sane
	subform = (SSubObjSubform*)obj->sub_obj;
	if (subform)
		return(iObj_getInteger(obj, subform->rcMin.top));

	// If we get here, failure
	return(NULL);
}

bool iiSubobj_subform_setMinWidth(SObject* obj, SVariable* var)
{
	s32				value;
	bool			error;
	u32				errorNum;
	SSubObjSubform*	subform;


	// Make sure our environment is sane
	subform = (SSubObjSubform*)obj->sub_obj;
	if (subform && iVariable_isTypeNumeric(var))
	{
		value = iiVariable_getAs_s32(var, false, &error, &errorNum);
		if (error)
		{
			iError_reportByNumber(errorNum, NULL);
			return(false);
		}

		// Set the value
		subform->rcMin.right = subform->rcMin.left + value;
	}

	// If we get here, failure
	return(false);
}

SVariable* iiSubobj_subform_getMinWidth(SObject* obj)
{
	SSubObjSubform* subform;


	// Make sure our environment is sane
	subform = (SSubObjSubform*)obj->sub_obj;
	if (subform)
		return(iObj_getInteger(obj, subform->rcMin.right - subform->rcMin.left));

	// If we get here, failure
	return(NULL);
}

bool iiSubobj_subform_setMinHeight(SObject* obj, SVariable* var)
{
	s32				value;
	bool			error;
	u32				errorNum;
	SSubObjSubform*	subform;


	// Make sure our environment is sane
	subform = (SSubObjSubform*)obj->sub_obj;
	if (subform && iVariable_isTypeNumeric(var))
	{
		value = iiVariable_getAs_s32(var, false, &error, &errorNum);
		if (error)
		{
			iError_reportByNumber(errorNum, NULL);
			return(false);
		}

		// Set the value
		subform->rcMin.bottom = subform->rcMin.top + value;
	}

	// If we get here, failure
	return(false);
}

SVariable* iiSubobj_subform_getMinHeight(SObject* obj)
{
	SSubObjSubform* subform;


	// Make sure our environment is sane
	subform = (SSubObjSubform*)obj->sub_obj;
	if (subform)
		return(iObj_getInteger(obj, subform->rcMin.bottom - subform->rcMin.top));

	// If we get here, failure
	return(NULL);
}

bool iiSubobj_subform_setMaxLeft(SObject* obj, SVariable* var)
{
	SSubObjSubform* subform;


	// Make sure our environment is sane
	subform = (SSubObjSubform*)obj->sub_obj;
	if (subform)
		return(iObj_setInteger(obj, var, &subform->rcMax.left, 0, 0, false, 0));

	// If we get here, failure
	return(false);
}

SVariable* iiSubobj_subform_getMaxLeft(SObject* obj)
{
	SSubObjSubform* subform;


	// Make sure our environment is sane
	subform = (SSubObjSubform*)obj->sub_obj;
	if (subform)
		return(iObj_getInteger(obj, subform->rcMax.left));

	// If we get here, failure
	return(NULL);
}

bool iiSubobj_subform_setMaxTop(SObject* obj, SVariable* var)
{
	SSubObjSubform* subform;


	// Make sure our environment is sane
	subform = (SSubObjSubform*)obj->sub_obj;
	if (subform)
		return(iObj_setInteger(obj, var, &subform->rcMax.top, 0, 0, false, 0));

	// If we get here, failure
	return(false);
}

SVariable* iiSubobj_subform_getMaxTop(SObject* obj)
{
	SSubObjSubform* subform;


	// Make sure our environment is sane
	subform = (SSubObjSubform*)obj->sub_obj;
	if (subform)
		return(iObj_getInteger(obj, subform->rcMin.top));

	// If we get here, failure
	return(NULL);
}

bool iiSubobj_subform_setMaxWidth(SObject* obj, SVariable* var)
{
	s32				value;
	bool			error;
	u32				errorNum;
	SSubObjSubform*	subform;


	// Make sure our environment is sane
	subform = (SSubObjSubform*)obj->sub_obj;
	if (subform && iVariable_isTypeNumeric(var))
	{
		value = iiVariable_getAs_s32(var, false, &error, &errorNum);
		if (error)
		{
			iError_reportByNumber(errorNum, NULL);
			return(false);
		}

		// Set the value
		subform->rcMax.right = subform->rcMax.left + value;
	}

	// If we get here, failure
	return(false);
}

SVariable* iiSubobj_subform_getMaxWidth(SObject* obj)
{
	SSubObjSubform* subform;


	// Make sure our environment is sane
	subform = (SSubObjSubform*)obj->sub_obj;
	if (subform)
		return(iObj_getInteger(obj, subform->rcMax.right - subform->rcMax.left));

	// If we get here, failure
	return(NULL);
}

bool iiSubobj_subform_setMaxHeight(SObject* obj, SVariable* var)
{
	s32				value;
	bool			error;
	u32				errorNum;
	SSubObjSubform*	subform;


	// Make sure our environment is sane
	subform = (SSubObjSubform*)obj->sub_obj;
	if (subform && iVariable_isTypeNumeric(var))
	{
		value = iiVariable_getAs_s32(var, false, &error, &errorNum);
		if (error)
		{
			iError_reportByNumber(errorNum, NULL);
			return(false);
		}

		// Set the value
		subform->rcMax.bottom = subform->rcMax.top + value;
	}

	// If we get here, failure
	return(false);
}

SVariable* iiSubobj_subform_getMaxHeight(SObject* obj)
{
	SSubObjSubform* subform;


	// Make sure our environment is sane
	subform = (SSubObjSubform*)obj->sub_obj;
	if (subform)
		return(iObj_getInteger(obj, subform->rcMin.bottom - subform->rcMin.top));

	// If we get here, failure
	return(NULL);
}

bool iiSubobj_subform_setFontName(SObject* obj, SVariable* var)
{
	bool			llResult;
	SSubObjSubform*	subform;


	// Make sure our environment is sane
	subform = (SSubObjSubform*)obj->sub_obj;
	if (subform)
	{
		// Perform the update
		llResult = iObj_setCharacter(obj, var, &subform->font->name, var->value.data, var->value.length);
		if (llResult)
			iiFont_refresh(subform->font);		// Refresh the font with its new settings

		// Indicate our status
		return(llResult);
	}

	// If we get here, failure
	return(false);
}

SVariable* iiSubobj_subform_getFontName(SObject* obj)
{
	SSubObjSubform* subform;


	// Make sure our environment is sane
	subform = (SSubObjSubform*)obj->sub_obj;
	if (subform)
		return(iObj_getCharacter(obj, &subform->font->name));

	// If we get here, failure
	return(false);
}

bool iiSubobj_subform_setFontSize(SObject* obj, SVariable* var)
{
	bool			llResult;
	SSubObjSubform*	subform;


	// Make sure our environment is sane
	subform = (SSubObjSubform*)obj->sub_obj;
	if (subform)
	{
		// Perform the update
		llResult = iObj_setInteger(obj, var, (s32*)&subform->font->_size, 0, 0, false, 0);
		if (llResult)
			iiFont_refresh(subform->font);		// Refresh the font with its new settings

		// Indicate our status
		return(llResult);
	}

	// If we get here, failure
	return(false);
}

SVariable* iiSubobj_subform_getFontSize(SObject* obj)
{
	SSubObjSubform* subform;


	// Make sure our environment is sane
	subform = (SSubObjSubform*)obj->sub_obj;
	if (subform)
		return(iObj_getInteger(obj, subform->font->_size));

	// If we get here, failure
	return(NULL);
}

bool iiSubobj_subform_setFontBold(SObject* obj, SVariable* var)
{
	bool			llResult;
	SSubObjSubform*	subform;


	// Make sure our environment is sane
	subform = (SSubObjSubform*)obj->sub_obj;
	if (subform)
	{
		// Perform the update
		llResult = iObj_setLogical(obj, var, &subform->font->isBold);
		if (llResult)
			iiFont_refresh(subform->font);		// Refresh the font with its new settings

		// Indicate our status
		return(llResult);
	}

	// If we get here, failure
	return(false);
}

SVariable* iiSubobj_subform_getFontBold(SObject* obj)
{
	SSubObjSubform* subform;


	// Make sure our environment is sane
	subform = (SSubObjSubform*)obj->sub_obj;
	if (subform)
		return(iObj_getLogical(obj, subform->font->isBold));

	// If we get here, failure
	return(NULL);
}

bool iiSubobj_subform_setFontItalic(SObject* obj, SVariable* var)
{
	bool			llResult;
	SSubObjSubform*	subform;


	// Make sure our environment is sane
	subform = (SSubObjSubform*)obj->sub_obj;
	if (subform)
	{
		// Perform the update
		llResult = iObj_setLogical(obj, var, &subform->font->isItalic);
		if (llResult)
			iiFont_refresh(subform->font);		// Refresh the font with its new settings

		// Indicate our status
		return(llResult);
	}

	// If we get here, failure
	return(false);
}

SVariable* iiSubobj_subform_getFontItalic(SObject* obj)
{
	SSubObjSubform* subform;


	// Make sure our environment is sane
	subform = (SSubObjSubform*)obj->sub_obj;
	if (subform)
		return(iObj_getLogical(obj, subform->font->isItalic));

	// If we get here, failure
	return(NULL);
}

bool iiSubobj_subform_setFontUnderline(SObject* obj, SVariable* var)
{
	bool			llResult;
	SSubObjSubform*	subform;


	// Make sure our environment is sane
	subform = (SSubObjSubform*)obj->sub_obj;
	if (subform)
	{
		// Perform the update
		llResult = iObj_setLogical(obj, var, &subform->font->isUnderline);
		if (llResult)
			iiFont_refresh(subform->font);		// Refresh the font with its new settings

		// Indicate our status
		return(llResult);
	}

	// If we get here, failure
	return(false);
}

SVariable* iiSubobj_subform_getFontUnderline(SObject* obj)
{
	SSubObjSubform* subform;


	// Make sure our environment is sane
	subform = (SSubObjSubform*)obj->sub_obj;
	if (subform)
		return(iObj_getLogical(obj, subform->font->isUnderline));

	// If we get here, failure
	return(NULL);
}

bool iiSubobj_subform_setFontStrikethrough(SObject* obj, SVariable* var)
{
	bool			llResult;
	SSubObjSubform*	subform;


	// Make sure our environment is sane
	subform = (SSubObjSubform*)obj->sub_obj;
	if (subform)
	{
		// Perform the update
		llResult = iObj_setLogical(obj, var, &subform->font->isStrikethrough);
		if (llResult)
			iiFont_refresh(subform->font);		// Refresh the font with its new settings

		// Indicate our status
		return(llResult);
	}

	// If we get here, failure
	return(false);
}

SVariable* iiSubobj_subform_getFontStrikethrough(SObject* obj)
{
	SSubObjSubform* subform;


	// Make sure our environment is sane
	subform = (SSubObjSubform*)obj->sub_obj;
	if (subform)
		return(iObj_getLogical(obj, subform->font->isStrikethrough));

	// If we get here, failure
	return(NULL);
}

bool iiSubobj_subform_setFontCondensed(SObject* obj, SVariable* var)
{
	bool			llResult;
	SSubObjSubform*	subform;


	// Make sure our environment is sane
	subform = (SSubObjSubform*)obj->sub_obj;
	if (subform)
	{
		// Perform the update
		llResult = iObj_setLogical(obj, var, &subform->font->isCondensed);
		if (llResult)
			iiFont_refresh(subform->font);		// Refresh the font with its new settings

		// Indicate our status
		return(llResult);
	}

	// If we get here, failure
	return(false);
}

SVariable* iiSubobj_subform_getFontCondensed(SObject* obj)
{
	SSubObjSubform* subform;


	// Make sure our environment is sane
	subform = (SSubObjSubform*)obj->sub_obj;
	if (subform)
		return(iObj_getLogical(obj, subform->font->isCondensed));

	// If we get here, failure
	return(NULL);
}

bool iiSubobj_subform_setFontExtended(SObject* obj, SVariable* var)
{
	bool			llResult;
	SSubObjSubform*	subform;


	// Make sure our environment is sane
	subform = (SSubObjSubform*)obj->sub_obj;
	if (subform)
	{
		// Perform the update
		llResult = iObj_setLogical(obj, var, &subform->font->isExtended);
		if (llResult)
			iiFont_refresh(subform->font);		// Refresh the font with its new settings

		// Indicate our status
		return(llResult);
	}

	// If we get here, failure
	return(false);
}

SVariable* iiSubobj_subform_getFontExtended(SObject* obj)
{
	SSubObjSubform* subform;


	// Make sure our environment is sane
	subform = (SSubObjSubform*)obj->sub_obj;
	if (subform)
		return(iObj_getLogical(obj, subform->font->isExtended));

	// If we get here, failure
	return(NULL);
}

bool iiSubobj_subform_setFontOutline(SObject* obj, SVariable* var)
{
	bool			llResult;
	SSubObjSubform*	subform;


	// Make sure our environment is sane
	subform = (SSubObjSubform*)obj->sub_obj;
	if (subform)
	{
		// Perform the update
		llResult = iObj_setLogical(obj, var, &subform->font->isOutline);
		if (llResult)
			iiFont_refresh(subform->font);		// Refresh the font with its new settings

		// Indicate our status
		return(llResult);
	}

	// If we get here, failure
	return(false);
}

SVariable* iiSubobj_subform_getFontOutline(SObject* obj)
{
	SSubObjSubform* subform;


	// Make sure our environment is sane
	subform = (SSubObjSubform*)obj->sub_obj;
	if (subform)
		return(iObj_getLogical(obj, subform->font->isOutline));

	// If we get here, failure
	return(NULL);
}

bool iiSubobj_subform_setFontShadow(SObject* obj, SVariable* var)
{
	bool			llResult;
	SSubObjSubform*	subform;


	// Make sure our environment is sane
	subform = (SSubObjSubform*)obj->sub_obj;
	if (subform)
	{
		// Perform the update
		llResult = iObj_setLogical(obj, var, &subform->font->isShadow);
		if (llResult)
			iiFont_refresh(subform->font);		// Refresh the font with its new settings

		// Indicate our status
		return(llResult);
	}

	// If we get here, failure
	return(false);
}

SVariable* iiSubobj_subform_getFontShadow(SObject* obj)
{
	SSubObjSubform* subform;


	// Make sure our environment is sane
	subform = (SSubObjSubform*)obj->sub_obj;
	if (subform)
		return(iObj_getLogical(obj, subform->font->isShadow));

	// If we get here, failure
	return(NULL);
}

bool iiSubobj_subform_setNwColor(SObject* obj, SVariable* var)
{
	SSubObjSubform* subform;


	// Make sure our environment is sane
	subform = (SSubObjSubform*)obj->sub_obj;
	if (subform)
		return(iObj_setInteger(obj, var, (s32*)&subform->nwRgba.color, 0, 0, false, 0));

	// If we get here, failure
	return(false);
}

SVariable* iiSubobj_subform_getNwColor(SObject* obj)
{
	SSubObjSubform* subform;


	// Make sure our environment is sane
	subform = (SSubObjSubform*)obj->sub_obj;
	if (subform)
		return(iObj_getInteger(obj, subform->nwRgba.color));

	// If we get here, failure
	return(NULL);
}

bool iiSubobj_subform_setNeColor(SObject* obj, SVariable* var)
{
	SSubObjSubform* subform;


	// Make sure our environment is sane
	subform = (SSubObjSubform*)obj->sub_obj;
	if (subform)
		return(iObj_setInteger(obj, var, (s32*)&subform->neRgba.color, 0, 0, false, 0));

	// If we get here, failure
	return(false);
}

SVariable* iiSubobj_subform_getNeColor(SObject* obj)
{
	SSubObjSubform* subform;


	// Make sure our environment is sane
	subform = (SSubObjSubform*)obj->sub_obj;
	if (subform)
		return(iObj_getInteger(obj, subform->neRgba.color));

	// If we get here, failure
	return(NULL);
}

bool iiSubobj_subform_setSwColor(SObject* obj, SVariable* var)
{
	SSubObjSubform* subform;


	// Make sure our environment is sane
	subform = (SSubObjSubform*)obj->sub_obj;
	if (subform)
		return(iObj_setInteger(obj, var, (s32*)&subform->swRgba.color, 0, 0, false, 0));

	// If we get here, failure
	return(false);
}

SVariable* iiSubobj_subform_getSwColor(SObject* obj)
{
	SSubObjSubform* subform;


	// Make sure our environment is sane
	subform = (SSubObjSubform*)obj->sub_obj;
	if (subform)
		return(iObj_getInteger(obj, subform->swRgba.color));

	// If we get here, failure
	return(NULL);
}

bool iiSubobj_subform_setSeColor(SObject* obj, SVariable* var)
{
	SSubObjSubform* subform;


	// Make sure our environment is sane
	subform = (SSubObjSubform*)obj->sub_obj;
	if (subform)
		return(iObj_setInteger(obj, var, (s32*)&subform->seRgba.color, 0, 0, false, 0));

	// If we get here, failure
	return(false);
}

SVariable* iiSubobj_subform_getSeColor(SObject* obj)
{
	SSubObjSubform* subform;


	// Make sure our environment is sane
	subform = (SSubObjSubform*)obj->sub_obj;
	if (subform)
		return(iObj_getInteger(obj, subform->seRgba.color));

	// If we get here, failure
	return(NULL);
}

bool iiSubobj_subform_setBackColor(SObject* obj, SVariable* var)
{
	SSubObjSubform* subform;


	// Make sure our environment is sane
	subform = (SSubObjSubform*)obj->sub_obj;
	if (subform)
		return(iObj_setInteger(obj, var, (s32*)&subform->backColor.color, 0, 0, false, 0));

	// If we get here, failure
	return(false);
}

SVariable* iiSubobj_subform_getBackColor(SObject* obj)
{
	SSubObjSubform* subform;


	// Make sure our environment is sane
	subform = (SSubObjSubform*)obj->sub_obj;
	if (subform)
		return(iObj_getInteger(obj, subform->backColor.color));

	// If we get here, failure
	return(NULL);
}

bool iiSubobj_subform_setForeColor(SObject* obj, SVariable* var)
{
	SSubObjSubform* subform;


	// Make sure our environment is sane
	subform = (SSubObjSubform*)obj->sub_obj;
	if (subform)
		return(iObj_setInteger(obj, var, (s32*)&subform->foreColor.color, 0, 0, false, 0));

	// If we get here, failure
	return(false);
}

SVariable* iiSubobj_subform_getForeColor(SObject* obj)
{
	SSubObjSubform* subform;


	// Make sure our environment is sane
	subform = (SSubObjSubform*)obj->sub_obj;
	if (subform)
		return(iObj_getInteger(obj, subform->foreColor.color));

	// If we get here, failure
	return(NULL);
}

bool iiSubobj_subform_setCaptionColor(SObject* obj, SVariable* var)
{
	SSubObjSubform* subform;


	// Make sure our environment is sane
	subform = (SSubObjSubform*)obj->sub_obj;
	if (subform)
		return(iObj_setInteger(obj, var, (s32*)&subform->captionColor.color, 0, 0, false, 0));

	// If we get here, failure
	return(false);
}

SVariable* iiSubobj_subform_getCaptionColor(SObject* obj)
{
	SSubObjSubform* subform;


	// Make sure our environment is sane
	subform = (SSubObjSubform*)obj->sub_obj;
	if (subform)
		return(iObj_getInteger(obj, subform->captionColor.color));

	// If we get here, failure
	return(NULL);
}

bool iiSubobj_subform_setCaption(SObject* obj, SVariable* var)
{
	SSubObjSubform* subform;


	// Make sure our environment is sane
	subform = (SSubObjSubform*)obj->sub_obj;
	if (subform)
		return(iObj_setCharacter(obj, var, &subform->caption, var->value.data, var->value.length));

	// If we get here, failure
	return(false);
}

SVariable* iiSubobj_subform_getCaption(SObject* obj)
{
	SSubObjSubform* subform;


	// Make sure our environment is sane
	subform = (SSubObjSubform*)obj->sub_obj;
	if (subform)
		return(iObj_getCharacter(obj, &subform->caption));

	// If we get here, failure
	return(false);
}

bool iiSubobj_subform_setPicture(SObject* obj, SVariable* var)
{
	SSubObjSubform* subform;


	// Make sure our environment is sane
	subform = (SSubObjSubform*)obj->sub_obj;
	if (subform)
		return(iObj_setCharacter(obj, var, &subform->pictureName, var->value.data, var->value.length));

	// If we get here, failure
	return(false);
}

SVariable* iiSubobj_subform_getPicture(SObject* obj)
{
	SSubObjSubform* subform;


	// Make sure our environment is sane
	subform = (SSubObjSubform*)obj->sub_obj;
	if (subform)
		return(iObj_getCharacter(obj, &subform->pictureName));

	// If we get here, failure
	return(false);
}

bool iiSubobj_subform_setAllowOutput(SObject* obj, SVariable* var)
{
	SSubObjSubform* subform;


	// Make sure our environment is sane
	subform = (SSubObjSubform*)obj->sub_obj;
	if (subform)
		return(iObj_setLogical(obj, var, &subform->allowOutput));

	// If we get here, failure
	return(false);
}

SVariable* iiSubobj_subform_getAllowOutput(SObject* obj)
{
	SSubObjSubform* subform;


	// Make sure our environment is sane
	subform = (SSubObjSubform*)obj->sub_obj;
	if (subform)
		return(iObj_getLogical(obj, subform->allowOutput));

	// If we get here, failure
	return(NULL);
}

bool iiSubobj_subform_setBorderStyle(SObject* obj, SVariable* var)
{
	SSubObjSubform* subform;


	// Make sure our environment is sane
	subform = (SSubObjSubform*)obj->sub_obj;
	if (subform)
		return(iObj_setInteger(obj, var, (s32*)&subform->borderStyle, 0, 3, true, 0));

	// If we get here, failure
	return(false);
}

SVariable* iiSubobj_subform_getBorderStyle(SObject* obj)
{
	SSubObjSubform* subform;


	// Make sure our environment is sane
	subform = (SSubObjSubform*)obj->sub_obj;
	if (subform)
		return(iObj_getInteger(obj, subform->borderStyle));

	// If we get here, failure
	return(NULL);
}

bool iiSubobj_subform_setProcessKeyPreviewEvents(SObject* obj, SVariable* var)
{
	SSubObjSubform* subform;


	// Make sure our environment is sane
	subform = (SSubObjSubform*)obj->sub_obj;
	if (subform)
		return(iObj_setLogical(obj, var, &subform->processKeyPreviewEvents));

	// If we get here, failure
	return(false);
}

SVariable* iiSubobj_subform_getProcessKeyPreviewEvents(SObject* obj)
{
	SSubObjSubform* subform;


	// Make sure our environment is sane
	subform = (SSubObjSubform*)obj->sub_obj;
	if (subform)
		return(iObj_getLogical(obj, subform->processKeyPreviewEvents));

	// If we get here, failure
	return(NULL);
}

bool iiSubobj_subform_setScaleMode(SObject* obj, SVariable* var)
{
	SSubObjSubform* subform;


	// Make sure our environment is sane
	subform = (SSubObjSubform*)obj->sub_obj;
	if (subform)
		return(iObj_setInteger(obj, var, (s32*)&subform->scaleMode, 0, 0, false, (u32)&iiSubobj_subform_setScaleMode_extraTest));

	// If we get here, failure
	return(false);
}

bool iiSubobj_subform_setScaleMode_extraTest(s32 value)
{
	if (value == 0 || value == 3)		return(true);
	else								return(false);
}

SVariable* iiSubobj_subform_getScaleMode(SObject* obj)
{
	SSubObjSubform* subform;


	// Make sure our environment is sane
	subform = (SSubObjSubform*)obj->sub_obj;
	if (subform)
		return(iObj_getInteger(obj, subform->scaleMode));

	// If we get here, failure
	return(NULL);
}

bool iiSubobj_subform_setWindowState(SObject* obj, SVariable* var)
{
	SSubObjSubform* subform;


	// Make sure our environment is sane
	subform = (SSubObjSubform*)obj->sub_obj;
	if (subform)
		return(iObj_setInteger(obj, var, (s32*)&subform->windowState, 0, 1, true, 0));

	// If we get here, failure
	return(false);
}

SVariable* iiSubobj_subform_getWindowState(SObject* obj)
{
	SSubObjSubform* subform;


	// Make sure our environment is sane
	subform = (SSubObjSubform*)obj->sub_obj;
	if (subform)
		return(iObj_getInteger(obj, subform->windowState));

	// If we get here, failure
	return(NULL);
}
