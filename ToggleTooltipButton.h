#pragma once

#include <wx/button.h>
#include <wx/tglbtn.h>
#include <wx/tooltip.h>

class ToggleTooltipButton : public wxToggleButton {
public:
	ToggleTooltipButton(wxWindow* parent, wxWindowID id, wxString& tooltipText, const wxString& label = wxEmptyString,
		const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxDefaultSize,
		long style = 0, const wxValidator& validator = wxDefaultValidator,
		const wxString& name = "button") : wxToggleButton(parent, id, label,
			pos, size, style, validator, name)
	{
		wxToolTip * tooltip = new wxToolTip(tooltipText);
		tooltip->Enable(false);
		tooltip->SetDelay(1);
		SetToolTip(tooltip);
	}

private:
	DECLARE_EVENT_TABLE()

	void OnMouseEnter(wxMouseEvent & event);
	void OnMouseLeave(wxMouseEvent & event);
};

BEGIN_EVENT_TABLE(ToggleTooltipButton, wxToggleButton)
	EVT_ENTER_WINDOW(ToggleTooltipButton::OnMouseEnter)
	EVT_LEAVE_WINDOW(ToggleTooltipButton::OnMouseLeave)
END_EVENT_TABLE()

void ToggleTooltipButton::OnMouseEnter(wxMouseEvent & event) {
	wxToolTip * tooltip = GetToolTip();
	tooltip->Enable(true);
}

void ToggleTooltipButton::OnMouseLeave(wxMouseEvent & event) {
	wxToolTip * tooltip = GetToolTip();
	tooltip->Enable(false);
}