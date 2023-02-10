#include <SkyrimScripting/Plugin.h>

struct WhatDidILearn : public RE::BSTEventSink<RE::SpellsLearned::Event> {
    RE::BSEventNotifyControl ProcessEvent(const RE::SpellsLearned::Event* event,
                                          RE::BSTEventSource<RE::SpellsLearned::Event>*) {
        logger::info("Learned something?");
        if (!event) {
            logger::info("Huh. The event, itself, was a nullptr. Huh. Weird.");
            return RE::BSEventNotifyControl::kContinue;
        }
        if (!event->spell) {
            logger::info("Huh. The spell is nullptr. Weird.");
            return RE::BSEventNotifyControl::kContinue;
        }
        logger::info("Form ID learned: ", event->spell->GetFormID());
        logger::info("Editor ID learned: ", event->spell->GetFormEditorID());
        logger::info("Name of learned: ", event->spell->GetFullName());
        return RE::BSEventNotifyControl::kContinue;
    }
};

OnInit { RE::SpellsLearned::GetEventSource()->AddEventSink(new WhatDidILearn()); }
