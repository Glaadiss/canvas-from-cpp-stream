class Playground {
  constructor(ctx) {
    this.ctx = ctx;
  }

  clear(x, y, level) {
    this.doAction(x, y, level, "green");
  }

  pee(x, y, level) {
    this.doAction(x, y, level, "yellow");
  }

  doAction(x, y, level, color) {
    this.ctx.fillStyle = color;
    this.ctx.beginPath();
    this.ctx.arc(x, y, level, 0, 2 * Math.PI);
    this.ctx.strokeStyle = color;
    this.ctx.stroke();
  }
}

module.exports = Playground;
