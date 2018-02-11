const { on } = require("./utils/socketHandler");
const Animal = require("./utils/Animal");
const { init } = require("./utils/initializer");

class Playground {
  constructor(ctx) {
    this.ctx = ctx;
  }

  pee(x, y) {}
}

const { ctx, canvas, animalsCtx, animalsCanvas } = init();

let animals = [];
const Playground = new Playground(ctx);
function show() {
  animalsCtx.clearRect(0, 0, canvas.width, canvas.height);
  animalsCtx.drawImage(canvas, 0, 0);
  animals.forEach(animal => animal.show());
}

function findAnimal(name) {
  return animals.find(animal => animal.name === name);
}

on("newAnimal", newAnimal => {
  animals = [...animals, new Animal(newAnimal, animalsCtx)];
});

on("peeing", action => {
  const { name } = action;
  const animal = findAnimal(name);
  animal.pee();
});

on("move", move => {
  const { name, x, y } = move;
  const animal = findAnimal(name);
  animal.move(x, y);
});

function loop() {
  show();
  window.requestAnimationFrame(loop);
}
loop();
