#include "../../include/Controllers/TemplateSelectorController.h"
#include "../../include/Views/TemplateSelectorView.h"
#include "../../include/Models/TemplateSelectorModel.h"

TemplateSelectorController::TemplateSelectorController(TemplateSelectorModel* _model, TemplateSelectorView* _view)
{
    TemplateSelectorController::model = _model;
    TemplateSelectorController::view = _view;
}

TemplateSelectorController::~TemplateSelectorController()
{

}