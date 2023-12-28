from Controller import Controller
from Model import Model
from View import View

def Main():
    model = Model()
    view = View()
    controller = Controller(view, model)
    controller.build_app("Basic app", "500x500")
    controller.run()

if __name__ == "__main__":
    Main()
