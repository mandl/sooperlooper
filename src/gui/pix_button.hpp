/*
** Copyright (C) 2004 Jesse Chappell <jesse@essej.net>
**  
** This program is free software; you can redistribute it and/or modify
** it under the terms of the GNU General Public License as published by
** the Free Software Foundation; either version 2 of the License, or
** (at your option) any later version.
**  
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
**  
** You should have received a copy of the GNU General Public License
** along with this program; if not, write to the Free Software
** Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
**  
*/

#ifndef __sooperlooper_gui_pix_button__
#define __sooperlooper_gui_pix_button__


#include <wx/wx.h>


#include <sigc++/sigc++.h>


namespace SooperLooperGui {


class PixButton
	: public wxWindow
{
  public:
	
	// ctor(s)
	PixButton(wxWindow * parent, wxWindowID id=-1,  const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize);
	virtual ~PixButton();


	void set_normal_bitmap (const wxBitmap & bm);
	void set_focus_bitmap (const wxBitmap & bm);
	void set_selected_bitmap (const wxBitmap & bm);
	void set_disabled_bitmap (const wxBitmap & bm);

	wxBitmap & get_normal_bitmap() { return _normal_bitmap;}
	wxBitmap & get_focus_bitmap() { return _focus_bitmap; }
	wxBitmap & get_selected_bitmap() { return _selected_bitmap; }
	wxBitmap & get_disabled_bitmap() { return _disabled_bitmap; }


	void set_bg_color (const wxColour & col);
	wxColour & get_bg_color () { return _bgcolor; }
	
	SigC::Signal0<void> pressed;
	SigC::Signal0<void> released;
	SigC::Signal0<void> clicked;
	SigC::Signal0<void> enter;
	SigC::Signal0<void> leave;
	
  protected:

	enum ButtonState {
		Normal,
		Selected,
		Disabled
	};

	enum EnterState {
		Inside,
		Outside
	};
	
	void OnPaint (wxPaintEvent &ev);
	void OnSize (wxSizeEvent &ev);
	void OnMouseEvents (wxMouseEvent &ev);

	void draw_area (wxDC & dc);
	
	wxBitmap _normal_bitmap;
	wxBitmap _focus_bitmap;
	wxBitmap _selected_bitmap;
	wxBitmap _disabled_bitmap;

	ButtonState _bstate;
	EnterState _estate;

	int _width, _height;
	
	wxColour _bgcolor;
	wxBrush  _bgbrush;

  private:
    // any class wishing to process wxWindows events must use this macro
    DECLARE_EVENT_TABLE()
	
};


};


#endif
