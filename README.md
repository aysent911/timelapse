# Timelapse

C++ binary for encoding snapshots into mp4 video timelapse using H.265 codec

## Dependencies

### Debian/Ubuntu

```shell
sudo apt-get install pkg-config cmake ffmpeg build-essential libsystemd-dev \
                                            libavcodec-dev libavutil-dev libavformat-dev \
                      libcurl4-openssl-dev libavdevice-dev libavfilter-dev \
                      libspdlog-dev gstreamer1.0 libgstreamer1.0-dev \
                      gstreamer1.0-vaapi gstreamer1.0-tools gstreamer1.0-rtsp
```

### macOS
Requires `pkg-config`, `ffmpeg`, `gstreamer`, and `spdlog` installable through Homebrew

```shell
brew install pkg-config ffmpeg spdlog gstreamer
```
## Building

```shell
cmake -S . -B cmake-build-debug   
```
then 

```shell
cmake --build cmake-build-debug   
```


## Usage

```shell
./timelapse <NUMBER_OF_DAYS> <PATH_TO_SNAPSHOTS> <SNAPSHOTS_PREFIX> <OPTIONAL_TIME_INTERVAL>
```
| Argument | Description |
| --- | --- |
| `NUMBER_OF_DAYS` | Number of days to look back from the current time when selecting snapshots. Use a positive integer, such as `7`. |
| `PATH_TO_SNAPSHOTS` | Directory containing the snapshot images. Quote paths containing spaces. |
| `SNAPSHOTS_PREFIX` | Filename text before the timestamp, including any trailing space or separator. For `Snapshot From 2026-10-27 08-30-00.png`, use `"Snapshot From "`. |
| `SNAPSHOT_TIMESTAMP_FORMAT` | For `Snapshot From 2026-10-27 08-30-00.png`, use `"%Y-%m-%d %H-%M-%S"` |
| `TIME_INTERVAL` | Optional sampling interval: `m` for minutes or `h` for hours, such as `5m` or `1h`. If omitted, every eligible snapshot is used. |

### Examples

Use every eligible snapshot from the past seven days:

```shell
./timelapse 7 "/path/to/snapshots" "Snapshot From " "%Y-%m-%d %H-%M-%S"
```

Use approximately one snapshot per hour from the past 30 days:

```shell
./timelapse 30 "/path/to/snapshots" "Snapshot From " "%Y-%m-%d %H-%M-% S" 1hcd 
```



