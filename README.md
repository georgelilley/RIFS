# 🤖 RIFS – Robotic Interactive Feedback System

Real-time autonomous robotics project combining sensing, audio analysis, and
physical actuation.

RIFS listens to its acoustic environment, decides where the dominant signal is
coming from, physically repositions a microphone using servo motors, and feeds
the captured sound back into a speaker system to create an evolving feedback
loop.

🎥 **Demo videos**  
👉 https://youtu.be/F7wPPT4t8aY  
👉 https://youtu.be/3jAcDtHfG2Q  
👉 https://youtu.be/l0ASNh7UYm8  
👉 https://youtu.be/o-HWAWLgwmI  
👉 https://youtu.be/E5-lMnob11M  
👉 https://youtu.be/eqWqho472yY  

---

## Overview

This project required integrating:

- real-time sensor input  
- decision logic  
- embedded firmware  
- host-side audio processing  
- mechanical movement  

The system operates continuously without human intervention and produces
non-deterministic outcomes based on live environmental conditions.

---

## What the System Does

1. Detects relative loudness using multiple directional microphones.  
2. Determines the most active sound source.  
3. Commands a robotic arm (via a Teensy microcontroller) to rotate toward it.  
4. Captures audio and re-injects it into the environment.  
5. The new sound alters the next decision cycle.

This creates a closed feedback loop between environment → computation →
mechanics → environment.

---

## Responsibilities & Engineering Work

- Firmware development for Teensy-based motor control  
- Serial communication between microcontroller and host system  
- Real-time audio analysis in Max/MSP  
- Decision logic for directional targeting  
- Physical integration and iterative tuning
- System debugging across hardware + software boundaries  
- End-to-end integration and live testing

---

## Architecture (High Level)

Microphones → Audio Interface → Max/MSP Processing  
→ Direction Decision → Serial Command  
→ Teensy → Servo Motors → Microphone Movement  
→ Updated Acoustic Input → repeat

---

## Key Technical Challenges

### Real-time behaviour
Latency directly affected physical motion and audio response.  
Processing and actuation had to remain tightly coordinated.

### Noisy input
Environmental sound is unpredictable.  
Logic had to remain stable despite chaotic data.

### Physical constraints
Momentum, elasticity, and air resistance introduced variation beyond software
control, requiring calibration and resilience in the control strategy.

### Cross-domain debugging
Issues could originate in hardware, firmware, audio routing, or mechanical
movement.

---

## Technology Stack

**Embedded:** Teensy 3.x, Arduino  
**Host Processing:** Max/MSP  
**Audio Routing:** external interfaces & live monitoring  
**Actuation:** SG90 servo motors  
**Languages:** C++ / Arduino, Max patch logic

---

## Outcome

Delivered a fully autonomous system capable of:

- continuous operation  
- environment-aware behaviour  
- repeatable sensing → decision → actuation cycles  

Every run produced different results while remaining structurally stable.

---

## Context

Originally developed during undergraduate study.  
While the implementation reflects the tools and experience I had at the time,
the project remains a strong example of early systems integration, real-time
reasoning, and hardware/software coordination.

---

## Why it still matters

This work formed my foundation for later interests in:

- event-driven systems  
- automation  
- control flows  
- designing software that interacts with the real world
