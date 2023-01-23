modded class ActionTargetsCursor
{
	override protected void PrepareCursorContent()
	{
		/*
		int health = -1;
		int cargoCount = 0;
		int q_type = 0;
		int q_min, q_max = -1;
		float q_cur = -1.0;
		
		//! item health
		health = GetItemHealth();
		SetItemHealth(health, "item", "item_health_mark", m_HealthEnabled);	
		//! quantity
		GetItemQuantity(q_type, q_cur, q_min, q_max);
		//! cargo in item
		GetItemCargoCount(cargoCount);
		//! fill the widget with data
		/*if ( m_DisplayInteractTarget )
			Print( "ActionTargetsCursor::PrepareCursorContent() m_DisplayInteractTarget.GetType(): " + m_DisplayInteractTarget.GetType() );
		*/
		/*SetItemQuantity(q_type, q_cur, q_min, q_max, "item", "item_quantity_pb", "item_quantity_text", m_QuantityEnabled);
		SetInteractActionIcon("interact", "interact_icon_frame", "interact_btn_inner_icon", "interact_btn_text");
		SetItemDesc(GetItemDesc(m_Interact), cargoCount, "item", "item_desc");
		SetActionWidget(m_Interact, GetActionDesc(m_Interact), "interact", "interact_action_name");

		SetInteractActionIcon("continuous_interact", "continuous_interact_icon_frame", "continuous_interact_btn_inner_icon", "continuous_interact_btn_text");
		SetActionWidget(m_ContinuousInteract, GetActionDesc(m_ContinuousInteract), "continuous_interact", "continuous_interact_action_name");

		SetActionWidget(m_Single, GetActionDesc(m_Single), "single", "single_action_name");
		SetActionWidget(m_Continuous, GetActionDesc(m_Continuous), "continuous", "continuous_action_name");
		SetMultipleItemAction("single_mlt_wrapper", "single_mlt_wrapper_not_select");
		SetMultipleContinuousItemAction("continuous_mlt_wrapper", "continuous_mlt_wrapper_not_select");
		SetMultipleInteractAction("interact_mlt_wrapper", "interact_mlt_wrapper_not_select");
		SetMultipleContinuousInteractAction("continuous_interact_mlt_wrapper", "continuous_interact_mlt_wrapper_not_select");
		*/
		
		super.PrepareCursorContent();

		/*
		Print( "ActionTargetsCursor::PrepareCursorContent() m_Target: " + m_Target );
		Print( "ActionTargetsCursor::PrepareCursorContent() m_Target.GetType(): " + m_Target.GetType() );
		//protected ActionTarget 					m_Target;
		*/
		
		//protected Object						m_DisplayInteractTarget;
		//Print( "ActionTargetsCursor::PrepareCursorContent() m_DisplayInteractTarget: " + m_DisplayInteractTarget );
		/*if ( m_DisplayInteractTarget )
			Print( "ActionTargetsCursor::PrepareCursorContent() m_DisplayInteractTarget.GetType(): " + m_DisplayInteractTarget.GetType() );
		*/
		
		//if ( m_Target )
			//Print( "ActionTargetsCursor::PrepareCursorContent() m_Target.GetObject().GetType(): " + m_Target.GetObject().GetType() );
		
		//Print( "ActionTargetsCursor::PrepareCursorContent() m_Target: " + m_Target );
		//Print( "ActionTargetsCursor::PrepareCursorContent() m_Target.GetObject(): " + m_Target.GetObject() );
		//Print( "ActionTargetsCursor::PrepareCursorContent() m_Target.GetObject().GetType(): " + m_Target.GetObject().GetType() );
		
		//if ( m_Target && m_Target.GetObject().GetType() == "CanisterGasoline" )
		if ( m_Target.GetObject() && m_Target.GetObject().GetType() == "CanisterGasoline" )
		{
			// Код ниже есть и в ItemActionsWidget
				// TO DO Подумать, как его можно оптимизировать
			Widget widget = m_Root.FindAnyWidget("item");
			
			// Ищем строку состояния
			ProgressBarWidget progressBar;
			Class.CastTo(progressBar, widget.FindAnyWidget("item_quantity_pb"));
			
			//Print( "ActionTargetsCursor::PrepareCursorContent() progressBar: " + progressBar );
			
			// Получаем текущий цвет строки состояния
			//Print( "ActionTargetsCursor::PrepareCursorContent() progressBar.GetColor(): " + progressBar.GetColor() );
			
			// Если пустая канистра, то ничего не меняем
			//Print( "ActionTargetsCursor::PrepareCursorContent() q_cur: " + q_cur );
			
			// TO DO Перенести вызов GetItemQuantity() сюда, чтобы оптимизировать скрипт
			int q_type = 0;
			int q_min, q_max = -1;
			float q_cur = -1.0;
			
			// Вызываем этот метод, чтобы получить значение q_cur, которое будем использовать ниже
			GetItemQuantity(q_type, q_cur, q_min, q_max);
			// Если канистра начинает заполняться, то меняем цвет, в зависимости от жидкости
			if ( q_cur > 0)
			{
				//CanisterGasoline canisterGasoline;
				//Print( "ActionTargetsCursor::PrepareCursorContent() Class.CastTo( canisterGasoline, m_Target.GetObject() ): " + Class.CastTo( canisterGasoline, m_Target.GetObject() ) );
				
				CanisterGasoline canisterGasoline = CanisterGasoline.Cast( m_Target.GetObject() );
				
				if (canisterGasoline)
				{
				/*
				if ( Class.CastTo(canisterGasoline, m_Target) )
				{*/
					//Print( "ActionTargetsCursor::PrepareCursorContent() m_Target.GetObject(): " + m_Target.GetObject() );
				
					// TO DO Тут нужно унаследоваться от ItemBase
					//int liquid_type = m_Target.GetObject().GetLiquidType();
					
					int liquid_type = canisterGasoline.GetLiquidType();
					//Print( "ActionTargetsCursor::PrepareCursorContent() liquid_type: " + liquid_type );
					
					if ( liquid_type == LIQUID_GASOLINE )
						// Colors.ORANGE - https://www.htmlcsscolor.com/hex/FFA500
						progressBar.SetColor( ARGB( 255, 255, 165, 0 ) );
					// ??? TO DO Речная вода действительно существует
						// Похоже, что нет
					if ( liquid_type == LIQUID_WATER )
						// Colors.COLOR_LIQUID - https://www.htmlcsscolor.com/hex/0000FF
						//progressBar.SetColor( ARGB( 255, 0, 0, 255 ) );	// -16776961
						//progressBar.SetColor( Colors.COLOR_LIQUID );	// 61183
						//progressBar.SetColor( 16772608 );	// 
						// Подобрал с помощью Colour picker в гугле
						progressBar.SetColor( ARGB( 255, 0, 255, 255 ) );	// -16711681
				//}
				}
			}
			// Во всех остальных случаях сбрасываем на дефолтный
			else
			{
				progressBar.SetColor(-1);
			}
			
			
			// Как изначально
			// progressBar.SetColor(-1);
			// Проверяем, что всё поменялось
			//Print("\n");
			//Print( "ItemActionsWidget::BuildCursor() progressBar.GetColor(): " + progressBar.GetColor() );
			if ( q_cur > 0)
				//Print( "ItemActionsWidget::BuildCursor() progressBar.GetColor(): " + progressBar.GetColor() );
		}
	}

}