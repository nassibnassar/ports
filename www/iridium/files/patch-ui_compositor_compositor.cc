--- ui/compositor/compositor.cc.orig	2024-11-04 08:56:03 UTC
+++ ui/compositor/compositor.cc
@@ -925,7 +925,7 @@ void Compositor::OnResume() {
     obs.ResetIfActive();
 }
 
-#if BUILDFLAG(IS_LINUX) && BUILDFLAG(IS_OZONE_X11)
+#if (BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)) && BUILDFLAG(IS_OZONE_X11)
 void Compositor::OnCompleteSwapWithNewSize(const gfx::Size& size) {
   for (auto& observer : observer_list_)
     observer.OnCompositingCompleteSwapWithNewSize(this, size);
