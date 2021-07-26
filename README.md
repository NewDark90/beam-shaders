# Example Beam Shaders

This project is meant to show examples of building beam shaders into usable wasm through rust.

The `rust-bindgen` script is used to generate bvm/src/lib.rs that exposes the public methods that you can use in the shaders. The bvm source code is available in this repository: https://github.com/BeamMW/beam

`name-me-contract` and `name-me-app` are projects that compile to wasm using wasm-bindgen.

***I have not tested these builds to ensure they work or if anything here is accurate. Take caution and do not use this project as an authoritative source on how organize or build a project.***