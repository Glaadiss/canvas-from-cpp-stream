function init() {
  const canvas = document.getElementById("playground");
  const animalsCanvas = document.getElementById("animals");
  canvas.width = animalsCanvas.width = window.innerWidth;
  canvas.height = animalsCanvas.height = window.innerHeight;
  const ctx = canvas.getContext("2d");
  const animalsCtx = animalsCanvas.getContext("2d");
  animalsCtx.fillStyle = "red";
  animalsCtx.font = "20px serif";
  return { ctx, canvas, animalsCtx, animalsCanvas };
}

module.exports = { init };
