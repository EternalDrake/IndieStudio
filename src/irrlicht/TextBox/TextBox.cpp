/*
** EPITECH PROJECT, 2019
** IndieStudio
** File description:
** TextBox.cpp
*/

#include <iostream>
#include "TextBox.hpp"

Irrlicht::TextBox::TextBox(ECS::Point pos, ECS::Vector4<int> size, unsigned id, irr::gui::IGUIEnvironment *guienv, std::string text) :
    id(id),
    _pos({0, 0}),
    _size(size),
    _guienv(guienv),
    _visible(true)
{
    wchar_t *val = reinterpret_cast<wchar_t *>(malloc(sizeof(*val) * (text.size() + 1)));

    for (size_t i = 0; i < text.size(); i++)
        val[i] = text[i];
    val[text.size()] = 0;
    if (!text.empty()) {
        this->_text = text;
        this->_textBox = this->_guienv->addButton(irr::core::rect<irr::s32>(_size.a, _size.b, _size.c, _size.d), 0, this->id, val);
        this->setPos(pos);
        return;
    }
    free(val);
    this->_textBox = this->_guienv->addButton(irr::core::rect<irr::s32>(_size.a, _size.b, _size.c, _size.d), 0, this->id);
    this->setPos(pos);
}

const std::string &Irrlicht::TextBox::getText()
{
    return this->_text;
}

const ECS::Point &Irrlicht::TextBox::getPos()
{
    return this->_pos;
}

const ECS::Vector4<int> &Irrlicht::TextBox::getSize()
{
    return this->_size;
}

void Irrlicht::TextBox::setText(std::string text)
{
    delete this->_button;
    this->_text = text;
    if (!text.empty()) {
        this->_button = this->_guienv->addButton(
                irr::core::rect<irr::s32>(_size.a, _size.b, _size.c, _size.d), 0, this->id,
                reinterpret_cast<const wchar_t *>(&this->_text));
        setPos(this->_pos);
        return;
    }
    this->_textBox = this->_guienv->addStaticText(this->_text, irr::core::rect<irr::s32>(_size.a, _size.b, _size.c, _size.d), 0, this->id);
    setPos(this->_pos);
}

void Irrlicht::TextBox::setPos(ECS::Point pos)
{

    if (pos.x != _pos.x && pos.y != _pos.y) {
        this->_pos = pos;
        this->_button->setRelativePosition(irr::core::position2di((int)_pos.x, (int)_pos.y));
    }
}

void Irrlicht::TextBox::setSize(ECS::Vector4<int> size)
{
    delete this->_button;
    if (size.a != _size.a && size.b != _size.b && size.c != _size.c && size.d && _size.d) {
        this->_size = size;
        this->_button = this->_guienv->addButton(
                irr::core::rect<irr::s32>(_size.a, _size.b, _size.c, _size.d), 0, this->id,
                reinterpret_cast<const wchar_t *>(&this->_text));
        setPos(this->_pos);
        return;
    }
}

bool Irrlicht::TextBox::isPressed()
{
    return this->_button->isPressed();
}

void Irrlicht::TextBox::setVisible(bool visible)
{
	if (this->_visible == visible)
		return;
	this->_visible = visible;
	this->_button->setVisible(visible);
}

Irrlicht::TextBox::~Button() = default;
