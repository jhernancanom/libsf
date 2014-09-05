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









// bool iObj_setLogical(SObject* obj, SVariable* var, bool* tlDest)
// {
// 	// Make sure the environment is sane
// 	if (obj && var && iVariable_isTypeLogical(var))
// 	{
// 		// Set the value
// 		*tlDest = ((var->value.data[0] == _LOGICAL_FALSE) ? false : true);
// 
// 		// Indicate success
// 		return(true);
// 	}
// 	// If we get here, failure
// 	return(false);
// }
// 
// 
// 
// 
// 
// //////////
// // OBJECT Properties
// //////
// SVariable* iObj_getProperty_scrollX(SObject* obj)
// {
// 	SVariable* var;
// 
// 
// 	// Make sure the environment is sane
// 	if (obj)
// 	{
// 		// Create a new variable
// 		var = iVariable_create(_VAR_TYPE_INTEGER, NULL);
// 		*(s32*)var->value.data = obj->scrollOffsetX;
// 		return(var);
// 	}
// 	// If we get here, failure
// 	return(NULL);
// }
// 
// bool iObj_setProperty_scrollY(SObject* obj, SVariable* var)
// {
// 	return(iObj_setInteger(obj, var, &obj->scrollOffsetY, 0, 0, false, 0));
// }
// 
// SVariable* iObj_getProperty_scrollY(SObject* obj)
// {
// 	SVariable* var;
// 
// 
// 	// Make sure the environment is sane
// 	if (obj)
// 	{
// 		// Create a new variable
// 		var = iVariable_create(_VAR_TYPE_INTEGER, NULL);
// 		*(s32*)var->value.data = obj->scrollOffsetY;
// 		return(var);
// 	}
// 	// If we get here, failure
// 	return(NULL);
// }
// 
// bool iObj_setProperty_scaleX(SObject* obj, SVariable* var)
// {
// 	s32		lnNewWidth;
// 	f32		value;
// 	bool	error;
// 	u32		errorNum;
// 
// 
// 	// Make sure the environment is sane
// 	if (obj && var && iVariable_isTypeNumeric(var))
// 	{
// 		// Try to get the value
// 		value = iiVariable_getAs_f32(var, false, &error, &errorNum);
// 		if (error)
// 		{
// 			iError_reportByNumber(errorNum, var->compRelated);
// 			return(false);
// 		}
// 		if (value <= 0.0f)
// 		{
// 			iError_reportByNumber(_ERROR_OUT_OF_RANGE, var->compRelated);
// 			return(false);
// 		}
// 
// 		// Set the value
// 		// Note:  This is done by resizing the underlying bitmap.
// 		lnNewWidth = (s32)((f32)(obj->rc.right - obj->rc.left) / value);
// 		obj->bmp = iBmp_verifySizeOrResize(obj->bmp, lnNewWidth, obj->bmp->bi.biHeight, obj->bmp->bi.biBitCount);
// 
// 		// Indicate success
// 		return(true);
// 	}
// 	// If we get here, failure
// 	return(false);
// }
// 
// SVariable* iObj_getProperty_scaleX(SObject* obj)
// {
// 	SVariable* var;
// 
// 
// 	// Make sure the environment is sane
// 	if (obj)
// 	{
// 		// Create a new variable
// 		var = iVariable_create(_VAR_TYPE_F32, NULL);
// 		if (!obj->isScaled || !obj->bmpScaled)
// 		{
// 			// Invalid
// 			*(f32*)var->value.data = -1.0f;
// 
// 		} else {
// 			// Compute the scale ratio
// 			*(f32*)var->value.data = ((f32)(obj->rc.right - obj->rc.left) / (f32)obj->bmp->bi.biWidth);
// 		}
// 		return(var);
// 	}
// 	// If we get here, failure
// 	return(NULL);
// }
// 
// bool iObj_setProperty_scaleY(SObject* obj, SVariable* var)
// {
// 	s32		lnNewHeight;
// 	f32		value;
// 	bool	error;
// 	u32		errorNum;
// 
// 
// 	// Make sure the environment is sane
// 	if (obj && var && iVariable_isTypeNumeric(var))
// 	{
// 		// Try to get the value
// 		value = iiVariable_getAs_f32(var, false, &error, &errorNum);
// 		if (error)
// 		{
// 			iError_reportByNumber(errorNum, var->compRelated);
// 			return(false);
// 		}
// 		if (value <= 0.0f)
// 		{
// 			iError_reportByNumber(_ERROR_OUT_OF_RANGE, var->compRelated);
// 			return(false);
// 		}
// 
// 		// Set the value
// 		// Note:  This is done by resizing the underlying bitmap.
// 		lnNewHeight = (s32)((f32)(obj->rc.bottom - obj->rc.top) / value);
// 		obj->bmp = iBmp_verifySizeOrResize(obj->bmp, obj->bmp->bi.biWidth, lnNewHeight, obj->bmp->bi.biBitCount);
// 
// 		// Indicate success
// 		return(true);
// 	}
// 	// If we get here, failure
// 	return(false);
// }
// 
// SVariable* iObj_getProperty_scaleY(SObject* obj)
// {
// 	SVariable* var;
// 
// 
// 	// Make sure the environment is sane
// 	if (obj)
// 	{
// 		// Create a new variable
// 		var = iVariable_create(_VAR_TYPE_F32, NULL);
// 		if (!obj->isScaled || !obj->bmpScaled)
// 		{
// 			// Invalid
// 			*(f32*)var->value.data = -1.0f;
// 
// 		} else {
// 			// Compute the scale ratio
// 			*(f32*)var->value.data = ((f32)(obj->rc.bottom - obj->rc.top) / (f32)obj->bmp->bi.biHeight);
// 		}
// 		return(var);
// 	}
// 	// If we get here, failure
// 	return(NULL);
// }
// 
// void iObj_setIcon(SObject* obj, SBitmap* bmp)
// {
// 	SObject*	objChild;
// 	RECT		lrc;
// 
// 
// 	// Make sure the environment is sane
// 	if (obj && iBmp_validate(bmp))
// 	{
// 		// If it's a form, we also update the child icon
// 		switch (obj->objType)
// 		{
// 			case _OBJ_TYPE_FORM:
// 			case _OBJ_TYPE_SUBFORM:
// 				//////////
// 				// Create the icon at 24x24
// 				//////
// 					iBmp_delete(&obj->p.icon, true, true);		// Delete the old
// 					obj->p.icon = iBmp_allocate();
// 					iBmp_createBySize(obj->p.icon, bmpArrowUl->bi.biWidth, bmpArrowUl->bi.biHeight, 24);
// 					iBmp_scale(obj->p.icon, bmp);				// Scale the indicated icon into our 24x24 size
// 
// 
// 				//////////
// 				// Forms have child-objects which hold their icons (so they can respond to user events, etc.)
// 				//////
// 					objChild = obj->firstChild;
// 					while (objChild)
// 					{
// 						if (objChild->objType == _OBJ_TYPE_IMAGE && iDatum_compare(&objChild->pa.name, cgcName_icon, sizeof(cgcName_icon) - 1) == 0)
// 						{
// 							// Adjust the size
// 							iObj_setSize(objChild, objChild->rc.left, objChild->rc.top, bmpArrowUl->bi.biWidth, bmpArrowUl->bi.biHeight);
// 
// 							// This is the one to update
// 							iBmp_delete(&objChild->p.bmpPicture,		true, true);	// Delete the old
// 							iBmp_delete(&objChild->p.bmpPictureOver,	true, true);	// Delete the old
// 							iBmp_delete(&objChild->p.bmpPictureDown,	true, true);	// Delete the old
// 							objChild->p.bmpPicture		= iBmp_copy(obj->p.icon);	// Set the new
// 							objChild->p.bmpPictureOver	= iBmp_copy(obj->p.icon);	// Set the new
// 							objChild->p.bmpPictureDown	= iBmp_copy(obj->p.icon);	// Set the new
// 
// 							// Add highlighting for the over and down
// 							SetRect(&lrc, 0, 0, 24, 24);
// 							iBmp_colorize(objChild->p.bmpPictureOver, &lrc, colorMouseOver,	false, 0.25f);
// 							iBmp_colorize(objChild->p.bmpPictureDown, &lrc, colorMouseDown,	false, 0.25f);
// 
// 							// All done
// 							break;
// 						}
// 
// 						// Move to next object
// 						objChild = (SObject*)objChild->ll.next;
// 					}
// 					break;
// 		}
// 	}
// }
// 
// bool iObj_set_caption(SObject* obj, SVariable* var)
// {
// 	bool		llResult;
// 	SObject*	objChild;
// 
// 
// 	llResult = false;
// 	if (obj)
// 	{
// 		// Set the main caption
// 		obj->isDirtyRender = true;
// 		if ((llResult = iObj_setCharacter(obj, var, &obj->p.caption, var->value.data, var->value.length)))
// 		{
// 			switch (obj->objType)
// 			{
// 				case _OBJ_TYPE_FORM:
// 				case _OBJ_TYPE_SUBFORM:
// 					objChild = obj->firstChild;
// 					while (objChild)
// 					{
// 						// Is this one
// 						if (objChild->objType == _OBJ_TYPE_LABEL && iDatum_compare(&objChild->pa.name, cgcCaption_icon, sizeof(cgcCaption_icon) - 1) == 0)
// 						{
// 							// Update this item
// 							llResult				= iObj_setCharacter(objChild, var, &objChild->p.caption, var->value.data, var->value.length);
// 							objChild->isDirtyRender	= true;
// 
// 							// All done
// 							break;
// 						}
// 
// 						// Move to next sibling
// 						objChild = (SObject*)objChild->ll.next;
// 					}
// 					break;
// 
// 				case _OBJ_TYPE_CHECKBOX:
// 					objChild = obj->firstChild;
// 					while (objChild)
// 					{
// 						// Is this one
// 						if (objChild->objType == _OBJ_TYPE_LABEL && iDatum_compare(&objChild->pa.name, cgcName_checkboxLabel, sizeof(cgcName_checkboxLabel) - 1) == 0)
// 						{
// 							// Update this item
// 							llResult				= iObj_setCharacter(objChild, var, &objChild->p.caption, var->value.data, var->value.length);
// 							objChild->isDirtyRender	= true;
// 
// 							// All done
// 							break;
// 						}
// 
// 						// Move to next sibling
// 						objChild = (SObject*)objChild->ll.next;
// 					}
// 					break;
// 			}
// 		}
// 	}
// 
// 	// Indicate our status
// 	return(llResult);
// }




//////////
//
// Called to set the bitmap to the indicated bitmap
//
//////
	bool iObjProp_set_bitmap(SObject* obj, u32 tnIndex, SBitmap* bmp)
	{
		SVariable* var;


		// Make sure the environment is sane
		if (obj)
		{
			// Grab the variable associated with this object's property
			var = iObjProp_get_variable_byIndex(obj, tnIndex);
			if (var)
				return(iVariable_set_bitmap(var, bmp));
		}
		// If we get here, failure
		return(false);
	}




//////////
//
// Called to set the character variable to the indicated input
//
//////
	bool iObjProp_set_character(SObject* obj, u32 tnIndex, SVariable* var)
	{
		return(false);
	}




//////////
// 
// Called to set the character variable to the indicated input
//
//////
	bool iObjProp_set_character_direct (SObject* obj, u32 tnIndex, cs8* tcText, u32 tnTextLength)
	{
		return(iObjProp_set_character_direct(obj, tnIndex, (s8*)tcText, tnTextLength));
	}

	bool iObjProp_set_character_direct(SObject* obj, u32 tnIndex, s8* tcText, u32 tnTextLength)
	{
		SVariable* var;


		// Make sure the environment is sane
		if (obj)
		{
			// Grab the variable associated with this object's property
			var = iObjProp_get_variable_byIndex(obj, tnIndex);
			if (var)
				return(iVariable_set_character(var, tcText, tnTextLength));
		}
		// If we get here, failure
		return(false);
	}

	bool iObjProp_set_character_direct(SObject* obj, u32 tnIndex, SDatum* datum)
	{
		SVariable* var;


		// Make sure the environment is sane
		if (obj)
		{
			// Grab the variable associated with this object's property
			var = iObjProp_get_variable_byIndex(obj, tnIndex);
			if (var)
				return(iVariable_set_character(var, datum));
		}
		// If we get here, failure
		return(false);
	}




//////////
//
// Called to set the f64 variable to the indicated input
//
//////
	bool iObjProp_set_f64(SObject* obj, u32 tnIndex, SVariable* var)
	{
		return(false);
	}




//////////
//
// Called to set the logical variable to the indicated input
//
//////
	bool iObjProp_set_logical(SObject* obj, u32 tnIndex, SVariable* var)
	{
		return(false);
	}




//////////
//
// Called to set the s32 variable directly by value
//
//////
	bool iObjProp_set_logical_direct(SObject* obj, u32 tnIndex, s32 tnValue)
	{
		SVariable* var;


		// Make sure the environment is sane
		if (obj)
		{
			switch (tnValue)
			{
				case _LOGICAL_TRUE:
				case _LOGICAL_FALSE:
				case _LOGICALX_OTHER:
				case _LOGICALX_PARTIAL:
				case _LOGICALX_EXTRA:
				case _LOGICALX_YET_ANOTHER:
				case _LOGICALX_ZATS_ALL_FOLKS:
					// Grab the variable associated with this object's property
					var = iObjProp_get_variable_byIndex(obj, tnIndex);
					if (var)
						return(iVariable_set_logical(var, tnValue));
					break;
			}
		}
		// If we get here, failure
		return(false);
	}




//////////
//
// Called to set the object variable to the indicated input
//
//////
	bool iObjProp_set_object(SObject* obj, u32 tnIndex, SVariable* var)
	{
		return(false);
	}




//////////
//
// Called to set the s32 variable to the indicated input
//
//////
	bool iObjProp_set_s32(SObject* obj, u32 tnIndex, SVariable* var)
	{
		return(false);
	}




//////////
//
// Called to set the s32 variable directly by value
//
//////
	bool iObjProp_set_s32_direct(SObject* obj, u32 tnIndex, s32 tnValue)
	{
		SVariable* var;


		// Make sure the environment is sane
		if (obj)
		{
			// Grab the variable associated with this object's property
			var = iObjProp_get_variable_byIndex(obj, tnIndex);
			if (var)
				return(iVariable_set_s32(var, tnValue));
		}
		// If we get here, failure
		return(false);
	}




//////////
//
// Called to set the u32 variable directly by value
//
//////
	bool iObjProp_set_u32_direct(SObject* obj, u32 tnIndex, u32 tnValue)
	{
		SVariable* var;


		// Make sure the environment is sane
		if (obj)
		{
			// Grab the variable associated with this object's property
			var = iObjProp_get_variable_byIndex(obj, tnIndex);
			if (var)
				return(iVariable_set_u32(var, tnValue));
		}
		// If we get here, failure
		return(false);
	}




//////////
//
// Called to set the f32 value directly by value
//
//////
	bool iObjProp_set_f32_direct(SObject* obj, u32 tnIndex, f32 tfValue)
	{
		SVariable* var;


		// Make sure the environment is sane
		if (obj)
		{
			// Grab the variable associated with this object's property
			var = iObjProp_get_variable_byIndex(obj, tnIndex);
			if (var)
				return(iVariable_set_f32(var, tfValue));
		}
		// If we get here, failure
		return(false);
	}




//////////
//
// Called to set the f64 value directly by value
//
//////
	bool iObjProp_set_f64_direct(SObject* obj, u32 tnIndex, f64 tfValue)
	{
		SVariable* var;


		// Make sure the environment is sane
		if (obj)
		{
			// Grab the variable associated with this object's property
			var = iObjProp_get_variable_byIndex(obj, tnIndex);
			if (var)
				return(iVariable_set_f64(var, tfValue));
		}
		// If we get here, failure
		return(false);
	}




//////////
//
// Called to set the SBgra variable directly by value
//
//////
	bool iObjProp_set_sbgra_direct(SObject* obj, u32 tnIndex, SBgra color)
	{
		SVariable* var;


		// Make sure the environment is sane
		if (obj)
		{
			// Grab the variable associated with this object's property
			var = iObjProp_get_variable_byIndex(obj, tnIndex);
			if (var)
				return(iVariable_set_u32(var, color.color));
		}
		// If we get here, failure
		return(false);
	}




//////////
//
// Called to copy the indicated variable
//
//////
	bool iObjProp_copy_byIndex(SObject* objDst, u32 tnIndexDst, SObject* objSrc, u32 tnIndexSrc)
	{
		SVariable* varDst;
		SVariable* varSrc;


		// Make sure the environment is sane
		if (objDst && objSrc)
		{
			// Grab the variable associated with this object's property
			varDst = iObjProp_get_variable_byIndex(objDst, tnIndexDst);
			varSrc = iObjProp_get_variable_byIndex(objSrc, tnIndexDst);
			if (varDst && varSrc)
				return(iVariable_copy(varDst, varSrc));
		}
		// If we get here, failure
		return(false);
	}




//////////
//
// Get the associated variable based upon the object type and property index.
//
// Note:  For performance, the value returned here is a pointer to the direct
//        variable, not a copy.
//
//////
	SVariable* iObjProp_get_variable_byIndex(SObject* obj, u32 tnIndex)
	{
		s32					lnI, lnJ;
		SBaseclassList*		classes;
		SPropertyMap*		props;


		// Make sure the environment is sane
		if (obj)
		{
			// Locate the base class
			for (lnI = 0; lnI < gnKnownBaseclasses_size; lnI++)
			{
				// Is this it?
				if (gsKnownBaseclasses[lnI].objType == obj->objType)
				{
					// Locate the property within the object's properties
					props = gsKnownBaseclasses[lnI].objProps;
					for (lnJ = 0; lnJ < props[lnJ].index != 0; lnJ++)
					{
						// Is this it?
						if (props[lnJ].index == tnIndex)
							return(obj->props[lnJ]);	// Return the variable associated with this position
					}
					// If we get here, not found
					break;
				}
				// If we get here, still searching
			}
			// If we get here, not found
		}

		// Invalid
		return(NULL);
	}




//////////
//
// Get the associated variable based optionally upon (1) the object type and property index,
// or (2) an add-on user property
//
//////
	SVariable* iObjProp_get_variable_byName(SObject* obj, u32 tnIndex, s8* tcName, u32 tnNameLength, bool tlSearchBaseProps, bool tlSearchUserProps)
	{
_asm int 3;
// TODO:  guess :-)
		return(NULL);
	}




//////////
//
// Called to get the bitmap from the indicated object
//
//////
	SBitmap* iObjProp_get_bitmap(SObject* obj, u32 tnIndex)
	{
		return(NULL);
	}




//////////
//
// Called to get the character from the indicated object
//
//////
	SVariable* iObjProp_get_character(SObject* obj, u32 tnIndex)
	{
		return(NULL);
	}




//////////
//
// Called to get the f32 variable from the indicated object
//
//////
	SVariable* iObjProp_get_f32(SObject* obj, u32 tnIndex)
	{
		bool		error;
		s32			lnResult;
		u32			errorNum;
		SVariable* var;


		// Make sure the environment is sane
		if (obj)
			return(iObjProp_get_variable_byIndex(obj, tnIndex));	// Grab the variable associated with this object's property
		
		// If we get here, failure
		return(NULL);
	}




//////////
//
// Called to get the f32 from the indicaed object
//
//////
	f64 iObjProp_get_f32_direct(SObject* obj, u32 tnIndex)
	{
		bool		error;
		f32			lfResult;
		u32			errorNum;
		SVariable*	var;


		// Make sure the environment is sane
		lfResult = _f32_min;
		if (obj)
		{
			// Grab the variable associated with this object's property
			var = iObjProp_get_variable_byIndex(obj, tnIndex);
			if (var)
			{
				// Try to get the value
				return(iiVariable_getAs_f32(var, false, &error, &errorNum));

				// If we got it...
				if (!error)
					return(lfResult);	// ...return the value

				// Reset the value to the minimum value
				lfResult = _f32_min;
			}
		}
		// If we get here, failure
		return(lfResult);
	}




//////////
//
// Called to get the f64 variable from the indicated object
//
//////
	SVariable* iObjProp_get_f64(SObject* obj, u32 tnIndex)
	{
		bool		error;
		s32			lnResult;
		u32			errorNum;
		SVariable* var;


		// Make sure the environment is sane
		if (obj)
			return(iObjProp_get_variable_byIndex(obj, tnIndex));	// Grab the variable associated with this object's property
		
		// If we get here, failure
		return(NULL);
	}




//////////
//
// Called to get the f64 from the indicaed object
//
//////
	f64 iObjProp_get_f64_direct(SObject* obj, u32 tnIndex)
	{
		bool		error;
		f64			lfResult;
		u32			errorNum;
		SVariable*	var;


		// Make sure the environment is sane
		lfResult = _f64_min;
		if (obj)
		{
			// Grab the variable associated with this object's property
			var = iObjProp_get_variable_byIndex(obj, tnIndex);
			if (var)
			{
				// Try to get the value
				return(iiVariable_getAs_f64(var, false, &error, &errorNum));

				// If we got it...
				if (!error)
					return(lfResult);	// ...return the value

				// Reset the value to the minimum value
				lfResult = _f64_min;
			}
		}
		// If we get here, failure
		return(lfResult);
	}




//////////
//
// Called to get the logical from the indicated object
//
//////
	SVariable* iObjProp_get_logical(SObject* obj, u32 tnIndex)
	{
		return(NULL);
	}




//////////
//
// Called to obtain the property's direct value
//
//////
	s32 iObjProp_get_logical_direct(SObject* obj, u32 tnIndex)
	{
		bool		error;
		s32			lnResult;
		u32			errorNum;
		SVariable* var;


		// Make sure the environment is sane
		if (obj)
		{
			// Grab the variable associated with this object's property
			var = iObjProp_get_variable_byIndex(obj, tnIndex);
			if (var)
			{
				// Try to get the value
				lnResult = iiVariable_getAs_s32(var, false, &error, &errorNum);

				// If we got it...
				if (!error)
					return(lnResult);	// ...return the value
			}
		}
		// If we get here, failure
		return(_LOGICAL_FALSE);
	}




//////////
//
// Called to get the object from the indicated object
//
//////
	SVariable* iObjProp_get_object(SObject* obj, u32 tnIndex)
	{
		return(NULL);
	}




//////////
//
// Called to get the s32 from the indicated object
//
//////
	SVariable* iObjProp_get_s32(SObject* obj, u32 tnIndex)
	{
		return(NULL);
	}




//////////
//
// Called to get the s32 from the indicated object directly
//
//////
	s32 iObjProp_get_s32_direct(SObject* obj, u32 tnIndex)
	{
		bool		error;
		s32			lnResult;
		u32			errorNum;
		SVariable* var;


		// Make sure the environment is sane
		if (obj)
		{
			// Grab the variable associated with this object's property
			var = iObjProp_get_variable_byIndex(obj, tnIndex);
			if (var)
			{
				// Try to get the value
				lnResult = iiVariable_getAs_s32(var, false, &error, &errorNum);

				// If we got it...
				if (!error)
					return(lnResult);	// ...return the value
			}
		}
		// If we get here, failure
		return(-1);
	}




//////////
//
// Called to obtain the s32 value as an SBgra color
//
//////
	SBgra iObjProp_get_sbgra_direct (SObject* obj, u32 tnIndex)
	{
		union {
			s32		_color;
			SBgra	color;
		};
		bool		error;
		s32			lnResult;
		u32			errorNum;
		SVariable* var;


		// Make sure the environment is sane
		if (obj)
		{
			// Grab the variable associated with this object's property
			var = iObjProp_get_variable_byIndex(obj, tnIndex);
			if (var)
			{
				// Try to get the value
				_color = iiVariable_getAs_s32(var, false, &error, &errorNum);

				// If we got it...
				if (!error)
					return(color);		// ...return the value
			}
		}
		// If we get here, failure
		_color = -1;
		return(color);
	}




//////////
//
// Called to delete the variable associated with the index
//
//////
	bool iObjProp_delete_variable_byIndex(SObject* obj, u32 tnIndex)
	{
		SVariable* var;


		// Make sure the environment is sane
		if (obj)
		{
			// Grab the variable associated with this object's property
			var = iObjProp_get_variable_byIndex(obj, tnIndex);
			if (var && var->varType == _VAR_TYPE_BITMAP)
			{
				iVariable_delete(var, false);
				return(true);
			}
		}
		// If we get here, failure
		return(false);
	}




//////////
//
// Called to compare the indicated character variable with the indicated text
//
//////
	s32 iObjProp_compare_character(SObject* obj, u32 tnIndex, s8* tcText, u32 tnTextLength)
	{
		SVariable* var;


		// Make sure the environment is sane
		if (obj)
		{
			// Grab the variable associated with this object's property
			var = iObjProp_get_variable_byIndex(obj, tnIndex);
			if (var && var->varType == _VAR_TYPE_CHARACTER)
				return(iDatum_compare(&var->value, tcText, tnTextLength));	// Do the compare normally
		}
		// If we get here, does not match
		return(-2);
	}
