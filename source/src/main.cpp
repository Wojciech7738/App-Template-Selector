#include <iostream>
#include "../include/Controllers/TemplateSelectorController.h"
#include "../include/Models/TemplateSelectorModel.h"
#include "../include/Views/TemplateSelectorView.h"


int main(int argc, char** argv) {
    TemplateSelectorModel* model = new TemplateSelectorModel;
    TemplateSelectorView* view = new TemplateSelectorView;
    TemplateSelectorController* controller = new TemplateSelectorController(model, view);

    std::cout << "Done.\n";

    delete controller;
    delete view;
    delete model;
}