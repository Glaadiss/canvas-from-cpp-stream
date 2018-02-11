const { on } = require("./utils/socketHandler");
const Animal = require("./utils/Animal");
const Playground = require("./utils/Playground");
const { init } = require("./utils/initializer");

const { ctx, canvas, animalsCtx, animalsCanvas } = init();

let animals = [];
const playground = new Playground(ctx);

function showPlayground() {
  playground.ctx.fill();
}

function showAnimals() {
  animalsCtx.clearRect(0, 0, canvas.width, canvas.height);
  animals.forEach(animal => animal.show());
}

function findAnimal(name) {
  return animals.find(animal => animal.name === name);
}

on("newAnimal", newAnimal => {
  newAnimal.action = "PEE";
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

let executeTime = 0;
function loop() {
  executeTime++;
  if (executeTime > 1) {
    showPlayground();
    showAnimals();
    executeTime = 0;
  }
  window.requestAnimationFrame(loop);
}
loop();
