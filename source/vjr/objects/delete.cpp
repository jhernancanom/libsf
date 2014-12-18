//////////
//
// /libsf/source/vjr/objects/delete.cpp
//
//////
// Version 0.54
// Copyright (c) 2014 by Rick C. Hodgin
//////
// Last update:
//     Dec.18.2014
//////
// Change log:
//     Dec.18.2014 - Initial creation
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
//
// Thank you.  And may The Lord bless you richly as you lift up your life, your
// talents, your gifts, your praise, unto Him.  In Jesus' name I pray.  Amen.
//
//









//////////
//
// Called to delete the common properties
//
//////
	void iObj_deleteCommon(SObject* obj)
	{
		SWindow* win;


		//////////
		// See if this object is the top-level object to any windows, and if so disconnect it
		//////
			win = iWindow_findByObj(obj);
			if (win)
				iWindow_disconnectObj(win, obj);

// TODO:  iterate through obj->props and delete all
	}




//////////
//
// Called to delete the empty.
//
//////
	void iSubobj_deleteEmpty(SObject* empty, bool tlDeleteSelf)
	{
		logfunc(__FUNCTION__);
		//////////
		// Free common components
		//////
			iObj_deleteCommon(empty);


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
	void iSubobj_deleteForm(SObject* form, bool tlDeleteSelf)
	{
		logfunc(__FUNCTION__);
		//////////
		// Free common components
		//////
			iObj_deleteCommon(form);


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
	void iSubobj_deleteSubform(SObject* subform, bool tlDeleteSelf)
	{
		logfunc(__FUNCTION__);
		//////////
		// Free common components
		//////
			iObj_deleteCommon(subform);


		//////////
		// Free self
		//////
			if (tlDeleteSelf)
				free(subform);
	}




//////////
//
// Called to delete the carousel
//
//////
	void iSubobj_deleteCarousel(SObject* carousel, bool tlDeleteSelf, bool tlLeaveRiders, bool tlLeaveObjects)
	{
		SObject* rider;
		SObject* riderNext;


		logfunc(__FUNCTION__);
		//////////
		// Free common components
		//////
			iObj_deleteCommon(carousel);


		//////////
		// Act on riders
		//////
			if (tlLeaveRiders)
			{
				// We just need to orphanize each one
//////////
// Note:  Orphanizing riders is a potentially precarious thing.  They must be known as they are
//        not maintained in a buffer somewhere.  Typically this only occurs when migrating the
//        last rider from one carousel to another.  But regardless, care must be taken to prevent
//        the orphaned rider from hanging around unused and forgotten.
//////
				// Get the first
				rider = carousel->firstChild;

				// Mark the parent as now being free from children
				carousel->firstChild = NULL;

				// Iterate for every rider
				while (rider)
				{
					// Determine the next rider
					riderNext = (SObject*)rider->ll.next;

					// Orphanize this rider
					iLl_orphanizeNode((SLL*)rider);

					// Move to next rider
					rider = riderNext;
				}

			} else {
				// They are being deleted
				iObj_delete(&carousel->firstChild, true, true, true);
			}


		//////////
		// Free self
		//////
			if (tlDeleteSelf)
				free(carousel);
	}




//////////
//
// Called to delete the rider
//
//////
	void iSubobj_deleteRider(SObject* rider, bool tlDeleteSelf, bool tlLeaveObjects)
	{
		logfunc(__FUNCTION__);
		//////////
		// Free common components
		//////
			iObj_deleteCommon(rider);


		//////////
		// Act on objects
		//////
			if (!tlLeaveObjects)
				iObj_delete(&rider->firstChild, true, true, true);		// They are being deleted


		//////////
		// Free self
		//////
			if (tlDeleteSelf)
				free(rider);
	}




//////////
//
// Called to delete the label.
//
//////
	void iSubobj_deleteLabel(SObject* label, bool tlDeleteSelf)
	{
		logfunc(__FUNCTION__);
		//////////
		// Free common components
		//////
			iObj_deleteCommon(label);


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
	void iSubobj_deleteTextbox(SObject* textbox, bool tlDeleteSelf)
	{
		logfunc(__FUNCTION__);
		//////////
		// Free common components
		//////
			iObj_deleteCommon(textbox);


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
	void iSubobj_deleteButton(SObject* button, bool tlDeleteSelf)
	{
		logfunc(__FUNCTION__);
		//////////
		// Free common components
		//////
			iObj_deleteCommon(button);


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
	void iSubobj_deleteEditbox(SObject* editbox, bool tlDeleteSelf)
	{
		logfunc(__FUNCTION__);
		//////////
		// Free common components
		//////
			iObj_deleteCommon(editbox);


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
	void iSubobj_deleteImage(SObject* image, bool tlDeleteSelf)
	{
		logfunc(__FUNCTION__);
		//////////
		// Free common components
		//////
			iObj_deleteCommon(image);


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
	void iSubobj_deleteCheckbox(SObject* checkbox, bool tlDeleteSelf)
	{
		logfunc(__FUNCTION__);
		//////////
		// Free common components
		//////
			iObj_deleteCommon(checkbox);


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
	void iSubobj_deleteOption(SObject* option, bool tlDeleteSelf)
	{
		logfunc(__FUNCTION__);
		//////////
		// Free common components
		//////
			iObj_deleteCommon(option);


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
	void iSubobj_deleteRadio(SObject* radio, bool tlDeleteSelf)
	{
		logfunc(__FUNCTION__);
		//////////
		// Free common components
		//////
			iObj_deleteCommon(radio);


		//////////
		// Free self
		//////
			if (tlDeleteSelf)
				free(radio);
	}
