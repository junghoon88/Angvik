#include "stdafx.h"
#include "monkkey.h"


monkkey::monkkey()
{
}


monkkey::~monkkey()
{

}
void monkkey::init(float x, float y) {

	spt = IMAGEMANAGER->findImage(L"¿ø¼þÀÌ");

	life = 1;
	ptX = x;
	ptY = y;


}
void monkkey::update(void) {



}
void monkkey::render(void) {

	//IMAGEMANAGER->findImage(L"¿ø¼þÀÌ")->frameRender()


}
void monkkey::move(void) {



}
void monkkey::attack(void) {



}