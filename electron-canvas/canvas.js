const { on } = require("./utils/socketHandler");
const Animal = require("./utils/Animal");
const { init } = require("./utils/initializer");

class Playground {
  constructor(ctx) {
    this.ctx = ctx;
    this.isPeeing;
    this.isClearing;
  }

  clear(x, y) {}

  pee(x, y) {
    this.ctx.fillStyle = "yellow";
    this.ctx.fillRect(x, y, 150, 80);
  }
}

const { ctx, canvas, animalsCtx, animalsCanvas } = init();

let animals = [];
const playground = new Playground(ctx);

function showPlayground() {
  playground.i;
}

function showAnimals() {
  animalsCtx.clearRect(0, 0, canvas.width, canvas.height);
  animalsCtx.drawImage(canvas, 0, 0);
  animals.forEach(animal => animal.show());
}

function findAnimal(name) {
  return animals.find(animal => animal.name === name);
}

on("newAnimal", newAnimal => {
  animals = [...animals, new Animal(newAnimal, animalsCtx, playground)];
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
  showPlayground();
  showAnimals();
  window.requestAnimationFrame(loop);
}
loop();
