const { on } = require("./utils/socketHandler");
const Animal = require("./utils/Animal");
const Playground = require("./utils/Playground");
const { init } = require("./utils/initializer");
const { loop } = require("./utils/loop");

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
  animals = [...animals, new Animal(newAnimal, animalsCtx, playground)];
});

on("special", action => {
  const { name, type } = action;
  const animal = findAnimal(name);
  if (animal)
    switch (type) {
      case "dog":
        animal.pee();
        break;
      case "cat":
        // DO WHAT CATS DO!
        break;
      case "rabbit":
        // DO WHAT CATS DO!
        break;
      default:
        console.log("WEIRD TYPE OF ANIMAL!" + type)
    }
  else
    console.log(`animal of name ${name} not found! can't do special action`)
});

on("move", move => {
  const { name, x, y } = move;
  const animal = findAnimal(name);
  if (animal)
    animal.move(x, y);
  else
    console.log(`animal of name ${name} not found! can't move`)
});

let executeTime = 0;

/* function loop() {
  executeTime++;
  if (executeTime > 1) {
    showPlayground();
    showAnimals();
    executeTime = 0;
  }
  window.requestAnimationFrame(loop);
} */

loop(function() {
  showPlayground();
  showAnimals();
}, 60);