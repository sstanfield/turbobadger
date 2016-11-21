// ================================================================================
// ==      This file is a part of Turbo Badger. (C) 2011-2014, Emil Segerås      ==
// ==                     See tb_core.h for more information.                    ==
// ================================================================================

#ifndef TB_INLINE_SELECT_H
#define TB_INLINE_SELECT_H

#include "tb_widgets_listener.h"
#include "tb_select_item.h"
#include "tb_editfield.h"

namespace tb {

/** TBSelectList is a select widget with no popups. Instead it has two
	arrow buttons that cycle between the choices.
	By default it is a number widget.

	FIX: Should also be possible to set a list of strings that will be
		shown instead of numbers.
*/
class TBInlineSelect : public TBWidget
{
public:
	// For safe typecasting
	TBOBJECT_SUBCLASS(TBInlineSelect, TBWidget);

	TBInlineSelect();
	~TBInlineSelect();

	/** Set along which axis the content should layouted. */
	void SetAxis(AXIS axis) override { m_layout.SetAxis(axis); }
	AXIS GetAxis() const override { return m_layout.GetAxis(); }

	void SetLimits(int min, int max);
	int GetMinValue() const { return m_min; }
	int GetMaxValue() const { return m_max; }

	void SetValue(int value) override { SetValueInternal(value, true); }
	int GetValue() override { return m_value; }

	void OnInflate(const INFLATE_INFO &info) override;
	void OnSkinChanged() override;
	bool OnEvent(const TBWidgetEvent &ev) override;
protected:
	TBButton m_buttons[2];
	TBLayout m_layout;
	TBEditField m_editfield;
	int m_value;
	int m_min, m_max;
	void SetValueInternal(int value, bool update_text);
};

} // namespace tb

#endif // TB_INLINE_SELECT_H
