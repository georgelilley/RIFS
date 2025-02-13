🤖 RIFS – Robotic Interactive Feedback System

📌 Disclaimer

This is a legacy project created in 2022/23 during my university studies. While the code in this repository may not reflect best practices, I believe it is valuable to showcase my progress. Since then, I have focused on writing cleaner, more maintainable code, following principles from Clean Code by Robert C. Martin.

🎛 Project Overview

RIFS (Robotic Interactive Feedback System) is a sonic automaton designed to explore new forms of musical creativity through robotic feedback loops and sensor-based interaction.

🔹 Key Features

-  Robotic catapult arm system controlled via a Teensy microcontroller with Arduino IDE.
-  Max/MSP software for real-time sound processing and decision-making.
-  Interactive feedback system using directional microphones and speakers to generate evolving sound textures.
-  Autonomous decision-making to reposition the robotic microphone based on live audio input.

🎯 Project Goals

This project aimed to investigate:
✅ How robotic systems can extend musical creativity beyond traditional human musicianship.
✅ The role of stochastic processing and feedback loops in shaping evolving soundscapes.
✅ How sonic automata can interact in an ensemble setting, responding to other robotic instruments.

🎵 How It Works

🔊 Audio Input & Feedback:

-  The system uses four outward-facing microphones to detect the loudest sound in the environment.
-  The robotic arm then positions the Teensy microphone towards this source.
-  The captured signal is fed back into the speakers, triggering a dynamic feedback loop.

🛠 Hardware & Software Stack:

-  Microcontroller: Teensy 3.x
-  Software: Arduino IDE, Max/MSP
-  Audio Processing: Logic Pro X, Zoom F4 (used as an interface)
-  Servo Motors: SG90 Servo motors for microphone positioning

🎶 Musical Interactivity & Sonic Automata

-  The movement of the microphone introduces natural variations due to air resistance and physical constraints.
-  The system's autonomous decision-making ensures that it constantly evolves, making each interaction unique.

📚 Research & Inspiration
🎼 Context & Creative Influence

RIFS was inspired by:

-  Dylan Sheridan’s "Random Impulse" (2021) – A kinetic microphone-based project that introduced elements of randomness through physical motion.
-  Steve Reich’s "Pendulum Music" – A pioneering work in microphone-based generative sound.
-  Stochastic Music Theories – The project integrates ideas from Iannis Xenakis, using randomness to shape complex sonic textures.
-  Musebot Ensemble Manifesto (2015) – Inspired by modular robotic musical agents interacting in real-time.

📊 Research Question

"How can sonic automata and musical robots explore new ideas of musical creativity beyond conventional human musicianship?"

Key insights:
✅ Sonic automata introduce stochastic behavior, creating unique, evolving compositions.
✅ Autonomous music systems can generate unexpected creative outputs beyond human intuition.
✅ Feedback loops and physical computing (sensors, motors) bring an organic quality to digital music.

🔥 Evaluation & Future Work

✅ Successes

-  Fully autonomous system responding to real-time audio input.
-  Unique feedback-based sound design, integrating stochastic principles.
-  Potential for ensemble performance alongside other sonic automata.

🔧 Areas for Improvement

-  The Teensy microphone is resilient, but a protective mesh could extend its lifespan.
-  The robotic arm elasticity introduces unintended shape changes, sometimes requiring manual resets.
-  Further development could include randomized mappings for more expressive control.

🎯 Future Development

-  Implementing MIDI control & generative sequencing.
-  Expanding machine learning techniques for more adaptive responses.
-  Exploring hardware refinements for enhanced durability.

🔗 Additional Resources

📽 Inspiration – "Random Impulse" by Dylan Sheridan: Vimeo
📄 Musebot Ensemble Manifesto: Research Paper
