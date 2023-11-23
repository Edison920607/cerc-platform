import signal
import sys

def signal_handler(sig, frame):
    print('Exiting program')
    sys.exit(0)

signal.signal(signal.SIGINT, signal_handler)


dir(signal)
print('Press Ctrl+C to exit')
signal.pause()


# import concurrent.futures
# import subprocess
# import json
# import msvcrt
# #import matlab.engine
#
# with open('ExecuteScript.json', 'r') as f:
#     ExecuteScript = json.load(f)
#     scripts = ExecuteScript["scripts"]
#
#
# #engine = matlab.engine.start_matlab()
# # scripts = [".\\WingFly yonghu\\FW-pubnew.py", ".\\WingFly_tianjin\\comnew-FW-sub.py",
# #            ".\\command\\M300 point control\\comnew-M300-sub.py", ".\\command\\M300 point control\\comnew-M300-pub.py",
# #            ".\\command\\M300-pubnew-mult.py"]
# print("Press any key...")
# key = msvcrt.getch()
#
# print(key)
#
# def run_script(script):
#     p = subprocess.Popen(["python", script], stdout=subprocess.PIPE, stderr=subprocess.PIPE)
#     out, err = p.communicate()
#     return script, out.decode(), err.decode()
#
#
# def print_result(future):
#     script, out, err = future.result()
#     print(f"Script: {script}")
#     print(f"Output: {out}")
#     print(f"Error: {err}")
#
#
# with concurrent.futures.ThreadPoolExecutor(max_workers=2) as executor:
#     futures = []
# for script in scripts:
#     future = executor.submit(run_script, script)
# future.add_done_callback(print_result)
# futures.append(future)
