**********
*
* /libsf/vvm/utils/inquiry/progs/inquiry_dll.prg
*
*****
* Version 0.10
* Copyright (c) 2014 by Rick C. Hodgin
*****
* Last update:
*     Aug.02.2014
*****
* Change log:
*     Aug.02.2014	- Initial creation
*****
*
* This software is released as Liberty Software under a Repeat License, as governed
* by the Public Benefit License v1.0 or later (PBL).
*
* You are free to use, copy, modify and share this software.  However, it can only
* be released under the PBL version indicated, and every project must include a copy
* of the pbl.txt document for its version as is at http:*www.libsf.org/licenses/.
*
* For additional information about this project, or to view the license, see:
*
*     http:*www.libsf.org/
*     http:*www.libsf.org/licenses/
*     http:*www.visual-freepro.org
*     http:*www.visual-freepro.org/blog/
*     http:*www.visual-freepro.org/forum/
*     http:*www.visual-freepro.org/wiki/
*     http:*www.visual-freepro.org/wiki/index.php/PBL
*     http:*www.visual-freepro.org/wiki/index.php/Repeat_License
*
* Thank you.  And may The Lord bless you richly as you lift up your life, your
* talents, your gifts, your praise, unto Him.  In Jesus' name I pray.  Amen.
*
*****
*
* List of functions to communicate with the remote Inquiry Server:
*
*		inquiry_get_applications 			&& Retrieves all applications being maintained by the Inquiry Server (no authentication required)
*
*		inquiry_login						&& Requires user name, password, and the application token
*		inquiry_logout						&& Logs out of a session
*
*		inquiry_get_status_list				&& Retrieves full list of statuses for this application
*		inquiry_get_priority_list			&& Retrieves full list of priorities for this application
*		inquiry_get_reported_list			&& Retrieves full list of reported texts for this application
*		inquiry_get_target_list				&& Retrieves full list of target texts for this application
*
*		inquiry_get_by_date					&& Retrieves full inquiry list of all records equal to or newer than the date and time
*		inquiry_get_by_status				&& Retrieves full inquiry list of all records matching the status
*		inquiry_get_by_priority				&& Retrieves full inquiry list of all records matching the priority
*		inquiry_get_by_reported				&& Retrieves full inquiry list of all records matching the reported (typically a version or date)
*		inquiry_get_by_target				&& Retrieves full inquiry list of all records matching the target (typically a version or date)
*
*		inquiry_get_description				&& Descriptions vary in length and are retrieved separately
*		inquiry_get_comment					&& Comments vary in length and are retrieved separately
*
*		inquiry_update_title				&& Updates the title, creates a change history log
*		inquiry_update_description			&& Updates the description, creates a change history log
*		inquiry_update_comment				&& Updates the comment, creates a change history log
*		inquiry_update_status				&& Updates the status, creates a change history log
*		inquiry_update_priority				&& Updates the priority, creates a change history log
*		inquiry_update_release				&& Updates the release, creates a change history log
*
*		inquiry_add							&& Add a new inquiry
*		inquiry_add_comment					&& Add a new comment to an inquiry
*
*		inquiry_get_change_history				&& Retrieves the change history for all changes made to title, status, priority, reported, or target
*		inquiry_get_change_history_description	&& Retrieves the description change history for the inquiry
*		inquiry_get_change_history_comment		&& Retrieves the comment change history for the inquiry and comment number
*
*		inquiry_check_status				&& Returns the status of the indicated requestId, either -1 timed out, 0 no response, or >= 1 Mail ID
*		inquiry_get_mail					&& Retrieves prepared text mail sent from the server
*****





**********
* Each of the functions below returns a Request ID, except inquiry_check_state()
* and inquiry_get_mail().
*
* The Request ID can be queried after to determine the state of the request.
* Ultimately the request will time out or be acknowledged.  Once the request
* is acknowledged, use inquiry_get_mail() to retrieve the text of the response.
*****
FUNCTION declare_inquiry_dll

	* Retrieve all applications from the indicated Inquiry Server
	* Note:  Connection remains active until a switch is made to another server, until the connection times out, or the application terminates
	DECLARE INTEGER		inquiry_get_applications ;
							IN exe\inquiry.dll ;
							INTEGER		nHwnd, ;				&& The notification HWND
							STRING		cIpAddress, ;			&& IP address to query
							STRING		cPort					&& Port to query
							**********
							* create cursor c_applications ;
							* ( ;
							*		cApp		c(64), ;		&& Name of the application
							*		cToken		c(40) ;			&& Token to send with inquiry_login()
							* )
							*****

	* Login
	* Returns Request ID.  Use inquiry_check_state() and inquiry_get_mail() to retrieve content.
	DECLARE INTEGER		inquiry_login ;
							IN exe\inquiry.dll ;
							STRING		cUser, ;				&& User name, pre-assigned
							STRING		cPassword, ;			&& Password, pre-assigned
							STRING		cApplicationToken		&& Application token to access
							**********
							* create cursor c_session ;
							* ( ;
							*		cUser		c(64), ;		&& User logged in
							*		cApp		c(64), ;		&& Name of the application logged into
							*		cSession	c(40), ;		&& The session token to use on requests
							*		nExpires	n(3) ;			&& Inactivity interval in seconds before the session is automatically closed on the server
							* )
							*****
	
	* Logout
	* Returns Request ID.  Use inquiry_check_state() and inquiry_get_mail() to retrieve content.
	DECLARE INTEGER		inquiry_logout ;
							IN exe\inquiry.dll ;
							STRING		cSession				&& The token received in mail after logging in
	
	* Retrieve all statuses for the application
	* Returns Request ID.  Use inquiry_check_state() and inquiry_get_mail() to retrieve content.
	DECLARE INTEGER		inquiry_get_status_list ;
							IN exe\inquiry.dll ;
							STRING		cSession				&& The token received in mail after logging in
							**********
							* create cursor c_status ;
							* ( ;
							*		cStatus		c(20)
							* )
							*****
	
	* Retrieve all priorities for the application
	* Returns Request ID.  Use inquiry_check_state() and inquiry_get_mail() to retrieve content.
	DECLARE INTEGER		inquiry_get_priority_list ;
							IN exe\inquiry.dll ;
							STRING		cSession				&& The token received in mail after logging in
							**********
							* create cursor c_priority ;
							* ( ;
							*		cPriority	c(20)
							* )
							*****
	
	* Retrieve all reported texts for the application
	* Returns Request ID.  Use inquiry_check_state() and inquiry_get_mail() to retrieve content.
	DECLARE INTEGER		inquiry_get_reported_list ;
							IN exe\inquiry.dll ;
							STRING		cSession				&& The token received in mail after logging in
							**********
							* create cursor c_reported ;
							* ( ;
							*		cName		c(20), ;
							* )
							*****
	
	* Retrieve all target texts for the application
	* Returns Request ID.  Use inquiry_check_state() and inquiry_get_mail() to retrieve content.
	DECLARE INTEGER		inquiry_get_target_list ;
							IN exe\inquiry.dll ;
							STRING		cSession				&& The token received in mail after logging in
							**********
							* create cursor c_target ;
							* ( ;
							*		cName		c(20), ;
							* )
							*****

	* Retrieves all inquiries by date
	* Returns Request ID.  Use inquiry_check_state() and inquiry_get_mail() to retrieve content.
	DECLARE INTEGER		inquiry_get_by_date ;
							IN exe\inquiry.dll ;
							STRING		cSession, ;				&& The token received in mail after logging in
							INTEGER		nYear, ;				&& Part of the datetime of records to retrieve (everything of this date or newer is retrieved)
							INTEGER		nMonth, ;
							INTEGER		nDay, ;
							INTEGER		nHour, ;
							INTEGER		nMinute, ;
							INTEGER		nSecond
							* See create cursor c_list below

	* Retrieves all inquiries by status
	* Returns Request ID.  Use inquiry_check_state() and inquiry_get_mail() to retrieve content.
	DECLARE INTEGER		inquiry_get_by_status ;
							IN exe\inquiry.dll ;
							STRING		cSession, ;				&& The token received in mail after logging in
							STRING		cStatus					&& What to retrieve
							* See create cursor c_list below

	* Retrieves all inquiries by priority
	* Returns Request ID.  Use inquiry_check_state() and inquiry_get_mail() to retrieve content.
	DECLARE INTEGER		inquiry_get_by_priority ;
							IN exe\inquiry.dll ;
							STRING		cSession, ;				&& The token received in mail after logging in
							STRING		cPriority				&& What to retrieve
							* See create cursor c_list below

	* Retrieves all inquiries by reported
	* Returns Request ID.  Use inquiry_check_state() and inquiry_get_mail() to retrieve content.
	DECLARE INTEGER		inquiry_get_by_reported ;
							IN exe\inquiry.dll ;
							STRING		cSession, ;				&& The token received in mail after logging in
							STRING		cStatus					&& What to retrieve
							* See create cursor c_list below

	* Retrieves all inquiries by target
	* Returns Request ID.  Use inquiry_check_state() and inquiry_get_mail() to retrieve content.
	DECLARE INTEGER		inquiry_get_by_target ;
							IN exe\inquiry.dll ;
							STRING		cSession, ;				&& The token received in mail after logging in
							STRING		cStatus					&& What to retrieve

							**********
							* create cursor c_list ;
							* ( ;
							*		nId			n(10), ;		&& Inquiry ID number
							*		cTitle		c(64), ;		&& Title of the inquiry
							*		cStatus		c(20), ;		&& Status of the inquiry
							*		cPriority	c(20), ;		&& Priority of the inquiry
							*		cReported	c(20), ;		&& Reported text (version or date the inquiry was found)
							*		cTarget		c(20), ;		&& Target text (planned version or date the inquiry should be fixed)
							*		cBy			c(64), ;		&& Name of the user who reported it
							*		cOn			c(14), ;		&& YYYYMMDDhhmmss reported
							*		cLast		c(14), ;		&& YYYYMMDDhhmmss status last updated or changed
							*		nComments	n(3) ;			&& Number of comments (for inquiry_get_comment() access)
							* )
							*****
	
	* Retrieve the inquiry description
	* Returns Request ID.  Use inquiry_check_state() and inquiry_get_mail() to retrieve content.
	DECLARE INTEGER		inquiry_get_description ;
							IN exe\inquiry.dll ;
							STRING		cSession, ;				&& The token received in mail after logging in
							INTEGER		nId						&& The inquiry number to request
							**********
							* Raw text of varying length to be, inserted into a memo field
							*****
	
	* Retrieve all inquiry comments
	* Returns Request ID.  Use inquiry_check_state() and inquiry_get_mail() to retrieve content.
	DECLARE INTEGER		inquiry_get_comment ;
							IN exe\inquiry.dll ;
							STRING		cSession, ;				&& The token received in mail after logging in
							INTEGER		nId, ;					&& The inquiry number to request
							INTEGER		nCommentNumber			&& The comment number to request
							**********
							* Raw text of varying length to be, inserted into a memo field
							*****

	* Change an existing title
	* Returns Request ID.  Use inquiry_check_state() and inquiry_get_mail() to retrieve content.
	DECLARE INTEGER		inquiry_update_title ;
							IN exe\inquiry.dll ;
							STRING		cSession, ;				&& The token received in mail after logging in
							INTEGER		nId, ;					&& The inquiry number to request
							STRING		cTitle					&& The new title text

	* Change an existing description
	* Returns Request ID.  Use inquiry_check_state() and inquiry_get_mail() to retrieve content.
	DECLARE INTEGER		inquiry_update_description ;
							IN exe\inquiry.dll ;
							STRING		cSession, ;				&& The token received in mail after logging in
							INTEGER		nId, ;					&& The inquiry number to request
							STRING		cDescription			&& The new description text

	* Change an existing comment
	* Returns Request ID.  Use inquiry_check_state() and inquiry_get_mail() to retrieve content.
	DECLARE INTEGER		inquiry_update_comment ;
							IN exe\inquiry.dll ;
							STRING		cSession, ;				&& The token received in mail after logging in
							INTEGER		nId, ;					&& The inquiry number to request
							INTEGER		nCommentNumber, ;		&& The comment number to update
							STRING		cComment				&& The new comment text

	* Change status of an inquiry
	* Returns Request ID.  Use inquiry_check_state() and inquiry_get_mail() to retrieve content.
	DECLARE INTEGER		inquiry_update_status ;
							IN exe\inquiry.dll ;
							STRING		cSession, ;				&& The token received in mail after logging in
							INTEGER		nId, ;					&& The inquiry number to request
							STRING		cStatus					&& The new status

	* Change priority of an inquiry
	* Returns Request ID.  Use inquiry_check_state() and inquiry_get_mail() to retrieve content.
	DECLARE INTEGER		inquiry_update_priority ;
							IN exe\inquiry.dll ;
							STRING		cSession, ;				&& The token received in mail after logging in
							INTEGER		nId, ;					&& The inquiry number to request
							STRING		cPriority				&& The new priority

	* Change release of an inquiry
	* Returns Request ID.  Use inquiry_check_state() and inquiry_get_mail() to retrieve content.
	DECLARE INTEGER		inquiry_update_release ;
							IN exe\inquiry.dll ;
							STRING		cSession, ;				&& The token received in mail after logging in
							INTEGER		nId, ;					&& The inquiry number to request
							STRING		cReported, ;			&& The new reported release
							STRING		cTarget					&& THe new target release for the fix/implementation

	* Add a new inquiry
	* Returns Request ID.  Use inquiry_check_state() and inquiry_get_mail() to retrieve content.
	DECLARE INTEGER		inquiry_add ;
							IN exe\inquiry.dll ;
							STRING		cSession, ;				&& The token received in mail after logging in
							STRING		cTitle, ;				&& Title of this inquiry (up to 64 characters)
							STRING		cDescription, ;			&& Description
							STRING		cStatus, ;				&& Status
							STRING		cPriority, ;			&& Priority
							STRING		cReported, ;			&& Reported release
							STRING		cTarget					&& Target release

	* Add a new comment to the inquiry
	* Returns Request ID.  Use inquiry_check_state() and inquiry_get_mail() to retrieve content.
	DECLARE INTEGER		inquiry_add_comment ;
							IN exe\inquiry.dll ;
							STRING		cSession, ;				&& The token received in mail after logging in
							INTEGER		nId, ;					&& The inquiry number to request
							STRING		cComment				&& The comment to add
	
	* Retrieve the change history
	* Returns Request ID.  Use inquiry_check_state() and inquiry_get_mail() to retrieve content.
	DECLARE INTEGER		inquiry_get_change_history ;
							IN exe\inquiry.dll ;
							STRING		cSession, ;				&& The token received in mail after logging in
							INTEGER		nId						&& The inquiry number to request
							**********
							* Raw text of to be parsed based on first character of each line,
							* of the general format (repeats in datetime order for as many as
							* there are, t=title, s=status, p=priority, r=reported, t=target):
							*
							*	t=YYYYMMDDhhmmssold text 64 chars-----------------------------------------------new text 64 chars-----------------------------------------------
							*	s=YYYYMMDDhhmmssold text 20 chars---new text 20 chars---
							*	p=YYYYMMDDhhmmssold text 20 chars---new text 20 chars---
							*	r=YYYYMMDDhhmmssold text 20 chars---new text 20 chars---
							*	t=YYYYMMDDhhmmssold text 20 chars---new text 20 chars---
							*
							*****
	
	* Retrieve the change history of the description
	* Returns Request ID.  Use inquiry_check_state() and inquiry_get_mail() to retrieve content.
	DECLARE INTEGER		inquiry_get_change_history_description ;
							IN exe\inquiry.dll ;
							STRING		cSession, ;				&& The token received in mail after logging in
							INTEGER		nId						&& The inquiry number to request
							**********
							* Raw text of varying length to be parsed, with multiple records
							* Of the general format (repeats for as many as there are):
							*
							*	-=[ START: datetime ]=-
							*	description text goes here
							*	-=[ END: datetime ]=-
							*
							*	-=[ START: datetime ]=-
							*	description text goes here
							*	-=[ END: datetime ]=-
							*
							*****
	
	* Retrieve the change history of the comment
	* Returns Request ID.  Use inquiry_check_state() and inquiry_get_mail() to retrieve content.
	DECLARE INTEGER		inquiry_get_change_history_comment ;
							IN exe\inquiry.dll ;
							STRING		cSession, ;				&& The token received in mail after logging in
							INTEGER		nId, ;					&& The inquiry number to request
							INTEGER		nCommentNumber, ;		&& The comment number to update
							**********
							* Raw text of varying length to be parsed, with multiple records
							* Of the general format (repeats for as many as there are):
							*
							*	-=[ START: datetime ]=-
							*	description text goes here
							*	-=[ END: datetime ]=-
							*
							*	-=[ START: datetime ]=-
							*	description text goes here
							*	-=[ END: datetime ]=-
							*
							*****

	* Requests the status of a previously issued request.
	* Returns 0 if no response yet, -1 if timed out, or a valid Mail ID if >= 1.
	DECLARE INTEGER		inquiry_check_status ;
							IN exe\inquiry.dll ;
							INTEGER		nRequestId				&& The Request ID retrieved after the prior request

	* Retrieves the mail content as a character string
	* Returns number of bytes required.  If the message is not fully consumed, it persists.
	* Use an nTextLength of 0 to retrieve N and allocate with SPACE(N).
	DECLARE INTEGER		inquiry_get_mail ;
							IN exe\inquiry.dll ;
							INTEGER		nMailId, ;				&& The Mail ID returned by inquiry_check_status()
							STRING@		cText, ;				&& Where to store the text (use @)
							INTEGER		nTextLength				&& How many bytes are available to store the mail
							**********
							* Raw text of varying length to be parsed. The request id will always be first.
							* Then the command.  After that the parameters except the session token.  After
							* that will be the response.
							*
							*	request:1
							*	command:inquiry_get_change_history_comment()
							*	p2:1
							*	p3:1
							*	response:The actual text of the response will begin here and continues on until the end of the 
							*
							*****
