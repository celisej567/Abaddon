#include "confirm.hpp"

ConfirmDialog::ConfirmDialog(Gtk::Window &parent)
    : Gtk::Dialog("Confirm", parent, true)
    , m_layout(Gtk::ORIENTATION_VERTICAL)
    , m_bbox(Gtk::ORIENTATION_HORIZONTAL)
    , m_ok("OK")
    , m_cancel("Cancel") {
    set_default_size(300, 50);
    get_style_context()->add_class("app-window");

    m_label.set_text("Are you sure?");

    m_ok.signal_clicked().connect([&]() {
        response(Gtk::RESPONSE_OK);
    });

    m_cancel.signal_clicked().connect([&]() {
        response(Gtk::RESPONSE_CANCEL);
    });

    m_bbox.pack_start(m_ok, Gtk::PACK_SHRINK);
    m_bbox.pack_start(m_cancel, Gtk::PACK_SHRINK);
    m_bbox.set_layout(Gtk::BUTTONBOX_END);

    m_layout.add(m_label);
    m_layout.add(m_bbox);
    get_content_area()->add(m_layout);

    show_all_children();
}

void ConfirmDialog::SetConfirmText(const Glib::ustring &text) {
    m_label.set_text(text);
}
