//////////
//
// /libsf/source/vjr/object_accessors.cpp
//
//////
// Version 0.30
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
//








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
	s32		value;
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
		obj->tabIndex = value;

		// Indicate success
		return(true);
	}
	// If we get here, failure
	return(false);
}

SVariable* iObj_getProperty_tabIndex(SObject* obj)
{
	SVariable* var;


	// Make sure the environment is sane
	if (obj)
	{
		// Create a new variable
		var = iVariable_create(_VAR_TYPE_INTEGER, NULL);
		*(s32*)var->value.data = obj->tabIndex;
		return(var);
	}
	// If we get here, failure
	return(NULL);
}

bool iObj_setProperty_tabStop(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_isTypeLogical(var))
	{
		// Set the value
		obj->tabStop = ((var->value.data[0] == _LOGICAL_FALSE) ? false : true);

		// Indicate success
		return(true);
	}
	// If we get here, failure
	return(false);
}

SVariable* iObj_getProperty_tabStop(SObject* obj)
{
	SVariable* var;


	// Make sure the environment is sane
	if (obj)
	{
		// Create a new variable
		var = iVariable_create(_VAR_TYPE_LOGICAL, NULL);
		*(u8*)var->value.data = ((obj->tabStop) ? _LOGICAL_TRUE : _LOGICAL_FALSE);
		return(var);
	}
	// If we get here, failure
	return(NULL);
}

bool iObj_setProperty_helpContextId(SObject* obj, SVariable* var)
{
	s32		value;
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
		obj->helpContextId = value;

		// Indicate success
		return(true);
	}
	// If we get here, failure
	return(false);
}

SVariable* iObj_getProperty_helpContextId(SObject* obj)
{
	SVariable* var;


	// Make sure the environment is sane
	if (obj)
	{
		// Create a new variable
		var = iVariable_create(_VAR_TYPE_INTEGER, NULL);
		*(s32*)var->value.data = obj->helpContextId;
		return(var);
	}
	// If we get here, failure
	return(NULL);
}

bool iObj_setProperty_hasWhatsThisButton(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_isTypeLogical(var))
	{
		// Set the value
		obj->hasWhatsThisButton = ((var->value.data[0] == _LOGICAL_FALSE) ? false : true);

		// Indicate success
		return(true);
	}
	// If we get here, failure
	return(false);
}

SVariable* iObj_getProperty_hasWhatsThisButton(SObject* obj)
{
	SVariable* var;


	// Make sure the environment is sane
	if (obj)
	{
		// Create a new variable
		var = iVariable_create(_VAR_TYPE_LOGICAL, NULL);
		*(u8*)var->value.data = ((obj->hasWhatsThisButton) ? _LOGICAL_TRUE : _LOGICAL_FALSE);
		return(var);
	}
	// If we get here, failure
	return(NULL);
}

bool iObj_setProperty_hasWhatsThisHelp(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_isTypeLogical(var))
	{
		// Set the value
		obj->hasWhatsThisHelp = ((var->value.data[0] == _LOGICAL_FALSE) ? false : true);

		// Indicate success
		return(true);
	}
	// If we get here, failure
	return(false);
}

SVariable* iObj_getProperty_hasWhatsThisHelp(SObject* obj)
{
	SVariable* var;


	// Make sure the environment is sane
	if (obj)
	{
		// Create a new variable
		var = iVariable_create(_VAR_TYPE_LOGICAL, NULL);
		*(u8*)var->value.data = ((obj->hasWhatsThisHelp) ? _LOGICAL_TRUE : _LOGICAL_FALSE);
		return(var);
	}
	// If we get here, failure
	return(NULL);
}

bool iObj_setProperty_whatsThisHelpId(SObject* obj, SVariable* var)
{
	s32		value;
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
		obj->whatsThisHelpId = value;

		// Indicate success
		return(true);
	}
	// If we get here, failure
	return(false);
}

SVariable* iObj_getProperty_whatsThisHelpId(SObject* obj)
{
	SVariable* var;


	// Make sure the environment is sane
	if (obj)
	{
		// Create a new variable
		var = iVariable_create(_VAR_TYPE_INTEGER, NULL);
		*(s32*)var->value.data = obj->whatsThisHelpId;
		return(var);
	}
	// If we get here, failure
	return(NULL);
}

bool iObj_setProperty_name(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_isTypeCharacter(var))
	{
		// Set the value
		iDatum_duplicate(&obj->name, &var->value);

		// Indicate success
		return(true);
	}
	// If we get here, failure
	return(false);
}

SVariable* iObj_getProperty_name(SObject* obj)
{
	SVariable* var;


	// Make sure the environment is sane
	if (obj)
	{
		// Create a new variable
		var = iVariable_create(_VAR_TYPE_CHARACTER, NULL);
		iDatum_duplicate(&var->value, &obj->name);
		return(var);
	}
	// If we get here, failure
	return(NULL);
}

SVariable* iObj_getProperty_className(SObject* obj)
{
	SVariable* var;


	// Make sure the environment is sane
	if (obj)
	{
		// Create a new variable
		var = iVariable_create(_VAR_TYPE_CHARACTER, NULL);
		iDatum_duplicate(&var->value, &obj->className);
		return(var);
	}
	// If we get here, failure
	return(NULL);
}

SVariable* iObj_getProperty_classLibrary(SObject* obj)
{
	SVariable* var;


	// Make sure the environment is sane
	if (obj)
	{
		// Create a new variable
		var = iVariable_create(_VAR_TYPE_CHARACTER, NULL);
		iDatum_duplicate(&var->value, &obj->classLibrary);
		return(var);
	}
	// If we get here, failure
	return(NULL);
}

bool iObj_setProperty_comment(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_isTypeCharacter(var))
	{
		// Set the value
		iDatum_duplicate(&obj->comment, &var->value);

		// Indicate success
		return(true);
	}
	// If we get here, failure
	return(false);
}

SVariable* iObj_getProperty_comment(SObject* obj)
{
	SVariable* var;


	// Make sure the environment is sane
	if (obj)
	{
		// Create a new variable
		var = iVariable_create(_VAR_TYPE_CHARACTER, NULL);
		iDatum_duplicate(&var->value, &obj->comment);
		return(var);
	}
	// If we get here, failure
	return(NULL);
}

bool iObj_setProperty_toolTip(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_isTypeCharacter(var))
	{
		// Set the value
		iDatum_duplicate(&obj->tooltip, &var->value);

		// Indicate success
		return(true);
	}
	// If we get here, failure
	return(false);
}

SVariable* iObj_getProperty_toolTip(SObject* obj)
{
	SVariable* var;


	// Make sure the environment is sane
	if (obj)
	{
		// Create a new variable
		var = iVariable_create(_VAR_TYPE_CHARACTER, NULL);
		iDatum_duplicate(&var->value, &obj->tooltip);
		return(var);
	}
	// If we get here, failure
	return(NULL);
}

bool iObj_setProperty_tag(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_isTypeCharacter(var))
	{
		// Set the value
		iDatum_duplicate(&obj->tag, &var->value);

		// Indicate success
		return(true);
	}
	// If we get here, failure
	return(false);
}

SVariable* iObj_getProperty_tag(SObject* obj)
{
	SVariable* var;


	// Make sure the environment is sane
	if (obj)
	{
		// Create a new variable
		var = iVariable_create(_VAR_TYPE_CHARACTER, NULL);
		iDatum_duplicate(&var->value, &obj->tag);
		return(var);
	}
	// If we get here, failure
	return(NULL);
}

bool iObj_setProperty_mousePointer(SObject* obj, SVariable* var)
{
	s32		value;
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
		if ((value < 0 || value > 17) && value != 99)
		{
			iError_reportByNumber(_ERROR_OUT_OF_RANGE, NULL);
			return(false);
		}

		// Set the value
		obj->mousePointer = value;

		// Indicate success
		return(true);
	}
	// If we get here, failure
	return(false);
}

SVariable* iObj_getProperty_mousePointer(SObject* obj)
{
	SVariable* var;


	// Make sure the environment is sane
	if (obj)
	{
		// Create a new variable
		var = iVariable_create(_VAR_TYPE_INTEGER, NULL);
		*(s32*)var->value.data = obj->mousePointer;
		return(var);
	}
	// If we get here, failure
	return(NULL);
}

bool iObj_setProperty_isEnabled(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_isTypeLogical(var))
	{
		// Set the value
		obj->isEnabled = ((var->value.data[0] == _LOGICAL_FALSE) ? false : true);

		// Indicate success
		return(true);
	}
	// If we get here, failure
	return(false);
}

SVariable* iObj_getProperty_isEnabled(SObject* obj)
{
	SVariable* var;


	// Make sure the environment is sane
	if (obj)
	{
		// Create a new variable
		var = iVariable_create(_VAR_TYPE_LOGICAL, NULL);
		*(u8*)var->value.data = ((obj->isEnabled) ? _LOGICAL_TRUE : _LOGICAL_FALSE);
		return(var);
	}
	// If we get here, failure
	return(NULL);
}

bool iObj_setProperty_hasFocus(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_isTypeLogical(var))
	{
		// Set the value
		obj->hasFocus = ((var->value.data[0] == _LOGICAL_FALSE) ? false : true);

		// Indicate success
		return(true);
	}
	// If we get here, failure
	return(false);
}

SVariable* iObj_getProperty_hasFocus(SObject* obj)
{
	SVariable* var;


	// Make sure the environment is sane
	if (obj)
	{
		// Create a new variable
		var = iVariable_create(_VAR_TYPE_LOGICAL, NULL);
		*(u8*)var->value.data = ((obj->hasFocus) ? _LOGICAL_TRUE : _LOGICAL_FALSE);
		return(var);
	}
	// If we get here, failure
	return(NULL);
}

bool iObj_setProperty_isMovable(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_isTypeLogical(var))
	{
		// Set the value
		obj->isMovable = ((var->value.data[0] == _LOGICAL_FALSE) ? false : true);

		// Indicate success
		return(true);
	}
	// If we get here, failure
	return(false);
}

SVariable* iObj_getProperty_isMovable(SObject* obj)
{
	SVariable* var;


	// Make sure the environment is sane
	if (obj)
	{
		// Create a new variable
		var = iVariable_create(_VAR_TYPE_LOGICAL, NULL);
		*(u8*)var->value.data = ((obj->isMovable) ? _LOGICAL_TRUE : _LOGICAL_FALSE);
		return(var);
	}
	// If we get here, failure
	return(NULL);
}

bool iObj_setProperty_isRendered(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_isTypeLogical(var))
	{
		// Set the value
		obj->isRendered = ((var->value.data[0] == _LOGICAL_FALSE) ? false : true);

		// Indicate success
		return(true);
	}
	// If we get here, failure
	return(false);
}

SVariable* iObj_getProperty_isRendered(SObject* obj)
{
	SVariable* var;


	// Make sure the environment is sane
	if (obj)
	{
		// Create a new variable
		var = iVariable_create(_VAR_TYPE_LOGICAL, NULL);
		*(u8*)var->value.data = ((obj->isRendered) ? _LOGICAL_TRUE : _LOGICAL_FALSE);
		return(var);
	}
	// If we get here, failure
	return(NULL);
}

bool iObj_setProperty_isPublished(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_isTypeLogical(var))
	{
		// Set the value
		obj->isPublished = ((var->value.data[0] == _LOGICAL_FALSE) ? false : true);

		// Indicate success
		return(true);
	}
	// If we get here, failure
	return(false);
}

SVariable* iObj_getProperty_isPublished(SObject* obj)
{
	SVariable* var;


	// Make sure the environment is sane
	if (obj)
	{
		// Create a new variable
		var = iVariable_create(_VAR_TYPE_LOGICAL, NULL);
		*(u8*)var->value.data = ((obj->isPublished) ? _LOGICAL_TRUE : _LOGICAL_FALSE);
		return(var);
	}
	// If we get here, failure
	return(NULL);
}

bool iObj_setProperty_isVisible(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_isTypeLogical(var))
	{
		// Set the value
		obj->isVisible = ((var->value.data[0] == _LOGICAL_FALSE) ? false : true);

		// Indicate success
		return(true);
	}
	// If we get here, failure
	return(false);
}

SVariable* iObj_getProperty_isVisible(SObject* obj)
{
	SVariable* var;


	// Make sure the environment is sane
	if (obj)
	{
		// Create a new variable
		var = iVariable_create(_VAR_TYPE_LOGICAL, NULL);
		*(u8*)var->value.data = ((obj->isVisible) ? _LOGICAL_TRUE : _LOGICAL_FALSE);
		return(var);
	}
	// If we get here, failure
	return(NULL);
}

bool iObj_setProperty_isDirty(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_isTypeLogical(var))
	{
		// Set the value
		obj->isDirty = ((var->value.data[0] == _LOGICAL_FALSE) ? false : true);

		// Indicate success
		return(true);
	}
	// If we get here, failure
	return(false);
}

SVariable* iObj_getProperty_isDirty(SObject* obj)
{
	SVariable* var;


	// Make sure the environment is sane
	if (obj)
	{
		// Create a new variable
		var = iVariable_create(_VAR_TYPE_LOGICAL, NULL);
		*(u8*)var->value.data = ((obj->isDirty) ? _LOGICAL_TRUE : _LOGICAL_FALSE);
		return(var);
	}
	// If we get here, failure
	return(NULL);
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
		obj->anchor = value;

		// Indicate success
		return(true);
	}
	// If we get here, failure
	return(false);
}

SVariable* iObj_getProperty_anchor(SObject* obj)
{
	SVariable* var;


	// Make sure the environment is sane
	if (obj)
	{
		// Create a new variable
		var = iVariable_create(_VAR_TYPE_INTEGER, NULL);
		*(s32*)var->value.data = obj->anchor;
		return(var);
	}
	// If we get here, failure
	return(NULL);
}

bool iObj_setProperty_scrollX(SObject* obj, SVariable* var)
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
		obj->scrollOffsetX = value;

		// Indicate success
		return(true);
	}
	// If we get here, failure
	return(false);
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
		obj->scrollOffsetY = value;

		// Indicate success
		return(true);
	}
	// If we get here, failure
	return(false);
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

bool iSubobj_form_setMinLeft(SObject* obj, SVariable* var)
{
	return(false);
}

SVariable* iSubobj_form_getMinLeft(SObject* obj)
{
	return(NULL);
}

bool iSubobj_form_setMinTop(SObject* obj, SVariable* var)
{
	return(false);
}

SVariable* iSubobj_form_getMinTop(SObject* obj)
{
	return(NULL);
}

bool iSubobj_form_setMinWidth(SObject* obj, SVariable* var)
{
	return(false);
}

SVariable* iSubobj_form_getMinWidth(SObject* obj)
{
	return(NULL);
}

bool iSubobj_form_setMinHeight(SObject* obj, SVariable* var)
{
	return(false);
}

SVariable* iSubobj_form_getMinHeight(SObject* obj)
{
	return(NULL);
}

bool iSubobj_form_setMaxLeft(SObject* obj, SVariable* var)
{
	return(false);
}

SVariable* iSubobj_form_getMaxLeft(SObject* obj)
{
	return(NULL);
}

bool iSubobj_form_setMaxTop(SObject* obj, SVariable* var)
{
	return(false);
}

SVariable* iSubobj_form_getMaxTop(SObject* obj)
{
	return(NULL);
}

bool iSubobj_form_setMaxWidth(SObject* obj, SVariable* var)
{
	return(false);
}

SVariable* iSubobj_form_getMaxWidth(SObject* obj)
{
	return(NULL);
}

bool iSubobj_form_setMaxHeight(SObject* obj, SVariable* var)
{
	return(false);
}

SVariable* iSubobj_form_getMaxHeight(SObject* obj)
{
	return(NULL);
}

bool iSubobj_form_setFontName(SObject* obj, SVariable* var)
{
	return(false);
}

SVariable* iSubobj_form_getFontName(SObject* obj)
{
	return(NULL);
}

bool iSubobj_form_setFontBold(SObject* obj, SVariable* var)
{
	return(false);
}

SVariable* iSubobj_form_getFontBold(SObject* obj)
{
	return(NULL);
}

bool iSubobj_form_setFontItalic(SObject* obj, SVariable* var)
{
	return(false);
}

SVariable* iSubobj_form_getFontItalic(SObject* obj)
{
	return(NULL);
}

bool iSubobj_form_setFontUnderline(SObject* obj, SVariable* var)
{
	return(false);
}

SVariable* iSubobj_form_getFontUnderline(SObject* obj)
{
	return(NULL);
}

bool iSubobj_form_setFontStrikethrough(SObject* obj, SVariable* var)
{
	return(false);
}

SVariable* iSubobj_form_getFontStrikethrough(SObject* obj)
{
	return(NULL);
}

bool iSubobj_form_setFontCondensed(SObject* obj, SVariable* var)
{
	return(false);
}

SVariable* iSubobj_form_getFontCondensed(SObject* obj)
{
	return(NULL);
}

bool iSubobj_form_setFontExtended(SObject* obj, SVariable* var)
{
	return(false);
}

SVariable* iSubobj_form_getFontExtended(SObject* obj)
{
	return(NULL);
}

bool iSubobj_form_setFontOutline(SObject* obj, SVariable* var)
{
	return(false);
}

SVariable* iSubobj_form_getFontOutline(SObject* obj)
{
	return(NULL);
}

bool iSubobj_form_setFontShadow(SObject* obj, SVariable* var)
{
	return(false);
}

SVariable* iSubobj_form_getFontShadow(SObject* obj)
{
	return(NULL);
}

bool iSubobj_form_setNwColor(SObject* obj, SVariable* var)
{
	return(false);
}

SVariable* iSubobj_form_getNwColor(SObject* obj)
{
	return(NULL);
}

bool iSubobj_form_setNeColor(SObject* obj, SVariable* var)
{
	return(false);
}

SVariable* iSubobj_form_getNeColor(SObject* obj)
{
	return(NULL);
}

bool iSubobj_form_setSwColor(SObject* obj, SVariable* var)
{
	return(false);
}

SVariable* iSubobj_form_getSwColor(SObject* obj)
{
	return(NULL);
}

bool iSubobj_form_setSeColor(SObject* obj, SVariable* var)
{
	return(false);
}

SVariable* iSubobj_form_getSeColor(SObject* obj)
{
	return(NULL);
}

bool iSubobj_form_setBackColor(SObject* obj, SVariable* var)
{
	return(false);
}

SVariable* iSubobj_form_getBackColor(SObject* obj)
{
	return(NULL);
}

bool iSubobj_form_setForeColor(SObject* obj, SVariable* var)
{
	return(false);
}

SVariable* iSubobj_form_getForeColor(SObject* obj)
{
	return(NULL);
}

bool iSubobj_form_setCaptionColor(SObject* obj, SVariable* var)
{
	return(false);
}

SVariable* iSubobj_form_getCaptionColor(SObject* obj)
{
	return(NULL);
}

bool iSubobj_form_setCaption(SObject* obj, SVariable* var)
{
	return(false);
}

SVariable* iSubobj_form_getCaption(SObject* obj)
{
	return(NULL);
}

bool iSubobj_form_setPicture(SObject* obj, SVariable* var)
{
	return(false);
}

SVariable* iSubobj_form_getPicture(SObject* obj)
{
	return(NULL);
}

bool iSubobj_form_setAllowOutput(SObject* obj, SVariable* var)
{
	return(false);
}

SVariable* iSubobj_form_getAllowOutput(SObject* obj)
{
	return(NULL);
}

bool iSubobj_form_setAlwaysOnBottom(SObject* obj, SVariable* var)
{
	return(false);
}

SVariable* iSubobj_form_getAlwaysOnBottom(SObject* obj)
{
	return(NULL);
}

bool iSubobj_form_setAlwaysOnTop(SObject* obj, SVariable* var)
{
	return(false);
}

SVariable* iSubobj_form_getAlwaysOnTop(SObject* obj)
{
	return(NULL);
}

bool iSubobj_form_setAutoCenter(SObject* obj, SVariable* var)
{
	return(false);
}

SVariable* iSubobj_form_getAutoCenter(SObject* obj)
{
	return(NULL);
}

bool iSubobj_form_setBorderStyle(SObject* obj, SVariable* var)
{
	return(false);
}

SVariable* iSubobj_form_getBorderStyle(SObject* obj)
{
	return(NULL);
}

bool iSubobj_form_setIsCloseable(SObject* obj, SVariable* var)
{
	return(false);
}

SVariable* iSubobj_form_getIsCloseable(SObject* obj)
{
	return(NULL);
}

bool iSubobj_form_setProcessKeyPreviewEvents(SObject* obj, SVariable* var)
{
	return(false);
}

SVariable* iSubobj_form_getProcessKeyPreviewEvents(SObject* obj)
{
	return(NULL);
}

bool iSubobj_form_setHasControlBox(SObject* obj, SVariable* var)
{
	return(false);
}

SVariable* iSubobj_form_getHasControlBox(SObject* obj)
{
	return(NULL);
}

bool iSubobj_form_setHasMinButton(SObject* obj, SVariable* var)
{
	return(false);
}

SVariable* iSubobj_form_getHasMinButton(SObject* obj)
{
	return(NULL);
}

bool iSubobj_form_setHasCloseButton(SObject* obj, SVariable* var)
{
	return(false);
}

SVariable* iSubobj_form_getHasCloseButton(SObject* obj)
{
	return(NULL);
}

bool iSubobj_form_setScaleMode(SObject* obj, SVariable* var)
{
	return(false);
}

SVariable* iSubobj_form_getScaleMode(SObject* obj)
{
	return(NULL);
}

bool iSubobj_form_setShowInTaskBar(SObject* obj, SVariable* var)
{
	return(false);
}

SVariable* iSubobj_form_getShowInTaskBar(SObject* obj)
{
	return(NULL);
}

bool iSubobj_form_setWindowState(SObject* obj, SVariable* var)
{
	return(false);
}

SVariable* iSubobj_form_getWindowState(SObject* obj)
{
	return(NULL);
}

bool iSubobj_form_setBindControls(SObject* obj, SVariable* var)
{
	return(false);
}

SVariable* iSubobj_form_getBindControls(SObject* obj)
{
	return(NULL);
}

bool iSubobj_form_setBufferMode(SObject* obj, SVariable* var)
{
	return(false);
}

SVariable* iSubobj_form_getBufferMode(SObject* obj)
{
	return(NULL);
}

bool iSubobj_form_setClipControls(SObject* obj, SVariable* var)
{
	return(false);
}

SVariable* iSubobj_form_getClipControls(SObject* obj)
{
	return(NULL);
}

bool iSubobj_form_setColorSource(SObject* obj, SVariable* var)
{
	return(false);
}

SVariable* iSubobj_form_getColorSource(SObject* obj)
{
	return(NULL);
}

bool iSubobj_form_setContinuousScroll(SObject* obj, SVariable* var)
{
	return(false);
}

SVariable* iSubobj_form_getContinuousScroll(SObject* obj)
{
	return(NULL);
}

bool iSubobj_form_setDataSession(SObject* obj, SVariable* var)
{
	return(false);
}

SVariable* iSubobj_form_getDataSession(SObject* obj)
{
	return(NULL);
}

bool iSubobj_form_setDataSessionId(SObject* obj, SVariable* var)
{
	return(false);
}

SVariable* iSubobj_form_getDataSessionId(SObject* obj)
{
	return(NULL);
}

bool iSubobj_form_setDeClass(SObject* obj, SVariable* var)
{
	return(false);
}

SVariable* iSubobj_form_getDeClass(SObject* obj)
{
	return(NULL);
}

bool iSubobj_form_setDeClassLibrary(SObject* obj, SVariable* var)
{
	return(false);
}

SVariable* iSubobj_form_getDeClassLibrary(SObject* obj)
{
	return(NULL);
}

bool iSubobj_form_setDefOleCid(SObject* obj, SVariable* var)
{
	return(false);
}

SVariable* iSubobj_form_getDefOleCid(SObject* obj)
{
	return(NULL);
}

bool iSubobj_form_setDesktop(SObject* obj, SVariable* var)
{
	return(false);
}

SVariable* iSubobj_form_getDesktop(SObject* obj)
{
	return(NULL);
}

bool iSubobj_form_setIsDockable(SObject* obj, SVariable* var)
{
	return(false);
}

SVariable* iSubobj_form_getIsDockable(SObject* obj)
{
	return(NULL);
}

bool iSubobj_form_setIsDocked(SObject* obj, SVariable* var)
{
	return(false);
}

SVariable* iSubobj_form_getIsDocked(SObject* obj)
{
	return(NULL);
}

bool iSubobj_form_setDockPosition(SObject* obj, SVariable* var)
{
	return(false);
}

SVariable* iSubobj_form_getDockPosition(SObject* obj)
{
	return(NULL);
}

bool iSubobj_form_setDrawMode(SObject* obj, SVariable* var)
{
	return(false);
}

SVariable* iSubobj_form_getDrawMode(SObject* obj)
{
	return(NULL);
}

bool iSubobj_form_setDrawStyle(SObject* obj, SVariable* var)
{
	return(false);
}

SVariable* iSubobj_form_getDrawStyle(SObject* obj)
{
	return(NULL);
}

bool iSubobj_form_setDrawWidth(SObject* obj, SVariable* var)
{
	return(false);
}

SVariable* iSubobj_form_getDrawWidth(SObject* obj)
{
	return(NULL);
}

bool iSubobj_form_setFillColor(SObject* obj, SVariable* var)
{
	return(false);
}

SVariable* iSubobj_form_getFillColor(SObject* obj)
{
	return(NULL);
}

bool iSubobj_form_setFillStyle(SObject* obj, SVariable* var)
{
	return(false);
}

SVariable* iSubobj_form_getFillStyle(SObject* obj)
{
	return(NULL);
}

bool iSubobj_form_setHalfHeightCaption(SObject* obj, SVariable* var)
{
	return(false);
}

SVariable* iSubobj_form_getHalfHeightCaption(SObject* obj)
{
	return(NULL);
}

bool iSubobj_form_setHScrollSmallChange(SObject* obj, SVariable* var)
{
	return(false);
}

SVariable* iSubobj_form_getHScrollSmallChange(SObject* obj)
{
	return(NULL);
}

bool iSubobj_form_setVScrollSmallChange(SObject* obj, SVariable* var)
{
	return(false);
}

SVariable* iSubobj_form_getVScrollSmallChange(SObject* obj)
{
	return(NULL);
}

bool iSubobj_form_setMacDesktop(SObject* obj, SVariable* var)
{
	return(false);
}

SVariable* iSubobj_form_getMacDesktop(SObject* obj)
{
	return(NULL);
}

bool iSubobj_form_setMdiForm(SObject* obj, SVariable* var)
{
	return(false);
}

SVariable* iSubobj_form_getMdiForm(SObject* obj)
{
	return(NULL);
}

bool iSubobj_form_setOleDragMode(SObject* obj, SVariable* var)
{
	return(false);
}

SVariable* iSubobj_form_getOleDragMode(SObject* obj)
{
	return(NULL);
}

bool iSubobj_form_setOleDragPicture(SObject* obj, SVariable* var)
{
	return(false);
}

SVariable* iSubobj_form_getOleDragPicture(SObject* obj)
{
	return(NULL);
}

bool iSubobj_form_setOleDropEffects(SObject* obj, SVariable* var)
{
	return(false);
}

SVariable* iSubobj_form_getOleDropEffects(SObject* obj)
{
	return(NULL);
}

bool iSubobj_form_setOleDropHasData(SObject* obj, SVariable* var)
{
	return(false);
}

SVariable* iSubobj_form_getOleDropHasData(SObject* obj)
{
	return(NULL);
}

bool iSubobj_form_setOleDropMode(SObject* obj, SVariable* var)
{
	return(false);
}

SVariable* iSubobj_form_getOleDropMode(SObject* obj)
{
	return(NULL);
}

bool iSubobj_form_setReleaseType(SObject* obj, SVariable* var)
{
	return(false);
}

SVariable* iSubobj_form_getReleaseType(SObject* obj)
{
	return(NULL);
}

bool iSubobj_form_setRightToLeft(SObject* obj, SVariable* var)
{
	return(false);
}

SVariable* iSubobj_form_getRightToLeft(SObject* obj)
{
	return(NULL);
}

bool iSubobj_form_setScrollbars(SObject* obj, SVariable* var)
{
	return(false);
}

SVariable* iSubobj_form_getScrollbars(SObject* obj)
{
	return(NULL);
}

bool iSubobj_form_setShowTips(SObject* obj, SVariable* var)
{
	return(false);
}

SVariable* iSubobj_form_getShowTips(SObject* obj)
{
	return(NULL);
}

bool iSubobj_form_setShowWindow(SObject* obj, SVariable* var)
{
	return(false);
}

SVariable* iSubobj_form_getShowWindow(SObject* obj)
{
	return(NULL);
}

bool iSubobj_form_setSizeBox(SObject* obj, SVariable* var)
{
	return(false);
}

SVariable* iSubobj_form_getSizeBox(SObject* obj)
{
	return(NULL);
}

bool iSubobj_form_setThemes(SObject* obj, SVariable* var)
{
	return(false);
}

SVariable* iSubobj_form_getThemes(SObject* obj)
{
	return(NULL);
}

bool iSubobj_form_setTitleBar(SObject* obj, SVariable* var)
{
	return(false);
}

SVariable* iSubobj_form_getTitleBar(SObject* obj)
{
	return(NULL);
}

bool iSubobj_form_setWindowType(SObject* obj, SVariable* var)
{
	return(false);
}

SVariable* iSubobj_form_getWindowType(SObject* obj)
{
	return(NULL);
}

bool iSubobj_form_setZoomBox(SObject* obj, SVariable* var)
{
	return(false);
}

SVariable* iSubobj_form_getZoomBox(SObject* obj)
{
	return(NULL);
}

