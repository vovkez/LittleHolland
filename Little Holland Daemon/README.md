# Little Holland Daemon

## Description
The Little Holland Daemon is a server application that listens for connections from the VST3/AU2 plugins. It receives MIDI and audio data and stores it locally.

## Configuration
The daemon is configured using `config.json` file. 

### Example `config.json`
```json
{
    "host": "0.0.0.0",
    "port": 8000
}
