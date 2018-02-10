class Animal {
  constructor({ name, type, x, y, action = null }) {
    this.name = name;
    this.type = type;
    this.x = x;
    this.y = y;
    this.action = action;
    console.log(`New ${this.type} named ${this.name} created! Hurra!`);
  }

  move(dstX, dstY) {
    console.log(
      `Moving animal ${this.name} to new destination: x ${dstX} y ${dstY}`
    );
    this.x = dstX;
    this.y = dstY;
  }

  show() {
    ctx.fillText(this.type + " " + this.name, this.x, this.y);
  }
}

function init() {
  const canvas = document.getElementById("playground");
  canvas.width = window.innerWidth;
  canvas.height = window.innerHeight;
  const ctx = canvas.getContext("2d");
  const fillStyle = "red";
  ctx.fillStyle = fillStyle;
  ctx.font = "20px serif";
  return { ctx, canvas };
}

const { ctx, canvas } = init();

let animals = [];

function show() {
  ctx.clearRect(0, 0, canvas.width, canvas.height);
  for (let animal of animals) animal.show();
}

function splitJSON(data) {
  return data.replace("}{", "}#{").split("#");
}

function executeAction(desiredEventName, callback, data) {
  const { eventName, eventData } = JSON.parse(data);
  console.log(`received event: ${eventName} with data: ${eventData}`);
  if (eventName === desiredEventName) callback(eventData);
}

function spawnBackend() {
  const { spawn } = require("child_process");
  const backend = spawn("../backend/cmake-build-debug/backend");

  const on = (desiredEventName, callback) =>
    backend.stdout.on("data", data =>
      splitJSON(data).map(obj => executeAction(desiredEventName, callback, obj))
    );

  /* backend.stdout.on("data", data => {
    const obj = JSON.parse(data);
    const { x, y, height, width } = obj;
    ctx.clearRect(0, 0, canvas.width, canvas.height);
    ctx.fillRect(x, y, height, width);
  }); */

  on("newAnimal", newAnimal => {
    console.log(newAnimal);
    animals.push(new Animal(newAnimal));
  });

  on("move", move => {
    const { name, x, y } = move;
    console.log(move + ":");
    console.log(name);
    console.log(x, y);

    const movingAnimal = animals.find(animal => animal.name === name);
    movingAnimal.move(x, y);

    show();
  });

  backend.stdout.on("error", data => {
    console.log(`error: ${data}`);
  });
}

spawnBackend();

/* 
backend.stdout.on("newAnimal", newAnimal => {
	animals.push(new Animal(JSON.parse(newAnimal)))
});

backend.stdout.on("move", move => {

	const { movingAnimalName, dst } = JSON.parse(move);

	const movingAnimal = animals.find(animal => animal.name === movingAnimalName);
	movingAnimal.move(dst);

	show();
});

backend.stdout.on("error", data => {
	console.log(`error: ${data}`);
}); */
