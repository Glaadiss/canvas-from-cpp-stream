module.exports = class Animal {
  constructor({ name, type, x, y, action = null }, ctx, playgroundConnect) {
    this.playgroundConnect = playgroundConnect;
    this.name = name;
    this.type = type;
    this.x = x;
    this.y = y;
    this.directionX = 0;
    this.directionY = 0;
    this.stepX = 0;
    this.stepY = 0;
    this.action = action;
    this.ctx = ctx;
    this.actionLevel = 1;
    this.fps = 60;
    console.log(
      `New ${this.type} named ${this.name} created! Hurra! On position: ${
        this.x
      }, ${this.y} `
    );
  }

  move(dstX, dstY) {
    this.log(dstX, dstY);
    this.action = "MOVE";
    this.directionX = dstX;
    this.directionY = dstY;
    this.stepX = (dstX - this.x) / this.fps;
    this.stepY = (dstY - this.y) / this.fps;
  }

  pee() {
    this.action = "PEE";
    this.actionLevel = 1;
  }

  shouldPeeing() {
    return this.action === "PEE";
  }

  makePee() {
    this.actionLevel += 10 / this.fps;
    console.log(this.name);
    this.playgroundConnect.pee(this.x, this.y, this.actionLevel);
  }

  shouldMoving() {
    return (
      this.action === "MOVE" &&
      Math.abs(this.directionX - this.x) > this.stepX &&
      this.directionY !== this.y > this.stepY
    );
  }

  makeStep() {
    this.x += this.stepX;
    this.y += this.stepY;
  }

  log(x, y) {
    console.log(`Moving animal ${this.name} to new destination: x ${x} y ${y}`);
  }

  show() {
    if (this.shouldMoving()) this.makeStep();
    if (this.shouldPeeing()) this.makePee();
    this.ctx.fillText(this.type + " " + this.name, this.x, this.y);
  }
};
