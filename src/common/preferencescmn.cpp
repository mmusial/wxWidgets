///////////////////////////////////////////////////////////////////////////////
// Name:        src/common/preferencescmn.cpp
// Purpose:     wxPreferencesEditor implementation common to all platforms.
// Author:      Vaclav Slavik
// Created:     2013-02-19
// RCS-ID:      $Id$
// Copyright:   (c) 2013 Vaclav Slavik <vslavik@fastmail.fm>
// Licence:     wxWindows licence
///////////////////////////////////////////////////////////////////////////////

// ============================================================================
// declarations
// ============================================================================

// ----------------------------------------------------------------------------
// headers
// ----------------------------------------------------------------------------

// for compilers that support precompilation, includes "wx.h".
#include "wx/wxprec.h"

#ifdef __BORLANDC__
    #pragma hdrstop
#endif

#include "wx/private/preferences.h"
#include "wx/intl.h"

// ============================================================================
// implementation
// ============================================================================

wxString wxStockPreferencesPage::GetName() const
{
    switch ( m_kind )
    {
        case Kind_General:
            return _("General");
        case Kind_Advanced:
            return _("Advanced");
    }
    return wxString(); // silence compiler warning
}

wxPreferencesEditor::wxPreferencesEditor()
    : m_impl(wxPreferencesEditorImpl::Create())
{
}

wxPreferencesEditor::~wxPreferencesEditor()
{
    delete m_impl;
}

void wxPreferencesEditor::AddPage(wxPreferencesPage* page)
{
    wxCHECK_RET( page, "can't set NULL page" );
    m_impl->AddPage(page);
}

void wxPreferencesEditor::Show(wxWindow* parent)
{
    m_impl->Show(parent);
}

void wxPreferencesEditor::Dismiss()
{
    m_impl->Dismiss();
}
