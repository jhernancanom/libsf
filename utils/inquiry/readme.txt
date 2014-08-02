Aug.02.2014
-----------

A user on the Facebook Visual FreePro group reported a bug in version 0.41
of Visual FreePro, Jr., released Aug.01.2014.  As such I resolved to setup
an issue tracker system of some kind so users could report the bugs.  I
began looking for something as simple and easy to use as the GitHub issue
tracker, but could not find any.  As such, I wrote one myself.

The term inquiry was created to represent the state of a computer software
application that is not processing something correctly because it either
is programmed incorrectly, or because given its programming it cannot complete
the requested task (such as adding the integer 2 to the character string
"rick").  In the case of a program bug the inquiry now exists to determine
the cause of the condition which led up to the mis-calculation.

Inquiry itself is an issue tracker system which operates locally via an installed
application, and communicates with a remote Inquiry Server to handle issues.
The Inquiry Server has its own data storage mechanism and runs on Linux
servers.  Overall is is simple and maintains a simple workflow:

(1)  A list of issues, each is called an "inquiry".

(2)  Each inquiry has:
		(a)  Title
		(b)  Description
		(c)  Status
		(d)  Priority
		(e)  Reported (version or date)
		(f)  Target (version or date)
		(g)  Reported by (the logged in user who reported it).

(3)  Each inquiry can have as many comments as are needed.

The codes used for status, priority, reported, and target, are all text-based
and can be created custom for any application.  Comments are raw text, sequentially
numbered and can be edited.  They can contain custom formatting in text form to
be passed out to third party applications for additional display features.

All changes log change histories.  The change histories can be requested and are
retrieved in datetime order.  The message system for communicating with the server
follows a simple protocol.

The local application can assign colors to codes making it a very pleasing
visual experience.

Small.  Fast.  Tight.  Efficient.  And immediate installation of Inquiry Server
with no complex setup.  The sys admin edits two text files on the server to
create applications and users.

Interface:
	inquiry_get_applications 				// Retrieves all applications being maintained by the Inquiry Server (no authentication required)

	inquiry_login							// Requires user name, password, and the application token
	inquiry_logout							// Logs out of a session

	inquiry_get_status_list					// Retrieves full list of statuses for this application
	inquiry_get_priority_list				// Retrieves full list of priorities for this application
	inquiry_get_reported_list				// Retrieves full list of reported texts for this application
	inquiry_get_target_list					// Retrieves full list of target texts for this application

	inquiry_get_by_date						// Retrieves full inquiry list of all records equal to or newer than the date and time
	inquiry_get_by_status					// Retrieves full inquiry list of all records matching the status
	inquiry_get_by_priority					// Retrieves full inquiry list of all records matching the priority
	inquiry_get_by_reported					// Retrieves full inquiry list of all records matching the reported (typically a version or date)
	inquiry_get_by_target					// Retrieves full inquiry list of all records matching the target (typically a version or date)

	inquiry_get_description					// Descriptions vary in length and are retrieved separately
	inquiry_get_comment						// Comments vary in length and are retrieved separately

	inquiry_update_title					// Updates the title, creates a change history log
	inquiry_update_description				// Updates the description, creates a change history log
	inquiry_update_comment					// Updates the comment, creates a change history log
	inquiry_update_status					// Updates the status, creates a change history log
	inquiry_update_priority					// Updates the priority, creates a change history log
	inquiry_update_release					// Updates the release, creates a change history log

	inquiry_add								// Add a new inquiry
	inquiry_add_comment						// Add a new comment to an inquiry

	inquiry_get_change_history				// Retrieves the change history for all changes made to title, status, priority, reported, or target
	inquiry_get_change_history_description	// Retrieves the description change history for the inquiry
	inquiry_get_change_history_comment		// Retrieves the comment change history for the inquiry and comment number

	inquiry_check_status					// Returns the status of the indicated requestId, either -1 timed out, 0 no response, or >= 1 Mail ID
	inquiry_get_mail						// Retrieves prepared text mail sent from the server


Best regards,
Rick C. Hodgin
