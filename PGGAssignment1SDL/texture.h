#pragma once
#ifndef TEXTURE_H
#define TEXTURE_H

#include <SDL.h>
#include <string>
#include <iostream>

/**
@brief Creates a Texture for use with a renderer 
Creates a Texture from an image file, this can then be used with a renderer.
*/
class Texture
{
private:
	/**The Texture data*/
	SDL_Texture* textureData;
	/**The dimensions of the Texture*/
	int textureWidth;
	int textureHeight;
public:
	/**
	Constructs a Texture
	Creates a Texture using an image location and a renderer. The magenta pixels of this image can
	represent alpha if needed.
	@param std::string The location of the image file.
	@param SDL_Renderer* The renderer.
	@param bool If true any magenta pixels in the image will be converted to alpha
	*/
	Texture(std::string, SDL_Renderer*, bool);

	/**
	De-constructs a Texture
	De-constructs the Texture deleting the Texture from memory.
	*/
	~Texture();

	/**
	Getter # Returns a pointer to the Texture
	@returns a pointer to the Texture data.
	*/
	SDL_Texture* getTexture();

	/**
	Getter # Returns textureWidth
	@returns the value of textureWidth.
	*/
	int getWidth();

	/**
	Getter # Returns textureHeight
	@returns the value of textureHeight.
	*/
	int getHeight();

	/**
	Pushes the image to the Renderer, to the XY Coordinates.
	@param SDL_Renderer* The renderer.
	@param int x coordinate of the image.
	@param int y coordinate of the image.
	*/
	void pushToScreen(SDL_Renderer*, int, int);

	/**
	Pushes the image to the Renderer, to the XY Coordinates. This is scaled to the width and height
	inputed.
	@param SDL_Renderer* The renderer.
	@param int x coordinate of the image.
	@param int y coordinate of the image.
	@param int width of the scaled image.
	@param int height of the scaled image.
	*/
	void pushToScreen(SDL_Renderer*, int, int, int, int);

	/**
	Pushes the image to the Renderer, to the XY Coordinates. Only displays the source rectangle inputed.
	@param SDL_Renderer* The renderer.
	@param int x coordinate of the image.
	@param int y coordinate of the image.
	@param int x coordinate of the source image.
	@param int y coordinate of the source image.
	@param int width of the source image.
	@param int height of the source image.
	*/
	void pushSpriteToScreen(SDL_Renderer*, int, int, int, int, int, int);

	/**
	Pushes the image to the Renderer, to the XY Coordinates. Only displays the source rectangle inputed.
	This is scaled to the width and height inputed.
	@param SDL_Renderer* The renderer.
	@param int x coordinate of the image.
	@param int y coordinate of the image.
	@param int x coordinate of the source image.
	@param int y coordinate of the source image.
	@param int width of the source image.
	@param int height of the source image.
	@param int width of the scaled image.
	@param int height of the scaled image.
	*/
	void pushSpriteToScreen(SDL_Renderer*, int, int, int, int, int, int, int, int);
};
#endif