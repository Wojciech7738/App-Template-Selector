import tkinter as tk
from Model import Model

class View(tk.Tk):
    def __init__(self, model_instance: Model) -> None:
        super().__init__()
        self.model = model_instance

    def get_width_height(size: str) -> tuple:
        try:
            width, height = map(int, size.split('x'))
        except Exception as e:
            raise e
        return (width, height)

    def create_window(self, size: str, window_name: str) -> None:
        width, height = self.get_width_height(size)
        self.title(window_name)
        self.geometry(f"{width}x{height}")
        button = tk.Button(self, text="Button", command=self.model.button_click)
        button.pack()
