
#ifndef TEXT_OBJECT1_H_
#define TEXT_OBJECT1_H_

#include "commonFunction.h"
#include "baseFunction.h"

class textObj {

public:
	textObj();
	~textObj();

	enum textColor {
		RED_TEXT = 0,
		WHITE_TEXT = 1,
		BLACK_TEXT = 2,
	};

	bool LoadFile(std::string path);
	bool LoadFromRenderText(TTF_Font* font, SDL_Renderer* screen);
	void Free();
	void setColor(Uint8 red, Uint8 green, Uint8 blue);
	void setColor(int type);

	void RenderText(SDL_Renderer* screen,
					int xp, int  ypos,
					SDL_Rect* clip = NULL,
					double angle = 0.0,
					SDL_Point* center = NULL,
					SDL_RendererFlip flip = SDL_FLIP_NONE);
	int GetWidth() const { return width_; }
	int GetHeight() const { return height_; }

	void setText(const std::string& text) { str_val_ = text; }
	std::string GetText() const { return str_val_; }

	void SetRect(const int& x, const int& y) {rect_.x =x, rect_.y =y;}
	SDL_Rect GetRect() const {return rect_;}

private:
	std::string str_val_;
	SDL_Color text_color_;
	SDL_Texture* texture_;
	int width_;
	int height_;
	SDL_Rect rect_;
};

#endif // TEXT_OBJECT_H_
