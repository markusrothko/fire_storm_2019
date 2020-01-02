#include "Scene0.h"
#include "Button.h"
#include <string>
#include "System.h"
#include <SDL_image.h>
#include "Sprite.h"
#include <SDL.h>
#include "GameEngine.h"
#include "SceneMenu.h"
#include <iostream>
namespace fs19 {


	Scene0::~Scene0() {

	}

	void Scene0::populateSpriteList() {
		
	}

	class NewGameButton : public Button {
	public:
		NewGameButton() :Button(100, 100, 100, 50, "New Game") {}


		void perform(Button* source) {
			Scene* sm = new SceneMenu();
			int currentSize = ge.size();


			
			for (Sprite* s : sm->getSpriteList()) {
				ge.add(s);
				
			}
			ge.remove(0, currentSize - 1);

		}
	};
	class Background : public Sprite {
	public:
		//remove hardcoded size later
		Background(std::string s) :Sprite(0, 0, 800, 600) {
			texture = IMG_LoadTexture(sys.get_ren(), s.c_str());
		}
		void draw() const {
			SDL_RenderCopy(sys.get_ren(), texture, NULL, &getRect());

		}
	private:
		SDL_Texture* texture;


	};



	//Moved constructor down so the encapsulated classes
	//could be reached.

	Scene0::Scene0() {



		addSprites(new Background("background.png"));
		addSprites(new NewGameButton());


	}
}

