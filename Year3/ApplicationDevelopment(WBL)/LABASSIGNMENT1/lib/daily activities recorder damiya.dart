import 'package:flutter/material.dart';

void main() {
  runApp(const MyApp());
}

class MyApp extends StatelessWidget {
  const MyApp({super.key});

  // This widget is the root of your application.
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      title: 'Flutter Demo',
      theme: ThemeData(
        // This is the theme of your application.
        //
        // TRY THIS: Try running your application with "flutter run". You'll see
        // the application has a purple toolbar. Then, without quitting the app,
        // try changing the seedColor in the colorScheme below to Colors.green
        // and then invoke "hot reload" (save your changes or press the "hot
        // reload" button in a Flutter-supported IDE, or press "r" if you used
        // the command line to start the app).
        //
        // Notice that the counter didn't reset back to zero; the application
        // state is not lost during the reload. To reset the state, use hot
        // restart instead.
        //
        // This works for code too, not just values: Most code changes can be
        // tested with just a hot reload.
        colorScheme: ColorScheme.fromSeed(seedColor: Colors.deepPurple),
      ),
      home: const MyHomePage(title: 'Flutter Demo Home Page'),
    );
  }
}

class MyHomePage extends StatefulWidget {
  const MyHomePage({super.key, required this.title});

  // This widget is the home page of your application. It is stateful, meaning
  // that it has a State object (defined below) that contains fields that affect
  // how it looks.

  // This class is the configuration for the state. It holds the values (in this
  // case the title) provided by the parent (in this case the App widget) and
  // used by the build method of the State. Fields in a Widget subclass are
  // always marked "final".

  final String title;

  @override
  State<MyHomePage> createState() => _MyHomePageState();
}

class _MyHomePageState extends State<MyHomePage> {
 final TextEditingController _activityController = TextEditingController();
final TextEditingController _timeController = TextEditingController();

List<Map<String, String>> activities = [];

  //Add Function
  void _addActivity() {
    setState(() {
      activities.add({
        "activity": _activityController.text,
        "time": _timeController.text,
      });

      _activityController.clear();
      _timeController.clear();
    });
  }

  //Delete Function
    void _deleteActivity(int index) {
    setState(() {
      activities.removeAt(index);
    });
  }
  
  @override
  Widget build(BuildContext context) {
    return Scaffold(
     backgroundColor: const Color(0xFFF4E3D7), // soft light brown

     appBar: AppBar(
      backgroundColor: const Color(0xFF8B5E3C), // darker brown header
      elevation: 0,
      centerTitle: true,
      title: const Text(
        "Daily Activities Recorder",
        style: TextStyle(
          color: Colors.white,
          fontWeight: FontWeight.bold,
        ),
      ),
    ),

    body: Padding(
      padding: const EdgeInsets.all(16),
      child: Column(
        children: [

          // INPUT SECTION
          Container(
            padding: const EdgeInsets.all(16),
            decoration: BoxDecoration(
              color: Colors.white,
              borderRadius: BorderRadius.circular(20),
              boxShadow: [
                BoxShadow(
                  color: Colors.black12,
                  blurRadius: 8,
                  offset: Offset(0, 4),
                ),
              ],
            ),
            child: Column(
              children: [
                TextField(
                  controller: _activityController,
                  decoration: InputDecoration(
                    hintText: "Activity name",
                    filled: true,
                    fillColor: Colors.grey[100],
                    contentPadding: const EdgeInsets.symmetric(horizontal: 16),
                    border: OutlineInputBorder(
                      borderRadius: BorderRadius.circular(14),
                      borderSide: BorderSide.none,
                    ),
                  ),
                ),
                const SizedBox(height: 12),

                TextField(
                  controller: _timeController,
                  decoration: InputDecoration(
                    hintText: "Time / Category",
                    filled: true,
                    fillColor: Colors.grey[100],
                    contentPadding: const EdgeInsets.symmetric(horizontal: 16),
                    border: OutlineInputBorder(
                      borderRadius: BorderRadius.circular(14),
                      borderSide: BorderSide.none,
                    ),
                  ),
                ),

                const SizedBox(height: 16),

                SizedBox(
                  width: double.infinity,
                  child: ElevatedButton(
                    onPressed: _addActivity,
                    style: ElevatedButton.styleFrom(
                      backgroundColor: const Color(0xFFFFC1CC), // baby pink
                      padding: const EdgeInsets.symmetric(vertical: 14),
                      shape: RoundedRectangleBorder(
                        borderRadius: BorderRadius.circular(14),
                      ),
                      elevation: 3,
                    ),
                    child: const Text(
                      "Add Activity",
                      style: TextStyle(
                        color: Colors.black,
                        fontWeight: FontWeight.w600,
                      ),
                    ),
                  ),
                ),
              ],
            ),
          ),

          const SizedBox(height: 20),

          // TITLE
          const Align(
            alignment: Alignment.centerLeft,
            child: Text(
              "My Activities",
              style: TextStyle(
                fontSize: 18,
                fontWeight: FontWeight.bold,
                color: Color(0xFF5A3E2B),
              ),
            ),
          ),

          const SizedBox(height: 10),

          // LIST
          Expanded(
            child: ListView.builder(
              itemCount: activities.length,
              itemBuilder: (context, index) {
                return Container(
                  margin: const EdgeInsets.only(bottom: 12),
                  padding: const EdgeInsets.all(14),
                  decoration: BoxDecoration(
                    color: Colors.white,
                    borderRadius: BorderRadius.circular(18),
                    boxShadow: [
                      BoxShadow(
                        color: Colors.black12,
                        blurRadius: 6,
                        offset: Offset(0, 3),
                      ),
                    ],
                  ),
                  child: Row(
                    mainAxisAlignment: MainAxisAlignment.spaceBetween,
                    children: [

                      // TEXT
                      Column(
                        crossAxisAlignment: CrossAxisAlignment.start,
                        children: [
                          Text(
                            activities[index]["activity"]!,
                            style: const TextStyle(
                              fontSize: 16,
                              fontWeight: FontWeight.w600,
                            ),
                          ),
                          const SizedBox(height: 4),
                          Text(
                            activities[index]["time"]!,
                            style: const TextStyle(
                              color: Colors.black54,
                            ),
                          ),
                        ],
                      ),

                      // DELETE
                     IconButton(
                        onPressed: () => _deleteActivity(index),
                        icon: const Icon(
                        Icons.delete_outline,
                        color: Color(0xFFB85C5C),
                     ),
),
                    ],
                  ),
                );
              },
            ),
          ),
        ],
      ),
    ),
  );
}
}
