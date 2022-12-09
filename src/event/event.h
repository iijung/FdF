/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjungk <minjungk@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 00:17:11 by minjungk          #+#    #+#             */
/*   Updated: 2022/12/09 04:49:57 by minjungk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENT_H
# define EVENT_H

/*
 * Reference: X11/X.h
 */
enum e_mask
{
	NoEventMask = 0L,
	KeyPressMask = (1L<<0),
	KeyReleaseMask = (1L<<1),
	ButtonPressMask = (1L<<2),
	ButtonReleaseMask = (1L<<3),
	EnterWindowMask = (1L<<4),
	LeaveWindowMask = (1L<<5),
	PointerMotionMask = (1L<<6),
	PointerMotionHintMask = (1L<<7),
	Button1MotionMask = (1L<<8),
	Button2MotionMask = (1L<<9),
	Button3MotionMask = (1L<<10),
	Button4MotionMask = (1L<<11),
	Button5MotionMask = (1L<<12),
	ButtonMotionMask = (1L<<13),
	KeymapStateMask = (1L<<1),
	ExposureMask = (1L<<15),
	VisibilityChangeMask = (1L<<16),
	StructureNotifyMask = (1L<<17),
	ResizeRedirectMask = (1L<<18),
	SubstructureNotifyMask = (1L<<19),
	SubstructureRedirectMask = (1L<<20),
	FocusChangeMask = (1L<<21),
	PropertyChangeMask = (1L<<22),
	ColormapChangeMask = (1L<<23),
	OwnerGrabButtonMask = (1L<<24)
};

enum e_event
{
	KeyPress = 2,
	KeyRelease = 3,
	ButtonPress = 4,
	ButtonRelease = 5,
	MotionNotify = 6,
	EnterNotify = 7,
	LeaveNotify = 8,
	FocusIn = 9,
	FocusOut = 10,
	KeymapNotify = 11,
	Expose = 12,
	GraphicsExpose = 13,
	NoExpose = 14,
	VisibilityNotify = 15,
	CreateNotify = 16,
	DestroyNotify = 17,
	UnmapNotify = 18,
	MapNotify = 19,
	MapRequest = 20,
	ReparentNotify = 21,
	ConfigureNotify = 22,
	ConfigureRequest = 23,
	GravityNotify = 24,
	ResizeRequest = 25,
	CirculateNotify = 26,
	CirculateRequest = 27,
	PropertyNotify = 28,
	SelectionClear = 29,
	SelectionRequest = 30,
	SelectionNotify = 31,
	ColormapNotify = 32,
	ClientMessage = 33,
	MappingNotify = 34,
	LASTEvent = 35
};

# ifndef __LINUX__
/*
 * Reference:
 * /Library/Developer/CommandLineTools/SDKs/MacOSX.sdk/System/Library
 * /Frameworks/Carbon.framework/Versions/A
 * /Frameworks/HIToolbox.framework/Versions/A
 * /Headers/Events.h 
 * */
enum e_virtual_keycode
{
	VK_Return = 0x0024,
	VK_Escape = 0x0035,
	VK_Left = 0x007B,
	VK_Up = 0x007E,
	VK_Right = 0x007C,
	VK_Down = 0x007D
};
# else
/*
 * Reference: X11/keysymdef.h
 */
enum e_keycode
{
	VK_Return = 0xFF0D,
	VK_Escape = 0xFF1B,
	VK_Left = 0xFF51,
	VK_Up = 0xFF52,
	VK_Right = 0xFF53,
	VK_Down = 0xFF54
};
# endif

#endif
