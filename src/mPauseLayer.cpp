#include <Geode/Geode.hpp> 
#include <Geode/modify/PauseLayer.hpp>
#include <Geode/ui/GeodeUI.hpp> 

using namespace geode::prelude;
 
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