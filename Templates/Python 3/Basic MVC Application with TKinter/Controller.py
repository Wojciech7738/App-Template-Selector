from Model import Model
from View import View

class Controller:
    def __init__(self, view_instance: View, model_instance: Model):
        self.view = view_instance
        self.model = model_instance

    def build_app(self, size: str, window_name: str) -> None:
        self.view.create_window(size, window_name)

    def run() -> None:
        self.view.mainloop()

