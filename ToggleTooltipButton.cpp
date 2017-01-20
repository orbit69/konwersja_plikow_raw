#include "ToggleTooltipButton.h"

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