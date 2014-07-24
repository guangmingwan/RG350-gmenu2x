#include <string>

#include "dialog.h"
#include "gmenu2x.h"
#include "font.h"

Dialog::Dialog(GMenu2X *gmenu2x) : gmenu2x(gmenu2x)
{
}

void Dialog::drawTitleIcon(const std::string &icon, bool skinRes, Surface *s)
{
	if (s==NULL)
		s = gmenu2x->s;

	Surface *i = NULL;
	if (!icon.empty()) {
		if (skinRes)
			i = gmenu2x->sc.skinRes(icon);
		else
			i = gmenu2x->sc[icon];
	}

	if (i==NULL)
		i = gmenu2x->sc.skinRes("icons/generic.png");

	i->blit(s,4,(gmenu2x->skinConfInt["topBarHeight"]-32)/2);
}

void Dialog::writeTitle(const std::string &title, Surface *s)
{
	if (s==NULL)
		s = gmenu2x->s;
	s->write(gmenu2x->font, title, 40, 0, Font::HAlignLeft, Font::VAlignTop);
}

void Dialog::writeSubTitle(const std::string &subtitle, Surface *s)
{
	if (s==NULL)
		s = gmenu2x->s;
	std::string wrapped = gmenu2x->font->wordWrap(subtitle, gmenu2x->resX - 48);
	s->write(gmenu2x->font, wrapped, 40, gmenu2x->skinConfInt["topBarHeight"] - gmenu2x->font->getTextHeight(wrapped), Font::HAlignLeft, Font::VAlignTop);
}


