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


bool iObj_set_activeColumn(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.activeColumn, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_activeColumn, obj->p.activeColumn, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.activeColumn, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.activeColumn, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_activeControl(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.activeControl, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_activeControl, obj->p.activeControl, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.activeControl, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.activeControl, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_activeForm(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.activeForm, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_activeForm, obj->p.activeForm, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.activeForm, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.activeForm, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_activePage(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.activePage, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_activePage, obj->p.activePage, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.activePage, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.activePage, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_activeRow(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.activeRow, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_activeRow, obj->p.activeRow, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.activeRow, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.activeRow, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_addLineFeeds(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.addLineFeeds, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_addLineFeeds, obj->p.addLineFeeds, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.addLineFeeds, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.addLineFeeds, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_align(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.align, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_align, obj->p.align, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.align, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.align, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_alignment(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.alignment, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_alignment, obj->p.alignment, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.alignment, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.alignment, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_allowAddNew(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.allowAddNew, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_allowAddNew, obj->p.allowAddNew, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.allowAddNew, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.allowAddNew, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_allowAutoColumnFit(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.allowAutoColumnFit, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_allowAutoColumnFit, obj->p.allowAutoColumnFit, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.allowAutoColumnFit, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.allowAutoColumnFit, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_allowCellSelection(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.allowCellSelection, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_allowCellSelection, obj->p.allowCellSelection, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.allowCellSelection, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.allowCellSelection, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_allowHeaderSizing(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.allowHeaderSizing, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_allowHeaderSizing, obj->p.allowHeaderSizing, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.allowHeaderSizing, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.allowHeaderSizing, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_allowOutput(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.allowOutput, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_allowOutput, obj->p.allowOutput, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.allowOutput, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.allowOutput, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_allowRowSizing(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.allowRowSizing, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_allowRowSizing, obj->p.allowRowSizing, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.allowRowSizing, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.allowRowSizing, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_allowTabs(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.allowTabs, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_allowTabs, obj->p.allowTabs, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.allowTabs, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.allowTabs, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_alwaysOnBottom(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.alwaysOnBottom, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_alwaysOnBottom, obj->p.alwaysOnBottom, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.alwaysOnBottom, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.alwaysOnBottom, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_alwaysOnTop(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.alwaysOnTop, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_alwaysOnTop, obj->p.alwaysOnTop, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.alwaysOnTop, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.alwaysOnTop, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_anchor(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.anchor, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_anchor, obj->p.anchor, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.anchor, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.anchor, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_application(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.application, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_application, obj->p.application, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.application, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.application, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_autoActivate(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.autoActivate, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_autoActivate, obj->p.autoActivate, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.autoActivate, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.autoActivate, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_autoCenter(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.autoCenter, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_autoCenter, obj->p.autoCenter, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.autoCenter, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.autoCenter, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_autoCompSource(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.autoCompSource, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_autoCompSource, obj->p.autoCompSource, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.autoCompSource, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.autoCompSource, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_autoCompTable(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.autoCompTable, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_autoCompTable, obj->p.autoCompTable, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.autoCompTable, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.autoCompTable, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_autoComplete(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.autoComplete, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_autoComplete, obj->p.autoComplete, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.autoComplete, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.autoComplete, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_autoHideScrollBar(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.autoHideScrollBar, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_autoHideScrollBar, obj->p.autoHideScrollBar, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.autoHideScrollBar, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.autoHideScrollBar, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_autoRelease(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.autoRelease, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_autoRelease, obj->p.autoRelease, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.autoRelease, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.autoRelease, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_autoSize(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.autoSize, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_autoSize, obj->p.autoSize, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.autoSize, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.autoSize, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_autoVerbMenu(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.autoVerbMenu, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_autoVerbMenu, obj->p.autoVerbMenu, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.autoVerbMenu, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.autoVerbMenu, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_backColor(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.backColor, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_backColor, obj->p.backColor, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.backColor, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.backColor, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_backStyle(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.backStyle, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_backStyle, obj->p.backStyle, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.backStyle, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.backStyle, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_baseClass(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.baseClass, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_baseClass, obj->p.baseClass, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.baseClass, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.baseClass, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_bindControls(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.bindControls, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_bindControls, obj->p.bindControls, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.bindControls, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.bindControls, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_borderColor(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.borderColor, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_borderColor, obj->p.borderColor, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.borderColor, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.borderColor, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_borderStyle(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.borderStyle, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_borderStyle, obj->p.borderStyle, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.borderStyle, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.borderStyle, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_borderWidth(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.borderWidth, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_borderWidth, obj->p.borderWidth, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.borderWidth, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.borderWidth, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_bound(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.bound, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_bound, obj->p.bound, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.bound, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.bound, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_boundColumn(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.boundColumn, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_boundColumn, obj->p.boundColumn, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.boundColumn, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.boundColumn, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_boundTo(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.boundTo, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_boundTo, obj->p.boundTo, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.boundTo, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.boundTo, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_bufferMode(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.bufferMode, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_bufferMode, obj->p.bufferMode, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.bufferMode, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.bufferMode, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_buttonCount(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.buttonCount, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_buttonCount, obj->p.buttonCount, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.buttonCount, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.buttonCount, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_cancel(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.cancel, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_cancel, obj->p.cancel, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.cancel, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.cancel, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_caption(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.caption, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_caption, obj->p.caption, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.caption, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.caption, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_centered(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.centered, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_centered, obj->p.centered, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.centered, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.centered, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_century(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.century, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_century, obj->p.century, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.century, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.century, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_childOrder(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.childOrder, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_childOrder, obj->p.childOrder, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.childOrder, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.childOrder, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_class(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p._class, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_class, obj->p._class, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p._class, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p._class, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_classLibrary(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.classLibrary, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_classLibrary, obj->p.classLibrary, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.classLibrary, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.classLibrary, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_clipControls(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.clipControls, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_clipControls, obj->p.clipControls, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.clipControls, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.clipControls, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_closable(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.closable, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_closable, obj->p.closable, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.closable, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.closable, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_colorScheme(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.colorScheme, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_colorScheme, obj->p.colorScheme, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.colorScheme, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.colorScheme, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_colorSource(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.colorSource, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_colorSource, obj->p.colorSource, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.colorSource, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.colorSource, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_columnCount(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.columnCount, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_columnCount, obj->p.columnCount, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.columnCount, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.columnCount, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_columnLines(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.columnLines, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_columnLines, obj->p.columnLines, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.columnLines, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.columnLines, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_columnOrder(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.columnOrder, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_columnOrder, obj->p.columnOrder, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.columnOrder, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.columnOrder, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_columnWidths(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.columnWidths, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_columnWidths, obj->p.columnWidths, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.columnWidths, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.columnWidths, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_columns(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.columns, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_columns, obj->p.columns, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.columns, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.columns, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_comment(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.comment, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_comment, obj->p.comment, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.comment, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.comment, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_continuousScroll(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.continuousScroll, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_continuousScroll, obj->p.continuousScroll, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.continuousScroll, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.continuousScroll, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_controlBox(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.controlBox, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_controlBox, obj->p.controlBox, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.controlBox, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.controlBox, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_controlCount(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.controlCount, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_controlCount, obj->p.controlCount, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.controlCount, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.controlCount, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_controlSource(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.controlSource, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_controlSource, obj->p.controlSource, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.controlSource, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.controlSource, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_controls(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.controls, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_controls, obj->p.controls, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.controls, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.controls, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_count(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.count, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_count, obj->p.count, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.count, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.count, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_currentControl(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.currentControl, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_currentControl, obj->p.currentControl, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.currentControl, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.currentControl, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_currentX(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.currentX, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_currentX, obj->p.currentX, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.currentX, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.currentX, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_currentY(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.currentY, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_currentY, obj->p.currentY, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.currentY, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.currentY, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_curvature(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.curvature, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_curvature, obj->p.curvature, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.curvature, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.curvature, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_dEClass(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.dEClass, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_dEClass, obj->p.dEClass, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.dEClass, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.dEClass, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_dEClassLibrary(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.dEClassLibrary, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_dEClassLibrary, obj->p.dEClassLibrary, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.dEClassLibrary, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.dEClassLibrary, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_dataEnvironment(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.dataEnvironment, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_dataEnvironment, obj->p.dataEnvironment, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.dataEnvironment, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.dataEnvironment, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_dataSession(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.dataSession, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_dataSession, obj->p.dataSession, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.dataSession, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.dataSession, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_dataSessionID(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.dataSessionID, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_dataSessionID, obj->p.dataSessionID, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.dataSessionID, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.dataSessionID, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_dateFormat(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.dateFormat, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_dateFormat, obj->p.dateFormat, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.dateFormat, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.dateFormat, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_dateMark(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.dateMark, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_dateMark, obj->p.dateMark, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.dateMark, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.dateMark, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_defOLELCID(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.defOLELCID, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_defOLELCID, obj->p.defOLELCID, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.defOLELCID, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.defOLELCID, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_default(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p._default, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_default, obj->p._default, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p._default, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p._default, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_deleteMark(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.deleteMark, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_deleteMark, obj->p.deleteMark, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.deleteMark, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.deleteMark, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_desktop(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.desktop, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_desktop, obj->p.desktop, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.desktop, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.desktop, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_details(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.details, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_details, obj->p.details, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.details, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.details, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_disabledBackColor(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.disabledBackColor, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_disabledBackColor, obj->p.disabledBackColor, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.disabledBackColor, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.disabledBackColor, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_disabledForeColor(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.disabledForeColor, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_disabledForeColor, obj->p.disabledForeColor, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.disabledForeColor, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.disabledForeColor, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_disabledItemBackColor(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.disabledItemBackColor, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_disabledItemBackColor, obj->p.disabledItemBackColor, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.disabledItemBackColor, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.disabledItemBackColor, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_disabledItemForeColor(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.disabledItemForeColor, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_disabledItemForeColor, obj->p.disabledItemForeColor, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.disabledItemForeColor, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.disabledItemForeColor, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_disabledPicture(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.disabledPicture, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_disabledPicture, obj->p.disabledPicture, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.disabledPicture, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.disabledPicture, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_displayCount(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.displayCount, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_displayCount, obj->p.displayCount, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.displayCount, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.displayCount, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_displayValue(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.displayValue, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_displayValue, obj->p.displayValue, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.displayValue, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.displayValue, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_doCreate(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.doCreate, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_doCreate, obj->p.doCreate, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.doCreate, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.doCreate, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_dockPosition(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.dockPosition, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_dockPosition, obj->p.dockPosition, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.dockPosition, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.dockPosition, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_dockable(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.dockable, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_dockable, obj->p.dockable, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.dockable, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.dockable, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_docked(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.docked, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_docked, obj->p.docked, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.docked, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.docked, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_documentFile(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.documentFile, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_documentFile, obj->p.documentFile, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.documentFile, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.documentFile, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_downPicture(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.downPicture, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_downPicture, obj->p.downPicture, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.downPicture, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.downPicture, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_dragIcon(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.dragIcon, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_dragIcon, obj->p.dragIcon, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.dragIcon, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.dragIcon, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_dragMode(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.dragMode, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_dragMode, obj->p.dragMode, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.dragMode, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.dragMode, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_drawMode(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.drawMode, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_drawMode, obj->p.drawMode, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.drawMode, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.drawMode, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_drawStyle(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.drawStyle, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_drawStyle, obj->p.drawStyle, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.drawStyle, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.drawStyle, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_drawWidth(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.drawWidth, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_drawWidth, obj->p.drawWidth, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.drawWidth, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.drawWidth, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_dynamicAlignment(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.dynamicAlignment, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_dynamicAlignment, obj->p.dynamicAlignment, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.dynamicAlignment, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.dynamicAlignment, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_dynamicBackColor(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.dynamicBackColor, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_dynamicBackColor, obj->p.dynamicBackColor, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.dynamicBackColor, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.dynamicBackColor, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_dynamicCurrentControl(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.dynamicCurrentControl, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_dynamicCurrentControl, obj->p.dynamicCurrentControl, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.dynamicCurrentControl, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.dynamicCurrentControl, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_dynamicFontBold(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.dynamicFontBold, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_dynamicFontBold, obj->p.dynamicFontBold, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.dynamicFontBold, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.dynamicFontBold, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_dynamicFontItalic(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.dynamicFontItalic, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_dynamicFontItalic, obj->p.dynamicFontItalic, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.dynamicFontItalic, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.dynamicFontItalic, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_dynamicFontName(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.dynamicFontName, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_dynamicFontName, obj->p.dynamicFontName, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.dynamicFontName, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.dynamicFontName, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_dynamicFontOutline(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.dynamicFontOutline, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_dynamicFontOutline, obj->p.dynamicFontOutline, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.dynamicFontOutline, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.dynamicFontOutline, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_dynamicFontShadow(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.dynamicFontShadow, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_dynamicFontShadow, obj->p.dynamicFontShadow, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.dynamicFontShadow, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.dynamicFontShadow, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_dynamicFontSize(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.dynamicFontSize, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_dynamicFontSize, obj->p.dynamicFontSize, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.dynamicFontSize, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.dynamicFontSize, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_dynamicFontStrikeThru(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.dynamicFontStrikeThru, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_dynamicFontStrikeThru, obj->p.dynamicFontStrikeThru, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.dynamicFontStrikeThru, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.dynamicFontStrikeThru, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_dynamicFontUnderline(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.dynamicFontUnderline, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_dynamicFontUnderline, obj->p.dynamicFontUnderline, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.dynamicFontUnderline, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.dynamicFontUnderline, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_dynamicForeColor(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.dynamicForeColor, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_dynamicForeColor, obj->p.dynamicForeColor, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.dynamicForeColor, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.dynamicForeColor, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_dynamicInputMask(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.dynamicInputMask, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_dynamicInputMask, obj->p.dynamicInputMask, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.dynamicInputMask, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.dynamicInputMask, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_enableHyperlinks(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.enableHyperlinks, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_enableHyperlinks, obj->p.enableHyperlinks, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.enableHyperlinks, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.enableHyperlinks, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_enabled(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.enabled, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_enabled, obj->p.enabled, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.enabled, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.enabled, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_errorNo(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.errorNo, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_errorNo, obj->p.errorNo, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.errorNo, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.errorNo, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_fillColor(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.fillColor, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_fillColor, obj->p.fillColor, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.fillColor, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.fillColor, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_fillStyle(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.fillStyle, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_fillStyle, obj->p.fillStyle, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.fillStyle, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.fillStyle, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_firstElement(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.firstElement, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_firstElement, obj->p.firstElement, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.firstElement, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.firstElement, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_fontBold(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.fontBold, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_fontBold, obj->p.fontBold, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.fontBold, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.fontBold, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_fontCharSet(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.fontCharSet, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_fontCharSet, obj->p.fontCharSet, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.fontCharSet, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.fontCharSet, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_fontCondense(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.fontCondense, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_fontCondense, obj->p.fontCondense, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.fontCondense, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.fontCondense, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_fontExtend(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.fontExtend, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_fontExtend, obj->p.fontExtend, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.fontExtend, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.fontExtend, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_fontItalic(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.fontItalic, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_fontItalic, obj->p.fontItalic, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.fontItalic, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.fontItalic, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_fontName(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.fontName, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_fontName, obj->p.fontName, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.fontName, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.fontName, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_fontOutline(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.fontOutline, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_fontOutline, obj->p.fontOutline, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.fontOutline, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.fontOutline, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_fontShadow(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.fontShadow, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_fontShadow, obj->p.fontShadow, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.fontShadow, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.fontShadow, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_fontSize(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.fontSize, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_fontSize, obj->p.fontSize, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.fontSize, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.fontSize, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_fontStrikeThru(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.fontStrikeThru, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_fontStrikeThru, obj->p.fontStrikeThru, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.fontStrikeThru, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.fontStrikeThru, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_fontUnderLine(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.fontUnderLine, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_fontUnderLine, obj->p.fontUnderLine, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.fontUnderLine, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.fontUnderLine, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_fontUnderline(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.fontUnderline, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_fontUnderline, obj->p.fontUnderline, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.fontUnderline, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.fontUnderline, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_foreColor(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.foreColor, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_foreColor, obj->p.foreColor, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.foreColor, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.foreColor, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_formCount(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.formCount, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_formCount, obj->p.formCount, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.formCount, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.formCount, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_format(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.format, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_format, obj->p.format, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.format, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.format, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_forms(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.forms, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_forms, obj->p.forms, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.forms, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.forms, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_gridLineColor(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.gridLineColor, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_gridLineColor, obj->p.gridLineColor, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.gridLineColor, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.gridLineColor, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_gridLineWidth(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.gridLineWidth, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_gridLineWidth, obj->p.gridLineWidth, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.gridLineWidth, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.gridLineWidth, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_gridLines(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.gridLines, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_gridLines, obj->p.gridLines, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.gridLines, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.gridLines, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_hScrollSmallChange(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.hScrollSmallChange, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_hScrollSmallChange, obj->p.hScrollSmallChange, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.hScrollSmallChange, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.hScrollSmallChange, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_hWnd(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.hWnd, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_hWnd, obj->p.hWnd, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.hWnd, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.hWnd, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_halfHeightCaption(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.halfHeightCaption, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_halfHeightCaption, obj->p.halfHeightCaption, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.halfHeightCaption, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.halfHeightCaption, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_headerClass(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.headerClass, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_headerClass, obj->p.headerClass, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.headerClass, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.headerClass, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_headerClassLibrary(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.headerClassLibrary, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_headerClassLibrary, obj->p.headerClassLibrary, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.headerClassLibrary, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.headerClassLibrary, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_headerHeight(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.headerHeight, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_headerHeight, obj->p.headerHeight, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.headerHeight, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.headerHeight, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_height(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.height, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_height, obj->p.height, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.height, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.height, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_helpContextID(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.helpContextID, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_helpContextID, obj->p.helpContextID, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.helpContextID, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.helpContextID, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_hideSelection(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.hideSelection, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_hideSelection, obj->p.hideSelection, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.hideSelection, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.hideSelection, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_highLight(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.highLight, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_highLight, obj->p.highLight, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.highLight, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.highLight, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_highLightRow(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.highLightRow, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_highLightRow, obj->p.highLightRow, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.highLightRow, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.highLightRow, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_highlightBackColor(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.highlightBackColor, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_highlightBackColor, obj->p.highlightBackColor, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.highlightBackColor, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.highlightBackColor, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_highlightForeColor(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.highlightForeColor, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_highlightForeColor, obj->p.highlightForeColor, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.highlightForeColor, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.highlightForeColor, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_highlightRowLineWidth(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.highlightRowLineWidth, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_highlightRowLineWidth, obj->p.highlightRowLineWidth, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.highlightRowLineWidth, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.highlightRowLineWidth, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_highlightStyle(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.highlightStyle, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_highlightStyle, obj->p.highlightStyle, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.highlightStyle, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.highlightStyle, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_hostName(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.hostName, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_hostName, obj->p.hostName, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.hostName, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.hostName, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_hours(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.hours, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_hours, obj->p.hours, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.hours, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.hours, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_iMEMode(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.iMEMode, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_iMEMode, obj->p.iMEMode, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.iMEMode, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.iMEMode, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_icon(SObject* obj, SBitmap* bmp)
{
	// Make sure the environment is sane
	if (obj && bmp)
	{
		// Call the user assign method so it can be examined, or updated:
		if (obj->anyPropertyHasAccessOrAssignMethods)
			iEngine_executeSetter(cgc_icon, NULL, NULL);
		
		// We can perform the set
		iBmp_scale(obj->p.icon, bmp);
		
		// We're good
		return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, NULL);
			return(false);
	}
}

bool iObj_set_increment(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.increment, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_increment, obj->p.increment, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.increment, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.increment, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_incrementalSearch(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.incrementalSearch, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_incrementalSearch, obj->p.incrementalSearch, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.incrementalSearch, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.incrementalSearch, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_inputMask(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.inputMask, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_inputMask, obj->p.inputMask, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.inputMask, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.inputMask, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_integralHeight(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.integralHeight, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_integralHeight, obj->p.integralHeight, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.integralHeight, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.integralHeight, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_interval(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.interval, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_interval, obj->p.interval, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.interval, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.interval, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_itemBackColor(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.itemBackColor, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_itemBackColor, obj->p.itemBackColor, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.itemBackColor, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.itemBackColor, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_itemData(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.itemData, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_itemData, obj->p.itemData, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.itemData, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.itemData, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_itemForeColor(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.itemForeColor, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_itemForeColor, obj->p.itemForeColor, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.itemForeColor, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.itemForeColor, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_itemIDData(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.itemIDData, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_itemIDData, obj->p.itemIDData, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.itemIDData, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.itemIDData, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_itemTips(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.itemTips, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_itemTips, obj->p.itemTips, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.itemTips, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.itemTips, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_keyPreview(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.keyPreview, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_keyPreview, obj->p.keyPreview, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.keyPreview, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.keyPreview, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_keySort(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.keySort, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_keySort, obj->p.keySort, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.keySort, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.keySort, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_keyboardHighValue(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.keyboardHighValue, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_keyboardHighValue, obj->p.keyboardHighValue, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.keyboardHighValue, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.keyboardHighValue, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_keyboardLowValue(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.keyboardLowValue, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_keyboardLowValue, obj->p.keyboardLowValue, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.keyboardLowValue, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.keyboardLowValue, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_left(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.left, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_left, obj->p.left, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.left, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.left, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_leftColumn(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.leftColumn, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_leftColumn, obj->p.leftColumn, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.leftColumn, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.leftColumn, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_lineContents(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.lineContents, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_lineContents, obj->p.lineContents, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.lineContents, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.lineContents, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_lineNo(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.lineNo, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_lineNo, obj->p.lineNo, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.lineNo, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.lineNo, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_lineSlant(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.lineSlant, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_lineSlant, obj->p.lineSlant, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.lineSlant, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.lineSlant, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_linkMaster(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.linkMaster, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_linkMaster, obj->p.linkMaster, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.linkMaster, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.linkMaster, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_list(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.list, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_list, obj->p.list, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.list, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.list, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_listCount(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.listCount, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_listCount, obj->p.listCount, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.listCount, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.listCount, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_listIndex(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.listIndex, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_listIndex, obj->p.listIndex, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.listIndex, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.listIndex, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_listItem(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.listItem, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_listItem, obj->p.listItem, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.listItem, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.listItem, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_listItemID(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.listItemID, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_listItemID, obj->p.listItemID, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.listItemID, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.listItemID, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_lockColumns(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.lockColumns, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_lockColumns, obj->p.lockColumns, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.lockColumns, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.lockColumns, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_lockColumnsLeft(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.lockColumnsLeft, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_lockColumnsLeft, obj->p.lockColumnsLeft, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.lockColumnsLeft, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.lockColumnsLeft, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_lockScreen(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.lockScreen, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_lockScreen, obj->p.lockScreen, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.lockScreen, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.lockScreen, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_mDIForm(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.mDIForm, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_mDIForm, obj->p.mDIForm, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.mDIForm, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.mDIForm, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_macDesktop(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.macDesktop, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_macDesktop, obj->p.macDesktop, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.macDesktop, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.macDesktop, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_margin(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.margin, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_margin, obj->p.margin, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.margin, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.margin, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_maxButton(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.maxButton, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_maxButton, obj->p.maxButton, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.maxButton, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.maxButton, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_maxHeight(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.maxHeight, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_maxHeight, obj->p.maxHeight, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.maxHeight, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.maxHeight, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_maxLeft(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.maxLeft, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_maxLeft, obj->p.maxLeft, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.maxLeft, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.maxLeft, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_maxLength(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.maxLength, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_maxLength, obj->p.maxLength, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.maxLength, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.maxLength, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_maxTop(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.maxTop, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_maxTop, obj->p.maxTop, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.maxTop, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.maxTop, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_maxWidth(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.maxWidth, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_maxWidth, obj->p.maxWidth, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.maxWidth, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.maxWidth, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_memberClass(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.memberClass, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_memberClass, obj->p.memberClass, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.memberClass, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.memberClass, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_memberClassLibrary(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.memberClassLibrary, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_memberClassLibrary, obj->p.memberClassLibrary, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.memberClassLibrary, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.memberClassLibrary, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_memoWindow(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.memoWindow, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_memoWindow, obj->p.memoWindow, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.memoWindow, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.memoWindow, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_message(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.message, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_message, obj->p.message, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.message, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.message, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_minButton(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.minButton, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_minButton, obj->p.minButton, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.minButton, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.minButton, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_minHeight(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.minHeight, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_minHeight, obj->p.minHeight, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.minHeight, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.minHeight, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_minWidth(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.minWidth, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_minWidth, obj->p.minWidth, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.minWidth, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.minWidth, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_mouseIcon(SObject* obj, SBitmap* bmp)
{
	// Make sure the environment is sane
	if (obj && bmp)
	{
		// Call the user assign method so it can be examined, or updated:
		iEngine_executeSetter(cgc_mouseIcon, NULL, NULL);

		// We can perform the set
		iBmp_scale(obj->p.mouseIcon, bmp);

		// We're good
		return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, NULL);
			return(false);
	}
}

bool iObj_set_mousePointer(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.mousePointer, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_mousePointer, obj->p.mousePointer, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.mousePointer, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.mousePointer, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_movable(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.movable, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_movable, obj->p.movable, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.movable, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.movable, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_moverBars(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.moverBars, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_moverBars, obj->p.moverBars, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.moverBars, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.moverBars, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_multiSelect(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.multiSelect, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_multiSelect, obj->p.multiSelect, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.multiSelect, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.multiSelect, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_name(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.name, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_name, obj->p.name, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.name, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.name, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_newIndex(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.newIndex, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_newIndex, obj->p.newIndex, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.newIndex, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.newIndex, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_newItemID(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.newItemID, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_newItemID, obj->p.newItemID, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.newItemID, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.newItemID, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_nullDisplay(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.nullDisplay, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_nullDisplay, obj->p.nullDisplay, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.nullDisplay, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.nullDisplay, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_numberOfElements(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.numberOfElements, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_numberOfElements, obj->p.numberOfElements, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.numberOfElements, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.numberOfElements, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_oLEClass(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.oLEClass, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_oLEClass, obj->p.oLEClass, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.oLEClass, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.oLEClass, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_oLEDragMode(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.oLEDragMode, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_oLEDragMode, obj->p.oLEDragMode, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.oLEDragMode, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.oLEDragMode, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_oLEDragPicture(SObject* obj, SBitmap* bmp)
{
	// Make sure the environment is sane
	if (obj && bmp)
	{
		// Call the user assign method so it can be examined, or updated:
		if (obj->anyPropertyHasAccessOrAssignMethods)
			iEngine_executeSetter(cgc_oLEDragPicture, NULL, NULL);
			
		// We can perform the set
		iBmp_scale(obj->p.oLEDragPicture, bmp);

		// We're good
		return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, NULL);
			return(false);
	}
}

bool iObj_set_oLEDropEffects(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.oLEDropEffects, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_oLEDropEffects, obj->p.oLEDropEffects, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.oLEDropEffects, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.oLEDropEffects, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_oLEDropHasData(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.oLEDropHasData, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_oLEDropHasData, obj->p.oLEDropHasData, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.oLEDropHasData, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.oLEDropHasData, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_oLEDropMode(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.oLEDropMode, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_oLEDropMode, obj->p.oLEDropMode, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.oLEDropMode, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.oLEDropMode, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_oLEDropTextInsertion(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.oLEDropTextInsertion, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_oLEDropTextInsertion, obj->p.oLEDropTextInsertion, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.oLEDropTextInsertion, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.oLEDropTextInsertion, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_oLELCID(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.oLELCID, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_oLELCID, obj->p.oLELCID, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.oLELCID, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.oLELCID, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_oLETypeAllowed(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.oLETypeAllowed, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_oLETypeAllowed, obj->p.oLETypeAllowed, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.oLETypeAllowed, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.oLETypeAllowed, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_object(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.object, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_object, obj->p.object, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.object, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.object, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_objects(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.objects, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_objects, obj->p.objects, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.objects, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.objects, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_openWindow(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.openWindow, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_openWindow, obj->p.openWindow, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.openWindow, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.openWindow, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_optimize(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.optimize, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_optimize, obj->p.optimize, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.optimize, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.optimize, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_pageCount(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.pageCount, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_pageCount, obj->p.pageCount, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.pageCount, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.pageCount, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_pageHeight(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.pageHeight, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_pageHeight, obj->p.pageHeight, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.pageHeight, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.pageHeight, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_pageOrder(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.pageOrder, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_pageOrder, obj->p.pageOrder, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.pageOrder, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.pageOrder, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_pageWidth(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.pageWidth, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_pageWidth, obj->p.pageWidth, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.pageWidth, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.pageWidth, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_pages(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.pages, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_pages, obj->p.pages, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.pages, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.pages, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_panel(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.panel, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_panel, obj->p.panel, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.panel, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.panel, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_panelLink(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.panelLink, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_panelLink, obj->p.panelLink, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.panelLink, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.panelLink, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_parent(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.parent, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_parent, obj->p.parent, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.parent, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.parent, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_parentClass(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.parentClass, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_parentClass, obj->p.parentClass, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.parentClass, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.parentClass, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_partition(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.partition, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_partition, obj->p.partition, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.partition, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.partition, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_passwordChar(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.passwordChar, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_passwordChar, obj->p.passwordChar, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.passwordChar, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.passwordChar, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_picture(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.picture, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_picture, obj->p.picture, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.picture, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.picture, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_pictureMargin(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.pictureMargin, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_pictureMargin, obj->p.pictureMargin, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.pictureMargin, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.pictureMargin, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_picturePosition(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.picturePosition, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_picturePosition, obj->p.picturePosition, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.picturePosition, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.picturePosition, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_pictureSelectionDisplay(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.pictureSelectionDisplay, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_pictureSelectionDisplay, obj->p.pictureSelectionDisplay, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.pictureSelectionDisplay, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.pictureSelectionDisplay, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_pictureSpacing(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.pictureSpacing, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_pictureSpacing, obj->p.pictureSpacing, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.pictureSpacing, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.pictureSpacing, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_pictureVal(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.pictureVal, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_pictureVal, obj->p.pictureVal, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.pictureVal, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.pictureVal, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_polyPoints(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.polyPoints, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_polyPoints, obj->p.polyPoints, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.polyPoints, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.polyPoints, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_procedure(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.procedure, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_procedure, obj->p.procedure, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.procedure, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.procedure, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_readBackColor(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.readBackColor, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_readBackColor, obj->p.readBackColor, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.readBackColor, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.readBackColor, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_readCycle(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.readCycle, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_readCycle, obj->p.readCycle, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.readCycle, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.readCycle, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_readForeColor(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.readForeColor, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_readForeColor, obj->p.readForeColor, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.readForeColor, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.readForeColor, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_readLock(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.readLock, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_readLock, obj->p.readLock, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.readLock, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.readLock, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_readMouse(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.readMouse, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_readMouse, obj->p.readMouse, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.readMouse, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.readMouse, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_readOnly(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.readOnly, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_readOnly, obj->p.readOnly, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.readOnly, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.readOnly, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_readSave(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.readSave, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_readSave, obj->p.readSave, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.readSave, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.readSave, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_readTimeOut(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.readTimeOut, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_readTimeOut, obj->p.readTimeOut, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.readTimeOut, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.readTimeOut, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_recordMark(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.recordMark, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_recordMark, obj->p.recordMark, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.recordMark, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.recordMark, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_recordSource(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.recordSource, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_recordSource, obj->p.recordSource, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.recordSource, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.recordSource, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_recordSourceType(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.recordSourceType, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_recordSourceType, obj->p.recordSourceType, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.recordSourceType, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.recordSourceType, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_relationalExpr(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.relationalExpr, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_relationalExpr, obj->p.relationalExpr, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.relationalExpr, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.relationalExpr, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_relativeColumn(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.relativeColumn, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_relativeColumn, obj->p.relativeColumn, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.relativeColumn, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.relativeColumn, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_relativeRow(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.relativeRow, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_relativeRow, obj->p.relativeRow, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.relativeRow, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.relativeRow, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_releaseType(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.releaseType, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_releaseType, obj->p.releaseType, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.releaseType, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.releaseType, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_resizable(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.resizable, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_resizable, obj->p.resizable, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.resizable, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.resizable, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_rightToLeft(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.rightToLeft, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_rightToLeft, obj->p.rightToLeft, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.rightToLeft, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.rightToLeft, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_rotateFlip(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.rotateFlip, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_rotateFlip, obj->p.rotateFlip, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.rotateFlip, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.rotateFlip, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_rotation(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.rotation, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_rotation, obj->p.rotation, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.rotation, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.rotation, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_rowColChange(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.rowColChange, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_rowColChange, obj->p.rowColChange, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.rowColChange, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.rowColChange, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_rowHeight(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.rowHeight, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_rowHeight, obj->p.rowHeight, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.rowHeight, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.rowHeight, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_rowSource(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.rowSource, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_rowSource, obj->p.rowSource, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.rowSource, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.rowSource, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_rowSourceType(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.rowSourceType, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_rowSourceType, obj->p.rowSourceType, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.rowSourceType, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.rowSourceType, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_scaleMode(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.scaleMode, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_scaleMode, obj->p.scaleMode, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.scaleMode, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.scaleMode, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_scrollBars(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.scrollBars, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_scrollBars, obj->p.scrollBars, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.scrollBars, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.scrollBars, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_seconds(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.seconds, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_seconds, obj->p.seconds, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.seconds, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.seconds, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_selLength(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.selLength, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_selLength, obj->p.selLength, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.selLength, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.selLength, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_selStart(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.selStart, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_selStart, obj->p.selStart, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.selStart, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.selStart, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_selText(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.selText, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_selText, obj->p.selText, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.selText, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.selText, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_selectOnEntry(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.selectOnEntry, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_selectOnEntry, obj->p.selectOnEntry, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.selectOnEntry, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.selectOnEntry, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_selected(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.selected, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_selected, obj->p.selected, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.selected, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.selected, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_selectedBackColor(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.selectedBackColor, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_selectedBackColor, obj->p.selectedBackColor, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.selectedBackColor, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.selectedBackColor, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_selectedForeColor(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.selectedForeColor, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_selectedForeColor, obj->p.selectedForeColor, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.selectedForeColor, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.selectedForeColor, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_selectedID(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.selectedID, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_selectedID, obj->p.selectedID, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.selectedID, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.selectedID, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_selectedItemBackColor(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.selectedItemBackColor, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_selectedItemBackColor, obj->p.selectedItemBackColor, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.selectedItemBackColor, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.selectedItemBackColor, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_selectedItemForeColor(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.selectedItemForeColor, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_selectedItemForeColor, obj->p.selectedItemForeColor, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.selectedItemForeColor, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.selectedItemForeColor, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_showInTaskbar(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.showInTaskbar, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_showInTaskbar, obj->p.showInTaskbar, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.showInTaskbar, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.showInTaskbar, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_showTips(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.showTips, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_showTips, obj->p.showTips, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.showTips, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.showTips, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_showWindow(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.showWindow, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_showWindow, obj->p.showWindow, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.showWindow, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.showWindow, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_sizable(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.sizable, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_sizable, obj->p.sizable, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.sizable, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.sizable, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_sizeBox(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.sizeBox, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_sizeBox, obj->p.sizeBox, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.sizeBox, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.sizeBox, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_sorted(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.sorted, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_sorted, obj->p.sorted, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.sorted, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.sorted, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_sparse(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.sparse, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_sparse, obj->p.sparse, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.sparse, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.sparse, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_specialEffect(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.specialEffect, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_specialEffect, obj->p.specialEffect, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.specialEffect, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.specialEffect, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_spinnerHighValue(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.spinnerHighValue, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_spinnerHighValue, obj->p.spinnerHighValue, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.spinnerHighValue, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.spinnerHighValue, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_spinnerLowValue(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.spinnerLowValue, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_spinnerLowValue, obj->p.spinnerLowValue, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.spinnerLowValue, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.spinnerLowValue, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_splitBar(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.splitBar, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_splitBar, obj->p.splitBar, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.splitBar, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.splitBar, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_stackLevel(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.stackLevel, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_stackLevel, obj->p.stackLevel, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.stackLevel, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.stackLevel, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_statusBarText(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.statusBarText, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_statusBarText, obj->p.statusBarText, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.statusBarText, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.statusBarText, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_stretch(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.stretch, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_stretch, obj->p.stretch, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.stretch, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.stretch, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_strictDateEntry(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.strictDateEntry, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_strictDateEntry, obj->p.strictDateEntry, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.strictDateEntry, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.strictDateEntry, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_style(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.style, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_style, obj->p.style, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.style, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.style, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_tabIndex(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.tabIndex, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_tabIndex, obj->p.tabIndex, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.tabIndex, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.tabIndex, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_tabOrientation(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.tabOrientation, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_tabOrientation, obj->p.tabOrientation, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.tabOrientation, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.tabOrientation, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_tabStop(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.tabStop, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_tabStop, obj->p.tabStop, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.tabStop, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.tabStop, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_tabStyle(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.tabStyle, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_tabStyle, obj->p.tabStyle, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.tabStyle, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.tabStyle, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_tabs(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.tabs, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_tabs, obj->p.tabs, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.tabs, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.tabs, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_tag(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.tag, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_tag, obj->p.tag, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.tag, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.tag, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_terminateRead(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.terminateRead, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_terminateRead, obj->p.terminateRead, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.terminateRead, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.terminateRead, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_text(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.text, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_text, obj->p.text, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.text, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.text, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_themes(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.themes, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_themes, obj->p.themes, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.themes, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.themes, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_titleBar(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.titleBar, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_titleBar, obj->p.titleBar, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.titleBar, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.titleBar, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_toolTipText(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.toolTipText, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_toolTipText, obj->p.toolTipText, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.toolTipText, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.toolTipText, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_top(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.top, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_top, obj->p.top, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.top, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.top, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_topIndex(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.topIndex, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_topIndex, obj->p.topIndex, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.topIndex, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.topIndex, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_topItemID(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.topItemID, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_topItemID, obj->p.topItemID, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.topItemID, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.topItemID, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_userValue(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.userValue, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_userValue, obj->p.userValue, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.userValue, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.userValue, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_vScrollSmallChange(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.vScrollSmallChange, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_vScrollSmallChange, obj->p.vScrollSmallChange, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.vScrollSmallChange, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.vScrollSmallChange, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_value(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.value, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_value, obj->p.value, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.value, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.value, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_view(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.view, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_view, obj->p.view, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.view, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.view, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_viewPortHeight(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.viewPortHeight, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_viewPortHeight, obj->p.viewPortHeight, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.viewPortHeight, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.viewPortHeight, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_viewPortLeft(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.viewPortLeft, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_viewPortLeft, obj->p.viewPortLeft, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.viewPortLeft, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.viewPortLeft, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_viewPortTop(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.viewPortTop, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_viewPortTop, obj->p.viewPortTop, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.viewPortTop, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.viewPortTop, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_viewPortWidth(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.viewPortWidth, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_viewPortWidth, obj->p.viewPortWidth, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.viewPortWidth, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.viewPortWidth, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_visible(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.visible, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_visible, obj->p.visible, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.visible, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.visible, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_visualEffect(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.visualEffect, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_visualEffect, obj->p.visualEffect, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.visualEffect, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.visualEffect, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_whatsThisButton(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.whatsThisButton, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_whatsThisButton, obj->p.whatsThisButton, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.whatsThisButton, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.whatsThisButton, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_whatsThisHelp(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.whatsThisHelp, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_whatsThisHelp, obj->p.whatsThisHelp, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.whatsThisHelp, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.whatsThisHelp, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_whatsThisHelpID(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.whatsThisHelpID, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_whatsThisHelpID, obj->p.whatsThisHelpID, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.whatsThisHelpID, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.whatsThisHelpID, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_width(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.width, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_width, obj->p.width, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.width, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.width, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_windowList(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.windowList, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_windowList, obj->p.windowList, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.windowList, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.windowList, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_windowState(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.windowState, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_windowState, obj->p.windowState, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.windowState, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.windowState, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_windowType(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.windowType, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_windowType, obj->p.windowType, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.windowType, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.windowType, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_wordWrap(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.wordWrap, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_wordWrap, obj->p.wordWrap, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.wordWrap, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.wordWrap, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}

bool iObj_set_zoomBox(SObject* obj, SVariable* var)
{
	// Make sure the environment is sane
	if (obj && var && iVariable_rightIsCompatibleWithLeft(obj->p.zoomBox, var))
	{
		SVariable* varUpdate;
		
		
		// If there are user setter functions
		if (obj->anyPropertyHasAccessOrAssignMethods)
		{
			//////////
			// Create a copy of the variable so the user can alter it if they need
			//////
				varUpdate = iVariable_copy(var);
			
			
			//////////
			//
			// Call the user assign method so it can be examined, or updated:
			//		property_assign(xOldValue, @xNewValue)
			//
			// FUNCTION property_assign
			// LOBJECT to AS (txOldValue, txNewValue)
			//
			//////
				iEngine_executeSetter(cgc_zoomBox, obj->p.zoomBox, varUpdate);
			
			
			//////////
			// Make sure the variable type is still compatible after the user possibly updated its value
			//////
				if (!iVariable_rightIsCompatibleWithLeft(obj->p.zoomBox, varUpdate))
				{
					iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, varUpdate);
					iVariable_delete(varUpdate, true);
					return(false);
				}
		
		} else {
			// Use the passed value for the update
			varUpdate = var;
		}
		
		
		//////////
		// We can perform the set
		//////
			iVariable_set(obj->p.zoomBox, varUpdate);
		
		
		//////////
		// Release our copy if need be
		//////
			if (obj->anyPropertyHasAccessOrAssignMethods)
				iVariable_delete(varUpdate, true);
		
		
		//////////
		// We're good
		//////
			return(true);
	
	} else {
		//////////
		// We need to generate an error because they're trying to do something like this.name = .f.
		//////
			iEngine_error(_ERROR_INVALID_ARGUMENT_TYPE_COUNT, var);
			return(false);
	}
}



SVariable* iObj_get_activeColumn(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.activeColumn));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_activeControl(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.activeControl));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_activeForm(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.activeForm));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_activePage(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.activePage));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_activeRow(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.activeRow));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_addLineFeeds(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.addLineFeeds));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_align(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.align));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_alignment(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.alignment));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_allowAddNew(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.allowAddNew));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_allowAutoColumnFit(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.allowAutoColumnFit));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_allowCellSelection(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.allowCellSelection));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_allowHeaderSizing(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.allowHeaderSizing));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_allowOutput(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.allowOutput));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_allowRowSizing(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.allowRowSizing));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_allowTabs(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.allowTabs));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_alwaysOnBottom(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.alwaysOnBottom));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_alwaysOnTop(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.alwaysOnTop));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_anchor(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.anchor));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_application(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.application));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_autoActivate(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.autoActivate));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_autoCenter(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.autoCenter));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_autoCompSource(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.autoCompSource));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_autoCompTable(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.autoCompTable));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_autoComplete(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.autoComplete));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_autoHideScrollBar(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.autoHideScrollBar));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_autoRelease(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.autoRelease));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_autoSize(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.autoSize));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_autoVerbMenu(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.autoVerbMenu));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_backColor(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.backColor));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_backStyle(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.backStyle));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_baseClass(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.baseClass));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_bindControls(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.bindControls));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_borderColor(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.borderColor));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_borderStyle(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.borderStyle));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_borderWidth(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.borderWidth));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_bound(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.bound));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_boundColumn(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.boundColumn));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_boundTo(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.boundTo));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_bufferMode(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.bufferMode));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_buttonCount(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.buttonCount));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_cancel(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.cancel));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_caption(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.caption));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_centered(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.centered));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_century(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.century));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_childOrder(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.childOrder));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_class(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p._class));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_classLibrary(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.classLibrary));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_clipControls(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.clipControls));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_closable(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.closable));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_colorScheme(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.colorScheme));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_colorSource(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.colorSource));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_columnCount(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.columnCount));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_columnLines(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.columnLines));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_columnOrder(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.columnOrder));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_columnWidths(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.columnWidths));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_columns(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.columns));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_comment(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.comment));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_continuousScroll(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.continuousScroll));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_controlBox(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.controlBox));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_controlCount(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.controlCount));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_controlSource(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.controlSource));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_controls(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.controls));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_count(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.count));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_currentControl(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.currentControl));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_currentX(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.currentX));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_currentY(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.currentY));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_curvature(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.curvature));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_dEClass(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.dEClass));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_dEClassLibrary(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.dEClassLibrary));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_dataEnvironment(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.dataEnvironment));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_dataSession(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.dataSession));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_dataSessionID(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.dataSessionID));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_dateFormat(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.dateFormat));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_dateMark(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.dateMark));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_defOLELCID(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.defOLELCID));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_default(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p._default));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_deleteMark(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.deleteMark));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_desktop(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.desktop));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_details(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.details));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_disabledBackColor(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.disabledBackColor));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_disabledForeColor(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.disabledForeColor));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_disabledItemBackColor(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.disabledItemBackColor));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_disabledItemForeColor(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.disabledItemForeColor));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_disabledPicture(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.disabledPicture));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_displayCount(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.displayCount));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_displayValue(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.displayValue));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_doCreate(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.doCreate));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_dockPosition(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.dockPosition));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_dockable(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.dockable));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_docked(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.docked));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_documentFile(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.documentFile));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_downPicture(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.downPicture));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_dragIcon(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.dragIcon));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_dragMode(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.dragMode));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_drawMode(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.drawMode));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_drawStyle(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.drawStyle));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_drawWidth(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.drawWidth));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_dynamicAlignment(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.dynamicAlignment));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_dynamicBackColor(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.dynamicBackColor));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_dynamicCurrentControl(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.dynamicCurrentControl));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_dynamicFontBold(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.dynamicFontBold));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_dynamicFontItalic(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.dynamicFontItalic));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_dynamicFontName(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.dynamicFontName));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_dynamicFontOutline(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.dynamicFontOutline));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_dynamicFontShadow(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.dynamicFontShadow));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_dynamicFontSize(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.dynamicFontSize));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_dynamicFontStrikeThru(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.dynamicFontStrikeThru));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_dynamicFontUnderline(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.dynamicFontUnderline));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_dynamicForeColor(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.dynamicForeColor));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_dynamicInputMask(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.dynamicInputMask));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_enableHyperlinks(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.enableHyperlinks));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_enabled(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.enabled));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_errorNo(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.errorNo));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_fillColor(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.fillColor));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_fillStyle(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.fillStyle));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_firstElement(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.firstElement));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_fontBold(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.fontBold));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_fontCharSet(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.fontCharSet));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_fontCondense(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.fontCondense));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_fontExtend(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.fontExtend));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_fontItalic(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.fontItalic));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_fontName(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.fontName));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_fontOutline(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.fontOutline));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_fontShadow(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.fontShadow));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_fontSize(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.fontSize));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_fontStrikeThru(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.fontStrikeThru));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_fontUnderLine(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.fontUnderLine));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_fontUnderline(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.fontUnderline));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_foreColor(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.foreColor));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_formCount(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.formCount));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_format(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.format));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_forms(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.forms));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_gridLineColor(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.gridLineColor));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_gridLineWidth(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.gridLineWidth));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_gridLines(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.gridLines));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_hScrollSmallChange(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.hScrollSmallChange));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_hWnd(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.hWnd));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_halfHeightCaption(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.halfHeightCaption));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_headerClass(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.headerClass));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_headerClassLibrary(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.headerClassLibrary));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_headerHeight(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.headerHeight));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_height(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.height));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_helpContextID(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.helpContextID));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_hideSelection(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.hideSelection));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_highLight(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.highLight));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_highLightRow(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.highLightRow));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_highlightBackColor(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.highlightBackColor));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_highlightForeColor(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.highlightForeColor));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_highlightRowLineWidth(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.highlightRowLineWidth));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_highlightStyle(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.highlightStyle));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_hostName(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.hostName));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_hours(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.hours));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_iMEMode(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.iMEMode));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SBitmap* iObj_get_icon(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iBmp_copy(obj->p.icon));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_increment(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.increment));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_incrementalSearch(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.incrementalSearch));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_inputMask(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.inputMask));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_integralHeight(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.integralHeight));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_interval(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.interval));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_itemBackColor(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.itemBackColor));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_itemData(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.itemData));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_itemForeColor(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.itemForeColor));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_itemIDData(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.itemIDData));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_itemTips(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.itemTips));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_keyPreview(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.keyPreview));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_keySort(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.keySort));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_keyboardHighValue(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.keyboardHighValue));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_keyboardLowValue(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.keyboardLowValue));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_left(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.left));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_leftColumn(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.leftColumn));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_lineContents(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.lineContents));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_lineNo(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.lineNo));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_lineSlant(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.lineSlant));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_linkMaster(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.linkMaster));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_list(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.list));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_listCount(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.listCount));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_listIndex(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.listIndex));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_listItem(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.listItem));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_listItemID(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.listItemID));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_lockColumns(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.lockColumns));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_lockColumnsLeft(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.lockColumnsLeft));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_lockScreen(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.lockScreen));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_mDIForm(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.mDIForm));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_macDesktop(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.macDesktop));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_margin(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.margin));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_maxButton(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.maxButton));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_maxHeight(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.maxHeight));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_maxLeft(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.maxLeft));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_maxLength(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.maxLength));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_maxTop(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.maxTop));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_maxWidth(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.maxWidth));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_memberClass(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.memberClass));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_memberClassLibrary(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.memberClassLibrary));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_memoWindow(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.memoWindow));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_message(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.message));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_minButton(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.minButton));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_minHeight(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.minHeight));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_minWidth(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.minWidth));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SBitmap* iObj_get_mouseIcon(SObject* obj)
{
	SBitmap* bmp;


	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the bitmap
		bmp = iBmp_copy(obj->p.mouseIcon);
		return(bmp);
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_mousePointer(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.mousePointer));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_movable(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.movable));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_moverBars(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.moverBars));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_multiSelect(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.multiSelect));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_name(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.name));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_newIndex(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.newIndex));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_newItemID(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.newItemID));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_nullDisplay(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.nullDisplay));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_numberOfElements(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.numberOfElements));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_oLEClass(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.oLEClass));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_oLEDragMode(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.oLEDragMode));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SBitmap* iObj_get_oLEDragPicture(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iBmp_copy(obj->p.oLEDragPicture));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_oLEDropEffects(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.oLEDropEffects));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_oLEDropHasData(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.oLEDropHasData));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_oLEDropMode(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.oLEDropMode));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_oLEDropTextInsertion(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.oLEDropTextInsertion));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_oLELCID(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.oLELCID));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_oLETypeAllowed(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.oLETypeAllowed));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_object(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.object));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_objects(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.objects));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_openWindow(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.openWindow));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_optimize(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.optimize));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_pageCount(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.pageCount));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_pageHeight(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.pageHeight));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_pageOrder(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.pageOrder));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_pageWidth(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.pageWidth));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_pages(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.pages));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_panel(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.panel));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_panelLink(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.panelLink));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_parent(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.parent));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_parentClass(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.parentClass));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_partition(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.partition));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_passwordChar(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.passwordChar));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_picture(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.picture));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_pictureMargin(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.pictureMargin));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_picturePosition(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.picturePosition));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_pictureSelectionDisplay(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.pictureSelectionDisplay));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_pictureSpacing(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.pictureSpacing));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_pictureVal(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.pictureVal));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_polyPoints(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.polyPoints));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_procedure(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.procedure));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_readBackColor(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.readBackColor));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_readCycle(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.readCycle));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_readForeColor(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.readForeColor));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_readLock(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.readLock));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_readMouse(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.readMouse));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_readOnly(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.readOnly));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_readSave(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.readSave));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_readTimeOut(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.readTimeOut));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_recordMark(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.recordMark));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_recordSource(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.recordSource));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_recordSourceType(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.recordSourceType));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_relationalExpr(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.relationalExpr));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_relativeColumn(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.relativeColumn));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_relativeRow(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.relativeRow));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_releaseType(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.releaseType));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_resizable(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.resizable));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_rightToLeft(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.rightToLeft));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_rotateFlip(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.rotateFlip));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_rotation(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.rotation));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_rowColChange(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.rowColChange));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_rowHeight(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.rowHeight));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_rowSource(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.rowSource));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_rowSourceType(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.rowSourceType));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_scaleMode(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.scaleMode));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_scrollBars(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.scrollBars));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_seconds(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.seconds));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_selLength(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.selLength));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_selStart(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.selStart));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_selText(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.selText));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_selectOnEntry(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.selectOnEntry));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_selected(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.selected));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_selectedBackColor(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.selectedBackColor));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_selectedForeColor(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.selectedForeColor));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_selectedID(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.selectedID));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_selectedItemBackColor(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.selectedItemBackColor));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_selectedItemForeColor(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.selectedItemForeColor));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_showInTaskbar(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.showInTaskbar));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_showTips(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.showTips));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_showWindow(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.showWindow));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_sizable(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.sizable));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_sizeBox(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.sizeBox));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_sorted(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.sorted));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_sparse(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.sparse));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_specialEffect(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.specialEffect));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_spinnerHighValue(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.spinnerHighValue));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_spinnerLowValue(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.spinnerLowValue));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_splitBar(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.splitBar));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_stackLevel(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.stackLevel));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_statusBarText(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.statusBarText));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_stretch(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.stretch));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_strictDateEntry(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.strictDateEntry));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_style(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.style));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_tabIndex(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.tabIndex));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_tabOrientation(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.tabOrientation));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_tabStop(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.tabStop));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_tabStyle(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.tabStyle));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_tabs(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.tabs));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_tag(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.tag));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_terminateRead(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.terminateRead));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_text(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.text));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_themes(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.themes));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_titleBar(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.titleBar));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_toolTipText(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.toolTipText));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_top(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.top));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_topIndex(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.topIndex));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_topItemID(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.topItemID));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_userValue(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.userValue));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_vScrollSmallChange(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.vScrollSmallChange));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_value(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.value));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_view(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.view));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_viewPortHeight(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.viewPortHeight));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_viewPortLeft(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.viewPortLeft));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_viewPortTop(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.viewPortTop));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_viewPortWidth(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.viewPortWidth));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_visible(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.visible));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_visualEffect(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.visualEffect));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_whatsThisButton(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.whatsThisButton));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_whatsThisHelp(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.whatsThisHelp));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_whatsThisHelpID(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.whatsThisHelpID));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_width(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.width));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_windowList(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.windowList));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_windowState(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.windowState));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_windowType(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.windowType));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_wordWrap(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.wordWrap));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

SVariable* iObj_get_zoomBox(SObject* obj)
{
	// Make sure the environment is sane
	if (obj)
	{
		// Return a copy of the variable
		return(iVariable_copy(obj->p.zoomBox));
	
	} else {
		// Indicate failure
		return(NULL);
	}
}

