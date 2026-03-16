#include <Geode/Geode.hpp> 
#include <Geode/modify/PauseLayer.hpp>
#include <Geode/ui/GeodeUI.hpp> 

using namespace geode::prelude;

// fun fact: i was timed out of the geode-sdk  server because i was too "anti-semitic"
// idfk i just said ".... Call me a jew but..." you decide yourself and idk if i should have 
// said that. I love Israel (Now if you want to read more pls (idfk.txt) ) Anyways, Src code - 
class $modify(MyPauseLayer, PauseLayer) {
    void customSetup() override {
        PauseLayer::customSetup();

        auto rightButtonMenu = this->getChildByID("right-button-menu");
        if (!rightButtonMenu) return;

        auto infoIconSpr = CCSprite::create("keybindsButton.png"_spr);
    
        auto infoBtn = CCMenuItemSpriteExtra::create(
            infoIconSpr,
            this,
            menu_selector(MyPauseLayer::openPopup)
        );
        
        infoBtn->setID("modify-keybinds-button");
        rightButtonMenu->addChild(infoBtn);
        rightButtonMenu->updateLayout();
    }

    void openPopup(CCObject* sender) {
        auto geodeCustomKeybindsMod = Loader::get()->getLoadedMod("geode.custom-keybinds");
        // dont blame me for terribly naming things. 
        
        if (!geodeCustomKeybindsMod) { 
            FLAlertLayer::create("Error", "Custom Keybinds mod not found!", "OK")->show();
        } 
        else {
            geode::openSettingsPopup(geodeCustomKeybindsMod);
        }
    }
};