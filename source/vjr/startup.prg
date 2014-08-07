*
*	(| round cask |)		(|| round cask with parameters ||)
*	
*	[| square cask |)		[|| square cask with parameters ||)
*	
*	<| triangle cask |>		<|| triangle cask with parameters ||>
*	
*	~| tilde cask |~		~|| tilde cask with parameters ||~
*
*	
**********
*
* /libsf/source/vjr/startup.prg
*
*****
* Version 0.20
* Copyright (c) 2014 by Rick C. Hodgin
*****
* Last update:
*     Jun.17.2014
*****
* Change log:
*     Jul.13.2014 - Modification to work with the early processing engine
*     Jun.17.2014 - Initial creation and design
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
*     http:*www.visual-freepro.org/vjr/indexmain.html
*     http:*www.visual-freepro.org/wiki/index.php/PBL
*     http:*www.visual-freepro.org/wiki/index.php/Repeat_License
*
* Thank you.  And may The Lord bless you richly as you lift up your life, your
* talents, your gifts, your praise, unto Him.  In Jesus' name I pray.  Amen.
*
*




**********
* Create _screen and _jdebi
*****
	_screen			= CREATEOBJECT("form")
	_jdebi			= CREATEOBJECT("form")
	_screen.name	= "_screen"
	_jdebi.name		= "_jdebi"


**********
* Set the screen defaults
*****
	* Set colors
	_screen.BackColor	= RGB(255,255,255)
	_screen.ForeColor	= RGB(0,0,0)
	_screen.NwColor		= RGB(222, 230, 255)
	_screen.NeColor		= RGB(157, 194, 214)
	_screen.SwColor		= RGB(255, 255, 255)
	_screen.SeColor		= RGB(192, 212, 255)
	lcVersion			= VERSION(4)
	_screen.Caption		= CONCATENATE("Visual FreePro, Jr.", lcVersion)
	
	* Position _screen
	lnValue1			= SYSMETRIC(1)
	lnValue1			= DIV(lnValue1, 8)
	lnValue2			= SYSMETRIC(2)
	lnValue28			= DIV(lnValue2, 8)
	lnMin				= MIN(lnValue1, lnValue2)
	
	_screen.Left		= lnMin
	_screen.Top			= lnMin
	
	lnValue1			= SYSMETRIC(1)
	lnValue1			= DIV(lnValue1, 2)			&& lnValue1 / 2
	_screen.Width		= SUB(lnValue1, lnMin)		&& lnValue1 - lnMin
	
	lnValue1			= SYSMETRIC(2)
	lnValue2			= MUL(2, lnMin)				&& 2 * lnMin
	_screen.Height		= SUB(lnValue1, lnValue2)	&& SYSMETRIC(2) - (2 * lnMin)
	
	_screen.Visible		= .T.




**********
* Set the JDebi Debugger defaults
*****
	* Set colors
	_jdebi.BackColor	= RGB(255,255,255)
	_jdebi.ForeColor	= RGB(0,0,0)
	_jdebi.NwColor		= RGB(222, 230, 255)
	_jdebi.NeColor		= RGB(157, 194, 214)
	_jdebi.SwColor		= RGB(255, 255, 255)
	_jdebi.SeColor		= RGB(192, 212, 255)
	_jdebi.Caption		= CONCATENATE("JDebi Debugger -- ", lcVersion)
	
	* Position screen
	lnMin				= MIN(SYSMETRIC(1) / 8, SYSMETRIC(2) / 8)
	_jdebi.Left			= SYSMETRIC(1) / 2
	_jdebi.Top			= lnMin
	_jdebi.Width		= (SYSMETRIC(1) / 2) - lnMin
	_jdebi.Height		= SYSMETRIC(2) - (2 * lnMin)
	
	
	* Position and size sourceCode
	ADDOBJECT(_jdebi, "sourceCode", "subform")
	_jdebi.sourceCode.Left		= 0
	_jdebi.sourceCode.Top		= 0
	lnValue1					= MUL(0.8, _jdebi.width)
	_jdebi.sourceCode.Width		= INT(lnValue1)
	lnValue1					= MUL(0.6, _jdebi.height)
	_jdebi.sourceCode.Height	= INT(lnValue1)
				
	* Make it visible
	_jdebi.sourceCode.Visible	= .T.

	
	* Position and size sourceLight
	ADDOBJECT(_jdebi, "sourceLight", "subform")
	_jdebi.sourceLight.Left		= _jdebi.sourceCode.Width
	_jdebi.sourceLight.Top		= 0
	_jdebi.sourceLight.Width	= SUB(_jdebi.Width, _jdebi.sourceCode.Width)
	_jdebi.sourceLight.Height	= _jdebi.sourceCode.Height
				
	* Add the index portion
	ADDOBJECT(_jdebi.sourceLight, "index", "subform")
	lnValue1							= MUL(0.8, _jdebi.sourceLight.Height)
	_jdebi.sourceLight.index.Top		= INT(lnValue1)
	_jdebi.sourceLight.index.Width		= _jdebi.sourceLight.Width
	_jdebi.sourceLight.index.Height		= SUB(_jdebi.sourceLight.Height, _jdebi.sourceLight.index.Top)
	_jdebi.sourceLight.index.Visible	= .T.
	_jdebi.sourceLight.Visible			= .T.
	
	
	* Position and size locals
	ADDOBJECT(_jdebi, "locals", "subform")
	_jdebi.locals.Left		= 0
	_jdebi.locals.Top		= _jdebi.sourceCode.Height
	_jdebi.locals.Width		= _jdebi.sourceCode.Width
	lnValue1				= SUB(_jdebi.Height, _jdebi.sourceCode.Height)
	_jdebi.locals.Height	= DIV(lnValue1, 2)
	.Visible	= .T.
		
		
	* Position and size watch
	ADDOBJECT(_jdebi, "watch", "subform")
	_jdebi.watch.Left		= 0
	_jdebi.watch.Top		= _jdebi.locals.Top + _jdebi.locals.Height
	_jdebi.watch.Width		= _jdebi.sourceCode.Width
	lnValue1				= SUB(_jdebi.Height, _jdebi.sourceCode.Height)
	_jdebi.watch.Height		= DIV(lnValue1, 2)
	.Visible	= .T.
		
		
	* Position and size debug
	ADDOBJECT(_jdebi, "debug", "subform")
	_jdebi.debug.Left		= _jDebi.sourceCode.Width
	_jdebi.debug.Top		= _jDebi.watchWindow.Top
	_jdebi.debug.Width		= _jdebi.sourceLight.Width
	lnValue1				= SUB(_jdebi.Height, _jdebi.sourceCode.Height)
	lnValue2				= MUL(0.3, lnValue1)
	_jdebi.debug.Height		= INT(lnValue2)
	_jdebi.debug.Visible	= .T.
		
		
	* Position and size command
	ADDOBJECT(_jdebi, "command", "subform")
	_jdebi.command.Left		= 0
	_jdebi.command.Top		= ADD(_jdebi.watchWindow.Top, _jdebi.watchWindow.Height)
	_jdebi.command.Width	= _jdebi.watchWindow.Width
	_jdebi.command.Height	= SUB(_jdebi.Height, _jdebi.command.Top)
	_jdebi.command.Visible	= .T.
		
		
	* Position and size output
	ADDOBJECT(_jdebi, "output", "subform")
	_jdebi.output.Left		= _jDebi.sourceCode.Width
	_jdebi.output.Top		= ADD(_jDebi.debugging.Top, _jDebi.debugging.Height)
	_jdebi.output.Width		= _jdebi.debugging.Width
	_jdebi.output.Height	= _jdebi.Height - .Top
	_jdebi.output.Visible	= .T.
		

	* Make JDebi visible
	_jdebi.Visible			= .T.
