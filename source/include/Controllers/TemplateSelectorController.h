#ifndef TEMPLATESELECTORCONTROLLER_H
#define TEMPLATESELECTORCONTROLLER_H

#pragma once

#include "../Views/TemplateSelectorView.h"
#include "../Models/TemplateSelectorModel.h"

class TemplateSelectorController
{
public:
    TemplateSelectorModel* model;
    TemplateSelectorView* view;
    TemplateSelectorController(TemplateSelectorModel* model, TemplateSelectorView* view);
    ~TemplateSelectorController();

private:

};

#endif